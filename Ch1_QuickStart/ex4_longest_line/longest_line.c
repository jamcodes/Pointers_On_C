#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_line.h"


struct longest_line{
    size_t len;
    char* line;
};
typedef struct longest_line LongestLine;


int main(void)
{
    char* temp_line;
    size_t len;
    LongestLine longest_line = {.len=0, .line=NULL};
    printf("LongestLine  --  reads lines of input from stdin until\n"
        "an empty line or EOF is entered.\n"
        "Finds the longest line and outputs it and it's length to stdout.\n");

    while((temp_line = get_line(stdin)) != NULL){
        if((len = strlen(temp_line)) > longest_line.len){
            if(longest_line.line != NULL)
                free(longest_line.line);
            longest_line.len = len;
            longest_line.line = temp_line;
        }else{
            free(temp_line);
        }
    }

    printf("Longest line:\n\t%s\n"
        "length: %lu\n", longest_line.line, (unsigned long)longest_line.len);

    free(longest_line.line);
    return 0;
}
