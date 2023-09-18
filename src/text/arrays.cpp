#include "arrays.h"

void* arrdup(void* src, size_t len, size_t elem_size) {
    assert(src);

    void* output = calloc(len, elem_size);

    if (output == nullptr)
        return nullptr;

    memcpy(output, src, len * elem_size);

    return output;
}
