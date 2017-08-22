#include <stdio.h>
#include <ctype.h>


struct char_types{
    unsigned int control;
    unsigned int whitespace;
    unsigned int digits;
    unsigned int lowercase;
    unsigned int uppercase;
    unsigned int punctuation;
    unsigned int non_print;
    unsigned int total;
};
typedef struct char_types CharTypes;


void show_percentage(CharTypes* chartypes);


int main(void)
{
    int ch;
    CharTypes chars;

    printf("Enter lines of data to have the contents tested for char type\n"
        "EOF to quit\n");

    do{
        chars = (CharTypes){0};
        while( (ch = getchar()) != '\n' ){
            if( iscntrl(ch) )
                ++chars.control;
            if( isspace(ch) )
                ++chars.whitespace;
            if( isdigit(ch) )
                ++chars.digits;
            if( islower(ch) )
                ++chars.lowercase;
            if( isupper(ch) )
                ++chars.uppercase;
            if( ispunct(ch) )
                ++chars.punctuation;
            if( !isprint(ch) )
                ++chars.non_print;
            ++chars.total;
        }

        if( chars.total ){
            show_percentage(&chars);
        }
    }while( ( ch != EOF ) );

}


void show_percentage(CharTypes* c)
{
    printf("Control: %d -- %f%%\n"
        "Whitespace: %d -- %f%%\n"
        "Digits: %d -- %f%%\n"
        "Lowercase: %d -- %f%%\n"
        "Uppercase: %d -- %f%%\n"
        "Punctuation: %d -- %f%%\n"
        "Non-Print: %d -- %f%%\n"
        "Total: %d characters\n",
        c->control, (float)c->control/c->total * 100,
        c->whitespace, (float)c->whitespace/c->total * 100,
        c->digits, (float)c->digits/c->total * 100,
        c->lowercase, (float)c->lowercase/c->total * 100,
        c->uppercase, (float)c->uppercase/c->total * 100,
        c->punctuation, (float)c->punctuation/c->total * 100,
        c->non_print, (float)c->non_print/c->total * 100,
        c->total);
}
