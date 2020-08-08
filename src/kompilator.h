/**
 * @file kompilator.h
 * @author Victor Antoniazzi
 * @date 7 August 2020
 * @brief Main compiler file.
 */

#ifndef KOMPILATOR_H
#define KOMPILATOR_H
#include "lexer.h"
#include "math.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Raises an error and stop the execution
 *
 * Used in a lot of diferent parts of the compiler, stop the execution after
 * call an output message.
 *
 * @param message a string containing the error to output.
 * @warning After execute, this will stop the compiler.
 */
void kompilator_expected(char *message, ...);

/**
 * @brief Emits the assembly code after parsing a valid AST.
 *
 * Simply output a char to stdout. The @p instruction must be a valid assembly
 * instruction.
 * @code
 * kompilator_emit("MOV AX, 2")
 * @endcode
 * @param instruction The string containing the assembly code.
 * @note This will only outputs to stdout the assembly code, it will not save to
 * a file for example.
 */
void kompilator_emit(char *instruction, ...);

/**
 * @brief Initialize the compiler, output welcome message and read from repl.
 */
void _kompilator_init();

/**
 * @brief Output initial message.
 */
void _kompilator_initial_message();

#endif
