#include "math.h"

void math_expression() {
  _math_term();
  while (lexer_look() == '+' || lexer_look() == '-') {
    kompilator_emit("PUSH AX");
    switch (lexer_look()) {
    case '+':
      _math_add();
      break;
    case '-':
      _math_subtract();
      break;
    default:
      kompilator_expected("Add operator");
      break;
    }
  }
}

void _math_add() {
  lexer_match('+');
  _math_term();
  kompilator_emit("POP BX");
  kompilator_emit("ADD AX, BX");
}

void _math_subtract() {
  lexer_match('-');
  _math_term();
  kompilator_emit("POP BX");
  kompilator_emit("SUB AX, BX");
  kompilator_emit("NEG AX");
}

void _math_multiply() {
  lexer_match('*');
  _math_factor();
  kompilator_emit("POP BX");
  kompilator_emit("IMUL BX");
}

void _math_divide() {
  lexer_match('/');
  _math_factor();
  kompilator_emit("POP BX");
  kompilator_emit("XCHG AX, BX");
  kompilator_emit("CWB");
  kompilator_emit("IDIV BX");
}

void _math_factor() { kompilator_emit("MOV AX, %c", lexer_get_num()); }

void _math_term() {
  _math_factor();
  while (lexer_look() == '*' || lexer_look() == '/') {
    kompilator_emit("PUSH AX");
    switch (lexer_look()) {
    case '*':
      _math_multiply();
      break;
    case '/':
      _math_divide();
      break;
    default:
      kompilator_expected("Mult Operator");
      break;
    }
  }
}
