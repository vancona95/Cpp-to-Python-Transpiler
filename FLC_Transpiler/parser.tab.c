/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

/****************** Prologue *****************/ 
	#include <math.h>
	#include <stdio.h>
	#include <ctype.h>
    #include <string.h>
	#include "symtab.h"
    #include "ast.h" 
    #include "translation.h"
    #include <stdbool.h>

    int yylex (void);
    int yyerror(char *s);
    int n_error = 0;
    extern int yylineno;
    // Pointer to file used for translation
    FILE *fptr;

/****************** Initialization of structs, counters and variables*****************/ 
    struct Ast_Node_Statements  *root;
    struct SymTab *local_table  = NULL; 
    struct AST_Node_Class       *class_array[100]       = { NULL };
    struct AST_Node_Object      *object_array[100]      = { NULL };
    struct AST_Node_FunctionDef *function_array[100]    = { NULL };
    int class_counter = 0;
    int object_counter = 0;
    int function_counter = 0;
    bool found = false;
    bool in_class = false;

/****************** functions declaration *****************/ 
    bool search_class_body(char* var_name, struct AST_Node_Statements *root);
    void check_function_call(struct AST_Node_FunctionCall *func_call);
    char * type_to_str(int type);
    void scope_enter();
    void scope_exit();
    

#line 109 "parser.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    SEMICOLON = 258,
    IF = 259,
    ELSE = 260,
    ID = 261,
    INT_NUMBER = 262,
    FLOAT_NUMBER = 263,
    INT = 264,
    FLOAT = 265,
    STRING = 266,
    BOOL = 267,
    LPAR = 268,
    RPAR = 269,
    LBRACE = 270,
    RBRACE = 271,
    COLON = 272,
    COMMA = 273,
    DOT = 274,
    BRACKETS = 275,
    RETURN = 276,
    COUT = 277,
    CIN = 278,
    STRING_V = 279,
    BOOL_V = 280,
    FOR = 281,
    FUNCTION = 282,
    CLASS = 283,
    MAIN = 284,
    PRIVATE = 285,
    PUBLIC = 286,
    UNKNOWN = 287,
    EQ = 288,
    AND = 289,
    OR = 290,
    ADD = 291,
    SUB = 292,
    MUL = 293,
    DIV = 294,
    GT = 295,
    LT = 296,
    GE = 297,
    LE = 298,
    EEQ = 299,
    NE = 300,
    LSHIFT = 301,
    RSHIFT = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union yystype YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   237

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

#define YYUNDEFTOK  2
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   103,   107,   113,   122,   127,   138,   144,
     150,   156,   161,   166,   171,   176,   181,   186,   191,   204,
     221,   239,   260,   261,   260,   282,   292,   313,   345,   398,
     452,   515,   515,   529,   529,   557,   564,   574,   575,   579,
     580,   584,   592,   599,   607,   614,   629,   632,   640,   641,
     642,   643,   644,   648,   666,   680,   697,   729,   762,   793,
     825,   849,   853,   864,   879,   883,   900,   914,   928,   942,
     957,   961,   965,   969,   973,   977,   981,   996,  1008,  1016,
    1023,  1030,  1037,  1049,  1059,  1063,  1070,  1080,  1089,  1102,
    1111,  1128,  1138,  1149,  1155,  1161,  1167,  1174,  1180,  1189,
    1190,  1191,  1192
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "IF", "ELSE", "ID",
  "INT_NUMBER", "FLOAT_NUMBER", "INT", "FLOAT", "STRING", "BOOL", "LPAR",
  "RPAR", "LBRACE", "RBRACE", "COLON", "COMMA", "DOT", "BRACKETS",
  "RETURN", "COUT", "CIN", "STRING_V", "BOOL_V", "FOR", "FUNCTION",
  "CLASS", "MAIN", "PRIVATE", "PUBLIC", "UNKNOWN", "EQ", "AND", "OR",
  "ADD", "SUB", "MUL", "DIV", "GT", "LT", "GE", "LE", "EEQ", "NE",
  "LSHIFT", "RSHIFT", "$accept", "program", "$@1", "statements",
  "instruction", "function_call", "function_def", "$@2", "$@3",
  "create_object", "access_class", "create_class", "$@4",
  "create_class_child", "$@5", "class_body", "private_body", "public_body",
  "if_statement", "if_condition", "else_if_statement", "else_statement",
  "for_loop", "body", "func_body", "expr", "math_expr", "logic_expr",
  "rel_expr", "input_stmnt", "output_stmnt", "multi_rshift",
  "multi_lshift", "single_rshift", "single_lshift", "multi_fun_param",
  "fun_param", "initialization", "assignment", "content", "types", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF (-110)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-90)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -110,    23,   152,  -110,    43,    29,    24,    30,  -110,  -110,
    -110,    16,    22,    50,    60,  -110,   152,    69,  -110,    73,
      88,    90,    93,  -110,  -110,  -110,  -110,    99,   100,    35,
     101,    86,    21,   105,   152,  -110,  -110,   117,    89,   183,
     106,   196,  -110,    16,   114,  -110,    22,   160,   104,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,   118,  -110,
     107,   120,   127,   130,    21,  -110,  -110,  -110,   145,   146,
    -110,  -110,  -110,   109,    21,   149,  -110,  -110,  -110,   159,
     158,   109,   171,    27,  -110,  -110,   173,    28,   109,   178,
       7,     6,     9,     8,    15,    18,    19,  -110,  -110,  -110,
     161,   190,   180,   181,   182,   175,    21,  -110,  -110,   187,
     191,   192,   195,  -110,  -110,    21,    21,    21,    21,    21,
      21,    21,    21,    21,    21,    21,   197,  -110,  -110,   175,
    -110,   107,   182,    21,    20,  -110,   184,   152,  -110,  -110,
     109,  -110,  -110,  -110,  -110,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   195,  -110,  -110,   209,
     199,   200,   188,   193,   207,   201,   204,  -110,   160,   152,
     152,   198,   208,   180,    21,   182,   211,  -110,  -110,  -110,
    -110,  -110,    71,  -110,   195,   210,  -110,  -110
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,   100,    99,   101,
     102,    75,    73,     0,     0,     3,     5,     0,     7,     0,
       0,     0,     0,    12,    13,    14,    15,     0,     0,     0,
       0,     0,    51,     0,     0,    44,    27,    51,     0,    51,
       0,    51,    71,    75,     0,    70,    73,     0,    31,     4,
       6,    10,    11,     8,     9,    16,    17,    19,    22,    18,
      88,    92,    94,    93,    51,    95,    96,    97,     0,    98,
      48,    49,    50,     0,    51,     0,   100,    21,    98,     0,
      84,    87,     0,    28,    29,    30,     0,    92,    91,     0,
      92,    94,    93,    95,    96,    97,    98,    74,    76,    72,
       0,     0,     0,     0,     0,    51,    51,    57,    59,    98,
      49,    50,     0,    56,    58,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,     0,    46,    20,    51,
      86,     0,     0,    51,    38,    32,     0,     0,    26,    23,
      90,    52,    61,    64,    41,    62,    63,    53,    54,    55,
      60,    67,    65,    68,    66,    69,     0,    85,    25,    50,
       0,     0,    40,    38,     0,     0,     0,    43,     0,     0,
       0,     0,     0,     0,    51,     0,     0,    37,    39,    35,
      36,    34,     0,    24,     0,     0,    45,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,  -110,   -15,  -110,    -2,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,    54,    65,    67,  -110,   156,
    -110,  -110,  -110,  -109,  -108,    -6,  -110,   167,   -56,  -110,
    -110,   186,   194,  -110,  -110,   -80,  -110,  -110,   -31,   -35,
     -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    15,    16,    67,    18,   105,   166,    19,
      20,    21,   102,    22,   103,   135,   162,   163,    23,    68,
      24,    25,    26,    35,   138,    78,    70,    71,    72,    27,
      28,    45,    42,    46,    43,    79,    80,    29,    30,    73,
      31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    49,    81,   144,    88,    82,    86,    85,   111,   -80,
     -77,   -78,   -79,   107,    17,    86,   101,   108,   -81,    75,
      37,   -82,   -83,     3,   158,   139,    69,    61,    62,    63,
      36,   -89,    17,    33,    64,    96,    84,    37,    57,    95,
      37,    37,   -89,    38,    34,    65,    66,   167,    58,   157,
     160,   161,   -80,   -77,   -78,   -79,    32,    39,   109,    40,
      39,   -81,    41,    47,   -82,   -83,    48,   183,    69,    44,
      81,   140,    50,    82,   185,   186,    51,   159,   113,   114,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    52,    60,    53,    81,    83,    54,    82,    76,     8,
       9,    10,    55,    56,    59,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   113,   114,    74,    89,
      98,   -33,   165,    61,    62,    63,    76,     8,     9,    10,
      64,    77,   104,    37,   107,    17,    86,   176,   108,   182,
     106,    65,    66,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   177,   178,     4,     5,     6,   112,
     -42,     7,     8,     9,    10,   127,   100,    17,    17,    76,
       8,     9,    10,   128,    11,    12,   129,   130,    13,   131,
      14,    61,    62,    63,    76,     8,     9,    10,    64,    87,
      62,    63,   132,   133,    39,   134,    64,   137,   136,    65,
      66,   141,    90,    91,    92,   142,   143,    65,    66,    64,
      34,   156,   168,   173,   179,   164,   169,   170,   175,   161,
      93,    94,   174,   160,   180,   184,   187,   181,   172,   171,
     126,   110,    99,     0,     0,     0,     0,    97
};

static const yytype_int16 yycheck[] =
{
       2,    16,    37,   112,    39,    37,    38,    38,    64,     3,
       3,     3,     3,     7,    16,    47,    47,     8,     3,    34,
      13,     3,     3,     0,   132,   105,    32,     6,     7,     8,
       6,     3,    34,     4,    13,    41,    38,    13,     3,    41,
      13,    13,    14,    19,    15,    24,    25,   156,    13,   129,
      30,    31,    46,    46,    46,    46,    13,    33,    64,    29,
      33,    46,    46,    13,    46,    46,     6,   175,    74,    47,
     105,   106,     3,   105,     3,   184,     3,   133,     7,     8,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,     3,     6,     3,   129,     6,     3,   129,     9,    10,
      11,    12,     3,     3,     3,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     7,     8,    13,    13,
       6,    17,   137,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    14,    13,     7,   137,   168,   168,     8,   174,
      33,    24,    25,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,   169,   170,     4,     5,     6,    14,
      14,     9,    10,    11,    12,    16,     6,   169,   170,     9,
      10,    11,    12,    14,    22,    23,    18,     6,    26,     6,
      28,     6,     7,     8,     9,    10,    11,    12,    13,     6,
       7,     8,    14,     3,    33,    15,    13,    15,    17,    24,
      25,    14,     6,     7,     8,    14,    14,    24,    25,    13,
      15,    14,     3,     6,    16,    31,    17,    17,    14,    31,
      24,    25,    21,    30,    16,    14,    16,   173,   163,   162,
      74,    64,    46,    -1,    -1,    -1,    -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,    50,     0,     4,     5,     6,     9,    10,    11,
      12,    22,    23,    26,    28,    51,    52,    53,    54,    57,
      58,    59,    61,    66,    68,    69,    70,    77,    78,    85,
      86,    88,    13,     4,    15,    71,     6,    13,    19,    33,
      29,    46,    80,    82,    47,    79,    81,    13,     6,    51,
       3,     3,     3,     3,     3,     3,     3,     3,    13,     3,
       6,     6,     7,     8,    13,    24,    25,    53,    67,    73,
      74,    75,    76,    87,    13,    51,     9,    14,    73,    83,
      84,    87,    88,     6,    53,    86,    88,     6,    87,    13,
       6,     7,     8,    24,    25,    53,    73,    80,     6,    79,
       6,    86,    60,    62,    14,    55,    33,     7,     8,    73,
      75,    76,    14,     7,     8,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    67,    16,    14,    18,
       6,     6,    14,     3,    15,    63,    17,    15,    72,    83,
      87,    14,    14,    14,    71,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    14,    83,    72,    76,
      30,    31,    64,    65,    31,    51,    56,    71,     3,    17,
      17,    65,    64,     6,    21,    14,    86,    51,    51,    16,
      16,    63,    87,    72,    14,     3,    71,    16
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    50,    49,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    53,    55,    56,    54,    54,    54,    57,    58,    58,
      58,    60,    59,    62,    61,    63,    63,    64,    64,    65,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    75,    76,    76,    76,    76,    76,    76,
      77,    78,    79,    79,    80,    80,    81,    82,    82,    82,
      82,    82,    82,    82,    83,    83,    84,    84,    85,    86,
      86,    86,    87,    87,    87,    87,    87,    87,    87,    88,
      88,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     2,     2,     2,     2,
       4,     3,     0,     0,     7,     5,     4,     2,     3,     3,
       3,     0,     4,     0,     7,     4,     4,     3,     0,     3,
       0,     5,     1,     6,     2,     9,     3,     6,     1,     1,
       1,     0,     3,     3,     3,     3,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     0,     2,     0,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     3,     2,     1,     2,     3,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 103 "parser.y"
               { scope_enter(); }
#line 1526 "parser.tab.c"
    break;

  case 3:
#line 103 "parser.y"
                                                   { root = (yyvsp[0].statements); scope_exit(); }
#line 1532 "parser.tab.c"
    break;

  case 4:
#line 107 "parser.y"
                                                    {   
                                                        (yyval.statements) = malloc(sizeof(struct AST_Node_Statements));
                                                        (yyval.statements)->n_type = STATEMENT_NODE;
                                                        (yyval.statements)->left = (yyvsp[-1].instruction);
                                                        (yyval.statements)->right = (yyvsp[0].statements);
                                                    }
#line 1543 "parser.tab.c"
    break;

  case 5:
#line 113 "parser.y"
                                                    {
                                                        (yyval.statements) = malloc(sizeof(struct AST_Node_Statements));
                                                        (yyval.statements)->n_type = STATEMENT_NODE;
                                                        (yyval.statements)->left = (yyvsp[0].instruction);
                                                        (yyval.statements)->right = NULL;
                                                    }
#line 1554 "parser.tab.c"
    break;

  case 6:
#line 122 "parser.y"
                                                {
                                                (yyval.instruction) = malloc(sizeof(struct AST_Node_Instruction));
                                                (yyval.instruction)->n_type = FUNC_CALL_NODE;
                                                (yyval.instruction)->value.functionCall = (yyvsp[-1].functionCall);
                                                }
#line 1564 "parser.tab.c"
    break;

  case 7:
#line 127 "parser.y"
                                                {
                                                (yyval.instruction) = malloc(sizeof(struct AST_Node_Instruction));
                                                (yyval.instruction)->value.functionDef = (yyvsp[0].functionDef);
                                                struct Symbol *s = NULL;
                                                s = find_symtab((yyvsp[0].functionDef)->func_name, local_table);
                                                if (s == NULL)  {
                                                (yyval.instruction)->n_type = FUNC_DEF_NODE;
                                                (yyval.instruction)->value.functionDef = (yyvsp[0].functionDef);
                                                struct Symbol *s = add_symbol((yyvsp[0].functionDef)->func_name, local_table, SYMBOL_FUNCTION, DATA_TYPE_NONE,(yyvsp[0].functionDef)->return_type, true, NULL, false, yylineno, null_value); }
                                                else { printf("\n\n\t***Error: %s already declared***\n\t***Line: %d***\n\n\n",s->name_sym,yylineno);n_error++; }
                                                }
#line 1580 "parser.tab.c"
    break;

  case 8:
#line 138 "parser.y"
                                                {
                                                (yyval.instruction) = malloc(sizeof(struct AST_Node_Instruction));
                                                (yyval.instruction)->n_type = CLASS_NODE;
                                                (yyval.instruction)->value.classNode = (yyvsp[-1].classNode);
                                                struct Symbol *s = add_symbol((yyvsp[-1].classNode)->class_name, local_table, SYMBOL_CLASS, DATA_TYPE_NONE,DATA_TYPE_NONE, false, NULL, true, yylineno, null_value);
                                                }
#line 1591 "parser.tab.c"
    break;

  case 9:
#line 144 "parser.y"
                                                {
                                                (yyval.instruction) = malloc(sizeof(struct AST_Node_Instruction));
                                                (yyval.instruction)->n_type = CLASS_CHILD_NODE;
                                                (yyval.instruction)->value.classNode = (yyvsp[-1].classNode);
                                                struct Symbol *s = add_symbol((yyvsp[-1].classNode)->class_name, local_table, SYMBOL_CLASS, DATA_TYPE_NONE,DATA_TYPE_NONE, false, NULL, true, yylineno, null_value);
                                                }
#line 1602 "parser.tab.c"
    break;

  case 10:
#line 150 "parser.y"
                                                {
                                                (yyval.instruction) = malloc(sizeof(struct AST_Node_Instruction));
                                                (yyval.instruction)->n_type = OBJECT_NODE;
                                                (yyval.instruction)->value.objectNode = (yyvsp[-1].objectNode);
                                                struct Symbol *s = add_symbol((yyvsp[-1].objectNode)->obj_name, local_table, SYMBOL_OBJECT, DATA_TYPE_NONE,DATA_TYPE_NONE, false, NULL, true, yylineno, null_value);
                                                }
#line 1613 "parser.tab.c"
    break;

  case 11:
#line 156 "parser.y"
                                                {      
                                                (yyval.instruction) = malloc(sizeof(struct AST_Node_Instruction));
                                                (yyval.instruction)->n_type = ACCESS_CLASS_NODE;
                                                (yyval.instruction)->value.objectNode = (yyvsp[-1].objectNode);
                                                }
#line 1623 "parser.tab.c"
    break;

  case 12:
#line 161 "parser.y"
                                                {
                                                (yyval.instruction) = malloc(sizeof(struct AST_Node_Instruction));
                                                (yyval.instruction)->n_type = IF_NODE;
                                                (yyval.instruction)->value.ifNode = (yyvsp[0].ifNode);
                                                }
#line 1633 "parser.tab.c"
    break;

  case 13:
#line 166 "parser.y"
                                                {
                                                (yyval.instruction) = malloc(sizeof(struct AST_Node_Instruction));
                                                (yyval.instruction)->n_type = ELSE_IF_NODE;
                                                (yyval.instruction)->value.elseIfNode = (yyvsp[0].elseIfNode);
                                                }
#line 1643 "parser.tab.c"
    break;

  case 14:
#line 171 "parser.y"
                                                {
                                                (yyval.instruction) = malloc(sizeof(struct AST_Node_Instruction));
                                                (yyval.instruction)->n_type = ELSE_NODE;
                                                (yyval.instruction)->value.elseNode = (yyvsp[0].elseNode);
                                                }
#line 1653 "parser.tab.c"
    break;

  case 15:
#line 176 "parser.y"
                                                {
                                                (yyval.instruction) = malloc(sizeof(struct AST_Node_Instruction));
                                                (yyval.instruction)->n_type = FOR_NODE;
                                                (yyval.instruction)->value.forNode = (yyvsp[0].forNode);
                                                }
#line 1663 "parser.tab.c"
    break;

  case 16:
#line 181 "parser.y"
                                                {
                                                (yyval.instruction) = malloc(sizeof(struct AST_Node_Instruction));
                                                (yyval.instruction)->n_type = INPUT_NODE;
                                                (yyval.instruction)->value.inputNode = (yyvsp[-1].inputNode);
                                                }
#line 1673 "parser.tab.c"
    break;

  case 17:
#line 186 "parser.y"
                                                {
                                                (yyval.instruction) = malloc(sizeof(struct AST_Node_Instruction));
                                                (yyval.instruction)->n_type = OUTPUT_NODE;
                                                (yyval.instruction)->value.outputNode = (yyvsp[-1].outputNode);
                                                }
#line 1683 "parser.tab.c"
    break;

  case 18:
#line 191 "parser.y"
                                                {
                                                (yyval.instruction) = malloc(sizeof(struct AST_Node_Instruction));
                                                (yyval.instruction)->n_type = ASSIGN_NODE;
                                                struct Symbol *s = find_symbol((yyvsp[-1].assign)->var, local_table);
                                                if ((s->data_type != (yyvsp[-1].assign)->val_type) || strcmp(type_to_str(s->data_type) , "Type none") == 0)   {
                                                    printf("\n\n\t***Error: Variable '%s' has been declared as a '%s' but type '%s' is assigned***\n\t***Line: %d***\n\n\n", 
                                                    (yyvsp[-1].assign)->var, type_to_str(s->data_type), type_to_str((yyvsp[-1].assign)->val_type),yylineno);n_error++;
                                                    }
                                                else    {
                                                    (yyval.instruction)->value.assign = (yyvsp[-1].assign);
                                                    s->value_sym = (yyvsp[-1].assign)->a_val;
                                                    }
                                                }
#line 1701 "parser.tab.c"
    break;

  case 19:
#line 204 "parser.y"
                                                {
                                                (yyval.instruction) = malloc(sizeof(struct AST_Node_Instruction));
                                                struct Symbol *s = NULL;
                                                for(struct AST_Node_Init *init = (yyvsp[-1].init); init != NULL; init = init->next_init) {
                                                    s = find_symbol(init->assign->var, local_table);
                                                    if (s == NULL)  {
                                                        (yyval.instruction)->n_type = INIT_NODE;
                                                        (yyval.instruction)->value.init = (yyvsp[-1].init);
                                                        s = add_symbol(init->assign->var, local_table, SYMBOL_VARIABLE, (yyvsp[-1].init)->data_type, DATA_TYPE_NONE, false, NULL, false, yylineno, null_value);
                                                        }
                                                    else {printf("\n\n\t***Error: Variable %s already declared, value is %s ***\n\t***Line: %d***\n\n\n",(yyvsp[-1].init)->assign->var,s->value_sym.val,yylineno);n_error++;
                                                        }
                                                    }
                                                }
#line 1720 "parser.tab.c"
    break;

  case 20:
#line 221 "parser.y"
                                                { 
                                                (yyval.functionCall) = malloc(sizeof(struct AST_Node_FunctionCall));
                                                struct Symbol *s = find_symtab((yyvsp[-3].string), local_table);
                                                if (s!=NULL) 
                                                    {
                                                    if (s->is_function) {
                                                        (yyval.functionCall)->func_name = (yyvsp[-3].string);
                                                        (yyval.functionCall)->return_type = s->ret_type;
                                                        (yyval.functionCall)->params = (yyvsp[-1].params);
                                                        /* Check if the function exists and if parameters are legit */
                                                        check_function_call((yyval.functionCall));                                                    
                                                        }
                                                    else {
                                                        printf("\n\n\t***Error: %s is not a function***\n\t***Line: %d***\n\n\n",(yyvsp[-3].string),yylineno);n_error++;
                                                        }
                                                    }
                                                else { printf("\n\n\t***Error: %s is not declared***\n\t***Line: %d***\n\n\n",(yyvsp[-3].string),yylineno); n_error++;}
                                                }
#line 1743 "parser.tab.c"
    break;

  case 21:
#line 239 "parser.y"
                                               { 
                                                (yyval.functionCall) = malloc(sizeof(struct AST_Node_FunctionCall));
                                                struct Symbol *s = find_symtab((yyvsp[-2].string), local_table);
                                                if (s!=NULL) 
                                                    {
                                                    if (s->is_function) {
                                                        (yyval.functionCall)->func_name = (yyvsp[-2].string);
                                                        (yyval.functionCall)->return_type = s->ret_type;
                                                        (yyval.functionCall)->params = NULL;
                                                        /* Check if the function exists and if parameters are legit */
                                                        check_function_call((yyval.functionCall));                                                    
                                                        }
                                                    else {
                                                        printf("\n\n\t***Error: %s is not a function***\n\t***Line: %d***\n\n\n",(yyvsp[-2].string),yylineno);n_error++;
                                                        }
                                                    }
                                                else { printf("\n\n\t***Error: %s is not declared***\n\t***Line: %d***\n\n\n",(yyvsp[-2].string),yylineno); n_error++;}
                                                }
#line 1766 "parser.tab.c"
    break;

  case 22:
#line 260 "parser.y"
                                                        { if (in_class == false ){scope_enter();}; }
#line 1772 "parser.tab.c"
    break;

  case 23:
#line 261 "parser.y"
                                                        { for(struct AST_Node_Params *param = (yyvsp[0].params); param != NULL; param = param->next_param) 
                                                        {
                                                        struct Symbol *s = add_symbol(param->decl_param->assign->var, local_table, SYMBOL_FUNCTION, (yyvsp[0].params)->decl_param->data_type, DATA_TYPE_NONE, true, (yyvsp[-3].init)->assign->var, false, yylineno, param->decl_param->assign->a_val);};
                                                        }
#line 1781 "parser.tab.c"
    break;

  case 24:
#line 265 "parser.y"
                                                        {
                                                        (yyval.functionDef) = malloc(sizeof(struct AST_Node_FunctionDef));
                                                        (yyval.functionDef)->func_name = (yyvsp[-6].init)->assign->var;
                                                        (yyval.functionDef)->params = (yyvsp[-3].params);
                                                        (yyval.functionDef)->f_body = (yyvsp[0].FBodyNode);
                                                        // check if return data type and function data type match
                                                        if ((yyvsp[-6].init)->data_type !=  (yyval.functionDef)->f_body->return_op->val_type)
                                                            {
                                                            printf("\n\n\t***Error: Function %s has been declared as a '%s' but type '%s' is returned ***\n\n\n", 
                                                            (yyval.functionDef)->func_name, type_to_str((yyvsp[-6].init)->data_type), type_to_str((yyval.functionDef)->f_body->return_op->val_type));n_error++;
                                                            }
                                                        (yyval.functionDef)->return_type = (yyvsp[-6].init)->data_type;
                                                        // add function to function array; 
                                                        function_array[function_counter] = (yyval.functionDef);
                                                        function_counter++;
                                                        if (in_class == false ){scope_exit();};
                                                        }
#line 1803 "parser.tab.c"
    break;

  case 25:
#line 282 "parser.y"
                                                        {     
                                                        scope_enter();
                                                        (yyval.functionDef) = malloc(sizeof(struct AST_Node_FunctionDef));
                                                        (yyval.functionDef)->func_name = "main";
                                                        (yyval.functionDef)->params = NULL;
                                                        (yyval.functionDef)->return_type = DATA_TYPE_INT;
                                                        //controllo su return?
                                                        (yyval.functionDef)->f_body = (yyvsp[0].FBodyNode);
                                                        scope_exit();
                                                        }
#line 1818 "parser.tab.c"
    break;

  case 26:
#line 292 "parser.y"
                                                        { if (in_class == false ){scope_enter();};
                                                        (yyval.functionDef) = malloc(sizeof(struct AST_Node_FunctionDef));
                                                        (yyval.functionDef)->func_name = (yyvsp[-3].init)->assign->var;
                                                        (yyval.functionDef)->params = NULL;
                                                        (yyval.functionDef)->f_body = (yyvsp[0].FBodyNode);
                                                        // check if return data type and function data type match
                                                        if ((yyvsp[-3].init)->data_type !=  (yyval.functionDef)->f_body->return_op->val_type)
                                                            {
                                                            printf("\n\n\t***Error: Function %s has been declared as a '%s' but type '%s' is returned ***\n\n\n", 
                                                            (yyval.functionDef)->func_name, type_to_str((yyvsp[-3].init)->data_type), type_to_str((yyval.functionDef)->f_body->return_op->val_type));n_error++;
                                                            }
                                                        (yyval.functionDef)->return_type = (yyvsp[-3].init)->data_type;
                                                        // add function to function array; 
                                                        function_array[function_counter] = (yyval.functionDef);
                                                        function_counter++;
                                                        if (in_class == false ){scope_exit();};
                                                        }
#line 1840 "parser.tab.c"
    break;

  case 27:
#line 313 "parser.y"
                            { /*check if $1 exists */
                            struct Symbol *s = find_symtab((yyvsp[-1].string), local_table);
                            if (s!=NULL) 
                                {
                                if (s->is_class) 
                                    {
                                    struct Symbol *s2 = find_symtab((yyvsp[0].string), local_table);
                                    if (s2==NULL) 
                                        {
                                        (yyval.objectNode) = malloc(sizeof(struct AST_Node_Object));
                                        (yyval.objectNode)->obj_class = malloc(sizeof(struct AST_Node_Class));
                                        //Search class in the class array by name
                                        for (int i = 0; i<class_counter; i++){
                                            if (strcmp(class_array[i]->class_name, (yyvsp[-1].string)) ==0)
                                                { 
                                                (yyval.objectNode)->obj_class = class_array[i];
                                                (yyval.objectNode)->obj_name = (yyvsp[0].string);
                                                object_array[object_counter] = (yyval.objectNode);
                                                object_counter++;
                                                break;
                                                }
                                            }
                                        }
                                    else { printf("\n\n\t***Error: object %s already exists***\n\t***Line: %d***\n\n\n",(yyvsp[0].string),yylineno); n_error++;}
                                    }
                                else { printf("\n\n\t***Error: %s is not a class***\n\t***Line: %d***\n\n\n",(yyvsp[-1].string),yylineno); n_error++;}
                                }
                            else { printf("\n\n\t***Error: class %s is not declared***\n\t***Line: %d***\n\n\n",(yyvsp[-1].string),yylineno); n_error++;}
                            }
#line 1874 "parser.tab.c"
    break;

  case 28:
#line 345 "parser.y"
                                        {
                                        // Search for the object in the object array by name
                                        for (int i = 0; i<object_counter; i++)
                                            {
                                            if (strcmp(object_array[i]->obj_name, (yyvsp[-2].string)) == 0)
                                                { 
                                                (yyval.objectNode)->obj_class = object_array[i]->obj_class;
                                                (yyval.objectNode)->obj_name = object_array[i]->obj_name;
                                                break;
                                                }
                                            }
                                        //Search class in class array by name
                                        for (int j = 0; j<class_counter; j++){
                                            if (strcmp(class_array[j]->class_name, (yyval.objectNode)->obj_class->class_name) ==0)
                                                {
                                                (yyval.objectNode)->obj_class->c_body->pub_body = class_array[j]->c_body->pub_body;
                                                break;
                                                }
                                            }
                                        //Search attribute in the same class of the object
                                        if (search_class_body((yyvsp[0].string), (yyval.objectNode)->obj_class->c_body->pub_body) == true)
                                            { (yyval.objectNode)->access_value.val = (yyvsp[0].string); }
                                        else 
                                            {
                                        // check if the attribute is present in the parent classes 
                                            for (int k = 0; k<class_counter; k++)
                                                {
                                                // check if the class is present in the classes array
                                                if (strcmp(class_array[k]->class_name, (yyval.objectNode)->obj_class->class_name) == 0)
                                                    {
                                                    // check if the class has a parent
                                                    if (class_array[k]->parent_class_public != NULL)
                                                        {
                                                        (yyval.objectNode)->obj_class->parent_class_public = class_array[k]->parent_class_public;
                                                        // cycle in the public body of each parent classes 
                                                        for (   class_array[k]->parent_class_public->parent_pub_body;
                                                                class_array[k]->parent_class_public->parent_pub_body != NULL;
                                                                class_array[k]->parent_class_public->parent_pub_body = class_array[k]->parent_class_public->next_parent_public->parent_pub_body
                                                            ){
                                                            // check if the attribute is present in the public body of the parent class
                                                            if (search_class_body((yyvsp[0].string), class_array[k]->parent_class_public->parent_pub_body) == true)
                                                                {                                       
                                                                (yyval.objectNode)->access_value.val = (yyvsp[0].string);
                                                                (yyval.objectNode)->access_type = ACCESS_TYPE_VAR;
                                                                break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if ((yyval.objectNode)->access_value.val == NULL){printf("\n\n\n\t\t***ERROR: %s not found in class %s***\n\n\n", (yyvsp[0].string),(yyval.objectNode)->obj_class->class_name);n_error++;}
                                        }
#line 1932 "parser.tab.c"
    break;

  case 29:
#line 398 "parser.y"
                                        {                     
                                        // Search for the object in the object array by name
                                        for (int i = 0; i<object_counter; i++)
                                            {
                                            if (strcmp(object_array[i]->obj_name, (yyvsp[-2].string)) ==0)
                                                { 
                                                (yyval.objectNode)->obj_class = object_array[i]->obj_class;
                                                (yyval.objectNode)->obj_name = object_array[i]->obj_name;
                                                break;
                                                }
                                            }
                                        //Search class in class array by name
                                        for (int j = 0; j<class_counter; j++){
                                            if (strcmp(class_array[j]->class_name, (yyval.objectNode)->obj_class->class_name) ==0)
                                                {
                                                (yyval.objectNode)->obj_class->c_body->pub_body = class_array[j]->c_body->pub_body;
                                                break;
                                                }
                                            }
                                        //Search attribute in the same class of the object
                                        if (search_class_body((yyvsp[0].functionCall)->func_name, (yyval.objectNode)->obj_class->c_body->pub_body) == true)
                                            {
                                            (yyval.objectNode)->access_value.funca = (yyvsp[0].functionCall);
                                            (yyval.objectNode)->access_type = ACCESS_TYPE_FUNCTION;
                                            }
                                        else 
                                            {
                                        // check if the attribute is present in the parent classes 
                                            for (int k = 0; k<class_counter; k++){
                                                // check if the class is present in the classes array
                                                if (strcmp(class_array[k]->class_name, (yyval.objectNode)->obj_class->class_name) == 0)
                                                    {
                                                    // check if the class has a parent
                                                    if (class_array[k]->parent_class_public != NULL)
                                                        {
                                                        (yyval.objectNode)->obj_class->parent_class_public = class_array[k]->parent_class_public;
                                                        // cycle in the public body of each parent classes   
                                                        for (   class_array[k]->parent_class_public->parent_pub_body;
                                                                class_array[k]->parent_class_public->parent_pub_body != NULL;
                                                                class_array[k]->parent_class_public->parent_pub_body = class_array[k]->parent_class_public->next_parent_public->parent_pub_body
                                                            ){
                                                            // check if the attribute is present in the public body of the parent class
                                                            if (search_class_body((yyvsp[0].functionCall)->func_name, class_array[k]->parent_class_public->parent_pub_body) == true){
                                                                (yyval.objectNode)->access_value.funca = (yyvsp[0].functionCall);
                                                                (yyval.objectNode)->access_type = ACCESS_TYPE_FUNCTION;
                                                                break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if ((yyval.objectNode)->access_value.funca == NULL){printf("\n\n\t***Error: %s not found in class %s***\n\t***Line: %d***\n\n\n",(yyvsp[0].functionCall)->func_name,(yyval.objectNode)->obj_class->class_name,yylineno);n_error++;}
                                        }
#line 1991 "parser.tab.c"
    break;

  case 30:
#line 452 "parser.y"
                                        { 
                                        // Search for the object in the object array by name
                                        for (int i = 0; i<object_counter; i++)
                                            {
                                            if (strcmp(object_array[i]->obj_name, (yyvsp[-2].string)) == 0)
                                                { 
                                                (yyval.objectNode)->obj_class = object_array[i]->obj_class;
                                                (yyval.objectNode)->obj_name = object_array[i]->obj_name;
                                                break;
                                                }
                                            }
                                        //Search class in class array by name

                                        for (int j = 0; j<class_counter; j++)
                                            {
                                            if (strcmp(class_array[j]->class_name, (yyval.objectNode)->obj_class->class_name) == 0)
                                                {
                                                (yyval.objectNode)->obj_class->c_body->pub_body = class_array[j]->c_body->pub_body;
                                                break;
                                                }
                                            }

                                            //Search attribute in the same class of the object
                                        if (search_class_body((yyvsp[0].assign)->var, (yyval.objectNode)->obj_class->c_body->pub_body) == true)
                                            {
                                            (yyval.objectNode)->access_value.ass_val = (yyvsp[0].assign);
                                            (yyval.objectNode)->access_type = ACCESS_TYPE_ASSIGN;
                                            }
                                        else 
                                            {
                                            // check if the attribute is present in the parent classes 
                                            for (int k = 0; k<class_counter; k++)
                                                {
                                                // check if the class is present in the classes array
                                                if (strcmp(class_array[k]->class_name, (yyval.objectNode)->obj_class->class_name) == 0)
                                                    {
                                                    // check if the class has a parent
                                                    if (class_array[k]->parent_class_public != NULL)
                                                        {
                                                        (yyval.objectNode)->obj_class->parent_class_public = class_array[k]->parent_class_public;
                                                        // cycle in the public body of each parent classes   
                                                        for (   class_array[k]->parent_class_public->parent_pub_body;
                                                                class_array[k]->parent_class_public->parent_pub_body != NULL;
                                                                class_array[k]->parent_class_public->parent_pub_body = class_array[k]->parent_class_public->next_parent_public->parent_pub_body
                                                            ){

                                                            // check if the attribute is present in the public body of the parent class
                                                            if (search_class_body((yyvsp[0].assign)->var, class_array[k]->parent_class_public->parent_pub_body) == true)
                                                                { 
                                                                (yyval.objectNode)->access_value.ass_val = (yyvsp[0].assign);
                                                                (yyval.objectNode)->access_type = ACCESS_TYPE_ASSIGN;
                                                                break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }                                                                    
                                            }
                                            if ((yyval.objectNode)->access_value.ass_val == NULL){printf("\n\n\t***Error: %s not found in class %s***\n\t***Line: %d***\n\n\n",(yyvsp[0].assign)->var,(yyval.objectNode)->obj_class->class_name,yylineno);n_error++;}
                                        }
#line 2056 "parser.tab.c"
    break;

  case 31:
#line 515 "parser.y"
                                        {in_class = true;}
#line 2062 "parser.tab.c"
    break;

  case 32:
#line 516 "parser.y"
                                        {
                                        (yyval.classNode) = malloc(sizeof(struct AST_Node_Class));
                                        (yyval.classNode)->parent_class_public = malloc(sizeof(struct AST_Node_Parent_Public));
                                        (yyval.classNode)->class_name = (yyvsp[-2].string);
                                        (yyval.classNode)->c_body = (yyvsp[0].CBodyNode);
                                        (yyval.classNode)->parent_class_public = NULL;
                                        class_array[class_counter] = (yyval.classNode);
                                        class_counter++;
                                        in_class = false;
                                        }
#line 2077 "parser.tab.c"
    break;

  case 33:
#line 529 "parser.y"
                                               {in_class = true;}
#line 2083 "parser.tab.c"
    break;

  case 34:
#line 530 "parser.y"
                                               {
                                                        (yyval.classNode) = malloc(sizeof(struct AST_Node_Class));
                                                        (yyval.classNode)->parent_class_public = malloc(sizeof(struct AST_Node_Parent_Public));
                                                        (yyval.classNode)->class_name = (yyvsp[-5].string);
                                                        (yyval.classNode)->c_body = (yyvsp[0].CBodyNode);
                                                        // search parent class in the class array
                                                        for (int i = 0; i<class_counter; i++)
                                                            {
                                                            // compare the name of the parent class in the statement with the name of the class in the class array
                                                             if (strcmp(class_array[i]->class_name, (yyvsp[-1].string)) == 0)
                                                                {
                                                                (yyval.classNode)->parent_class = class_array[i];
                                                                (yyval.classNode)->parent_class->class_name = class_array[i]->class_name;
                                                                (yyval.classNode)->parent_class_public->parent_pub_body = class_array[i]->c_body->pub_body;
                                                                (yyval.classNode)->parent_class_public->next_parent_public = class_array[i]->parent_class_public;
                                                                class_array[class_counter] = (yyval.classNode);        
                                                                class_counter++;
                                                                break;
                                                                }
                                                             else if (i == class_counter){printf("\n\n\n\t\t***ERROR: class parent %s not found***\n\n\n",(yyvsp[-1].string)); n_error++;}
                                                        }
                                                        in_class = false;

                                                        }
#line 2112 "parser.tab.c"
    break;

  case 35:
#line 557 "parser.y"
                                                                    {   
                                                                    (yyval.CBodyNode) = malloc(sizeof(struct AST_Node_CBody));
                                                                    //$$->pri_body = malloc(sizeof(struct AST_Node_Statements));
                                                                    //$$->pub_body = malloc(sizeof(struct AST_Node_Statements));
                                                                    (yyval.CBodyNode)->pri_body = (yyvsp[-2].statements);
                                                                    (yyval.CBodyNode)->pub_body = (yyvsp[-1].statements);
                                                                    }
#line 2124 "parser.tab.c"
    break;

  case 36:
#line 564 "parser.y"
                                                                    {
                                                                    (yyval.CBodyNode) = malloc(sizeof(struct AST_Node_CBody));
                                                                    //$$->pri_body = malloc(sizeof(struct AST_Node_Statements));
                                                                    //$$->pub_body = malloc(sizeof(struct AST_Node_Statements));
                                                                    (yyval.CBodyNode)->pri_body = (yyvsp[-1].statements);
                                                                    (yyval.CBodyNode)->pub_body = (yyvsp[-2].statements);
                                                                    }
#line 2136 "parser.tab.c"
    break;

  case 37:
#line 574 "parser.y"
                                         { (yyval.statements) = (yyvsp[0].statements); }
#line 2142 "parser.tab.c"
    break;

  case 39:
#line 579 "parser.y"
                                        { (yyval.statements) = (yyvsp[0].statements); }
#line 2148 "parser.tab.c"
    break;

  case 41:
#line 584 "parser.y"
                                                        { 
                                                        (yyval.ifNode) = malloc(sizeof(struct AST_Node_If));
                                                        (yyval.ifNode)->condition = (yyvsp[-2].expression);
                                                        (yyval.ifNode)->if_body = (yyvsp[0].statements);
                                                        }
#line 2158 "parser.tab.c"
    break;

  case 42:
#line 592 "parser.y"
                                                {
                                                if((yyvsp[0].expression)->expr_type != DATA_TYPE_BOOL) { printf("\n\n\t***Error: IF condition must be boolean type***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                                else { (yyval.expression) = (yyvsp[0].expression); }
                                                }
#line 2167 "parser.tab.c"
    break;

  case 43:
#line 599 "parser.y"
                                                    {
                                                    (yyval.elseIfNode) = malloc(sizeof(struct AST_Node_Else_If));
                                                    (yyval.elseIfNode)->condition = (yyvsp[-2].expression);
                                                    (yyval.elseIfNode)->elif_body = (yyvsp[0].statements);
                                                    }
#line 2177 "parser.tab.c"
    break;

  case 44:
#line 607 "parser.y"
                                                {
                                                (yyval.elseNode) = malloc(sizeof(struct AST_Node_Else));
                                                (yyval.elseNode)->else_body = (yyvsp[0].statements);
                                                }
#line 2186 "parser.tab.c"
    break;

  case 45:
#line 614 "parser.y"
                                                                                        {
                                                                                        (yyval.forNode) = malloc(sizeof(struct AST_Node_For));
                                                                                        (yyval.forNode)->init = (yyvsp[-6].assign);
                                                                                        (yyval.forNode)->condition = (yyvsp[-4].expression);
                                                                                        (yyval.forNode)->increment = (yyvsp[-2].assign);
                                                                                        // The increment can be expressed only as x = x + 1 and not as x++ or x += 1
                                                                                        // The sign of the increment expression will be used at translation time for further control:
                                                                                        // The control is needed to solve a problem where the decrement is written as x = x -1 and not as x = x - 1
                                                                                        (yyval.forNode)->increment->a_val.expr->op = (yyvsp[-2].assign)->a_val.expr->op;
                                                                                        (yyval.forNode)->for_body = (yyvsp[0].statements);
                                                                                        delete_symbol( find_symbol((yyvsp[-6].assign)->var,local_table), local_table);
                                                                                        }
#line 2203 "parser.tab.c"
    break;

  case 46:
#line 629 "parser.y"
                                                  { (yyval.statements) = (yyvsp[-1].statements); }
#line 2209 "parser.tab.c"
    break;

  case 47:
#line 632 "parser.y"
                                                                        {   
                                                                        (yyval.FBodyNode) = malloc(sizeof(struct AST_Node_FBody));                                       
                                                                        (yyval.FBodyNode)->func_body = (yyvsp[-4].statements);
                                                                        (yyval.FBodyNode)->return_op = (yyvsp[-2].operand);
                                                                        }
#line 2219 "parser.tab.c"
    break;

  case 48:
#line 640 "parser.y"
                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2225 "parser.tab.c"
    break;

  case 49:
#line 641 "parser.y"
                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2231 "parser.tab.c"
    break;

  case 50:
#line 642 "parser.y"
                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2237 "parser.tab.c"
    break;

  case 51:
#line 643 "parser.y"
                                        { (yyval.expression) = NULL; }
#line 2243 "parser.tab.c"
    break;

  case 52:
#line 644 "parser.y"
                                        { (yyval.expression) = (yyvsp[-1].expression); }
#line 2249 "parser.tab.c"
    break;

  case 53:
#line 648 "parser.y"
                                            {
                                            (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                            // queste malloc permettono il riconoscimento della x
                                            (yyval.expression)->left_op = malloc(sizeof(struct AST_Node_Operand));
                                            (yyval.expression)->right_op = malloc(sizeof(struct AST_Node_Operand));
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->op = (yyvsp[-1].string);
                                            (yyval.expression)->expr_type = (yyvsp[0].operand)->val_type;
                                            if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                                { printf("\n\n\t***Error: Cannot add '%s' to '%s'***\n\t***Line: %d***\n\n\n",type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                                
                                            else 
                                                {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                                };
                                            }
#line 2272 "parser.tab.c"
    break;

  case 54:
#line 666 "parser.y"
                                            { 
                                            (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                            (yyval.expression)->op = (yyvsp[-1].string);
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = (yyvsp[-2].operand)->val_type;
                                            if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                                { printf("\n\n\t***Error: Cannot subtract '%s' to '%s'***\n\t***Line: %d***\n\n\n",type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                            else 
                                                {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                                };
                                            }
#line 2291 "parser.tab.c"
    break;

  case 55:
#line 680 "parser.y"
                                            { 
                                            (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                            // queste malloc permettono il riconoscimento della x
                                            (yyval.expression)->left_op = malloc(sizeof(struct AST_Node_Operand));
                                            (yyval.expression)->right_op = malloc(sizeof(struct AST_Node_Operand));
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->op = (yyvsp[-1].string);
                                            if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                                { printf("\n\n\t***Error: Cannot multiply '%s' to '%s'***\n\t***Line: %d***\n\n\n",type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                            else 
                                                {
                                                (yyval.expression)->left_op = (yyvsp[-2].operand);
                                                (yyval.expression)->right_op = (yyvsp[0].operand);
                                                (yyval.expression)->expr_type = (yyvsp[-2].operand)->val_type;
                                                }
                                            }
#line 2313 "parser.tab.c"
    break;

  case 56:
#line 697 "parser.y"
                                            {   
                                            // This rule is used in case expression written as: int x = A -B and not as x = A - B
                                            // check if the second token is a negative integer number
                                            if (atoi((yyvsp[0].string))<0) 
                                                {                                               
                                                int temp= atoi((yyvsp[0].string));
                                                temp = -temp;
                                                int length = snprintf( NULL, 0, "%d", temp );
                                                char* temp_str = malloc( length + 1 );
                                                //cast back to string
                                                snprintf( temp_str, length + 1, "%d", temp );

                                                // Need to allocate operands in order to use the expression
                                                struct AST_Node_Operand *S1, *S2;
                                                S1 = malloc(sizeof(struct AST_Node_Operand));
                                                S1->value = (yyvsp[-1].operand)->value;
                                                S1->val_type = DATA_TYPE_INT;
                                                S1->operand_type = CONTENT_TYPE_INT_NUMBER;

                                                S2 = malloc(sizeof(struct AST_Node_Operand));
                                                S2->value.val = temp_str;
                                                S2->val_type = DATA_TYPE_INT;
                                                S2->operand_type = CONTENT_TYPE_INT_NUMBER;
                                                
                                                (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                                (yyval.expression)->op = "-";
                                                (yyval.expression)->left_op = S1;
                                                (yyval.expression)->right_op = S2;
                                                (yyval.expression)->expr_type = DATA_TYPE_INT;
                                            }
                                            else { printf("\n\n\t***Error: Operation not allowed ***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                            }
#line 2350 "parser.tab.c"
    break;

  case 57:
#line 729 "parser.y"
                                            {   
                                            // This rule is used in case expression written as: int x = A -B and not as x = A - B
                                            // check if the second token is a negative integer number
                                            if (atoi((yyvsp[0].string))<0) 
                                                {                                               
                                                int temp= atoi((yyvsp[0].string));
                                                temp = -temp;
                                                int length = snprintf( NULL, 0, "%d", temp );
                                                char* temp_str = malloc( length + 1 );
                                                //cast back to string
                                                snprintf( temp_str, length + 1, "%d", temp );

                                                // Need to allocate operands in order to use the expression
                                                struct AST_Node_Operand *S1, *S2;
                                                S1 = malloc(sizeof(struct AST_Node_Operand));
                                                S1->value.val = (yyvsp[-1].string);
                                                S1->val_type = DATA_TYPE_INT;
                                                S1->operand_type = CONTENT_TYPE_INT_NUMBER;

                                                S2 = malloc(sizeof(struct AST_Node_Operand));
                                                S2->value.val = temp_str;
                                                S2->val_type = DATA_TYPE_INT;
                                                S2->operand_type = CONTENT_TYPE_INT_NUMBER;
                                                
                                                (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                                (yyval.expression)->op = "-";
                                                (yyval.expression)->left_op = S1;
                                                (yyval.expression)->right_op = S2;
                                                (yyval.expression)->expr_type = DATA_TYPE_INT;
                                            }
                                            else { printf("\n\n\t***Error: Operation not allowed ***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                            }
#line 2387 "parser.tab.c"
    break;

  case 58:
#line 762 "parser.y"
                                            {
                                            //check if the second token is a negative float number
                                            if (atof((yyvsp[0].string))<0) 
                                                {                                               
                                                float temp= atof((yyvsp[0].string));
                                                temp = -temp;
                                                int length = snprintf( NULL, 0, "%4.3f", temp );
                                                char* temp_str = malloc( length + 1 );
                                                //cast back to string
                                                snprintf( temp_str, length + 1, "%4.3f", temp );
                                                
                                                // Need to allocate operands in order to use the expression
                                                struct AST_Node_Operand *S1, *S2;
                                                S1 = malloc(sizeof(struct AST_Node_Operand));
                                                S1->value = (yyvsp[-1].operand)->value;
                                                S1->val_type = DATA_TYPE_FLOAT;
                                                S1->operand_type = CONTENT_TYPE_FLOAT_NUMBER;

                                                S2 = malloc(sizeof(struct AST_Node_Operand));
                                                S2->value.val = temp_str;
                                                S2->val_type = DATA_TYPE_FLOAT;
                                                S2->operand_type = CONTENT_TYPE_FLOAT_NUMBER;
                                                
                                                (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                                (yyval.expression)->op = "-";
                                                (yyval.expression)->left_op = S1;
                                                (yyval.expression)->right_op = S2;
                                                (yyval.expression)->expr_type = DATA_TYPE_FLOAT;
                                            }
                                            else { printf("\n\n\t***Error: Operation not allowed***\n\t***Line: %d***\n\n\n",yylineno);n_error++; }
                                            }
#line 2423 "parser.tab.c"
    break;

  case 59:
#line 793 "parser.y"
                                            {
                                            //check if the second token is a negative float number
                                            if (atof((yyvsp[0].string))<0) 
                                                {                                               
                                                float temp= atof((yyvsp[0].string));
                                                temp = -temp;
                                                int length = snprintf( NULL, 0, "%4.3f", temp );
                                                char* temp_str = malloc( length + 1 );
                                                //cast back to string
                                                snprintf( temp_str, length + 1, "%4.3f", temp );
                                                
                                                // Need to allocate operands in order to use the expression
                                                struct AST_Node_Operand *S1, *S2;
                                                S1 = malloc(sizeof(struct AST_Node_Operand));
                                                S1->value.val = (yyvsp[-1].string);
                                                S1->val_type = DATA_TYPE_FLOAT;
                                                S1->operand_type = CONTENT_TYPE_FLOAT_NUMBER;

                                                S2 = malloc(sizeof(struct AST_Node_Operand));
                                                S2->value.val = temp_str;
                                                S2->val_type = DATA_TYPE_FLOAT;
                                                S2->operand_type = CONTENT_TYPE_FLOAT_NUMBER;
                                                
                                                (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                                (yyval.expression)->op = "-";
                                                (yyval.expression)->left_op = S1;
                                                (yyval.expression)->right_op = S2;
                                                (yyval.expression)->expr_type = DATA_TYPE_FLOAT;

                                            }
                                            else { printf("\n\n\t***Error: Operation not allowed***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                            }
#line 2460 "parser.tab.c"
    break;

  case 60:
#line 825 "parser.y"
                                        { 
                                        (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                        // queste malloc permettono il riconoscimento della x
                                        (yyval.expression)->left_op = malloc(sizeof(struct AST_Node_Operand));
                                        (yyval.expression)->right_op = malloc(sizeof(struct AST_Node_Operand));
                                        (yyval.expression)->left_op = (yyvsp[-2].operand);
                                        (yyval.expression)->right_op = (yyvsp[0].operand);
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                            { printf("\n\n\t***Error: Cannot divide '%s' by '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                        else    
                                            {
                                            if (strcmp((yyvsp[0].operand)->value.val,"0" ) == 0)   { printf("\n\n\t***Error: Cannot divide by 0***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                            else 
                                                {
                                                (yyval.expression)->left_op = (yyvsp[-2].operand);
                                                (yyval.expression)->right_op = (yyvsp[0].operand);
                                                (yyval.expression)->expr_type = (yyvsp[-2].operand)->val_type;
                                                }
                                            }
                                        }
#line 2486 "parser.tab.c"
    break;

  case 61:
#line 849 "parser.y"
                                        {   
                                        (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression) = (yyvsp[-1].expression);
                                        }
#line 2495 "parser.tab.c"
    break;

  case 62:
#line 853 "parser.y"
                                        {   
                                        (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != DATA_TYPE_BOOL || (yyvsp[0].operand)->val_type != DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot AND '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno);n_error++; }
                                        else {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
#line 2511 "parser.tab.c"
    break;

  case 63:
#line 864 "parser.y"
                                        {   
                                        (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != DATA_TYPE_BOOL || (yyvsp[0].operand)->val_type != DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot OR '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno);n_error++; }
                                        else 
                                            {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
#line 2528 "parser.tab.c"
    break;

  case 64:
#line 879 "parser.y"
                                        {  
                                        (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression) = (yyvsp[-1].expression); 
                                        }
#line 2537 "parser.tab.c"
    break;

  case 65:
#line 883 "parser.y"
                                        { 
                                        (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression)->left_op = malloc(sizeof(struct AST_Node_Operand));
                                        (yyval.expression)->right_op = malloc(sizeof(struct AST_Node_Operand));
                                        (yyval.expression)->left_op = (yyvsp[-2].operand);
                                        (yyval.expression)->right_op = (yyvsp[0].operand);
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                            { printf("\n\n\t***Error: Cannot compare '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                        else if ((yyvsp[-2].operand)->val_type == DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot compare boolean values***\n\t***Line: %d***\n\n\n",yylineno);n_error++; }
                                        else {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
#line 2559 "parser.tab.c"
    break;

  case 66:
#line 900 "parser.y"
                                        { 
                                        (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                            { printf("\n\n\t***Error: Cannot compare '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                        else if ((yyvsp[-2].operand)->val_type == DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot compare boolean values***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                        else 
                                            {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
#line 2578 "parser.tab.c"
    break;

  case 67:
#line 914 "parser.y"
                                        { 
                                        (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                            { printf("\n\n\t***Error: Cannot compare '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                        else if ((yyvsp[-2].operand)->val_type == DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot compare boolean values***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                        else 
                                            {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
#line 2597 "parser.tab.c"
    break;

  case 68:
#line 928 "parser.y"
                                        {
                                        (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                            { printf("\n\n\t***Error: Cannot compare '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno);n_error++; }
                                        else if ((yyvsp[-2].operand)->val_type == DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot compare boolean values***\n\t***Line: %d***\n\n\n",yylineno);n_error++; }
                                        else 
                                            {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
#line 2616 "parser.tab.c"
    break;

  case 69:
#line 942 "parser.y"
                                        { 
                                        (yyval.expression) = malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                            { printf("\n\n\t***Error: Cannot compare '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                        else 
                                            {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
#line 2633 "parser.tab.c"
    break;

  case 70:
#line 957 "parser.y"
                                  { (yyval.inputNode)=(yyvsp[0].inputNode); }
#line 2639 "parser.tab.c"
    break;

  case 71:
#line 961 "parser.y"
                                   { (yyval.outputNode)=(yyvsp[0].outputNode); }
#line 2645 "parser.tab.c"
    break;

  case 72:
#line 965 "parser.y"
                                            {                     
                                            (yyvsp[-1].inputNode)->next_input = (yyvsp[0].inputNode);
                                            (yyval.inputNode) = (yyvsp[-1].inputNode); 
                                            }
#line 2654 "parser.tab.c"
    break;

  case 73:
#line 969 "parser.y"
                                            { (yyval.inputNode)=NULL; }
#line 2660 "parser.tab.c"
    break;

  case 74:
#line 973 "parser.y"
                                            { 
                                            (yyvsp[-1].outputNode)->next_output = (yyvsp[0].outputNode);
                                            (yyval.outputNode) = (yyvsp[-1].outputNode);
                                            }
#line 2669 "parser.tab.c"
    break;

  case 75:
#line 977 "parser.y"
                                            { (yyval.outputNode) = NULL; }
#line 2675 "parser.tab.c"
    break;

  case 76:
#line 981 "parser.y"
                                        {
                                        (yyval.inputNode) = malloc(sizeof(struct AST_Node_Input));
                                        (yyval.inputNode)->input_op = malloc(sizeof(struct AST_Node_Operand));
                                        struct Symbol *s = find_symbol((yyvsp[0].string), local_table);
                                        if(s == NULL) { (yyval.inputNode)->input_op->val_type = DATA_TYPE_NONE; }
                                        else    
                                            {
                                        (yyval.inputNode)->input_op->value.val = (yyvsp[0].string);
                                        (yyval.inputNode)->input_op->val_type = s->data_type;
                                        (yyval.inputNode)->input_op->operand_type = CONTENT_TYPE_ID;
                                            }
                                        }
#line 2692 "parser.tab.c"
    break;

  case 77:
#line 996 "parser.y"
                                        {
                                        (yyval.outputNode) = malloc(sizeof(struct AST_Node_Output));
                                        (yyval.outputNode)->output_op = malloc(sizeof(struct AST_Node_Operand));
                                        struct Symbol *s = find_symbol((yyvsp[0].string), local_table);
                                        if(s == NULL) { (yyval.outputNode)->output_op->val_type = DATA_TYPE_NONE; }
                                        else    
                                            {
                                            (yyval.outputNode)->output_op->value.val = (yyvsp[0].string);
                                            (yyval.outputNode)->output_op->val_type = s->data_type;
                                            (yyval.outputNode)->output_op->operand_type = CONTENT_TYPE_ID;
                                            }
                                        }
#line 2709 "parser.tab.c"
    break;

  case 78:
#line 1008 "parser.y"
                                        {
                                        (yyval.outputNode) = malloc(sizeof(struct AST_Node_Output));
                                        (yyval.outputNode)->output_op = malloc(sizeof(struct AST_Node_Operand));
                                        (yyval.outputNode)->output_op->value.val = (yyvsp[0].string);
                                        (yyval.outputNode)->output_op->val_type = DATA_TYPE_STRING;
                                        (yyval.outputNode)->output_op->operand_type = CONTENT_TYPE_STRING;
                                        (yyval.outputNode)->next_output = NULL;
                                        }
#line 2722 "parser.tab.c"
    break;

  case 79:
#line 1016 "parser.y"
                                        {
                                        (yyval.outputNode) = malloc(sizeof(struct AST_Node_Output));
                                        (yyval.outputNode)->output_op = malloc(sizeof(struct AST_Node_Operand));
                                        (yyval.outputNode)->output_op->value.val = (yyvsp[0].string);
                                        (yyval.outputNode)->output_op->val_type = DATA_TYPE_FLOAT;
                                        (yyval.outputNode)->output_op->operand_type = CONTENT_TYPE_FLOAT_NUMBER;
                                        }
#line 2734 "parser.tab.c"
    break;

  case 80:
#line 1023 "parser.y"
                                        {
                                        (yyval.outputNode) = malloc(sizeof(struct AST_Node_Output));
                                        (yyval.outputNode)->output_op = malloc(sizeof(struct AST_Node_Operand));
                                        (yyval.outputNode)->output_op->value.val = (yyvsp[0].string);
                                        (yyval.outputNode)->output_op->val_type = DATA_TYPE_INT;
                                        (yyval.outputNode)->output_op->operand_type = CONTENT_TYPE_INT_NUMBER;
                                        }
#line 2746 "parser.tab.c"
    break;

  case 81:
#line 1030 "parser.y"
                                        {
                                        (yyval.outputNode) = malloc(sizeof(struct AST_Node_Output));
                                        (yyval.outputNode)->output_op = malloc(sizeof(struct AST_Node_Operand));
                                        (yyval.outputNode)->output_op->value.val = (yyvsp[0].string);
                                        (yyval.outputNode)->output_op->val_type = DATA_TYPE_BOOL;
                                        (yyval.outputNode)->output_op->operand_type = CONTENT_TYPE_BOOL;
                                        }
#line 2758 "parser.tab.c"
    break;

  case 82:
#line 1037 "parser.y"
                                        {
                                        (yyval.outputNode) = malloc(sizeof(struct AST_Node_Output));
                                        (yyval.outputNode)->output_op = malloc(sizeof(struct AST_Node_Operand));
                                        struct Symbol *s = find_symbol((yyvsp[0].functionCall), local_table);
                                        if(s==NULL) { (yyval.outputNode)->output_op->val_type = DATA_TYPE_NONE; }
                                        else 
                                            {
                                        (yyval.outputNode)->output_op->value.funca = (yyvsp[0].functionCall);
                                        (yyval.outputNode)->output_op->val_type = s->data_type;
                                        (yyval.outputNode)->output_op->operand_type = CONTENT_TYPE_FUNCTION;
                                            }
                                        }
#line 2775 "parser.tab.c"
    break;

  case 83:
#line 1049 "parser.y"
                                        {
                                        (yyval.outputNode) = malloc(sizeof(struct AST_Node_Output));
                                        (yyval.outputNode)->output_op = malloc(sizeof(struct AST_Node_Operand));
                                        (yyval.outputNode)->output_op->value.expr = (yyvsp[0].expression);
                                        (yyval.outputNode)->output_op->val_type = (yyvsp[0].expression)->expr_type;
                                        (yyval.outputNode)->output_op->operand_type = CONTENT_TYPE_EXPRESSION;
                                        }
#line 2787 "parser.tab.c"
    break;

  case 84:
#line 1059 "parser.y"
                                                   {
                                                    (yyvsp[0].params)->next_param = NULL;
                                                    (yyval.params) = (yyvsp[0].params);
                                                    }
#line 2796 "parser.tab.c"
    break;

  case 85:
#line 1063 "parser.y"
                                                    {
                                                    (yyvsp[-2].params)->next_param = (yyvsp[0].params);
                                                    (yyval.params) = (yyvsp[-2].params);
                                                    }
#line 2805 "parser.tab.c"
    break;

  case 86:
#line 1070 "parser.y"
                                { 
                                (yyval.params) = malloc(sizeof(struct AST_Node_Params));
                                (yyval.params)->decl_param = malloc(sizeof(struct AST_Node_Init));
                                (yyval.params)->decl_param->data_type = str_to_type((yyvsp[-1].string));
                                (yyval.params)->decl_param->assign = malloc(sizeof(struct AST_Node_Assign));
                                (yyval.params)->decl_param->assign->val_type = str_to_type((yyvsp[-1].string));
                                (yyval.params)->decl_param->assign->var = (yyvsp[0].string);
                                (yyval.params)->decl_param->assign->a_val.val = NULL;
                                (yyval.params)->decl_param->assign->a_type = CONTENT_TYPE_ID;
                                }
#line 2820 "parser.tab.c"
    break;

  case 87:
#line 1080 "parser.y"
                                { 
                                (yyval.params) = malloc(sizeof(struct AST_Node_Params));
                                //$$->call_param = malloc(sizeof(struct AST_Node_Operand));
                                (yyval.params)->call_param = (yyvsp[0].operand);
                                //$$->call_param->val_type = $1->val_type;
                                }
#line 2831 "parser.tab.c"
    break;

  case 88:
#line 1089 "parser.y"
                                {
                                (yyval.init) = malloc(sizeof(struct AST_Node_Init));
                                (yyval.init)->data_type = str_to_type((yyvsp[-1].string));
                                (yyval.init)->next_init = NULL;
                                (yyval.init)->assign = malloc(sizeof(struct AST_Node_Assign));
                                (yyval.init)->assign->val_type = str_to_type((yyvsp[-1].string));
                                (yyval.init)->assign->var = (yyvsp[0].string);
                                (yyval.init)->assign->a_val.val = NULL;
                                (yyval.init)->assign->a_type = CONTENT_TYPE_ID;
                                }
#line 2846 "parser.tab.c"
    break;

  case 89:
#line 1102 "parser.y"
                                    { 
                                    (yyval.assign) = malloc(sizeof(struct AST_Node_Assign));
                                    (yyval.assign)->var = (yyvsp[-2].string);
                                    (yyval.assign)->a_val.val = (yyvsp[0].string);
                                    (yyval.assign)->a_type = CONTENT_TYPE_ID;
                                    struct Symbol *s = find_symbol((yyvsp[0].string), local_table);
                                    if (s==NULL) { (yyval.assign)->val_type = DATA_TYPE_NONE; }
                                    else { (yyval.assign)-> val_type = s->data_type; }
                                    }
#line 2860 "parser.tab.c"
    break;

  case 90:
#line 1111 "parser.y"
                                    { 
                                    struct Symbol *s = NULL;
                                    s = find_symbol((yyvsp[-2].string), local_table);
                                    if (s == NULL)  
                                        { s = add_symbol((yyvsp[-2].string), local_table, SYMBOL_VARIABLE, str_to_type((yyvsp[-3].string)), str_to_type((yyvsp[-3].string)), false, NULL, false, yylineno, (yyvsp[0].operand)->value); }
                                    else { printf("\n\n\t***Error: Variable %s already declared, value is %s***\n\t***Line: %d***\n\n\n",(yyvsp[-2].string),s->value_sym.val,yylineno); n_error++;}
                                    if((str_to_type((yyvsp[-3].string)) != (yyvsp[0].operand)->val_type))
                                        { printf("\n\n\t***Error: Cannot assign type %s to type %s***\n\t***Line: %d***\n\n\n",type_to_str((yyvsp[0].operand)->val_type),type_to_str(str_to_type((yyvsp[-3].string))),yylineno); n_error++;}
                                    else
                                        {
                                        (yyval.assign) = malloc(sizeof(struct AST_Node_Assign));
                                        (yyval.assign)->a_type = (yyvsp[0].operand)->operand_type;
                                        (yyval.assign)->var = (yyvsp[-2].string);
                                        (yyval.assign)->a_val = (yyvsp[0].operand)->value;
                                        (yyval.assign)->val_type = str_to_type((yyvsp[-3].string));
                                        }
                                    }
#line 2882 "parser.tab.c"
    break;

  case 91:
#line 1128 "parser.y"
                                    { 
                                    (yyval.assign) = malloc(sizeof(struct AST_Node_Assign));
                                    (yyval.assign)->var = (yyvsp[-2].string);
                                    (yyval.assign)->a_val = (yyvsp[0].operand)->value;
                                    (yyval.assign)->val_type = (yyvsp[0].operand)->val_type;
                                    (yyval.assign)->a_type = (yyvsp[0].operand)->operand_type;
                                    }
#line 2894 "parser.tab.c"
    break;

  case 92:
#line 1138 "parser.y"
                                { 
                                (yyval.operand) = malloc(sizeof(struct AST_Node_Operand));
                                struct Symbol *s = find_symtab((yyvsp[0].string), local_table);
                                if(s==NULL) { (yyval.operand)->val_type = DATA_TYPE_NONE; }
                                else 
                                    {
                                    (yyval.operand)->value.val = (yyvsp[0].string);
                                    (yyval.operand)->val_type = s->data_type;
                                    (yyval.operand)->operand_type = CONTENT_TYPE_ID;
                                    }
                                }
#line 2910 "parser.tab.c"
    break;

  case 93:
#line 1149 "parser.y"
                                {
                                (yyval.operand) = malloc(sizeof(struct AST_Node_Operand));
                                (yyval.operand)->value.val = (yyvsp[0].string);
                                (yyval.operand)->val_type = DATA_TYPE_FLOAT;
                                (yyval.operand)->operand_type = CONTENT_TYPE_FLOAT_NUMBER;
                                }
#line 2921 "parser.tab.c"
    break;

  case 94:
#line 1155 "parser.y"
                                {
                                (yyval.operand) = malloc(sizeof(struct AST_Node_Operand));
                                (yyval.operand)->value.val = (yyvsp[0].string);
                                (yyval.operand)->val_type = DATA_TYPE_INT;
                                (yyval.operand)->operand_type = CONTENT_TYPE_INT_NUMBER;
                                }
#line 2932 "parser.tab.c"
    break;

  case 95:
#line 1161 "parser.y"
                                { 
                                (yyval.operand) = malloc(sizeof(struct AST_Node_Operand));
                                (yyval.operand)->value.val = (yyvsp[0].string);
                                (yyval.operand)->val_type = DATA_TYPE_STRING;
                                (yyval.operand)->operand_type = CONTENT_TYPE_STRING;
                                }
#line 2943 "parser.tab.c"
    break;

  case 96:
#line 1167 "parser.y"
                                { 
                                (yyval.operand) = malloc(sizeof(struct AST_Node_Operand));
                                if (strcmp((yyvsp[0].string),"false")==0){(yyval.operand)->value.val = "False";}
                                else if (strcmp((yyvsp[0].string),"true")==0){(yyval.operand)->value.val = "True";}
                                (yyval.operand)->val_type = DATA_TYPE_BOOL;
                                (yyval.operand)->operand_type = CONTENT_TYPE_BOOL;
                                }
#line 2955 "parser.tab.c"
    break;

  case 97:
#line 1174 "parser.y"
                                {
                                (yyval.operand) = malloc(sizeof(struct AST_Node_Operand));
                                (yyval.operand)->value.funca = (yyvsp[0].functionCall);
                                (yyval.operand)->val_type = (yyvsp[0].functionCall)->return_type;
                                (yyval.operand)->operand_type = CONTENT_TYPE_FUNCTION;
                                }
#line 2966 "parser.tab.c"
    break;

  case 98:
#line 1180 "parser.y"
                                { 
                                (yyval.operand) = malloc(sizeof(struct AST_Node_Operand));
                                (yyval.operand)->value.expr = (yyvsp[0].expression);
                                (yyval.operand)->val_type = (yyvsp[0].expression)->expr_type;
                                (yyval.operand)->operand_type = CONTENT_TYPE_EXPRESSION;
                                }
#line 2977 "parser.tab.c"
    break;

  case 99:
#line 1189 "parser.y"
                    { (yyval.string) = DATA_TYPE_FLOAT; }
#line 2983 "parser.tab.c"
    break;

  case 100:
#line 1190 "parser.y"
                    { (yyval.string) = DATA_TYPE_INT; }
#line 2989 "parser.tab.c"
    break;

  case 101:
#line 1191 "parser.y"
                    { (yyval.string) = DATA_TYPE_STRING; }
#line 2995 "parser.tab.c"
    break;

  case 102:
#line 1192 "parser.y"
                    { (yyval.string) = DATA_TYPE_BOOL; }
#line 3001 "parser.tab.c"
    break;


#line 3005 "parser.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 1193 "parser.y"


/****************** Functions *****************/ 

int main(){
    
    yyparse();
    null_value.val = NULL;
    indent_counter=0;
    
    if (n_error == 0){
    fptr = fopen("python_transpiled.py","w");
    traverse(root);
    fclose(fptr);
    printf("\nParsing completed\n");
    }
    else {printf("\nParsing failed. errors found: %d\n",n_error);}
    return 0;
    }

int yyerror(char *s) { printf("\n\n\t***Error: %s***\n\t***Line: %d***\n\n\n",s,yylineno); n_error++;}

/****************** Scope handling *****************/ 

void scope_enter(){
    local_table = new_symtab(indent_counter, local_table);
    indent_counter++;
}

void scope_exit(){
    delete_symtab(local_table);
    indent_counter--;
}

/****************** Convert Data Type to String and viceversa *****************/ 

char * type_to_str(int type) {
    switch (type) {
        case DATA_TYPE_STRING:
            return "string";
        break;
        case DATA_TYPE_FLOAT:
            return "float";
        break;
        case DATA_TYPE_INT:
            return "int";
        break;
        case DATA_TYPE_BOOL:
            return "bool";
        break;
        case DATA_TYPE_NONE:
            return "Type none";
        break;
        default:
            return "Type not defined";
        break;
    }
}

int str_to_type (int type) {
    if      (strcmp(type_to_str(type), "string") == 0)  { return DATA_TYPE_STRING; }
    else if (strcmp(type_to_str(type), "float") == 0)   { return DATA_TYPE_FLOAT; }
    else if (strcmp(type_to_str(type), "int") == 0)     { return DATA_TYPE_INT; }
    else if (strcmp(type_to_str(type), "bool") == 0)    { return DATA_TYPE_BOOL; }
    else                                                { return DATA_TYPE_NONE; }
    }


/************************************************************* Support functions ***********************************************************************/

// Function to traverse the statements in class body
// Given a variable or function, it checks if is is present in the statements of the class body
// This function is used to check the parent class body when parent_class_body is given. (eg. in access_class rule)

bool search_class_body(char* var_name, struct AST_Node_Statements *root)
{
        if ( root->left == NULL && root->right == NULL) {} 
        else if (root->left != NULL && root->right == NULL)
        {       
            struct AST_Node_Instruction *left = root->left;
            struct AST_Node_Statements *right = root->right;
            switch (left->n_type)
            {
            case INIT_NODE:
                if (strcmp(left->value.init->assign->var, var_name)==0){
                    found = true;
                    return true;
                    break;
                    }
                else{                    
                    found = false;
                    return false;
                    break;
                    }
                break;
            case ASSIGN_NODE:
                if (strcmp(left->value.assign->var, var_name)==0){
                    found = true;
                    return true;
                    break;
                    }
                else{                    
                    found = false;
                    return false;
                    break;
                    }
                break;
            case FUNC_DEF_NODE:
                if (strcmp(left->value.functionDef->func_name, var_name)==0){
                    found = true;
                    return true;
                    break;
                    }
                else{                   
                    found = false;
                    return false;
                    break;
                    }
                break;
            default:
                printf("\n\n\t***Error: Unknown node***\n\t***Line: %d***\n\n\n",yylineno);n_error++;
                break;
            }
        }
        else {  
            bool found = false;
            struct AST_Node_Instruction *left = root->left;
            struct AST_Node_Statements *right = root->right;
            switch (left->n_type)
                {
                case INIT_NODE:
                    if (strcmp(left->value.init->assign->var, var_name)==0){
                        found = true;
                        return true;
                        break;
                        }
                    else{                    
                        found = false;
                        }
                    break;
                case ASSIGN_NODE:
                    if (strcmp(left->value.assign->var, var_name)==0){
                        found = true;
                        return true;
                        break;
                        }
                    else{                    
                        found = false;
                        }
                    break;
                case FUNC_DEF_NODE:
                    if (strcmp(left->value.functionDef->func_name, var_name)==0){
                        found = true;
                        return true;
                        break;
                        }
                    else{                    
                        found = false;
                        }
                    break;
                default:
                    printf("\n\n\t***Error: Unknown node***\n\t***Line: %d***\n\n\n",yylineno);n_error++;
                    break;
                }
        search_class_body(var_name,right); //continue traverse    
        }
}


/************************************************************* check function declarement ***********************************************************************/

// Check if the function name is already defined, if it is actually a function and then check parameters
void check_function_call(struct AST_Node_FunctionCall *func_call)
    {
    struct AST_Node_Params *func_call_first_param   = malloc(sizeof(struct AST_Node_Params));
    struct AST_Node_Params *func_def_first_param    = malloc(sizeof(struct AST_Node_Params));
    struct Symbol *s = NULL;
    s = find_symtab(func_call->func_name, local_table);
    if (s == NULL)  { printf("\n\n\t***Error: Function %s has not been declared ***\n\t***Line: %d***\n\n\n",func_call->func_name,yylineno); n_error++;}
    else if (s->is_function != true) { printf("\n\n\t***Error: Variable %s is not a function ***\n\t***Line: %d***\n\n\n",s->name_sym,yylineno); n_error++;}
    else    {
            for (int i = 0; i<function_counter; i++)
                {
                if (strcmp(function_array[i]->func_name, func_call->func_name) == 0)
                    {
                    // make a copy of the functions's FIRST parameters pointer, so we can roll back at the end of the check.
                    func_call_first_param = func_call->params;
                    func_def_first_param = function_array[i]->params;       
                    
                    // check if defined functin has empty parameters
                    if      ((function_array[i]->params == NULL) && (func_call->params != NULL))    { printf("\n\n\t***Error: Function %s has no parameters ***\n\t***Line: %d***\n\n\n",func_call->func_name,yylineno); n_error++;}
                    else if ((function_array[i]->params == NULL) && (func_call->params == NULL))    {/* both function definition and function call parameters are empty */}
                    else    
                        {
                        while((function_array[i]->params != NULL) && (func_call->params != NULL))
                        {
                        if (func_call->params->call_param->val_type == function_array[i]->params->decl_param->data_type)    { /* the parameter is of the correct type */ }
                        else 
                            {
                            printf("\n\n\t***Error: Parameter %s is type %s, while declared function needs type %s ***\n\n\n",func_call->params->call_param->value.val, type_to_str(func_call->params->call_param->val_type),type_to_str(function_array[i]->params->decl_param->data_type));n_error++;
                            }
                        // If one of the two functions has no more parameters, but the other has, then there is an error
                        if (    ((func_call->params->next_param == NULL) && (function_array[i]->params->next_param != NULL))
                                ||
                                ((func_call->params->next_param != NULL) && (function_array[i]->params->next_param == NULL))
                            )   { printf("\n\n\t***Error: Number of defined function parameter and called function differs ***\n\n\n");n_error++; }

                        // Check next parameters
                        func_call->params = func_call->params->next_param;
                        function_array[i]->params = function_array[i]->params->next_param;
                        }
                        // Roll back to the first parameter pointer of the functions.
                        func_call->params = func_call_first_param;
                        function_array[i]->params = func_def_first_param;  
                        }
                    }
                }
            }
}
