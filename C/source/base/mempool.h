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

/*
代码基本复制于 acl
*/
#ifndef __MEM_POOL_H
#define __MEM_POOL_H
#include <stdio.h>

typedef struct SCL_DBUF_POOL SCL_DBUF_POOL;
/**
* 创建内存池对象
* @param block_size {size_t} 内存池中每个连续内存块的大小（字节）
* @return {ACL_DBUF_POOL*} 返回非 NULL 对象
*/
SCL_DBUF_POOL *scl_dbuf_pool_create(size_t block_size);

/**
* 销毁内存池
* @param pool {ACL_DBUF_POOL*} 对象池对象
*/
void scl_dbuf_pool_destroy(SCL_DBUF_POOL *pool);

/**
* 分配指定长度的内存
* @param pool {ACL_DBUF_POOL*} 对象池对象
* @param  len {size_t} 需要分配的内存大小
* @return {void*} 新分配的内存地址
*/
void *scl_dbuf_pool_alloc(SCL_DBUF_POOL *pool, size_t len);

/**
* 归还由内存池分配的内存
* @param pool {ACL_DBUF_POOL*} 对象池对象
* @param addr {const void*} 由内存池分配的内存地址
* @return {int} 如果该内存地址非内存池分配或释放多次，则返回 -1，操作成功则
*  返回 0
*/
int scl_dbuf_pool_free(SCL_DBUF_POOL *pool, const void *addr);

#endif
