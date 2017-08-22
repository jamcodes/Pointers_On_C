#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool copy_file(FILE* to, FILE* from);


int main(void)
{
    char fname[FILENAME_MAX];
    FILE* infile;
    FILE* outfile;

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


    if( copy_file(outfile, infile) ){
        printf("File copy successful\n");
    }else{
        printf("Error copying file\n");
        return 1;
    }

    return 0;
}


bool copy_file(FILE* to, FILE* from)
{
    static char BUF[255];

    while( fgets(BUF, 255, from) != NULL ){
        fputs(BUF, to);
    }

    if( ferror(to) || ferror(from) )
        return false;

    return true;
}
