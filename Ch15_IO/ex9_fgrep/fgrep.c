#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "get_lines.h"


bool findstr(const char* s, const char* fname);


int main(int argc, char* argv[])
{
    if( argc < 3 ){
        printf("Usage: %s str_to_find fname1 fname2 ... fnameN\n", __FILE__);
        exit(EXIT_FAILURE);
    }

    for( int i = 2; i < argc; ++i ){
        if( ! findstr(argv[1], argv[i]) )
            printf("Failed to open file: %s", argv[i]);
        putchar('\n');
    }

    return 0;
}


bool findstr(const char* s, const char* fname)
{
    FILE* fh;
    register char* buf;
    register char* t;
    unsigned int bufsize = 255;

    if( (fh = fopen(fname, "r")) == NULL )
        return false;

    if( (buf = (char*)malloc(sizeof(char) * bufsize)) == NULL )
        return false;

    while( (t = get_lines(buf, &bufsize, fh)) != NULL){
        buf = t;
        if( strstr(buf, s) != NULL )
            printf("%s: %s", fname, buf);
    }

    if( buf != NULL )
        free(buf);
    return true;
}
