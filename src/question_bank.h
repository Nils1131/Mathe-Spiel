#ifndef QUESTION_BANK_H
#define QUESTION_BANK_H

#include <stddef.h>

typedef struct {
    const char *text;
    const char *options[4];
    int correct; /* index of correct answer */
} question_t;

size_t qb_count(void);
const question_t *qb_get(size_t index);

#endif /* QUESTION_BANK_H */
