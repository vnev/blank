#include "lexer.h"

#define MAX_FILE_SIZE  256 * 256 // random

static void dumpTokens(Buffer* buffer, Token* token);

Buffer* readFile(const char* path)
{
  FILE* file = fopen(path, "r");

  Buffer* buffer = newBuffer(MAX_FILE_SIZE);

  size_t read = fread(buffer->bytes, sizeof(char), MAX_FILE_SIZE, file);
  buffer->bytes[read] = '\0';

  fclose(file);
  return buffer;
}

int main(int argc, const char * argv[])
{
  Buffer* buffer = readFile(argv[1]);
  Token* tokens = tokenize(buffer);
  dumpTokens(buffer, tokens);
  freeBuffer(buffer);

  return 0;
}

static void dumpTokens(Buffer* buffer, Token* token)
{
  while (token)
  {
      switch (token->type)
      {
          case TOKEN_LINE: printf("(line)"); break;
          case TOKEN_ERROR: printf("(error)"); break;
          case TOKEN_EOF: printf("(eof)"); break;
          default:
              printf(" [ ");
              for (int i = token->start; i < token->end; i++)
              {
                  putchar(buffer->bytes[i]);
              }
              printf(" ] ");
      }
      token = token->next;
  }
  printf("\n");
}