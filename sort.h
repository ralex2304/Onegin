#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <assert.h>

#include "text_lib.h"

/**
 * @brief Comparator func template
 *
 * @param a
 * @param b
 * @return typedef
 */
typedef int comp_t(const void* a, const void* b);

/**
 * @brief String comparator (uses stringcmp_isalpha)
 *
 * @param a
 * @param b
 * @return int
 */
int string_comp(const void* a, const void* b);

/**
 * @brief Suffix string comparator (uses stringcmp_isalpha_suf)
 *
 * @param a
 * @param b
 * @return int
 */
int string_comp_suf(const void* a, const void* b);

/**
 * @brief Int comparator
 *
 * @param a
 * @param b
 * @return int
 */
int int_comp(const void* a, const void* b);

/**
 * @brief Quick sort algorithm
 *
 * @param array data array pointer
 * @param len array len
 * @param pivot buffer variable
 * @param elem_size array element size
 * @param comp comparator func pointer
 */
void quick_sort(void* array, size_t len, void* const pivot, size_t elem_size, comp_t* comp);

/**
 * @brief Sorts an array of 2 or 3 elements
 *
 * @param array data array pointer
 * @param len array len
 * @param elem_size array element size
 * @param comp comparator func pointer
 */
void small_sort(void* array, size_t len, size_t elem_size, comp_t* comp);

/**
 * @brief Swaps variables
 *
 * @param a
 * @param b
 * @param size
 */
inline void swap(void* a, void* b, size_t size) {
    assert(a);
    assert(b);

    for (size_t i = 0; i < size; i++) {
        char c = ((char*)a)[i];
                 ((char*)a)[i] = ((char*)b)[i];
                                 ((char*)b)[i] = c;
    }
}

#endif // #ifndef SORT_H_
