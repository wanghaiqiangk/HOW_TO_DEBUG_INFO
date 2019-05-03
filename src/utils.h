#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdarg.h>

#define sRED "\e[31m"
#define sGREEN "\e[32m"
#define sYELLOW "\e[33m"
#define sWHITE "\e[0m"

inline void cprintf_func(const char *col, const char *fmt, ...)
{
    fprintf(stdout, "%s", col);
    va_list vl;
    va_start(vl, fmt);
    vfprintf(stdout, fmt, vl);
    fprintf(stdout, "%s", sWHITE);
    va_end(vl);
}

inline void cfprintf_func(const char *col, FILE *fp, const char *fmt, ...)
{
    FILE *fp_ = fp;
    if(fp_ == NULL)
    {
	fprintf(stdout, "%sWARNING::FILE_NOT_OPEN(WRITING_IN_STDOUT)%s\n", sRED, sWHITE);
	fp_ = stdout;
    }
    fprintf(fp_, "%s", col);
    va_list vl;
    va_start(vl, fmt);
    vfprintf(fp_, fmt, vl);
    fprintf(fp_, "%s", sWHITE);
    va_end(vl);
}

#ifdef DEBUG
#define cprintf cprintf_func
#define cfprintf cfprintf_func
#else
#define cprintf
#define cfprintf
#endif	/* DEBUG */

#endif	/* UTILS_H */
