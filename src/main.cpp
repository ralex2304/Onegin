#include <stdio.h>

#include "utils/args_parser.h"
#include "file/file.h"
#include "sort.h"
#include "text/text_proccessor.h"
#include "text/arrays.h"

int main(int argc, char* argv[]) {

    /// Parsing console arguments
    ArgsVars args_vars = {};
    args_vars.input_filename  = "text.txt"; ///< default value
    args_vars.output_filename = "dict.txt"; ///< default value

    args_parse(argc, argv, &args_vars);
    /// Parsing console arguments end

    /// Read input data
    InputData input_data = {};

    input_data.ctor(args_vars.input_filename);
    /// Read input data end

    /// Sortable arrays creation
    static const size_t SORT_METHODS = 2;
    String* lines_arrays[SORT_METHODS] = {};

    for (size_t i = 0; i < SORT_METHODS; i++) {
        lines_arrays[i] = (String*)arrdup(input_data.lines, input_data.lines_cnt, sizeof(String));

        if (lines_arrays[i] == nullptr) {
            printf("Memory allocation error\n");
            return Status::raise(Status::MEMORY_EXCEED);
        }
    }
    /// Sortable arrays creation end

    /// Lines sorting
    char* pivot = 0;
    quick_sort(lines_arrays[0], input_data.lines_cnt, &pivot, sizeof(String), string_comp);
    qsort(lines_arrays[1], input_data.lines_cnt, sizeof(String), string_comp_suf);
    /// Lines sorting end

    /// File writing
    FILE* out_file = nullptr;
    if (!file_open(&out_file, args_vars.output_filename, "w"))
        return Status::raise(Status::FILE_ERROR);

    fprintf(out_file, "------------Prefix sort:----------------------------------------------------------\n");
    if (!file_write_lines(out_file, lines_arrays[0])) {
        file_close(out_file);
        return Status::raise(Status::FILE_ERROR);
    }

    fprintf(out_file, "------------Suffix sort:----------------------------------------------------------\n");
    if (!file_write_lines(out_file, lines_arrays[1])) {
        file_close(out_file);
        return Status::raise(Status::FILE_ERROR);
    }

    fprintf(out_file, "------------Original text:--------------------------------------------------------\n");
    if (!file_write_lines(out_file, input_data.lines)) {
        file_close(out_file);
        return Status::raise(Status::FILE_ERROR);
    }

    if (!file_close(out_file))
        return Status::raise(Status::FILE_ERROR);
    /// File writing end

    input_data.detor();

    for (size_t i = 0; i < SORT_METHODS; i++)
        FREE(lines_arrays[i]);

    return Status::OK_EXIT;
}

