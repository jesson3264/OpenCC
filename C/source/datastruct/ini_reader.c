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

#include "ini_reader.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void func_erase_val_chash_s_s(void* val)
{
	chash_destroy((chash*)val);
}

static chash* create_section_hash(void)
{
	chash* hash = chash_create(13,
		func_clone_key_str,		// key is string
		func_destroy_val_str,// 
		func_clone_val_str,		// val is string
		func_destroy_val_str,
		func_hash_key_str,
		func_key_cmp_str);
	return hash;
}

IniFile* inifile_open(const char* filepath)
{
	(void)filepath;

	chash* hash = chash_create(13, 
		func_clone_key_str,// sections' type is string
		func_destroy_val_str,
		NULL, // not clone val, because val is a hash 
        func_erase_val_chash_s_s,// hash's destroy hand to IniFile
        func_hash_key_str,//
        func_key_cmp_str);
    
	if (!hash) {
		return NULL;
	}

	char line[MAX_LINE_LEN] = { 0 };
	char key[MAX_LINE_LEN / 2] = { 0 };
	char val[MAX_LINE_LEN / 2] = { 0 };

	do {
#if defined(_MSC_VER)
		FILE* fp = NULL;
		fopen_s(&fp, filepath, "r");
#else 
		FILE* fp = fopen(filepath, "r");
#endif 
		if (!fp) {
			break;
		}

		while (fgets(line,sizeof(line) - 1, fp) != NULL) {

			printf("line:%s\n", line);
		}

	} while (0);

	char* names_section = "names";
	chash* cur_hash = NULL;
	chash_node_t* tnode = chash_get(hash, names_section);
	if (!tnode)
	{
		printf("it not exist section of names. Then create...\n");
		cur_hash = create_section_hash();
		assert(cur_hash != NULL);

		char* name1 = "zhangsan";
		chash_add(cur_hash, "name1", name1);
		
		char* name2 = "lisi";
		chash_add(cur_hash, "name2", name2);

		chash_add(hash, names_section, cur_hash);
	}
	else
	{
		cur_hash = (chash*)tnode->val;
	}

	IniFile* ini = NULL;
	ini = (IniFile*)calloc(1, sizeof(IniFile));
	if (!ini)
	{
		return NULL;
	}

	ini->ihash = hash;
	return ini;
}

int inifile_close(IniFile* ini)
{
	// todo
	(void)ini;
	return 0;
}

int inifile_get(IniFile* ini, char* section, char* key, IniNode* res)
{
	if (!ini) {
		return -1;
	}

	chash* all = ini->ihash;
	chash_node_t* inner = (chash_node_t*)chash_get(all, section);
	if (!inner) {
		return -1;
	}

	res->section_name = inner->key;
	chash_node_t* inner_node = chash_get(inner->val, key);
	if (!inner_node) {
		return -1;
	}

	res->key = inner_node->key;
	res->val = inner_node->val;

	return 0;
}