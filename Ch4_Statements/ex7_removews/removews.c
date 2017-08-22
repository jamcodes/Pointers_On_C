#include <stdio.h>
#include <ctype.h>
#include <string.h>

void deblank(char string[]);


int main(void)
{
    char string[] = "   0 12    3  4 56      7";
    
    printf("Original string: %s\n", string);
    deblank(string);
    printf("Deblanked string: %s\n", string);

    return 0;
}


void deblank(char string[])
{
    int len = strlen(string);
    char temp[len+1];
    register char* begin, *end, *t;
    t = temp;

    begin = string;
    end = begin + len + 1;

    /* skip leading ws */
    while( isspace(*begin) && begin < end )
        ++begin;

    for( *t = *begin++; begin < end; ++begin ){
        if( isspace(*begin) ){
            if( !isspace(*t) )
                *++t = ' ';
        }
        else
            *++t = *begin;
    }

    *++t = '\0';
    strcpy(string, temp);
}
