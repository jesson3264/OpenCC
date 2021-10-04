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

#include "test-skiplist.h"
#include "skiplist.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT	10
int test_skiplist()
{

    skip_list_t sl;
	int i, tmp, *keys;

	keys = (int*)malloc(COUNT*sizeof(int));

	srand(time(NULL));

	sl = skip_list_create();

	for(i=0; i<COUNT; i++) {
		keys[i] = rand();
		tmp = rand();
		//printf("put %5d : %5d, return %5d", keys[i], tmp, (int)skip_list_put(sl, keys[i], (void*)tmp));
		printf(", count=%d\n", skip_list_count(sl));
	}

	puts("*****************************************");

	for(i=0; i<COUNT; i++) {
		;//printf("put %5d : %5d, return %d\n", keys[i], keys[i], (int)skip_list_put(sl, keys[i], (void*)keys[i]));
	}

	puts("*****************************************");

	skip_list_key_set(sl, keys, COUNT);
	printf("key set : ");
	for(i=0; i<COUNT-1; i++) {
		printf("%d, ", keys[i]);
	}
	printf("%d\n", keys[COUNT-1]);

	puts("*****************************************");

	for(i=0; i<COUNT; i++) {
		;//printf("get %5d, return %d\n", keys[i], (int)skip_list_get(sl, keys[i]));
	}

	puts("*****************************************");

	for(i=0; i<COUNT; i++) {
		printf("constains %5d, return %d\n", keys[i], skip_list_contains(sl, keys[i]));
	}

	puts("*****************************************");

	for(i=0; i<COUNT; i++) {
		;//printf("remove %5d, return %5d", keys[i], (int)skip_list_remove(sl, keys[i]));
		printf(", count=%d\n", skip_list_count(sl));
	}

	puts("*****************************************");

	for(i=0; i<COUNT; i++) {
		printf("constains %5d, %d\n", keys[i], skip_list_contains(sl, keys[i]));
	}

	skip_list_destroy(sl);

	free(keys);

	return 0;
}