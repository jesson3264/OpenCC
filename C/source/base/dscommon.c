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

#include "dscommon.h"

// single link node add.
void sl_node_add(s_node_t* prev, s_node_t* next, s_node_t* newnode)
{
	if (!prev || !next || !newnode)
		return ;
	newnode->next = next;
	prev->next = newnode;
}

// single link node remove.
void sl_node_remove(s_node_t* prev, s_node_t* next)
{
	if (!prev || !next)
		return ;
	prev->next = next;
}

// double link node add.
void dl_node_add(d_node_t* prev, d_node_t* next, d_node_t* newnode)
{
	if (!newnode || !prev || !next) 
		return ;
	next->prev = newnode;
	newnode->next = next;
	newnode->prev = prev;
	prev->next = newnode;
}

// remove node from prev to next.
void dl_node_remove(d_node_t* prev, d_node_t* next)
{
	prev->next = next;
	next->prev = prev;
}
