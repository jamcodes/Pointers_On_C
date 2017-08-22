#ifndef _GET_LINE_H_
#define _GET_LINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
** Takes a pointer to a character input stream
** Reads characters from the stream up to, and including the new line character
** Returns a char array allocated on the free store; the '\n' char is replaced
** with the terminating '\0'.
*/
char* get_line(FILE* fh);


#endif /*_GET_LINE_H_*/
