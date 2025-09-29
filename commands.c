// commands.h
#ifndef COMMANDS_H
#define COMMANDS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

// int SPEED = 50;
char TEXT[50] = "OH YES BETA WELCOME!";

void help() {
//     system("cls");
    // printf("\n");

    printf("\n");
    printf("\tCOMMANDS\t\tDESCRIPTION\n");
    printf("\n");

    printf("\thelp\t\t\t");
    printf("Display the options for help\n");

    printf("\tstart_marquee\t\t");
    printf("Start the marquee animation\n");

    printf("\tstop_marquee\t\t");
    printf("Stop the marquee animation\n");

    printf("\tset_text <string>\t");
    printf("Set the text displayed in the marquee\n");

    printf("\tset_speed <ms>\t\t");
    printf("Set the speed of the marquee animation\n");

    printf("\texit\t\t\t");
    printf("Exit the program\n");

    printf("\n");
}

void stop_marquee() {

    system("cls");
    printf("stop_marquee was selected\n");
}

void start_marquee() {
    system("cls");
    char choice[20];

    char empty_string[100];
    int padding = strlen(TEXT);

    for(int i = 0; i < padding; i++)
        empty_string[i] = ' ';
    empty_string[padding] = '\0';

    strcat(empty_string, TEXT);

    printf("%s\n", empty_string);

    do {
        for( int i = 0; i <= strlen(empty_string); i++ ){
            // while (kbhit()){
            //     printf("> ");
            //     scanf("%s", choice);
            //     if(strcmp(choice, "stop_marquee") == 0) {
            //         stop_marquee();
            //         break;
            //     }
            // } 
            if(strcmp(choice, "stop_marquee") == 0) break;
            system("cls");
            printf("%.*s\n", strlen(TEXT), empty_string+ i);
            Sleep(500);
        }
    } while (!(strcmp(choice, "stop_marquee") == 0));

    stop_marquee();
    return;
}

void set_text() {

    system("cls");
    printf("set_text was selected\n");
    
    int c;
    printf("Please enter new text: "); 

    while ((c = getchar()) != '\n') { 
        }
        
    fgets(TEXT, sizeof(TEXT), stdin);
    TEXT[strcspn(TEXT, "\n")] = '\0';

    printf("MARQUEE updated successfully!\n");

}

void set_speed() {

    system("cls");
    printf("set_speed was selected\n");

    int c;
    printf("Please enter new speed(int): ");

    while (TRUE) {
        printf("Please enter new speed (integer): ");

        if (scanf("%d", 500) == 1) {
            while ((c = getchar()) != '\n') { 
                }
            printf("SPEED updated successfully!\n");
            break;
        } 
        else {
            while ((c = getchar()) != '\n') { 
                }
            printf("Invalid input. Please input an integer.\n");
        }
    }

}

#endif 