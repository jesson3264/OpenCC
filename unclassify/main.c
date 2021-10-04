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
char** os_argv;
char*  os_argv_last;

void init_setproctitle()
{
	char * p;
	size_t size;
	int i;
	size = 0;
	os_argv_last = os_argv[0];
	for (i = 0; os_argv[i]; ++i)
	{
		if (os_argv_last == os_argv[i])
		{
			size += strlen(os_argv[i]) + 1;
			printf("i:%d size:%d\n", i, size);	
			os_argv_last = os_argv[i] + strlen(os_argv[i]) + 1;
		}
	}

	printf("len:%d os_argv_last:%s\n", os_argv_last - os_argv[0], os_argv_last);
	// 移动到了环境变量的最后
	os_argv_last += strlen(os_argv_last);
}

void save_argv(int argc, const char** argv)
{
	os_argv = (char **) argv;
}

void setproctitle(char *title)
{
	char  *p;
	os_argv[1] = NULL;

	p = strncpy((char *) os_argv[0], (char *) title,
			strlen(title));
	p += strlen(title);

	if (os_argv_last - (char *) p > 0) {
		printf("后面部分清零\n");
		memset(p, 0, os_argv_last - (char *) p);
	}

}

int main(int argc, char** argv)
{
	save_argv(argc, argv);
	init_setproctitle();
	setproctitle("xxxxyyyyyyyyyyyyyyyyyyyyyyyyyyyxxxxxxxx");

	printf("%s\n", argv[0]);
	while (1) ;
	return 0;
}
