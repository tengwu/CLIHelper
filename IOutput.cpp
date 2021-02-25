//
// Created by wuteng on 2020/5/31.
//

#include "IOutput.h"
#include <cstdarg>
#include <cstdio>

void IOutput::Output(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
}