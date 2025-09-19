#include "commands.c"
#include "ui.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()  {
    char choice[20];
    display_menu();
    input_format();
    do {
        // Format initial input
        scanf("%s", &choice);

        if(strcmp(choice, "help") == 0){
            help();
            input_format();
        }

        if(strcmp(choice, "start_marquee") == 0){
            start_marquee();
            input_format();
        }

        if(strcmp(choice, "stop_marquee") == 0){
            stop_marquee();
            display_menu();
            input_format();
        }

        if(strcmp(choice, "set_text") == 0){
            set_text();
            input_format();
        }

        if(strcmp(choice, "set_speed") == 0){
            set_speed();
            input_format();
        }

        // Added additional option for ease of testing
        if(strcmp(choice, "clear") == 0) {
            system("cls");
            display_menu();
            input_format();
        }
    } 
    while ( !(strcmp(choice, "exit") == 0));
    return 0;
}