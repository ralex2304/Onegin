#include <stdio.h>

#include "file.h"
#include "text_lib.h"
#include "sort.h"


int main() {
    const char* input_filename = "text.txt";
    const char* output_filename = "dict.txt";

    /// File reading
    char* text = nullptr;
    Status::Statuses res = file_open_and_read(input_filename, &text);
    if (res != Status::NORMAL_WORK)
        return Status::raise(res);

    assert(text);
    /// File reading end

    size_t lines_cnt = 0;
    for (size_t i = 0; text[i] != '\0'; i++)
        if (text[i] == '\n')
            lines_cnt++;

    char** lines = (char**)calloc((lines_cnt + 1) * 3, sizeof(char*));
    char** lines_sorted_pref = lines + 1 * (lines_cnt + 1);
    char** lines_sorted_suf  = lines + 2 * (lines_cnt + 1);

    lines[0] = my_strtok_line(text);
    size_t lines_i = 1;
    do {
        lines[lines_i] = my_strtok_line(nullptr);
        lines_sorted_pref[lines_i - 1] = lines[lines_i - 1];
        lines_sorted_suf[lines_i - 1]  = lines[lines_i - 1];
        lines_i++;
    } while (lines[lines_i - 1] != nullptr);

    char* pivot = 0;
    quick_sort(lines_sorted_pref, lines_i - 1, &pivot, sizeof(char*), str_comp);
    quick_sort(lines_sorted_suf, lines_i - 1, &pivot, sizeof(char*), str_comp_suf);

    FILE* out_file = nullptr;
    if (!file_open_w(&out_file, output_filename))
        return Status::raise(Status::FILE_ERROR);


    fprintf(out_file, "------------Original text:--------------------------------------------------------\n");
    if (!file_write_lines(out_file, lines)) {
        file_close(out_file);
        return Status::raise(Status::FILE_ERROR);
    }

    fprintf(out_file, "------------Prefix sort:----------------------------------------------------------\n");
    if (!file_write_lines(out_file, lines_sorted_pref)) {
        file_close(out_file);
        return Status::raise(Status::FILE_ERROR);
    }

    fprintf(out_file, "------------Suffix sort:----------------------------------------------------------\n");
    if (!file_write_lines(out_file, lines_sorted_suf)) {
        file_close(out_file);
        return Status::raise(Status::FILE_ERROR);
    }

    if (!file_close(out_file))
        return Status::raise(Status::FILE_ERROR);

    return Status::OK_EXIT;
}

