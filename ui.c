#ifndef UI_H
#define UI_H

void input_format() {

    printf("CSOPESY> ");
}

void display_menu() {
    system("cls"); 
    for ( int i = 0; i < 40; i++ )
        printf("-");
    printf("\n");

    printf("\tCSOPESY Marquee Console \n");
    printf("\n");
    printf("type 'help' for options or 'exit' to leave the program\n");
    printf("\n");

    for ( int i = 0; i < 40; i++ )
        printf("-");
    printf("\n");
}
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
#endif