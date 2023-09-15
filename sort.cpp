#include "sort.h"


int string_comp(const void* a, const void* b) {
    return stringcmp_is_alpha(*(const String*)a, *(const String*)b);
}

int string_comp_suf(const void* a, const void* b) {
    return stringcmp_is_alpha_suf(*(const String*)a, *(const String*)b);
}

int int_comp(const void* a, const void* b) {
    return *((const int*)a) - *((const int*)b);
}

void quick_sort(void* array, size_t len, void* const pivot, size_t elem_size, comp_t* comp) {
    assert(array);
    assert(pivot);

    char* arr = (char*)array;

    if (len == 0 || len == 1) return;
    else if (len <= 3)
        small_sort(arr, len, elem_size, comp);

    memcpy(pivot, arr, elem_size);

    size_t left = 0;
    size_t right = len - 1;
    while (1) {
        while (comp(arr + left * elem_size, pivot) < 0) left++;
        while (comp(pivot, arr + right * elem_size) < 0) right--;
        if (left >= right) break;

        swap(arr + left * elem_size, arr + right * elem_size, elem_size);
        left++;
        right--;
    }

    quick_sort(arr, right + 1, pivot, elem_size, comp);
    quick_sort(arr + (right + 1) * elem_size, len - (right + 1), pivot, elem_size, comp);
}

void small_sort(void* array, size_t len, size_t elem_size, comp_t* comp) {
    assert(array);
    assert(2 <= len && len <= 3);

    char* arr = (char*)array;

    if (len <= 3) {
        if(comp(arr, arr + 1 * elem_size) > 0)
            swap(arr, arr + 1 * elem_size, elem_size);
    }
    if (len == 3) {
        if(comp(arr + 1 * elem_size, arr + 2 * elem_size) > 0)
            swap(arr + 1 * elem_size, arr + 2 * elem_size, elem_size);

        if(comp(arr, arr + 1 * elem_size) > 0)
            swap(arr, arr + 1 * elem_size, elem_size);
    }
}
