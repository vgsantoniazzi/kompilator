#ifndef LEXER_H
#define LEXER_H
#include "kompilator.h"
#include <ctype.h>
#include <stdio.h>

char _look;

void lexer_next();
void lexer_match(char c);
char lexer_look();
char lexer_get_num();

#endif
