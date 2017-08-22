#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define SIZE_LINE 128


char* s_gets(char* st, int n);


int main(void)
{

    _Bool print = false;
    char last[SIZE_LINE] = {'\0'};
    char cur[SIZE_LINE];


    while(s_gets(cur, SIZE_LINE) != NULL){
        if(strcmp(cur, last) == 0)
            print = true;
        else if(print){
            puts(last);
            print = false;
        }

        strcpy(last, cur);
    }
    if(print)
        puts(last);


    return 0;
}


char* s_gets(char* st, int n)
{
    char *ret_val;

    ret_val = fgets(st, n, stdin);
    if(ret_val){
        while(*st != '\n' && *st != '\0')
            ++st;
        if(*st == '\n')
            *st = '\0';
        else
            while(getchar() != '\n')
                ;
    }

    return ret_val;
}
