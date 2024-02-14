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

	#include<bits/stdc++.h> 
	#include<cstdio>
	#include<cstdlib>
	#include<iostream>
	#include<fstream>
	#include<string>
	#include "2005104_SymbolTable.h"
	using namespace std;

	ofstream logout("log.txt"), parseout("parsetree.txt"),errorout("error.txt");
	int yyparse(void);
	int yylex(void);
	extern FILE *yyin;
	SymbolTable table(11);
	extern int errorCount;
	int arraySize=0;
	bool arrayInsertable;
	int line=1;
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

#line 108 "2005104.tab.c" /* yacc.c:339  */

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
   by #include "2005104.tab.h".  */
#ifndef YY_YY_2005104_TAB_H_INCLUDED
# define YY_YY_2005104_TAB_H_INCLUDED
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
    SEMICOLON = 261,
    ASSIGNOP = 262,
    NOT = 263,
    INCOP = 264,
    DECOP = 265,
    LOGICOP = 266,
    RELOP = 267,
    ADDOP = 268,
    MULOP = 269,
    INT = 270,
    FLOAT = 271,
    VOID = 272,
    IF = 273,
    ELSE = 274,
    FOR = 275,
    WHILE = 276,
    PRINTLN = 277,
    RETURN = 278,
    LPAREN = 279,
    RPAREN = 280,
    LTHIRD = 281,
    RTHIRD = 282,
    LCURL = 283,
    RCURL = 284,
    COMMA = 285,
    STRUCT = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 43 "2005104.y" /* yacc.c:355  */

	SymbolInfo *symbol;

#line 184 "2005104.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_2005104_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "2005104.tab.c" /* yacc.c:358  */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   183

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

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
       0,    69,    69,    82,    91,   102,   110,   118,   126,   136,
     166,   192,   265,   292,   326,   347,   365,   386,   398,   413,
     458,   469,   479,   491,   503,   517,   547,   595,   623,   661,
     668,   679,   686,   693,   700,   713,   724,   738,   749,   760,
     769,   778,   782,   789,   799,   812,   833,   870,   879,   905,
     916,   929,   938,   951,   960,   982,   991,  1023,  1036,  1045,
    1057,  1066,  1104,  1117,  1126,  1134,  1143,  1154,  1165,  1174,
    1195,  1211
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST_INT", "CONST_FLOAT", "ID",
  "SEMICOLON", "ASSIGNOP", "NOT", "INCOP", "DECOP", "LOGICOP", "RELOP",
  "ADDOP", "MULOP", "INT", "FLOAT", "VOID", "IF", "ELSE", "FOR", "WHILE",
  "PRINTLN", "RETURN", "LPAREN", "RPAREN", "LTHIRD", "RTHIRD", "LCURL",
  "RCURL", "COMMA", "STRUCT", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "parameter_list",
  "compound_statement", "var_declaration", "struct_declaration",
  "struct_defination", "type_specifier", "declaration_list", "statements",
  "statement", "embedded_exp", "embedded_void", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", "lcurl", YY_NULLPTR
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

#define YYPACT_NINF -94

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-94)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,   -94,   -94,   -94,    26,    15,     9,   -94,   -94,   -94,
     -94,   -94,    30,    22,   -94,   -94,    44,     6,    49,   104,
      40,   -94,    50,    43,    71,    10,    19,    75,    61,    67,
     -94,    82,   -94,   -94,   -94,    81,    13,    49,   -94,   -94,
     114,   -94,   -94,    55,   -94,    87,    87,    98,   100,   111,
     112,    87,    87,   -94,   132,   -94,   -94,   -94,   110,   -94,
     -94,   141,   134,   -94,   135,    94,   144,   -94,   -94,   -94,
     -94,   148,   122,    87,    87,    12,   -94,   -94,    87,    54,
      87,   159,   160,   140,    71,   -94,   -94,    87,   -94,   -94,
     -94,    87,    87,    87,    87,   -94,   -94,   -94,   143,   142,
     146,   -94,   -94,   -94,   149,   -94,   -94,     7,   -94,   -94,
     156,   144,   -94,   -94,    87,   -94,   150,   -94,   151,   165,
     -94,   -94,   -94,    54,   -94,   -94,   139,   -94,   139,   158,
     -94,   -94,   139,    87,   -94,   -94,   -94,   153,   139,   -94
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    22,    23,    24,     0,     0,     2,     4,     6,     7,
       5,     8,     0,     0,     1,     3,    27,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,    16,     0,    25,
      20,    27,    10,    71,    12,     0,     0,     0,    15,    28,
       0,    63,    64,    45,    43,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,    33,    31,    40,     0,    29,
      32,    60,     0,    47,    49,    51,    53,    55,    59,     9,
      11,    14,     0,    68,     0,    60,    58,    57,     0,     0,
       0,     0,     0,     0,     0,    17,    30,     0,    65,    66,
      44,     0,     0,     0,     0,    13,    26,    70,     0,    67,
       0,    41,    41,    41,     0,    39,    62,     0,    48,    50,
      52,    54,    56,    61,     0,    46,     0,    42,     0,     0,
      21,    69,    42,     0,    42,    38,     0,    41,     0,    35,
      42,    37,     0,     0,    36,    41,    42,     0,     0,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -94,   -94,   -94,   173,   -94,   -94,   -94,     3,    14,   -94,
     -94,    11,    96,   -94,   -55,   -93,   -61,   -77,   -40,   -51,
     -69,    90,    91,    89,   -38,   -94,   -94,   -94,   -94
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    26,    55,    56,    11,
      57,    24,    17,    58,    59,   116,   123,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    98,    99,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      82,    83,   102,    86,    97,    75,    75,    76,    77,   117,
     118,    12,    21,   120,    10,    14,    32,    12,   108,    69,
      10,    88,    89,   100,     1,     2,     3,   101,    34,   103,
      27,    13,    23,    75,   130,    16,    22,    22,    33,    70,
       4,    33,   136,    28,    36,   121,   127,    75,    71,    37,
      18,    75,    75,    75,    75,    29,   112,    41,    42,    43,
      44,   126,    45,   128,     1,     2,     3,    46,    19,   133,
      20,   129,    30,   131,    75,   137,    31,   134,    52,    73,
      38,    74,   135,   139,    41,    42,    43,    44,    39,    45,
      41,    42,    43,    40,    46,    45,     1,     2,     3,    47,
      46,    48,    49,    50,    51,    52,    92,    93,    20,    33,
      53,    52,    54,    41,    42,    43,    44,    72,    45,     1,
       2,     3,    78,    46,    79,     1,     2,     3,    47,    25,
      48,    49,    50,    51,    52,    80,    81,    84,    33,    85,
      90,    54,    41,    42,    43,    44,    91,    45,    87,    96,
      88,    89,    46,    95,     1,     2,     3,    47,    94,    48,
      49,    50,    51,    52,   104,   106,   105,    33,   113,    93,
      54,   125,   114,   115,   119,   122,   124,   132,   138,    15,
     107,   109,   111,   110
};

static const yytype_uint8 yycheck[] =
{
      51,    52,    79,    58,    73,    45,    46,    45,    46,   102,
     103,     0,     6,     6,     0,     0,     6,     6,    87,     6,
       6,     9,    10,    74,    15,    16,    17,    78,    25,    80,
      19,     5,    18,    73,   127,     5,    30,    30,    28,    36,
      31,    28,   135,     3,    25,   114,   123,    87,    37,    30,
      28,    91,    92,    93,    94,     5,    94,     3,     4,     5,
       6,   122,     8,   124,    15,    16,    17,    13,    24,   130,
      26,   126,    29,   128,   114,   136,     5,   132,    24,    24,
       5,    26,   133,   138,     3,     4,     5,     6,    27,     8,
       3,     4,     5,    26,    13,     8,    15,    16,    17,    18,
      13,    20,    21,    22,    23,    24,    12,    13,    26,    28,
      29,    24,    31,     3,     4,     5,     6,     3,     8,    15,
      16,    17,    24,    13,    24,    15,    16,    17,    18,    25,
      20,    21,    22,    23,    24,    24,    24,     5,    28,    29,
       6,    31,     3,     4,     5,     6,    11,     8,     7,    27,
       9,    10,    13,     5,    15,    16,    17,    18,    14,    20,
      21,    22,    23,    24,     5,    25,     6,    28,    25,    13,
      31,     6,    30,    27,    25,    25,    25,    19,    25,     6,
      84,    91,    93,    92
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    16,    17,    31,    33,    34,    35,    36,    37,
      40,    41,    43,     5,     0,    35,     5,    44,    28,    24,
      26,     6,    30,    40,    43,    25,    38,    43,     3,     5,
      29,     5,     6,    28,    39,    60,    25,    30,     5,    27,
      26,     3,     4,     5,     6,     8,    13,    18,    20,    21,
      22,    23,    24,    29,    31,    39,    40,    42,    45,    46,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     6,
      39,    43,     3,    24,    26,    50,    56,    56,    24,    24,
      24,    24,    51,    51,     5,    29,    46,     7,     9,    10,
       6,    11,    12,    13,    14,     5,    27,    52,    58,    59,
      51,    51,    49,    51,     5,     6,    25,    44,    52,    53,
      54,    55,    56,    25,    30,    27,    47,    47,    47,    25,
       6,    52,    25,    48,    25,     6,    48,    49,    48,    46,
      47,    46,    19,    48,    46,    51,    47,    48,    25,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    36,
      36,    37,    37,    38,    38,    38,    38,    39,    39,    40,
      41,    42,    43,    43,    43,    44,    44,    44,    44,    45,
      45,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    47,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    59,
      59,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     6,
       5,     6,     5,     4,     3,     2,     1,     3,     2,     3,
       5,     4,     1,     1,     1,     3,     6,     1,     4,     1,
       2,     1,     1,     1,    13,     7,     9,     7,     5,     3,
       1,     0,     0,     1,     2,     1,     4,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     2,     2,     1,
       1,     4,     3,     1,     1,     2,     2,     1,     0,     3,
       1,     1
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
#line 69 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("program","start");
	logout << "start : program" << endl;
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine= (yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	parseout<<(yyval.symbol)->printParseTree(1);
	logout<<"Total Lines: "<<line<<endl;
	logout<<"Total Errors: "<<errorCount<<endl;
}
#line 1391 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 82 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("program unit","program");
	(yyval.symbol)->startLine=(yyvsp[-1].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "program  : program unit " << endl;
}
#line 1405 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 91 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("unit","program");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "program  : unit " << endl;
}
#line 1418 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 102 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol) = new SymbolInfo("var_declaration","unit");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout<<"unit  : var_declaration "<<endl;
}
#line 1431 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 110 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol) = new SymbolInfo("func_declaration","unit");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "unit  : func_declaration " << endl;
}
#line 1444 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 118 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol) = new SymbolInfo("func_definition","unit");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "unit  : func_definition " << endl;
}
#line 1457 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol) = new SymbolInfo("struct_declaration","unit");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout<<"rrmfbher"<<endl;
}
#line 1469 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 136 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)= new SymbolInfo("type_specifier ID LPAREN parameter_list RPAREN SEMICOLON","func_declaration");
	(yyval.symbol)->startLine=(yyvsp[-5].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-5].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	for(int i=0;i<(yyvsp[-2].symbol)->paraList.size();i++){
		(yyvsp[-4].symbol)->paraList.push_back((yyvsp[-2].symbol)->paraList[i]);
	}

	(yyvsp[-4].symbol)->isDeclared=true;
	SymbolInfo newSymbol((yyvsp[-4].symbol)->getName(),(yyvsp[-4].symbol)->getType());
	table.insert(newSymbol);
	SymbolInfo * temp=table.lookUp((yyvsp[-4].symbol)->getName());
	temp->isDeclared=true;
	temp->type_specifier="FUNCTION";
	temp->retType=(yyvsp[-5].symbol)->type_specifier;
	temp->setFunction();
	for(int i=0;i<(yyvsp[-2].symbol)->paraList.size();i++){
		temp->paraList.push_back((yyvsp[-2].symbol)->paraList[i]);
	}
	
	pList.clear();
	logout << "func_declaration  : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON " << endl;
}
#line 1504 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 166 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("type_specifier ID LPAREN RPAREN SEMICOLON","func_declaration");
	(yyval.symbol)->startLine=(yyvsp[-4].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	(yyvsp[-3].symbol)->isDeclared=true; 
	SymbolInfo  newSymbol((yyvsp[-3].symbol)->getName(),(yyvsp[-3].symbol)->getType());
	table.insert(newSymbol);
	SymbolInfo* temp=table.lookUp((yyvsp[-3].symbol)->getName());
	temp->isDeclared=true;
	temp->type_specifier="FUNCTION";
	temp->retType=(yyvsp[-4].symbol)->type_specifier;
	temp->varType=(yyvsp[-4].symbol)->varType;
	temp->setFunction();
	pList.clear();
	
	logout << "func_declaration  : type_specifier ID LPAREN RPAREN SEMICOLON " << endl;
}
#line 1532 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 192 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("type_specifier ID LPAREN parameter_list RPAREN compound_statement","func_definition");
	(yyval.symbol)->startLine=(yyvsp[-5].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;

	(yyval.symbol)->child.push_back((yyvsp[-5].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	SymbolInfo* temp1=table.lookUp((yyvsp[-4].symbol)->getName());

	if(!temp1){
		SymbolInfo* sym= new SymbolInfo((yyvsp[-4].symbol)->getName(),(yyvsp[-5].symbol)->getType());

		for(int i=0;i<(yyvsp[-2].symbol)->paraList.size();i++){
			(yyvsp[-4].symbol)->paraList.push_back((yyvsp[-2].symbol)->paraList[i]);
			SymbolInfo newSymbol((yyvsp[-2].symbol)->paraList[i]->getName(),(yyvsp[-2].symbol)->paraList[i]->getType());
			// table.insert(newSymbol);
		}
		SymbolInfo newSymbol3(sym->getName(),sym->getType());
		table.insert(newSymbol3);
		SymbolInfo* temp=table.lookUp(sym->getName());

		for(int i=0;i<(yyvsp[-2].symbol)->paraList.size();i++){
			temp->paraList.push_back((yyvsp[-2].symbol)->paraList[i]);
		}

		temp->type_specifier="FUNCTION";
		temp->retType=(yyvsp[-5].symbol)->type_specifier;
		temp->varType=(yyvsp[-5].symbol)->varType;
		temp->setFunction();
	}else{
		SymbolInfo* temp =table.lookUp((yyvsp[-4].symbol)->getName());

		if(temp->isDefined || temp->isDeclared){
			if((yyvsp[-5].symbol)->varType!=temp->varType){
				errorout<<"Line# "<<(yyvsp[-4].symbol)->endLine<<": Conflicting types for '"<<(yyvsp[-4].symbol)->getName()<<"' "<<endl;
				errorCount++;
			}else if(temp1->paraList.size()>(yyvsp[-2].symbol)->paraList.size()){
				errorout<<"Line# "<<line<<": Too few arguments to function '"<<(yyvsp[-4].symbol)->getName()<<"' "<<endl;
				errorCount++;
			}
			else if(temp1->paraList.size()<(yyvsp[-2].symbol)->paraList.size()){
				errorout<<"Line# "<<line<<": Too many arguments to function '"<<(yyvsp[-4].symbol)->getName()<<"' "<<endl;
				errorCount++;
			}else{
				bool misMatch=false;

				for(int i=0;i<pList.size();i++){
					if(((yyvsp[-2].symbol)->paraList[i]->varType!= temp1->paraList[i]->varType)){
						errorout<<"Line# "<< line<<": Type mismatch for argument "<<(i+1)<<" of '"<<(yyvsp[-5].symbol)->getName()<<"' "<<endl;
						errorCount++;
						misMatch=true;	
					}
				}

				if(!misMatch){
					(yyvsp[-4].symbol)->isDefined=true; 
				}
			}

		}else{
			errorout<<"Line# "<<(yyvsp[-4].symbol)->startLine<<": '"<<(yyvsp[-4].symbol)->getName()<<"' redeclared as different kind of symbol "<<endl;
			errorCount++;
		}
	}

	pList.clear();
	logout << "func_definition  : type_specifier ID LPAREN parameter_list RPAREN compound_statement " << endl;
}
#line 1610 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 265 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("type_specifier ID LPAREN RPAREN compound_statement","func_definition");
	(yyval.symbol)->startLine=(yyvsp[-4].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	SymbolInfo* temp=table.lookUp((yyvsp[-3].symbol)->getName());

	if(!temp){
		SymbolInfo newSymbol4((yyvsp[-3].symbol)->getName(),(yyvsp[-4].symbol)->getType());
		table.insert(newSymbol4);
		SymbolInfo* temp1=table.lookUp(newSymbol4.getName());
		temp1->isDefined=true;
		temp1->type_specifier="FUNCTION";
		temp1->retType=(yyvsp[-4].symbol)->type_specifier;
		temp1->setFunction();
	}

	logout << "func_definition  : type_specifier ID LPAREN RPAREN compound_statement " << endl;
}
#line 1639 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 292 "2005104.y" /* yacc.c:1646  */
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
				errorout<<"Line# "<<line<<": Redefinition of parameter '"<<(yyvsp[-3].symbol)->paraList[i]->getName()<<"' "<<endl;
				errorCount++;
			}
		}
	}

	(yyval.symbol)->startLine=(yyvsp[-3].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "parameter_list  : parameter_list COMMA type_specifier ID " << endl;
}
#line 1678 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 326 "2005104.y" /* yacc.c:1646  */
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
	
	(yyval.symbol)->startLine=(yyvsp[-2].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "parameter_list  : parameter_list COMMA type_specifier " << endl;
}
#line 1704 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 347 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("type_specifier ID","parameter_list");
	param temp;
	temp.type=(yyvsp[-1].symbol)->varType;
	temp.name=(yyvsp[0].symbol)->getName();
	(yyvsp[0].symbol)->type_specifier=(yyvsp[-1].symbol)->type_specifier;

	pList.push_back(temp);

	(yyval.symbol)->paraList.push_back((yyvsp[0].symbol));

	(yyval.symbol)->startLine=(yyvsp[-1].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "parameter_list  : type_specifier ID " << endl;
}
#line 1727 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 365 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("type_specifier","parameter_list");

	param temp;
	temp.type=(yyvsp[0].symbol)->varType;
	temp.name="";

	pList.push_back(temp);
	SymbolInfo* sym=new SymbolInfo("","ID");
	sym->type_specifier=(yyvsp[0].symbol)->type_specifier;
	(yyval.symbol)->paraList.push_back(sym);

	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "parameter_list  : type_specifier " << endl;
}
#line 1750 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 386 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("LCURL statements RCURL","compound_statement");
	(yyval.symbol)->startLine=(yyvsp[-2].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "compound_statement  : LCURL statements RCURL " << endl;
	logout << table.printAllScopeTable();
	table.exitScope();
}
#line 1767 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 398 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("LCURL RCURL","compound_statement");
	(yyval.symbol)->startLine=(yyvsp[-1].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "compound_statement  : LCURL RCURL " << endl;	
	logout << table.printAllScopeTable();
	table.exitScope();
}
#line 1783 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 413 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("type_specifier declaration_list SEMICOLON","var_declaration");

	SymbolInfo* sym;
	if((yyvsp[-2].symbol)->varType=="void"){
		errorCount++;
		for(int i=0;i<vList.size();i++){
			sym=new SymbolInfo(vList[i].name,"ID");
			SymbolInfo* temp=table.lookUp(sym->getName());
			if(temp->isInserted)
				temp->varType=(yyvsp[-2].symbol)->varType;
				temp->type_specifier=(yyvsp[-2].symbol)->type_specifier;
			errorout<<"Line# "<<line<<": Variable or field '"<<vList[i].name<<"' declared void "<<endl;
		}
	}else{
		for(int i=0;i<vList.size();i++){
			SymbolInfo* temp=table.lookUp(vList[i].name);
			if((yyvsp[-2].symbol)->varType!= type ){
				errorout<<"Line# "<<line<<": Conflicting types for '"<<vList[i].name<<"' "<<endl;
			}
			if(temp->isInserted){
				temp->varType=(yyvsp[-2].symbol)->varType;
				temp->type_specifier=(yyvsp[-2].symbol)->type_specifier;
			}
		}
	}
	

	for(int i=0;i<(yyvsp[-1].symbol)->decList.size();i++){
		(yyvsp[-1].symbol)->decList[i]->varType=(yyvsp[-2].symbol)->varType;
		(yyvsp[-1].symbol)->decList[i]->type_specifier=(yyvsp[-2].symbol)->type_specifier;
	}

	vList.clear();

	(yyval.symbol)->startLine=(yyvsp[-2].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "var_declaration  : type_specifier declaration_list SEMICOLON " << endl;
}
#line 1831 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 458 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol) = new SymbolInfo("STRUCT ID LCURL var_declaration RCURL","struct_declaration");
	(yyval.symbol)->startLine=(yyvsp[-4].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
}
#line 1846 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 469 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol) = new SymbolInfo("STRUCT ID declaration_list SEMICOLON","struct_defination");
	(yyval.symbol)->startLine=(yyvsp[-3].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
}
#line 1860 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 479 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("INT","type_specifier");
	(yyval.symbol)->varType="int";
	(yyval.symbol)->type_specifier="INT";
	//type="int";
	type="int";
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "type_specifier : INT" << endl;
}
#line 1877 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 491 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("FLOAT","type_specifier");
	(yyval.symbol)->varType="float";
	(yyval.symbol)->type_specifier="FLOAT";
	type="float";
	
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "type_specifier : FLOAT" << endl;
}
#line 1894 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 503 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("VOID","type_specifier");
	(yyval.symbol)->varType="void";
	(yyval.symbol)->type_specifier="VOID";
	type="void";
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "type_specifier  : VOID " << endl;
}
#line 1910 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 517 "2005104.y" /* yacc.c:1646  */
    {
	string name=(yyvsp[0].symbol)->getName();
	(yyval.symbol)=new SymbolInfo("declaration_list COMMA ID","declaration_list");
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->startLine=(yyvsp[-2].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	for(int i=0;i<(yyvsp[-2].symbol)->decList.size();i++){
		(yyval.symbol)->decList.push_back((yyvsp[-2].symbol)->decList[i]);
	}
	(yyval.symbol)->decList.push_back((yyvsp[0].symbol));
	SymbolInfo newSymbol12((yyvsp[0].symbol)->getName(),(yyvsp[0].symbol)->getType());
	bool insertable=table.insert(newSymbol12);
	if(insertable){
		SymbolInfo* temp=table.lookUp((yyvsp[0].symbol)->getName());
		temp->arraySize=var.size;
		temp->isInserted=true;
		temp->varType=(yyvsp[-2].symbol)->decList[0]->varType;
		temp->type_specifier=(yyvsp[-2].symbol)->decList[0]->type_specifier;
		var.name=(string)(yyvsp[0].symbol)->getName();
		var.size=0;

		vList.push_back(var);
	}else{
		errorout<<"Line# "<<line<<": Redefinition of parameter '"<<(yyvsp[0].symbol)->getName()<<"' "<<endl;
		errorCount++;
	}
	logout << "declaration_list  : declaration_list COMMA ID " << endl;
}
#line 1945 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 547 "2005104.y" /* yacc.c:1646  */
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
	bool insertable=table.insert(newSymbol);
	arrayInsertable=insertable;

	if(insertable){
		SymbolInfo* temp=table.lookUp((yyvsp[-3].symbol)->getName());
		
		if((yyvsp[-1].symbol)->varType=="float")
		{
			errorout<<"Error at line# "<<line<<": array size cannot be float '"<<(yyvsp[-3].symbol)->getType()<<"' "<<endl;
		}
		else{
			(yyvsp[-3].symbol)->arraySize=stoi((yyvsp[-1].symbol)->getName());
		}

		vList.push_back(var);
		temp->arraySize=var.size;
		temp->varType=(yyvsp[-5].symbol)->varType;
		temp->type_specifier="ARRAY";
		temp->isInserted=true;
	}else{
		errorout<<"Line# "<<line<<": Conflicting types for'"<<(yyvsp[-3].symbol)->getName()<<"' "<<endl;
		errorCount++;
	}

	arraySize=var.size;
	(yyval.symbol)->startLine=(yyvsp[-5].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-5].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "declaration_list  : declaration_list COMMA ID LSQUARE CONST_INT RSQUARE " << endl;
}
#line 1998 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 595 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("ID","declaration_list");
	(yyval.symbol)->decList.push_back((yyvsp[0].symbol));
	SymbolInfo newSymbol((yyvsp[0].symbol)->getName(),(yyvsp[0].symbol)->getType());
	bool insertable=table.insert(newSymbol);

	
	if(insertable){
		SymbolInfo* temp=table.lookUp((yyvsp[0].symbol)->getName());
		temp->arraySize=var.size;
		temp->isInserted=true;

		var.name=(string)(yyvsp[0].symbol)->getName();
		var.size=0;

		vList.push_back(var);
	}
	else{
		errorout<<"Line# "<<line<<": Conflicting types for'"<<(yyvsp[0].symbol)->getName()<<"' "<<endl;
		errorCount++;
	}

	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "declaration_list  : ID " << endl;
}
#line 2031 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 623 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("ID LTHIRD CONST_INT RTHIRD ","declaration_list");

	if((yyvsp[-1].symbol)->varType=="float"){
		errorout<<"Line# "<<line<<": array size cannot be float '"<<(yyvsp[-1].symbol)->getType()<<"' "<<endl;
		errorCount++;
	}

	(yyvsp[-3].symbol)->arraySize=stoi((yyvsp[-1].symbol)->getName());
	(yyval.symbol)->decList.push_back((yyvsp[-3].symbol));
	arraySize=var.size;
	SymbolInfo newSymbol15((yyvsp[-3].symbol)->getName(),(yyvsp[-3].symbol)->getType());
	bool insertable=table.insert(newSymbol15);
	arrayInsertable=insertable;
	if(insertable){
		SymbolInfo* temp=table.lookUp((yyvsp[-3].symbol)->getName());
		var.name=(string)(yyvsp[-3].symbol)->getName();
		var.size=stoi((yyvsp[-1].symbol)->getName());
		vList.push_back(var);
		temp->arraySize=var.size;
		temp->isInserted=true;
		temp->type_specifier="ARRAY";
	}else{
		errorout<<"Line# "<<line<<": Conflicting types for'"<<(yyvsp[-3].symbol)->getName()<<"' "<<endl;
		errorCount++;
	}
	arraySize=var.size;
	(yyval.symbol)->startLine=(yyvsp[-3].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "declaration_list  : ID LSQUARE CONST_INT RSQUARE " << endl;
}
#line 2071 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 661 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("statement","statements");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statements : statement" << endl;
}
#line 2083 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 668 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("statements statement","statements");
	(yyval.symbol)->startLine=(yyvsp[-1].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statements  : statements statement " << endl;
}
#line 2096 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 679 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("var_declaration","statement");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statement  : var_declaration " << endl;
}
#line 2108 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 686 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("expression_statement","statement");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statement  : expression_statement " << endl;
}
#line 2120 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 693 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("compound_statement","statement");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statement  : compound_statement " << endl;
}
#line 2132 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 700 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("FOR LPAREN expression_statement expression RPAREN statement","statement");
	(yyval.symbol)->startLine=(yyvsp[-12].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-12].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-11].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-10].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-7].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statement  : FOR LPAREN expression_statement expression_statement expression RPAREN statement " << endl;
}
#line 2150 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 713 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("IF LPAREN expression RPAREN statement","statement");
	(yyval.symbol)->startLine=(yyvsp[-6].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-6].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-5].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statement  : IF LPAREN expression RPAREN statement " << endl;
}
#line 2166 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 724 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("IF LPAREN expression RPAREN statement ELSE statement","statement");
	(yyval.symbol)->startLine=(yyvsp[-8].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-8].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-7].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-6].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
		
	logout << "statement  : IF LPAREN expression RPAREN statement ELSE statement " << endl;
}
#line 2185 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 738 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("WHILE LPAREN expression RPAREN statement","statement");
	(yyval.symbol)->startLine=(yyvsp[-6].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-6].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-5].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	logout << "statement  : WHILE LPAREN expression RPAREN statement " << endl;
}
#line 2201 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 749 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("PRINTLN LPAREN ID RPAREN SEMICOLON","statement");
	(yyval.symbol)->startLine=(yyvsp[-4].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-4].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statement  : PRINTLN LPAREN ID RPAREN SEMICOLON ";
}
#line 2217 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 760 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("RETURN expression SEMICOLON","statement");
	(yyval.symbol)->startLine=(yyvsp[-2].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;	
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statement  : RETURN expression SEMICOLON " << endl;
}
#line 2231 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 769 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("struct_defination","statement");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;	
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	//$$->child.push_back($2);
}
#line 2243 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 778 "2005104.y" /* yacc.c:1646  */
    {
	 type_final=type;
}
#line 2251 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 782 "2005104.y" /* yacc.c:1646  */
    {
	if(type_final=="void"){
		errorout<<"Line# "<<line<<": void function called within expression "<<endl;
		errorCount++;
	}
}
#line 2262 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 789 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("SEMICOLON","expression_statement");
	(yyval.symbol)->varType="int";
	type="int";
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;	
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "expression_statement  : SEMICOLON " << endl;
}
#line 2277 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 799 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("expression SEMICOLON","expression_statement");
	(yyval.symbol)->varType=(yyvsp[-1].symbol)->varType;//why?
	type=(yyvsp[-1].symbol)->varType;//why?
	(yyval.symbol)->startLine=(yyvsp[-1].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[-1].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "expression_statement  : expression SEMICOLON " << endl;
}
#line 2292 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 812 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("ID","variable");
	SymbolInfo* temp=table.lookUp((yyvsp[0].symbol)->getName());
	if(!temp){
		errorout<<"Line# "<<line<<": Undeclared variable '"<<(yyvsp[0].symbol)->getName()<<"' "<<endl;
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

	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "variable  : ID " << endl;
}
#line 2318 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 833 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("ID LTHIRD expression RTHIRD","variable");
	SymbolInfo* temp=table.lookUp((yyvsp[-3].symbol)->getName());
	
	if(!temp){
		errorout<<"Line# "<<line<<": undeclared variable '"<<(yyvsp[-3].symbol)->getName()<<"' "<<endl;
		errorCount++;
		(yyval.symbol)->varType="float";
	}else if(temp->arraySize==0){
		errorout<<"Line# "<<line<<": '"<<(yyvsp[-3].symbol)->getName()<<"' is not an array "<<endl;
		errorCount++;
	}else{
		(yyval.symbol)->varType=temp->varType;
		(yyvsp[-3].symbol)->type_specifier="ARRAY";
		(yyval.symbol)->arraySize=(yyvsp[-1].symbol)->arraySize;
		if((yyvsp[-3].symbol)->varType!="void"){
			(yyval.symbol)->varType=(yyvsp[-3].symbol)->varType;
		}else{
			(yyval.symbol)->varType="float";
		}	
	}

	if((yyvsp[-1].symbol)->varType!="int"){
		errorout<<"Line# "<<line<<": Array subscript is not an integer "<<endl;
		errorCount++;
	}
	(yyval.symbol)->startLine=(yyvsp[-3].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "variable  : ID LSQUARE expression RSQUARE " << endl;
}
#line 2357 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 870 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("logic_expression","expression");
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	type=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "expression  : logic_expression " << endl;
}
#line 2371 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 879 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("variable ASSIGNOP logic_expression","expression");
	
	if((yyvsp[-2].symbol)->varType=="float" && type=="int"){
		(yyvsp[0].symbol)->varType="float";
	}else if((yyvsp[-2].symbol)->varType=="void" || (yyvsp[0].symbol)->varType=="void"){
		errorout<<"Line# "<<line<<": Void cannot be used in expression  "<<endl;
		errorCount++;
	}else if((yyvsp[0].symbol)->varType=="float" && (yyvsp[-2].symbol)->varType=="int"){
		errorout<<"Line# "<<line<<": Warning: possible loss of data in assignment of FLOAT to INT "<<endl;
		errorCount++;
	}else {
		(yyval.symbol)->varType=(yyvsp[-2].symbol)->varType;
		type=(yyvsp[-2].symbol)->varType;
	}
	(yyval.symbol)->startLine=(yyvsp[-2].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "expression  : variable ASSIGNOP logic_expression " << endl;
}
#line 2399 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 905 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("rel_expression","logic_expression");

	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;

	logout << "logic_expression  : rel_expression " << endl;
}
#line 2415 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 916 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("rel_expression LOGICOP rel_expression","logic_expression");
	(yyval.symbol)->varType="int";
	(yyval.symbol)->startLine=(yyvsp[-2].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "logic_expression  : rel_expression LOGICOP rel_expression " << endl;
}
#line 2430 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 929 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("simple_expression","rel_expression");	
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;
	logout << "rel_expression  : simple_expression " << endl;
}
#line 2444 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 938 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("simple_expression RELOP simple_expression","rel_expression");
	(yyval.symbol)->varType="int";
	(yyval.symbol)->startLine=(yyvsp[-2].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "rel_expression  : simple_expression RELOP simple_expression " << endl;
}
#line 2459 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 951 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("term","simple_expression");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;
	logout << "simple_expression  : term " << endl;
}
#line 2473 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 960 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("simple_expression ADDOP term","simple_expression");

	if((yyvsp[-2].symbol)->varType=="void" || (yyvsp[0].symbol)->varType=="void"){
		errorout<<"Line# "<<line<<": Void function cannot be called in argument of function  "<<endl;;
	}else if((yyvsp[-2].symbol)->varType=="float" || (yyvsp[0].symbol)->varType=="float"){
		(yyval.symbol)->varType="float";
	}else {
		(yyval.symbol)->varType=(yyvsp[-2].symbol)->varType;
	}

	(yyval.symbol)->startLine=(yyvsp[-2].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
					
	logout << "simple_expression  : simple_expression ADDOP term " << endl;
}
#line 2497 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 982 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("unary_expression","term");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;
	logout << "term  : unary_expression " << endl;
}
#line 2511 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 991 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("term MULOP unary_expression","term");


	if((yyvsp[-2].symbol)->varType=="void" || (yyvsp[0].symbol)->varType=="void"){
		errorout<<"Line# "<<line<<": Void cannot be used in expression "<<endl;
		errorCount++;
	}else if(((yyvsp[-1].symbol)->getName()=="%"|| (yyvsp[-1].symbol)->getName()=="/") && !value){
		errorout<<"Line# "<<line<<": Warning: division by zero i=0f=1Const=0 "<<endl;
		errorCount++;
		(yyval.symbol)->varType="int";
	}else if((yyvsp[-1].symbol)->getName()=="%" && ((yyvsp[-2].symbol)->varType!="int" || (yyvsp[0].symbol)->varType!="int")){
		errorout<<"Line# "<<line<<": Operands of modulus must be integers  "<<endl;
		errorCount++;
		(yyval.symbol)->varType="int";
	}else if((yyvsp[-1].symbol)->getName()!="%" && ((yyvsp[-2].symbol)->varType=="float" || (yyvsp[0].symbol)->varType=="float")) {
		(yyval.symbol)->varType="float";
	}else{
		(yyval.symbol)->varType=(yyvsp[-2].symbol)->varType;
	}

	(yyval.symbol)->startLine=(yyvsp[-2].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "term  : term MULOP unary_expression " << endl;
}
#line 2545 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1023 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("ADDOP unary_expression","unary_expression");
	(yyval.symbol)->startLine=(yyvsp[-1].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	if((yyvsp[0].symbol)->varType=="void"){
		errorout<<"Line# "<<line<<": Void cannot be used in expression "<<endl;
		errorCount++;
	}
	(yyval.symbol)->varType="int";
	logout << "unary_expression  : ADDOP unary_expression " << endl;
}
#line 2563 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1036 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("NOT unary_expression","unary_expression");
	(yyval.symbol)->startLine=(yyvsp[-1].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType="int";
	logout << "unary_expression  : NOT unary_expression " << endl;
}
#line 2577 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1045 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("factor","unary_expression");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;

	logout << "unary_expression  : factor " << endl;
}
#line 2592 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1057 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("variable","factor");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;
	logout << "factor  : variable " << endl;
}
#line 2606 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1066 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("ID LPAREN argument_list RPAREN","factor");
	SymbolInfo* si=table.lookUp((yyvsp[-3].symbol)->getName());
	argList.clear();
	(yyval.symbol)->startLine=(yyvsp[-3].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-3].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	SymbolInfo* temp=table.lookUp((yyvsp[-3].symbol)->getName());

	if(!temp){
		errorout<<"Line# "<<line<<": Undeclared function '"<<(yyvsp[-3].symbol)->getName()<<"' "<<endl;
		errorCount++;
		(yyval.symbol)->varType="empty";
	}else{
		(yyval.symbol)->varType=temp->varType;
		if(temp->varType=="void"){
			(yyval.symbol)->varType="void";
		}else if((yyvsp[-1].symbol)->argList.size()<temp->paraList.size()){
			errorout<<"Line# "<<(yyvsp[-2].symbol)->startLine<<": Too few arguments to function '"<<(yyvsp[-3].symbol)->getName()<<"' "<<endl;
			errorCount++;
		}else if((yyvsp[-1].symbol)->argList.size()>temp->paraList.size()){
			errorout<<"Line# "<<(yyvsp[-2].symbol)->startLine<<": Too many arguments to function '"<<(yyvsp[-3].symbol)->getName()<<"' "<<endl;
			errorCount++;
		}else {
			for(int i=0;i<temp->paraList.size();i++){
				if(((yyvsp[-1].symbol)->argList[i]->varType!= temp->paraList[i]->varType) ){
					// errorout<<"Line# "<<$1->startLine<<": Type mismatch for argument "<<(i+1)<<" of '"<<$1->getName()<<"' "<<endl;
					// errorCount++;
				}
			}
		}
	}
	logout << "factor  : ID LPAREN argument_list RPAREN " << endl;
}
#line 2649 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1104 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("LPAREN expression RPAREN","factor");
	SymbolInfo* temp=table.lookUp((yyvsp[-2].symbol)->getName());
	(yyval.symbol)->startLine=(yyvsp[-2].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	//$2->varType="float";
	(yyval.symbol)->varType=(yyvsp[-1].symbol)->varType;
	logout << "factor  : LPAREN expression RPAREN " << endl;
}
#line 2667 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1117 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("CONST_INT","factor");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType="int";
	value=stoi((yyvsp[0].symbol)->getName());
	logout << "factor  : CONST_INT " << endl;
}
#line 2681 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1126 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("CONST_FLOAT","factor");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType="float";
	logout << "factor  : CONST_FLOAT " << endl;
}
#line 2694 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1134 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("variable INCOP","factor");
	(yyval.symbol)->varType=(yyvsp[-1].symbol)->varType;
	(yyval.symbol)->startLine=(yyvsp[-1].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "factor  : variable INCOP " << endl;
}
#line 2708 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1143 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("variable DECOP","factor");
	(yyval.symbol)->varType=(yyvsp[-1].symbol)->varType;
	(yyval.symbol)->startLine=(yyvsp[-1].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "factor  : variable DECOP " << endl;
}
#line 2722 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1154 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("arguments","argument_list");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	for(int i=0;i<(yyvsp[0].symbol)->argList.size();i++){
		(yyval.symbol)->argList.push_back((yyvsp[0].symbol)->argList[i]);		
	}
	logout << "argument_list  : arguments " << endl;
}
#line 2738 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1165 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("","argument_list");
	(yyval.symbol)->startLine=line;
	(yyval.symbol)->endLine=line;
	logout << "argument_list  :  " << endl;
}
#line 2749 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1174 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("arguments COMMA logic_expression ","arguments");
	
	if((yyvsp[0].symbol)->varType=="void"){
		errorout<<"Line# "<<line<<": Void function cannot be called in argument of function  "<<endl;;
		errorCount++;
		(yyvsp[0].symbol)->varType="float";
	}

	(yyval.symbol)->startLine=(yyvsp[-2].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	for(int i=0;i<(yyvsp[-2].symbol)->argList.size();i++){
		(yyval.symbol)->argList.push_back((yyvsp[-2].symbol)->argList[i]);
	}
	(yyval.symbol)->argList.push_back((yyvsp[0].symbol));

	logout << "arguments  : arguments COMMA logic_expression " << endl;
}
#line 2775 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1195 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol)=new SymbolInfo("logic_expression","arguments");
	if((yyvsp[0].symbol)->varType=="void"){
		errorout<<"Line# "<<line<<": Void function cannot be called in argument of function "<<endl;
		errorCount++;
		(yyvsp[0].symbol)->varType="float";
	}
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	argList.push_back((yyvsp[0].symbol));
	(yyval.symbol)->argList.push_back((yyvsp[0].symbol));
	logout << "arguments  : logic_expression " << endl;
}
#line 2794 "2005104.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1211 "2005104.y" /* yacc.c:1646  */
    {
	(yyval.symbol) = (yyvsp[0].symbol);
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	table.enterScope();
	for(int i=0;i<pList.size();i++){
		if(pList[i].name!=""){
			if(pList[i].name=="void"){

			}else{
				SymbolInfo  newSymbol6(pList[i].name,pList[i].type);
				table.insert(newSymbol6);
				SymbolInfo* temp=table.lookUp(pList[i].name);
				temp->varType=pList[i].type;
			}
		}
	}
	pList.clear();
	// $$->child.push_back($1);
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;		
}
#line 2821 "2005104.tab.c" /* yacc.c:1646  */
    break;


#line 2825 "2005104.tab.c" /* yacc.c:1646  */
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
#line 1235 "2005104.y" /* yacc.c:1906  */

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
