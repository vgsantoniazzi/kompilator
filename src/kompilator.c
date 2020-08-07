#include "kompilator.h"

int main() {
  _kompilator_init();
  return 0;
}

void kompilator_emit(char *instruction, ...) {
  va_list(args);
  putchar('\t');
  va_start(args, instruction);
  vprintf(instruction, args);
  va_end(args);
  putchar('\n');
}

void kompilator_expected(char *message, ...) {
  va_list(args);
  fputs("Error: ", stderr);
  va_start(args, message);
  vfprintf(stderr, message, args);
  va_end(args);
  fputs(" Expected!\n", stderr);
  exit(1);
}

void _kompilator_init() {
  _kompilator_initial_message();
  lexer_next();
  math_expression();
}

void _kompilator_initial_message() {
  printf("Welcome to kompilator\n"
         "Write your program and press enter.\n"
         "Example: + 2 (- 4 1)\n"
         "(k)> ");
}
