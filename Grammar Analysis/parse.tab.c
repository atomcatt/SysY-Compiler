/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CONST = 258,
     INT = 259,
     VOID = 260,
     IF = 261,
     ELSE = 262,
     WHILE = 263,
     BREAK = 264,
     CONTINUE = 265,
     RETURN = 266,
     ASSIGN = 267,
     AND = 268,
     OR = 269,
     EQ = 270,
     LT = 271,
     LE = 272,
     GT = 273,
     GE = 274,
     NE = 275,
     ADD = 276,
     SUB = 277,
     MUL = 278,
     DIV = 279,
     MOD = 280,
     NOT = 281,
     LPAREN = 282,
     RPAREN = 283,
     LBRACE = 284,
     RBRACE = 285,
     LBRACK = 286,
     RBRACK = 287,
     COMMA = 288,
     SEMI = 289,
     Ident = 290,
     IntConst = 291
   };
#endif
/* Tokens.  */
#define CONST 258
#define INT 259
#define VOID 260
#define IF 261
#define ELSE 262
#define WHILE 263
#define BREAK 264
#define CONTINUE 265
#define RETURN 266
#define ASSIGN 267
#define AND 268
#define OR 269
#define EQ 270
#define LT 271
#define LE 272
#define GT 273
#define GE 274
#define NE 275
#define ADD 276
#define SUB 277
#define MUL 278
#define DIV 279
#define MOD 280
#define NOT 281
#define LPAREN 282
#define RPAREN 283
#define LBRACE 284
#define RBRACE 285
#define LBRACK 286
#define RBRACK 287
#define COMMA 288
#define SEMI 289
#define Ident 290
#define IntConst 291




/* Copy the first part of user declarations.  */
#line 1 "parse.y"

    #include <stdio.h>
    int yylex(void);
    void yyerror(const char *s);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 53 "parse.y"
{
    int const_int_val;
    char *const_string_val;
}
/* Line 193 of yacc.c.  */
#line 179 "parse.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 192 "parse.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNRULES -- Number of states.  */
#define YYNSTATES  192

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    15,    17,    22,
      24,    28,    32,    37,    41,    46,    48,    51,    55,    57,
      61,    65,    67,    71,    73,    77,    80,    85,    89,    94,
      96,    99,   103,   105,   109,   115,   121,   128,   135,   137,
     141,   144,   149,   155,   159,   164,   167,   171,   173,   176,
     178,   180,   185,   187,   190,   192,   198,   206,   212,   215,
     218,   221,   225,   227,   229,   231,   234,   238,   243,   247,
     249,   251,   253,   257,   262,   265,   267,   269,   271,   273,
     276,   279,   283,   285,   289,   293,   297,   299,   303,   307,
     309,   313,   317,   321,   325,   327,   331,   335,   337,   341,
     343,   347
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    39,    -1,    52,    -1,    38,    39,    -1,
      38,    52,    -1,    40,    -1,    46,    -1,     3,     4,    41,
      34,    -1,    42,    -1,    41,    33,    42,    -1,    35,    12,
      44,    -1,    35,    43,    12,    44,    -1,    31,    75,    32,
      -1,    43,    31,    75,    32,    -1,    75,    -1,    29,    30,
      -1,    29,    45,    30,    -1,    44,    -1,    45,    33,    44,
      -1,     4,    47,    34,    -1,    48,    -1,    47,    33,    48,
      -1,    35,    -1,    35,    12,    50,    -1,    35,    49,    -1,
      35,    49,    12,    50,    -1,    31,    75,    32,    -1,    49,
      31,    75,    32,    -1,    60,    -1,    29,    30,    -1,    29,
      51,    30,    -1,    50,    -1,    51,    33,    50,    -1,     5,
      35,    27,    28,    56,    -1,     4,    35,    27,    28,    56,
      -1,     5,    35,    27,    53,    28,    56,    -1,     4,    35,
      27,    53,    28,    56,    -1,    54,    -1,    53,    33,    54,
      -1,     4,    35,    -1,     4,    35,    31,    32,    -1,     4,
      35,    31,    32,    55,    -1,    31,    60,    32,    -1,    55,
      31,    60,    32,    -1,    29,    30,    -1,    29,    57,    30,
      -1,    58,    -1,    57,    58,    -1,    39,    -1,    59,    -1,
      62,    12,    60,    34,    -1,    34,    -1,    60,    34,    -1,
      56,    -1,     6,    27,    61,    28,    59,    -1,     6,    27,
      61,    28,    59,     7,    59,    -1,     8,    27,    61,    28,
      59,    -1,     9,    34,    -1,    10,    34,    -1,    11,    34,
      -1,    11,    60,    34,    -1,    70,    -1,    74,    -1,    35,
      -1,    62,    63,    -1,    31,    60,    32,    -1,    63,    31,
      60,    32,    -1,    27,    60,    28,    -1,    62,    -1,    36,
      -1,    64,    -1,    35,    27,    28,    -1,    35,    27,    67,
      28,    -1,    66,    65,    -1,    21,    -1,    22,    -1,    26,
      -1,    60,    -1,    60,    68,    -1,    33,    60,    -1,    68,
      33,    60,    -1,    65,    -1,    69,    23,    65,    -1,    69,
      24,    65,    -1,    69,    25,    65,    -1,    69,    -1,    70,
      21,    69,    -1,    70,    22,    69,    -1,    70,    -1,    71,
      16,    70,    -1,    71,    17,    70,    -1,    71,    18,    70,
      -1,    71,    19,    70,    -1,    71,    -1,    72,    15,    71,
      -1,    72,    20,    71,    -1,    72,    -1,    73,    13,    72,
      -1,    73,    -1,    74,    14,    73,    -1,    70,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    66,    70,    74,    81,    85,    92,   100,
     104,   117,   121,   128,   132,   139,   144,   149,   156,   160,
     168,   175,   179,   186,   190,   194,   198,   205,   209,   217,
     221,   225,   232,   236,   243,   247,   251,   255,   269,   273,
     280,   284,   289,   297,   301,   308,   313,   321,   325,   332,
     336,   344,   349,   353,   357,   361,   365,   370,   375,   380,
     385,   390,   398,   405,   412,   416,   424,   428,   435,   441,
     445,   456,   460,   465,   470,   477,   482,   487,   495,   499,
     507,   511,   518,   523,   528,   533,   541,   546,   551,   559,
     563,   568,   573,   578,   586,   590,   595,   603,   607,   615,
     619,   627
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST", "INT", "VOID", "IF", "ELSE",
  "WHILE", "BREAK", "CONTINUE", "RETURN", "ASSIGN", "AND", "OR", "EQ",
  "LT", "LE", "GT", "GE", "NE", "ADD", "SUB", "MUL", "DIV", "MOD", "NOT",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "COMMA",
  "SEMI", "Ident", "IntConst", "$accept", "CompUnit", "Decl", "ConstDecl",
  "ConstDefList", "ConstDef", "ConstDefGroup", "ConstInitVal",
  "ConstInitValGroup", "VarDecl", "VarDeclGroup", "VarDef", "ArrDef",
  "InitVal", "InitValGroup", "FuncDef", "FuncFParams", "FuncFParam",
  "FuncFParamArr", "Block", "BlockGroup", "BlockItem", "Stmt", "Exp",
  "Cond", "LVal", "Arr", "PrimaryExp", "UnaryExp", "UnaryOp",
  "FuncRParams", "FuncRParamsGroup", "MulExp", "AddExp", "RelExp", "EqExp",
  "LAndExp", "LOrExp", "ConstExp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    38,    38,    39,    39,    40,    41,
      41,    42,    42,    43,    43,    44,    44,    44,    45,    45,
      46,    47,    47,    48,    48,    48,    48,    49,    49,    50,
      50,    50,    51,    51,    52,    52,    52,    52,    53,    53,
      54,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    61,    62,    62,    63,    63,    64,    64,
      64,    65,    65,    65,    65,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    70,    70,    70,    71,
      71,    71,    71,    71,    72,    72,    72,    73,    73,    74,
      74,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     4,     1,
       3,     3,     4,     3,     4,     1,     2,     3,     1,     3,
       3,     1,     3,     1,     3,     2,     4,     3,     4,     1,
       2,     3,     1,     3,     5,     5,     6,     6,     1,     3,
       2,     4,     5,     3,     4,     2,     3,     1,     2,     1,
       1,     4,     1,     2,     1,     5,     7,     5,     2,     2,
       2,     3,     1,     1,     1,     2,     3,     4,     3,     1,
       1,     1,     3,     4,     2,     1,     1,     1,     1,     2,
       2,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     6,     7,     3,     0,
      23,     0,    21,     0,     1,     4,     5,     0,     0,     9,
       0,     0,     0,    25,     0,    20,     0,     0,     0,     0,
       0,     8,    75,    76,    77,     0,     0,    64,    70,    24,
      29,    69,    71,    82,     0,    86,    62,     0,     0,     0,
      38,   101,     0,     0,     0,    23,    22,     0,     0,     0,
      11,    15,     0,     0,     0,    10,     0,    30,    32,     0,
       0,     0,    65,    74,     0,     0,     0,     0,     0,    40,
       0,    35,     0,     0,    27,    26,     0,    34,     0,    16,
      18,     0,    13,    12,     0,    68,    31,     0,    72,    78,
       0,     0,     0,    83,    84,    85,    87,    88,     0,     0,
       0,     0,     0,     0,     0,    45,    52,    49,    54,     0,
      47,    50,     0,    69,    37,    39,    28,    36,    17,     0,
      14,    33,     0,    79,    73,    66,     0,    41,     0,     0,
      58,    59,    60,     0,    46,    48,    53,     0,    19,    80,
       0,    67,     0,    42,     0,    89,    94,    97,    99,    63,
       0,    61,     0,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    43,     0,    55,
      90,    91,    92,    93,    95,    96,    98,   100,    57,    44,
       0,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,   117,     6,    18,    19,    29,    60,    91,     7,
      11,    12,    23,    39,    69,     8,    49,    50,   153,   118,
     119,   120,   121,   122,   154,    41,    72,    42,    43,    44,
     100,   133,    45,    46,   156,   157,   158,   159,    61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -153
static const yytype_int16 yypact[] =
{
     107,    -2,    -7,    28,    76,  -153,  -153,  -153,  -153,    30,
      17,    56,  -153,    13,  -153,  -153,  -153,    -1,   102,  -153,
     195,     5,   228,    19,    36,  -153,    11,   206,   228,    37,
      30,  -153,  -153,  -153,  -153,   228,    79,    24,  -153,  -153,
    -153,    47,  -153,  -153,   228,   106,   117,    60,    84,   -11,
    -153,   117,    70,   195,   228,    41,  -153,    84,    58,    98,
    -153,  -153,    89,   206,   228,  -153,    95,  -153,  -153,    -6,
     147,   228,   101,  -153,   228,   228,   228,   228,   228,   110,
     150,  -153,    84,   122,  -153,  -153,   125,  -153,    84,  -153,
    -153,    34,  -153,  -153,   130,  -153,  -153,   195,  -153,   132,
     138,   135,   228,  -153,  -153,  -153,   106,   106,   146,    36,
     143,   154,   155,   157,   217,  -153,  -153,  -153,  -153,   184,
    -153,  -153,   162,    54,  -153,  -153,  -153,  -153,  -153,   206,
    -153,  -153,   228,   164,  -153,  -153,   166,   168,   228,   228,
    -153,  -153,  -153,   167,  -153,  -153,  -153,   228,  -153,  -153,
     228,  -153,   228,   169,   174,   117,    80,    73,   190,   193,
     176,  -153,   175,  -153,   180,   228,    48,   228,   228,   228,
     228,   228,   228,   228,   228,    48,  -153,  -153,   183,   201,
     117,   117,   117,   117,    80,    80,    73,   190,  -153,  -153,
      48,  -153
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,    16,  -153,  -153,   196,  -153,   -56,  -153,  -153,
    -153,   199,  -153,   -35,  -153,   221,   203,   151,  -153,   -36,
    -153,   118,  -152,   -10,    97,   -72,  -153,  -153,   -40,  -153,
    -153,  -153,    66,   -22,    -8,    67,    71,  -153,    -9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      51,    68,     9,    90,    73,    51,    51,    93,   123,    47,
      40,    27,    81,    52,   179,    47,     5,    82,    85,    62,
      15,    87,    83,   188,    96,    66,    40,    97,    10,    20,
      28,    53,    51,    48,   103,   104,   105,    51,   191,    57,
      26,    51,    51,    40,    21,    86,   124,   123,    22,    63,
      54,    70,   127,    20,   110,    94,   111,   112,   113,   114,
      99,   101,   131,    13,   128,    17,   147,   129,    64,    32,
      33,    55,    22,   148,    34,    35,    14,    80,    71,     1,
       2,     3,   116,    37,    38,    71,    88,    40,   171,    24,
      25,    83,   136,   172,   123,    79,   167,   168,   169,   170,
      32,    33,    84,   123,   143,    34,    35,    51,    36,    67,
       1,     2,     3,    80,    37,    38,   155,   155,   123,    32,
      33,    92,   149,    95,    34,    35,    47,    59,    89,    74,
      75,    76,   102,    37,    38,    30,    31,   162,    77,    78,
     163,   108,   164,   106,   107,   180,   181,   182,   183,   155,
     155,   155,   155,     1,   109,   178,   110,   126,   111,   112,
     113,   114,   130,   184,   185,   132,   134,   135,    32,    33,
     138,    32,    33,    34,    35,    98,    34,    35,   137,    80,
     115,   139,    37,    38,   116,    37,    38,     1,   109,   140,
     110,   141,   111,   112,   113,   114,   146,   150,   151,   152,
     165,   161,   166,   173,   175,    32,    33,   174,   190,   176,
      34,    35,   177,    80,   144,   189,    32,    33,   116,    37,
      38,    34,    35,    56,    36,    16,    65,    32,    33,    58,
      37,    38,    34,    35,   125,    59,   160,   145,    32,    33,
     186,    37,    38,    34,    35,   187,     0,     0,     0,    32,
      33,   142,    37,    38,    34,    35,     0,     0,     0,     0,
       0,     0,     0,    37,    38
};

static const yytype_int16 yycheck[] =
{
      22,    36,     4,    59,    44,    27,    28,    63,    80,     4,
      20,    12,    48,    22,   166,     4,     0,    28,    53,    28,
       4,    57,    33,   175,    30,    35,    36,    33,    35,    12,
      31,    12,    54,    28,    74,    75,    76,    59,   190,    28,
      27,    63,    64,    53,    27,    54,    82,   119,    31,    12,
      31,    27,    88,    12,     6,    64,     8,     9,    10,    11,
      70,    71,    97,    35,    30,    35,    12,    33,    31,    21,
      22,    35,    31,   129,    26,    27,     0,    29,    31,     3,
       4,     5,    34,    35,    36,    31,    28,    97,    15,    33,
      34,    33,   102,    20,   166,    35,    16,    17,    18,    19,
      21,    22,    32,   175,   114,    26,    27,   129,    29,    30,
       3,     4,     5,    29,    35,    36,   138,   139,   190,    21,
      22,    32,   132,    28,    26,    27,     4,    29,    30,    23,
      24,    25,    31,    35,    36,    33,    34,   147,    21,    22,
     150,    31,   152,    77,    78,   167,   168,   169,   170,   171,
     172,   173,   174,     3,     4,   165,     6,    32,     8,     9,
      10,    11,    32,   171,   172,    33,    28,    32,    21,    22,
      27,    21,    22,    26,    27,    28,    26,    27,    32,    29,
      30,    27,    35,    36,    34,    35,    36,     3,     4,    34,
       6,    34,     8,     9,    10,    11,    34,    33,    32,    31,
      31,    34,    28,    13,    28,    21,    22,    14,     7,    34,
      26,    27,    32,    29,    30,    32,    21,    22,    34,    35,
      36,    26,    27,    24,    29,     4,    30,    21,    22,    26,
      35,    36,    26,    27,    83,    29,   139,   119,    21,    22,
     173,    35,    36,    26,    27,   174,    -1,    -1,    -1,    21,
      22,    34,    35,    36,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    38,    39,    40,    46,    52,     4,
      35,    47,    48,    35,     0,    39,    52,    35,    41,    42,
      12,    27,    31,    49,    33,    34,    27,    12,    31,    43,
      33,    34,    21,    22,    26,    27,    29,    35,    36,    50,
      60,    62,    64,    65,    66,    69,    70,     4,    28,    53,
      54,    70,    75,    12,    31,    35,    48,    28,    53,    29,
      44,    75,    75,    12,    31,    42,    60,    30,    50,    51,
      27,    31,    63,    65,    23,    24,    25,    21,    22,    35,
      29,    56,    28,    33,    32,    50,    75,    56,    28,    30,
      44,    45,    32,    44,    75,    28,    30,    33,    28,    60,
      67,    60,    31,    65,    65,    65,    69,    69,    31,     4,
       6,     8,     9,    10,    11,    30,    34,    39,    56,    57,
      58,    59,    60,    62,    56,    54,    32,    56,    30,    33,
      32,    50,    33,    68,    28,    32,    60,    32,    27,    27,
      34,    34,    34,    60,    30,    58,    34,    12,    44,    60,
      33,    32,    31,    55,    61,    70,    71,    72,    73,    74,
      61,    34,    60,    60,    60,    31,    28,    16,    17,    18,
      19,    15,    20,    13,    14,    28,    34,    32,    60,    59,
      70,    70,    70,    70,    71,    71,    72,    73,    59,    32,
       7,    59
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 62 "parse.y"
    {
        printf("Decl -> CompUnit\n");
    
    ;}
    break;

  case 3:
#line 67 "parse.y"
    {
        printf("FuncDef -> CompUnit\n");
    ;}
    break;

  case 4:
#line 71 "parse.y"
    {
        printf("CompUnit Decl -> CompUnit\n");
    ;}
    break;

  case 5:
#line 75 "parse.y"
    {
        printf("CompUnit FuncDef -> CompUnit\n");
    ;}
    break;

  case 6:
#line 82 "parse.y"
    {
        printf("ConstDecl -> Decl\n");
    ;}
    break;

  case 7:
#line 86 "parse.y"
    {
        printf("VarDecl -> Decl\n");
    ;}
    break;

  case 8:
#line 93 "parse.y"
    {
        printf("const int ConstDefList ; -> ConstDecl\n");
    ;}
    break;

  case 9:
#line 101 "parse.y"
    {
        printf("ConstDef -> ConstDefList\n");
    ;}
    break;

  case 10:
#line 105 "parse.y"
    {
        printf("ConstDef , ConstDef -> ConstDefList\n");
    ;}
    break;

  case 11:
#line 118 "parse.y"
    {
        printf("%s = ConstInitVal -> ConstDef\n", (yyvsp[(1) - (3)].const_string_val));
    ;}
    break;

  case 12:
#line 122 "parse.y"
    {
        printf("%s ConstDefGroup = ConstInitVal -> ConstDef\n", (yyvsp[(1) - (4)].const_string_val));
    ;}
    break;

  case 13:
#line 129 "parse.y"
    {
        printf("[ ConstExp ] -> ConstDefGroup\n")
    ;}
    break;

  case 14:
#line 133 "parse.y"
    {
        printf("ConstDefGroup [ ConstExp ] -> ConstDefGroup\n")
    ;}
    break;

  case 15:
#line 140 "parse.y"
    {
        printf("ConstExp -> ConstInitVal\n");
    
    ;}
    break;

  case 16:
#line 145 "parse.y"
    {
        printf("{ } -> ConstInitVal\n");
    
    ;}
    break;

  case 17:
#line 150 "parse.y"
    {
        printf("{ ConstInitValGroup } -> ConstInitVal\n");
    ;}
    break;

  case 18:
#line 157 "parse.y"
    {
        printf("ConstInitVal -> ConstInitValGroup\n");
    ;}
    break;

  case 19:
#line 161 "parse.y"
    {
        printf("ConstInitValGroup , ConstInitVal -> ConstInitValGroup\n");
    
    ;}
    break;

  case 20:
#line 169 "parse.y"
    {
        printf("int VarDeclGroup ; -> VarDecl\n");
    ;}
    break;

  case 21:
#line 176 "parse.y"
    {
        printf("VarDef -> VarDeclGroup\n");
    ;}
    break;

  case 22:
#line 180 "parse.y"
    {
        printf("VarDef , VarDef -> VarDeclGroup\n");
    ;}
    break;

  case 23:
#line 187 "parse.y"
    {
        printf("%s -> VarDef\n", (yyvsp[(1) - (1)].const_string_val));
    ;}
    break;

  case 24:
#line 191 "parse.y"
    {
        printf("%s = InitVal -> VarDef\n", (yyvsp[(1) - (3)].const_string_val));
    ;}
    break;

  case 25:
#line 195 "parse.y"
    {
        printf("%s ArrDef -> VarDef\n", (yyvsp[(1) - (2)].const_string_val));
    ;}
    break;

  case 26:
#line 199 "parse.y"
    {
        printf("%s Arrdef = InitVal -> VarDef\n", (yyvsp[(1) - (4)].const_string_val));
    ;}
    break;

  case 27:
#line 206 "parse.y"
    {
        printf("[ ConstExp ] -> ArrDef\n");
    ;}
    break;

  case 28:
#line 210 "parse.y"
    {
        printf("ArrDef [ ConstExp ] -> ArrDef\n");
    
    ;}
    break;

  case 29:
#line 218 "parse.y"
    {
        printf("Exp -> InitVal\n");
    ;}
    break;

  case 30:
#line 222 "parse.y"
    {
        printf("{ } -> InitVal\n");
    ;}
    break;

  case 31:
#line 226 "parse.y"
    {
        printf("{ InitValGroup } -> InitVal\n");
    ;}
    break;

  case 32:
#line 233 "parse.y"
    {
        printf("InitVal -> InitValGroup\n");
    ;}
    break;

  case 33:
#line 237 "parse.y"
    {
        printf("InitValGroup , InitVal -> InitValGroup\n");
    ;}
    break;

  case 34:
#line 244 "parse.y"
    {
        printf("void %s ( ) Block -> FuncDef\n", (yyvsp[(2) - (5)].const_string_val));
    ;}
    break;

  case 35:
#line 248 "parse.y"
    {
        printf("int %s ( ) Block -> FuncDef\n", (yyvsp[(2) - (5)].const_string_val));
    ;}
    break;

  case 36:
#line 252 "parse.y"
    {
        printf("void %s ( FuncFParams ) Block -> FuncDef\n", (yyvsp[(2) - (6)].const_string_val));
    ;}
    break;

  case 37:
#line 256 "parse.y"
    {
        printf("int %s ( FuncFParams ) Block -> FuncDef\n", (yyvsp[(2) - (6)].const_string_val));
    ;}
    break;

  case 38:
#line 270 "parse.y"
    {
        printf("FuncFParam -> FuncFParams\n");
    ;}
    break;

  case 39:
#line 274 "parse.y"
    {
        printf("FuncFParams , FuncFParam -> FuncFParams\n");
    ;}
    break;

  case 40:
#line 281 "parse.y"
    {
        printf("int %s -> FuncFParam\n", (yyvsp[(2) - (2)].const_string_val));
    ;}
    break;

  case 41:
#line 285 "parse.y"
    {
        //printf("INT Ident [LBRACK RBRACK {LBRACK Exp RBRACK}] -> FuncFParam\n");
        printf("int %s [ ] -> FuncFParam\n", (yyvsp[(2) - (4)].const_string_val));
    ;}
    break;

  case 42:
#line 290 "parse.y"
    {
        //printf("INT Ident [LBRACK RBRACK {LBRACK Exp RBRACK}] -> FuncFParam\n");
        printf("int %s [ ] FuncFParamArr -> FuncFParam\n", (yyvsp[(2) - (5)].const_string_val));
    ;}
    break;

  case 43:
#line 298 "parse.y"
    {
        printf("[ Exp ] -> FuncFParamArr\n");
    ;}
    break;

  case 44:
#line 302 "parse.y"
    {
        printf("FuncFParamArr [ Exp ] -> FuncFParamArr\n");
    ;}
    break;

  case 45:
#line 309 "parse.y"
    {
        //printf("LBRACE RBRACE -> Block\n");
        printf("{ } -> Block\n");
    ;}
    break;

  case 46:
#line 314 "parse.y"
    {
        //printf("LBRACE {BlockItem} RBRACE -> Block\n");
        printf("{ BlockGroup } -> Block\n");
    ;}
    break;

  case 47:
#line 322 "parse.y"
    {
        printf("BlockItem -> BlockGroup\n");
    ;}
    break;

  case 48:
#line 326 "parse.y"
    {
        printf("BlockGroup BlockItem -> BlockGroup\n");
    ;}
    break;

  case 49:
#line 333 "parse.y"
    {
        printf("Decl -> BlockItem\n");
    ;}
    break;

  case 50:
#line 337 "parse.y"
    {
        printf("Stmt -> BlockItem\n");
    
    ;}
    break;

  case 51:
#line 345 "parse.y"
    {
        printf("LVal = Exp ; -> Stmt\n");
    
    ;}
    break;

  case 52:
#line 350 "parse.y"
    {
        printf("; -> Stmt\n");
    ;}
    break;

  case 53:
#line 354 "parse.y"
    {
        printf("Exp ; -> Stmt\n");
    ;}
    break;

  case 54:
#line 358 "parse.y"
    {
        printf("Block -> Stmt\n");
    ;}
    break;

  case 55:
#line 362 "parse.y"
    {
        printf("if ( Cond ) Stmt -> Stmt\n");
    ;}
    break;

  case 56:
#line 366 "parse.y"
    {
        //printf("IF LPAREN Cond RPAREN Stmt ELSE Stmt -> Stmt\n");
        printf("if ( Cond ) Stmt else Stmt -> Stmt\n");
    ;}
    break;

  case 57:
#line 371 "parse.y"
    {
        //printf("WHILE LPAREN Cond RPAREN Stmt -> Stmt\n");
        printf("while ( Cond ) Stmt -> Stmt\n");
    ;}
    break;

  case 58:
#line 376 "parse.y"
    {
        //printf("BREAK SEMI -> Stmt\n");
        printf("break ; -> Stmt\n");
    ;}
    break;

  case 59:
#line 381 "parse.y"
    {
        //printf("CONTINUE SEMI -> Stmt\n");
        printf("continue ; -> Stmt\n");
    ;}
    break;

  case 60:
#line 386 "parse.y"
    {
        //printf("RETURN SEMI -> Stmt\n");
        printf("return ; -> Stmt\n");
    ;}
    break;

  case 61:
#line 391 "parse.y"
    {
        //printf("RETURN Exp SEMI -> Stmt\n");
        printf("return Exp ; -> Stmt\n");
    ;}
    break;

  case 62:
#line 399 "parse.y"
    {
        printf("AddExp -> Exp\n");
    ;}
    break;

  case 63:
#line 406 "parse.y"
    {
        printf("LOrExp -> Cond\n");
    ;}
    break;

  case 64:
#line 413 "parse.y"
    {
        printf("%s -> LVal\n", (yyvsp[(1) - (1)].const_string_val));
    ;}
    break;

  case 65:
#line 417 "parse.y"
    {
        //printf("Ident {LBRACK Exp RBRACK} -> LVal\n");
        printf("LVal Arr -> LVal\n");
    ;}
    break;

  case 66:
#line 425 "parse.y"
    {
        printf("[ Exp ] -> Arr\n");
    ;}
    break;

  case 67:
#line 429 "parse.y"
    {
        printf("Arr [ Exp ] -> Arr\n");
    ;}
    break;

  case 68:
#line 436 "parse.y"
    {
        //printf("LPAREN Exp RPAREN -> PrimaryExp\n");
        printf("( Exp ) -> PrimaryExp\n");
    
    ;}
    break;

  case 69:
#line 442 "parse.y"
    {
        printf("LVal -> PrimaryExp\n");
    ;}
    break;

  case 70:
#line 446 "parse.y"
    {
        printf("%d -> PrimaryExp\n", (yyvsp[(1) - (1)].const_int_val));
    ;}
    break;

  case 71:
#line 457 "parse.y"
    {
        printf("PrimaryExp -> UnaryExp\n");
    ;}
    break;

  case 72:
#line 461 "parse.y"
    {
        //printf("Ident LPAREN RPAREN -> UnaryExp\n");
        printf("%s ( ) -> UnaryExp\n", (yyvsp[(1) - (3)].const_string_val));
    ;}
    break;

  case 73:
#line 466 "parse.y"
    {
        //printf("Ident LPAREN FuncRParams RPAREN -> UnaryExp\n");
        printf("%s ( FuncRParams ) -> UnaryExp\n", (yyvsp[(1) - (4)].const_string_val));
    ;}
    break;

  case 74:
#line 471 "parse.y"
    {
        printf("UnaryOp UnaryExp -> UnaryExp\n");
    ;}
    break;

  case 75:
#line 478 "parse.y"
    {
        //printf("ADD -> UnaryOp\n");
        printf("+ -> UnaryOp\n");
    ;}
    break;

  case 76:
#line 483 "parse.y"
    {
        //printf("SUB -> UnaryOp\n");
        printf("- -> UnaryOp\n");
    ;}
    break;

  case 77:
#line 488 "parse.y"
    {
        //printf("NOT -> UnaryOp\n");
        printf("! -> UnaryOp\n");
    ;}
    break;

  case 78:
#line 496 "parse.y"
    {
        printf("Exp -> FuncRParams\n");
    ;}
    break;

  case 79:
#line 500 "parse.y"
    {
        //printf("Exp {COMMA Exp} -> FuncRParams\n");
        printf("Exp FuncRParamsGroup -> FuncRParams\n");
    ;}
    break;

  case 80:
#line 508 "parse.y"
    {
        printf(", Exp -> FuncRParamsGroup\n");
    ;}
    break;

  case 81:
#line 512 "parse.y"
    {
        printf("FuncRParamsGroup , Exp -> FuncRParamsGroup\n");
    ;}
    break;

  case 82:
#line 519 "parse.y"
    {
        printf("UnaryExp -> MulExp\n");
    
    ;}
    break;

  case 83:
#line 524 "parse.y"
    {
        //printf("MulExp MUL UnaryExp -> MulExp\n");
        printf("MulExp * UnaryExp -> MulExp\n");
    ;}
    break;

  case 84:
#line 529 "parse.y"
    {
        //printf("MulExp DIV UnaryExp -> MulExp\n");
        printf("MulExp / UnaryExp -> MulExp\n");
    ;}
    break;

  case 85:
#line 534 "parse.y"
    {
        //printf("MulExp MOD UnaryExp -> MulExp\n");
        printf("MulExp %% UnaryExp -> MulExp\n");
    ;}
    break;

  case 86:
#line 542 "parse.y"
    {
        printf("MulExp -> AddExp\n");
    
    ;}
    break;

  case 87:
#line 547 "parse.y"
    {
        //printf("AddExp ADD MulExp -> AddExp\n");
        printf("AddExp + MulExp -> AddExp\n");
    ;}
    break;

  case 88:
#line 552 "parse.y"
    {
        //printf("AddExp SUB MulExp -> AddExp\n");
        printf("AddExp - MulExp -> AddExp\n");
    ;}
    break;

  case 89:
#line 560 "parse.y"
    {
        printf("AddExp -> RelExp\n");
    ;}
    break;

  case 90:
#line 564 "parse.y"
    {
        //printf("RelExp LT AddExp -> RelExp\n");
        printf("RelExp < AddExp -> RelExp\n");
    ;}
    break;

  case 91:
#line 569 "parse.y"
    {
        //printf("RelExp LE AddExp -> RelExp\n");
        printf("RelExp <= AddExp -> RelExp\n");
    ;}
    break;

  case 92:
#line 574 "parse.y"
    {
        //printf("RelExp GT AddExp -> RelExp\n");
        printf("RelExp > AddExp -> RelExp\n");
    ;}
    break;

  case 93:
#line 579 "parse.y"
    {
        //printf("RelExp GE AddExp -> RelExp\n");
        printf("RelExp >= AddExp -> RelExp\n");
    ;}
    break;

  case 94:
#line 587 "parse.y"
    {
        printf("RelExp -> EqExp\n");
    ;}
    break;

  case 95:
#line 591 "parse.y"
    {
        //printf("EqExp EQ RelExp -> EqExp\n");
        printf("EqExp == RelExp -> EqExp\n");
    ;}
    break;

  case 96:
#line 596 "parse.y"
    {
        //printf("EqExp NE RelExp -> EqExp\n");
        printf("EqExp != RelExp -> EqExp\n");
    ;}
    break;

  case 97:
#line 604 "parse.y"
    {
        printf("EqExp -> LAndExp\n");
    ;}
    break;

  case 98:
#line 608 "parse.y"
    {
        //printf("LAndExp AND EqExp -> LAndExp\n");
        printf("LAndExp && EqExp -> LAndExp\n");
    ;}
    break;

  case 99:
#line 616 "parse.y"
    {
        printf("LAndExp -> LOrExp\n");
    ;}
    break;

  case 100:
#line 620 "parse.y"
    {
        //printf("LOrExp OR LAndExp -> LOrExp\n");
        printf("LOrExp || LAndExp -> LOrExp\n");
    ;}
    break;

  case 101:
#line 628 "parse.y"
    {
        printf("AddExp -> ConstExp\n");
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2318 "parse.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 633 "parse.y"


void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int main() {
    yyparse();
    return 0;
}
