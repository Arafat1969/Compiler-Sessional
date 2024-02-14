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
#line 1 "2005104.y"

	#include<bits/stdc++.h> 
	#include<cstdio>
	#include<cstdlib>
	#include<iostream>
	#include<fstream>
	#include<string>
	#include "2005104_SymbolTable.h"
	using namespace std;

	ofstream logout("log.txt"), parseout("parsetree.txt"),errorout("error.txt");
	ofstream assemble("code.asm");
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
	bool is_global=true;
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

	void unit(SymbolInfo* sym){
		if(sym->child[0]->getType()=="var_declaration"){
			//var_declaration(sym->child[0]);
		}else if(sym->child[0]->getType()=="func_declaration"){
			
		}else{

		}
	}

	void program(SymbolInfo* sym){
		if(sym->child.size()==2){
			program(sym->child[0]);
			unit(sym->child[1]);
		}else{
			unit(sym->child[0]);
		}
	}

	void start(SymbolInfo* sym){
		assemble<<".MODEL SMALL"<<endl;
		assemble<<".STACK 1000H"<<endl;
		assemble<<".DATA"<<endl;
		assemble<<"\tnumber DB \"00000$\""<<endl;
		program(sym->child[0]);
	}
	void printNewLine(){
		assemble<<"new_line proc\n\tpush ax\n\tpush dx\n\tmov ah,2\n\tmov dl,0Dh\n\tint 21h\n\tmov ah,2\n\tmov dl,0Ah\n\tint 21h\n\tpop dx\n\tpop ax\n\tret\nnew_line endp"<<endl;
	}
	void printOutput(){
		assemble<<"print_output proc  ;print what is in ax\n\tpush ax\n\tpush bx\n\tpush cx\n\tpush dx\n\tpush si\n\tlea si,number\n\tmov bx,10\n\tadd si,4\n\tcmp ax,0\n\tjnge negate\nprint:\n\txor dx,dx\n\tdiv bx\n\tmov [si],dl\n\tadd [si],'0'\n\tdec si\n\tcmp ax,0\n\tjne print\n\tinc si\n\tlea dx,si\n\tmov ah,9\n\tint 21h\n\tpop si\n\tpop dx\n\tpop cx\n\tpop bx\n\tpop ax\n\tret\nnegate:\n\tpush ax\n\tmov ah,2\n\tmov dl,'-'\n\tint 21h\n\tpop ax\n\tneg ax\n\tjmp print\nprint_output endp"<<endl;
	}

#line 148 "2005104.tab.c"

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

#include "2005104.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONST_INT = 3,                  /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 4,                /* CONST_FLOAT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_SEMICOLON = 6,                  /* SEMICOLON  */
  YYSYMBOL_ASSIGNOP = 7,                   /* ASSIGNOP  */
  YYSYMBOL_NOT = 8,                        /* NOT  */
  YYSYMBOL_INCOP = 9,                      /* INCOP  */
  YYSYMBOL_DECOP = 10,                     /* DECOP  */
  YYSYMBOL_LOGICOP = 11,                   /* LOGICOP  */
  YYSYMBOL_RELOP = 12,                     /* RELOP  */
  YYSYMBOL_ADDOP = 13,                     /* ADDOP  */
  YYSYMBOL_MULOP = 14,                     /* MULOP  */
  YYSYMBOL_INT = 15,                       /* INT  */
  YYSYMBOL_FLOAT = 16,                     /* FLOAT  */
  YYSYMBOL_VOID = 17,                      /* VOID  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_FOR = 20,                       /* FOR  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_PRINTLN = 22,                   /* PRINTLN  */
  YYSYMBOL_RETURN = 23,                    /* RETURN  */
  YYSYMBOL_LPAREN = 24,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 25,                    /* RPAREN  */
  YYSYMBOL_LTHIRD = 26,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 27,                    /* RTHIRD  */
  YYSYMBOL_LCURL = 28,                     /* LCURL  */
  YYSYMBOL_RCURL = 29,                     /* RCURL  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_start = 32,                     /* start  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_unit = 34,                      /* unit  */
  YYSYMBOL_func_declaration = 35,          /* func_declaration  */
  YYSYMBOL_func_definition = 36,           /* func_definition  */
  YYSYMBOL_parameter_list = 37,            /* parameter_list  */
  YYSYMBOL_compound_statement = 38,        /* compound_statement  */
  YYSYMBOL_var_declaration = 39,           /* var_declaration  */
  YYSYMBOL_type_specifier = 40,            /* type_specifier  */
  YYSYMBOL_declaration_list = 41,          /* declaration_list  */
  YYSYMBOL_statements = 42,                /* statements  */
  YYSYMBOL_statement = 43,                 /* statement  */
  YYSYMBOL_embedded_exp = 44,              /* embedded_exp  */
  YYSYMBOL_embedded_void = 45,             /* embedded_void  */
  YYSYMBOL_expression_statement = 46,      /* expression_statement  */
  YYSYMBOL_variable = 47,                  /* variable  */
  YYSYMBOL_expression = 48,                /* expression  */
  YYSYMBOL_logic_expression = 49,          /* logic_expression  */
  YYSYMBOL_rel_expression = 50,            /* rel_expression  */
  YYSYMBOL_simple_expression = 51,         /* simple_expression  */
  YYSYMBOL_term = 52,                      /* term  */
  YYSYMBOL_unary_expression = 53,          /* unary_expression  */
  YYSYMBOL_factor = 54,                    /* factor  */
  YYSYMBOL_argument_list = 55,             /* argument_list  */
  YYSYMBOL_arguments = 56,                 /* arguments  */
  YYSYMBOL_lcurl = 57                      /* lcurl  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   104,   104,   121,   130,   141,   149,   157,   168,   198,
     224,   297,   324,   358,   379,   397,   418,   430,   444,   490,
     502,   514,   528,   558,   606,   633,   671,   678,   689,   696,
     703,   710,   723,   734,   748,   759,   770,   781,   785,   792,
     802,   815,   836,   873,   882,   912,   923,   936,   945,   958,
     967,   989,   998,  1030,  1043,  1052,  1064,  1073,  1111,  1124,
    1133,  1141,  1150,  1161,  1172,  1181,  1202,  1218
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
  "\"end of file\"", "error", "\"invalid token\"", "CONST_INT",
  "CONST_FLOAT", "ID", "SEMICOLON", "ASSIGNOP", "NOT", "INCOP", "DECOP",
  "LOGICOP", "RELOP", "ADDOP", "MULOP", "INT", "FLOAT", "VOID", "IF",
  "ELSE", "FOR", "WHILE", "PRINTLN", "RETURN", "LPAREN", "RPAREN",
  "LTHIRD", "RTHIRD", "LCURL", "RCURL", "COMMA", "$accept", "start",
  "program", "unit", "func_declaration", "func_definition",
  "parameter_list", "compound_statement", "var_declaration",
  "type_specifier", "declaration_list", "statements", "statement",
  "embedded_exp", "embedded_void", "expression_statement", "variable",
  "expression", "logic_expression", "rel_expression", "simple_expression",
  "term", "unary_expression", "factor", "argument_list", "arguments",
  "lcurl", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-87)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,   -87,   -87,   -87,    14,    31,   -87,   -87,   -87,   -87,
      64,   -87,   -87,    18,     6,    47,    70,   -87,    80,    10,
       4,    82,    48,    62,   -87,   -87,   -87,    78,    13,    31,
     -87,   -87,    86,   -87,   -87,    35,   -87,   138,   138,    66,
      73,    79,    81,   138,   138,   -87,   -87,   -87,    87,   105,
     -87,   -87,    11,    98,   -87,   101,    54,   100,   -87,   -87,
     -87,   -87,   110,    89,   138,   138,    68,   -87,   -87,   138,
      52,   138,   112,   113,    99,   104,   -87,   -87,   138,   -87,
     -87,   -87,   138,   138,   138,   138,   -87,   -87,   -87,   106,
     102,   117,   -87,   -87,   -87,   114,   -87,   -87,   -87,   -87,
     144,   100,   -87,   -87,   138,   -87,   133,   -87,   134,   155,
     -87,   -87,    52,   -87,   -87,   132,   -87,   132,   145,   -87,
     -87,   132,   138,   -87,   -87,   -87,   140,   132,   -87
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    19,    20,    21,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    24,     0,     0,     0,    18,     0,     0,
       0,    15,     0,    22,     9,    67,    11,     0,     0,     0,
      14,    25,     0,    59,    60,    41,    39,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    30,    28,     0,     0,
      26,    29,    56,     0,    43,    45,    47,    49,    51,    55,
       8,    10,    13,     0,    64,     0,    56,    54,    53,     0,
       0,     0,     0,     0,     0,    24,    16,    27,     0,    61,
      62,    40,     0,     0,     0,     0,    12,    23,    66,     0,
      63,     0,    37,    37,    37,     0,    36,    58,    44,    46,
      48,    50,    52,    57,     0,    42,     0,    38,     0,     0,
      65,    38,     0,    38,    35,     0,    37,     0,    32,    38,
      34,     0,     0,    33,    37,    38,     0,     0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   158,   -87,   -87,   -87,    -4,    30,     8,
     -87,   -87,   -47,   -84,   -86,   -59,   -33,   -43,   -61,    84,
      85,    83,   -31,   -87,   -87,   -87,   -87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    20,    46,    47,    48,
      14,    49,    50,   106,   112,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    89,    90,    27
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      73,    74,    77,    88,    66,    66,    67,    68,    10,   107,
     108,    93,    17,    10,    11,    26,    24,    98,    78,    60,
      79,    80,    91,    21,    61,   115,    92,   117,    94,    28,
       9,    66,   119,   122,    29,     9,    18,    62,    25,   126,
     125,    25,    15,   110,    16,    66,     1,     2,     3,    66,
      66,    66,    66,   116,   102,    33,    34,    35,    36,    64,
      37,    65,     1,     2,     3,    38,    83,    84,   118,    13,
     120,    66,    19,    22,   123,    31,    44,    79,    80,   124,
     128,    33,    34,    35,    36,    23,    37,    30,    32,    63,
      69,    38,    75,     1,     2,     3,    39,    70,    40,    41,
      42,    43,    44,    71,    81,    72,    25,    45,    33,    34,
      35,    36,    82,    37,    85,    86,    87,    95,    38,    96,
       1,     2,     3,    39,    97,    40,    41,    42,    43,    44,
      16,   103,   104,    25,    76,    33,    34,    35,    36,   109,
      37,    33,    34,    35,   105,    38,    37,     1,     2,     3,
      39,    38,    40,    41,    42,    43,    44,    84,   111,   113,
      25,   114,    44,    12,   121,   127,    99,   101,   100
};

static const yytype_int8 yycheck[] =
{
      43,    44,    49,    64,    37,    38,    37,    38,     0,    93,
      94,    70,     6,     5,     0,    19,     6,    78,     7,     6,
       9,    10,    65,    15,    28,   111,    69,   113,    71,    25,
       0,    64,   116,   119,    30,     5,    30,    29,    28,   125,
     124,    28,    24,   104,    26,    78,    15,    16,    17,    82,
      83,    84,    85,   112,    85,     3,     4,     5,     6,    24,
       8,    26,    15,    16,    17,    13,    12,    13,   115,     5,
     117,   104,    25,     3,   121,    27,    24,     9,    10,   122,
     127,     3,     4,     5,     6,     5,     8,     5,    26,     3,
      24,    13,     5,    15,    16,    17,    18,    24,    20,    21,
      22,    23,    24,    24,     6,    24,    28,    29,     3,     4,
       5,     6,    11,     8,    14,     5,    27,     5,    13,     6,
      15,    16,    17,    18,    25,    20,    21,    22,    23,    24,
      26,    25,    30,    28,    29,     3,     4,     5,     6,    25,
       8,     3,     4,     5,    27,    13,     8,    15,    16,    17,
      18,    13,    20,    21,    22,    23,    24,    13,    25,    25,
      28,     6,    24,     5,    19,    25,    82,    84,    83
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    16,    17,    32,    33,    34,    35,    36,    39,
      40,     0,    34,     5,    41,    24,    26,     6,    30,    25,
      37,    40,     3,     5,     6,    28,    38,    57,    25,    30,
       5,    27,    26,     3,     4,     5,     6,     8,    13,    18,
      20,    21,    22,    23,    24,    29,    38,    39,    40,    42,
      43,    46,    47,    48,    49,    50,    51,    52,    53,    54,
       6,    38,    40,     3,    24,    26,    47,    53,    53,    24,
      24,    24,    24,    48,    48,     5,    29,    43,     7,     9,
      10,     6,    11,    12,    13,    14,     5,    27,    49,    55,
      56,    48,    48,    46,    48,     5,     6,    25,    49,    50,
      51,    52,    53,    25,    30,    27,    44,    44,    44,    25,
      49,    25,    45,    25,     6,    45,    46,    45,    43,    44,
      43,    19,    45,    43,    48,    44,    45,    25,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    34,    35,    35,
      36,    36,    37,    37,    37,    37,    38,    38,    39,    40,
      40,    40,    41,    41,    41,    41,    42,    42,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    44,    45,    46,
      46,    47,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    55,    55,    56,    56,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     5,     4,     3,     2,     1,     3,     2,     3,     1,
       1,     1,     3,     6,     1,     4,     1,     2,     1,     1,
       1,    13,     7,     9,     7,     5,     3,     0,     0,     1,
       2,     1,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     2,     1,     1,     4,     3,     1,
       1,     2,     2,     1,     0,     3,     1,     1
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
  case 2: /* start: program  */
#line 104 "2005104.y"
                {
	(yyval.symbol)=new SymbolInfo("program","start");
	logout << "start : program" << endl;
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine= (yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	parseout<<(yyval.symbol)->printParseTree(1);
	start((yyval.symbol));
	printOutput();
	printNewLine();
	assemble<<"END main"<<endl;
	logout<<"Total Lines: "<<line<<endl;
	logout<<"Total Errors: "<<errorCount<<endl;
}
#line 1294 "2005104.tab.c"
    break;

  case 3: /* program: program unit  */
#line 121 "2005104.y"
                       {
	(yyval.symbol)=new SymbolInfo("program unit","program");
	(yyval.symbol)->startLine=(yyvsp[-1].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "program  : program unit " << endl;
}
#line 1308 "2005104.tab.c"
    break;

  case 4: /* program: unit  */
#line 130 "2005104.y"
       {
	(yyval.symbol)=new SymbolInfo("unit","program");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "program  : unit " << endl;
}
#line 1321 "2005104.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 141 "2005104.y"
                       {
	(yyval.symbol) = new SymbolInfo("var_declaration","unit");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout<<"unit  : var_declaration "<<endl;
}
#line 1334 "2005104.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 149 "2005104.y"
                   {
	(yyval.symbol) = new SymbolInfo("func_declaration","unit");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "unit  : func_declaration " << endl;
}
#line 1347 "2005104.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 157 "2005104.y"
                  {
	(yyval.symbol) = new SymbolInfo("func_definition","unit");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "unit  : func_definition " << endl;
}
#line 1360 "2005104.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 168 "2005104.y"
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
#line 1395 "2005104.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 198 "2005104.y"
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
#line 1423 "2005104.tab.c"
    break;

  case 10: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement  */
#line 224 "2005104.y"
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
#line 1501 "2005104.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID LPAREN RPAREN compound_statement  */
#line 297 "2005104.y"
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
#line 1530 "2005104.tab.c"
    break;

  case 12: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 324 "2005104.y"
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
#line 1569 "2005104.tab.c"
    break;

  case 13: /* parameter_list: parameter_list COMMA type_specifier  */
#line 358 "2005104.y"
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
#line 1595 "2005104.tab.c"
    break;

  case 14: /* parameter_list: type_specifier ID  */
#line 379 "2005104.y"
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
#line 1618 "2005104.tab.c"
    break;

  case 15: /* parameter_list: type_specifier  */
#line 397 "2005104.y"
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
#line 1641 "2005104.tab.c"
    break;

  case 16: /* compound_statement: lcurl statements RCURL  */
#line 418 "2005104.y"
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
#line 1658 "2005104.tab.c"
    break;

  case 17: /* compound_statement: lcurl RCURL  */
#line 430 "2005104.y"
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
#line 1674 "2005104.tab.c"
    break;

  case 18: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 444 "2005104.y"
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
#line 1722 "2005104.tab.c"
    break;

  case 19: /* type_specifier: INT  */
#line 490 "2005104.y"
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
#line 1739 "2005104.tab.c"
    break;

  case 20: /* type_specifier: FLOAT  */
#line 502 "2005104.y"
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
#line 1756 "2005104.tab.c"
    break;

  case 21: /* type_specifier: VOID  */
#line 514 "2005104.y"
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
#line 1772 "2005104.tab.c"
    break;

  case 22: /* declaration_list: declaration_list COMMA ID  */
#line 528 "2005104.y"
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
#line 1807 "2005104.tab.c"
    break;

  case 23: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 558 "2005104.y"
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
#line 1860 "2005104.tab.c"
    break;

  case 24: /* declaration_list: ID  */
#line 606 "2005104.y"
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
#line 1892 "2005104.tab.c"
    break;

  case 25: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 633 "2005104.y"
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
#line 1932 "2005104.tab.c"
    break;

  case 26: /* statements: statement  */
#line 671 "2005104.y"
                       {
	(yyval.symbol)=new SymbolInfo("statement","statements");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statements : statement" << endl;
}
#line 1944 "2005104.tab.c"
    break;

  case 27: /* statements: statements statement  */
#line 678 "2005104.y"
                       {
	(yyval.symbol)=new SymbolInfo("statements statement","statements");
	(yyval.symbol)->startLine=(yyvsp[-1].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statements  : statements statement " << endl;
}
#line 1957 "2005104.tab.c"
    break;

  case 28: /* statement: var_declaration  */
#line 689 "2005104.y"
                            {
	(yyval.symbol)=new SymbolInfo("var_declaration","statement");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statement  : var_declaration " << endl;
}
#line 1969 "2005104.tab.c"
    break;

  case 29: /* statement: expression_statement  */
#line 696 "2005104.y"
                       {
	(yyval.symbol)=new SymbolInfo("expression_statement","statement");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statement  : expression_statement " << endl;
}
#line 1981 "2005104.tab.c"
    break;

  case 30: /* statement: compound_statement  */
#line 703 "2005104.y"
                     {
	(yyval.symbol)=new SymbolInfo("compound_statement","statement");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statement  : compound_statement " << endl;
}
#line 1993 "2005104.tab.c"
    break;

  case 31: /* statement: FOR LPAREN expression_statement embedded_exp embedded_void expression_statement embedded_exp embedded_void expression embedded_exp embedded_void RPAREN statement  */
#line 710 "2005104.y"
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
#line 2011 "2005104.tab.c"
    break;

  case 32: /* statement: IF LPAREN expression embedded_exp RPAREN embedded_void statement  */
#line 723 "2005104.y"
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
#line 2027 "2005104.tab.c"
    break;

  case 33: /* statement: IF LPAREN expression embedded_exp RPAREN embedded_void statement ELSE statement  */
#line 734 "2005104.y"
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
#line 2046 "2005104.tab.c"
    break;

  case 34: /* statement: WHILE LPAREN expression embedded_exp RPAREN embedded_void statement  */
#line 748 "2005104.y"
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
#line 2062 "2005104.tab.c"
    break;

  case 35: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 759 "2005104.y"
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
#line 2078 "2005104.tab.c"
    break;

  case 36: /* statement: RETURN expression SEMICOLON  */
#line 770 "2005104.y"
                              {
	(yyval.symbol)=new SymbolInfo("RETURN expression SEMICOLON","statement");
	(yyval.symbol)->startLine=(yyvsp[-2].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;	
	(yyval.symbol)->child.push_back((yyvsp[-2].symbol));
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "statement  : RETURN expression SEMICOLON " << endl;
}
#line 2092 "2005104.tab.c"
    break;

  case 37: /* embedded_exp: %empty  */
#line 781 "2005104.y"
              {
	 type_final=type;
}
#line 2100 "2005104.tab.c"
    break;

  case 38: /* embedded_void: %empty  */
#line 785 "2005104.y"
               {
	if(type_final=="void"){
		errorout<<"Line# "<<line<<": void function called within expression "<<endl;
		errorCount++;
	}
}
#line 2111 "2005104.tab.c"
    break;

  case 39: /* expression_statement: SEMICOLON  */
#line 792 "2005104.y"
                                 {
	(yyval.symbol)=new SymbolInfo("SEMICOLON","expression_statement");
	(yyval.symbol)->varType="int";
	type="int";
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;	
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));

	logout << "expression_statement  : SEMICOLON " << endl;
}
#line 2126 "2005104.tab.c"
    break;

  case 40: /* expression_statement: expression SEMICOLON  */
#line 802 "2005104.y"
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
#line 2141 "2005104.tab.c"
    break;

  case 41: /* variable: ID  */
#line 815 "2005104.y"
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
#line 2167 "2005104.tab.c"
    break;

  case 42: /* variable: ID LTHIRD expression RTHIRD  */
#line 836 "2005104.y"
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
#line 2206 "2005104.tab.c"
    break;

  case 43: /* expression: logic_expression  */
#line 873 "2005104.y"
                              {
	(yyval.symbol)=new SymbolInfo("logic_expression","expression");
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	type=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "expression  : logic_expression " << endl;
}
#line 2220 "2005104.tab.c"
    break;

  case 44: /* expression: variable ASSIGNOP logic_expression  */
#line 882 "2005104.y"
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
	}else if((yyvsp[-2].symbol)->varType!=(yyvsp[0].symbol)->varType){
		//errorout<<"Line# "<<line<<": type mismatch(not array2) "<<endl;
		//cout<<"from assign: "<<$1->varType<<" : "<<$3->varType<<endl;
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
#line 2252 "2005104.tab.c"
    break;

  case 45: /* logic_expression: rel_expression  */
#line 912 "2005104.y"
                                  {
	(yyval.symbol)=new SymbolInfo("rel_expression","logic_expression");

	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;

	logout << "logic_expression  : rel_expression " << endl;
}
#line 2268 "2005104.tab.c"
    break;

  case 46: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 923 "2005104.y"
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
#line 2283 "2005104.tab.c"
    break;

  case 47: /* rel_expression: simple_expression  */
#line 936 "2005104.y"
                                   {
	(yyval.symbol)=new SymbolInfo("simple_expression","rel_expression");	
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;
	logout << "rel_expression  : simple_expression " << endl;
}
#line 2297 "2005104.tab.c"
    break;

  case 48: /* rel_expression: simple_expression RELOP simple_expression  */
#line 945 "2005104.y"
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
#line 2312 "2005104.tab.c"
    break;

  case 49: /* simple_expression: term  */
#line 958 "2005104.y"
                         {
	(yyval.symbol)=new SymbolInfo("term","simple_expression");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;
	logout << "simple_expression  : term " << endl;
}
#line 2326 "2005104.tab.c"
    break;

  case 50: /* simple_expression: simple_expression ADDOP term  */
#line 967 "2005104.y"
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
#line 2350 "2005104.tab.c"
    break;

  case 51: /* term: unary_expression  */
#line 989 "2005104.y"
                        {
	(yyval.symbol)=new SymbolInfo("unary_expression","term");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;
	logout << "term  : unary_expression " << endl;
}
#line 2364 "2005104.tab.c"
    break;

  case 52: /* term: term MULOP unary_expression  */
#line 998 "2005104.y"
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
#line 2398 "2005104.tab.c"
    break;

  case 53: /* unary_expression: ADDOP unary_expression  */
#line 1030 "2005104.y"
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
#line 2416 "2005104.tab.c"
    break;

  case 54: /* unary_expression: NOT unary_expression  */
#line 1043 "2005104.y"
                       {
	(yyval.symbol)=new SymbolInfo("NOT unary_expression","unary_expression");
	(yyval.symbol)->startLine=(yyvsp[-1].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType="int";
	logout << "unary_expression  : NOT unary_expression " << endl;
}
#line 2430 "2005104.tab.c"
    break;

  case 55: /* unary_expression: factor  */
#line 1052 "2005104.y"
         {
	(yyval.symbol)=new SymbolInfo("factor","unary_expression");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;

	logout << "unary_expression  : factor " << endl;
}
#line 2445 "2005104.tab.c"
    break;

  case 56: /* factor: variable  */
#line 1064 "2005104.y"
                  {
	(yyval.symbol)=new SymbolInfo("variable","factor");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType=(yyvsp[0].symbol)->varType;
	(yyval.symbol)->arraySize=(yyvsp[0].symbol)->arraySize;
	logout << "factor  : variable " << endl;
}
#line 2459 "2005104.tab.c"
    break;

  case 57: /* factor: ID LPAREN argument_list RPAREN  */
#line 1073 "2005104.y"
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
#line 2502 "2005104.tab.c"
    break;

  case 58: /* factor: LPAREN expression RPAREN  */
#line 1111 "2005104.y"
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
#line 2520 "2005104.tab.c"
    break;

  case 59: /* factor: CONST_INT  */
#line 1124 "2005104.y"
            {
	(yyval.symbol)=new SymbolInfo("CONST_INT","factor");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType="int";
	value=stoi((yyvsp[0].symbol)->getName());
	logout << "factor  : CONST_INT " << endl;
}
#line 2534 "2005104.tab.c"
    break;

  case 60: /* factor: CONST_FLOAT  */
#line 1133 "2005104.y"
              {
	(yyval.symbol)=new SymbolInfo("CONST_FLOAT","factor");
	(yyval.symbol)->startLine=(yyvsp[0].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	(yyval.symbol)->varType="float";
	logout << "factor  : CONST_FLOAT " << endl;
}
#line 2547 "2005104.tab.c"
    break;

  case 61: /* factor: variable INCOP  */
#line 1141 "2005104.y"
                 {
	(yyval.symbol)=new SymbolInfo("variable INCOP","factor");
	(yyval.symbol)->varType=(yyvsp[-1].symbol)->varType;
	(yyval.symbol)->startLine=(yyvsp[-1].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "factor  : variable INCOP " << endl;
}
#line 2561 "2005104.tab.c"
    break;

  case 62: /* factor: variable DECOP  */
#line 1150 "2005104.y"
                 {
	(yyval.symbol)=new SymbolInfo("variable DECOP","factor");
	(yyval.symbol)->varType=(yyvsp[-1].symbol)->varType;
	(yyval.symbol)->startLine=(yyvsp[-1].symbol)->startLine;
	(yyval.symbol)->endLine=(yyvsp[0].symbol)->endLine;
	(yyval.symbol)->child.push_back((yyvsp[-1].symbol));
	(yyval.symbol)->child.push_back((yyvsp[0].symbol));
	logout << "factor  : variable DECOP " << endl;
}
#line 2575 "2005104.tab.c"
    break;

  case 63: /* argument_list: arguments  */
#line 1161 "2005104.y"
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
#line 2591 "2005104.tab.c"
    break;

  case 64: /* argument_list: %empty  */
#line 1172 "2005104.y"
  {
	(yyval.symbol)=new SymbolInfo("","argument_list");
	(yyval.symbol)->startLine=line;
	(yyval.symbol)->endLine=line;
	logout << "argument_list  :  " << endl;
}
#line 2602 "2005104.tab.c"
    break;

  case 65: /* arguments: arguments COMMA logic_expression  */
#line 1181 "2005104.y"
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
#line 2628 "2005104.tab.c"
    break;

  case 66: /* arguments: logic_expression  */
#line 1202 "2005104.y"
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
#line 2647 "2005104.tab.c"
    break;

  case 67: /* lcurl: LCURL  */
#line 1218 "2005104.y"
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
#line 2674 "2005104.tab.c"
    break;


#line 2678 "2005104.tab.c"

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

#line 1242 "2005104.y"

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
