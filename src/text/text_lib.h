#ifndef TEXT_LIB_H_
#define TEXT_LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "arrays.h"

/**
 * @brief Struct to keep string and len together
 */
struct String {
    char* str = nullptr; ///< string
    ssize_t len = 0;     ///< string len
};

/**
 * @brief Tokenizator for lines
 *
 * @param str
 * @return String
 */
String my_strtok_line(const char* str);

/**
 * @brief Uses my_strtok_lines and writes results into array
 *
 * @param text
 * @param lines_array
 */
void split_text_to_lines(const char* text, String* lines_array);

/**
 * @brief Create a lines arrays object
 *
 * @param text
 * @param lines_arrays pointer to array of lines arrays
 * @param lines_array_size
 * @param lines_arrays_cnt
 * @return true success
 * @return false failure
 */
bool create_lines_arrays(const char* text, String** lines_arrays, const size_t lines_array_size, const size_t lines_arrays_cnt);

/**
 * @brief compares two strings, ignores non alpha symbols at the beginning
 *
 * @param str1
 * @param str2
 * @return int
 */
int stringcmp_is_alpha(String str1, String str2);

/**
 * @brief compares two strings, goes from the end, ignores non alpha symbols at the beginning
 *
 * @param str1
 * @param str2
 * @return int
 */
int stringcmp_is_alpha_suf(String str1, String str2);

/**
 * @brief Counts ch in str
 *
 * @param str
 * @param ch
 * @return size_t
 */
inline size_t cntchar(const char* str, const char ch) {
    size_t cnt = 0;

    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] == ch)
            cnt++;

    return cnt;
}

/**
 * @brief Returns pointer at the first isalpha() symbol from str
 *
 * @param str
 * @return char*
 */
inline char* skip_non_alpha(char* str) {
    while (!isalpha(*str) && *str != '\0') str++;
    return str;
}

/**
 * @brief Returns len of str, but without non alpha symbols in the end
 *
 * @param str
 * @param len
 * @return ssize_t
 */
inline ssize_t skip_non_alpha_from_end(char* str, ssize_t len) {
    while (len > 0 && !isalpha(str[len - 1])) len--;

    return len;
}

#endif // #ifndef MY_STRING_H_
