/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parse.y"

    #include <stdio.h>
    int yylex(void);
    void yyerror(const char *s);

#line 77 "parse.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parse.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONST = 3,                      /* CONST  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_VOID = 5,                       /* VOID  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_CONTINUE = 10,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_ASSIGN = 12,                    /* ASSIGN  */
  YYSYMBOL_AND = 13,                       /* AND  */
  YYSYMBOL_OR = 14,                        /* OR  */
  YYSYMBOL_EQ = 15,                        /* EQ  */
  YYSYMBOL_LT = 16,                        /* LT  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_GT = 18,                        /* GT  */
  YYSYMBOL_GE = 19,                        /* GE  */
  YYSYMBOL_NE = 20,                        /* NE  */
  YYSYMBOL_ADD = 21,                       /* ADD  */
  YYSYMBOL_SUB = 22,                       /* SUB  */
  YYSYMBOL_MUL = 23,                       /* MUL  */
  YYSYMBOL_DIV = 24,                       /* DIV  */
  YYSYMBOL_MOD = 25,                       /* MOD  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_LPAREN = 27,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 28,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 29,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 30,                    /* RBRACE  */
  YYSYMBOL_LBRACK = 31,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 32,                    /* RBRACK  */
  YYSYMBOL_COMMA = 33,                     /* COMMA  */
  YYSYMBOL_SEMI = 34,                      /* SEMI  */
  YYSYMBOL_Ident = 35,                     /* Ident  */
  YYSYMBOL_IntConst = 36,                  /* IntConst  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_CompUnit = 38,                  /* CompUnit  */
  YYSYMBOL_Decl = 39,                      /* Decl  */
  YYSYMBOL_ConstDecl = 40,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 41,              /* ConstDefList  */
  YYSYMBOL_ConstDef = 42,                  /* ConstDef  */
  YYSYMBOL_ConstDefGroup = 43,             /* ConstDefGroup  */
  YYSYMBOL_ConstInitVal = 44,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValGroup = 45,         /* ConstInitValGroup  */
  YYSYMBOL_VarDecl = 46,                   /* VarDecl  */
  YYSYMBOL_VarDeclGroup = 47,              /* VarDeclGroup  */
  YYSYMBOL_VarDef = 48,                    /* VarDef  */
  YYSYMBOL_ArrDef = 49,                    /* ArrDef  */
  YYSYMBOL_InitVal = 50,                   /* InitVal  */
  YYSYMBOL_InitValGroup = 51,              /* InitValGroup  */
  YYSYMBOL_FuncDef = 52,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 53,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 54,                /* FuncFParam  */
  YYSYMBOL_FuncFParamArr = 55,             /* FuncFParamArr  */
  YYSYMBOL_Block = 56,                     /* Block  */
  YYSYMBOL_BlockGroup = 57,                /* BlockGroup  */
  YYSYMBOL_BlockItem = 58,                 /* BlockItem  */
  YYSYMBOL_Stmt = 59,                      /* Stmt  */
  YYSYMBOL_Exp = 60,                       /* Exp  */
  YYSYMBOL_Cond = 61,                      /* Cond  */
  YYSYMBOL_LVal = 62,                      /* LVal  */
  YYSYMBOL_Arr = 63,                       /* Arr  */
  YYSYMBOL_PrimaryExp = 64,                /* PrimaryExp  */
  YYSYMBOL_UnaryExp = 65,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 66,                   /* UnaryOp  */
  YYSYMBOL_FuncRParams = 67,               /* FuncRParams  */
  YYSYMBOL_FuncRParamsGroup = 68,          /* FuncRParamsGroup  */
  YYSYMBOL_MulExp = 69,                    /* MulExp  */
  YYSYMBOL_AddExp = 70,                    /* AddExp  */
  YYSYMBOL_RelExp = 71,                    /* RelExp  */
  YYSYMBOL_EqExp = 72,                     /* EqExp  */
  YYSYMBOL_LAndExp = 73,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 74,                    /* LOrExp  */
  YYSYMBOL_ConstExp = 75                   /* ConstExp  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
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

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CONST", "INT", "VOID",
  "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "RETURN", "ASSIGN", "AND",
  "OR", "EQ", "LT", "LE", "GT", "GE", "NE", "ADD", "SUB", "MUL", "DIV",
  "MOD", "NOT", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK",
  "COMMA", "SEMI", "Ident", "IntConst", "$accept", "CompUnit", "Decl",
  "ConstDecl", "ConstDefList", "ConstDef", "ConstDefGroup", "ConstInitVal",
  "ConstInitValGroup", "VarDecl", "VarDeclGroup", "VarDef", "ArrDef",
  "InitVal", "InitValGroup", "FuncDef", "FuncFParams", "FuncFParam",
  "FuncFParamArr", "Block", "BlockGroup", "BlockItem", "Stmt", "Exp",
  "Cond", "LVal", "Arr", "PrimaryExp", "UnaryExp", "UnaryOp",
  "FuncRParams", "FuncRParamsGroup", "MulExp", "AddExp", "RelExp", "EqExp",
  "LAndExp", "LOrExp", "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-153)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
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

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,    16,  -153,  -153,   196,  -153,   -56,  -153,  -153,
    -153,   199,  -153,   -35,  -153,   221,   203,   151,  -153,   -36,
    -153,   118,  -152,   -10,    97,   -72,  -153,  -153,   -40,  -153,
    -153,  -153,    66,   -22,    -8,    67,    71,  -153,    -9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,   117,     6,    18,    19,    29,    60,    91,     7,
      11,    12,    23,    39,    69,     8,    49,    50,   153,   118,
     119,   120,   121,   122,   154,    41,    72,    42,    43,    44,
     100,   133,    45,    46,   156,   157,   158,   159,    61
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* CompUnit: Decl  */
#line 62 "parse.y"
    {
        printf("Decl -> CompUnit\n");
    
    }
#line 1287 "parse.tab.cpp"
    break;

  case 3: /* CompUnit: FuncDef  */
#line 67 "parse.y"
    {
        printf("FuncDef -> CompUnit\n");
    }
#line 1295 "parse.tab.cpp"
    break;

  case 4: /* CompUnit: CompUnit Decl  */
#line 71 "parse.y"
    {
        printf("CompUnit Decl -> CompUnit\n");
    }
#line 1303 "parse.tab.cpp"
    break;

  case 5: /* CompUnit: CompUnit FuncDef  */
#line 75 "parse.y"
    {
        printf("CompUnit FuncDef -> CompUnit\n");
    }
#line 1311 "parse.tab.cpp"
    break;

  case 6: /* Decl: ConstDecl  */
#line 82 "parse.y"
    {
        printf("ConstDecl -> Decl\n");
    }
#line 1319 "parse.tab.cpp"
    break;

  case 7: /* Decl: VarDecl  */
#line 86 "parse.y"
    {
        printf("VarDecl -> Decl\n");
    }
#line 1327 "parse.tab.cpp"
    break;

  case 8: /* ConstDecl: CONST INT ConstDefList SEMI  */
#line 93 "parse.y"
    {
        printf("const int ConstDefList ; -> ConstDecl\n");
    }
#line 1335 "parse.tab.cpp"
    break;

  case 9: /* ConstDefList: ConstDef  */
#line 101 "parse.y"
    {
        printf("ConstDef -> ConstDefList\n");
    }
#line 1343 "parse.tab.cpp"
    break;

  case 10: /* ConstDefList: ConstDefList COMMA ConstDef  */
#line 105 "parse.y"
    {
        printf("ConstDef , ConstDef -> ConstDefList\n");
    }
#line 1351 "parse.tab.cpp"
    break;

  case 11: /* ConstDef: Ident ASSIGN ConstInitVal  */
#line 118 "parse.y"
    {
        printf("%s = ConstInitVal -> ConstDef\n", (yyvsp[-2].const_string_val));
    }
#line 1359 "parse.tab.cpp"
    break;

  case 12: /* ConstDef: Ident ConstDefGroup ASSIGN ConstInitVal  */
#line 122 "parse.y"
    {
        printf("%s ConstDefGroup = ConstInitVal -> ConstDef\n", (yyvsp[-3].const_string_val));
    }
#line 1367 "parse.tab.cpp"
    break;

  case 13: /* ConstDefGroup: LBRACK ConstExp RBRACK  */
#line 129 "parse.y"
    {
        printf("[ ConstExp ] -> ConstDefGroup\n");
    }
#line 1375 "parse.tab.cpp"
    break;

  case 14: /* ConstDefGroup: ConstDefGroup LBRACK ConstExp RBRACK  */
#line 133 "parse.y"
    {
        printf("ConstDefGroup [ ConstExp ] -> ConstDefGroup\n");
    }
#line 1383 "parse.tab.cpp"
    break;

  case 15: /* ConstInitVal: ConstExp  */
#line 140 "parse.y"
    {
        printf("ConstExp -> ConstInitVal\n");
    
    }
#line 1392 "parse.tab.cpp"
    break;

  case 16: /* ConstInitVal: LBRACE RBRACE  */
#line 145 "parse.y"
    {
        printf("{ } -> ConstInitVal\n");
    
    }
#line 1401 "parse.tab.cpp"
    break;

  case 17: /* ConstInitVal: LBRACE ConstInitValGroup RBRACE  */
#line 150 "parse.y"
    {
        printf("{ ConstInitValGroup } -> ConstInitVal\n");
    }
#line 1409 "parse.tab.cpp"
    break;

  case 18: /* ConstInitValGroup: ConstInitVal  */
#line 157 "parse.y"
    {
        printf("ConstInitVal -> ConstInitValGroup\n");
    }
#line 1417 "parse.tab.cpp"
    break;

  case 19: /* ConstInitValGroup: ConstInitValGroup COMMA ConstInitVal  */
#line 161 "parse.y"
    {
        printf("ConstInitValGroup , ConstInitVal -> ConstInitValGroup\n");
    
    }
#line 1426 "parse.tab.cpp"
    break;

  case 20: /* VarDecl: INT VarDeclGroup SEMI  */
#line 169 "parse.y"
    {
        printf("int VarDeclGroup ; -> VarDecl\n");
    }
#line 1434 "parse.tab.cpp"
    break;

  case 21: /* VarDeclGroup: VarDef  */
#line 176 "parse.y"
    {
        printf("VarDef -> VarDeclGroup\n");
    }
#line 1442 "parse.tab.cpp"
    break;

  case 22: /* VarDeclGroup: VarDeclGroup COMMA VarDef  */
#line 180 "parse.y"
    {
        printf("VarDef , VarDef -> VarDeclGroup\n");
    }
#line 1450 "parse.tab.cpp"
    break;

  case 23: /* VarDef: Ident  */
#line 187 "parse.y"
    {
        printf("%s -> VarDef\n", (yyvsp[0].const_string_val));
    }
#line 1458 "parse.tab.cpp"
    break;

  case 24: /* VarDef: Ident ASSIGN InitVal  */
#line 191 "parse.y"
    {
        printf("%s = InitVal -> VarDef\n", (yyvsp[-2].const_string_val));
    }
#line 1466 "parse.tab.cpp"
    break;

  case 25: /* VarDef: Ident ArrDef  */
#line 195 "parse.y"
    {
        printf("%s ArrDef -> VarDef\n", (yyvsp[-1].const_string_val));
    }
#line 1474 "parse.tab.cpp"
    break;

  case 26: /* VarDef: Ident ArrDef ASSIGN InitVal  */
#line 199 "parse.y"
    {
        printf("%s Arrdef = InitVal -> VarDef\n", (yyvsp[-3].const_string_val));
    }
#line 1482 "parse.tab.cpp"
    break;

  case 27: /* ArrDef: LBRACK ConstExp RBRACK  */
#line 206 "parse.y"
    {
        printf("[ ConstExp ] -> ArrDef\n");
    }
#line 1490 "parse.tab.cpp"
    break;

  case 28: /* ArrDef: ArrDef LBRACK ConstExp RBRACK  */
#line 210 "parse.y"
    {
        printf("ArrDef [ ConstExp ] -> ArrDef\n");
    
    }
#line 1499 "parse.tab.cpp"
    break;

  case 29: /* InitVal: Exp  */
#line 218 "parse.y"
    {
        printf("Exp -> InitVal\n");
    }
#line 1507 "parse.tab.cpp"
    break;

  case 30: /* InitVal: LBRACE RBRACE  */
#line 222 "parse.y"
    {
        printf("{ } -> InitVal\n");
    }
#line 1515 "parse.tab.cpp"
    break;

  case 31: /* InitVal: LBRACE InitValGroup RBRACE  */
#line 226 "parse.y"
    {
        printf("{ InitValGroup } -> InitVal\n");
    }
#line 1523 "parse.tab.cpp"
    break;

  case 32: /* InitValGroup: InitVal  */
#line 233 "parse.y"
    {
        printf("InitVal -> InitValGroup\n");
    }
#line 1531 "parse.tab.cpp"
    break;

  case 33: /* InitValGroup: InitValGroup COMMA InitVal  */
#line 237 "parse.y"
    {
        printf("InitValGroup , InitVal -> InitValGroup\n");
    }
#line 1539 "parse.tab.cpp"
    break;

  case 34: /* FuncDef: VOID Ident LPAREN RPAREN Block  */
#line 244 "parse.y"
    {
        printf("void %s ( ) Block -> FuncDef\n", (yyvsp[-3].const_string_val));
    }
#line 1547 "parse.tab.cpp"
    break;

  case 35: /* FuncDef: INT Ident LPAREN RPAREN Block  */
#line 248 "parse.y"
    {
        printf("int %s ( ) Block -> FuncDef\n", (yyvsp[-3].const_string_val));
    }
#line 1555 "parse.tab.cpp"
    break;

  case 36: /* FuncDef: VOID Ident LPAREN FuncFParams RPAREN Block  */
#line 252 "parse.y"
    {
        printf("void %s ( FuncFParams ) Block -> FuncDef\n", (yyvsp[-4].const_string_val));
    }
#line 1563 "parse.tab.cpp"
    break;

  case 37: /* FuncDef: INT Ident LPAREN FuncFParams RPAREN Block  */
#line 256 "parse.y"
    {
        printf("int %s ( FuncFParams ) Block -> FuncDef\n", (yyvsp[-4].const_string_val));
    }
#line 1571 "parse.tab.cpp"
    break;

  case 38: /* FuncFParams: FuncFParam  */
#line 270 "parse.y"
    {
        printf("FuncFParam -> FuncFParams\n");
    }
#line 1579 "parse.tab.cpp"
    break;

  case 39: /* FuncFParams: FuncFParams COMMA FuncFParam  */
#line 274 "parse.y"
    {
        printf("FuncFParams , FuncFParam -> FuncFParams\n");
    }
#line 1587 "parse.tab.cpp"
    break;

  case 40: /* FuncFParam: INT Ident  */
#line 281 "parse.y"
    {
        printf("int %s -> FuncFParam\n", (yyvsp[0].const_string_val));
    }
#line 1595 "parse.tab.cpp"
    break;

  case 41: /* FuncFParam: INT Ident LBRACK RBRACK  */
#line 285 "parse.y"
    {
        //printf("INT Ident [LBRACK RBRACK {LBRACK Exp RBRACK}] -> FuncFParam\n");
        printf("int %s [ ] -> FuncFParam\n", (yyvsp[-2].const_string_val));
    }
#line 1604 "parse.tab.cpp"
    break;

  case 42: /* FuncFParam: INT Ident LBRACK RBRACK FuncFParamArr  */
#line 290 "parse.y"
    {
        //printf("INT Ident [LBRACK RBRACK {LBRACK Exp RBRACK}] -> FuncFParam\n");
        printf("int %s [ ] FuncFParamArr -> FuncFParam\n", (yyvsp[-3].const_string_val));
    }
#line 1613 "parse.tab.cpp"
    break;

  case 43: /* FuncFParamArr: LBRACK Exp RBRACK  */
#line 298 "parse.y"
    {
        printf("[ Exp ] -> FuncFParamArr\n");
    }
#line 1621 "parse.tab.cpp"
    break;

  case 44: /* FuncFParamArr: FuncFParamArr LBRACK Exp RBRACK  */
#line 302 "parse.y"
    {
        printf("FuncFParamArr [ Exp ] -> FuncFParamArr\n");
    }
#line 1629 "parse.tab.cpp"
    break;

  case 45: /* Block: LBRACE RBRACE  */
#line 309 "parse.y"
    {
        //printf("LBRACE RBRACE -> Block\n");
        printf("{ } -> Block\n");
    }
#line 1638 "parse.tab.cpp"
    break;

  case 46: /* Block: LBRACE BlockGroup RBRACE  */
#line 314 "parse.y"
    {
        //printf("LBRACE {BlockItem} RBRACE -> Block\n");
        printf("{ BlockGroup } -> Block\n");
    }
#line 1647 "parse.tab.cpp"
    break;

  case 47: /* BlockGroup: BlockItem  */
#line 322 "parse.y"
    {
        printf("BlockItem -> BlockGroup\n");
    }
#line 1655 "parse.tab.cpp"
    break;

  case 48: /* BlockGroup: BlockGroup BlockItem  */
#line 326 "parse.y"
    {
        printf("BlockGroup BlockItem -> BlockGroup\n");
    }
#line 1663 "parse.tab.cpp"
    break;

  case 49: /* BlockItem: Decl  */
#line 333 "parse.y"
    {
        printf("Decl -> BlockItem\n");
    }
#line 1671 "parse.tab.cpp"
    break;

  case 50: /* BlockItem: Stmt  */
#line 337 "parse.y"
    {
        printf("Stmt -> BlockItem\n");
    
    }
#line 1680 "parse.tab.cpp"
    break;

  case 51: /* Stmt: LVal ASSIGN Exp SEMI  */
#line 345 "parse.y"
    {
        printf("LVal = Exp ; -> Stmt\n");
    
    }
#line 1689 "parse.tab.cpp"
    break;

  case 52: /* Stmt: SEMI  */
#line 350 "parse.y"
    {
        printf("; -> Stmt\n");
    }
#line 1697 "parse.tab.cpp"
    break;

  case 53: /* Stmt: Exp SEMI  */
#line 354 "parse.y"
    {
        printf("Exp ; -> Stmt\n");
    }
#line 1705 "parse.tab.cpp"
    break;

  case 54: /* Stmt: Block  */
#line 358 "parse.y"
    {
        printf("Block -> Stmt\n");
    }
#line 1713 "parse.tab.cpp"
    break;

  case 55: /* Stmt: IF LPAREN Cond RPAREN Stmt  */
#line 362 "parse.y"
    {
        printf("if ( Cond ) Stmt -> Stmt\n");
    }
#line 1721 "parse.tab.cpp"
    break;

  case 56: /* Stmt: IF LPAREN Cond RPAREN Stmt ELSE Stmt  */
#line 366 "parse.y"
    {
        //printf("IF LPAREN Cond RPAREN Stmt ELSE Stmt -> Stmt\n");
        printf("if ( Cond ) Stmt else Stmt -> Stmt\n");
    }
#line 1730 "parse.tab.cpp"
    break;

  case 57: /* Stmt: WHILE LPAREN Cond RPAREN Stmt  */
#line 371 "parse.y"
    {
        //printf("WHILE LPAREN Cond RPAREN Stmt -> Stmt\n");
        printf("while ( Cond ) Stmt -> Stmt\n");
    }
#line 1739 "parse.tab.cpp"
    break;

  case 58: /* Stmt: BREAK SEMI  */
#line 376 "parse.y"
    {
        //printf("BREAK SEMI -> Stmt\n");
        printf("break ; -> Stmt\n");
    }
#line 1748 "parse.tab.cpp"
    break;

  case 59: /* Stmt: CONTINUE SEMI  */
#line 381 "parse.y"
    {
        //printf("CONTINUE SEMI -> Stmt\n");
        printf("continue ; -> Stmt\n");
    }
#line 1757 "parse.tab.cpp"
    break;

  case 60: /* Stmt: RETURN SEMI  */
#line 386 "parse.y"
    {
        //printf("RETURN SEMI -> Stmt\n");
        printf("return ; -> Stmt\n");
    }
#line 1766 "parse.tab.cpp"
    break;

  case 61: /* Stmt: RETURN Exp SEMI  */
#line 391 "parse.y"
    {
        //printf("RETURN Exp SEMI -> Stmt\n");
        printf("return Exp ; -> Stmt\n");
    }
#line 1775 "parse.tab.cpp"
    break;

  case 62: /* Exp: AddExp  */
#line 399 "parse.y"
    {
        printf("AddExp -> Exp\n");
    }
#line 1783 "parse.tab.cpp"
    break;

  case 63: /* Cond: LOrExp  */
#line 406 "parse.y"
    {
        printf("LOrExp -> Cond\n");
    }
#line 1791 "parse.tab.cpp"
    break;

  case 64: /* LVal: Ident  */
#line 413 "parse.y"
    {
        printf("%s -> LVal\n", (yyvsp[0].const_string_val));
    }
#line 1799 "parse.tab.cpp"
    break;

  case 65: /* LVal: LVal Arr  */
#line 417 "parse.y"
    {
        //printf("Ident {LBRACK Exp RBRACK} -> LVal\n");
        printf("LVal Arr -> LVal\n");
    }
#line 1808 "parse.tab.cpp"
    break;

  case 66: /* Arr: LBRACK Exp RBRACK  */
#line 425 "parse.y"
    {
        printf("[ Exp ] -> Arr\n");
    }
#line 1816 "parse.tab.cpp"
    break;

  case 67: /* Arr: Arr LBRACK Exp RBRACK  */
#line 429 "parse.y"
    {
        printf("Arr [ Exp ] -> Arr\n");
    }
#line 1824 "parse.tab.cpp"
    break;

  case 68: /* PrimaryExp: LPAREN Exp RPAREN  */
#line 436 "parse.y"
    {
        //printf("LPAREN Exp RPAREN -> PrimaryExp\n");
        printf("( Exp ) -> PrimaryExp\n");
    
    }
#line 1834 "parse.tab.cpp"
    break;

  case 69: /* PrimaryExp: LVal  */
#line 442 "parse.y"
    {
        printf("LVal -> PrimaryExp\n");
    }
#line 1842 "parse.tab.cpp"
    break;

  case 70: /* PrimaryExp: IntConst  */
#line 446 "parse.y"
    {
        printf("%d -> PrimaryExp\n", (yyvsp[0].const_int_val));
    }
#line 1850 "parse.tab.cpp"
    break;

  case 71: /* UnaryExp: PrimaryExp  */
#line 457 "parse.y"
    {
        printf("PrimaryExp -> UnaryExp\n");
    }
#line 1858 "parse.tab.cpp"
    break;

  case 72: /* UnaryExp: Ident LPAREN RPAREN  */
#line 461 "parse.y"
    {
        //printf("Ident LPAREN RPAREN -> UnaryExp\n");
        printf("%s ( ) -> UnaryExp\n", (yyvsp[-2].const_string_val));
    }
#line 1867 "parse.tab.cpp"
    break;

  case 73: /* UnaryExp: Ident LPAREN FuncRParams RPAREN  */
#line 466 "parse.y"
    {
        //printf("Ident LPAREN FuncRParams RPAREN -> UnaryExp\n");
        printf("%s ( FuncRParams ) -> UnaryExp\n", (yyvsp[-3].const_string_val));
    }
#line 1876 "parse.tab.cpp"
    break;

  case 74: /* UnaryExp: UnaryOp UnaryExp  */
#line 471 "parse.y"
    {
        printf("UnaryOp UnaryExp -> UnaryExp\n");
    }
#line 1884 "parse.tab.cpp"
    break;

  case 75: /* UnaryOp: ADD  */
#line 478 "parse.y"
    {
        //printf("ADD -> UnaryOp\n");
        printf("+ -> UnaryOp\n");
    }
#line 1893 "parse.tab.cpp"
    break;

  case 76: /* UnaryOp: SUB  */
#line 483 "parse.y"
    {
        //printf("SUB -> UnaryOp\n");
        printf("- -> UnaryOp\n");
    }
#line 1902 "parse.tab.cpp"
    break;

  case 77: /* UnaryOp: NOT  */
#line 488 "parse.y"
    {
        //printf("NOT -> UnaryOp\n");
        printf("! -> UnaryOp\n");
    }
#line 1911 "parse.tab.cpp"
    break;

  case 78: /* FuncRParams: Exp  */
#line 496 "parse.y"
    {
        printf("Exp -> FuncRParams\n");
    }
#line 1919 "parse.tab.cpp"
    break;

  case 79: /* FuncRParams: Exp FuncRParamsGroup  */
#line 500 "parse.y"
    {
        //printf("Exp {COMMA Exp} -> FuncRParams\n");
        printf("Exp FuncRParamsGroup -> FuncRParams\n");
    }
#line 1928 "parse.tab.cpp"
    break;

  case 80: /* FuncRParamsGroup: COMMA Exp  */
#line 508 "parse.y"
    {
        printf(", Exp -> FuncRParamsGroup\n");
    }
#line 1936 "parse.tab.cpp"
    break;

  case 81: /* FuncRParamsGroup: FuncRParamsGroup COMMA Exp  */
#line 512 "parse.y"
    {
        printf("FuncRParamsGroup , Exp -> FuncRParamsGroup\n");
    }
#line 1944 "parse.tab.cpp"
    break;

  case 82: /* MulExp: UnaryExp  */
#line 519 "parse.y"
    {
        printf("UnaryExp -> MulExp\n");
    
    }
#line 1953 "parse.tab.cpp"
    break;

  case 83: /* MulExp: MulExp MUL UnaryExp  */
#line 524 "parse.y"
    {
        //printf("MulExp MUL UnaryExp -> MulExp\n");
        printf("MulExp * UnaryExp -> MulExp\n");
    }
#line 1962 "parse.tab.cpp"
    break;

  case 84: /* MulExp: MulExp DIV UnaryExp  */
#line 529 "parse.y"
    {
        //printf("MulExp DIV UnaryExp -> MulExp\n");
        printf("MulExp / UnaryExp -> MulExp\n");
    }
#line 1971 "parse.tab.cpp"
    break;

  case 85: /* MulExp: MulExp MOD UnaryExp  */
#line 534 "parse.y"
    {
        //printf("MulExp MOD UnaryExp -> MulExp\n");
        printf("MulExp %% UnaryExp -> MulExp\n");
    }
#line 1980 "parse.tab.cpp"
    break;

  case 86: /* AddExp: MulExp  */
#line 542 "parse.y"
    {
        printf("MulExp -> AddExp\n");
    
    }
#line 1989 "parse.tab.cpp"
    break;

  case 87: /* AddExp: AddExp ADD MulExp  */
#line 547 "parse.y"
    {
        //printf("AddExp ADD MulExp -> AddExp\n");
        printf("AddExp + MulExp -> AddExp\n");
    }
#line 1998 "parse.tab.cpp"
    break;

  case 88: /* AddExp: AddExp SUB MulExp  */
#line 552 "parse.y"
    {
        //printf("AddExp SUB MulExp -> AddExp\n");
        printf("AddExp - MulExp -> AddExp\n");
    }
#line 2007 "parse.tab.cpp"
    break;

  case 89: /* RelExp: AddExp  */
#line 560 "parse.y"
    {
        printf("AddExp -> RelExp\n");
    }
#line 2015 "parse.tab.cpp"
    break;

  case 90: /* RelExp: RelExp LT AddExp  */
#line 564 "parse.y"
    {
        //printf("RelExp LT AddExp -> RelExp\n");
        printf("RelExp < AddExp -> RelExp\n");
    }
#line 2024 "parse.tab.cpp"
    break;

  case 91: /* RelExp: RelExp LE AddExp  */
#line 569 "parse.y"
    {
        //printf("RelExp LE AddExp -> RelExp\n");
        printf("RelExp <= AddExp -> RelExp\n");
    }
#line 2033 "parse.tab.cpp"
    break;

  case 92: /* RelExp: RelExp GT AddExp  */
#line 574 "parse.y"
    {
        //printf("RelExp GT AddExp -> RelExp\n");
        printf("RelExp > AddExp -> RelExp\n");
    }
#line 2042 "parse.tab.cpp"
    break;

  case 93: /* RelExp: RelExp GE AddExp  */
#line 579 "parse.y"
    {
        //printf("RelExp GE AddExp -> RelExp\n");
        printf("RelExp >= AddExp -> RelExp\n");
    }
#line 2051 "parse.tab.cpp"
    break;

  case 94: /* EqExp: RelExp  */
#line 587 "parse.y"
    {
        printf("RelExp -> EqExp\n");
    }
#line 2059 "parse.tab.cpp"
    break;

  case 95: /* EqExp: EqExp EQ RelExp  */
#line 591 "parse.y"
    {
        //printf("EqExp EQ RelExp -> EqExp\n");
        printf("EqExp == RelExp -> EqExp\n");
    }
#line 2068 "parse.tab.cpp"
    break;

  case 96: /* EqExp: EqExp NE RelExp  */
#line 596 "parse.y"
    {
        //printf("EqExp NE RelExp -> EqExp\n");
        printf("EqExp != RelExp -> EqExp\n");
    }
#line 2077 "parse.tab.cpp"
    break;

  case 97: /* LAndExp: EqExp  */
#line 604 "parse.y"
    {
        printf("EqExp -> LAndExp\n");
    }
#line 2085 "parse.tab.cpp"
    break;

  case 98: /* LAndExp: LAndExp AND EqExp  */
#line 608 "parse.y"
    {
        //printf("LAndExp AND EqExp -> LAndExp\n");
        printf("LAndExp && EqExp -> LAndExp\n");
    }
#line 2094 "parse.tab.cpp"
    break;

  case 99: /* LOrExp: LAndExp  */
#line 616 "parse.y"
    {
        printf("LAndExp -> LOrExp\n");
    }
#line 2102 "parse.tab.cpp"
    break;

  case 100: /* LOrExp: LOrExp OR LAndExp  */
#line 620 "parse.y"
    {
        //printf("LOrExp OR LAndExp -> LOrExp\n");
        printf("LOrExp || LAndExp -> LOrExp\n");
    }
#line 2111 "parse.tab.cpp"
    break;

  case 101: /* ConstExp: AddExp  */
#line 628 "parse.y"
    {
        printf("AddExp -> ConstExp\n");
    }
#line 2119 "parse.tab.cpp"
    break;


#line 2123 "parse.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 633 "parse.y"


void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int main() {
    yyparse();
    return 0;
}
