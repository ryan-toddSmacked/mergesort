#ifndef __MSORT_C_DECL_H
#define __MSORT_C_DECL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Needed for size_t typedef */
#include <stddef.h>



/*************************************************************************************
 * In place merge sort.
 *
 * Inputs:
 *     void*  vals       - Pointer to elements to sort
 *     size_t elem_size  - Size of each element in bytes
 *     size_t elem_count - Number of elements
 *
 *     int (*_comp)(const void*, const void*) - Function pointer
 *
 * Output:
 *      void* - Pointer to sorted elements
 *
 * Function Comparator Example, Sorting Type { int }
 *  int compare_int(const void* L, const void* R)
 *  {
 *      int _L = *(int*)L; int _R = *(int*)R;
 *      if (_L <  _R) return -1;
 *      if (_L == _R) return  0;
 *      if (_L >  _R) return  1;
 *      return 0;
 *  }
 *************************************************************************************/
void* msort_ADT(void* vals, size_t elem_size, size_t elem_count, int (*_comp)(const void*,const void*));



#ifdef __cplusplus
}
#endif

#endif
