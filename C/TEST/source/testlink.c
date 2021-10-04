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
#include "testcommon.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
typedef struct Student
{
	s_node_t node;
	int age;
}Student;

typedef struct Teacher
{
	d_node_t node;
	int salary;

}Teacher;
void testslink()
{
	slist_node_t stu_head;
	slist_init(&stu_head);
	int i = 0;
	for (i = 0; i < 3; ++i)
	{
		struct Student* p = (struct Student*)malloc(sizeof(struct Student));
		p->age = i;
		slist_add_tail(&stu_head, &p->node);
	}
	printf("\n");
	s_node_t *pos = NULL;
	slist_for_each(pos, &stu_head)
	{
		printf("age:%d ", ((Student*)pos)->age);
	}

	for (i = 0; i < 3; ++i)
	{
		struct Student* p = (struct Student*)malloc(sizeof(struct Student));
		p->age = i;
		slist_add_head(&stu_head, &p->node);
	}
	printf("\n");
	// show   2 1 0 0 1 2 
	
	slist_for_each(pos, &stu_head)
	{
		printf("age:%d ", ((Student*)pos)->age);
	}
}



void testdlink()
{
	d_node_t dlist_head;

	dlist_init(&dlist_head);
	int i = 0;
	for (i = 0; i < 3; ++i)
	{
		struct Teacher* p = (struct Teacher*)malloc(sizeof(struct Teacher));
		p->salary = 1000*i+1000;
		dlist_add_tail(&dlist_head, &p->node);
	}

	printf("\n");
	d_node_t* pos = NULL;
	//
	printf("Clockwise traversal.\n");
	dlist_for_each(pos, &dlist_head)
	{
		printf("salary:%d ", ((Teacher*)pos)->salary);
	}
	printf("\n");
	printf("anticlockwise traversal.\n");
	struct Teacher* teac = NULL;
	dlist_reverse_for_each(pos, &dlist_head)
	{
		teac = container_of(pos, struct Teacher, node);
		//printf("salary:%d ", ((Teacher*)pos)->salary);
		printf("salary:%d ", teac->salary);
	}
	printf("\ncount:%d\n", dlist_size(&dlist_head));


	pos = dlist_peek_head(&dlist_head);
	teac = container_of(pos, struct Teacher, node);
	assert(teac->salary == 1000);
	// ɾ��ͷԪ��
	pos = dlist_remove_from_head(&dlist_head);
	teac = container_of(pos, struct Teacher, node);
	printf("\ncount:%d\n", dlist_size(&dlist_head));
	assert(teac->salary == 1000);
	free(teac);

	pos = dlist_peek_tail(&dlist_head);
	teac = container_of(pos, struct Teacher, node);
	assert(teac->salary == 3000);

	// ɾ��βԪ��
	pos = dlist_remove_from_tail(&dlist_head);
	teac = container_of(pos, struct Teacher, node);
	printf("\ncount:%d\n", dlist_size(&dlist_head));
	assert(teac->salary == 3000);
	free(teac);


	pos = dlist_peek_tail(&dlist_head);
	teac = container_of(pos, struct Teacher, node);
	assert(teac->salary == 2000);

	printf("\ncount:%d\n", dlist_size(&dlist_head));

	printf("\n");
}