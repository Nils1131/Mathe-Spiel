#include "leaderboard.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static LBEntry entries[LB_MAX_ENTRIES];
static size_t entry_count = 0;

static FILE *open_file(const char *path, const char *mode) {
#ifdef _WIN32
    FILE *f = NULL;
    if (fopen_s(&f, path, mode) != 0) {
        return NULL;
    }
    return f;
#else
    return fopen(path, mode);
#endif
}

static int cmp_entries(const void *a, const void *b) {
    const LBEntry *ea = (const LBEntry *)a;
    const LBEntry *eb = (const LBEntry *)b;
    return eb->score - ea->score;
}

int lb_load(const char *path) {
    if (!path) {
        path = LB_DEFAULT_PATH;
    }
    FILE *f = open_file(path, "r");
    if (!f) {
        return -1;
    }

    entry_count = 0;
    char line[256];
    while (entry_count < LB_MAX_ENTRIES && fgets(line, sizeof(line), f)) {
        char *comma = strchr(line, ',');
        if (!comma) {
            continue;
        }
        *comma = '\0';
        char *name = line;
        char *score_str = comma + 1;
        int score = atoi(score_str);
        strncpy(entries[entry_count].name, name, LB_NAME_LEN - 1);
        entries[entry_count].name[LB_NAME_LEN - 1] = '\0';
        entries[entry_count].score = score;
        entry_count++;
    }
    fclose(f);
    qsort(entries, entry_count, sizeof(LBEntry), cmp_entries);
    return 0;
}

int lb_save(const char *path) {
    if (!path) {
        path = LB_DEFAULT_PATH;
    }
    FILE *f = open_file(path, "w");
    if (!f) {
        return -1;
    }

    for (size_t i = 0; i < entry_count; i++) {
        fprintf(f, "%s,%d\n", entries[i].name, entries[i].score);
    }
    fclose(f);
    return 0;
}

int lb_add(const char *name, int score) {
    if (entry_count >= LB_MAX_ENTRIES) {
        return -1;
    }

    strncpy(entries[entry_count].name, name, LB_NAME_LEN - 1);
    entries[entry_count].name[LB_NAME_LEN - 1] = '\0';
    entries[entry_count].score = score;
    entry_count++;
    qsort(entries, entry_count, sizeof(LBEntry), cmp_entries);
    return 0;
}

int lb_reset(const char *path) {
    entry_count = 0;
    if (!path) {
        path = LB_DEFAULT_PATH;
    }
    FILE *f = open_file(path, "w");
    if (!f) {
        return -1;
    }
    fclose(f);
    return 0;
}

size_t lb_count(void) {
    return entry_count;
}

const LBEntry *lb_entries(void) {
    return entries;
}

