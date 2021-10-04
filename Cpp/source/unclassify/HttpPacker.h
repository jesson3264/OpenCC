/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2020 ÈÇì‰øäÂÖ¥ (Deng Junxing)
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

#ifndef __HTTP_PACKER_H__
#define __HTTP_PACKER_H__
#include <string>
#include <map>
#include "DataNode.h"
#ifdef  IN_EMM
#define LOG  EMMRunPrintf
#else
#define LOG  printf
#endif

using std::string;
using std::map;


#define SPACE_LEN  strlen(" ")
#define HEAD_LINE_END "\r\n" 
typedef struct emmstr
{
	char *buf;
	int size;
}emmstr;
class HttpPacker
{
public:
	HttpPacker();
	~HttpPacker();
	void SetVersion(const char *version);//
	void SetMethod(const char *method);// GET POST CONNECT etc. 
	void SetUrl(const char *url);
	// “‘ '\0'; Ω·Œ≤
	void SetBody(const char *pszbody);
	// ∑« '\0' Ω·Œ≤¥¯…œ  ˝æ›≥§∂» len
	void SetBody(const char *body, int len);
	emmstr* Pack();
private:
	void toUpper(std::string &str);

	int calcTotalLen();
private:
	string m_sMethod;
	string m_sUrl;
	string m_sVersion;
	// Õ∑≤ø–≈œ¢¥¶«Î«Û––“‘Œ™µƒÕ∑≤ø–≈œ¢ 
	map<string, string> m_mHeaders;//Content-Length:xxx
	emmstr m_eBody;
	// ∞¸∫¨Õ∑≤ø∫Õœ˚œ¢ÃÂbody 
	emmstr m_eHole; 
}; 



#endif 

/*
 
GET /hello/index.jsp HTTP/1.1
«Î«ÛÕ∑–≈œ¢£¨“ÚŒ™GET«Î«Û√ª”–’˝Œƒ
Host: localhost
User-Agent: Mozilla/5.0 (Windows NT 5.1; rv:5.0) Gecko/20100101 Firefox/5.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,
Accept-Language: zh-cn,zh;q=0.5
Accept-Encoding: gzip, deflate
Accept-Charset: GB2312,utf-8;q=0.7,*;q=0.7
Connection: keep-alive
Cookie: JSESSIONID=369766FDF6220F7803433C0B2DE36D98
ø’––
“ÚŒ™GET√ª”–’˝Œƒ£¨À˘“‘œ¬√ÊŒ™ø’
*/

/*
// «Î«Û ◊––
// POST /hello/index.jsp HTTP/1.1
// //«Î«ÛÕ∑–≈œ¢
 Host: localhost
 User-Agent: Mozilla/5.0 (Windows NT 5.1; rv:5.0) Gecko/20100101 Firefox/5.0
 Accept: text/html,application/xhtml+xml,application/xml;q=0.9,
 Accept-Language: zh-cn,zh;q=0.5
 Accept-Encoding: gzip, deflate
 Accept-Charset: GB2312,utf-8;q=0.7,*;q=0.7
 Connection: keep-alive
 Referer: http://localhost/hello/index.jsp
 Cookie: JSESSIONID=369766FDF6220F7803433C0B2DE36D98
 Content-Type: application/x-www-form-urlencoded 
 Content-Length: 14 
 // ’‚¿Ô «ø’––
// //POST”–«Î«Û’˝Œƒ
 username=hello
*/

