#ifndef LEXDEF_H
#define LEXDEF_H

#include "statemap.h"

class LexDef {
public:
    LexDef() {
        m["base"].set('a', 'z', m["ident"]);
        m["base"].set('A', 'Z', m["ident"]);
        m["base"].set('0', '9', m["integer"]);
        m["base"].set('#', '#', m["commment"]);
        m["base"].set('\r', '\r', m["ws"].set(0, 255, "tokWS"));
        m["base"].set('\n', '\n', m["ws"].set(0, 255, "tokWS"));
        m["base"].set('\t', '\t', m["ws"].set(0, 255, "tokWS"));
        m["base"].set(' ', ' ', m["ws"].set(0, 255, "tokWS"));

        m["base"].set('=', '=', m["op ="]);
        m["op ="].set(0, 255, "tokAssign");
        m["op ="].set('=', '=', m["op =="].set(0, 255, "tokCmpEq"), 0);
        m["op ="].set('!', '!', m["op =!"].set(0, 255, "tokCmpEqNot"), 0);

        m["base"].set('<', '<', m["op <"]);
        m["op <"].set('<', '<', m["op <<"].set(0, 255, "tokLeftShift"));

        m["base"].set('>', '>', m["op >"]);
        m["op >"].set('>', '>', m["op >>"].set(0, 255, "tokRightShift"));

        m["base"].set(':', ':', m["op :"].set(0, 255, "tokColon"));
        m["base"].set('+', '+', m["op +"].set(0, 255, "tokPlus"));
        m["base"].set('-', '-', m["op -"].set(0, 255, "tokMinus"));
        m["base"].set('*', '*', m["op *"].set(0, 255, "tokStar"));
        m["base"].set('/', '/', m["op /"].set(0, 255, "tokForwardSlash"));
        m["base"].set('&', '&', m["op &"].set(0, 255, "tokAmp"));
        m["base"].set('%', '%', m["op %"].set(0, 255, "tokPercent"));
        m["base"].set('.', '.', m["op ."].set(0, 255, "tokDot"));
        m["base"].set('(', '(', m["op ("].set(0, 255, "tokLeftParen"));
        m["base"].set(')', ')', m["op )"].set(0, 255, "tokRightParen"));
        m["base"].set(',', ',', m["op ,"].set(0, 255, "tokComma"));
        m["base"].set('{', '{', m["op {"].set(0, 255, "tokLeftBrace"));
        m["base"].set('}', '}', m["op }"].set(0, 255, "tokRightBrace"));
        m["base"].set(';', ';', m["op ;"].set(0, 255, "tokSemicolon"));
        m["base"].set('[', '[', m["op ["].set(0, 255, "tokLeftBracket"));
        m["base"].set(']', ']', m["op ]"].set(0, 255, "tokRightBracket"));


        m["base"].set('d', 'd', m["ident_d"]);
        m["ident_d"].set('e', 'e', m["ident_de"]);
        m["ident_de"].set('c', 'c', m["ident_dec"]);
        m["ident_dec"].set('i', 'i', m["ident_deci"]);
        m["ident_deci"].set('s', 's', m["ident_decis"]);
        m["ident_decis"].set('i', 'i', m["ident_decisi"]);
        m["ident_decisi"].set('o', 'o', m["ident_decisio"]);
        m["ident_decisio"].set('n', 'n', m["ident_decision"].set(0, 255, "tokDecision"));

        m["base"].set('i', 'i', m["ident_i"]);
        m["ident_i"].set('n', 'n', m["ident_in"]);
        m["ident_in"].set('t', 't', m["ident_int"].set(0, 255, "tokInt"));

        m["base"].set('p', 'p', m["ident_p"]);
        m["ident_p"].set('r', 'r', m["ident_pr"]);
        m["ident_pr"].set('i', 'i', m["ident_pri"]);
        m["ident_pri"].set('n', 'n', m["ident_prin"]);
        m["ident_prin"].set('t', 't', m["ident_print"].set(0, 255, "tokPrint"));
        m["ident_pr"].set('o', 'o', m["ident_pro"]);
        m["ident_pro"].set('g', 'g', m["ident_prog"]);
        m["ident_prog"].set('r', 'r', m["ident_progr"]);
        m["ident_progr"].set('a', 'a', m["ident_progra"]);
        m["ident_progra"].set('m', 'm', m["ident_program"].set(0, 255, "tokProgram"));

        m["base"].set('r', 'r', m["ident_r"]);
        m["ident_r"].set('e', 'e', m["ident_re"]);
        m["ident_re"].set('t', 't', m["ident_ret"]);
        m["ident_ret"].set('u', 'u', m["ident_retu"]);
        m["ident_retu"].set('r', 'r', m["ident_retur"]);
        m["ident_retur"].set('n', 'n', m["ident_return"].set(0, 255, "tokReturn"));
        m["ident_re"].set('a', 'a', m["ident_rea"]);
        m["ident_rea"].set('d', 'd', m["ident_read"].set(0, 255, "tokRead"));

        m["base"].set('s', 's', m["ident_s"]);
        m["ident_s"].set('t', 't', m["ident_st"]);
        m["ident_st"].set('a', 'a', m["ident_sta"]);
        m["ident_sta"].set('r', 'r', m["ident_star"]);
        m["ident_star"].set('t', 't', m["ident_start"].set(0, 255, "tokStart"));
        m["ident_st"].set('o', 'o', m["ident_sto"]);
        m["ident_sto"].set('p', 'p', m["ident_stop"].set(0, 255, "tokStop"));

        m["base"].set('v', 'v', m["ident_v"]);
        m["ident_v"].set('o', 'o', m["ident_vo"]);
        m["ident_vo"].set('i', 'i', m["ident_voi"]);
        m["ident_voi"].set('d', 'd', m["ident_void"].set(0, 255, "tokVoid"));

        m["base"].set('w', 'w', m["ident_w"]);
        m["ident_w"].set('h', 'h', m["ident_wh"]);
        m["ident_wh"].set('i', 'i', m["ident_whi"]);
        m["ident_whi"].set('l', 'l', m["ident_whil"]);
        m["ident_whil"].set('e', 'e', m["ident_while"].set(0, 255, "tokWhile"));

        m["ident"].set(0, 255, "tokIdent");
        m["ident"].set('a', 'z', m["ident"], 0);
        m["ident"].set('A', 'Z', m["ident"], 0);

        m["integer"].set(0, 255, "tokInteger");
        m["integer"].set('0', '9', m["integer"], 0);

        m["comment"].set(0, 255, m["comment"]);
        m["comment"].set('\r', '\r', m["ws"], "tokComment");
        m["comment"].set('\n', '\n', m["ws"], "tokComment");
        m["comment"].set('\t', '\t', m["ws"], "tokComment");
        m["comment"].set(' ', ' ', m["ws"], "tokComment");

        m.apply_defaults(m["base"]);
    }

    const State *get_init() {
        return &m["base"];
    }

private:
    StateMap m;
};

/*
All case sensitive
Alphabet
    all English letters (upper and lower), digits, plus the extra characters as seen below, plus WS
    No other characters allowed and they should generate lexical errors
        Each scanner error should display "Scanner Error:" followed by details.
Identifiers
    begin with a letter and
    continue with any number of letters
    you may assume no identifier is longer than 8
Keywords (reserved, suggested individual tokens)
    start stop decision while void int return read print program
Operators delimiters etc.
    =  <<  >>  =!  == :  +  -  *  / & %  . (  ) , { } ; [ ]
Integers
    any sequence of decimal digits, no sign
    you may assume no number longer than 8 digits
Comments start with # and end with WS
*/

#endif // LEXDEF_H
