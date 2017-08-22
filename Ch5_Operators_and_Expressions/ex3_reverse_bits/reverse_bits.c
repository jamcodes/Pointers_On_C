#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define INT_BIT CHAR_BIT * sizeof(unsigned int)

unsigned int reverse_bits(unsigned int val);
bool get_hex(unsigned int* v);

int main(void)
{
    unsigned int val = 0;

    printf("Enter hexadecimal integer values.\n"
        "The bit orded will be reversed.\n");

    printf("Enter a hex number (q to quit)\n> ");
    while(get_hex(&val)){
        printf("\nNumber with reversed bits: 0x%x\n", reverse_bits(val));
        printf("Number in decimal: %u\n", reverse_bits(val));
        printf("> ");
    }

    return 0;
}

unsigned int reverse_bits(unsigned int val)
{
    unsigned int ret_val = 0;

    for(int i = 0; i < INT_BIT-1; ++i, ret_val <<= 1, val >>= 1){
        ret_val |= (val & 0x1);
    }

    return ret_val;
}

bool get_hex(unsigned int* v)
{
    if(scanf(" %x", v) != 1)
        return false;
    while(getchar() != '\n')
        ;
    return true;
}
