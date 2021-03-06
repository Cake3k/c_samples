#ifndef TXTCOUNT_H
#define TXTCOUNT_H
#include <stdbool.h>

/**
 * Entry point for txt counter modules
 * @param[in] type Counter type (word/ch)
 */
void txtcounter(char *type);

/**
 * Counts the number of words in a text file,
 * chosen by the user.
 */
static bool wordcounter(char *fpath);

/**
 * Counts the number of characters in a text file,
 * chosen by the user.
 */
static bool charcounter(char *fpath);



#endif