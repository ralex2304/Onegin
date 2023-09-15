#include "arrays.h"

bool create_several_arrays(void** arrays, const size_t array_size, const size_t arrays_cnt, const size_t elem_size) {
    assert(arrays);

    char** arr = (char**)arrays;
    *arr = (char*)calloc(array_size * arrays_cnt, elem_size);
    if (*arr == nullptr) {
        printf("Memory allocation error!\n");
        return false;
    }

    for (size_t i = 1; i < arrays_cnt; i++)
        arr[i] = *arr + i * array_size * elem_size;

    return true;
}
