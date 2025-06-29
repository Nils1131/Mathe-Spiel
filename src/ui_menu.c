#include <stdio.h>

static void show_menu(void) {
    printf("\nHauptmen\303\274\n");
    printf("1. Spielen\n");
    printf("2. Bestenliste anzeigen\n");
    printf("3. Bestenliste zur\303\274cksetzen\n");
    printf("4. Beenden\n");
    printf("Auswahl: ");
}

void ui_main_menu(void) {
    int choice = 0;
    while (1) {
        show_menu();
        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("Ung\303\274ltige Eingabe. Bitte Zahl zwischen 1 und 4 eingeben.\n");
            continue;
        }
        switch (choice) {
            case 1:
                printf("Spielen gew\303\244hlt.\n");
                break;
            case 2:
                printf("Bestenliste wird angezeigt.\n");
                break;
            case 3:
                printf("Bestenliste wird zur\303\274ckgesetzt.\n");
                break;
            case 4:
                printf("Programm wird beendet.\n");
                return;
            default:
                printf("Bitte Zahl zwischen 1 und 4 eingeben.\n");
                break;
        }
    }
}

