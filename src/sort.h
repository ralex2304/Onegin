#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <assert.h>

#include "text/text_lib.h"
#include "utils/rand_wrapper.h"

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
void swap(void* a, void* b, size_t size);

#endif // #ifndef SORT_H_
