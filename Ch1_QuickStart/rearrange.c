/*
** This program reads input lines from standard input and prints
** each input line, followed by just some portions of the line, to
** the standard output.
**
** The first input is a lint of column numbers, which ends with a
** negative number. The column numbers are paired and specify
** ranges of columns from the input line that are to be printed.
** For example, 0 3 10 12 -1 indicates that only columns 0 through 3
** and columns 10 through 12 will be printed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS    20      /* max # of columns to process */
#define MAX_INPUT   1000    /* max len of input & output lines */


int read_column_numbers(int columns[], int max);
void rearrange(char* output, char const* input,
                int n_columns, int const columns[]);


int main(void)
{
    int n_columns;
    int columns[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    n_columns = read_column_numbers(columns, MAX_COLS);

    while(gets(input) != NULL){
        printf("Original input: %s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("Rerranged line: %s\n", output);
    }

    return EXIT_SUCCESS;
}


int
read_column_numbers(int columns[], int max)
{
    int num = 0;
    int ch;

    while(num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0){
        ++num;
    }

    if(num % 2 != 0){
        puts("Last column number is not paired.");
        exit(EXIT_FAILURE);
    }

    while((ch = getchar()) != EOF && ch != '\n')
        ;

    return num;
}


void
rearrange(char* output, char const* input,
            int n_columns, int const columns[])
{
    int col;
    int output_col;
    int len;

    len = strlen(input);
    output_col = 0;

    for(col = 0; col < n_columns; col += 2){
        int nchars = columns[col+1] - columns[col] + 1;

        /* if the input line isn't this long or the output array
        ** is full, we're done
        */
        if(columns[col] >= len ||
            output_col == MAX_INPUT - 1)
            break;

        /* If there isn't room in the output array, only copy what will fit */
        if(output_col + nchars > MAX_INPUT - 1)
            nchars = MAX_INPUT - output_col - 1;

        strncpy(output + output_col, input + columns[col], nchars);
        output_col += nchars;
    }

    output[output_col] = '\0';
}
