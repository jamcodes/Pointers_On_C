#include "get_lines.h"


char* get_lines(char* buf, unsigned int* bufsize, FILE* fh)
{
    static unsigned int EXPAND_RATE = 255;
    register unsigned int len = 0;
    register unsigned int max = *bufsize;
    register int ch = 0;
    register char *t;
    
    
    while( (ch = getc(fh)) != EOF && ch != '\n' ){
        if( len == max-2 ){
            if( (t = realloc(buf, (max += EXPAND_RATE))) == NULL ){
                // Return at least what we already have
                ungetc(ch, fh);
                buf[len] = '\0';
                return buf;
            }
            buf = t;
            *bufsize = max;
        }

        buf[len++] = ch;
    }
    if(ch == '\n')
        buf[len++] = '\n';

    // if the first char we read is EOF
    if( len == 0 ){
        return NULL;
    }

    buf[len] = '\0';
    return buf;
}
