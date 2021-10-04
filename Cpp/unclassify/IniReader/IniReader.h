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

#ifndef INI_READER_H
#define INI_READER_H
#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <iostream>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
using std::string;
using std::map;
using std::list;
using std::vector;

string& RTrim(string& s);
string& LTrim(string& s);
string& Trim(string& s);

enum ErrorType
{
	ErrorType_NotDefine = -1,
	ErrorType_Success = 0, 
	ErrorType_OpenFailured = 1,
	ErrorType_NoSection = 2,
	ErrorType_Syntax_Error = 3,
	ErrorType_Repeat_Key = 4,
	ErrorType_Empty_Section_val = 5
};

typedef string SECTION_NAME_TYPE;
typedef string KEY_TYPE;
typedef string VALUE_TYPE;

typedef enum ItemType
{
	ITEM_TYPE_UNDEFINE = -1,
	ITEM_TYPE_SECTION = 1,
	ITEM_TYPE_PARAMETER = 2,///< key ,value pair
	ITEM_TYPE_COMMENTS = 3,
	ITEM_TYPE_EMPTY = 4

}ItemType;

typedef struct IniItem
{
	ItemType type;
	string source; ///
	string sectionname;
	string key;
	string value;
}IniItem;

class IniReader
{
public:
	IniReader(const string& strfile, const char comment='#');
	~IniReader();
	/**
	 * @brief
	 * @return string empty success, either error info.
	 */
	string ParseIniFile();
	string GetOptValue(const char* section, const char* szname, const string& strdefault);
	
	/** 
	 * @brief 
	 */
	bool AddSection(const char* section, const char* comments);

	/**
	 * @brief if no section , then add. if not exist key in section, then add;
	 */
	bool Set(const char* section, const char* key, const char* val,  
		     const string& comments_para="");
	
	bool WriteToFile(const string& filename = "");
	string DoShow();
private:
	string getErrorInfo(int errnum);

private:
	/** */
	char comment_char_;
	string filename_;
	vector<IniItem> configs_;
	map< SECTION_NAME_TYPE, map<KEY_TYPE, VALUE_TYPE>> dicts_;
};

#endif
/**
## comments
[section1]
#comment11
key1 = val1
## comments11
#comment22
key2 = val2

[section2]
key21 = val21
key22=val22


*/