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

/***
module: singly linked list
*/
#ifndef __SLIST_H__
#define __SLIST_H__
#include "dscommon.h"

//signly link list
typedef struct slist_node_s
{
	s_node_t* head;
	s_node_t* tail;
}slist_node_t;

void slist_init(slist_node_t* slist);

void slist_add_tail(slist_node_t* slist, s_node_t* newnode);

void slist_add_head(slist_node_t* slist, s_node_t* newnode);

// remove the first element from head.
s_node_t* slist_remove_head(slist_node_t* slist);

// get the first element.
s_node_t* slist_peek_head(slist_node_t* slist);

#define slist_for_each(pos, slist) \
	for (pos = (slist)->head;  pos != NULL; pos = pos->next)

#endif 
