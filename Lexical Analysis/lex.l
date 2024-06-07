%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>

    int lines = 1;
    int words = 0;
    int chars = 1;

    const char* INTCONST = "IntConst";
    const char* IDENT = "Ident";
    void print_head_info()
    {
        printf("%-20s %-10s %-20s %-10s \n", "Text", "Line", "Column (Start, End)", "Type");
    }
    void print_info(char* text, int len, int type)
    {
        const char* type_info = type ? INTCONST : IDENT;
        printf("%-20s %-10d (%d, %d) %-*s %-10s\n", text, lines, chars, chars + len, 10, " ", type_info);
    }
%}

DIGIT               [0-9]
OCTDIGIT            [0-8]
HEXDIGIT            [0-9a-fA-F]
HEXPREFIX           0x|0X
ZERO                0
NUMBER              [1-9]{DIGIT}*
OCTNUMBER           0{OCTDIGIT}+
HEXNUMBER           {HEXPREFIX}{HEXDIGIT}+
LETTER              [a-zA-Z]
NONDIGIT            {LETTER}|"_"
IDENTIFIER          ("_"|({NONDIGIT}|{DIGIT})*)|({LETTER}({NONDIGIT}|{DIGIT})*)
 /*IDENTIFIER          {NONDIGIT}({NONDIGIT}|{DIGIT})**/
ILLEGALIDENT        {DIGIT}{IDENTIFIER}*
ONELINECOMMENT      "//".*
COMMENT             “/*”(.|\n)*“*/”
HEADERFILE          "<"{IDENTIFIER}".h>"|\"{IDENTIFIER}".h"\"
STRING              \".*\"

%x MULTY_COMMENT

%%
 /*These are keywords*/
"const" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"int" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"void" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"if" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"else" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"while" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"break" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"continue" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"return" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"&&" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"||" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"==" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"!=" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"<" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"<=" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
">" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
">=" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"=" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"(" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
")" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"{" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"}" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
";" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"," {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"+" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"-" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"*" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"/" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"%" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"!" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"[" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
"]" {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
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
{OCTNUMBER} {int len = strlen(yytext); print_info(yytext, len, 1); chars += len;}
{NUMBER} {int len = strlen(yytext); print_info(yytext, len, 1); chars += len;}
{HEXNUMBER} {int len = strlen(yytext); print_info(yytext, len, 1); chars += len;}
{ZERO} {int len = strlen(yytext); print_info(yytext, len, 1); chars += len;}

{ILLEGALIDENT} {printf("Illegal identifier: %s\n", yytext); chars += strlen(yytext);}
{IDENTIFIER} {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
{STRING} {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}
{HEADERFILE} {int len = strlen(yytext); print_info(yytext, len, 0); chars += len;}

. {printf("Unrecognized character: %s\n", yytext); chars += strlen(yytext);}
%%

int main(int argv, char* argc[])
{
    yyin = stdin;
    print_head_info();
    yylex();
    return 0;
}