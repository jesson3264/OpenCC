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

#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <stdinit.h>
#if defined(_MSC_VER)
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#else
#include <sys/types.h>
#endif

#define T chash_node_t 

size_t default_hash_key(void* val)
{
    if (!val) {
        return 0;
    }
    size_t hash = 0;
    const char* str = (char*)val;
    const char* p;
    for (p = str; *p; ++p) {
        hash += hash * 33 + *p;
    }

    return hash;
}

chash* chash_create(size_t bucket_size,
    func_clone_key fmk,
    func_destroy_key ffk,
    func_clone_val fmv,
    func_destroy_val ffv, 
    func_hash_key fhash,
    func_key_cmp key_cmp)
{
    if (bucket_size == 0) {
        return NULL;
    }

    chash* hash = (chash*)calloc(1, sizeof(chash));
    size_t tmp = sizeof(*hash->buckets);
    T** nodes = (T**)calloc(tmp, bucket_size);
    if (!hash || !nodes) {
        return NULL;
    }

    hash->buckets = (T**)nodes;
    hash->nbuckets = bucket_size;

    hash->malloc_key = fmk;
    hash->free_key = ffk;
    hash->malloc_val = fmv;
    hash->free_val = ffv;
    hash->key_cmp = key_cmp;

    if (!fhash)
        hash->fhash = default_hash_key;
    else
        hash->fhash = fhash;

    return hash;
}

T* chash_add(chash* hash, void* key, void* val)
{
    if (!key) {
        return NULL;
    }

    size_t hash_val = hash->fhash(key);
    size_t index = hash_val % hash->nbuckets;
    if (hash->buckets[index] == NULL)
    {
        printf("index : is null.\n");
    }

    T t;
    T* pre = &t;
    pre->next = hash->buckets[index];
    T* node = pre->next;
    while (node) {
        if (hash->key_cmp(node->key, key) == 0) {
            break;
        }

        pre = node;
        node = node->next;
    }

    if (node) { //exist
        if (hash->free_val) {
            hash->free_val(node->val);
        }

        node->val = val;
    } else {
        node = (T*)malloc(sizeof(T));
        if (!node)
        {
            return NULL;
        }

        node->key = key;
        node->val = val;
        if (hash->malloc_key) {
            node->key = hash->malloc_key(key);
        }

        if (hash->malloc_val) {
            node->val = hash->malloc_val(val);
        }
        
        node->next = pre->next;
        hash->buckets[index] = node;
    }

    return node;
}

T* chash_get(chash* hash, void* key)
{
    size_t hash_val = hash->fhash(key);
    size_t index = hash_val % hash->nbuckets;
    T t;
    T* pre = &t;
    pre->next = hash->buckets[index];
    T* node = pre->next;

    while (node) {
        if (hash->key_cmp) {
            if (hash->key_cmp(key, node->key) == 0 ) {
                break;
            }
        }

        node = node->next;
    }

    return node;
}

static int chash_free_node(chash* hash, T* node)
{
    if (!hash || !node) {
        return -1;
    }

    if (hash->free_key) {
        hash->free_key(node->key);
    }

    if (hash->free_val) {
        hash->free_val(node->val);
    }

    free(node);
    return 0;
}

int chash_remove(chash* hash, void* key)
{
    size_t hash_val = hash->fhash(key);
    size_t index = hash_val % hash->nbuckets;
    // 用一个临时节点，方便编程
    T t;
    T* pre = &t;
    pre->next = hash->buckets[index];
    T* node = pre->next;
    while (node) {
        if (hash->key_cmp) {
            if (hash->key_cmp(key, node->key) == 0) {
                break;
            }
        }

        pre = node;
        node = node->next;
    }

    if (node)
    {
        pre->next = node->next;
    }

    chash_free_node(hash, node);

    return 0;
}

int chash_destroy(chash* hash)
{
    size_t i = 0; 
    T pre;
    for (i = 0; i < hash->nbuckets; ++i) {
        pre.next = hash->buckets[i];
        T* node = pre.next;
        while (node) {
            pre.next = node->next;
            if (hash->free_val) {
                hash->free_val(node->val);
            }

            if (hash->free_key) {
                hash->free_key(node->key);
            }

            free(node);
            node = pre.next;
        }
    }

    free(hash->buckets);
    free(hash);
    return 0;
}

void* func_clone_key_str(void* key)
{
    const char* str = (char*)key;
    size_t len = strlen(str) + 1;
    char* t = (char*)malloc(len);
    if (!t) {
        return NULL;
    }
    memcpy(t, str, len);
    return (void*)t;
}

void func_destroy_key_str(void* key)
{
    free(key);
}

void* func_clone_val_str(void* key)
{
    const char* str = (char*)key;
    size_t len = strlen(str) + 1;
    unsigned char* t = (unsigned char*)malloc(len);
    if (!t) {
        return NULL;
    }
    memcpy(t, str, len);
    return (void*)t;
}

void func_destroy_val_str(void* key)
{
    free(key);
}

/*
 * @brief use "times 33" hash algorithm
 * @
 * @ 
**/
size_t func_hash_key_str(void* key)
{
    const char* p;
    p = (char*)key;
    size_t hash = 0;
    ssize_t i = 0;
    ssize_t len = strlen(p);
    for (; i < len; p++, i++) {
        hash = hash * 33 + *p;
    }

    return hash;
}

size_t hash_int(void* key)
{
    return (size_t)(*((int*)key));
}

int func_key_cmp_str(void* key1, void* key2)
{
    const char* str1 = (char*)key1;
    const char* str2 = (char*)key2;
    return strcmp(str1, str2);
}

void* func_clone_val_int(void* key)
{
    int* k = (int*)key;
    int* t = (void*)malloc(sizeof(*k));
    if (!t) {
        return NULL;
    }

    memcpy(t, k, sizeof(*k));
    return (void*)t;
}