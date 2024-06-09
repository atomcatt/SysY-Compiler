%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "parse.tab.hpp"

    int lines = 1;
    int words = 0;
    int chars = 1;

    const char* IDENT = "Ident";
    const char* INTCONST = "IntConst";
    const char* KEYWORD = "Keyword";
    const char* RIGHTBRACKET = "RightBracket";
    const char* LEFTBRACKET = "LeftBracket";
    const char* RIGHTCURLYBRACKET = "RightCurlyBracket";
    const char* LEFTCURLYBRACKET = "LeftCurlyBracket";
    const char* ADDOP = "AddOP";
    const char* MULOP = "MulOP";
    const char* CMP = "cmp";
    const char* END = "end";
    const char* ASSIGNT = "Assignment";
    const char* COMMAT = "Comma";
    const char* MODT = "mod";
    const char* RIGHTSQUAREBRACKET = "RightSquareBracket";
    const char* LEFTSQUAREBRACKET = "LeftSquareBracket";

    void print_head_info()
    {
        printf("%-20s %-10s %-20s %-10s \n", "Text", "Line", "Column (Start, End)", "Type");
    }
    void print_info(char* text, int len, int type)
    {
        // const char* type_info;
        // switch (type){
        //     case 0: type_info = IDENT; break;
        //     case 1: type_info = INTCONST; break;
        //     case 2: type_info = KEYWORD; break;
        //     case 3: type_info = RIGHTBRACKET; break;
        //     case 4: type_info = LEFTBRACKET; break;
        //     case 5: type_info = RIGHTCURLYBRACKET; break;
        //     case 6: type_info = LEFTCURLYBRACKET; break;
        //     case 7: type_info = ADDOP; break;
        //     case 8: type_info = MULOP; break;
        //     case 9: type_info = CMP; break;
        //     case 10: type_info = END; break;
        //     case 11: type_info = ASSIGNT; break;
        //     case 12: type_info = COMMAT; break;
        //     case 13: type_info = MODT; break;
        //     case 14: type_info = RIGHTSQUAREBRACKET; break;
        //     case 15: type_info = LEFTSQUAREBRACKET; break;
        // }
        // printf("%-20s %-10d (%d, %d) %-*s %-10s\n", text, lines, chars, chars + len - 1, 10, " ", type_info);
    }
%}

DIGIT               [0-9]
OCTDIGIT            [0-8]
HEXDIGIT            [0-9a-fA-F]
HEXPREFIX           0x|0X
ZERO                0
 /* NUMBER              [+-]?[1-9]{DIGIT}* */
NUMBER              [1-9]{DIGIT}*
OCTNUMBER           0{OCTDIGIT}+
HEXNUMBER           {HEXPREFIX}{HEXDIGIT}+
LETTER              [a-zA-Z]
NONDIGIT            {LETTER}|"_"
IDENTIFIER          ("_"|({NONDIGIT}|{DIGIT})*)|({LETTER}({NONDIGIT}|{DIGIT})*)
ILLEGALIDENT        {DIGIT}{IDENTIFIER}*
ONELINECOMMENT      "//".*
COMMENT             “/*”(.|\n)*“*/”
HEADERFILE          "<"{IDENTIFIER}".h>"|\"{IDENTIFIER}".h"\"
STRING              \".*\"
 /* GETADDRESS          "&"{IDENTIFIER} */



%x MULTY_COMMENT

%%
 /*These are keywords*/

"include" {int len = strlen(yytext); print_info(yytext, len, 2); chars += len; return INCLUDE;}
"const" {int len = strlen(yytext); print_info(yytext, len, 2); chars += len; return CONST;}
"int" {int len = strlen(yytext); print_info(yytext, len, 2); chars += len; return INT;}
"void" {int len = strlen(yytext); print_info(yytext, len, 2); chars += len; return VOID;}
"if" {int len = strlen(yytext); print_info(yytext, len, 2); chars += len; return IF;}
"else" {int len = strlen(yytext); print_info(yytext, len, 2); chars += len; return ELSE;}
"while" {int len = strlen(yytext); print_info(yytext, len, 2); chars += len; return WHILE;}
"break" {int len = strlen(yytext); print_info(yytext, len, 2); chars += len; return BREAK;}
"continue" {int len = strlen(yytext); print_info(yytext, len, 2); chars += len; return CONTINUE;}
"return" {int len = strlen(yytext); print_info(yytext, len, 2); chars += len; return RETURN;}
"main" {int len = strlen(yytext); print_info(yytext, len, 2); chars += len; yylval.const_string_val = strdup(yytext); return Ident;}
"&&" {int len = strlen(yytext); print_info(yytext, len, 9); chars += len; return AND;}
"||" {int len = strlen(yytext); print_info(yytext, len, 9); chars += len; return OR;}
"==" {int len = strlen(yytext); print_info(yytext, len, 9); chars += len; return EQ;}
"!=" {int len = strlen(yytext); print_info(yytext, len, 9); chars += len; return NE;}
"<" {int len = strlen(yytext); print_info(yytext, len, 9); chars += len; return LT;}
"<=" {int len = strlen(yytext); print_info(yytext, len, 9); chars += len; return LE;}
">" {int len = strlen(yytext); print_info(yytext, len, 9); chars += len; return GT;}
">=" {int len = strlen(yytext); print_info(yytext, len, 9); chars += len; return GE;}
"=" {int len = strlen(yytext); print_info(yytext, len, 11); chars += len; return ASSIGN;}
"(" {int len = strlen(yytext); print_info(yytext, len, 4); chars += len; return LPAREN;}
")" {int len = strlen(yytext); print_info(yytext, len, 3); chars += len; return RPAREN;}
"{" {int len = strlen(yytext); print_info(yytext, len, 6); chars += len; return LBRACE;}
"}" {int len = strlen(yytext); print_info(yytext, len, 5); chars += len; return RBRACE;}
";" {int len = strlen(yytext); print_info(yytext, len, 10); chars += len; return SEMI;}
"," {int len = strlen(yytext); print_info(yytext, len, 12); chars += len; return COMMA;}
"+" {int len = strlen(yytext); print_info(yytext, len, 7); chars += len; return ADD;}
"-" {int len = strlen(yytext); print_info(yytext, len, 7); chars += len; return SUB;}
"*" {int len = strlen(yytext); print_info(yytext, len, 8); chars += len; return MUL;}
"/" {int len = strlen(yytext); print_info(yytext, len, 8); chars += len; return DIV;}
"%" {int len = strlen(yytext); print_info(yytext, len, 13); chars += len; return MOD;}
"&" {int len = strlen(yytext); print_info(yytext, len, 9); chars += len; return SINGLEAND;}
"|" {int len = strlen(yytext); print_info(yytext, len, 9); chars += len; return SINGLEOR;}
"!" {int len = strlen(yytext); print_info(yytext, len, 9); chars += len; return NOT;}
"[" {int len = strlen(yytext); print_info(yytext, len, 15); chars += len; return LBRACK;}
"]" {int len = strlen(yytext); print_info(yytext, len, 14); chars += len; return RBRACK;}
"#" {int len = strlen(yytext); print_info(yytext, len, 10); chars += len; return HASH;}
" " {chars += 1;}
"\n" {lines += 1; chars = 1;}
"\t" {chars += 1;}
  /*These are comments*/
{ONELINECOMMENT} {}
"/*" {BEGIN(MULTY_COMMENT);}
<MULTY_COMMENT>\n {lines += 1; chars = 1;}
<MULTY_COMMENT>. {chars += 1;}
<MULTY_COMMENT>"*/" {BEGIN(INITIAL);}
 

 /*{COMMENT} {int len = strlen(yytext); char* line_pos = strchr(yytext, '\n'); while(line_pos != NULL){lines++; line_pos = strchr(line_pos + 1, '\n');}}*/
  /*These are constants*/
{OCTNUMBER} {int len = strlen(yytext); print_info(yytext, len, 1); chars += len; yylval.const_int_val = atoi(yytext); return IntConst;}
{NUMBER} {int len = strlen(yytext); print_info(yytext, len, 1); chars += len; yylval.const_int_val = atoi(yytext); return IntConst;}
{HEXNUMBER} {int len = strlen(yytext); print_info(yytext, len, 1); chars += len; yylval.const_int_val = atoi(yytext); return IntConst;}
{ZERO} {int len = strlen(yytext); print_info(yytext, len, 1); chars += len; yylval.const_int_val = atoi(yytext); return IntConst;}

{ILLEGALIDENT} {printf("Illegal identifier: %s\n", yytext); chars += strlen(yytext);}
{IDENTIFIER} {int len = strlen(yytext); print_info(yytext, len, 0); chars += len; yylval.const_string_val = strdup(yytext);return Ident;}
 /* {GETADDRESS} {int len = strlen(yytext); print_info(yytext, len, 0); chars += len; yylval.const_string_val = strdup(yytext);return GetAddressOfIdent;} */
{HEADERFILE} {int len = strlen(yytext); print_info(yytext, len, 2); chars += len; yylval.const_string_val = strdup(yytext); return HeaderFile;}
{STRING} {int len = strlen(yytext); print_info(yytext, len, 0); chars += len; yylval.const_string_val = strdup(yytext); return String;}

. {chars += strlen(yytext);}
%%

// void yyerror(const char *s) {
//     fprintf(stderr, "Error: %s at line %d, column %d\n", s, lines, chars);
// }