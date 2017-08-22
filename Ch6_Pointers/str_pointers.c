#include <stdio.h>
#include <assert.h>

#define TRUE  1
#define FALSE 0


/*
** Given a pointer to a NULL-terminated list of pointers, search
** the strings in the list for a particular character.
*/
int
find_char( char **strings, char value)
{
    char *string;   /* the string we're looking at */

    /* for each string in the list */
    while( (string = *strings++ ) != NULL){
        /* Look at each char in the string to see if
        ** it contains the one we're looking for
        */
        while( *string != '\0' ){
            if( *string++ == value )
                return TRUE;
        }
    }
    return FALSE;
}


/*
** Given a pointer to a NULL-terminated list of pointers, search
** the strings in the list for a particular character. This
** version destroys the pointers so it can only be used when
** the collection will be examined only once.
*/
int
find_char_destructive( char **strings, int value)
{
    assert( strings != NULL );

    while( *strings != NULL ){
        while( **strings != '\0' ){
            if( *(*strings)++ == value )
                return TRUE;
        }
        strings++;
    }
    return FALSE;
}
