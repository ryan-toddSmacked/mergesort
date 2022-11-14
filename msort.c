
#include <stdlib.h>
#include <string.h>
#include "msort.h"


#ifndef INSERTION_SORT_SIZE
# define INSERTION_SORT_SIZE (10)
#endif



void merge_ADT(void*, void*, size_t N, void*, size_t M, size_t size, int (*)(const void*,const void*));
void mergesort_ADT(void*, void*, size_t l, size_t r, void*, size_t size, int (*)(const void*,const void*));
void insertion_ADT(void*, size_t l, size_t r, void*, size_t size, int (*)(const void*,const void*));


void* msort_ADT(void* vals, size_t elem_size, size_t elem_count, int (*__compar_fn_t)(const void*,const void*))
{
    void* aux = malloc(elem_size * elem_count);
    void* T = malloc(elem_size);
    if (aux == NULL || vals == NULL)
        return NULL;

    memcpy(aux, vals, elem_size * elem_count);
    mergesort_ADT(vals, aux, 0, elem_count-1, T, elem_size, __compar_fn_t);
    free(aux);
    free(T);
    return vals;
}

void mergesort_ADT(void* a, void* b, size_t l, size_t r, void* v, size_t size, int (*f)(const void*,const void*))
{
    size_t m = (l + (r - l) / 2);
    if ((r-l) <= INSERTION_SORT_SIZE)
    {
        insertion_ADT(a, l, r, v, size, f);
        return;
    }
    mergesort_ADT(b, a, l, m, v, size, f);
    mergesort_ADT(b, a, m+1, r, v, size, f);
    merge_ADT((char*)a + (size * l), (char*)b + (size * l), m-l+1, (char*)b + (size * (m+1)), r-m, size, f);
}

void merge_ADT(void* c, void* a, size_t N, void* b, size_t M, size_t size, int (*f)(const void*,const void*))
{
    size_t i, j, k;
    for (i = 0, j = 0, k = 0; k < (N+M); k++)
    {
        if (i == N)
        {
            memcpy((char*)c + (size * k), (char*)b + (size * j), size);
            j++;
            continue;
        }
        if (j == M)
        {
            memcpy((char*)c + (size * k), (char*)a + (size * i), size);
            i++;
            continue;
        }
        if (f((char*)a + (size * i), (char*)b + (size * j)) == -1)
        {
            memcpy((char*)c + (size * k), (char*)a + (size * i), size);
            i++;
        }
        else
        {
            memcpy((char*)c + (size * k), (char*)b + (size * j), size);
            j++;
        }
    }
}


void insertion_ADT(void* a, size_t l, size_t r, void* v, size_t size, int (*f)(const void*,const void*))
{
    size_t i;
    for (i = r; i > l; i--)
    {
        if (f((char*)a + (size * i), (char*)a + (size * (i-1))) == -1)
        {
            memcpy(v, (char*)a + (size * (i-1)), size);
            memcpy((char*)a + (size * (i-1)), (char*)a + (size * i), size);
            memcpy((char*)a + (size * i), v, size);
        }
    }

    for (i = l+2; i <= r; i++)
    {
        size_t j = i; memcpy(v, (char*)a + (size * i), size);
        while (f(v, (char*)a + (size * (j-1))) == -1)
        {
            memcpy((char*)a + (size * j), (char*)a + (size * (j-1)), size);
            j--;
        }
        memcpy((char*)a + (size * j), v, size);
    }
}



