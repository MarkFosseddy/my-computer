#ifndef LEXER_H
#define LEXER_h

#include <stdio.h>
#include <stdbool.h>

enum Token_Kind {
    ILLEGAL_TOKEN,
    TOKEN_KIND_EOF,

    TOKEN_KIND_KEYWORD,
    TOKEN_KIND_IDENT,
    TOKEN_KIND_SYMBOL,
    TOKEN_KIND_INT_CONST,
    TOKEN_KIND_STR_CONST
};

#define TOKEN_VALUE_SIZE 80
struct Token {
    enum Token_Kind kind;
    char value[TOKEN_VALUE_SIZE];
};

struct Lexer {
    char ch;
    FILE *file;
    bool has_tokens;
    struct Token *token;
};

struct Lexer *make_lexer(const char *file_name);
void free_lexer(struct Lexer *lex);
void lexer_advance(struct Lexer *lex);

#endif
