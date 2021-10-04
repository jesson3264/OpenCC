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

/*********************************
single linked queue
*********************************/

#ifndef __SQUEUE_H__
#define __SQUEUE_H__
#include "dscommon.h"

/*
@function : 
initialization
*/
void squeue_init(sq_node_t* squeue);
/*
@function :
Inserts a new element at the end of the queue, after its current last element. 
The content of this new element is initialized to val.
*/
void squeue_push(sq_node_t* squeue, sq_node_t* newnode);
/*
@function : 
Removes the next element in the queue, effectively reducing its size by one.
The element removed is the "oldest" element in the queue whose value can be retrieved by calling member queue::front.
This calls the removed element's destructor.
*/
sq_node_t* squeue_pop(sq_node_t* squeue);
/*
@function :
Returns a pointer to the last element in the queue. 
	This is the "newest" element in the queue 
	(i.e. the last element pushed into the queue).
*/
sq_node_t* squeue_back(sq_node_t* squeue);

sq_node_t* squeue_front(sq_node_t* squeue);

/*
@function :
Returns whether the queue is empty: i.e. whether its size is zero.
*/
int squeue_empty(sq_node_t* squeue);




#endif