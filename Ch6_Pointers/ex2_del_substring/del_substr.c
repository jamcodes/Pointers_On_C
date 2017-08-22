#include <stdio.h>


int del_substring( char* str, char const* substr );


int main(void)
{
    char string[] = "ABCDEFG";
    char sub1[] = "FGH";
    char sub2[] = "CDE";
    int res = -1;


    res = del_substring(string, sub1);
    printf("del_substring(string, sub1):\n"
        "res = %d,\nstring = %s\n\n", res, string);

    res = del_substring(string, sub2);
    printf("del_substring(string, sub2):\n"
        "res = %d,\nstring = %s\n\n", res, string);


    return 0;
}


int del_substring( char* str, char const* substr )
{
    register char const* sub;
    register char* s;

    for( s = str, sub = substr; *s != '\0'; s = ++str, sub = substr ){
        for( ; *sub != '\0' && *s != '\0'; ++sub, ++s ){
            if( *sub != *s )
                break;
        }

        if( *sub == '\0' )
            break;
    }

    if( *str == '\0' )
        return 0;

    while( (*str++ = *s++) != '\0' )
        ;
    *str = '\0';
    return 1;
}
