#include <stdio.h>

#define CHECKSUM_INIT -1



int main(void)
{
    signed char checksum = CHECKSUM_INIT;
    int ch;
    printf("%s  --  echoes characters from stdin to stdout, computes checksum\n"
        "for the characters read and outputs it to stdout.\n", __FILE__);

    while((ch = getchar()) != EOF && ch !='\n'){
        putchar(ch);
        checksum += ch;
    }
    checksum += ch;
    printf("\n%d\n", checksum);

    return 0;
}
