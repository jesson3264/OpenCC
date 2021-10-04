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

#ifndef __INI_READER_H__
#define __INI_READER_H__
#include <string>
#include <map>
#include <list>

using std::string;
using std::map;
using std::list;

namespace ACE
{

enum Type 
{
     typ_empty = 1, //
     typ_comment,
     typ_section,
     typ_field
};

typedef struct LineInfo
{
    LineInfo()
    {
        _lineNum = -1;
    }

    int _lineNum;
    std::string _src;
    Type _type;
    std::string _sectionName;
    std::string _key;
    std::string _val;
}LineInfo;

class IniReaderPlus
{
public:
    IniReaderPlus(const string &strfile);
    ~IniReaderPlus();
    int Reload();
    int Sync();
    // 返回：0 成功
    int ScanCfgFile();
    string GetValue(const char * section, const char *szname);
    // 如果不存在，返回默认值
    string GetOptValue(const char *section, const char *szname, const string &strdefault);
    int Remove(std::string &section, std::string &key);
    int Modify(std::string &section, std::string &key, std::string &newval);

    // 1. 加注释，在常规项前面加，在常规项后面加。不支持在注释中间加注释，因为意义不大
    // 2. 加常规项， 
    //
    // 默认在块的最后添加， mode = 1 在块的最开头添加
    int AddBaseSection(const string &section, const string &key, const string &val, int mode = 0);
    // 默认加在原 key 的后面， mode = 1 在原 key 后面添加
    int AddBaseField(const string &section, const string &key, const string &newkey, const string &newval, int mode = 0);
    void show();
    
private:
    list<LineInfo*>::iterator find(const string &section, const string &key);
    list<LineInfo*>::iterator find(const string &section);
    void destroy();
    int transfer();
private:
    bool _bscan;
    string _strfile;
    map<string, map<string, LineInfo*> *> _cfgDict;
    //map<int, LineInfo>  _allLine;
    list<LineInfo*> _allLine;
};

} // namespace ACE

#endif 
