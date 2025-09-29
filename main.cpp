#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <iomanip>
#include <queue>

#include <conio.h>
#include <windows.h>
#include "ui.c"

// --- Shared State and Thread Control ---
// Global flag to signal all threads to exit.
std::atomic<bool> is_running{true};

// The command interpreter and display thread share this variable.
std::string prompt_display_buffer = "";
std::mutex prompt_mutex;

// Shared state for the keyboard handler and command interpreter.
std::queue<std::string> command_queue;
std::mutex command_queue_mutex;

// The marquee logic thread and display thread share this variable.
std::string marquee_display_buffer = "";
std::mutex marquee_to_display_mutex;


//// User created variables

std::atomic<int> SPEED(200);
std::string TEXT_x = "HELLO WORLD";
std::mutex string_mutex;

// --- Utility Function ---
// Moves the cursor to a specific (x, y) coordinate on the console.
void gotoxy(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

// --- Thread Functions ---
void keyboard_handler_thread_func() {
    std::string command_line;
    while (is_running) {
        std::getline(std::cin, command_line);
        if (!command_line.empty()) {
            std::unique_lock<std::mutex> lock(command_queue_mutex);
            command_queue.push(command_line);
            lock.unlock();
        }
    }
}


void marquee_logic_thread_func(int display_width) {

    std::string display_string = "";
    std::string beginning_pad = "";
    while (is_running) {
            display_string = "";
            beginning_pad = "";
        {
            std::unique_lock<std::mutex> lock_string(string_mutex);
            display_string += TEXT_x;
            for(int i = 0; i < TEXT_x.length(); i++){
                display_string += " ";
                beginning_pad += " ";
            }
            display_string = beginning_pad + display_string;

        }
        {

            for(int i = 0; i < 2* beginning_pad.length(); i++){
                std::unique_lock<std::mutex> marquee_lock(marquee_to_display_mutex);
                marquee_display_buffer = display_string.substr(i, beginning_pad.length());

                std::this_thread::sleep_for(std::chrono::milliseconds(SPEED));
            }
        }
    }
}

void display_thread_func() {
    const int refresh_rate_ms = 50;

    while (is_running) {
        // Display logic goes here...
        if (prompt_display_buffer == "help"){
            system("cls");
            help();
            input_format();
        }
        if (prompt_display_buffer == "start_marquee"){
            system("cls");
            std::cout << marquee_display_buffer << std::endl;
              
        }

        if (prompt_display_buffer == "stop_marquee"){
            system("cls");
            display_menu();
            input_format();
        }

        if (prompt_display_buffer == "main" || prompt_display_buffer ==""){
            // Display default menu
            system("cls");
            display_menu();
            input_format();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(refresh_rate_ms));

    }
}

// --- Main Function (Command Interpreter Thread) ---
int main() {
    // Start the three worker threads.
    std::thread marquee_logic_thread(marquee_logic_thread_func, 40);
    std::thread display_thread(display_thread_func);
    std::thread keyboard_handler_thread(keyboard_handler_thread_func);


    // Main loop that processes commands from the queue.
    while (is_running) {

        std::string command_line;
        {
            std::unique_lock<std::mutex> lock(command_queue_mutex);
            if (!command_queue.empty()) {
                command_line = command_queue.front();
                command_queue.pop();
            }
        }
         
        if (!command_line.empty()) {
            // Command processing logic goes here...
            std::string arg1;
            std::string arg2;
            boolean secondArgBoolean = false;

            for(int i = 0; i < command_line.length(); i++){
                if (i < command_line.find_first_of(' ')){
                    arg1 += command_line[i];
                } 
                else {
                    if (command_line[i] == ' ' && secondArgBoolean == false) {
                        i++;
                        secondArgBoolean = true;
                    }
                    if (i > command_line.find_first_of(' ')) arg2 += command_line[i];
                }

            }
            secondArgBoolean = true;

            if (arg1== "main" )
            {
                std::unique_lock<std::mutex> lock(prompt_mutex);
                prompt_display_buffer = "main";
                lock.unlock();
            }

            if (arg1 == "exit") {
                printf("\nPress the enter key to exit...");
                is_running = false;
            }


            if(arg1 == "help"){
                std::unique_lock<std::mutex> lock(prompt_mutex);
                prompt_display_buffer = "help";
                lock.unlock();
            }

            if(arg1 == "start_marquee"){
                std::unique_lock<std::mutex> lock(prompt_mutex);
                prompt_display_buffer = "start_marquee";
                lock.unlock();
            }

            if(arg1 == "stop_marquee"){
                std::unique_lock<std::mutex> lock(prompt_mutex);
                prompt_display_buffer = "stop_marquee";
                lock.unlock();
            }

            if(arg1 == "set_speed"){
                SPEED = std::stoi(arg2);
            }

            if(arg1 == "set_text"){

                std::unique_lock<std::mutex> lock(string_mutex);
                TEXT_x = arg2;
                lock.unlock();
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    // Join threads to ensure they finish cleanly.
    if (marquee_logic_thread.joinable()) {
        marquee_logic_thread.join();
    }
    if (display_thread.joinable()) {
        display_thread.join();
    }
    if (keyboard_handler_thread.joinable()) {
        keyboard_handler_thread.join();
    }

    return 0;
}

