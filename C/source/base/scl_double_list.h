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

/****
module: double linked list
*****/
#ifndef __DLIST_H__
#define __DLIST_H__
#include "dscommon.h"
#include <stdlib.h>

void dlist_init(d_node_t* head);

void dlist_add_tail(d_node_t* head, d_node_t* newnode);

void dlist_add_head(d_node_t* head, d_node_t* newnode);

// return the removed element pointer
d_node_t* dlist_remove_from_head(d_node_t* head);

d_node_t* dlist_remove_from_tail(d_node_t* head);

// get the first element from head.
d_node_t* dlist_peek_head(d_node_t* head);

// get the last element 
d_node_t* dlist_peek_tail(d_node_t* head);

int dlist_size(d_node_t* head);

#define dlist_for_each(pos, head) \
	for (pos = (head)->next; pos != head; pos = pos->next)

#define dlist_reverse_for_each(pos, head)  \
	for (pos = (head)->prev; pos != head; pos = pos->prev)

#endif 
