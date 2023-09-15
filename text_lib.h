#ifndef TEXT_LIB_H_
#define TEXT_LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

/**
 * @brief Tokenizator for lines
 *
 * @param str
 * @return char*
 */
char* my_strtok_line(const char* str);

/**
 * @brief compares two strings, ignores non alpha symbols at the beginning
 *
 * @param str1
 * @param str2
 * @return int
 */
int strcmp_is_alpha(const char* str1, const char* str2);

/**
 * @brief compares two strings, goes from the end, ignores non alpha symbols at the beginning
 *
 * @param str1
 * @param str2
 * @return int
 */
int strcmp_is_alpha_suf(const char* str1, const char* str2);




#endif // #ifndef MY_STRING_H_
