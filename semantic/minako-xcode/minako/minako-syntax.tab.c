/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "minako-syntax.tab.h".  */
#ifndef YY_YY_USERS_DAIZHIRUI_DOCUMENTS_COMPILERBAU_HAUSAUFGABEN_COMPILERBAU_BUNG_SEMANTIC_MINAKO_XCODE_MINAKO_MINAKO_SYNTAX_TAB_H_INCLUDED
# define YY_YY_USERS_DAIZHIRUI_DOCUMENTS_COMPILERBAU_HAUSAUFGABEN_COMPILERBAU_BUNG_SEMANTIC_MINAKO_XCODE_MINAKO_MINAKO_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 4 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:355  */

	#include <stdlib.h>
	#include <stdarg.h>
	#include "symtab.h"
	#include "syntree.h"

	extern void yyerror(const char*, ...);
	extern int yylex(void);
	extern int yylineno;
	extern FILE* yyin;

#line 109 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AND = 258,
    OR = 259,
    EQ = 260,
    NEQ = 261,
    LEQ = 262,
    GEQ = 263,
    LSS = 264,
    GRT = 265,
    KW_BOOLEAN = 266,
    KW_DO = 267,
    KW_ELSE = 268,
    KW_FLOAT = 269,
    KW_FOR = 270,
    KW_IF = 271,
    KW_INT = 272,
    KW_PRINTF = 273,
    KW_RETURN = 274,
    KW_VOID = 275,
    KW_WHILE = 276,
    CONST_INT = 277,
    CONST_FLOAT = 278,
    CONST_BOOLEAN = 279,
    CONST_STRING = 280,
    ID = 281,
    UMINUS = 282,
    LOWER_THAN_ELSE = 283
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 67 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:355  */

	char* string;
	double floatValue;
	int intValue;

	symtab_symbol_t* symbol;
	syntree_nid node;
	syntree_node_type type;

#line 160 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);
/* "%code provides" blocks.  */
#line 16 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:355  */

	extern symtab_t* tab;
	extern syntree_t* ast;

#line 178 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:355  */

#endif /* !YY_YY_USERS_DAIZHIRUI_DOCUMENTS_COMPILERBAU_HAUSAUFGABEN_COMPILERBAU_BUNG_SEMANTIC_MINAKO_XCODE_MINAKO_MINAKO_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 184 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 21 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:359  */

	/* globale Zeiger auf Symboltabelle und abstrakten Syntaxbaum */
	symtab_t* tab;
	syntree_t* ast;

	/* interner (globaler) Zeiger auf die aktuell geparste Funktion */
	static symtab_symbol_t* func;

	/**@brief Kombiniert zwei Ausdrücke einer binären Operation und stellt
	 * sicher, dass sie auf deren Typen definiert ist.
	 * @param id1  linke Seite
	 * @param id2  rechte Seite
	 * @param op   Operator
	 * @return ID des Operatorknoten
	 */
	static syntree_nid
	combine(syntree_nid id1, syntree_nid id2, syntree_node_tag op);

	/* Hilfsfunktionen */

	/**@brief Gibt den Zeiger auf einen Knoten der entsprechenden ID zurück.
	 */
	static inline syntree_node_t*
	nodePtr(syntree_nid id) { return syntreeNodePtr(ast, id); }

	/**@brief Gibt den Knotentyp zurück.
	 */
	static inline syntree_node_type
	nodeType(syntree_nid id) { return nodePtr(id)->type; }

	/**@brief Gibt den Wert eines Knotens zurück.
	 */
	static inline union syntree_node_value_u*
	nodeValue(syntree_nid id) { return &nodePtr(id)->value; }

	/**@brief Gibt den ersten Kindknoten eines Containers zurück.
	 */
	static inline syntree_nid
	nodeFirst(syntree_nid id) { return nodePtr(id)->value.container.first; }

	/**@brief Gibt den Folgeknoten eines Knotens zurück.
	 */
	static inline syntree_nid
	nodeNext(syntree_nid id) { return nodePtr(id)->next; }

#line 232 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:359  */

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
#define YYLAST   183

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

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
      34,    35,    29,    27,    38,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    39,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      25,    26,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   143,   143,   154,   155,   157,   161,   161,   181,   183,
     187,   188,   192,   230,   265,   266,   270,   272,   278,   279,
     284,   284,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   303,   303,   303,   317,   319,   319,   324,   324,
     335,   335,   349,   349,   361,   361,   373,   380,   393,   395,
     400,   409,   430,   431,   432,   433,   437,   462,   480,   484,
     485,   487,   489,   491,   493,   495,   500,   502,   504,   506,
     508,   510,   512,   516,   518,   520,   522,   523,   528
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "OR", "EQ", "NEQ", "LEQ", "GEQ",
  "LSS", "GRT", "KW_BOOLEAN", "KW_DO", "KW_ELSE", "KW_FLOAT", "KW_FOR",
  "KW_IF", "KW_INT", "KW_PRINTF", "KW_RETURN", "KW_VOID", "KW_WHILE",
  "CONST_INT", "CONST_FLOAT", "CONST_BOOLEAN", "CONST_STRING", "ID", "'+'",
  "'-'", "'*'", "'/'", "UMINUS", "LOWER_THAN_ELSE", "';'", "'('", "')'",
  "'{'", "'}'", "','", "'='", "$accept", "start", "program",
  "functiondefinition", "$@1", "opt_parameterlist", "parameterlist",
  "parameter", "functioncall", "opt_argumentlist", "argumentlist",
  "statementlist", "block", "$@2", "statement", "ifstatement", "$@3",
  "$@4", "opt_else", "$@5", "forstatement", "$@6", "$@7",
  "dowhilestatement", "$@8", "whilestatement", "$@9", "returnstatement",
  "printf", "declassignment", "type", "statassignment", "assignment",
  "expr", "simpexpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    43,    45,    42,
      47,   282,   283,    59,    40,    41,   123,   125,    44,    61
};
# endif

#define YYPACT_NINF -109

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-109)))

#define YYTABLE_NINF -51

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -109,     6,    60,  -109,  -109,  -109,  -109,  -109,  -109,   -29,
      -4,  -109,   -12,    39,    -5,  -109,  -109,  -109,   -11,    76,
      39,  -109,  -109,  -109,     8,    60,    39,    39,     5,  -109,
      14,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    18,  -109,     2,    22,    19,    28,  -109,
    -109,  -109,  -109,     4,    16,    16,    16,    16,    16,    16,
       4,     4,  -109,  -109,    15,    60,  -109,  -109,    39,  -109,
    -109,  -109,    75,  -109,    26,    36,    38,    39,    41,    13,
    -109,  -109,    43,  -109,  -109,  -109,  -109,    55,  -109,    64,
      70,    72,    80,    74,   115,    89,    39,   142,  -109,    39,
      39,  -109,  -109,  -109,  -109,  -109,  -109,    85,  -109,   104,
      60,   111,   107,   108,   109,   110,  -109,   102,   112,   114,
     130,   116,  -109,  -109,  -109,  -109,  -109,    39,    76,    76,
     115,   115,   113,   117,   138,  -109,  -109,  -109,   111,   111,
     159,   139,   140,  -109,  -109,   115,   115,   115,  -109,  -109,
    -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,    52,    53,    54,    55,     5,     0,
       0,     4,     6,     0,     0,    73,    74,    75,    77,     0,
       0,    76,    51,    58,    59,     8,    14,     0,    77,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,    10,     0,     0,    15,    16,
      57,    78,    71,    68,    60,    61,    62,    63,    64,    65,
      66,    67,    69,    70,     0,     0,    12,    13,     0,    18,
      11,    17,     0,    42,     0,     0,     0,    46,     0,     0,
      20,     7,     0,    31,    19,    22,    23,     0,    24,     0,
       0,     0,     0,     0,     0,    38,     0,     0,    47,     0,
       0,    18,    30,    26,    25,    27,    28,    50,    29,     0,
       0,     0,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,    32,    49,    48,    44,    21,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    45,    43,     0,     0,
      35,     0,     0,    36,    34,     0,     0,     0,    39,    41,
      37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -109,  -109,  -109,  -109,  -109,  -109,   118,  -109,   -62,  -109,
    -109,    77,  -109,  -109,   -89,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,    -2,
      -1,  -108,   -18,  -103,   121
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,    14,    43,    44,    45,    21,    47,
      48,    72,    83,   101,    84,    85,   130,   140,   144,   147,
      86,   110,   111,    87,    94,    88,   131,    89,    90,    91,
      92,    93,    22,    23,    24
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    10,    30,   121,    11,   109,     3,    31,    49,    50,
      82,    31,    32,    33,    34,    35,    36,    37,    38,    31,
      32,   -50,    12,    26,    46,   133,   134,    13,    27,    25,
     141,   142,    82,    41,    42,    39,    40,    41,    42,    26,
      65,   135,   136,    39,    40,    41,    42,    26,    66,    51,
      71,    69,   100,    64,    67,    82,   148,   149,   150,    98,
      95,    15,    16,    17,    46,    18,    68,    19,    82,    82,
      96,     4,    97,    20,     5,    99,   102,     6,   112,   114,
       7,   115,   116,    82,    82,    82,     4,    73,   103,     5,
      74,    75,     6,    76,    77,     7,    78,   104,    15,    16,
      17,    79,    28,   105,    19,   106,   107,   108,   119,   132,
      20,    80,    81,     4,    73,   -40,     5,    74,    75,     6,
      76,    77,     7,    78,    13,   118,     4,    73,    79,     5,
      74,    75,     6,    76,    77,     7,    78,   120,    80,   126,
      29,    79,   122,   123,   124,   125,   127,   128,   137,   129,
     138,    80,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    15,    16,    17,   113,    18,   100,
      19,   139,   143,     0,   145,   146,    20,     0,   117,     0,
       0,     0,     0,    70
};

static const yytype_int16 yycheck[] =
{
       2,     2,    20,   111,    33,    94,     0,     3,    26,    27,
      72,     3,     4,     5,     6,     7,     8,     9,    10,     3,
       4,    33,    26,    34,    25,   128,   129,    39,    39,    34,
     138,   139,    94,    29,    30,    27,    28,    29,    30,    34,
      38,   130,   131,    27,    28,    29,    30,    34,    26,    35,
      68,    36,    39,    35,    35,   117,   145,   146,   147,    77,
      34,    22,    23,    24,    65,    26,    38,    28,   130,   131,
      34,    11,    34,    34,    14,    34,    33,    17,    96,    97,
      20,    99,   100,   145,   146,   147,    11,    12,    33,    14,
      15,    16,    17,    18,    19,    20,    21,    33,    22,    23,
      24,    26,    26,    33,    28,    33,    26,    33,   110,   127,
      34,    36,    37,    11,    12,    26,    14,    15,    16,    17,
      18,    19,    20,    21,    39,    21,    11,    12,    26,    14,
      15,    16,    17,    18,    19,    20,    21,    26,    36,    37,
      19,    26,    35,    35,    35,    35,    34,    33,    35,    33,
      33,    36,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    22,    23,    24,    25,    26,    39,
      28,    33,    13,    -1,    35,    35,    34,    -1,   101,    -1,
      -1,    -1,    -1,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,    11,    14,    17,    20,    43,    69,
      70,    33,    26,    39,    44,    22,    23,    24,    26,    28,
      34,    48,    72,    73,    74,    34,    34,    39,    26,    74,
      72,     3,     4,     5,     6,     7,     8,     9,    10,    27,
      28,    29,    30,    45,    46,    47,    70,    49,    50,    72,
      72,    35,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    35,    38,    26,    35,    38,    36,
      46,    72,    51,    12,    15,    16,    18,    19,    21,    26,
      36,    37,    48,    52,    54,    55,    60,    63,    65,    67,
      68,    69,    70,    71,    64,    34,    34,    34,    72,    34,
      39,    53,    33,    33,    33,    33,    33,    26,    33,    54,
      61,    62,    72,    25,    72,    72,    72,    51,    21,    69,
      26,    71,    35,    35,    35,    35,    37,    34,    33,    33,
      56,    66,    72,    73,    73,    54,    54,    35,    33,    33,
      57,    71,    71,    13,    58,    35,    35,    59,    54,    54,
      54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    42,    44,    43,    45,    45,
      46,    46,    47,    48,    49,    49,    50,    50,    51,    51,
      53,    52,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    56,    57,    55,    58,    59,    58,    61,    60,
      62,    60,    64,    63,    66,    65,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    71,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     3,     2,     0,     9,     0,     1,
       1,     3,     2,     4,     0,     1,     1,     3,     0,     2,
       0,     4,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     1,     0,     0,     8,     0,     0,     3,     0,    10,
       0,    10,     0,     7,     0,     6,     1,     2,     4,     4,
       2,     4,     1,     1,     1,     1,     3,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     1,     1,     3
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
  switch (yytype)
    {
          case 22: /* CONST_INT  */
#line 79 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      { fprintf(yyoutput, "%i", ((*yyvaluep).intValue)); }
#line 834 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 23: /* CONST_FLOAT  */
#line 78 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      { fprintf(yyoutput, "%g", ((*yyvaluep).floatValue)); }
#line 840 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 24: /* CONST_BOOLEAN  */
#line 79 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      { fprintf(yyoutput, "%i", ((*yyvaluep).intValue)); }
#line 846 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 25: /* CONST_STRING  */
#line 77 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      { fprintf(yyoutput, "\"%s\"", ((*yyvaluep).string)); }
#line 852 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 26: /* ID  */
#line 77 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      { fprintf(yyoutput, "\"%s\"", ((*yyvaluep).string)); }
#line 858 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 42: /* program  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 870 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 43: /* functiondefinition  */
#line 87 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	putc('\n', yyoutput);
	symtabPrint(tab, yyoutput);
}
#line 879 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 48: /* functioncall  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 891 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 49: /* opt_argumentlist  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 903 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 50: /* argumentlist  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 915 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 51: /* statementlist  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 927 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 52: /* block  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 939 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 54: /* statement  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 951 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 55: /* ifstatement  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 963 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 58: /* opt_else  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 975 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 60: /* forstatement  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 987 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 63: /* dowhilestatement  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 999 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 65: /* whilestatement  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 1011 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 67: /* returnstatement  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 1023 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 68: /* printf  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 1035 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 69: /* declassignment  */
#line 87 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	putc('\n', yyoutput);
	symtabPrint(tab, yyoutput);
}
#line 1044 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 71: /* statassignment  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 1056 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 72: /* assignment  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 1068 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 73: /* expr  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 1080 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;

    case 74: /* simpexpr  */
#line 80 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:684  */
      {
	if (((*yyvaluep).node) != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, ((*yyvaluep).node), yyoutput, 1);
	}
}
#line 1092 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:684  */
        break;


      default:
        break;
    }
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
  switch (yytype)
    {
          case 25: /* CONST_STRING  */
#line 92 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1258  */
      { free(((*yyvaluep).string)); }
#line 1439 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1258  */
        break;

    case 26: /* ID  */
#line 92 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1258  */
      { free(((*yyvaluep).string)); }
#line 1445 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1258  */
        break;


      default:
        break;
    }
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
#line 143 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {
		symtab_symbol_t* entry = symtabLookup(tab, "main");
        if (entry == NULL) { yyerror("main function is not defined."); }                /* ERROR: No main function */
		nodeValue(0)->program.body = syntreeNodeAppend(ast, (yyvsp[0].node), entry->body);
		nodeValue(0)->program.globals = symtabMaxGlobals(tab);
	}
#line 1714 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 3:
#line 154 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = syntreeNodeEmpty(ast, SYNTREE_TAG_Sequence); }
#line 1720 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 4:
#line 156 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { syntreeNodeAppend(ast, (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1726 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 6:
#line 161 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {
		/* globale Zeiger auf das aktuelle Funktionssymbol */
		func = symtabSymbol((yyvsp[0].string), (yyvsp[-1].type));
		func->is_function = 1;
		func->body = syntreeNodeEmpty(ast, SYNTREE_TAG_Function);

		if (symtabInsert(tab, func) != 0) {
            yyerror("double declaration of function %s.", (yyvsp[0].string));                       /* ERROR: Double declarations of function */
		} else {
			symtabEnter(tab);
		}
	}
#line 1743 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 7:
#line 173 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {

		syntreeNodeAppend(ast, func->body, (yyvsp[-1].node));                                      /* Store function body */
		nodeValue(func->body)->function.locals = symtabMaxLocals(tab);                  /* Record the number of local values */
		symtabLeave(tab);
	}
#line 1754 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 12:
#line 192 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {
		switch ((yyvsp[-1].type)) {
			case SYNTREE_TYPE_Boolean: {

				if (symtabInsert(tab, symtabSymbol((yyvsp[0].string), SYNTREE_TYPE_Boolean)) != 0) {
					yyerror("double declaration of parameter %s.", (yyvsp[0].string));                       /* ERROR: Double declarations of function */
				} else {
					symtabParam(func, symtabSymbol((yyvsp[0].string), SYNTREE_TYPE_Boolean));
					// foo(int a, int b)
					// int a, int b
				}
				break;
			}
			case SYNTREE_TYPE_Float: {

				if (symtabInsert(tab, symtabSymbol((yyvsp[0].string), SYNTREE_TYPE_Float)) != 0) {
					yyerror("double declaration of parameter %s.", (yyvsp[0].string));                       /* ERROR: Double declarations of function */
				} else {
					symtabParam(func, symtabSymbol((yyvsp[0].string), SYNTREE_TYPE_Float));
				}
				break;
			}
			case SYNTREE_TYPE_Integer: {

				if (symtabInsert(tab, symtabSymbol((yyvsp[0].string), SYNTREE_TYPE_Integer)) != 0) {
					yyerror("double declaration of parameter %s.", (yyvsp[0].string));                       /* ERROR: Double declarations of function */
				} else {
					symtabParam(func, symtabSymbol((yyvsp[0].string), SYNTREE_TYPE_Integer));
				}
				break;
			}
			case SYNTREE_TYPE_Void: yyerror("Parameter type cannot be void.");break;
			default: yyerror("Parameter type is wrong.(Internal error)");
		}
	}
#line 1794 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 13:
#line 230 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {
		symtab_symbol_t* fn = symtabLookup(tab, (yyvsp[-3].string));

		if (fn == NULL) {
			yyerror("unknown function '%s'", (yyvsp[-3].string));
		} else {
			symtab_symbol_t* paramList = fn->par_next;
			syntree_nid argumentListID = nodeFirst((yyvsp[-1].node));
			syntree_node_t* argumentList = syntreeNodePtr(ast, argumentListID);

			while(paramList != NULL) {
				if (argumentList == NULL) {
					yyerror("No enough argument for ''%s'.", (yyvsp[-3].string));
				}

				if (paramList->type != argumentList->type) {
					yyerror("Incompatabile argument for '%s'.", (yyvsp[-3].string));
				}
				paramList = paramList->par_next;
				argumentListID = nodeNext(argumentListID);
				argumentList = syntreeNodePtr(ast, argumentListID);
			}

			if (argumentListID != 0) {
				yyerror("Extra argument for '%s'.", (yyvsp[-3].string));
			}

			(yyval.node) = syntreeNodePair(ast, SYNTREE_TAG_Call, (yyvsp[-1].node), fn->body);
			nodePtr((yyval.node))->type = fn->type;
		}
	}
#line 1830 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 14:
#line 265 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = syntreeNodeEmpty(ast, SYNTREE_TAG_Sequence); }
#line 1836 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 16:
#line 271 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = syntreeNodeTag(ast, SYNTREE_TAG_Sequence, (yyvsp[0].node)); }
#line 1842 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 17:
#line 273 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = syntreeNodeAppend(ast, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1848 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 18:
#line 278 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = syntreeNodeEmpty(ast, SYNTREE_TAG_Sequence); }
#line 1854 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 19:
#line 280 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = syntreeNodeAppend(ast, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1860 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 20:
#line 284 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { symtabEnter(tab); }
#line 1866 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 21:
#line 286 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = (yyvsp[-1].node); symtabLeave(tab);   }
#line 1872 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 22:
#line 290 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1878 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 28:
#line 296 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1884 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 32:
#line 303 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { symtabEnter(tab); }
#line 1890 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 33:
#line 303 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { symtabLeave(tab); }
#line 1896 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 34:
#line 303 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {

		if (nodeType((yyvsp[-5].node)) != SYNTREE_TYPE_Boolean) {
			yyerror("Condition for if-statement is not boolean.");
		}

		(yyval.node) = syntreeNodePair(ast, SYNTREE_TAG_If, (yyvsp[-5].node), (yyvsp[-2].node));
		(yyval.node) = syntreeNodeAppend(ast, (yyval.node), (yyvsp[0].node));
	}
#line 1910 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 35:
#line 318 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = 0; }
#line 1916 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 36:
#line 319 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { symtabEnter(tab); }
#line 1922 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 37:
#line 320 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = (yyvsp[0].node); symtabLeave(tab); }
#line 1928 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 38:
#line 324 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { symtabEnter(tab); }
#line 1934 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 39:
#line 324 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {

		if (nodeType((yyvsp[-4].node)) != SYNTREE_TYPE_Boolean) {
			yyerror("Condition for for-loop is not boolean.");
		}

		(yyval.node) = syntreeNodePair(ast, SYNTREE_TAG_For, (yyvsp[-6].node), (yyvsp[-4].node));
		(yyval.node) = syntreeNodeAppend(ast, (yyval.node), (yyvsp[-2].node));
		(yyval.node) = syntreeNodeAppend(ast, (yyval.node), (yyvsp[0].node));
		symtabLeave(tab);
	}
#line 1950 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 40:
#line 335 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { symtabEnter(tab); }
#line 1956 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 41:
#line 335 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {

		if (nodeType((yyvsp[-4].node)) != SYNTREE_TYPE_Boolean) {
			yyerror("Condition for for-loop is not boolean.");
		}

		(yyval.node) = syntreeNodePair(ast, SYNTREE_TAG_For, (yyvsp[-6].node), (yyvsp[-4].node));
		(yyval.node) = syntreeNodeAppend(ast, (yyval.node), (yyvsp[-2].node));
		(yyval.node) = syntreeNodeAppend(ast, (yyval.node), (yyvsp[0].node));
		symtabLeave(tab);
	}
#line 1972 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 42:
#line 349 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { symtabEnter(tab); }
#line 1978 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 43:
#line 349 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {

		if (nodeType((yyvsp[-1].node)) != SYNTREE_TYPE_Boolean) {
			yyerror("Condition for do-while-loop is not boolean.");
		}

		(yyval.node) = syntreeNodePair(ast, SYNTREE_TAG_DoWhile, (yyvsp[-1].node), (yyvsp[-4].node));
		symtabLeave(tab);
	}
#line 1992 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 44:
#line 361 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { symtabEnter(tab); }
#line 1998 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 45:
#line 361 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {

		if (nodeType((yyvsp[-3].node)) != SYNTREE_TYPE_Boolean) {
			yyerror("Condition for while-loop is not boolean.");
		}

		(yyval.node) = syntreeNodePair(ast, SYNTREE_TAG_While, (yyvsp[-3].node), (yyvsp[0].node));
		symtabLeave(tab);
	}
#line 2012 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 46:
#line 373 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {
		if (func->type != SYNTREE_TYPE_Void) {
			yyerror("Missing return value for '%s'.", func->name);
		} else {
			(yyval.node) = syntreeNodeEmpty(ast, SYNTREE_TAG_Return);
		}
	}
#line 2024 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 47:
#line 380 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {
		if (func->type != nodeType((yyvsp[0].node))) {
			if (!(func->type == SYNTREE_TYPE_Float && nodeType((yyvsp[0].node)) == SYNTREE_TYPE_Integer)) {
				yyerror("Incompatabile return type for '%s'.", func->name);
			}
			(yyvsp[0].node) = syntreeNodeCast(ast, func->type, (yyvsp[0].node));
		}

		(yyval.node) = syntreeNodeTag(ast, SYNTREE_TAG_Return, (yyvsp[0].node));
	}
#line 2039 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 48:
#line 394 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = syntreeNodeTag(ast, SYNTREE_TAG_Print, (yyvsp[-1].node)); }
#line 2045 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 49:
#line 396 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = syntreeNodeTag(ast, SYNTREE_TAG_Print, syntreeNodeString(ast, (yyvsp[-1].string))); }
#line 2051 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 50:
#line 400 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {
		symtab_symbol_t* sym = symtabSymbol((yyvsp[0].string), (yyvsp[-1].type));

		if (symtabInsert(tab, sym) != 0) {
            yyerror("double declaration of variable %s.", (yyvsp[0].string));
		}

		(yyval.node) = syntreeNodeTag(ast, SYNTREE_TAG_Assign, syntreeNodeVariable(ast, sym));
	}
#line 2065 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 51:
#line 409 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {
		symtab_symbol_t* sym = symtabSymbol((yyvsp[-2].string), (yyvsp[-3].type));

		if (symtabInsert(tab, sym) != 0) {
            yyerror("double declaration of variable %s.", (yyvsp[-2].string));
		} else {

			if (sym->type != nodeType((yyvsp[0].node))) {
				if (!(sym->type == SYNTREE_TYPE_Float && nodeType((yyvsp[0].node)) == SYNTREE_TYPE_Integer)) {
					yyerror("Type incompatabile in statassignment.");
				}
				(yyvsp[0].node) = syntreeNodeCast(ast, sym->type, (yyvsp[0].node));
			}
		}

		(yyval.node) = syntreeNodePair(ast, SYNTREE_TAG_Assign,
							 syntreeNodeVariable(ast, sym), (yyvsp[0].node));
	}
#line 2088 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 52:
#line 430 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.type) = SYNTREE_TYPE_Boolean; }
#line 2094 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 53:
#line 431 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.type) = SYNTREE_TYPE_Float; }
#line 2100 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 54:
#line 432 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.type) = SYNTREE_TYPE_Integer; }
#line 2106 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 55:
#line 433 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.type) = SYNTREE_TYPE_Void; }
#line 2112 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 56:
#line 437 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {
		symtab_symbol_t* sym = symtabLookup(tab, (yyvsp[-2].string));

		if (sym == NULL) {
			yyerror("Variable reference before declaration.");
		} else {

			if (sym->is_function == 1) {
				yyerror("Assignment to function is not allowed.");
			}

			if (sym->type != nodeType((yyvsp[0].node))) {
				if (!(sym->type == SYNTREE_TYPE_Float && nodeType((yyvsp[0].node)) == SYNTREE_TYPE_Integer)) {
					yyerror("Type incompatabile in statassignment.");
				}
				(yyvsp[0].node) = syntreeNodeCast(ast, sym->type, (yyvsp[0].node));
			}

			(yyval.node) = syntreeNodePair(ast, SYNTREE_TAG_Assign,
			                     syntreeNodeVariable(ast, sym), (yyvsp[0].node));
		}
	}
#line 2139 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 57:
#line 462 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {
		symtab_symbol_t* sym = symtabLookup(tab, (yyvsp[-2].string));

		if (sym == NULL) {
			yyerror("Variable reference before declaration.");
		} else {
			if (sym->type != nodeType((yyvsp[0].node))) {
				if (!(sym->type == SYNTREE_TYPE_Float && nodeType((yyvsp[0].node)) == SYNTREE_TYPE_Integer)) {
					yyerror("Type incompatabile in statassignment.");
				}
				(yyvsp[0].node) = syntreeNodeCast(ast, sym->type, (yyvsp[0].node));
			}

			(yyval.node) = syntreeNodePair(ast, SYNTREE_TAG_Assign,
			                     syntreeNodeVariable(ast, sym), (yyvsp[0].node));
			nodePtr((yyval.node))->type = sym->type;
		}
	}
#line 2162 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 58:
#line 480 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2168 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 59:
#line 484 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2174 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 60:
#line 486 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = combine((yyvsp[-2].node), (yyvsp[0].node), SYNTREE_TAG_Eqt); }
#line 2180 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 61:
#line 488 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = combine((yyvsp[-2].node), (yyvsp[0].node), SYNTREE_TAG_Neq); }
#line 2186 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 62:
#line 490 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = combine((yyvsp[-2].node), (yyvsp[0].node), SYNTREE_TAG_Leq); }
#line 2192 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 63:
#line 492 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = combine((yyvsp[-2].node), (yyvsp[0].node), SYNTREE_TAG_Geq); }
#line 2198 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 64:
#line 494 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = combine((yyvsp[-2].node), (yyvsp[0].node), SYNTREE_TAG_Lst); }
#line 2204 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 65:
#line 496 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = combine((yyvsp[-2].node), (yyvsp[0].node), SYNTREE_TAG_Grt); }
#line 2210 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 66:
#line 501 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = combine((yyvsp[-2].node), (yyvsp[0].node), SYNTREE_TAG_Plus); }
#line 2216 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 67:
#line 503 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = combine((yyvsp[-2].node), (yyvsp[0].node), SYNTREE_TAG_Minus); }
#line 2222 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 68:
#line 505 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = combine((yyvsp[-2].node), (yyvsp[0].node), SYNTREE_TAG_LogOr); }
#line 2228 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 69:
#line 507 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = combine((yyvsp[-2].node), (yyvsp[0].node), SYNTREE_TAG_Times); }
#line 2234 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 70:
#line 509 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = combine((yyvsp[-2].node), (yyvsp[0].node), SYNTREE_TAG_Divide); }
#line 2240 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 71:
#line 511 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = combine((yyvsp[-2].node), (yyvsp[0].node), SYNTREE_TAG_LogAnd); }
#line 2246 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 72:
#line 512 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {
		(yyval.node) = syntreeNodeTag(ast, SYNTREE_TAG_Uminus, (yyvsp[0].node));
		nodePtr((yyval.node))->type = nodeType((yyvsp[0].node));
	}
#line 2255 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 73:
#line 517 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = syntreeNodeInteger(ast, (yyvsp[0].intValue)); }
#line 2261 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 74:
#line 519 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = syntreeNodeFloat(ast, (yyvsp[0].floatValue)); }
#line 2267 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 75:
#line 521 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = syntreeNodeBoolean(ast, (yyvsp[0].intValue)); }
#line 2273 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 77:
#line 523 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    {
		symtab_symbol_t* sym = symtabLookup(tab, (yyvsp[0].string));

		(yyval.node) = syntreeNodeVariable(ast, sym);
	}
#line 2283 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;

  case 78:
#line 529 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1663  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2289 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
    break;


#line 2293 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.tab.c" /* yacc.c:1663  */
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
#line 532 "/Users/daizhirui/Documents/Compilerbau/Hausaufgaben/Compilerbau--bung/semantic/minako-xcode/minako/minako-syntax.y" /* yacc.c:1907  */


int main(int argc, const char* argv[])
{
	symtab_t symtab;
	syntree_t syntree;

	int rc;

	/* belege die globalen Zeiger mit den lokalen Werten */
	tab = &symtab;
	ast = &syntree;

	/* versuche die Datei aus der Kommandozeile zu öffnen
	 * oder lies aus der Standardeingabe */
	yyin = (argc != 2) ? stdin : fopen(argv[1], "r");

	if (yyin == NULL)
		yyerror("couldn't open file %s\n", argv[1]);

	/* initialisiere die Hilfsstrukturen */
	if (symtabInit(tab))
	{
		fputs("out-of-memory error\n", stderr);
		exit(-1);
	}

	if (syntreeInit(ast))
	{
		fputs("out-of-memory error\n", stderr);
		exit(-1);
	}

	/* parse das Programm */
	yydebug = 1;
	rc = yyparse();

	/* gib' Symboltabelle und Syntaxbaum wieder frei */
	symtabRelease(&symtab);
	syntreeRelease(&syntree);

	return rc;
}

/**@brief Gibt eine Fehlermeldung aus und beendet das Programm mit Exitcode -1.
 * Die Funktion akzeptiert eine variable Argumentliste und nutzt die Syntax von
 * printf.
 * @param msg  die Fehlermeldung
 * @param ...  variable Argumentliste für die Formatierung von \p msg
 */
void yyerror(const char* msg, ...)
{
	va_list args;

	va_start(args, msg);
	fprintf(stderr, "Error in line %d: ", yylineno);
	vfprintf(stderr, msg, args);
	fprintf(stderr, "\n");
	va_end(args);
}

/**@brief Testet, ob eine binäre Operation zwischen zwei getypten Ausdrücken
 * definiert ist und bricht mit einem Fehler ab, falls nicht.
 * @param lhs  Typ des Operanden auf der linken Seite
 * @param rhs  Typ des Operanden auf der rechten Seite
 * @param op   Operator
 * @return resultierender Typ aus der Operation
 */
static syntree_node_type
combineTypes(syntree_node_type lhs_type, syntree_node_type rhs_type, syntree_node_tag op)
{
	/* lhs und rhs können sein:
	 * SYNTREE_TYPE_Void,
	 * SYNTREE_TYPE_Boolean,
	 * SYNTREE_TYPE_Integer,
	 * SYNTREE_TYPE_Float
	 */

	if (lhs_type == SYNTREE_TYPE_Void || rhs_type == SYNTREE_TYPE_Void) {
		yyerror("Invalid type: void.");
		return SYNTREE_TYPE_Integer;
	}

	if (lhs_type != rhs_type) {
		if (lhs_type == SYNTREE_TYPE_Boolean || rhs_type == SYNTREE_TYPE_Boolean) {
			yyerror("Incompatabile operands.");
			return SYNTREE_TYPE_Integer;
		}
	}

	switch (op)
	{
		case SYNTREE_TAG_Eqt:
		case SYNTREE_TAG_Neq:break;
		case SYNTREE_TAG_Leq:
		case SYNTREE_TAG_Geq:
		case SYNTREE_TAG_Lst:
		case SYNTREE_TAG_Grt:
		case SYNTREE_TAG_LogOr:
		case SYNTREE_TAG_LogAnd:
		case SYNTREE_TAG_Plus:
		case SYNTREE_TAG_Minus:
		case SYNTREE_TAG_Times:
		case SYNTREE_TAG_Divide: {
			if (lhs_type == SYNTREE_TYPE_Boolean) {
				yyerror("Invalid operator.");
				return SYNTREE_TYPE_Integer;
			}
			break;
		}
		default: {
		 	yyerror("unknown operation (internal error)");
			return SYNTREE_TYPE_Integer;
		}
	}

	/* just to avoid a warning */
	switch (op)
	{
		case SYNTREE_TAG_Eqt:
		case SYNTREE_TAG_Neq:
		case SYNTREE_TAG_Leq:
		case SYNTREE_TAG_Geq:
		case SYNTREE_TAG_Lst:
		case SYNTREE_TAG_Grt: return SYNTREE_TYPE_Boolean;
		case SYNTREE_TAG_LogOr:
		case SYNTREE_TAG_LogAnd:
		case SYNTREE_TAG_Plus:
		case SYNTREE_TAG_Minus:
		case SYNTREE_TAG_Times:
		case SYNTREE_TAG_Divide: {
			if (lhs_type == SYNTREE_TYPE_Float || rhs_type == SYNTREE_TYPE_Float) {
				return SYNTREE_TYPE_Float;
			} else {
				return lhs_type;
			}
		}
		default:return SYNTREE_TYPE_Integer;
	}
}

syntree_nid
combine(syntree_nid lhs, syntree_nid rhs, syntree_node_tag op)
{
	syntree_nid res;
	syntree_node_type lhs_type = nodeType(lhs);
	syntree_node_type rhs_type = nodeType(rhs);

	syntree_node_type type = combineTypes(lhs_type, rhs_type, op);

	if (lhs_type != rhs_type)
	{
		/* Situation: ein Integer und ein Float (impliziter Cast) */
		if (lhs_type != SYNTREE_TYPE_Float)
			lhs = syntreeNodeCast(ast, SYNTREE_TYPE_Float, lhs);
		else if (rhs_type != SYNTREE_TYPE_Float)
			rhs = syntreeNodeCast(ast, SYNTREE_TYPE_Float, rhs);
	}

	res = syntreeNodePair(ast, op, lhs, rhs);
	nodePtr(res)->type = type;
	return res;
}
