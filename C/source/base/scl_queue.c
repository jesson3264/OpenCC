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

#include "scl_queue.h"
#include "dscommon.h"
#include <stdlib.h>

/*
prev <-- | head |  --> next
queue tail -- queue head --- queue front
*/
/*
@function init, the squeue has one head node, link double linkedlist
*/
void squeue_init(sq_node_t* squeue)
{
	squeue->next = squeue;
	squeue->prev = squeue;
}

// add node to the tail.
void squeue_push(sq_node_t* squeue, sq_node_t* newnode)
{
	if (!squeue || !newnode)
		return ;
	dl_node_add(squeue->prev, squeue, newnode);
}

// remove node from the head.
sq_node_t* squeue_pop(sq_node_t* squeue)
{
	sq_node_t* ret = NULL;
	if (!squeue)
		return NULL;
	if (squeue->next == squeue)
		return NULL;
	ret = squeue->next;
	dl_node_remove(squeue, squeue->next->next);
	return ret;
}

// obtain the queue back ele
sq_node_t* squeue_back(sq_node_t* squeue)
{
	if (!squeue)
		return NULL;
	if (squeue->next == squeue)
		return NULL;
	return squeue->prev;
}

sq_node_t* squeue_front(sq_node_t* squeue)
{
	if (!squeue || (squeue->next == squeue))
		return NULL;
	return squeue->next;
}

/*
@function Returns whether the queue is empty: i.e. whether its size is zero.
*/
int squeue_empty(sq_node_t* squeue)
{
	return (squeue->next == squeue) ? 1 : 0;
}
