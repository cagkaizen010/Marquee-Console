#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    system("cls"); 

    printf("--- CSOPESY Marquee Console ---\n");
    printf("help\n");
    printf("start_marquee\n");
    printf("stop_marquee\n");
    printf("set_text\n");
    printf("set_speed\n");
    printf("exit\n");
}


void conclusion_msg() {
    printf("Press enter to exit...");
    while(getchar() != '\n');
    exit;
    // getchar();
}

int main()  {
    int choice;
    display_menu();
    do {

        scanf("%d", &choice);
        switch(choice) {
            case 1:
                system("cls"); 
                printf("Meow\n");
                conclusion_msg();
                break;
            case 2:
                system("cls"); 
                printf("Woof\n");
                conclusion_msg();
                break;
            case 3:
                system("cls"); 
                printf("Exiting...");
                break;
        }
    } 
    while ( choice != 3);
    return 0;
}