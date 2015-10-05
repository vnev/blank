#include "token.h"

Buffer* newBuffer(size_t size)
{
  Buffer* buffer = malloc(sizeof(*buffer));
  buffer->bytes = malloc(size);
  buffer->size = size;

  return buffer;
}

void freeBuffer(Buffer* buffer)
{
  free(buffer->bytes);
  free(buffer);
}

Token* newToken(TokenType type, int start, int end)
{
  Token* token = malloc(sizeof(*token));
  token->type = type;
  token->start = start;
  token->end = end;
  token->prev = NULL;
  token->next = NULL;
  return token;
}

void printToken(Buffer* buffer, Token* token)
{
  for (int i = token->start; i < token->end; i++)
  {
    putchar(buffer->bytes[i]);
  }
}

Token* unlinkToken(Token* token)
{
  if (token->next) token->next->prev = token->prev;
  if (token->prev) token->prev->next = token->next;

  token->next = NULL;
  token->prev = NULL;

  return token;
}
