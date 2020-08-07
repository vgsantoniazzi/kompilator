#ifndef KOMPILATOR_H
#define KOMPILATOR_H
#include "lexer.h"
#include "math.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void _kompilator_init();
void _kompilator_initial_message();
void kompilator_expected(char *message, ...);
void kompilator_emit(char *instruction, ...);
void _kompilator_execute();

#endif
