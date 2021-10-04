/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2020 邓俊兴 (Deng Junxing)
 * Email : jesson3264@163.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * @file      c_sharemem.h
 * @author    jesson3264@163.com
 * @brief     2021-01-02
 * @details
 * @interface
 **/
#ifndef MEMORY_C_SHAREMEM_H
#define MEMORY_C_SHAREMEM_H
#include "c_memcomm.h"

enum { SHARE_MAX_BYTES = 4096 };
enum { SHARE_NFREELISTS = SHARE_MAX_BYTES / ALIGN};

#define SHARE_MEM_ERROR__PARAMETER   1
#define SHARE_MEM_ERROR__MMAP_FAIL   2
#define SHARE_MEM_ERROR__NO_MEMORY   3  ///< no memory
#define SHARE_MEM_ERROR__NO_SPACE    4  ///< init space is used.


struct CShareMemPool;

typedef int (*ErrorCallback)(struct CShareMemPool* smp, const char* filename, int line, int errorno);

typedef struct CShareMemPool
{
    char* share_mem_start;
    ErrorCallback call_back;   ///< if occour error, it will be call.
    size_t  total_size;
    union obj* free_list[SHARE_NFREELISTS];
    char* start_free;
    char* end_free;
}CShareMemPool;

/**
 * @brief if occour error, then revoke call_back
**/
CShareMemPool* ShareCreateMempool(size_t memsize, ErrorCallback call_back);

void ShareDestroyMempool(CShareMemPool* );

void* ShareAllocate(CShareMemPool* , size_t n);

void ShareDeAllocate(CShareMemPool* , void* p);

/**
 * for debug.
 */
void ShowShareMempoolInfo(CShareMemPool*);
#endif
