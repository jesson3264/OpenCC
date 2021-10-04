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

/*****************************
Stack
Stacks are a type of container, 
specifically designed to operate in a LIFO context (last-in first-out), 
where elements are inserted and extracted only from one end of the container.

*******************************/

#ifndef __CSTACK_H__
#define __CSTACK_H__
#include "dscommon.h"
// the name s_entry_t has defined, so, use st_node_t representive of stack node.

typedef struct d_node_s  st_node_t;
#define T st_node_t  
#define StackNode T

void stack_init(T* stack);

StackNode* stack_top(T* stack);

StackNode* stack_pop(T* stack);

void stack_push(st_node_t* stack, st_node_t* node);

int stack_empty(st_node_t* stack);

#undef StackNode
#undef T
#endif 
