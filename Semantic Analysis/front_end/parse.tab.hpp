/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSE_TAB_HPP_INCLUDED
# define YY_YY_PARSE_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INCLUDE = 258,                 /* INCLUDE  */
    CONST = 259,                   /* CONST  */
    INT = 260,                     /* INT  */
    VOID = 261,                    /* VOID  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    WHILE = 264,                   /* WHILE  */
    BREAK = 265,                   /* BREAK  */
    CONTINUE = 266,                /* CONTINUE  */
    RETURN = 267,                  /* RETURN  */
    ASSIGN = 268,                  /* ASSIGN  */
    AND = 269,                     /* AND  */
    OR = 270,                      /* OR  */
    EQ = 271,                      /* EQ  */
    LT = 272,                      /* LT  */
    LE = 273,                      /* LE  */
    GT = 274,                      /* GT  */
    GE = 275,                      /* GE  */
    NE = 276,                      /* NE  */
    ADD = 277,                     /* ADD  */
    SUB = 278,                     /* SUB  */
    MUL = 279,                     /* MUL  */
    DIV = 280,                     /* DIV  */
    MOD = 281,                     /* MOD  */
    NOT = 282,                     /* NOT  */
    LPAREN = 283,                  /* LPAREN  */
    RPAREN = 284,                  /* RPAREN  */
    LBRACE = 285,                  /* LBRACE  */
    RBRACE = 286,                  /* RBRACE  */
    LBRACK = 287,                  /* LBRACK  */
    RBRACK = 288,                  /* RBRACK  */
    COMMA = 289,                   /* COMMA  */
    SEMI = 290,                    /* SEMI  */
    HASH = 291,                    /* HASH  */
    Ident = 292,                   /* Ident  */
    IntConst = 293,                /* IntConst  */
    HeaderFile = 294,              /* HeaderFile  */
    String = 295,                  /* String  */
    IFX = 296                      /* IFX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 137 "parse.y"

    int const_int_val;
    char *const_string_val;
    struct BaseAST* base_type;
    struct CompUnitAST* compunit_type;
    struct ExternalDefAST* externaldef_type;
    struct DeclAST* decl_type;
    // struct ConstExpAST* constexp_type;
    struct ConstDeclAST* constdecl_type;
    struct ConstDefListAST* constdeflist_type;
    struct ConstDefAST* constdef_type;
    struct ConstArrDefAST* constarrdef_type;
    struct ConstInitValAST* constinitval_type;
    struct ConstInitValListAST* constinitvallist_type;
    struct VarDeclAST* vardecl_type;
    struct VarDefListAST* vardeflist_type;
    struct VarDefAST* vardef_type;
    struct ArrDefAST* arrdef_type;
    struct InitValAST* initval_type;
    struct InitValListAST* initvallist_type;
    struct FuncDefAST* funcdef_type;
    struct FuncFParamsAST* funcfparams_type;
    struct FuncFParamAST* funcfparam_type;
    struct BlockAST* block_type;
    struct BlockGroupAST* blockgroup_type;
    struct BlockItemAST* blockitem_type;
    struct StmtAST* stmt_type;
    struct NullStmtAST* nullstmt_type;
    struct AssignStmtAST* assignstmt_type;
    struct ExpStmtAST* expstmt_type;
    struct BlockStmtAST* blockstmt_type;
    struct IfStmtAST* ifstmt_type;
    struct WhileStmtAST* whilestmt_type;
    struct BreakStmtAST* breakstmt_type;
    struct ContinueStmtAST* continuestmt_type; 
    struct ReturnStmtAST* returnstmt_type;
    struct LValAST* lval_type;
    // struct CondAST* cond_type;
    struct ExpAST* exp_type;
    // struct PrimaryExpAST* primaryexp_type;
    struct BinaryExpAST* binaryexp_type;
    struct VarExpAST* varexp_type;
    struct NumExpAST* numexp_type;
    struct UnaryExpAST* unaryexp_type;
    struct FuncCallAST* funccall_type;
    struct UnaryOpAST* unaryop_type;
    struct FuncRParamsAST* funcrparams_type;
    // struct MulExpAST* mulexp_type;
    // struct AddExpAST* addexp_type;
    // struct RelExpAST* relexp_type;
    // struct EqExpAST* eqexp_type;
    // struct LAndExpAST* landexp_type;
    // struct LOrExpAST* lorexp_type;

#line 160 "parse.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSE_TAB_HPP_INCLUDED  */
