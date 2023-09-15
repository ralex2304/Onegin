#include <stdio.h>

#include "args_parser.h"
#include "file.h"
#include "text_lib.h"
#include "sort.h"

int main(int argc, char* argv[]) {

    /// Parsing console arguments
    ArgsVars args_vars = {};
    args_vars.input_filename = "text.txt";  /// default value
    args_vars.output_filename = "dict.txt"; /// default value

    args_parse(argc, argv, &args_vars);
    /// Parsing console arguments end

    /// File reading
    char* text = nullptr;
    Status::Statuses res = file_open_and_read(args_vars.input_filename, &text);
    if (res != Status::NORMAL_WORK)
        return Status::raise(res);

    assert(text);
    /// File reading end

    /// Text parsing
    static const size_t SORT_METHODS = 2;
    String* lines_arrays[SORT_METHODS + 1] = {};

    size_t lines_cnt = cntchar(text, '\n');

    if (!create_lines_arrays(text, lines_arrays, lines_cnt + 1, sizeof(lines_arrays) / sizeof(*lines_arrays)))
        return Status::raise(Status::MEMORY_EXCEED);
    /// Text parsing end

    /// Lines sorting
    char* pivot = 0;
    quick_sort(lines_arrays[1], lines_cnt, &pivot, sizeof(String), string_comp);
    qsort(lines_arrays[2], lines_cnt, sizeof(String), string_comp_suf);
    /// Lines sorting end

    /// File writing
    FILE* out_file = nullptr;
    if (!file_open_w(&out_file, args_vars.output_filename))
        return Status::raise(Status::FILE_ERROR);

    fprintf(out_file, "------------Prefix sort:----------------------------------------------------------\n");
    if (!file_write_lines(out_file, lines_arrays[1])) {
        file_close(out_file);
        return Status::raise(Status::FILE_ERROR);
    }

    fprintf(out_file, "------------Suffix sort:----------------------------------------------------------\n");
    if (!file_write_lines(out_file, lines_arrays[2])) {
        file_close(out_file);
        return Status::raise(Status::FILE_ERROR);
    }

    fprintf(out_file, "------------Original text:--------------------------------------------------------\n");
    if (!file_write_lines(out_file, lines_arrays[0])) {
        file_close(out_file);
        return Status::raise(Status::FILE_ERROR);
    }

    if (!file_close(out_file))
        return Status::raise(Status::FILE_ERROR);
    /// File writing end

    free(*lines_arrays);
    *lines_arrays = nullptr;
    free(text);
    text = nullptr;

    return Status::OK_EXIT;
}

