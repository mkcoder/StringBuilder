//
//  StringBuilder.c
//  StringBuilder
//
//  Created by Khalil's on 4/2/15.
//  Copyright (c) 2015 Muhammad Khan. All rights reserved.
//

#include "StringBuilder.h"
#define GROWTH_RATE 2

typedef enum bool {
    true = 1,
    false = 0
} Bool;

typedef struct _listNode {
    struct _listNode * next;
    char * str;
    int size;
    int MAX_CAPACITY;
}* ListNodePtr;

struct _list {
    ListNodePtr head;
    ListNodePtr tail;
};

struct _str {
    ListPtr stringBuilder;
    int totalStringSize;
};

StringBuilderPtr newStringBuilder()
{
    return newStringBuilderSize(255);
}

StringBuilderPtr newStringBuilderSize(int size)
{
    
    StringBuilderPtr builder = malloc(sizeof(struct _str));
    builder->stringBuilder = malloc(sizeof(struct _list));
    builder->stringBuilder->head = malloc(sizeof(struct _listNode));
    builder->stringBuilder->head->str = malloc(sizeof(char)*size);
    builder->stringBuilder->head->MAX_CAPACITY = size;
    builder->stringBuilder->head->size = 0;
    builder->stringBuilder->tail = malloc(sizeof(struct _listNode));
    builder->stringBuilder->tail = builder->stringBuilder->head;
    return builder;
}

ListNodePtr newListNode(int size)
{
    ListNodePtr node = malloc(sizeof(struct _listNode));
    node->str = malloc(sizeof(char)*size);
    node->MAX_CAPACITY = size;
    node->size = 0;
    
    return node;
}
    
int str_size(const char * str)
{
    int i;
    for ( i = 0; str[i] != '\0'; i++);
    return i;
}

void add(StringBuilderPtr builder)
{
    StringBuilderPtr node = newListNode(255);
    builder->stringBuilder->tail->next = node;
    builder->stringBuilder->tail = node;
}

Bool willNotOverflow(StringBuilderPtr builder, int size)
{
    if ( (builder->stringBuilder->tail->size+size) <
        (builder->stringBuilder->tail->MAX_CAPACITY) )
        return true;
    else
        return false;
}
void append(StringBuilderPtr builder, const char * str)
{
    /*
        1. check if the size of the current stringbuider length + the new string size 
           will overflow the buffer?
            1.2 if so then add a new node to the list, with at least the min size being the size of the string
    */

    int L_str_length = str_size(str);
    if ( willNotOverflow(builder, L_str_length) == false )
    {
        add(builder);
    }

    int builderSize = builder->stringBuilder->tail->size;
    
    for ( int i = builderSize, j = 0; i < (builderSize+L_str_length); i++, j++)
    {
        builder->stringBuilder->tail->str[i] = str[j];
    }
    
    builder->stringBuilder->tail->size+=L_str_length;
    builder->totalStringSize+=L_str_length;
}

char * toString(StringBuilderPtr builder)
{
    char * str = malloc(sizeof(char) * (builder->totalStringSize) );
    ListNodePtr temp = builder->stringBuilder->head;
    
    while ( temp != NULL )
    {
        str = strncat(str, temp->str, temp->size);
        temp = temp->next;
    }
    return str;
}
