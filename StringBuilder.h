//
//  StringBuilder.h
//  StringBuilder
//
//  Copyright (c) 2015 Muhammad Khan. All rights reserved.
//

#ifndef __StringBuilder__StringBuilder__
#define __StringBuilder__StringBuilder__

#include <stdio.h>
#include <string.h>

typedef struct _list* ListPtr;
typedef struct _str* StringBuilderPtr;

StringBuilderPtr newStringBuilder();
StringBuilderPtr newStringBuilderSize(int size);

void append(StringBuilderPtr builder, const char * str);

char * toString(StringBuilderPtr builder);

#endif /* defined(__StringBuilder__StringBuilder__) */
