#include <stdio.h>


char* find_char( char const* source, char const* chars );


int main(void)
{
    char source[] = "ABCDEFG";
    char chars1[] = "XYZ";
    char chars2[] = "XRCQEF";
    char* res = NULL;

    res = find_char(source, chars1);
    printf("find_char(source, chars1) == %s\n", res == NULL ? "NULL" : res);

    res = find_char(source, chars2);
    printf("find_char(source, chars2) == %s\n", res == NULL ? "NULL" : res);

    return 0;
}


char* find_char( char const* source, char const* chars )
{
    register char ch;
    register const char const* sp = source;

    while( (ch = *chars++) != '\0' ){
        for( sp = source; *sp != '\0'; ++sp ){
            if( *sp == ch )
                return sp;
        }
    }
    return NULL;
}
