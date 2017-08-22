#include <stdio.h>
#include <stdlib.h>
#include "get_line.h"


int main(void)
{
    unsigned int nline = 0;
    char* line;

    while((line = get_line(stdin)) != NULL){
        printf("%u: %s\n", ++nline, line);
    }

    return EXIT_SUCCESS;
}
