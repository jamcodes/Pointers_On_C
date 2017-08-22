#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "get_lines.h"


bool copy_and_sum(FILE* to, FILE* from, char* buf, unsigned* bufsize);


int main(void)
{
    char fname[FILENAME_MAX];
    FILE* infile;
    FILE* outfile;
    unsigned int bufsize = 255;
    char* buf;

    printf("Enter the input file name: ");
    if( scanf(" %s", fname) != 1 ){
        perror("Invalid file name");
        exit(EXIT_FAILURE);
    }
    if( (infile = fopen(fname, "r")) == NULL ){
        fprintf(stderr, "Failed to open file: %s\n", fname);
        exit(EXIT_FAILURE);
    }

    printf("Enter output file name: ");
    if( scanf(" %s", fname) != 1 ){
        fprintf(stderr, "Invalid file name");
        exit(EXIT_FAILURE);
    }
    if( (outfile = fopen(fname, "w")) == NULL ){
        fprintf(stderr, "Failed to open file %s\n", fname);
        exit(EXIT_FAILURE);
    }

    if( (buf = (char*)malloc(sizeof(char) * bufsize)) == NULL ){
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    if( copy_and_sum(outfile, infile, buf, &bufsize) )
        printf("File copy successful\n");
    else{
        printf("Error copying file\n");
        return 1;
    }
}


bool copy_and_sum(FILE* to, FILE* from, char* buf, unsigned* bufsize)
{
    int sum = 0;
    int i = -1;

    while( (buf = get_lines(buf, bufsize, from)) != NULL ){
        if( sscanf(buf, "%d", &i) ){
            sum += i;
        }
        fputs(buf, to);
    }

    fprintf(to, "Total = %d\n", sum);
    fprintf(to, "i = %d\n", i);
    fprintf(to, "bufsize = %u\n", *bufsize);

    if( ferror(to) || ferror(from) )
        return false;
    return true;
}
