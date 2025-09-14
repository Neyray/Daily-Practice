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

// 声明 vec_length 和 get_vec_element 函数
size_t vec_length(vec* v);
int get_vec_element(vec* v, size_t idx, data_t* val);

void combine(vec* v, data_t* dest) {
    size_t length = vec_length(v);
    if (length == 0) { // 空数组处理
        *dest = IDENT;
        return;
    }

    data_t acc0 = IDENT;
    data_t acc1 = IDENT;

    // 循环展开
    size_t i;
    for (i = 0; i + 1 < length; i += 2) {
        acc0 += v->data[i];
        acc1 += v->data[i + 1];
    }

    // 处理剩余元素
    if (i < length) {
        acc0 += v->data[i];
    }

    *dest = acc0 + acc1;
}
