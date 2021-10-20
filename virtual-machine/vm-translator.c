#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"
#include "translator.h"
#include "path.h"

#define OUTPUT_EXT ".asm"

void create_out_file_from_in_file(const char *in_file, char *out_file);

int main (int argc, char **argv)
{
    assert(argc > 1);

    const char *in_file = argv[1];
    const char out_file[256];
    path_get_file_name((char *) out_file, in_file);
    path_concat_ext((char *) out_file, OUTPUT_EXT);

    Parser p = make_parser(in_file);
    Translator t = make_translator(out_file);

    while (parser_peek_line(&p)) {
        Instruction inst = parser_parse_instruction(&p);
        translator_translate_inst(&t, &inst);
    }

    free_translator(&t);

    return 0;
}
