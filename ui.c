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

#endif