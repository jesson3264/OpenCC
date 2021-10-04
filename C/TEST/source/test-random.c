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

#include "test-random.h"
#include "uuid.h"
#include <stdio.h>
#include <stdlib.h>

void show(uuid_t src,char *out)
{
    unsigned char* p = (unsigned char*)src;
    int i = 0; 
    int j = 0;
    for (i = 0; i < sizeof(uuid_t); ++i)
    {
        int g = (*(p + i))%16;
        int s = (*(p + i))/16;
        out[j++] = (s >= 10) ? ('a' + s - 10) : ('0' + s);
        out[j++] = (g >= 10) ? ('a' + g - 10) : ('0' + g);
        
        printf("%02x ", *(p + i));
    }
        
    printf("\n");
}
void gen_random()
{
    uuid_t out;
    char dst[33] = {0};
    int i = 0;
    for (i = 0; i < 20; ++i)
    {
        uuid_generate(out);
        //printf("uuid:%s\n", out);
        show(out, dst);
        printf("dst:%s\n", dst);
    }
}