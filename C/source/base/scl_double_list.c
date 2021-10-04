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

#include "scl_double_list.h"
void dlist_init(d_node_t* head)
{
	if (!head) 
		return ;
	head->next = head;
	head->prev = head;
}

void dlist_add_tail(d_node_t* head, d_node_t* newnode)
{
	if (!head || !newnode) 
		return ;

	dl_node_add(head->prev, head, newnode);
}

void dlist_add_head(d_node_t* head, d_node_t* newnode)
{
	if (!head || !newnode) 
		return ;

	dl_node_add(head, head->next, newnode);
}

d_node_t* dlist_remove_from_head(d_node_t* head)
{
	d_node_t* ret = NULL;
	if (!head)
		return NULL;
	//  empty
	if (head->next == head)
		return NULL;

	ret = head->next;
	dl_node_remove(head, head->next->next);
	
	return ret;
}

d_node_t* dlist_remove_from_tail(d_node_t* head)
{
	d_node_t* ret = NULL;
	if (!head)
		return  NULL;
	if (head->next == head)
		return NULL;

	ret = head->prev;
	dl_node_remove(head->prev->prev, head);
	return ret;
}

// get the first element from head.
d_node_t* dlist_peek_head(d_node_t* head)
{
	if (!head)
		return NULL;
	// empty list.
	if (head->next == head)
		return NULL;

	return head->next;
}

// get the last element 
d_node_t* dlist_peek_tail(d_node_t* head)
{
	if (!head)
		return NULL;
	if (head->next == head)
		return NULL;
	return head->prev;
}

int dlist_size(d_node_t* head)
{
	if (!head || (head->next == head))
		return 0;
	int cnt = 0;
	d_node_t* pos = NULL;
	dlist_for_each(pos, head)
	{
		cnt++;
	}

	return cnt;
}
