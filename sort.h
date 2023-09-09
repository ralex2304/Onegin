#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <assert.h>

#include "text_lib.h"

typedef int comp_t(const void* a, const void* b);

int str_comp(const void* a, const void* b);

int str_comp_suf(const void* a, const void* b);

int int_comp(const void* a, const void* b);

void quick_sort(void* arr, size_t len, void* const pivot, size_t elem_size, comp_t* comp);

inline void swap(void* a, void* b, size_t size) {
    assert(a);
    assert(b);

    for (size_t i = 0; i < size; i++) {
        char c = ((char*)a)[i];
                 ((char*)a)[i] = ((char*)b)[i];
                                 ((char*)b)[i] = c;
    }
}

#endif // #ifndefSORT_H_
