#include "text_lib.h"

char* my_strtok_line(const char* input) {
    static char* str = nullptr;

    if (input != nullptr)
        str = const_cast<char*>(input);

    if (str == nullptr)
        return nullptr;

    char* ret = str;

    while (*str != '\r' && *str != '\n')
        str++;

    while ((*str == '\r' || *str == '\n') && *str) {
        *str = '\0';
        str++;
    }

    if (*str == '\0')
        str = nullptr;

    return ret;
}

int strcmp_is_alpha(const char* str1, const char* str2) {
    while (!isalpha(*str1) && *str1 != '\0') str1++;
    while (!isalpha(*str2) && *str2 != '\0') str2++;

    return strcmp(str1, str2);
}

int strcmp_is_alpha_suf(const char* str1, const char* str2) {
    ssize_t str1_len = strlen(str1);
    ssize_t str2_len = strlen(str2);

    while (--str1_len >= 0 && !isalpha(str1[str1_len])) {}
    while (--str2_len >= 0 && !isalpha(str2[str2_len])) {}

    while(str1_len >= 0 && str2_len >=0) {
        if (str1[str1_len] != str2[str2_len])
            return str1[str1_len] - str2[str2_len];
        str1_len--;
        str2_len--;
    }
    return (int)(str1_len - str2_len);
}
