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
    #include "assemble.hpp"
    #include "AST.hpp"
    #include "symbol_table.hpp"
    #include "log.hpp"
    #include <fstream>
    #include <iostream>
    #include <variant>
    #include <typeinfo>
    #include "const_eval_helper.hpp"
    // #include "parse.tab.hpp"

    int yylex(void);
    extern int yyparse(void);
    void yyerror(const char *s);
    
    char message[1024];

    FILE* detail_fp;

    extern int lines;
    extern int chars;
    
    Log logger = Log("./logfile.json");

    extern BaseAST* root;

    int offset;

    extern Assemble rodata, data, bss, text;

    // SymbolTable *symbol_table = new SymbolTable();
    // Assemble assemble = Assemble();

#line 107 "parse.tab.cpp"

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
  YYSYMBOL_INCLUDE = 3,                    /* INCLUDE  */
  YYSYMBOL_CONST = 4,                      /* CONST  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_BREAK = 10,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 11,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_ASSIGN = 13,                    /* ASSIGN  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_LT = 17,                        /* LT  */
  YYSYMBOL_LE = 18,                        /* LE  */
  YYSYMBOL_GT = 19,                        /* GT  */
  YYSYMBOL_GE = 20,                        /* GE  */
  YYSYMBOL_NE = 21,                        /* NE  */
  YYSYMBOL_ADD = 22,                       /* ADD  */
  YYSYMBOL_SUB = 23,                       /* SUB  */
  YYSYMBOL_MUL = 24,                       /* MUL  */
  YYSYMBOL_DIV = 25,                       /* DIV  */
  YYSYMBOL_MOD = 26,                       /* MOD  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_LPAREN = 28,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 29,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 30,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 31,                    /* RBRACE  */
  YYSYMBOL_LBRACK = 32,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 33,                    /* RBRACK  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_SEMI = 35,                      /* SEMI  */
  YYSYMBOL_HASH = 36,                      /* HASH  */
  YYSYMBOL_Ident = 37,                     /* Ident  */
  YYSYMBOL_IntConst = 38,                  /* IntConst  */
  YYSYMBOL_HeaderFile = 39,                /* HeaderFile  */
  YYSYMBOL_String = 40,                    /* String  */
  YYSYMBOL_IFX = 41,                       /* IFX  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_Start = 43,                     /* Start  */
  YYSYMBOL_CompUnit = 44,                  /* CompUnit  */
  YYSYMBOL_ExternalDef = 45,               /* ExternalDef  */
  YYSYMBOL_Decl = 46,                      /* Decl  */
  YYSYMBOL_ConstDecl = 47,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 48,              /* ConstDefList  */
  YYSYMBOL_ConstDef = 49,                  /* ConstDef  */
  YYSYMBOL_ConstArrDef = 50,               /* ConstArrDef  */
  YYSYMBOL_ArrDef = 51,                    /* ArrDef  */
  YYSYMBOL_ConstInitVal = 52,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValList = 53,          /* ConstInitValList  */
  YYSYMBOL_VarDecl = 54,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 55,                /* VarDefList  */
  YYSYMBOL_VarDef = 56,                    /* VarDef  */
  YYSYMBOL_InitVal = 57,                   /* InitVal  */
  YYSYMBOL_InitValList = 58,               /* InitValList  */
  YYSYMBOL_FuncDef = 59,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 60,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 61,                /* FuncFParam  */
  YYSYMBOL_Block = 62,                     /* Block  */
  YYSYMBOL_BlockGroup = 63,                /* BlockGroup  */
  YYSYMBOL_BlockItem = 64,                 /* BlockItem  */
  YYSYMBOL_Stmt = 65,                      /* Stmt  */
  YYSYMBOL_Exp = 66,                       /* Exp  */
  YYSYMBOL_ConstExp = 67,                  /* ConstExp  */
  YYSYMBOL_Cond = 68,                      /* Cond  */
  YYSYMBOL_LVal = 69,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 70,                /* PrimaryExp  */
  YYSYMBOL_UnaryExp = 71,                  /* UnaryExp  */
  YYSYMBOL_UnaryOp = 72,                   /* UnaryOp  */
  YYSYMBOL_FuncRParams = 73,               /* FuncRParams  */
  YYSYMBOL_MulExp = 74,                    /* MulExp  */
  YYSYMBOL_AddExp = 75,                    /* AddExp  */
  YYSYMBOL_RelExp = 76,                    /* RelExp  */
  YYSYMBOL_EqExp = 77,                     /* EqExp  */
  YYSYMBOL_LAndExp = 78,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 79                     /* LOrExp  */
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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   279

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   194,   194,   204,   211,   217,   223,   229,   235,   241,
     250,   258,   264,   273,   283,   289,   298,   305,   316,   322,
     331,   337,   346,   352,   357,   366,   372,   381,   390,   396,
     405,   411,   418,   425,   436,   442,   447,   456,   462,   471,
     479,   487,   496,   508,   514,   523,   529,   536,   548,   553,
     562,   568,   577,   583,   592,   600,   605,   612,   619,   628,
     637,   645,   650,   655,   662,   672,   680,   688,   696,   702,
     712,   717,   725,   735,   740,   749,   760,   771,   777,   783,
     792,   798,   804,   813,   818,   827,   836,   848,   853,   862,
     874,   879,   888,   897,   906,   918,   923,   932,   944,   949,
     961,   966
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
  "\"end of file\"", "error", "\"invalid token\"", "INCLUDE", "CONST",
  "INT", "VOID", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "RETURN",
  "ASSIGN", "AND", "OR", "EQ", "LT", "LE", "GT", "GE", "NE", "ADD", "SUB",
  "MUL", "DIV", "MOD", "NOT", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "LBRACK", "RBRACK", "COMMA", "SEMI", "HASH", "Ident", "IntConst",
  "HeaderFile", "String", "IFX", "$accept", "Start", "CompUnit",
  "ExternalDef", "Decl", "ConstDecl", "ConstDefList", "ConstDef",
  "ConstArrDef", "ArrDef", "ConstInitVal", "ConstInitValList", "VarDecl",
  "VarDefList", "VarDef", "InitVal", "InitValList", "FuncDef",
  "FuncFParams", "FuncFParam", "Block", "BlockGroup", "BlockItem", "Stmt",
  "Exp", "ConstExp", "Cond", "LVal", "PrimaryExp", "UnaryExp", "UnaryOp",
  "FuncRParams", "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp",
  "LOrExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-116)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,    21,    26,    30,    72,    55,     8,  -116,  -116,  -116,
    -116,  -116,    40,    46,    69,  -116,    68,    76,  -116,  -116,
    -116,  -116,    49,   111,  -116,   200,    18,   241,    51,    42,
    -116,    47,  -116,   212,   241,    52,    40,  -116,  -116,  -116,
    -116,   241,   176,    -3,  -116,  -116,  -116,  -116,  -116,  -116,
     241,   102,   125,    82,   100,   -14,  -116,   107,   200,   241,
      53,  -116,   100,    57,   188,  -116,  -116,   125,   118,   212,
     241,  -116,   129,  -116,  -116,   -15,   149,   131,  -116,   241,
     241,   241,   241,   241,   133,    23,  -116,   100,   156,  -116,
    -116,   135,  -116,   100,  -116,  -116,    78,  -116,  -116,   140,
    -116,  -116,   200,  -116,   130,   141,   137,  -116,  -116,  -116,
     102,   102,   148,    42,   146,   154,   153,   155,   224,  -116,
    -116,  -116,  -116,    83,  -116,  -116,   158,   170,  -116,  -116,
    -116,  -116,  -116,   212,  -116,  -116,   157,   157,  -116,   159,
     241,   241,  -116,  -116,  -116,   161,  -116,  -116,  -116,   241,
    -116,  -116,  -116,   131,   163,   125,   105,    81,   186,   187,
     172,  -116,   173,   132,   241,   241,   241,   241,   241,   241,
     241,   241,   132,  -116,   197,   125,   125,   125,   125,   105,
     105,    81,   186,  -116,   132,  -116
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     2,     6,     4,    11,
      12,     5,     0,    30,     0,    28,     0,     0,     1,     9,
       7,     8,     0,     0,    14,     0,     0,     0,    32,     0,
      27,     0,    10,     0,     0,     0,     0,    13,    77,    78,
      79,     0,     0,    68,    72,    31,    34,    71,    73,    83,
       0,    87,    65,     0,     0,     0,    43,     0,     0,     0,
      30,    29,     0,     0,     0,    16,    22,    66,     0,     0,
       0,    15,     0,    35,    37,     0,     0,    69,    76,     0,
       0,     0,     0,     0,    45,     0,    40,     0,     0,    20,
      33,     0,    39,     0,    23,    25,     0,    18,    17,     0,
      70,    36,     0,    74,     0,    80,     0,    84,    85,    86,
      88,    89,     0,     0,     0,     0,     0,     0,     0,    48,
      55,    52,    57,     0,    50,    53,     0,    71,    42,    44,
      21,    41,    24,     0,    19,    38,     0,     0,    75,    46,
       0,     0,    61,    62,    63,     0,    49,    51,    56,     0,
      26,    82,    81,    47,     0,    90,    95,    98,   100,    67,
       0,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    58,    91,    92,    93,    94,    96,
      97,    99,   101,    60,     0,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,   203,    11,  -116,  -116,   181,  -116,   -40,
     -60,  -116,  -116,  -116,   183,   -34,  -116,   214,   190,   136,
     -44,  -116,   106,  -115,   -20,   -28,    90,   -83,  -116,    -9,
    -116,    13,    70,   -33,   -12,    62,    65,  -116
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,   121,     9,    23,    24,    35,    28,
      65,    96,    10,    14,    15,    45,    75,    11,    55,    56,
     122,   123,   124,   125,   126,    66,   154,    47,    48,    49,
      50,   106,    51,    52,   156,   157,   158,   159
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      67,    67,   127,    77,    95,    46,    68,    57,    74,    98,
      86,     8,     1,     2,     3,    87,   101,    20,    92,   102,
      88,    72,    46,    53,    90,    76,    12,     1,   113,    27,
     114,    67,   115,   116,   117,   118,    67,    67,    46,    91,
     127,    78,    99,   128,     4,    38,    39,    54,   174,   131,
      40,    41,    53,    85,   119,    18,   105,   183,   120,    25,
      43,    44,    33,    13,    58,    69,    25,    16,   135,   185,
     107,   108,   109,   150,    26,    17,    62,    22,    27,    60,
     127,    34,    46,    59,    70,    27,    93,     1,   113,   127,
     114,    88,   115,   116,   117,   118,    31,   168,   145,   153,
      67,   127,   169,    29,    30,    38,    39,   155,   155,   132,
      40,    41,   133,    85,   146,    32,   105,   105,   120,    84,
      43,    44,   164,   165,   166,   167,    79,    80,    81,   162,
      85,   175,   176,   177,   178,   155,   155,   155,   155,   114,
      89,   115,   116,   117,   118,    36,    37,    82,    83,   151,
     152,    97,   110,   111,    38,    39,   179,   180,   100,    40,
      41,    53,    85,    59,   136,   112,   138,   120,   130,    43,
      44,    38,    39,   134,   140,   137,    40,    41,   103,    38,
      39,   139,   141,   149,    40,    41,    43,    44,   142,   104,
     143,    27,   163,   148,    43,    44,   161,   104,    38,    39,
     170,   172,   171,    40,    41,   184,    42,    73,   173,    19,
      38,    39,    61,    43,    44,    40,    41,    71,    64,    94,
      21,    63,    38,    39,   129,    43,    44,    40,    41,   147,
      42,   160,   181,     0,    38,    39,   182,    43,    44,    40,
      41,     0,    64,     0,     0,     0,    38,    39,     0,    43,
      44,    40,    41,     0,     0,     0,     0,     0,     0,   144,
       0,    43,    44,    38,    39,     0,     0,     0,    40,    41,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    44
};

static const yytype_int16 yycheck[] =
{
      33,    34,    85,    43,    64,    25,    34,    27,    42,    69,
      54,     0,     4,     5,     6,    29,    31,     6,    62,    34,
      34,    41,    42,     5,    58,    28,     5,     4,     5,    32,
       7,    64,     9,    10,    11,    12,    69,    70,    58,    59,
     123,    50,    70,    87,    36,    22,    23,    29,   163,    93,
      27,    28,     5,    30,    31,     0,    76,   172,    35,    13,
      37,    38,    13,    37,    13,    13,    13,    37,   102,   184,
      79,    80,    81,   133,    28,     3,    29,    37,    32,    37,
     163,    32,   102,    32,    32,    32,    29,     4,     5,   172,
       7,    34,     9,    10,    11,    12,    28,    16,   118,   139,
     133,   184,    21,    34,    35,    22,    23,   140,   141,    31,
      27,    28,    34,    30,    31,    39,   136,   137,    35,    37,
      37,    38,    17,    18,    19,    20,    24,    25,    26,   149,
      30,   164,   165,   166,   167,   168,   169,   170,   171,     7,
      33,     9,    10,    11,    12,    34,    35,    22,    23,   136,
     137,    33,    82,    83,    22,    23,   168,   169,    29,    27,
      28,     5,    30,    32,    34,    32,    29,    35,    33,    37,
      38,    22,    23,    33,    28,    34,    27,    28,    29,    22,
      23,    33,    28,    13,    27,    28,    37,    38,    35,    40,
      35,    32,    29,    35,    37,    38,    35,    40,    22,    23,
      14,    29,    15,    27,    28,     8,    30,    31,    35,     6,
      22,    23,    29,    37,    38,    27,    28,    36,    30,    31,
       6,    31,    22,    23,    88,    37,    38,    27,    28,   123,
      30,   141,   170,    -1,    22,    23,   171,    37,    38,    27,
      28,    -1,    30,    -1,    -1,    -1,    22,    23,    -1,    37,
      38,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    37,    38,    22,    23,    -1,    -1,    -1,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,    36,    43,    44,    45,    46,    47,
      54,    59,     5,    37,    55,    56,    37,     3,     0,    45,
      46,    59,    37,    48,    49,    13,    28,    32,    51,    34,
      35,    28,    39,    13,    32,    50,    34,    35,    22,    23,
      27,    28,    30,    37,    38,    57,    66,    69,    70,    71,
      72,    74,    75,     5,    29,    60,    61,    66,    13,    32,
      37,    56,    29,    60,    30,    52,    67,    75,    67,    13,
      32,    49,    66,    31,    57,    58,    28,    51,    71,    24,
      25,    26,    22,    23,    37,    30,    62,    29,    34,    33,
      57,    66,    62,    29,    31,    52,    53,    33,    52,    67,
      29,    31,    34,    29,    40,    66,    73,    71,    71,    71,
      74,    74,    32,     5,     7,     9,    10,    11,    12,    31,
      35,    46,    62,    63,    64,    65,    66,    69,    62,    61,
      33,    62,    31,    34,    33,    57,    34,    34,    29,    33,
      28,    28,    35,    35,    35,    66,    31,    64,    35,    13,
      52,    73,    73,    51,    68,    75,    76,    77,    78,    79,
      68,    35,    66,    29,    17,    18,    19,    20,    16,    21,
      14,    15,    29,    35,    65,    75,    75,    75,    75,    76,
      76,    77,    78,    65,     8,    65
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    44,    44,    44,    44,
      45,    46,    46,    47,    48,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    52,    53,    53,    54,    55,    55,
      56,    56,    56,    56,    57,    57,    57,    58,    58,    59,
      59,    59,    59,    60,    60,    61,    61,    61,    62,    62,
      63,    63,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    66,    67,    68,    69,    69,
      70,    70,    70,    71,    71,    71,    71,    72,    72,    72,
      73,    73,    73,    74,    74,    74,    74,    75,    75,    75,
      76,    76,    76,    76,    76,    77,    77,    77,    78,    78,
      79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     1,     2,     2,     2,
       3,     1,     1,     4,     1,     3,     3,     4,     3,     4,
       3,     4,     1,     2,     3,     1,     3,     3,     1,     3,
       1,     3,     2,     4,     1,     2,     3,     1,     3,     5,
       5,     6,     6,     1,     3,     2,     4,     5,     2,     3,
       1,     2,     1,     1,     4,     1,     2,     1,     5,     7,
       5,     2,     2,     2,     3,     1,     1,     1,     1,     2,
       3,     1,     1,     1,     3,     4,     2,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3
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
  case 2: /* Start: CompUnit  */
#line 195 "parse.y"
    {
        fprintf(detail_fp, "CompUnit -> Start\n");
        root = (yyvsp[0].compunit_type);
        // const std::type_info& objType = typeid($1);
        // 使用type_info的name()成员函数获取类型名
        // std::cout << "Type of obj: " << objType.name() << std::endl;
        // fprintf(detail_fp, "root type: %s\n", std::holds_alternative<CompUnitAST*>(root) ? "CompUnit" : "Other");
    }
#line 1325 "parse.tab.cpp"
    break;

  case 3: /* Start: %empty  */
#line 204 "parse.y"
    {
        fprintf(detail_fp, "empty -> Start\n");
        root = new CompUnitAST();
    }
#line 1334 "parse.tab.cpp"
    break;

  case 4: /* CompUnit: Decl  */
#line 212 "parse.y"
    {
        fprintf(detail_fp, "Decl -> CompUnit\n");
        (yyval.compunit_type) = new CompUnitAST();
        (yyval.compunit_type)->decls.push_back((yyvsp[0].decl_type));
    }
#line 1344 "parse.tab.cpp"
    break;

  case 5: /* CompUnit: FuncDef  */
#line 218 "parse.y"
    {
        fprintf(detail_fp, "FuncDef -> CompUnit\n");
        (yyval.compunit_type) = new CompUnitAST();
        (yyval.compunit_type)->func_defs.emplace_back((yyvsp[0].funcdef_type));
    }
#line 1354 "parse.tab.cpp"
    break;

  case 6: /* CompUnit: ExternalDef  */
#line 224 "parse.y"
    {
        fprintf(detail_fp, "ExternalDef -> CompUnit\n");
        (yyval.compunit_type) = new CompUnitAST();
        (yyval.compunit_type)->external_defs.emplace_back((yyvsp[0].externaldef_type));
    }
#line 1364 "parse.tab.cpp"
    break;

  case 7: /* CompUnit: CompUnit Decl  */
#line 230 "parse.y"
    {
        fprintf(detail_fp, "CompUnit Decl -> CompUnit\n");
        (yyvsp[-1].compunit_type)->decls.emplace_back((yyvsp[0].decl_type));
        (yyval.compunit_type) = (yyvsp[-1].compunit_type);
    }
#line 1374 "parse.tab.cpp"
    break;

  case 8: /* CompUnit: CompUnit FuncDef  */
#line 236 "parse.y"
    {
        fprintf(detail_fp, "CompUnit FuncDef -> CompUnit\n");
        (yyvsp[-1].compunit_type)->func_defs.emplace_back((yyvsp[0].funcdef_type));
        (yyval.compunit_type) = (yyvsp[-1].compunit_type);
    }
#line 1384 "parse.tab.cpp"
    break;

  case 9: /* CompUnit: CompUnit ExternalDef  */
#line 242 "parse.y"
    {
        fprintf(detail_fp, "CompUnit ExternalDef -> CompUnit\n");
        (yyvsp[-1].compunit_type)->external_defs.emplace_back((yyvsp[0].externaldef_type));
        (yyval.compunit_type) = (yyvsp[-1].compunit_type);
    }
#line 1394 "parse.tab.cpp"
    break;

  case 10: /* ExternalDef: HASH INCLUDE HeaderFile  */
#line 251 "parse.y"
    {
        fprintf(detail_fp, "# include %s -> ExternalDef\n", (yyvsp[0].const_string_val));
        (yyval.externaldef_type) = new ExternalDefAST((yyvsp[0].const_string_val));
    }
#line 1403 "parse.tab.cpp"
    break;

  case 11: /* Decl: ConstDecl  */
#line 259 "parse.y"
    {
        fprintf(detail_fp, "ConstDecl -> Decl\n");
        (yyval.decl_type) = new DeclAST();
        (yyval.decl_type)->decl = (yyvsp[0].constdecl_type);
    }
#line 1413 "parse.tab.cpp"
    break;

  case 12: /* Decl: VarDecl  */
#line 265 "parse.y"
    {
        fprintf(detail_fp, "VarDecl -> Decl\n");
        (yyval.decl_type) = new DeclAST();
        (yyval.decl_type)->decl = (yyvsp[0].vardecl_type);
    }
#line 1423 "parse.tab.cpp"
    break;

  case 13: /* ConstDecl: CONST INT ConstDefList SEMI  */
#line 274 "parse.y"
    {
        fprintf(detail_fp, "const int ConstDefList ; -> ConstDecl\n");
        (yyval.constdecl_type) = new ConstDeclAST();
        (yyval.constdecl_type)->const_defs = (yyvsp[-1].constdeflist_type)->const_defs;
    }
#line 1433 "parse.tab.cpp"
    break;

  case 14: /* ConstDefList: ConstDef  */
#line 284 "parse.y"
    {
        fprintf(detail_fp, "ConstDef -> ConstDefList\n");
        (yyval.constdeflist_type) = new ConstDefListAST();
        (yyval.constdeflist_type)->const_defs.emplace_back((yyvsp[0].constdef_type));
    }
#line 1443 "parse.tab.cpp"
    break;

  case 15: /* ConstDefList: ConstDefList COMMA ConstDef  */
#line 290 "parse.y"
    {
        fprintf(detail_fp, "ConstDef , ConstDef -> ConstDefList\n");
        (yyvsp[-2].constdeflist_type)->const_defs.emplace_back((yyvsp[0].constdef_type));
        (yyval.constdeflist_type) = (yyvsp[-2].constdeflist_type);
    }
#line 1453 "parse.tab.cpp"
    break;

  case 16: /* ConstDef: Ident ASSIGN ConstInitVal  */
#line 299 "parse.y"
    {
        fprintf(detail_fp, "%s = ConstInitVal -> ConstDef\n", (yyvsp[-2].const_string_val));
        (yyval.constdef_type) = new ConstDefAST();
        (yyval.constdef_type)->ident = (yyvsp[-2].const_string_val);
        (yyval.constdef_type)->const_init_val = (yyvsp[0].constinitval_type);
    }
#line 1464 "parse.tab.cpp"
    break;

  case 17: /* ConstDef: Ident ConstArrDef ASSIGN ConstInitVal  */
#line 306 "parse.y"
    {
        fprintf(detail_fp, "%s ConstArrDef = ConstInitVal -> ConstDef\n", (yyvsp[-3].const_string_val));
        (yyval.constdef_type) = new ConstDefAST();
        (yyval.constdef_type)->ident = (yyvsp[-3].const_string_val);
        (yyval.constdef_type)->dim = (yyvsp[-2].constarrdef_type)->dim;
        (yyval.constdef_type)->const_init_val = (yyvsp[0].constinitval_type);
    }
#line 1476 "parse.tab.cpp"
    break;

  case 18: /* ConstArrDef: LBRACK ConstExp RBRACK  */
#line 317 "parse.y"
    {
        fprintf(detail_fp, "[ ConstExp ] -> ConstArrDef\n");
        (yyval.constarrdef_type) = new ConstArrDefAST();
        (yyval.constarrdef_type)->dim.emplace_back((yyvsp[-1].exp_type));
    }
#line 1486 "parse.tab.cpp"
    break;

  case 19: /* ConstArrDef: ConstArrDef LBRACK ConstExp RBRACK  */
#line 323 "parse.y"
    {
        fprintf(detail_fp, "ConstArrDef [ ConstExp ] -> ConstArrDef\n");
        (yyvsp[-3].constarrdef_type)->dim.emplace_back((yyvsp[-1].exp_type));
        (yyval.constarrdef_type) = (yyvsp[-3].constarrdef_type);
    }
#line 1496 "parse.tab.cpp"
    break;

  case 20: /* ArrDef: LBRACK Exp RBRACK  */
#line 332 "parse.y"
    {
        fprintf(detail_fp, "[ Exp ] -> ArrDef\n");
        (yyval.arrdef_type) = new ArrDefAST();
        (yyval.arrdef_type)->dim.emplace_back((yyvsp[-1].exp_type));
    }
#line 1506 "parse.tab.cpp"
    break;

  case 21: /* ArrDef: ArrDef LBRACK Exp RBRACK  */
#line 338 "parse.y"
    {
        fprintf(detail_fp, "ArrDef [ Exp ] -> ArrDef\n");
        (yyvsp[-3].arrdef_type)->dim.emplace_back((yyvsp[-1].exp_type));
        (yyval.arrdef_type) = (yyvsp[-3].arrdef_type);
    }
#line 1516 "parse.tab.cpp"
    break;

  case 22: /* ConstInitVal: ConstExp  */
#line 347 "parse.y"
    {
        fprintf(detail_fp, "ConstExp -> ConstInitVal\n");
        (yyval.constinitval_type) = new ConstInitValAST();
        (yyval.constinitval_type)->value = (yyvsp[0].exp_type);
    }
#line 1526 "parse.tab.cpp"
    break;

  case 23: /* ConstInitVal: LBRACE RBRACE  */
#line 353 "parse.y"
    {
        fprintf(detail_fp, "{ } -> ConstInitVal\n");
        (yyval.constinitval_type) = new ConstInitValAST();
    }
#line 1535 "parse.tab.cpp"
    break;

  case 24: /* ConstInitVal: LBRACE ConstInitValList RBRACE  */
#line 358 "parse.y"
    {
        fprintf(detail_fp, "{ ConstInitValList } -> ConstInitVal\n");
        (yyval.constinitval_type) = new ConstInitValAST();
        (yyval.constinitval_type)->value = (yyvsp[-1].constinitvallist_type);
    }
#line 1545 "parse.tab.cpp"
    break;

  case 25: /* ConstInitValList: ConstInitVal  */
#line 367 "parse.y"
    {
        fprintf(detail_fp, "ConstInitVal -> ConstInitValList\n");
        (yyval.constinitvallist_type) = new ConstInitValListAST();
        (yyval.constinitvallist_type)->const_init_vals.emplace_back((yyvsp[0].constinitval_type));
    }
#line 1555 "parse.tab.cpp"
    break;

  case 26: /* ConstInitValList: ConstInitValList COMMA ConstInitVal  */
#line 373 "parse.y"
    {
        fprintf(detail_fp, "ConstInitValList , ConstInitVal -> ConstInitValList\n");
        (yyvsp[-2].constinitvallist_type)->const_init_vals.emplace_back((yyvsp[0].constinitval_type));
        (yyval.constinitvallist_type) = (yyvsp[-2].constinitvallist_type);
    }
#line 1565 "parse.tab.cpp"
    break;

  case 27: /* VarDecl: INT VarDefList SEMI  */
#line 382 "parse.y"
    {
        fprintf(detail_fp, "int VarDeclList ; -> VarDecl\n");
        (yyval.vardecl_type) = new VarDeclAST();
        (yyval.vardecl_type)->var_defs = (yyvsp[-1].vardeflist_type)->var_defs;
    }
#line 1575 "parse.tab.cpp"
    break;

  case 28: /* VarDefList: VarDef  */
#line 391 "parse.y"
    {
        fprintf(detail_fp, "VarDef -> VarDefList\n");
        (yyval.vardeflist_type) = new VarDefListAST();
        (yyval.vardeflist_type)->var_defs.emplace_back((yyvsp[0].vardef_type));
    }
#line 1585 "parse.tab.cpp"
    break;

  case 29: /* VarDefList: VarDefList COMMA VarDef  */
#line 397 "parse.y"
    {
        fprintf(detail_fp, "VarDef , VarDef -> VarDefList\n");
        (yyvsp[-2].vardeflist_type)->var_defs.emplace_back((yyvsp[0].vardef_type));
        (yyval.vardeflist_type) = (yyvsp[-2].vardeflist_type);
    }
#line 1595 "parse.tab.cpp"
    break;

  case 30: /* VarDef: Ident  */
#line 406 "parse.y"
    {
        fprintf(detail_fp, "%s -> VarDef\n", (yyvsp[0].const_string_val));
        (yyval.vardef_type) = new VarDefAST();
        (yyval.vardef_type)->ident = (yyvsp[0].const_string_val);
    }
#line 1605 "parse.tab.cpp"
    break;

  case 31: /* VarDef: Ident ASSIGN InitVal  */
#line 412 "parse.y"
    {
        fprintf(detail_fp, "%s = InitVal -> VarDef\n", (yyvsp[-2].const_string_val));
        (yyval.vardef_type) = new VarDefAST();
        (yyval.vardef_type)->ident = (yyvsp[-2].const_string_val);
        (yyval.vardef_type)->init_val = (yyvsp[0].initval_type);
    }
#line 1616 "parse.tab.cpp"
    break;

  case 32: /* VarDef: Ident ArrDef  */
#line 419 "parse.y"
    {
        fprintf(detail_fp, "%s ArrDef -> VarDef\n", (yyvsp[-1].const_string_val));
        (yyval.vardef_type) = new VarDefAST();
        (yyval.vardef_type)->ident = (yyvsp[-1].const_string_val);
        (yyval.vardef_type)->dim = (yyvsp[0].arrdef_type)->dim;
    }
#line 1627 "parse.tab.cpp"
    break;

  case 33: /* VarDef: Ident ArrDef ASSIGN InitVal  */
#line 426 "parse.y"
    {
        fprintf(detail_fp, "%s Arrdef = InitVal -> VarDef\n", (yyvsp[-3].const_string_val));
        (yyval.vardef_type) = new VarDefAST();
        (yyval.vardef_type)->ident = (yyvsp[-3].const_string_val);
        (yyval.vardef_type)->dim = (yyvsp[-2].arrdef_type)->dim;
        (yyval.vardef_type)->init_val = (yyvsp[0].initval_type);
    }
#line 1639 "parse.tab.cpp"
    break;

  case 34: /* InitVal: Exp  */
#line 437 "parse.y"
    {
        fprintf(detail_fp, "Exp -> InitVal\n");
        (yyval.initval_type) = new InitValAST();
        (yyval.initval_type)->value = (yyvsp[0].exp_type);
    }
#line 1649 "parse.tab.cpp"
    break;

  case 35: /* InitVal: LBRACE RBRACE  */
#line 443 "parse.y"
    {
        fprintf(detail_fp, "{ } -> InitVal\n");
        (yyval.initval_type) = new InitValAST();
    }
#line 1658 "parse.tab.cpp"
    break;

  case 36: /* InitVal: LBRACE InitValList RBRACE  */
#line 448 "parse.y"
    {
        fprintf(detail_fp, "{ InitValList } -> InitVal\n");
        (yyval.initval_type) = new InitValAST();
        (yyval.initval_type)->value = (yyvsp[-1].initvallist_type);
    }
#line 1668 "parse.tab.cpp"
    break;

  case 37: /* InitValList: InitVal  */
#line 457 "parse.y"
    {
        fprintf(detail_fp, "InitVal -> InitValList\n");
        (yyval.initvallist_type) = new InitValListAST();
        (yyval.initvallist_type)->init_vals.emplace_back((yyvsp[0].initval_type));
    }
#line 1678 "parse.tab.cpp"
    break;

  case 38: /* InitValList: InitValList COMMA InitVal  */
#line 463 "parse.y"
    {
        fprintf(detail_fp, "InitValList , InitVal -> InitValList\n");
        (yyvsp[-2].initvallist_type)->init_vals.emplace_back((yyvsp[0].initval_type));
        (yyval.initvallist_type) = (yyvsp[-2].initvallist_type);
    }
#line 1688 "parse.tab.cpp"
    break;

  case 39: /* FuncDef: VOID Ident LPAREN RPAREN Block  */
#line 472 "parse.y"
    {
        fprintf(detail_fp, "void %s ( ) Block -> FuncDef\n", (yyvsp[-3].const_string_val));
        (yyval.funcdef_type) = new FuncDefAST();
        (yyval.funcdef_type)->return_type = false;
        (yyval.funcdef_type)->ident = (yyvsp[-3].const_string_val);
        (yyval.funcdef_type)->block = (yyvsp[0].block_type);
    }
#line 1700 "parse.tab.cpp"
    break;

  case 40: /* FuncDef: INT Ident LPAREN RPAREN Block  */
#line 480 "parse.y"
    {
        fprintf(detail_fp, "int %s ( ) Block -> FuncDef\n", (yyvsp[-3].const_string_val));
        (yyval.funcdef_type) = new FuncDefAST();
        (yyval.funcdef_type)->return_type = true;
        (yyval.funcdef_type)->ident = (yyvsp[-3].const_string_val);
        (yyval.funcdef_type)->block = (yyvsp[0].block_type);
    }
#line 1712 "parse.tab.cpp"
    break;

  case 41: /* FuncDef: VOID Ident LPAREN FuncFParams RPAREN Block  */
#line 488 "parse.y"
    {
        fprintf(detail_fp, "void %s ( FuncFParams ) Block -> FuncDef\n", (yyvsp[-4].const_string_val));
        (yyval.funcdef_type) = new FuncDefAST();
        (yyval.funcdef_type)->return_type = false;
        (yyval.funcdef_type)->ident = (yyvsp[-4].const_string_val);
        (yyval.funcdef_type)->f_args.emplace_back((yyvsp[-2].funcfparams_type));
        (yyval.funcdef_type)->block = (yyvsp[0].block_type);
    }
#line 1725 "parse.tab.cpp"
    break;

  case 42: /* FuncDef: INT Ident LPAREN FuncFParams RPAREN Block  */
#line 497 "parse.y"
    {
        fprintf(detail_fp, "int %s ( FuncFParams ) Block -> FuncDef\n", (yyvsp[-4].const_string_val));
        (yyval.funcdef_type) = new FuncDefAST();
        (yyval.funcdef_type)->return_type = true;
        (yyval.funcdef_type)->ident = (yyvsp[-4].const_string_val);
        (yyval.funcdef_type)->f_args.emplace_back((yyvsp[-2].funcfparams_type));
        (yyval.funcdef_type)->block = (yyvsp[0].block_type);
    }
#line 1738 "parse.tab.cpp"
    break;

  case 43: /* FuncFParams: FuncFParam  */
#line 509 "parse.y"
    {
        fprintf(detail_fp, "FuncFParam -> FuncFParams\n");
        (yyval.funcfparams_type) = new FuncFParamsAST();
        (yyval.funcfparams_type)->f_args.emplace_back((yyvsp[0].funcfparam_type));
    }
#line 1748 "parse.tab.cpp"
    break;

  case 44: /* FuncFParams: FuncFParams COMMA FuncFParam  */
#line 515 "parse.y"
    {
        fprintf(detail_fp, "FuncFParams , FuncFParam -> FuncFParams\n");
        (yyvsp[-2].funcfparams_type)->f_args.emplace_back((yyvsp[0].funcfparam_type));
        (yyval.funcfparams_type) = (yyvsp[-2].funcfparams_type);
    }
#line 1758 "parse.tab.cpp"
    break;

  case 45: /* FuncFParam: INT Ident  */
#line 524 "parse.y"
    {
        fprintf(detail_fp, "int %s -> FuncFParam\n", (yyvsp[0].const_string_val));
        (yyval.funcfparam_type) = new FuncFParamAST();
        (yyval.funcfparam_type)->ident = (yyvsp[0].const_string_val);
    }
#line 1768 "parse.tab.cpp"
    break;

  case 46: /* FuncFParam: INT Ident LBRACK RBRACK  */
#line 530 "parse.y"
    {
        fprintf(detail_fp, "int %s [ ] -> FuncFParam\n", (yyvsp[-2].const_string_val));
        (yyval.funcfparam_type) = new FuncFParamAST();
        (yyval.funcfparam_type)->ident = (yyvsp[-2].const_string_val);
        (yyval.funcfparam_type)->dim.emplace_back(nullptr);
    }
#line 1779 "parse.tab.cpp"
    break;

  case 47: /* FuncFParam: INT Ident LBRACK RBRACK ArrDef  */
#line 537 "parse.y"
    {
        fprintf(detail_fp, "int %s [ ] ArrDef -> FuncFParam\n", (yyvsp[-3].const_string_val));
        (yyval.funcfparam_type) = new FuncFParamAST();
        (yyval.funcfparam_type)->ident = (yyvsp[-3].const_string_val);
        (yyvsp[0].arrdef_type)->dim.emplace_back(nullptr);
        (yyval.funcfparam_type)->dim = (yyvsp[0].arrdef_type)->dim;
        /* TODO */
    }
#line 1792 "parse.tab.cpp"
    break;

  case 48: /* Block: LBRACE RBRACE  */
#line 549 "parse.y"
    {
        fprintf(detail_fp, "{ } -> Block\n");
        (yyval.block_type) = new BlockAST();
    }
#line 1801 "parse.tab.cpp"
    break;

  case 49: /* Block: LBRACE BlockGroup RBRACE  */
#line 554 "parse.y"
    {
        fprintf(detail_fp, "{ BlockGroup } -> Block\n");
        (yyval.block_type) = new BlockAST();
        (yyval.block_type)->block_items = (yyvsp[-1].blockgroup_type)->block_items;
    }
#line 1811 "parse.tab.cpp"
    break;

  case 50: /* BlockGroup: BlockItem  */
#line 563 "parse.y"
    {
        fprintf(detail_fp, "BlockItem -> BlockGroup\n");
        (yyval.blockgroup_type) = new BlockGroupAST();
        (yyval.blockgroup_type)->block_items.emplace_back((yyvsp[0].blockitem_type));
    }
#line 1821 "parse.tab.cpp"
    break;

  case 51: /* BlockGroup: BlockGroup BlockItem  */
#line 569 "parse.y"
    {
        fprintf(detail_fp, "BlockGroup BlockItem -> BlockGroup\n");
        (yyvsp[-1].blockgroup_type)->block_items.emplace_back((yyvsp[0].blockitem_type));
        (yyval.blockgroup_type) = (yyvsp[-1].blockgroup_type);
    }
#line 1831 "parse.tab.cpp"
    break;

  case 52: /* BlockItem: Decl  */
#line 578 "parse.y"
    {
        fprintf(detail_fp, "Decl -> BlockItem\n");
        (yyval.blockitem_type) = new BlockItemAST();
        (yyval.blockitem_type)->block_item = (yyvsp[0].decl_type);
    }
#line 1841 "parse.tab.cpp"
    break;

  case 53: /* BlockItem: Stmt  */
#line 584 "parse.y"
    {
        fprintf(detail_fp, "Stmt -> BlockItem\n");
        (yyval.blockitem_type) = new BlockItemAST();
        (yyval.blockitem_type)->block_item = (yyvsp[0].stmt_type);
    }
#line 1851 "parse.tab.cpp"
    break;

  case 54: /* Stmt: LVal ASSIGN Exp SEMI  */
#line 593 "parse.y"
    {
        fprintf(detail_fp, "LVal = Exp ; -> Stmt\n");
        auto ptr = new AssignStmtAST();
        ptr->lvalue = (yyvsp[-3].lval_type);
        ptr->rvalue = (yyvsp[-1].exp_type);
        (yyval.stmt_type) = ptr;
    }
#line 1863 "parse.tab.cpp"
    break;

  case 55: /* Stmt: SEMI  */
#line 601 "parse.y"
    {
        fprintf(detail_fp, "; -> Stmt\n");
        (yyval.stmt_type) = new NullStmtAST();
    }
#line 1872 "parse.tab.cpp"
    break;

  case 56: /* Stmt: Exp SEMI  */
#line 606 "parse.y"
    {
        fprintf(detail_fp, "Exp ; -> Stmt\n");
        auto ptr = new ExpStmtAST();
        ptr->exp = (yyvsp[-1].exp_type);
        (yyval.stmt_type) = ptr;
    }
#line 1883 "parse.tab.cpp"
    break;

  case 57: /* Stmt: Block  */
#line 613 "parse.y"
    {
        fprintf(detail_fp, "Block -> Stmt\n");
        auto ptr = new BlockStmtAST();
        ptr->block_items = (yyvsp[0].block_type)->block_items;
        (yyval.stmt_type) = ptr;
    }
#line 1894 "parse.tab.cpp"
    break;

  case 58: /* Stmt: IF LPAREN Cond RPAREN Stmt  */
#line 620 "parse.y"
    {
        fprintf(detail_fp, "if ( Cond ) Stmt -> Stmt\n");
        auto ptr = new IfStmtAST();
        ptr->cond = (yyvsp[-2].exp_type);
        ptr->then_stmt = (yyvsp[0].stmt_type);
        ptr->else_stmt = nullptr;
        (yyval.stmt_type) = ptr;
    }
#line 1907 "parse.tab.cpp"
    break;

  case 59: /* Stmt: IF LPAREN Cond RPAREN Stmt ELSE Stmt  */
#line 629 "parse.y"
    {
        fprintf(detail_fp, "if ( Cond ) Stmt else Stmt -> Stmt\n");
        auto ptr = new IfStmtAST();
        ptr->cond = (yyvsp[-4].exp_type);
        ptr->then_stmt = (yyvsp[-2].stmt_type);
        ptr->else_stmt = (yyvsp[0].stmt_type);
        (yyval.stmt_type) = ptr;
    }
#line 1920 "parse.tab.cpp"
    break;

  case 60: /* Stmt: WHILE LPAREN Cond RPAREN Stmt  */
#line 638 "parse.y"
    {
        fprintf(detail_fp, "while ( Cond ) Stmt -> Stmt\n");
        auto ptr = new WhileStmtAST();
        ptr->cond = (yyvsp[-2].exp_type);
        ptr->stmt = (yyvsp[0].stmt_type);
        (yyval.stmt_type) = ptr;
    }
#line 1932 "parse.tab.cpp"
    break;

  case 61: /* Stmt: BREAK SEMI  */
#line 646 "parse.y"
    {
        fprintf(detail_fp, "break ; -> Stmt\n");
        (yyval.stmt_type) = new BreakStmtAST();
    }
#line 1941 "parse.tab.cpp"
    break;

  case 62: /* Stmt: CONTINUE SEMI  */
#line 651 "parse.y"
    {
        fprintf(detail_fp, "continue ; -> Stmt\n");
        (yyval.stmt_type) = new ContinueStmtAST();
    }
#line 1950 "parse.tab.cpp"
    break;

  case 63: /* Stmt: RETURN SEMI  */
#line 656 "parse.y"
    {
        fprintf(detail_fp, "return ; -> Stmt\n");
        auto ptr = new ReturnStmtAST();
        ptr->exp = nullptr;
        (yyval.stmt_type) = ptr;
    }
#line 1961 "parse.tab.cpp"
    break;

  case 64: /* Stmt: RETURN Exp SEMI  */
#line 663 "parse.y"
    {
        fprintf(detail_fp, "return Exp ; -> Stmt\n");
        auto ptr = new ReturnStmtAST();
        ptr->exp = (yyvsp[-1].exp_type);
        (yyval.stmt_type) = ptr;
    }
#line 1972 "parse.tab.cpp"
    break;

  case 65: /* Exp: AddExp  */
#line 673 "parse.y"
    {
        fprintf(detail_fp, "AddExp -> Exp\n");
        (yyval.exp_type) = (yyvsp[0].exp_type);
    }
#line 1981 "parse.tab.cpp"
    break;

  case 66: /* ConstExp: AddExp  */
#line 681 "parse.y"
    {
        fprintf(detail_fp, "AddExp -> ConstExp\n");
        (yyval.exp_type) = (yyvsp[0].exp_type);
    }
#line 1990 "parse.tab.cpp"
    break;

  case 67: /* Cond: LOrExp  */
#line 689 "parse.y"
    {
        fprintf(detail_fp, "LOrExp -> Cond\n");
        (yyval.exp_type) = (yyvsp[0].exp_type);
    }
#line 1999 "parse.tab.cpp"
    break;

  case 68: /* LVal: Ident  */
#line 697 "parse.y"
    {
        fprintf(detail_fp, "%s -> LVal\n", (yyvsp[0].const_string_val));
        (yyval.lval_type) = new LValAST();
        (yyval.lval_type)->ident = (yyvsp[0].const_string_val);
    }
#line 2009 "parse.tab.cpp"
    break;

  case 69: /* LVal: Ident ArrDef  */
#line 703 "parse.y"
    {
        fprintf(detail_fp, "Ident ArrDef -> LVal\n");
        (yyval.lval_type) = new LValAST();
        (yyval.lval_type)->ident = (yyvsp[-1].const_string_val);
        (yyval.lval_type)->dim = (yyvsp[0].arrdef_type)->dim;
    }
#line 2020 "parse.tab.cpp"
    break;

  case 70: /* PrimaryExp: LPAREN Exp RPAREN  */
#line 713 "parse.y"
    {
        fprintf(detail_fp, "( Exp ) -> PrimaryExp\n");
        (yyval.exp_type) = (yyvsp[-1].exp_type);
    }
#line 2029 "parse.tab.cpp"
    break;

  case 71: /* PrimaryExp: LVal  */
#line 718 "parse.y"
    {
        fprintf(detail_fp, "LVal -> PrimaryExp\n");
        auto ptr = new VarExpAST();
        ptr->ident = (yyvsp[0].lval_type)->ident;
        ptr->dim = (yyvsp[0].lval_type)->dim;
        (yyval.exp_type) = ptr;
    }
#line 2041 "parse.tab.cpp"
    break;

  case 72: /* PrimaryExp: IntConst  */
#line 726 "parse.y"
    {
        fprintf(detail_fp, "%d -> PrimaryExp\n", (yyvsp[0].const_int_val));
        auto ptr = new NumExpAST();
        ptr->value = (yyvsp[0].const_int_val);
        (yyval.exp_type) = ptr;
    }
#line 2052 "parse.tab.cpp"
    break;

  case 73: /* UnaryExp: PrimaryExp  */
#line 736 "parse.y"
    {
        fprintf(detail_fp, "PrimaryExp -> UnaryExp\n");
        (yyval.exp_type) = (yyvsp[0].exp_type);
    }
#line 2061 "parse.tab.cpp"
    break;

  case 74: /* UnaryExp: Ident LPAREN RPAREN  */
#line 741 "parse.y"
    {
        fprintf(detail_fp, "%s ( ) -> UnaryExp\n", (yyvsp[-2].const_string_val));
        auto ptr = new FuncCallAST();
        ptr->ident = (yyvsp[-2].const_string_val);
        ptr->r_args.emplace_back(nullptr);
        (yyval.exp_type) = ptr;
        (yyval.exp_type) = ptr;
    }
#line 2074 "parse.tab.cpp"
    break;

  case 75: /* UnaryExp: Ident LPAREN FuncRParams RPAREN  */
#line 750 "parse.y"
    {
        fprintf(detail_fp, "%s ( FuncRParams ) -> UnaryExp\n", (yyvsp[-3].const_string_val));
        auto ptr = new FuncCallAST();
        ptr->ident = (yyvsp[-3].const_string_val);
        if((yyvsp[-1].funcrparams_type)->str != "") {
            ptr->format_output = (yyvsp[-1].funcrparams_type)->str;
        }
        ptr->r_args = (yyvsp[-1].funcrparams_type)->r_args;
        (yyval.exp_type) = ptr;
    }
#line 2089 "parse.tab.cpp"
    break;

  case 76: /* UnaryExp: UnaryOp UnaryExp  */
#line 761 "parse.y"
    {
        fprintf(detail_fp, "UnaryOp UnaryExp -> UnaryExp\n");
        auto ptr = new UnaryExpAST();
        ptr->op = (yyvsp[-1].unaryop_type)->op;
        ptr->value = (yyvsp[0].exp_type);
        (yyval.exp_type) = ptr;
    }
#line 2101 "parse.tab.cpp"
    break;

  case 77: /* UnaryOp: ADD  */
#line 772 "parse.y"
    {
        fprintf(detail_fp, "+ -> UnaryOp\n");
        (yyval.unaryop_type) = new UnaryOpAST();
        (yyval.unaryop_type)->op = "+";
    }
#line 2111 "parse.tab.cpp"
    break;

  case 78: /* UnaryOp: SUB  */
#line 778 "parse.y"
    {
        fprintf(detail_fp, "- -> UnaryOp\n");
        (yyval.unaryop_type) = new UnaryOpAST();
        (yyval.unaryop_type)->op = std::string("-");
    }
#line 2121 "parse.tab.cpp"
    break;

  case 79: /* UnaryOp: NOT  */
#line 784 "parse.y"
    {
        fprintf(detail_fp, "! -> UnaryOp\n");
        (yyval.unaryop_type) = new UnaryOpAST();
        (yyval.unaryop_type)->op = std::string("!");
    }
#line 2131 "parse.tab.cpp"
    break;

  case 80: /* FuncRParams: Exp  */
#line 793 "parse.y"
    {
        fprintf(detail_fp, "Exp -> FuncRParams\n");
        (yyval.funcrparams_type) = new FuncRParamsAST();
        (yyval.funcrparams_type)->r_args.emplace_back((yyvsp[0].exp_type));
    }
#line 2141 "parse.tab.cpp"
    break;

  case 81: /* FuncRParams: Exp COMMA FuncRParams  */
#line 799 "parse.y"
    {
        fprintf(detail_fp, "Exp , FuncRParams -> FuncRParams\n");
        (yyvsp[0].funcrparams_type)->r_args.emplace_back((yyvsp[-2].exp_type));
        (yyval.funcrparams_type) = (yyvsp[0].funcrparams_type);
    }
#line 2151 "parse.tab.cpp"
    break;

  case 82: /* FuncRParams: String COMMA FuncRParams  */
#line 805 "parse.y"
    {
        fprintf(detail_fp, "%s , FuncRParams -> FuncRParams\n", (yyvsp[-2].const_string_val));
        (yyvsp[0].funcrparams_type)->str = (yyvsp[-2].const_string_val);
        (yyval.funcrparams_type) = (yyvsp[0].funcrparams_type);
    }
#line 2161 "parse.tab.cpp"
    break;

  case 83: /* MulExp: UnaryExp  */
#line 814 "parse.y"
    {
        fprintf(detail_fp, "UnaryExp -> MulExp\n");
        (yyval.exp_type) = (yyvsp[0].exp_type);
    }
#line 2170 "parse.tab.cpp"
    break;

  case 84: /* MulExp: MulExp MUL UnaryExp  */
#line 819 "parse.y"
    {
        fprintf(detail_fp, "MulExp * UnaryExp -> MulExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("*");
        ptr->lhs = (yyvsp[-2].exp_type);
        ptr->rhs = (yyvsp[0].exp_type);
        (yyval.exp_type) = ptr;
    }
#line 2183 "parse.tab.cpp"
    break;

  case 85: /* MulExp: MulExp DIV UnaryExp  */
#line 828 "parse.y"
    {
        fprintf(detail_fp, "MulExp / UnaryExp -> MulExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("/");
        ptr->lhs = (yyvsp[-2].exp_type);
        ptr->rhs = (yyvsp[0].exp_type);
        (yyval.exp_type) = ptr;
    }
#line 2196 "parse.tab.cpp"
    break;

  case 86: /* MulExp: MulExp MOD UnaryExp  */
#line 837 "parse.y"
    {
        fprintf(detail_fp, "MulExp %% UnaryExp -> MulExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("%");
        ptr->lhs = (yyvsp[-2].exp_type);
        ptr->rhs = (yyvsp[0].exp_type);
        (yyval.exp_type) = ptr;
    }
#line 2209 "parse.tab.cpp"
    break;

  case 87: /* AddExp: MulExp  */
#line 849 "parse.y"
    {
        fprintf(detail_fp, "MulExp -> AddExp\n");
        (yyval.exp_type) = (yyvsp[0].exp_type);
    }
#line 2218 "parse.tab.cpp"
    break;

  case 88: /* AddExp: AddExp ADD MulExp  */
#line 854 "parse.y"
    {
        fprintf(detail_fp, "AddExp + MulExp -> AddExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("+");
        ptr->lhs = (yyvsp[-2].exp_type);
        ptr->rhs = (yyvsp[0].exp_type);
        (yyval.exp_type) = ptr;
    }
#line 2231 "parse.tab.cpp"
    break;

  case 89: /* AddExp: AddExp SUB MulExp  */
#line 863 "parse.y"
    {
        fprintf(detail_fp, "AddExp - MulExp -> AddExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("-");
        ptr->lhs = (yyvsp[-2].exp_type);
        ptr->rhs = (yyvsp[0].exp_type);
        (yyval.exp_type) = ptr;
    }
#line 2244 "parse.tab.cpp"
    break;

  case 90: /* RelExp: AddExp  */
#line 875 "parse.y"
    {
        fprintf(detail_fp, "AddExp -> RelExp\n");
        (yyval.exp_type) = (yyvsp[0].exp_type);
    }
#line 2253 "parse.tab.cpp"
    break;

  case 91: /* RelExp: RelExp LT AddExp  */
#line 880 "parse.y"
    {
        fprintf(detail_fp, "RelExp < AddExp -> RelExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("<");
        ptr->lhs = (yyvsp[-2].exp_type);
        ptr->rhs = (yyvsp[0].exp_type);
        (yyval.exp_type) = ptr;
    }
#line 2266 "parse.tab.cpp"
    break;

  case 92: /* RelExp: RelExp LE AddExp  */
#line 889 "parse.y"
    {
        fprintf(detail_fp, "RelExp <= AddExp -> RelExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("<=");
        ptr->lhs = (yyvsp[-2].exp_type);
        ptr->rhs = (yyvsp[0].exp_type);
        (yyval.exp_type) = ptr;
    }
#line 2279 "parse.tab.cpp"
    break;

  case 93: /* RelExp: RelExp GT AddExp  */
#line 898 "parse.y"
    {
        fprintf(detail_fp, "RelExp > AddExp -> RelExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string(">");
        ptr->lhs = (yyvsp[-2].exp_type);
        ptr->rhs = (yyvsp[0].exp_type);
        (yyval.exp_type) = ptr;
    }
#line 2292 "parse.tab.cpp"
    break;

  case 94: /* RelExp: RelExp GE AddExp  */
#line 907 "parse.y"
    {
        fprintf(detail_fp, "RelExp >= AddExp -> RelExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string(">=");
        ptr->lhs = (yyvsp[-2].exp_type);
        ptr->rhs = (yyvsp[0].exp_type);
        (yyval.exp_type) = ptr;
    }
#line 2305 "parse.tab.cpp"
    break;

  case 95: /* EqExp: RelExp  */
#line 919 "parse.y"
    {
        fprintf(detail_fp, "RelExp -> EqExp\n");
        (yyval.exp_type) = (yyvsp[0].exp_type);
    }
#line 2314 "parse.tab.cpp"
    break;

  case 96: /* EqExp: EqExp EQ RelExp  */
#line 924 "parse.y"
    {
        fprintf(detail_fp, "EqExp == RelExp -> EqExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("==");
        ptr->lhs = (yyvsp[-2].exp_type);
        ptr->rhs = (yyvsp[0].exp_type);
        (yyval.exp_type) = ptr;
    }
#line 2327 "parse.tab.cpp"
    break;

  case 97: /* EqExp: EqExp NE RelExp  */
#line 933 "parse.y"
    {
        fprintf(detail_fp, "EqExp != RelExp -> EqExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("!=");
        ptr->lhs = (yyvsp[-2].exp_type);
        ptr->rhs = (yyvsp[0].exp_type);
        (yyval.exp_type) = ptr;
    }
#line 2340 "parse.tab.cpp"
    break;

  case 98: /* LAndExp: EqExp  */
#line 945 "parse.y"
    {
        fprintf(detail_fp, "EqExp -> LAndExp\n");
        (yyval.exp_type) = (yyvsp[0].exp_type);
    }
#line 2349 "parse.tab.cpp"
    break;

  case 99: /* LAndExp: LAndExp AND EqExp  */
#line 950 "parse.y"
    {
        fprintf(detail_fp, "LAndExp && EqExp -> LAndExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("&&");
        ptr->lhs = (yyvsp[-2].exp_type);
        ptr->rhs = (yyvsp[0].exp_type);
        (yyval.exp_type) = ptr;
    }
#line 2362 "parse.tab.cpp"
    break;

  case 100: /* LOrExp: LAndExp  */
#line 962 "parse.y"
    {
        fprintf(detail_fp, "LAndExp -> LOrExp\n");
        (yyval.exp_type) = (yyvsp[0].exp_type);
    }
#line 2371 "parse.tab.cpp"
    break;

  case 101: /* LOrExp: LOrExp OR LAndExp  */
#line 967 "parse.y"
    {
        fprintf(detail_fp, "LOrExp || LAndExp -> LOrExp\n");
        auto ptr = new BinaryExpAST();
        ptr->op = std::string("||");
        ptr->lhs = (yyvsp[-2].exp_type);
        ptr->rhs = (yyvsp[0].exp_type);
        (yyval.exp_type) = ptr;
    }
#line 2384 "parse.tab.cpp"
    break;


#line 2388 "parse.tab.cpp"

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

#line 977 "parse.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d, column %d\n", s, lines, chars);
}

int main() {
    detail_fp = fopen("./results/plot/detail.txt", "w");
    printf("Start\n");
    FILE *file = fopen("out.s", "w");
    // assemble_init();
    rodata.append(".section .rodata\n");
    data.append(".section .data\n");
    bss.append(".section .bss\n");
    text.append(".section .text\n");
    yyparse();
    std::ofstream out("results/plot/tree.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); // 保存旧的缓冲区
    std::cout.rdbuf(out.rdbuf()); // 重定向
    // 显示 AST
    show_ast(root, 0);
    // 恢复 std::cout 的缓冲区
    std::cout.rdbuf(coutbuf);
    // assemble_init();
    // BaseAST* base = root;
    // CompUnitAST* root = dynamic_cast<CompUnitAST*>(root);
    // root->const_eval(base);
    // ConstDeclAST* t = new ConstDeclAST();
    // t->const_eval(root);
    // root->const_eval(root);
    // const std::type_info& objType = typeid(dynamic_cast<CompUnitAST*>(root));
    // // 使用type_info的name()成员函数获取类型名
    // std::cout << "Type of obj: " << objType.name() << std::endl;
    root = (dynamic_cast<CompUnitAST*>(root));
    root->const_eval(root);
    root->code_gen();
    logger.log("----------------------------------------------------------------------") << std::endl;
    rodata.print_info(file);
    data.print_info(file);
    bss.print_info(file);
    text.print_info(file);
    fclose(file);
    return 0;
}
