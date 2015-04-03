//
//  main.c
//  StringBuilder
//
//  Created by Khalil's on 4/2/15.
//  Copyright (c) 2015 Muhammad Khan. All rights reserved.
//
#include <time.h>
#include <stdio.h>
#include "StringBuilder.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    time_t start = time(0);
    
    StringBuilderPtr strBuilder = newStringBuilder();
    
    for ( int i = 0; i < 100000; i++ ) {
    append(strBuilder, ")Contrary to popular belief, Lorem Ipsum is not simply random text.");
    append(strBuilder, "It has roots in a piece");
    append(strBuilder, "of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, ");
    append(strBuilder, "a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure");
    append(strBuilder, "Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the ");
    append(strBuilder, "word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from");
    append(strBuilder, "sections 1.10.32 and 1.10.33 of ");
    append(strBuilder, "de Finibus Bonorum et Malorum The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of");
    append(strBuilder, "ethics, very popular during the Renaissance. The first line of Lorem Ipsum, Lorem ipsum dolor sit amet.., comes from a line in section 1.10.32.\n");
    }
    printf("done!");
    printf("result =\n%s\n", toString(strBuilder));
    
    printf("Run time: %d\n", time(0)-start);
    return 0;
}
