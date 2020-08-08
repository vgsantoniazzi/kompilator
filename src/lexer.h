/**
 * @file lexer.h
 * @author Victor Antoniazzi
 * @date 7 August 2020
 * @brief Lexer for the compiler.
 *
 * @details These functions are responsible for reading the input program,
 * eat @c lexer_next the tokens, look without eating @c lexer_look and
 * get tokens specifically by types, e.g. @c lexer_get_num.
 */

#ifndef LEXER_H
#define LEXER_H
#include "kompilator.h"
#include <ctype.h>
#include <stdio.h>

/**
 * @brief Current looking token.
 *
 * this must be only managed by the implementation from the lexer.
 * You have getters and setters for this using defined methods.
 *
 * @warning Do not touch this outside @c lexer.c
 */
char _look;

/**
 * @brief Eat the next char.
 *
 * Eating char is used in compilers design to mean that this current token was
 * loaded, consumed and is no longer necessary.
 *
 * @warning After eating the token, there is no way back. You must ensure
 * that this current token is no longer necessary.
 * @note It will update the @c _look
 * @see lexer_look() to just take a look in the token and do not eat it.
 */
void lexer_next();

/**
 * @brief Match the current token with the param.
 *
 * Force matching the char with the input argument. It is useful after taking a
 * look and seeing that it will match with division for example.
 * @code
 * lexer_match("/")
 * @endcode
 *
 * @param c The string containing the value to be compared
 * @warning If does not match, will stop the compiler.
 */
void lexer_match(char c);

/**
 * @brief Take a look on the current token without eating it.
 *
 * @return the current @c _look
 */
char lexer_look();

/**
 * @brief forces the current token is a number, because it is expected.
 *
 * After a @c + token is expected a number, for example
 *
 * @return the current @c _look that is a integer.
 * @warning If the look is not a valid integer, it will stop the compiler.
 */
char lexer_get_num();

#endif
