#include <iostream>
#include <string>
#include <stdio.h>

#include "lexdef.h"

int main(int argc, char **argv) {
    FILE *fp;
    if (argc == 2) {
        const std::string filename = argv[1] + std::string(".4280E01");
        fp = fopen(filename.data(), "r");
        if (!fp) {
            fprintf(stderr, "Unable to open '%s': %s\n", argv[1], strerror(errno));
            return 1;
        }
    } else if (argc == 1) {
        fp = stdin;
    } else {
        fprintf(stderr, "Invalid invocation\n");
        return 1;
    }

    LexDef lex_def;
    const State *state = lex_def.get_init();

    std::string tok;

    unsigned int buf;
    while (fread(&buf, 1, 1, fp)) {
        const char *emit = state->get_emit(buf);
        state = state->follow_edge(buf);

        //std::cout << buf << ": " << state->get_name() << std::endl;

        if (emit) {
            std::cout << "{" << emit << ", \"" << tok << "\"}" << std::endl;
            tok = "";
        }

        if (!state) {
            std::cerr << "Invalid character with code " << buf << std::endl;
            return 1;
        }

        tok += buf;
    }

    std::cout << "{EOFTok, \"\"}" << std::endl;

    return 0;
}
