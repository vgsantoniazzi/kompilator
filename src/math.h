/**
 * @file math.h
 * @author Victor Antoniazzi
 * @date 7 August 2020
 * @brief Polish math parser.
 */
#ifndef MATH_H
#define MATH_H
#include "lexer.h"

/**
 * @brief Process a expected math expression.
 *
 * Is expected to be a valid polish math expression.
 *
 * @warning It will stop the execution in case of invalid and stop the compiler.
 */
void math_expression();

/**
 * @brief It will search for a valid term operator.
 *
 * A term operator is multiplication or division. They should be executed before
 * a commom math add or subtract.
 *
 * @note It search for a valid term operation, check for numbers, eat tokens and
 * raises error the the correct operation is not supported.
 */
void _math_term();

/**
 * @brief It will execute a factor and expect the current token is a number.
 *
 * A factor is a preparation to execute any kind of math operation. It will
 * use the register AX, calling
 * @code
 * kompilator_emit("MOV AX, %c", lexer_get_num())
 * @endcode
 *
 * @note It requires the current token is a number. Otherwise will stop the compiler.
 */
void _math_factor();

/**
 * @brief It will execute a division.
 *
 * @note It execute the operation and validate the tokens. If the format
 * is not right, will stop the compiler.
 */
void _math_divide();

/**
 * @brief It will execute a multiplication.
 *
 * @note It execute the operation and validate the tokens. If the format
 * is not right, will stop the compiler.
 */
void _math_multiply();

/**
 * @brief It will execute a subtract.
 *
 * @note It execute the operation and validate the tokens. If the format
 * is not right, will stop the compiler.
 */
void _math_subtract();

/**
 * @brief It will execute an addition.
 *
 * @note It execute the operation and validate the tokens. If the format
 * is not right, will stop the compiler.
 */
void _math_add();

#endif
