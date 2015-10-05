#ifndef mango_token_h
#define mango_token_h

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char*  bytes;
  size_t size;
} Buffer;

typedef enum
{
  TOKEN_LEFT_PAREN,
  TOKEN_RIGHT_PAREN,
  TOKEN_LEFT_BRACKET,
  TOKEN_RIGHT_BRACKET,
  TOKEN_LEFT_BRACE,
  TOKEN_RIGHT_BRACE,
  TOKEN_COLON,
  TOKEN_DOT,
  TOKEN_COMMA,
  TOKEN_STAR,
  TOKEN_SLASH,
  TOKEN_PERCENT,
  TOKEN_PLUS,
  TOKEN_MINUS,
  TOKEN_AMP,
  TOKEN_BANG,
  TOKEN_EQ,
  TOKEN_LT,
  TOKEN_GT,
  TOKEN_LTEQ,
  TOKEN_GTEQ,
  TOKEN_EQEQ,
  TOKEN_BANGEQ,

  TOKEN_ELSE,
  TOKEN_IF,
  TOKEN_LET,

  TOKEN_NAME,
  TOKEN_NUMBER,
  TOKEN_STRING,
  TOKEN_WHITESPACE,

  TOKEN_LINE,
  TOKEN_ERROR,
  TOKEN_EOF,

} TokenType;

typedef struct Token_t
{
  TokenType type;
  int start;
  int end;

  struct Token_t* prev;
  struct Token_t* next;
} Token;

Buffer* newBuffer(size_t size);
void freeBuffer(Buffer* buffer);

Token* newToken(TokenType type, int start, int end);

void printToken(Buffer* buffer, Token* token);

Token* unlinkToken(Token* token);

#endif
