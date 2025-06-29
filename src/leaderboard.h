#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <stddef.h>

#define LB_NAME_LEN 64
#define LB_MAX_ENTRIES 100

#ifdef _WIN32
#define LB_DEFAULT_PATH "data\\leaderboard.csv"
#else
#define LB_DEFAULT_PATH "data/leaderboard.csv"
#endif

typedef struct {
    char name[LB_NAME_LEN];
    int score;
} LBEntry;

int lb_load(const char *path);
int lb_save(const char *path);
int lb_add(const char *name, int score);
int lb_reset(const char *path);
size_t lb_count(void);
const LBEntry *lb_entries(void);

#endif // LEADERBOARD_H
