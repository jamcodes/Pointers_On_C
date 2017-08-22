#ifndef _GET_LINE_H_
#define _GET_LINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
** Takes a pointer to a character input stream
** a buffer allocated on the free store and buffer size,
** Reads characters from the stream up to, and including the new line character
** The '\n' char is replaced with the terminating '\0'.
** On success return a pointer to the buffer, on failure returns NULL
*/
char* get_lines(char* buf, unsigned int* bufsize, FILE* fh);


#endif /*_GET_LINE_H_*/
