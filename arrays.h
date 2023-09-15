#ifndef ARRAYS_H_
#define ARRAYS_H_

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * @brief Creates array of arrays
 *
 * @param arrays pointer to an array of arrays
 * @param array_size size of one array
 * @param arrays_cnt number of arrays in array
 * @param elem_size
 * @return true success
 * @return false failure
 */
bool create_several_arrays(void** arrays, const size_t array_size, const size_t arrays_cnt, const size_t elem_size);

#endif /// #ifndef ARRAYS_H_
