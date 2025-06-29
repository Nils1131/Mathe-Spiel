#include "game_logic.h"
#include "question_bank.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game(void) {
    size_t total = qb_count();
    if (total == 0) {
        printf("Keine Fragen verf\303\274gbar.\n");
        return;
    }

    size_t count = total < 10 ? total : 10;
    size_t *indices = malloc(total * sizeof(size_t));
    if (!indices) {
        printf("Speicherfehler.\n");
        return;
    }

    for (size_t i = 0; i < total; i++) {
        indices[i] = i;
    }
    srand((unsigned)time(NULL));
    for (size_t i = total - 1; i > 0; i--) {
        size_t j = (size_t)rand() % (i + 1);
        size_t tmp = indices[i];
        indices[i] = indices[j];
        indices[j] = tmp;
    }

    int score = 0;
    for (size_t q = 0; q < count; q++) {
        const question_t *question = qb_get(indices[q]);
        if (!question) {
            continue;
        }
        printf("\nFrage %zu: %s\n", q + 1, question->text);
        for (int i = 0; i < 4; i++) {
            printf("%d) %s\n", i + 1, question->options[i]);
        }
        printf("Antwort (1-4): ");
        int ans;
        if (scanf("%d", &ans) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Ung\303\274ltige Eingabe. Frage wird \303\274bersprungen.\n");
            continue;
        }
        if (ans - 1 == question->correct) {
            printf("Richtig!\n");
            score++;
        } else {
            printf("Falsch.\n");
        }
    }

    free(indices);
    printf("\nSpiel beendet. Punkte: %d von %zu.\n", score, count);
}

