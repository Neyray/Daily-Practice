#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <immintrin.h>

#define IDENT 0
#define OP +
#define data_t int

typedef struct {
    size_t len;
    data_t* data;
} vec;

void combine(vec* v, data_t* dest) {
    size_t i;
    size_t length = vec_length(v);

    data_t* data = v->data;
    data_t acc0 = IDENT;
    data_t acc1 = IDENT;

    for (i = 0; i < length - 1; i += 2) {
        acc0 = acc0 OP data[i];
        acc1 = acc1 OP data[i + 1];
    }

    for (; i < length; ++i) {
        acc0 = acc0 OP data[i];
    }

    *dest = acc0 OP acc1;
}