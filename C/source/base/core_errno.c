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

#include "core_errno.h"
#include "scl_cpystrn.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct ErrorInfo {
    scl_status_t code;
    char* error_info;
}ErrorInfo;

ErrorInfo err_info_map[] = {
    {0, "Success"},
    {SCL_ERRNO_COMM_PARAMETER_VALID, "Prameter error."}
};

char* scl_native_strerror(scl_status_t code)
{
    int i = 0;
    for (i = 0; i < sizeof(err_info_map)/sizeof(ErrorInfo); ++i) {
        if (code == err_info_map[i].code) {
            return err_info_map[i].error_info;
        }
    }

    return "Undefine error no..";
}

char* scl_strerror(scl_status_t code)
{
    if (code < SCL_ERRNO_START) {
        return strerror(code);
    }
    else {
        return scl_native_strerror(code);
    }
    
    return NULL;
}
