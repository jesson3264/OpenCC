/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2020 é‚“ä¿Šå…´ (Deng Junxing)
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

#ifndef __HTTP_RESPONSE_PARSE_H__
#define __HTTP_RESPONSE_PARSE_H__
#include <string>
#include <map>
#include "DataNode.h" 
using std::string;

/*
¶Ô»ØÓ¦µÄ½âÎö 
*/

#define emm_str2_cmp(m, c0, c1) 				\
	m[0] == c0 && m[1] == c1
#define emm_str3_cmp(m, c0, c1, c2)             \
    m[0] == c0 && m[1] == c1 && m[2] == c2
#define emm_str4_cmp(m, c0, c1, c2, c3)			\
	m[0] == c0 && m[1] == c1 && m[2] == c2 && m[3] == c3
enum  HttpParsePhase
{
	HttpParse_Start = 0, 	// »¹Î´»ñÈ¡µ½»ØÓ¦ÐÐ 
	HttpParse_Response, // »ñÈ¡µ½ÁË HTTP/1.1 200 OK
	HttpParse_Headers, 	// »ñÈ¡µ½ÁËËùÓÐ headers 
	HttpParse_Body,		// »ñÈ¡µ½ÁË body 
	HttpParse_End,     	// »ñÈ¡µ½ÁËËùÓÐÊý¾Ý 
}; 


class HttpResponseParse
{
public:
	HttpResponseParse();
	HttpResponseParse(int dn_len);
	~HttpResponseParse();
	
	const string& GetResponseLine();
	HttpParsePhase GetPhase();
	
	// ·µ»ØÊµ¼ÊÑ¹ÈëÊý¾Ý³¤¶È 
	int PushData(const char *src, int len);
	
	DS::DataNode *GetDataNode()
	{
		return m_pdDn; 
	} 
	std::map<string, string> & GetHeaders()
	{
		return m_mHeaders;
	}
	std::map<int, DS::DataNode *> & GetBodys()
	{
		return m_mBodys;
	}
	int GetHttpCode()
	{
		return m_nHttpCode;
	}
	// Ã¿´Îµ÷ÓÃ Parse ¶¼²»´ÓÍ·¿ªÊ¼ Parse, Ö»´Ó½âÎö¹ýµÄÎ»ÖÃ¿ªÊ¼½âÎö
	// ±ÈÈçÒÑ¾­½âÎöµ½ÁË GET ÎªÇëÇó·½·¨£¬ÏÂ´Î¾Í½âÎö 
	int Parse();
	
private:
	int parseResponse();
	int parseHeaders();
	int parseHeaderItems(const char *start, const char *end);
	int parseBody();
	int parseBodyByContentLength();
	int parseBodyByTransferEncoding();
	int parseJson();
	int parseBodyHtml();
private:
	DS::DataNode *m_pdDn;		// d ±íÊ¾ÀàÐÍ¼òÐ´
	std::string m_sResponseLine;// HTTP/1.1 200 OK
	std::map<string, string>  m_mHeaders;
	std::map<int, DS::DataNode *> m_mBodys;
	
	enum HttpParsePhase m_hStatus;
	int m_nHandledEnd;// ÒÑ´¦ÀíÎ»ÖÃµÄ±ê¼Ç£¬²»ÄÜÓÃ char * ¼ÇÂ¼£¬ÒòÎª  m_pdDn ÀïÃæµÄÊý¾Ý¿ÉÄÜ×ö marshal ²Ù×÷ 
	int m_nBodySerivalNo;
	int m_nHttpCode;
};

#endif 

