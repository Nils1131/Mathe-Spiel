#ifndef MAIN_H
#define MAIN_H

/**
 * @file main.h
 * @brief Declarations for the math quiz application.
 */

/**
 * @brief Initialize the quiz system.
 */
void quiz_init(void);

/**
 * @brief Start the interactive quiz loop.
 */
void quiz_run(void);

/**
 * @brief Clean up resources before exiting the quiz.
 */
void quiz_cleanup(void);

/**
 * @brief Entry point of the program.
 *
 * @return 0 on success, non-zero otherwise.
 */
int main(void);

#endif /* MAIN_H */
