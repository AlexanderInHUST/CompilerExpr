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
#line 1 "main.y" /* yacc.c:339  */

    #include "stdio.h"
    #include "math.h"
    #include "string.h"
    #include "node.h"
    #include "symbol_table.h"
    #include "create_table.h"

    extern char *yytext;
    extern FILE *yyin;

    int yyerror(char *s);
    int yylex();
    void exit(int);
    enum exp_kind get_exp_kind (struct tree_node * e1, struct tree_node * e2);
    

#line 84 "main.tab.c" /* yacc.c:339  */

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
   by #include "main.tab.h".  */
#ifndef YY_YY_MAIN_TAB_H_INCLUDED
# define YY_YY_MAIN_TAB_H_INCLUDED
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
    _VARIABLE_NAME = 258,
    _INTEGER_VALUE = 259,
    _FLOAT_VALUE = 260,
    _CHAR_VALUE = 261,
    _INT_DECLARATION = 262,
    _FLOAT_RECLARATION = 263,
    _CHAR_DECLARATION = 264,
    _IF_CONDITION = 265,
    _WHILE_CONDITION = 266,
    _ELSE_CONDITION = 267,
    _ASSIGN_UNARY_OP = 268,
    _PLUS_OP = 269,
    _MINUS_OP = 270,
    _MULTIPLE_OP = 271,
    _DIVIDE_OP = 272,
    _MODULE_OP = 273,
    _OR_OP = 274,
    _AND_OP = 275,
    _NOT_OP = 276,
    _PLUS_ASSIGN_OP = 277,
    _MINUS_ASSIGN_OP = 278,
    _MULTI_ASSIGN_OP = 279,
    _DIVIDE_ASSIGN_OP = 280,
    _MODULE_ASSIGN_OP = 281,
    _SELF_PLUS_UNARY_OP = 282,
    _SELF_MINUS_UNARY_OP = 283,
    _LARGER_OP = 284,
    _LESS_OP = 285,
    _LARGER_EQUAL_OP = 286,
    _LESS_EQUAL_OP = 287,
    _NOT_EQUAL_OP = 288,
    _EQUAL_OP = 289,
    _LEFT_BRACKET = 290,
    _RIGHT_BRACKET = 291,
    _LEFT_BRACE = 292,
    _RIGHT_BRACE = 293,
    _END_DIVIDED_CHAR = 294,
    _COMMA_DIVIDED_CHAR = 295,
    _COMMENT_LEFT = 296,
    _COMMENT_RIGHT = 297,
    _LEFT_SELF_PLUS_UNARY_OP = 298,
    _LEFT_SELF_MINUS_UNARY_OP = 299,
    _RIGHT_SELF_PLUS_UNARY_OP = 300,
    _RIGHT_SELF_MINUS_UNARY_OP = 301,
    _UMINUS_OP = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "main.y" /* yacc.c:355  */

    int int_value;
    char name_value[32];
    float float_value;
    char char_value[32];
    struct tree_node * tree_node;

#line 180 "main.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MAIN_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 197 "main.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   188

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  90

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    57,    57,    66,    70,    78,    86,    94,   105,   114,
     124,   136,   147,   157,   169,   184,   190,   196,   202,   211,
     220,   229,   238,   249,   257,   265,   273,   281,   292,   300,
     308,   316,   324,   332,   343,   351,   362,   373,   383,   391,
     401,   406,   411,   416,   421,   426,   433,   438,   443,   451,
     457,   466
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_VARIABLE_NAME", "_INTEGER_VALUE",
  "_FLOAT_VALUE", "_CHAR_VALUE", "_INT_DECLARATION", "_FLOAT_RECLARATION",
  "_CHAR_DECLARATION", "_IF_CONDITION", "_WHILE_CONDITION",
  "_ELSE_CONDITION", "_ASSIGN_UNARY_OP", "_PLUS_OP", "_MINUS_OP",
  "_MULTIPLE_OP", "_DIVIDE_OP", "_MODULE_OP", "_OR_OP", "_AND_OP",
  "_NOT_OP", "_PLUS_ASSIGN_OP", "_MINUS_ASSIGN_OP", "_MULTI_ASSIGN_OP",
  "_DIVIDE_ASSIGN_OP", "_MODULE_ASSIGN_OP", "_SELF_PLUS_UNARY_OP",
  "_SELF_MINUS_UNARY_OP", "_LARGER_OP", "_LESS_OP", "_LARGER_EQUAL_OP",
  "_LESS_EQUAL_OP", "_NOT_EQUAL_OP", "_EQUAL_OP", "_LEFT_BRACKET",
  "_RIGHT_BRACKET", "_LEFT_BRACE", "_RIGHT_BRACE", "_END_DIVIDED_CHAR",
  "_COMMA_DIVIDED_CHAR", "_COMMENT_LEFT", "_COMMENT_RIGHT",
  "_LEFT_SELF_PLUS_UNARY_OP", "_LEFT_SELF_MINUS_UNARY_OP",
  "_RIGHT_SELF_PLUS_UNARY_OP", "_RIGHT_SELF_MINUS_UNARY_OP", "_UMINUS_OP",
  "$accept", "input", "code", "if_conditions", "while_conditions", "block",
  "sentence", "exp", "assign_series", "declaration_series",
  "var_declaration", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -62

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -62,     2,    53,   -62,    44,   -62,   -62,   -62,   -30,   -29,
     -62,   -62,   -62,   -62,   -31,     6,   -62,   -62,   -62,   -62,
     -62,   -62,    38,    38,    38,    13,   -62,    44,   -13,   -20,
     -62,   -62,   -62,    38,    38,    38,    14,    45,   135,    96,
     104,   -62,    38,     6,   -62,   -62,   -62,   -62,    69,   -62,
     -62,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    10,    10,   135,   -62,   -62,    38,
      -3,    -3,   -62,   -62,   -62,    62,    62,   161,   161,   161,
     161,   156,   156,    37,   -62,   127,     8,   -62,   -62,   -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,    46,    48,    47,     0,     0,
       3,     5,     6,     4,     0,     0,    40,    41,    42,    43,
      44,    45,     0,     0,     0,     0,     7,    49,    13,    15,
      16,    17,    18,     0,     0,     0,     0,     0,    14,     0,
       0,    12,     0,     0,    19,    20,    38,    39,     0,    21,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    37,     0,
      23,    24,    25,    26,    27,    34,    35,    28,    29,    30,
      31,    33,    32,     8,    11,     0,     0,    36,    10,     9
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,    42,   -32,   -62,   -61,   -62,   -23,    28,   -62,
      15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    11,    12,    13,    14,    38,    22,    15,
      28
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    40,     3,    83,    84,    23,    24,    44,    26,    27,
      46,    47,    48,    53,    54,    55,     4,    49,     8,    66,
       5,     6,     7,     8,     9,    89,    45,    43,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    29,    30,    31,    32,    10,    85,    10,    50,    86,
      10,    41,    25,    33,    88,    42,     4,    16,    67,    34,
       5,     6,     7,     8,     9,     0,    17,    18,    19,    20,
      21,     0,     0,    35,     0,     0,    51,    52,    53,    54,
      55,    36,    37,    51,    52,    53,    54,    55,    56,    57,
      10,    58,    59,    60,    61,    62,    63,     0,    58,    59,
      60,    61,    62,    63,     0,    68,     0,     0,     0,    69,
      51,    52,    53,    54,    55,    56,    57,     0,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    58,    59,    60,    61,    62,    63,     0,
      65,    51,    52,    53,    54,    55,    56,    57,     0,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    87,    58,    59,    60,    61,    62,    63,
      51,    52,    53,    54,    55,    51,    52,    53,    54,    55,
       0,     0,     0,     0,     0,    58,    59,    60,    61
};

static const yytype_int8 yycheck[] =
{
      23,    24,     0,    64,    65,    35,    35,    27,    39,     3,
      33,    34,    35,    16,    17,    18,     3,     3,    10,    42,
       7,     8,     9,    10,    11,    86,    46,    40,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     3,     4,     5,     6,    37,    69,    37,     3,    12,
      37,    38,    10,    15,    86,    27,     3,    13,    43,    21,
       7,     8,     9,    10,    11,    -1,    22,    23,    24,    25,
      26,    -1,    -1,    35,    -1,    -1,    14,    15,    16,    17,
      18,    43,    44,    14,    15,    16,    17,    18,    19,    20,
      37,    29,    30,    31,    32,    33,    34,    -1,    29,    30,
      31,    32,    33,    34,    -1,    36,    -1,    -1,    -1,    40,
      14,    15,    16,    17,    18,    19,    20,    -1,    14,    15,
      16,    17,    18,    19,    20,    29,    30,    31,    32,    33,
      34,    -1,    36,    29,    30,    31,    32,    33,    34,    -1,
      36,    14,    15,    16,    17,    18,    19,    20,    -1,    14,
      15,    16,    17,    18,    19,    20,    29,    30,    31,    32,
      33,    34,    -1,    36,    29,    30,    31,    32,    33,    34,
      14,    15,    16,    17,    18,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    49,    50,     0,     3,     7,     8,     9,    10,    11,
      37,    51,    52,    53,    54,    57,    13,    22,    23,    24,
      25,    26,    56,    35,    35,    50,    39,     3,    58,     3,
       4,     5,     6,    15,    21,    35,    43,    44,    55,    55,
      55,    38,    56,    40,    27,    46,    55,    55,    55,     3,
       3,    14,    15,    16,    17,    18,    19,    20,    29,    30,
      31,    32,    33,    34,    36,    36,    55,    58,    36,    40,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    53,    53,    55,    12,    36,    51,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    50,    50,    51,    51,
      51,    52,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    57,    57,    57,    58,
      58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     3,     5,     7,
       7,     5,     3,     2,     3,     1,     1,     1,     1,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3
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
#line 57 "main.y" /* yacc.c:1661  */
    {
            display((yyvsp[0].tree_node), 0);
            symbol_table * root = create_symbol_table();
            create_tables(root, 0, (yyvsp[0].tree_node), -1);
            print_table(root, "", 1);
            free_symbol_table(root, 0);
        }
#line 1368 "main.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 66 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->kind = BLANK_NODE;
        }
#line 1377 "main.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 70 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = NOT_EXP;
            strcpy((yyval.tree_node)->op_name, (yyvsp[0].tree_node)->op_name);
            (yyval.tree_node)->kind = CODE_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-1].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1390 "main.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 78 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = NOT_EXP;
            strcpy((yyval.tree_node)->op_name, (yyvsp[0].tree_node)->op_name);
            (yyval.tree_node)->kind = CODE_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-1].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1403 "main.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 86 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = NOT_EXP;
            strcpy((yyval.tree_node)->op_name, (yyvsp[0].tree_node)->op_name);
            (yyval.tree_node)->kind = CODE_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-1].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1416 "main.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 94 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = NOT_EXP;
            strcpy((yyval.tree_node)->op_name, (yyvsp[-1].tree_node)->op_name);
            (yyval.tree_node)->kind = CODE_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[-1].tree_node);
        }
#line 1429 "main.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 105 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            strcpy((yyval.tree_node)->op_name, "if");
            (yyval.tree_node)->exp_kind = NOT_EXP;
            (yyval.tree_node)->kind = IF_CONDITION_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1442 "main.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 114 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            strcpy((yyval.tree_node)->op_name, "if-else");
            (yyval.tree_node)->exp_kind = NOT_EXP;
            (yyval.tree_node)->kind = IF_ELSE_CONDITION_NODE;
            (yyval.tree_node)->trinary_children.first_child = (yyvsp[-4].tree_node);
            (yyval.tree_node)->trinary_children.second_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->trinary_children.third_child = (yyvsp[0].tree_node);
        }
#line 1456 "main.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 124 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            strcpy((yyval.tree_node)->op_name, "if-else");
            (yyval.tree_node)->exp_kind = NOT_EXP;
            (yyval.tree_node)->kind = IF_ELSE_CONDITION_NODE;
            (yyval.tree_node)->trinary_children.first_child = (yyvsp[-4].tree_node);
            (yyval.tree_node)->trinary_children.second_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->trinary_children.third_child = (yyvsp[0].tree_node);
        }
#line 1470 "main.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 136 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            strcpy((yyval.tree_node)->op_name, "while");
            (yyval.tree_node)->exp_kind = NOT_EXP;
            (yyval.tree_node)->kind = WHILE_CONDITION_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1483 "main.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 147 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = NOT_EXP;
            strcpy((yyval.tree_node)->op_name, "block");
            (yyval.tree_node)->kind = BLOCK_NODE;
            (yyval.tree_node)->unary_child.child = (yyvsp[-1].tree_node);
        }
#line 1495 "main.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 157 "main.y" /* yacc.c:1661  */
    {
            if (((yyvsp[-1].tree_node)->exp_kind != (yyvsp[0].tree_node)->exp_kind) && (yyvsp[0].tree_node)->exp_kind != NOT_EXP) {
                yyerror("value fit error");
                exit(0);
            } else {
                (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
                (yyval.tree_node)->exp_kind = (yyvsp[-1].tree_node)->exp_kind;
                strcpy((yyval.tree_node)->op_name, (yyvsp[-1].tree_node)->op_name);
                (yyval.tree_node)->kind = DATA_DECLARE_NODE;
                (yyval.tree_node)->unary_child.child = (yyvsp[0].tree_node);
            }
        }
#line 1512 "main.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 169 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = (yyvsp[0].tree_node)->exp_kind;
            strcpy((yyval.tree_node)->complex_op.op1, (yyvsp[-2].name_value));
            strcpy((yyval.tree_node)->complex_op.op2, (yyvsp[-1].tree_node)->op_name);
            (yyval.tree_node)->complex_op.var_pos = 1;
            (yyval.tree_node)->kind = DATA_ASSIGN_NODE;
            (yyval.tree_node)->unary_child.child = (yyvsp[0].tree_node);
        }
#line 1526 "main.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 184 "main.y" /* yacc.c:1661  */
    {         
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->kind = VARIABLE_NODE;
            (yyval.tree_node)->exp_kind = NOT_EXP;         // fix me
            strcpy((yyval.tree_node)->variable_name, (yyvsp[0].name_value));
        }
#line 1537 "main.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 190 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->kind = CONST_INT_NODE;
            (yyval.tree_node)->exp_kind = INTEGER_EXP;
            (yyval.tree_node)->int_value = (yyvsp[0].int_value);
        }
#line 1548 "main.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 196 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->kind = CONST_FLOAT_NODE;
            (yyval.tree_node)->exp_kind = FLOAT_EXP;
            (yyval.tree_node)->float_value = (yyvsp[0].float_value);
        }
#line 1559 "main.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 202 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->kind = CONST_CHAR_NODE;
            (yyval.tree_node)->exp_kind = CHAR_EXP;
            (yyval.tree_node)->char_value = (yyvsp[0].char_value)[1];
        }
#line 1570 "main.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 211 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            strcpy((yyval.tree_node)->complex_op.op1, (yyvsp[-1].name_value));
            strcpy((yyval.tree_node)->complex_op.op2, "++");
            (yyval.tree_node)->complex_op.var_pos = 1;
            (yyval.tree_node)->exp_kind = INTEGER_EXP;     // fix me
            (yyval.tree_node)->kind = UNARY_OP_NODE;
        }
#line 1583 "main.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 220 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            strcpy((yyval.tree_node)->complex_op.op1, (yyvsp[-1].name_value));
            strcpy((yyval.tree_node)->complex_op.op2, "--");
            (yyval.tree_node)->complex_op.var_pos = 1;
            (yyval.tree_node)->exp_kind = INTEGER_EXP;     // fix me
            (yyval.tree_node)->kind = UNARY_OP_NODE;
        }
#line 1596 "main.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 229 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            strcpy((yyval.tree_node)->complex_op.op1, "++");
            strcpy((yyval.tree_node)->complex_op.op2, (yyvsp[0].name_value));
            (yyval.tree_node)->complex_op.var_pos = 2;
            (yyval.tree_node)->exp_kind = INTEGER_EXP;     // fix me
            (yyval.tree_node)->kind = UNARY_OP_NODE;
        }
#line 1609 "main.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 238 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            strcpy((yyval.tree_node)->complex_op.op1, "--");
            strcpy((yyval.tree_node)->complex_op.op2, (yyvsp[0].name_value));
            (yyval.tree_node)->complex_op.var_pos = 2;
            (yyval.tree_node)->exp_kind = INTEGER_EXP;     // fix me
            (yyval.tree_node)->kind = UNARY_OP_NODE;
        }
#line 1622 "main.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 249 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = get_exp_kind((yyvsp[-2].tree_node), (yyvsp[0].tree_node));
            strcpy((yyval.tree_node)->op_name, "+");
            (yyval.tree_node)->kind = BINARY_OP_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1635 "main.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 257 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = get_exp_kind((yyvsp[-2].tree_node), (yyvsp[0].tree_node));
            strcpy((yyval.tree_node)->op_name, "-");
            (yyval.tree_node)->kind = BINARY_OP_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1648 "main.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 265 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = get_exp_kind((yyvsp[-2].tree_node), (yyvsp[0].tree_node));
            strcpy((yyval.tree_node)->op_name, "*");
            (yyval.tree_node)->kind = BINARY_OP_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1661 "main.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 273 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = get_exp_kind((yyvsp[-2].tree_node), (yyvsp[0].tree_node));
            strcpy((yyval.tree_node)->op_name, "/");
            (yyval.tree_node)->kind = BINARY_OP_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1674 "main.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 281 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = get_exp_kind((yyvsp[-2].tree_node), (yyvsp[0].tree_node));
            strcpy((yyval.tree_node)->op_name, "%");
            (yyval.tree_node)->kind = BINARY_OP_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1687 "main.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 292 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = INTEGER_EXP;
            strcpy((yyval.tree_node)->op_name, ">");
            (yyval.tree_node)->kind = BINARY_OP_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1700 "main.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 300 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = INTEGER_EXP;
            strcpy((yyval.tree_node)->op_name, "<");
            (yyval.tree_node)->kind = BINARY_OP_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1713 "main.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 308 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = INTEGER_EXP;
            strcpy((yyval.tree_node)->op_name, ">=");
            (yyval.tree_node)->kind = BINARY_OP_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1726 "main.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 316 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = INTEGER_EXP;
            strcpy((yyval.tree_node)->op_name, "<=");
            (yyval.tree_node)->kind = BINARY_OP_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1739 "main.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 324 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = INTEGER_EXP;
            strcpy((yyval.tree_node)->op_name, "==");
            (yyval.tree_node)->kind = BINARY_OP_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1752 "main.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 332 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = INTEGER_EXP;
            strcpy((yyval.tree_node)->op_name, "!=");
            (yyval.tree_node)->kind = BINARY_OP_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1765 "main.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 343 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = INTEGER_EXP;
            strcpy((yyval.tree_node)->op_name, "||");
            (yyval.tree_node)->kind = BINARY_OP_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1778 "main.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 351 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = INTEGER_EXP;
            strcpy((yyval.tree_node)->op_name, "&&");
            (yyval.tree_node)->kind = BINARY_OP_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
    }
#line 1791 "main.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 362 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = get_exp_kind((yyvsp[-3].tree_node), (yyvsp[-1].tree_node));
            strcpy((yyval.tree_node)->op_name, ",");
            (yyval.tree_node)->kind = BINARY_OP_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-3].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[-1].tree_node);
        }
#line 1804 "main.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 373 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = (yyvsp[-1].tree_node)->exp_kind;
            strcpy((yyval.tree_node)->op_name, "()");
            (yyval.tree_node)->kind = S_UNARY_OP_NODE;
            (yyval.tree_node)->unary_child.child = (yyvsp[-1].tree_node);
        }
#line 1816 "main.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 383 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = (yyvsp[0].tree_node)->exp_kind;
            strcpy((yyval.tree_node)->op_name, "-");
            (yyval.tree_node)->kind = S_UNARY_OP_NODE;
            (yyval.tree_node)->unary_child.child = (yyvsp[0].tree_node);
        }
#line 1828 "main.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 391 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = (yyvsp[0].tree_node)->exp_kind;
            strcpy((yyval.tree_node)->op_name, "!");
            (yyval.tree_node)->kind = S_UNARY_OP_NODE;
            (yyval.tree_node)->unary_child.child = (yyvsp[0].tree_node);
        }
#line 1840 "main.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 401 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            strcpy((yyval.tree_node)->op_name, "=");
        }
#line 1849 "main.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 406 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            strcpy((yyval.tree_node)->op_name, "+=");
        }
#line 1858 "main.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 411 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            strcpy((yyval.tree_node)->op_name, "-=");
        }
#line 1867 "main.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 416 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            strcpy((yyval.tree_node)->op_name, "*=");
        }
#line 1876 "main.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 421 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            strcpy((yyval.tree_node)->op_name, "/=");
        }
#line 1885 "main.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 426 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            strcpy((yyval.tree_node)->op_name, "%=");
        }
#line 1894 "main.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 433 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = INTEGER_EXP;
            strcpy((yyval.tree_node)->op_name, "int");
        }
#line 1904 "main.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 438 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = CHAR_EXP;
            strcpy((yyval.tree_node)->op_name, "char");
        }
#line 1914 "main.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 443 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = FLOAT_EXP;
            strcpy((yyval.tree_node)->op_name, "float");
        }
#line 1924 "main.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 451 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = NOT_EXP;        // fix me  
            strcpy((yyval.tree_node)->variable_name, (yyvsp[0].name_value));
            (yyval.tree_node)->kind = DATA_DECLARE_VAR_NODE;
        }
#line 1935 "main.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 457 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = (yyvsp[0].tree_node)->exp_kind;
            strcpy((yyval.tree_node)->complex_op.op1, (yyvsp[-2].name_value));
            strcpy((yyval.tree_node)->complex_op.op2, (yyvsp[-1].tree_node)->op_name);
            (yyval.tree_node)->complex_op.var_pos = 1;
            (yyval.tree_node)->kind = DATA_DECLARE_UNARY_NODE;
            (yyval.tree_node)->unary_child.child = (yyvsp[0].tree_node);
        }
#line 1949 "main.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 466 "main.y" /* yacc.c:1661  */
    {
            (yyval.tree_node) = (tree_node *) malloc (sizeof(tree_node));
            (yyval.tree_node)->exp_kind = (yyvsp[-2].tree_node)->exp_kind;
            strcpy((yyval.tree_node)->op_name, ",");
            (yyval.tree_node)->kind = DATA_DECLARE_BINARY_NODE;
            (yyval.tree_node)->binary_children.left_child = (yyvsp[-2].tree_node);
            (yyval.tree_node)->binary_children.right_child = (yyvsp[0].tree_node);
        }
#line 1962 "main.tab.c" /* yacc.c:1661  */
    break;


#line 1966 "main.tab.c" /* yacc.c:1661  */
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
#line 476 "main.y" /* yacc.c:1906  */


int main(int argc, char *argv[]){
	yyin = fopen(argv[1], "r");
	if (!yyin) {
        return 0;
    }
	yyparse();
	return 0;
}

enum exp_kind get_exp_kind (struct tree_node * e1, struct tree_node * e2) {
    if (e1->exp_kind == FLOAT_EXP || e2->exp_kind == FLOAT_EXP) {
        return FLOAT_EXP;
    } else if (e1->exp_kind == CHAR_EXP && e2->exp_kind == CHAR_EXP) {
        return CHAR_EXP;
    } else if (e1->exp_kind == NOT_EXP && e2->exp_kind == NOT_EXP) {
        return NOT_EXP;
    } else {
        return INTEGER_EXP;
    }
}