#include "lexer.h"

void lexer_next() { _look = getchar(); }

void lexer_match(char c) {
  if (_look != c)
    kompilator_expected("%c", c);
  lexer_next();
}

char lexer_get_num() {
  char num;
  if (!isdigit(_look))
    kompilator_expected("Integer");
  num = _look;
  lexer_next();
  return num;
}

char lexer_look() { return _look; }
