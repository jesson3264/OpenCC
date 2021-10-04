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

#include "testlink.h"
#include "testcmap.h"
#include "testqueue.h"
#include "teststack.h"
#include "test-random.h"
#include "test-mempool.h"
#include "scl_miniunit.h"
#include "test-skiplist.h"

#include <stdio.h>
int tests_run = 0;
int main(int argc, char *argv)
{
	//testslink();
	//testdlink();
	printf("Hello World.\n");
	//testqueue();
	//testdqueue2();
	//teststack();
	printf("\n====start test map.===============\n");
	//testmap();
	printf("\n==== start test skiplist.===============\n");
	//test_skiplist();
	printf("\n==== end   test skiplist.===============\n");
	printf("\n");

	fprintf(stderr, "\n====start test_mempool.===============\n");
	test_mempool();
	fprintf(stderr, "\n====end   test_mempool.===============\n");
	fprintf(stderr, "\n====start test-random.===============\n");
	gen_random();
	fprintf(stderr, "\n====end  test- random.===============\n");
	return 0;
}

/*

*/