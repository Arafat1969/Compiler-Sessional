/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "2005104.y" /* yacc.c:339  */

	#include<cstdio>
	#include<cstdlib>
	#include<iostream>
	#include<fstream>
	#include<string>
	#include "2005104_SymbolTable.h"
	using namespace std;

	ofstream logout("2005104_log.txt"), tokenout("2005104_token.txt"),errorout("2005104_error.txt");
	int yyparse(void);
	int yylex(void);
	extern FILE *yyin;
	extern int yylineno;
	SymbolTable *table = new SymbolTable(11);
	extern int errorCount;
	int arraySize=0;
	bool arrayInsertable;
	int value;
	string type;
	string type_final;
	void yyerror(string s)
	{
	
	}

	struct variable{
		string name;
		int size;
	}var;

	struct param{
		string type;
		string name;
	};

	vector<variable> vList;
	vector<param> pList;
	vector<SymbolInfo*> argList;

#line 107 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CONST_INT = 258,
    CONST_FLOAT = 259,
    ID = 260,
    ASSIGNOP = 261,
    NOT = 262,
    INCOP = 263,
    DECOP = 264,
    LOGICOP = 265,
    RELOP = 266,
    ADDOP = 267,
    MULOP = 268,
    INT = 269,
    FLOAT = 270,
    VOID = 271,
    IF = 272,
    ELSE = 273,
    FOR = 274,
    WHILE = 275,
    PRINTLN = 276,
    RETURN = 277,
    LPAREN = 278,
    RPAREN = 279,
    LCURL = 280,
    RCURL = 281,
    LTHIRD = 282,
    RTHIRD = 283,
    COMMA = 284,
    SEMICOLON = 285,
    LOWER_THAN_ELSE = 286
  };
#endif
/* Tokens.  */
#define CONST_INT 258
#define CONST_FLOAT 259
#define ID 260
#define ASSIGNOP 261
#define NOT 262
#define INCOP 263
#define DECOP 264
#define LOGICOP 265
#define RELOP 266
#define ADDOP 267
#define MULOP 268
#define INT 269
#define FLOAT 270
#define VOID 271
#define IF 272
#define ELSE 273
#define FOR 274
#define WHILE 275
#define PRINTLN 276
#define RETURN 277
#define LPAREN 278
#define RPAREN 279
#define LCURL 280
#define RCURL 281
#define LTHIRD 282
#define RTHIRD 283
#define COMMA 284
#define SEMICOLON 285
#define LOWER_THAN_ELSE 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 42 "2005104.y" /* yacc.c:355  */

	SymbolInfo *symbol;

#line 213 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 230 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    79,    88,    99,   107,   115,   126,   155,
     177,   252,   277,   311,   332,   350,   371,   383,   397,   440,
     450,   460,   473,   498,   544,   572,   609,   616,   627,   634,
     641,   648,   661,   672,   686,   697,   708,   719,   722,   729,
     739,   752,   773,   811,   820,   851,   862,   875,   884,   897,
     906,   926,   935,   967,   976,   985,   997,  1006,  1042,  1055,
    1064,  1072,  1081,  1092,  1103,  1112,  1133,  1149
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST_INT", "CONST_FLOAT", "ID",
  "ASSIGNOP", "NOT", "INCOP", "DECOP", "LOGICOP", "RELOP", "ADDOP",
  "MULOP", "INT", "FLOAT", "VOID", "IF", "ELSE", "FOR", "WHILE", "PRINTLN",
  "RETURN", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD",
  "COMMA", "SEMICOLON", "LOWER_THAN_ELSE", "$accept", "start", "program",
  "unit", "func_declaration", "func_definition", "parameter_list",
  "compound_statement", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "embedded_exp",
  "embedded_void", "expression_statement", "variable", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", "lcurl", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

#define YYPACT_NINF -83

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-83)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      98,   -83,   -83,   -83,     4,    98,   -83,   -83,   -83,   -83,
      32,   -83,   -83,    -4,    18,     0,    19,    49,   -83,     9,
      12,    55,    34,    48,   -83,   -83,   -83,    80,    38,    98,
     -83,   -83,    75,   -83,   -83,    17,    54,    54,    57,    63,
      66,    70,    54,    54,   -83,   -83,   -83,    93,   104,   -83,
      82,   128,   -83,    94,   125,    97,   -83,   -83,   -83,   -83,
     110,    89,    54,    54,   130,   -83,   -83,    54,    26,    54,
     117,   111,   122,   101,   -83,   -83,    54,   -83,   -83,   -83,
      54,    54,    54,    54,   -83,   -83,   -83,   131,   105,   124,
     -83,   -83,   -83,   126,   -83,   133,   -83,   -83,   -83,   -83,
     142,    97,   -83,   -83,    54,   -83,   134,   -83,   -83,   135,
     132,   -83,   -83,    26,   -83,   -83,   128,   -83,   128,   143,
     -83,   -83,   128,    54,   -83,   -83,   -83,   136,   128,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    19,    20,    21,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    24,     0,     0,     0,     0,    18,     0,
       0,    15,     0,    22,    67,     9,    11,     0,     0,     0,
      14,    25,     0,    59,    60,    41,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    30,    28,     0,     0,    26,
      56,     0,    43,    45,    47,    49,    51,    55,     8,    10,
      13,     0,    64,     0,    56,    54,    53,     0,     0,     0,
       0,     0,     0,    24,    16,    27,     0,    61,    62,    29,
       0,     0,     0,     0,    12,    23,    66,     0,    63,     0,
      37,    39,    37,     0,    37,     0,    36,    58,    44,    46,
      48,    50,    52,    57,     0,    42,     0,    38,    40,     0,
       0,    65,    38,     0,    38,    35,     0,    37,     0,    32,
      38,    34,     0,     0,    33,    37,    38,     0,     0,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -83,   -83,   158,   -83,   -83,   -83,    -8,    64,    13,
     -83,   -83,   -46,   -82,   -47,    51,   -30,   -42,   -59,    85,
      86,    84,   -28,   -83,   -83,   -83,   -83
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    20,    45,    46,    47,
      14,    48,    49,   106,   113,    92,    50,    51,    52,    53,
      54,    55,    56,    57,    87,    88,    27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      71,    72,    75,    86,    11,    79,    64,    64,    65,    66,
     107,    26,   109,    10,     1,     2,     3,    98,    10,    15,
      59,    89,    22,    16,    19,    90,    93,    94,    21,    33,
      34,    35,    64,    36,    24,   120,    28,    13,    37,    25,
      62,    29,    60,   126,    63,   111,    64,    17,    18,    43,
      64,    64,    64,    64,    23,   102,    91,    33,    34,    35,
      30,    36,    31,    24,     9,   116,    37,   118,    58,     9,
     119,    93,   121,   123,    64,    32,   124,    43,    61,   127,
      67,   125,   129,    33,    34,    35,    68,    36,    76,    69,
      77,    78,    37,    70,     1,     2,     3,    38,    73,    39,
      40,    41,    42,    43,    80,    24,    44,    33,    34,    35,
      83,    36,     1,     2,     3,    84,    37,    85,     1,     2,
       3,    38,    95,    39,    40,    41,    42,    43,    16,    24,
      74,    33,    34,    35,   104,    36,    81,    82,    77,    78,
      37,    96,     1,     2,     3,    38,    97,    39,    40,    41,
      42,    43,   105,    24,    82,   103,   108,   110,   112,   114,
     128,   122,   115,    12,   117,    99,   101,   100
};

static const yytype_uint8 yycheck[] =
{
      42,    43,    48,    62,     0,    51,    36,    37,    36,    37,
      92,    19,    94,     0,    14,    15,    16,    76,     5,    23,
      28,    63,     3,    27,    24,    67,    68,    69,    15,     3,
       4,     5,    62,     7,    25,   117,    24,     5,    12,    30,
      23,    29,    29,   125,    27,   104,    76,    29,    30,    23,
      80,    81,    82,    83,     5,    83,    30,     3,     4,     5,
       5,     7,    28,    25,     0,   112,    12,   114,    30,     5,
     116,   113,   118,   120,   104,    27,   122,    23,     3,   126,
      23,   123,   128,     3,     4,     5,    23,     7,     6,    23,
       8,     9,    12,    23,    14,    15,    16,    17,     5,    19,
      20,    21,    22,    23,    10,    25,    26,     3,     4,     5,
      13,     7,    14,    15,    16,     5,    12,    28,    14,    15,
      16,    17,     5,    19,    20,    21,    22,    23,    27,    25,
      26,     3,     4,     5,    29,     7,    11,    12,     8,     9,
      12,    30,    14,    15,    16,    17,    24,    19,    20,    21,
      22,    23,    28,    25,    12,    24,    30,    24,    24,    24,
      24,    18,    30,     5,   113,    80,    82,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    15,    16,    33,    34,    35,    36,    37,    40,
      41,     0,    35,     5,    42,    23,    27,    29,    30,    24,
      38,    41,     3,     5,    25,    30,    39,    58,    24,    29,
       5,    28,    27,     3,     4,     5,     7,    12,    17,    19,
      20,    21,    22,    23,    26,    39,    40,    41,    43,    44,
      48,    49,    50,    51,    52,    53,    54,    55,    30,    39,
      41,     3,    23,    27,    48,    54,    54,    23,    23,    23,
      23,    49,    49,     5,    26,    44,     6,     8,     9,    44,
      10,    11,    12,    13,     5,    28,    50,    56,    57,    49,
      49,    30,    47,    49,    49,     5,    30,    24,    50,    51,
      52,    53,    54,    24,    29,    28,    45,    45,    30,    45,
      24,    50,    24,    46,    24,    30,    46,    47,    46,    44,
      45,    44,    18,    46,    44,    49,    45,    46,    24,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    36,    36,
      37,    37,    38,    38,    38,    38,    39,    39,    40,    41,
      41,    41,    42,    42,    42,    42,    43,    43,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    45,    46,    47,
      47,    48,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    57,    57,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     5,     4,     3,     2,     1,     3,     2,     3,     1,
       1,     1,     3,     6,     1,     4,     1,     2,     1,     2,
       1,    13,     7,     9,     7,     5,     3,     0,     0,     1,
       2,     1,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     2,     1,     1,     4,     3,     1,
       1,     2,     2,     1,     0,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 68 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("program","start");
	logout << "start : program" << endl;
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end= (yyvsp[0].symbol)->end;
	logout<<"Total Lines: "<<yylineno<<endl;
	logout<<"Total Errors: 0"<<endl;
}
#line 1407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 79 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("program unit","program");
	(yyval.symbol)->start=(yyvsp[-1].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "program : program unit" << endl;
}
#line 1421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 88 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("program unit","program");
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "program : program unit" << endl;
}
#line 1434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 99 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol) = new SymbolInfo("var_declaration","unit");
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout<<"unit : var_declaration"<<endl;
}
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 107 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol) = new SymbolInfo("func_declaration","unit");
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "unit : func_declaration" << endl;
}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 115 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol) = new SymbolInfo("func_definition","unit");
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "unit : func_definition" << endl;
}
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)= new SymbolInfo("type_specifier","func_declaration");
	(yyval.symbol)->start=(yyvsp[-5].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-5].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	for(int i=0;i<(yyvsp[-2].symbol)->paraList.size();i++){
		(yyvsp[-4].symbol)->paraList.push_back((yyvsp[-2].symbol)->paraList[i]);
	}

	(yyvsp[-4].symbol)->isDec=true;
	SymbolInfo newSymbol((yyvsp[-4].symbol)->getName(),(yyvsp[-4].symbol)->getType());
	table->insert(newSymbol);
	SymbolInfo * temp=table->lookUp((yyvsp[-4].symbol)->getName());
	temp->isDec=true;
	temp->varType=(yyvsp[-5].symbol)->varType;

	for(int i=0;i<(yyvsp[-2].symbol)->paraList.size();i++){
		temp->paraList.push_back((yyvsp[-2].symbol)->paraList[i]);
	}
	
	pList.clear();
	logout << "func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON" << endl;
}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 155 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("type_specifier ID LPAREN RPAREN SEMICOLON","func_declaration");
	(yyval.symbol)->start=(yyvsp[-4].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	(yyvsp[-3].symbol)->isDec=true; 
	SymbolInfo  newSymbol((yyvsp[-3].symbol)->getName(),(yyvsp[-3].symbol)->getType());
	table->insert(newSymbol);
	SymbolInfo* temp=table->lookUp((yyvsp[-3].symbol)->getName());
	temp->isDec=true;
	pList.clear();

	logout << "func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON" << endl;
}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 177 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("type_specifier ID LPAREN parameter_list RPAREN compound_statement","func_definition");
	(yyval.symbol)->start=(yyvsp[-5].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-5].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	SymbolInfo* temp1=table->lookUp((yyvsp[-4].symbol)->getName());

	if(!temp1){
		SymbolInfo* sym= new SymbolInfo((yyvsp[-4].symbol)->getName(),(yyvsp[-5].symbol)->getType());

		for(int i=0;i<(yyvsp[-2].symbol)->paraList.size();i++){
			(yyvsp[-4].symbol)->paraList.push_back((yyvsp[-2].symbol)->paraList[i]);
			SymbolInfo newSymbol((yyvsp[-2].symbol)->paraList[i]->getName(),(yyvsp[-2].symbol)->paraList[i]->getType());
			table->insert(newSymbol);
		}
		SymbolInfo newSymbol3(sym->getName(),sym->getType());
		table->insert(newSymbol3);
		SymbolInfo* temp=table->lookUp(sym->getName());

		for(int i=0;i<(yyvsp[-2].symbol)->paraList.size();i++){
			temp->paraList.push_back((yyvsp[-2].symbol)->paraList[i]);
		}

		temp->varType=(yyvsp[-5].symbol)->varType;
	}else{
		SymbolInfo* temp =table->lookUp((yyvsp[-4].symbol)->getName());

		if(temp->isDef || temp->isDec){
			if((yyvsp[-5].symbol)->varType!=temp->varType){
				errorout<<"Line# "<<(yyvsp[-4].symbol)->end<<": Conflicting types for '"<<(yyvsp[-4].symbol)->getName()<<"'"<<endl;
				errorCount++;
			}

			if(temp1->paraList.size()>(yyvsp[-2].symbol)->paraList.size()){
				errorout<<"Line# "<<yylineno<<": Too few arguments to function '"<<(yyvsp[-4].symbol)->getName()<<"'"<<endl;
				errorCount++;
			}
			else if(temp1->paraList.size()<(yyvsp[-2].symbol)->paraList.size()){
				errorout<<"Line# "<<yylineno<<": Too many arguments to function '"<<(yyvsp[-4].symbol)->getName()<<"'"<<endl;
				errorCount++;
			}else{
				bool misMatch=false;

				for(int i=0;i<pList.size();i++)
				{
					if(((yyvsp[-2].symbol)->paraList[i]->varType!= temp1->paraList[i]->varType))
					{
						errorout<<"Line# "<< yylineno<<": Type mismatch for argument "<<(i+1)<<" of '"<<(yyvsp[-5].symbol)->getName()<<"'"<<endl;
						errorCount++;
						misMatch=true;
						
					}
				}

				if(!misMatch)
				{
					(yyvsp[-4].symbol)->isDef=true; 
				}
			}

		}else{
			errorout<<"Line# "<<(yyvsp[-4].symbol)->start<<": '"<<(yyvsp[-4].symbol)->getName()<<"' redeclared as different kind of symbol"<<endl;
			errorCount++;
		}
	}


	logout << "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement" << endl;
}
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 252 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("type_specifier ID LPAREN RPAREN compound_statement","func_definition");
	(yyval.symbol)->start=(yyvsp[-4].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	SymbolInfo* temp=table->lookUp((yyvsp[-3].symbol)->getName());

	if(!temp){
		SymbolInfo newSymbol4((yyvsp[-3].symbol)->getName(),(yyvsp[-4].symbol)->getType());
		table->insert(newSymbol4);
		SymbolInfo* temp1=table->lookUp(newSymbol4.getName());
		temp1->isDef=true;
		temp1->varType=(yyvsp[-4].symbol)->varType;
	}

	logout << "func_definition : type_specifier ID LPAREN RPAREN compound_statement" << endl;
}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 277 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)= new SymbolInfo("parameter_list COMMA type_specifier ID","parameter_list");
	param temp;
	temp.type=(yyvsp[-1].symbol)->varType;
	temp.name=(yyvsp[0].symbol)->getName();

	pList.push_back(temp);

	for(int i=0;i<(yyvsp[-3].symbol)->paraList.size();i++){
		(yyval.symbol)->paraList.push_back((yyvsp[-3].symbol)->paraList[i]);
	}

	(yyval.symbol)->paraList.push_back((yyvsp[0].symbol));
	(yyvsp[0].symbol)->varType=(yyvsp[-1].symbol)->varType;

	for(int i=0;i<(yyvsp[-3].symbol)->paraList.size();i++){
		for(int j=i+1;j<(yyvsp[-3].symbol)->paraList.size();j++){
			if((yyvsp[-3].symbol)->paraList[i]->getName()==(yyvsp[-3].symbol)->paraList[j]->getName())
			{
				errorout<<"Line# "<<yylineno<<": Redefinition of parameter '"<<(yyvsp[-3].symbol)->paraList[i]->getName()<<"'"<<endl;
				errorCount++;
			}
		}
	}

	(yyval.symbol)->start=(yyvsp[-3].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "parameter_list : parameter_list COMMA type_specifier ID" << endl;
}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 311 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("parameter_list COMMA type_specifier","parameter_list");
	param temp;
	temp.type=(yyvsp[0].symbol)->varType;
	temp.name="";
	pList.push_back(temp);

	SymbolInfo* sym= new SymbolInfo("","ID");
	(yyval.symbol)->paraList.push_back(sym);
	for(int i=0;i<(yyvsp[-2].symbol)->paraList.size();i++){
		(yyval.symbol)->paraList.push_back((yyvsp[-2].symbol)->paraList[i]);
	}
	
	(yyval.symbol)->start=(yyvsp[-2].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "parameter_list: parameter_list COMMA type_specifier" << endl;
}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 332 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("type_specifier ID","parameter_list");
	param temp;
	temp.type=(yyvsp[-1].symbol)->getType();
	temp.name=(yyvsp[0].symbol)->getName();
	(yyvsp[0].symbol)->varType=(yyvsp[-1].symbol)->varType;

	pList.push_back(temp);

	(yyval.symbol)->paraList.push_back((yyvsp[0].symbol));

	(yyval.symbol)->start=(yyvsp[-1].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "parameter_list : type_specifier ID" << endl;
}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 350 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("type_specifier","parameter_list");

	param temp;
	temp.type=(string)(yyvsp[0].symbol)->getType();
	temp.name="";

	pList.push_back(temp);
	SymbolInfo* sym=new SymbolInfo("","ID");
	sym->varType=(yyvsp[0].symbol)->getName();
	(yyval.symbol)->paraList.push_back(sym);

	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "parameter_list : type_specifier" << endl;
}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 371 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("LCURL statements RCURL","compound_statement");
	(yyval.symbol)->start=(yyvsp[-2].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "compound_statement: LCURL statements RCURL" << endl;
	logout << table->printAllScopeTable();
	table->exitScope();
}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 383 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("LCURL RCURL","compound_statement");
	(yyval.symbol)->start=(yyvsp[-1].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "compound_statement : LCURL RCURL" << endl;	
	logout << table->printAllScopeTable();
	table->exitScope();
}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 397 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("type_specifier declaration_list SEMICOLON","var_declaration");

	SymbolInfo* sym;
	if(sym->varType=="void"){
		errorCount++;
		for(int i=0;i<vList.size();i++){
			sym=new SymbolInfo(vList[i].name,"ID");
			SymbolInfo* temp=table->lookUp(sym->getName());
			if(temp->isInserted)
				temp->varType=(yyvsp[-2].symbol)->varType;
			errorout<<"Line# "<<yylineno<<": Variable or field '"<<vList[i].name<<"' declared void"<<endl;
		}
	}else{
		for(int i=0;i<vList.size();i++){
			SymbolInfo* temp=table->lookUp(vList[i].name);
			if((yyvsp[-2].symbol)->varType!= type ){
				errorout<<"Line# "<<yylineno<<": Conflicting types for '"<<vList[i].name<<"'"<<endl;
			}
			if(temp->isInserted){
				temp->varType=(yyvsp[-2].symbol)->varType;
			}
		}
	}
	

	for(int i=0;i<(yyvsp[-1].symbol)->decList.size();i++){
		(yyvsp[-1].symbol)->decList[i]->varType=(yyvsp[-2].symbol)->varType;
	}

	vList.clear();

	(yyval.symbol)->start=(yyvsp[-2].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "var_declaration : type_specifier declaration_list SEMICOLON" << endl;
}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 440 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("INT","type_specifier");
	(yyval.symbol)->varType="int";
	type="int";
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "type_specifier : INT" << endl;
}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 450 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("FLOAT","type_specifier");
	(yyval.symbol)->varType="float";
	type="float";
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "type_specifier : FLOAT" << endl;
}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 460 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("VOID","type_specifier");
	(yyval.symbol)->varType="void";
	type="void";
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "type_specifier : VOID" << endl;
}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 473 "2005104.y" /* yacc.c:1646  */
    {
	string name=(yyvsp[0].symbol)->getName();
	(yyval.symbol)=new SymbolInfo("declaration_list COMMA ID","declaration_list");

	for(int i=0;i<(yyvsp[-2].symbol)->decList.size();i++){
		(yyval.symbol)->decList.push_back((yyvsp[-2].symbol)->decList[i]);
	}
	(yyval.symbol)->decList.push_back((yyvsp[0].symbol));
	SymbolInfo newSymbol12((yyvsp[0].symbol)->getName(),(yyvsp[0].symbol)->getType());
	bool insertable=table->insert(newSymbol12);
	if(insertable){
		SymbolInfo* temp=table->lookUp((yyvsp[0].symbol)->getName());
		temp->arraySize=var.size;
		temp->isInserted=true;

		var.name=(string)(yyvsp[0].symbol)->getName();
		var.size=0;

		vList.push_back(var);
	}else{
		errorout<<"Line# "<<yylineno<<": Redefinition of parameter '"<<(yyvsp[0].symbol)->getName()<<"'"<<endl;
		errorCount++;
	}
	logout << "declaration_list : declaration_list COMMA ID" << endl;
}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 498 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("declaration_list COMMA ID LTHIRD CONST_INT RTHIRD","declaration_list");

	var.name=(string)(yyvsp[-3].symbol)->getName();
	var.size=stoi((yyvsp[-1].symbol)->getName());
	(yyvsp[-3].symbol)->arraySize=var.size;
	for(int i=0;i<(yyvsp[-5].symbol)->decList.size();i++)
	{
		(yyval.symbol)->decList.push_back((yyvsp[-5].symbol)->decList[i]);
	}
	(yyval.symbol)->decList.push_back((yyvsp[-3].symbol));
	SymbolInfo newSymbol((yyvsp[-3].symbol)->getName(),(yyvsp[-3].symbol)->getType());
	bool insertable=table->insert(newSymbol);
	arrayInsertable=insertable;

	if(insertable){
		SymbolInfo* temp=table->lookUp((yyvsp[-3].symbol)->getName());
		
		if((yyvsp[-1].symbol)->varType=="float")
		{
			errorout<<"Error at line# "<<yylineno<<": array size cannot be float '"<<(yyvsp[-3].symbol)->getType()<<"'"<<endl;
		}
		else{
			(yyvsp[-3].symbol)->arraySize=stoi((yyvsp[-1].symbol)->getName());
		}

		vList.push_back(var);
		temp->arraySize=var.size;
		temp->isInserted=true;
	}else{
		errorout<<"Line# "<<yylineno<<": Conflicting types for'"<<(yyvsp[-3].symbol)->getName()<<"'"<<endl;
		errorCount++;
	}

	arraySize=var.size;
	(yyval.symbol)->start=(yyvsp[-5].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-5].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "declaration_list : declaration_list COMMA ID LSQUARE CONST_INT RSQUARE" << endl;
}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 544 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("ID","declaration_list");
	(yyval.symbol)->decList.push_back((yyvsp[0].symbol));
	SymbolInfo newSymbol((yyvsp[0].symbol)->getName(),(yyvsp[0].symbol)->getType());
	bool insertable=table->insert(newSymbol);

	
	if(insertable){
		SymbolInfo* temp=table->lookUp((yyvsp[0].symbol)->getName());
		temp->arraySize=var.size;
		temp->isInserted=true;

		var.name=(string)(yyvsp[0].symbol)->getName();
		var.size=0;

		vList.push_back(var);
	}
	else{
		errorout<<"Line# "<<yylineno<<": Conflicting types for'"<<(yyvsp[0].symbol)->getName()<<"'"<<endl;
		errorCount++;
	}

	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "declaration_list : ID" << endl;
}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 572 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("ID LTHIRD CONST_INT RTHIRD ","declaration_list");

	if((yyvsp[-1].symbol)->varType=="float"){
		errorout<<"Line# "<<yylineno<<": array size cannot be float '"<<(yyvsp[-1].symbol)->getType()<<"'"<<endl;
		errorCount++;
	}

	(yyvsp[-3].symbol)->arraySize=stoi((yyvsp[-1].symbol)->getName());
	(yyval.symbol)->decList.push_back((yyvsp[-3].symbol));
	arraySize=var.size;
	SymbolInfo newSymbol15((yyvsp[-3].symbol)->getName(),(yyvsp[-3].symbol)->getType());
	bool insertable=table->insert(newSymbol15);
	arrayInsertable=insertable;
	if(insertable){
		SymbolInfo* temp=table->lookUp((yyvsp[-3].symbol)->getName());
		var.name=(string)(yyvsp[-3].symbol)->getName();
		var.size=stoi((yyvsp[-1].symbol)->getName());
		vList.push_back(var);
		temp->arraySize=var.size;
		temp->isInserted=true;
	}else{
		errorout<<"Line# "<<yylineno<<": Conflicting types for'"<<(yyvsp[-3].symbol)->getName()<<"'"<<endl;
		errorCount++;
	}
	arraySize=var.size;
	(yyval.symbol)->start=(yyvsp[-3].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "declaration_list : ID LSQUARE CONST_INT RSQUARE" << endl;
}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 609 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("statement","statements");
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statements : statement" << endl;
}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 616 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("statements statement","statements");
	(yyval.symbol)->start=(yyvsp[-1].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statements : statements statement" << endl;
}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 627 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("var_declaration","statement");
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statement : var_declaration" << endl;
}
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 634 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("expression_statement","statement");
	(yyval.symbol)->start=(yyvsp[-1].symbol)->start;
	(yyval.symbol)->end=(yyvsp[-1].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	logout << "statement : expression_statement" << endl;
}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 641 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("compound_statement","statement");
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statement : compound_statement" << endl;
}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 648 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("FOR LPAREN expression_statement expression RPAREN statement","statement");
	(yyval.symbol)->start=(yyvsp[-12].symbol)->start;
	(yyval.symbol)->end=(yyvsp[-6].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-12].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-11].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-10].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-9].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-8].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-7].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-6].symbol));
	logout << "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement" << endl;
}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 661 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("IF LPAREN expression RPAREN statement","statement");
	(yyval.symbol)->start=(yyvsp[-6].symbol)->start;
	(yyval.symbol)->end=(yyvsp[-2].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-6].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-5].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	logout << "statement : IF LPAREN expression RPAREN statement" << endl;
}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 672 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("IF LPAREN expression RPAREN statement ELSE statement","statement");
	(yyval.symbol)->start=(yyvsp[-8].symbol)->start;
	(yyval.symbol)->end=(yyvsp[-2].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-8].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-7].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-6].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-5].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
		
	logout << "statement : IF LPAREN expression RPAREN statement ELSE statement" << endl;
}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 686 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("WHILE LPAREN expression RPAREN statement","statement");
	(yyval.symbol)->start=(yyvsp[-6].symbol)->start;
	(yyval.symbol)->end=(yyvsp[-2].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-6].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-5].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	logout << "statement : WHILE LPAREN expression RPAREN statement" << endl;
}
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 697 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("PRINTLN LPAREN ID RPAREN SEMICOLON","statement");
	(yyval.symbol)->start=(yyvsp[-4].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statement: PRINTLN LPAREN ID RPAREN SEMICOLON";
}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 708 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("RETURN expression SEMICOLON","statement");
	(yyval.symbol)->start=(yyvsp[-2].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;	
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statement : RETURN expression SEMICOLON" << endl;
}
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 719 "2005104.y" /* yacc.c:1646  */
    {
	 type_final=type;
}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 722 "2005104.y" /* yacc.c:1646  */
    {
	if(type_final=="void")
	{
		errorout<<"Line# "<<yylineno<<": void function called within expression"<<endl;
		errorCount++;
	}
}
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 729 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("SEMICOLON","expression_statement");
	(yyval.symbol)->varType="int";//why?
	type="int";//why?
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;	
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "expression_statement : SEMICOLON" << endl;
}
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 739 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("expression SEMICOLON","expression_statement");
	(yyval.symbol)->varType=(yyvsp[-1].symbol)->varType;//why?
	type=(yyvsp[-1].symbol)->varType;//why?
	(yyval.symbol)->start=(yyvsp[-1].symbol)->start;
	(yyval.symbol)->end=(yyvsp[-1].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "expression_statement : expression SEMICOLON" << endl;
}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 752 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("ID","variable");
	SymbolInfo* temp=table->lookUp((yyvsp[0].symbol)->getName());
	if(!temp){
		errorout<<"Line# "<<yylineno<<": Undeclared variable '"<<(yyvsp[0].symbol)->getName()<<"'"<<endl;
		errorCount++;
		(yyval.symbol)->varType="error";
	}else{
		(yyvsp[0].symbol)->varType=temp->varType;
		if((yyvsp[0].symbol)->varType!="void"){
			(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
		}else{
			(yyval.symbol)->varType="float";
		}
	}

	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "variable : ID" << endl;
}
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 773 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("ID LTHIRD expression RTHIRD","variable");
	SymbolInfo* temp=table->lookUp((yyvsp[-3].symbol)->getName());
	(yyval.symbol)->varType=temp->varType;
	(yyvsp[-3].symbol)->varType=temp->varType;

	(yyval.symbol)->arraySize=(yyvsp[-1].symbol)->arraySize;
	if(!temp){
		errorout<<"Line# "<<yylineno<<": undeclared variable '"<<(yyvsp[-3].symbol)->getName()<<"'"<<endl;
		errorCount++;
		(yyval.symbol)->varType="float";
	}else if(temp->arraySize==0){
		errorout<<"Line# "<<yylineno<<": '"<<(yyvsp[-3].symbol)->getName()<<"' is not an array"<<endl;
		errorCount++;
	}else{
		(yyvsp[-3].symbol)->varType=temp->varType;
		if((yyvsp[-3].symbol)->varType!="void"){
			(yyval.symbol)->varType=(yyvsp[-3].symbol)->varType;
		}else{
			(yyval.symbol)->varType="float";
		}	
	}

	if((yyvsp[-1].symbol)->varType!="int"){
		errorout<<"Line# "<<yylineno<<": Array subscript is not an integer"<<endl;
		errorCount++;
	}
	(yyval.symbol)->start=(yyvsp[-3].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "variable : ID LSQUARE expression RSQUARE" << endl;
}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 811 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("logic_expression","expression");
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	type=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "expression : logic_expression" << endl;
}
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 820 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("variable ASSIGNOP logic_expression","expression");
	
	if((yyvsp[-2].symbol)->varType=="float" && type=="int"){
		(yyvsp[0].symbol)->varType="float";
	}else if((yyvsp[-2].symbol)->varType=="void" || (yyvsp[0].symbol)->varType=="void"){
		errorout<<"Line# "<<yylineno<<": Void cannot be used in expression "<<endl;
		errorCount++;
	}
	else if((yyvsp[0].symbol)->varType=="float" && (yyvsp[-2].symbol)->varType=="int"){
		errorout<<"Line# "<<yylineno<<": Warning: possible loss of data in assignment of FLOAT to INT"<<endl;
		errorCount++;
	}else if((yyvsp[-2].symbol)->varType!=(yyvsp[0].symbol)->varType){
		errorout<<"Line# "<<yylineno<<": type mismatch(not array2)"<<endl;
		//cout<<"from assign: "<<$1->varType<<" : "<<$3->varType<<endl;
		errorCount++;
	}else {
		(yyval.symbol)->varType=(yyvsp[-2].symbol)->varType;
		type=(yyvsp[-2].symbol)->varType;
	}
	(yyval.symbol)->start=(yyvsp[-2].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "expression : variable ASSIGNOP logic_expression" << endl;
}
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 851 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("rel_expression","logic_expression");

	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;

	logout << "logic_expression : rel_expression" << endl;
}
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 862 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("rel_expression LOGICOP rel_expression","logic_expression");
	(yyval.symbol)->varType="int";
	(yyval.symbol)->start=(yyvsp[-2].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "logic_expression : rel_expression LOGICOP rel_expression" << endl;
}
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 875 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("simple_expression","rel_expression");	
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;
	logout << "rel_expression : simple_expression" << endl;
}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 884 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("simple_expression RELOP simple_expression","rel_expression");
	(yyval.symbol)->varType="int";
	(yyval.symbol)->start=(yyvsp[-2].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "rel_expression : simple_expression RELOP simple_expression" << endl;
}
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 897 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("term","simple_expression");
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;
	logout << "simple_expression : term" << endl;
}
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 906 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("simple_expression ADDOP term","simple_expression");

	if((yyvsp[-2].symbol)->varType=="float" || (yyvsp[0].symbol)->varType=="float"){
		(yyval.symbol)->varType="float";
	}else {
		(yyval.symbol)->varType=(yyvsp[-2].symbol)->varType;
	}

	(yyval.symbol)->start=(yyvsp[-2].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
					
	logout << "simple_expression : simple_expression ADDOP term" << endl;
}
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 926 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("unary_expression","term");
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;
	logout << "term : unary_expression" << endl;
}
#line 2458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 935 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("term MULOP unary_expression","term");


	if((yyvsp[-2].symbol)->varType=="void" || (yyvsp[0].symbol)->varType=="void"){
		errorout<<"Line# "<<yylineno<<": Void cannot be used in expression"<<endl;
		errorCount++;
	}else if(((yyvsp[-1].symbol)->getName()=="%"|| (yyvsp[-1].symbol)->getName()=="/") && !value){
		errorout<<"Line# "<<yylineno<<": Warning: division by zero i=0f=1Const=0"<<endl;
		errorCount++;
		(yyval.symbol)->varType="int";
	}else if((yyvsp[-1].symbol)->getName()=="%" && ((yyvsp[-2].symbol)->varType!="int" || (yyvsp[0].symbol)->varType!="int")){
		errorout<<"Line# "<<yylineno<<": Operands of modulus must be integers "<<endl;
		errorCount++;
		(yyval.symbol)->varType="int";
	}else if((yyvsp[-1].symbol)->getName()!="%" && ((yyvsp[-2].symbol)->varType=="float" || (yyvsp[0].symbol)->varType=="float")) {
		(yyval.symbol)->varType="float";
	}else{
		(yyval.symbol)->varType=(yyvsp[-2].symbol)->varType;
	}

	(yyval.symbol)->start=(yyvsp[-2].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "term : term MULOP unary_expression" << endl;
}
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 967 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("ADDOP unary_expression","unary_expression");
	(yyval.symbol)->start=(yyvsp[-1].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType="int";
	logout << "unary_expression : ADDOP unary_expression" << endl;
}
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 976 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("NOT unary_expression","unary_expression");
	(yyval.symbol)->start=(yyvsp[-1].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType="int";
	logout << "unary_expression : NOT unary_expression" << endl;
}
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 985 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("factor","unary_expression");
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;

	logout << "unary_expression : factor" << endl;
}
#line 2535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 997 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("variable","factor");
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;
	logout << "factor : variable" << endl;
}
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1006 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("ID LPAREN argument_list RPAREN","factor");
	SymbolInfo* si=table->lookUp((yyvsp[-3].symbol)->getName());
	argList.clear();
	(yyval.symbol)->start=(yyvsp[-3].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	SymbolInfo* temp=table->lookUp((yyvsp[-3].symbol)->getName());

	if(!temp){
		errorout<<"Line# "<<yylineno<<": Undeclared function '"<<(yyvsp[-3].symbol)->getName()<<"'"<<endl;
		errorCount++;
		(yyval.symbol)->varType="empty";
	}else{
		(yyval.symbol)->varType=temp->varType;
		if((yyvsp[-1].symbol)->argList.size()<temp->paraList.size()){
			errorout<<"Line# "<<(yyvsp[-2].symbol)->start<<": Too few arguments to function '"<<(yyvsp[-3].symbol)->getName()<<"'"<<endl;
			errorCount++;
		}else if((yyvsp[-1].symbol)->argList.size()>temp->paraList.size()){
			errorout<<"Line# "<<(yyvsp[-2].symbol)->start<<": Too many arguments to function '"<<(yyvsp[-3].symbol)->getName()<<"'"<<endl;
			errorCount++;
		}else {
			for(int i=0;i<temp->paraList.size();i++){
				if((argList[i]->varType!= temp->paraList[i]->varType) || (argList[i]->arraySize!= temp->paraList[i]->arraySize) ){
					errorout<<"Line# "<<(yyvsp[-3].symbol)->start<<": Type mismatch for argument "<<(i+1)<<" of '"<<(yyvsp[-3].symbol)->getName()<<"'"<<endl;
					errorCount++;
				}
			}
		}
	}
	logout << "factor : ID LPAREN argument_list RPAREN" << endl;
}
#line 2590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1042 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("LPAREN expression RPAREN","factor");
	SymbolInfo* temp=table->lookUp((yyvsp[-2].symbol)->getName());
	(yyval.symbol)->start=(yyvsp[-2].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	(yyvsp[-1].symbol)->varType="float";
	(yyval.symbol)->varType=(yyvsp[-1].symbol)->varType;
	logout << "factor : LPAREN expression RPAREN" << endl;
}
#line 2608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1055 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("CONST_INT","factor");
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType="int";
	value=stoi((yyvsp[0].symbol)->getName());
	logout << "factor : CONST_INT" << endl;
}
#line 2622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1064 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("CONST_FLOAT","factor");
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType="float";
	logout << "factor : CONST_FLOAT" << endl;
}
#line 2635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1072 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("variable INCOP","factor");
	(yyval.symbol)->varType=(yyvsp[-1].symbol)->varType;
	(yyval.symbol)->start=(yyvsp[-1].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "factor : variable INCOP" << endl;
}
#line 2649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1081 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("variable DECOP","factor");
	(yyval.symbol)->varType=(yyvsp[-1].symbol)->varType;
	(yyval.symbol)->start=(yyvsp[-1].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "factor : variable DECOP" << endl;
}
#line 2663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1092 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("arguments","argument_list");
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	for(int i=0;i<(yyvsp[0].symbol)->argList.size();i++){
		(yyval.symbol)->argList.push_back((yyvsp[0].symbol)->argList[i]);		
	}
	logout << "argument_list : arguments" << endl;
}
#line 2679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1103 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("","argument_list");
	(yyval.symbol)->start=yylineno;
	(yyval.symbol)->end=yylineno;
	logout << "argument_list : " << endl;
}
#line 2690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1112 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("arguments COMMA logic_expression ","arguments");
	
	if((yyvsp[0].symbol)->varType=="void"){
		errorout<<"Line# "<<yylineno<<": Void function cannot be called in argument of function "<<endl;;
		errorCount++;
		(yyvsp[0].symbol)->varType="float";
	}

	(yyval.symbol)->start=(yyvsp[-2].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	argList.push_back((yyvsp[0].symbol));
	for(int i=0;i<argList.size();i++){
		(yyval.symbol)->argList.push_back(argList[i]);
	}

	logout << "arguments : arguments COMMA logic_expression" << endl;
}
#line 2716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1133 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("logic_expression","arguments");
	if((yyvsp[0].symbol)->varType=="void"){
		errorout<<"Line# "<<yylineno<<": Void function cannot be called in argument of function"<<endl;
		errorCount++;
		(yyvsp[0].symbol)->varType="float";
	}
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	argList.push_back((yyvsp[0].symbol));
	(yyval.symbol)->argList.push_back((yyvsp[0].symbol));
	logout << "arguments : logic_expression" << endl;
}
#line 2735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1149 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;
	table->enterScope();
	for(int i=0;i<pList.size();i++){
		if(pList[i].name!=""){
			if(pList[i].name=="void"){

			}else{
				SymbolInfo  newSymbol6(pList[i].name,pList[i].type);
				table->insert(newSymbol6);
			}
		}
	}
	pList.clear();
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->start=(yyvsp[0].symbol)->start;
	(yyval.symbol)->end=(yyvsp[0].symbol)->end;		
}
#line 2759 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2763 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
  return yyresult;
}
#line 1170 "2005104.y" /* yacc.c:1906  */

int main(int argc,char *argv[])
{
	auto fp = fopen(argv[1], "r");
	if(fp==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	yyin=fp;
	yyparse();
	
	fclose(fp);
	
	return 0;
}
