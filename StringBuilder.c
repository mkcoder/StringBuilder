//
//  StringBuilder.c
//  StringBuilder
//
//  Created by Khalil's on 4/2/15.
//  Copyright (c) 2015 Muhammad Khan. All rights reserved.
//

#include "StringBuilder.h"
#define GROWTH_RATE 2

enum bool {
    true = 1,
    false = 0
};

typedef struct _listNode {
    StringBuilderPtr string;
    struct _listNode * next;
}* ListNodePtr;
    
struct _list {
    ListNodePtr head;
    ListNodePtr tail;
    int totalStringSize;
};

struct _str {
    char * str;
    int size;
    int capacity;
};

StringBuilderPtr newStringBuilder()
{
    return newStringBuilderSize(255);
}

StringBuilderPtr newStringBuilderSize(int size)
{
    
    StringBuilderPtr builder = malloc(sizeof(struct _str));
    builder->str = malloc(sizeof(char)*size);
    builder->size = 0;
    builder->capacity = size;
    
    return builder;
}
int arraySize(const char * str)
{
    int i;
    for ( i = 0; str[i] != '\0'; i++);
    return i;
}
void copyString(char * src, char * dst)
{
    for ( int i = 0; src[i] != '\0'; i++ )
    {
        dst[i] = src[i];
    }
}
void growArray(StringBuilderPtr builder, int s)
{
    int b_size = builder->size;
    int b_capcity = builder->capacity;
    if ( (b_size+s) >= b_capcity)
    {
        StringBuilderPtr newBuilder = newStringBuilderSize(b_capcity*GROWTH_RATE);
        newBuilder->size = builder->size;
        copyString(builder->str, newBuilder->str);
    }
}

void append(StringBuilderPtr builder, const char * str)
{
    int totalLength = arraySize(str);
    int builderSize = builder->size;
    growArray(builder, totalLength);
    
    for ( int i = builderSize, j = 0; i < (builderSize+totalLength); i++, j++)
    {
        builder->str[i] = str[j];
    }
    
    builder->size+=totalLength;
}
    
char * toString(StringBuilderPtr builder)
{
    return builder->str;
}
