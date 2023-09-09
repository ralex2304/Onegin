#include "sort.h"


int str_comp(const void* a, const void* b) {
    return strcmp_is_alpha(*(const char* const*)a, *(const char* const*)b);
}

int str_comp_suf(const void* a, const void* b) {
    return strcmp_is_alpha_suf(*(const char* const*)a, *(const char* const*)b);
}

int int_comp(const void* a, const void* b) {
    return *((const int*)a) - *((const int*)b);
}

void quick_sort(void* arr, size_t len, void* const pivot, size_t elem_size, comp_t* comp) {
    if (len == 0 || len == 1) return;
    else if (len == 2) {
        if (comp(arr, (char*)arr + 1 * elem_size) > 0)
            swap(arr, (char*)arr + 1 * elem_size, elem_size);
        return;
    } else if (len == 3) {
        if (comp(arr, (char*)arr + 1 * elem_size) > 0)
            if (comp((char*)arr + 1 * elem_size, (char*)arr + 2 * elem_size) > 0) {
                swap(arr, (char*)arr + 2 * elem_size, elem_size);
            } else {
                swap(arr, (char*)arr + 1 * elem_size, elem_size);
                swap((char*)arr + 1 * elem_size, (char*)arr + 2 * elem_size, elem_size);
            }
        else if (comp((char*)arr + 1 * elem_size, (char*)arr + 2 * elem_size) > 0) {
            swap((char*)arr + 1 * elem_size, (char*)arr + 2 * elem_size, elem_size);
            swap(arr, (char*)arr + 1 * elem_size, elem_size);
        }
    }

    memcpy(pivot, (char*)arr, elem_size);

    size_t left = 0;
    size_t right = len - 1;
    while (1) {
        while (comp((char*)arr + left * elem_size, pivot) < 0) left++;
        while (comp(pivot, (char*)arr + right * elem_size) < 0) right--;
        if (left >= right) break;

        swap((char*)arr + left * elem_size, (char*)arr + right * elem_size, elem_size);
        left++;
        right--;
    }

    quick_sort(arr, right + 1, pivot, elem_size, comp);
    quick_sort((char*)arr + (right + 1) * elem_size, len - (right + 1), pivot, elem_size, comp);
}
