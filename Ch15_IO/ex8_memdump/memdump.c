#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NCHARS 16


void dump(FILE* fh);


int main(int argc, char* argv[])
{
    FILE* fh;

    if( argc < 2 ){
        fprintf(stderr, "Usage: %s filename", __FILE__);
        exit(EXIT_FAILURE);
    }

    if( (fh = fopen(argv[1], "rb")) == NULL ){
        fprintf(stderr, "Failed to open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    dump(fh);

    if( fh ) fclose(fh);
    return 0;
}


void dump(FILE* fh)
{
    register int n, i, offset = 0;
    char ch[NCHARS];

    printf("  Offset                   Bytes                   Characters   \n");
    printf(" --------  -----------------------------------  ----------------\n");

    while( (n = fread(ch, 1, NCHARS, fh)) > 0 ){
        printf(" %08d  ", offset);
        for( i = 0; i < NCHARS && i < n; ++i ){
            printf("%.2X", ch[i]);
            if( (i+1) % 4 == 0)
                putchar(' ');
        }
        for( ; i < NCHARS; ++i ){
            printf("  ");
        }
        putchar(' ');

        for( i = 0; i < n; ++i ){
            if( isprint(ch[i]) )
                fputc(ch[i], stdout);
            else
                putchar('.');
        }
        putchar('\n');
        offset += NCHARS;
    }
}
