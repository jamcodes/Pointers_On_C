#include <stdio.h>


void copy_n(char dst[], char src[], int n);
void printn(char str[], int n);

int main(void)
{

    char* source1 = "abc";
    char* source2 = "xyzXYZ";
    char* source3 = "waytoolongbrah";
    char dest[7];

    copy_n(dest, source1, 7);
    printf("copy_n(dest, source1, 7): ");
    printn(dest, 7);

    copy_n(dest, source2, 7);
    printf("\ncopy_n(dest, source2, 7): ");
    printn(dest, 7);

    copy_n(dest, source3, 7);
    printf("\ncopy_n(dest, source3, 7): ");
    printn(dest, 7);
    putchar('\n');
}


void copy_n(char dst[], char src[], int n)
{
    register char* to = dst;
    register char* from = src;
    register char* end = from + n;

    while(from < end && *from != '\0')
        *to++ = *from++;

    while(from++ < end)
        *to++ = '\0';
}


void printn(char str[], int n)
{
    for(int i = 0; i < n; ++i){
        str[i] == '\0' ? printf("\\0") : putchar(str[i]);
        putchar(' ');
    }
}
