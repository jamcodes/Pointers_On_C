#include "get_line.h"


char* get_line(FILE* fh)
{
    static size_t BUFSIZE = 255;
    size_t len = 0, max = BUFSIZE;
    int ch = 0;
    char* buf, * t;

    if((buf = (char*)calloc(BUFSIZE, sizeof(char))) == NULL)
        return NULL;
    
    
    while((ch = getc(fh)) != EOF && ch != '\n'){
        if(len == max-1){
            if((t = realloc(buf, (max += BUFSIZE))) == NULL){
                // Return at least what we already have
                ungetc(ch, fh);
                buf[len] = '\0';
                return buf;
            }
            buf = t;
        }
        buf[len] = ch;
        ++len;
    }
    // if the first char we read is EOF or '\n' return NULL to indicate failure
    if(len == 0){
        if(buf != NULL) free(buf);
        return NULL;
    }

    buf[len] = '\0';
    return buf;
}
