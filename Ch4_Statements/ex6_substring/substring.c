#include <stdio.h>
#include <string.h>


int substr(char dest[], char src[], int start, int len);


int main(void)
{
    int dst_len=0, start=0, end=0;
    char* src = "0123456789";
    char dst[11];

    start = 0;
    while(++end < 11){
        dst_len = substr(dst, src, start, end);
        printf("dst_len = substr(dst, src, %d, %d):\n"
            "\tdst_len = %d, dst = %s\n", start, end, dst_len, dst);
    }
    return 0;
}


int substr(char dest[], char src[], int start, int len)
{
    int src_len = 0;
    register int dst_len = 0;
    register char *begin, *end;

    if(start < 0 || len < 0 || (src_len = strlen(src)) < start){
        dest[0] = '\0';
        return 0;
    }

    begin = src + start;
    end = begin+len > src+src_len ? src+src_len : begin+len;

    while(begin < end){
        *dest++ = *begin++;
        ++dst_len;
    }

    *dest = '\0';
    return dst_len;
}
