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

#include "scl_deque.h"
#include "scl_double_list.h"
#include <stdlib.h>

void dqueue_init(dq_node_t* dqueue)
{
	if (!dqueue)
		return;
	dqueue->next = dqueue;
	dqueue->prev = dqueue;
}

void dqueue_clear(dq_node_t* dqueue)
{

}

void dqueue_push_back(dq_node_t* dqueue, dq_node_t* newnode)
{
	if (!dqueue || !newnode)
		return;
	dl_node_add(dqueue->prev, dqueue, newnode);
}

void dqueue_push_front(dq_node_t* dqueue, dq_node_t* newnode)
{
	if (!dqueue || !newnode)
		return;
	dl_node_add(dqueue, dqueue->next, newnode);
}

dq_node_t* dqueue_pop_back(dq_node_t* dqueue)
{
	return dlist_remove_from_tail(dqueue);
}

dq_node_t* dqueue_pop_front(dq_node_t* dqueue)
{
	dq_node_t* ret = NULL;
	if (!dqueue)
		return NULL;
	if (dqueue->next == dqueue)
		return NULL;
	ret = dqueue->next;
	dl_node_remove(dqueue, dqueue->next->next);
	return ret;
}

dq_node_t* dqueue_front(dq_node_t* dqueue)
{
	return dlist_peek_head(dqueue);
}

dq_node_t* dqueue_back(dq_node_t* dqueue)
{
	return dlist_peek_tail(dqueue);
}
