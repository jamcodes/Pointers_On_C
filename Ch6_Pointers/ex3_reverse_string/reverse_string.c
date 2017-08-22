#include <stdio.h>


void reverse_string( char* string );


int main(void)
{
    char str1[] = "ABCDEFG";
    char str2[] = "ABCDEF";

    printf("str1: %s, ", str1);
    reverse_string(str1);
    printf("reverse_string(str1): %s\n\n", str1);

    printf("str2: %s, ", str2);
    reverse_string(str2);
    printf("reverse_string(str2): %s\n", str2);

    return 0;
}


void reverse_string( char* string )
{
    register char ch;
    register char *front, *back;
    front = back = string;

    while( *back != '\0' )
        ++back;

    while( front < back ){
        ch = *--back;
        *back = *front;
        *front++ = ch;
    }
}
