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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "hash.h"
#include "ini_reader.h"

void* func_create_key_int(void* key)
{
    int* k = (int*)key;
    int* t = (void*)malloc(sizeof(*k));
    if (!t) {
        return NULL;
    }

    memcpy(t, k, sizeof(*k));
    return (void*)t;
}

void func_erase_key_int(void* key)
{
    free(key);
}

void func_erase_val_int(void* key)
{
    free(key);
}

int func_key_cmp_int(void* key1, void* key2)
{
    return memcmp(key1, key2, sizeof(int));
}

#define TEST_INI_FILE_PATH "D:/ini.ini"

void test_read_ini(void)
{
    printf("start read ini.\n");
    IniFile* ini_file = inifile_open(TEST_INI_FILE_PATH);
    
    IniNode node;
    inifile_get(ini_file, "names", "name1", &node);

    assert(strcmp(node.key, "name1") == 0);
    assert(strcmp(node.val, "zhangsan") == 0);


    return;
}

void test_hash_base(void )
{
    chash* hash = chash_create(13,
        func_create_key_int,
        func_erase_key_int,
        func_clone_val_int,
        func_erase_val_int,
        hash_int,
        func_key_cmp_int);

    int key = 10;
    int val = 11;

    chash_add(hash, &key, &val);
    chash_node_t* get_val = (chash_node_t*)chash_get(hash, &key);

    if (get_val)
        printf("get_val:%d\n", *(int*)(get_val->val));

    chash_remove(hash, &key);
    get_val = (chash_node_t*)chash_get(hash, &key);
    if (get_val)
        printf("get_val:%d\n", *(int*)(get_val->val));
    else {
        printf("get val  failured.\n");
    }
    printf("hello world2\n");

    // memset(apr_palloc(ht->pool, sizeof(*ht->array) * (max + 1)), 0, sizeof(*ht->array) * (max + 1))

}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    test_read_ini();
    return 0;
    
}