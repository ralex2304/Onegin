#include "text_lib.h"

String my_strtok_line(const char* input) {
    static char* str = nullptr;

    if (input != nullptr)
        str = const_cast<char*>(input);
    else
        input = str;

    if (str == nullptr)
        return String {};

    String ret = {};
    ret.str = str;

    while (*str != '\r' && *str != '\n')
        str++;

    while ((*str == '\r') && *str) {
        if (ret.len == 0)
            ret.len = str - input;

        *str = '\0';
        str++;
    }
    if (ret.len == 0)
        ret.len = str - input;

    *str = '\0';
    str++;

    if (*str == '\0')
        str = nullptr;

    return ret;
}

void split_text_to_lines(const char* text, String* lines_array) {
    assert(text);
    assert(lines_array);

    lines_array[0] = my_strtok_line(text);

    for (size_t i = 1; lines_array[i - 1].str != nullptr; i++) {
        lines_array[i] = my_strtok_line(nullptr);
    }
}

int stringcmp_is_alpha(String str1, String str2) {
    assert(str1.str);
    assert(str2.str);

    str1.str = skip_non_alpha(str1.str);
    str2.str = skip_non_alpha(str2.str);

    return strcmp(str1.str, str2.str);
}

int stringcmp_is_alpha_suf(String str1, String str2) {
    assert(str1.str);
    assert(str2.str);

    str1.len = skip_non_alpha_from_end(str1.str, str1.len);
    str2.len = skip_non_alpha_from_end(str2.str, str2.len);

    while(str1.len > 0 && str2.len >0) {
        if (str1.str[str1.len - 1] != str2.str[str2.len - 1])
            return str1.str[str1.len - 1] - str2.str[str2.len - 1];
        str1.len--;
        str2.len--;
    }

    return (int)(str1.len - str2.len);
}
