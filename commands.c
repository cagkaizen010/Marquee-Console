// commands.h
#ifndef COMMANDS_H
#define COMMANDS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help() {
    system("cls");
    printf("start_marquee\n");
    printf("stop_marquee\n");
    printf("set_text\n");
    printf("set_speed\n");
    printf("exit\n");

}

void start_marquee() {
    system("cls");
    printf("start_marquee was selected");
}

void stop_marquee() {

    system("cls");
    printf("stop_marquee was selected");
}

void set_text() {

    system("cls");
    printf("set_text was selected");

}

void set_speed() {

    system("cls");
    printf("set_speed was selected");

}

#endif 