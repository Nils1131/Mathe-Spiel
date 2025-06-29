#include <stdio.h>
#include "game_logic.h"
#include "leaderboard.h"

#define LB_FILE "leaderboard.txt"

static void show_menu(void) {
    printf("\nHauptmen\303\274\n");
    printf("1. Spielen\n");
    printf("2. Bestenliste anzeigen\n");
    printf("3. Bestenliste zur\303\274cksetzen\n");
    printf("4. Beenden\n");
    printf("Auswahl: ");
}

static void show_leaderboard(void) {
    if (lb_load(LB_FILE) != 0) {
        printf("Noch keine Bestenliste vorhanden.\n");
        return;
    }
    size_t count = lb_count();
    const LBEntry *entries = lb_entries();
    printf("\nBestenliste:\n");
    for (size_t i = 0; i < count; i++) {
        printf("%zu. %s - %d\n", i + 1, entries[i].name, entries[i].score);
    }
}

int main(void) {
    lb_load(LB_FILE);
    int choice = 0;
    while (1) {
        show_menu();
        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Ung\303\274ltige Eingabe. Bitte Zahl zwischen 1 und 4 eingeben.\n");
            continue;
        }
        switch (choice) {
            case 1: {
                int score = play_game();
                char name[LB_NAME_LEN];
                printf("Bitte Namen eingeben: ");
                if (scanf("%63s", name) != 1) {
                    int c; while ((c = getchar()) != '\n' && c != EOF) {}
                    printf("Ung\303\274ltige Eingabe. Ergebnis wird nicht gespeichert.\n");
                } else {
                    lb_add(name, score);
                    lb_save(LB_FILE);
                }
                break;
            }
            case 2:
                show_leaderboard();
                break;
            case 3:
                if (lb_reset(LB_FILE) == 0) {
                    printf("Bestenliste zur\303\274ckgesetzt.\n");
                } else {
                    printf("Fehler beim Zur\303\274cksetzen der Bestenliste.\n");
                }
                break;
            case 4:
                lb_save(LB_FILE);
                printf("Programm wird beendet.\n");
                return 0;
            default:
                printf("Bitte Zahl zwischen 1 und 4 eingeben.\n");
                break;
        }
    }
}
