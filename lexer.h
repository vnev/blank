#ifndef mango_lexer_h
#define mango_lexer_h

#include <stdio.h>
#include <string.h>

#include "token.h"

Token* tokenize(Buffer* source);

#endif
