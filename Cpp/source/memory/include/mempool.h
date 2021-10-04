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

#ifndef __XMEMPOOL_MEMPOOL_H_
#define __XMEMPOOL_MEMPOOL_H_
#include <map>
using std::map;

typedef struct Node Node;
typedef struct BucketInfo BucketInfo;

struct BucketInfo
{
	Node *data;
	int bucketDepth;
	int surplus; /**/ 
};

struct Node
{
	Node* next;
};

class Parameter
{
public:
	static const int Align = 8;
	static const int MaxBytes = 128;
	static const int Buckets = MaxBytes / Align;/* 20 buckets, step 8 bytes*/
};

class XMempool
{
public:
	XMempool();
	~XMempool();
	void Init(size_t depths);
	void* GetMem(int size);

	 
private:
	size_t roundup(int size)
	{
		return ((size + Parameter::Align - 1) & ~(Parameter::Align - 1));
	}

	/**/
	std::map<int, BucketInfo> m_bucket;
	size_t m_bucketDepths;
};

#endif