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
#line 2 "./compiler.y"

    #include "compiler_common.h"
    #include "compiler_util.h"
    #include "main.h"
    #include <stdlib.h>

    int yydebug = 1;

    char* tmp_var[10] = {};
    int tmp_var_index = 0;

    ObjectType tmp_cout[100];
    int tmp_cout_index = 0;
    char* tmp_ident = "";

    int array_size = 0;
    char* array_name = "";

    char function_sig[50] = "(";
    char func_sig_list[50][50];
    int func_sig_index = 0;
    char func_sig_none[10][50] = {"-"};
    char call_func_name[50][50];

#line 96 "./build/y.tab.c"

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

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COUT = 3,                       /* COUT  */
  YYSYMBOL_SHR = 4,                        /* SHR  */
  YYSYMBOL_SHL = 5,                        /* SHL  */
  YYSYMBOL_BAN = 6,                        /* BAN  */
  YYSYMBOL_BOR = 7,                        /* BOR  */
  YYSYMBOL_BNT = 8,                        /* BNT  */
  YYSYMBOL_BXO = 9,                        /* BXO  */
  YYSYMBOL_ADD = 10,                       /* ADD  */
  YYSYMBOL_SUB = 11,                       /* SUB  */
  YYSYMBOL_MUL = 12,                       /* MUL  */
  YYSYMBOL_DIV = 13,                       /* DIV  */
  YYSYMBOL_REM = 14,                       /* REM  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_GTR = 16,                       /* GTR  */
  YYSYMBOL_LES = 17,                       /* LES  */
  YYSYMBOL_GEQ = 18,                       /* GEQ  */
  YYSYMBOL_LEQ = 19,                       /* LEQ  */
  YYSYMBOL_EQL = 20,                       /* EQL  */
  YYSYMBOL_NEQ = 21,                       /* NEQ  */
  YYSYMBOL_LAN = 22,                       /* LAN  */
  YYSYMBOL_LOR = 23,                       /* LOR  */
  YYSYMBOL_VAL_ASSIGN = 24,                /* VAL_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 25,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 26,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 27,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 28,                /* DIV_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 29,                /* REM_ASSIGN  */
  YYSYMBOL_BAN_ASSIGN = 30,                /* BAN_ASSIGN  */
  YYSYMBOL_BOR_ASSIGN = 31,                /* BOR_ASSIGN  */
  YYSYMBOL_BXO_ASSIGN = 32,                /* BXO_ASSIGN  */
  YYSYMBOL_SHR_ASSIGN = 33,                /* SHR_ASSIGN  */
  YYSYMBOL_SHL_ASSIGN = 34,                /* SHL_ASSIGN  */
  YYSYMBOL_INC_ASSIGN = 35,                /* INC_ASSIGN  */
  YYSYMBOL_DEC_ASSIGN = 36,                /* DEC_ASSIGN  */
  YYSYMBOL_IF = 37,                        /* IF  */
  YYSYMBOL_ELSE = 38,                      /* ELSE  */
  YYSYMBOL_FOR = 39,                       /* FOR  */
  YYSYMBOL_WHILE = 40,                     /* WHILE  */
  YYSYMBOL_RETURN = 41,                    /* RETURN  */
  YYSYMBOL_BREAK = 42,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 43,                  /* CONTINUE  */
  YYSYMBOL_VARIABLE_T = 44,                /* VARIABLE_T  */
  YYSYMBOL_IDENT = 45,                     /* IDENT  */
  YYSYMBOL_STR_LIT = 46,                   /* STR_LIT  */
  YYSYMBOL_BOOL_LIT = 47,                  /* BOOL_LIT  */
  YYSYMBOL_INT_LIT = 48,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 49,                 /* FLOAT_LIT  */
  YYSYMBOL_50_ = 50,                       /* ';'  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* '{'  */
  YYSYMBOL_54_ = 54,                       /* '}'  */
  YYSYMBOL_55_ = 55,                       /* ','  */
  YYSYMBOL_56_ = 56,                       /* '['  */
  YYSYMBOL_57_ = 57,                       /* ']'  */
  YYSYMBOL_58_ = 58,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_Program = 60,                   /* Program  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_GlobalStmtList = 62,            /* GlobalStmtList  */
  YYSYMBOL_63_2 = 63,                      /* $@2  */
  YYSYMBOL_GlobalStmt = 64,                /* GlobalStmt  */
  YYSYMBOL_DefineVariableStmt = 65,        /* DefineVariableStmt  */
  YYSYMBOL_FunctionDefStmt = 66,           /* FunctionDefStmt  */
  YYSYMBOL_67_3 = 67,                      /* $@3  */
  YYSYMBOL_68_4 = 68,                      /* $@4  */
  YYSYMBOL_69_5 = 69,                      /* $@5  */
  YYSYMBOL_FunctionParameterStmtList = 70, /* FunctionParameterStmtList  */
  YYSYMBOL_FunctionParameterStmt = 71,     /* FunctionParameterStmt  */
  YYSYMBOL_FunctionCallStmt = 72,          /* FunctionCallStmt  */
  YYSYMBOL_FunctionOp = 73,                /* FunctionOp  */
  YYSYMBOL_StmtList = 74,                  /* StmtList  */
  YYSYMBOL_Stmt = 75,                      /* Stmt  */
  YYSYMBOL_CoutParmListStmt = 76,          /* CoutParmListStmt  */
  YYSYMBOL_decStmtList = 77,               /* decStmtList  */
  YYSYMBOL_decStmt = 78,                   /* decStmt  */
  YYSYMBOL_decStmtWithVal = 79,            /* decStmtWithVal  */
  YYSYMBOL_ifStmt = 80,                    /* ifStmt  */
  YYSYMBOL_ifElseStmt = 81,                /* ifElseStmt  */
  YYSYMBOL_ifHead = 82,                    /* ifHead  */
  YYSYMBOL_ifHead2 = 83,                   /* ifHead2  */
  YYSYMBOL_castingStmt = 84,               /* castingStmt  */
  YYSYMBOL_whileStmt = 85,                 /* whileStmt  */
  YYSYMBOL_86_6 = 86,                      /* $@6  */
  YYSYMBOL_87_7 = 87,                      /* $@7  */
  YYSYMBOL_forStmt = 88,                   /* forStmt  */
  YYSYMBOL_89_8 = 89,                      /* $@8  */
  YYSYMBOL_forHead = 90,                   /* forHead  */
  YYSYMBOL_arrayDecStmt = 91,              /* arrayDecStmt  */
  YYSYMBOL_ElementList = 92,               /* ElementList  */
  YYSYMBOL_93_9 = 93,                      /* $@9  */
  YYSYMBOL_arrayAssignStmt = 94,           /* arrayAssignStmt  */
  YYSYMBOL_95_10 = 95,                     /* $@10  */
  YYSYMBOL_arrayStmt = 96,                 /* arrayStmt  */
  YYSYMBOL_Expression = 97,                /* Expression  */
  YYSYMBOL_singleExpr = 98,                /* singleExpr  */
  YYSYMBOL_Factor = 99                     /* Factor  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2066

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  300

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


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
      51,    52,     2,     2,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    50,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    82,    82,    82,    87,    91,    91,    94,    97,    98,
     105,   110,   113,   113,   110,   130,   131,   132,   136,   148,
     156,   166,   176,   187,   188,   191,   194,   197,   200,   203,
     206,   209,   212,   215,   218,   221,   224,   227,   230,   233,
     236,   239,   244,   245,   249,   250,   254,   255,   256,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   274,   278,   284,   288,   300,   304,   310,   314,   329,
     336,   337,   340,   343,   351,   358,   367,   368,   369,   370,
     373,   374,   377,   378,   379,   382,   385,   413,   413,   413,
     418,   418,   423,   424,   425,   426,   427,   428,   429,   436,
     441,   442,   446,   451,   454,   454,   459,   464,   464,   471,
     474,   479,   482,   485,   489,   493,   497,   501,   505,   509,
     513,   517,   521,   525,   529,   533,   537,   541,   545,   549,
     553,   557,   561,   565,   569,   573,   577,   581,   585,   589,
     593,   597,   600,   603,   606,   610,   613,   617,   620,   624,
     627,   631,   636,   641,   645,   652,   659
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
  "\"end of file\"", "error", "\"invalid token\"", "COUT", "SHR", "SHL",
  "BAN", "BOR", "BNT", "BXO", "ADD", "SUB", "MUL", "DIV", "REM", "NOT",
  "GTR", "LES", "GEQ", "LEQ", "EQL", "NEQ", "LAN", "LOR", "VAL_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "REM_ASSIGN",
  "BAN_ASSIGN", "BOR_ASSIGN", "BXO_ASSIGN", "SHR_ASSIGN", "SHL_ASSIGN",
  "INC_ASSIGN", "DEC_ASSIGN", "IF", "ELSE", "FOR", "WHILE", "RETURN",
  "BREAK", "CONTINUE", "VARIABLE_T", "IDENT", "STR_LIT", "BOOL_LIT",
  "INT_LIT", "FLOAT_LIT", "';'", "'('", "')'", "'{'", "'}'", "','", "'['",
  "']'", "':'", "$accept", "Program", "$@1", "GlobalStmtList", "$@2",
  "GlobalStmt", "DefineVariableStmt", "FunctionDefStmt", "$@3", "$@4",
  "$@5", "FunctionParameterStmtList", "FunctionParameterStmt",
  "FunctionCallStmt", "FunctionOp", "StmtList", "Stmt", "CoutParmListStmt",
  "decStmtList", "decStmt", "decStmtWithVal", "ifStmt", "ifElseStmt",
  "ifHead", "ifHead2", "castingStmt", "whileStmt", "$@6", "$@7", "forStmt",
  "$@8", "forHead", "arrayDecStmt", "ElementList", "$@9",
  "arrayAssignStmt", "$@10", "arrayStmt", "Expression", "singleExpr",
  "Factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-115)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-105)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,     8,   -31,  -115,   -27,   -29,  -115,  -115,  -115,    -2,
     -31,  1437,   -28,  -115,    77,   228,  1553,  -115,  -115,  -115,
    -115,  -115,  1363,  -115,  1045,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,    16,   776,  1437,  1437,  1437,
    1437,  1437,  1437,  1437,  1437,  1437,  1437,  1437,  1437,  1437,
    1437,  1437,  1437,  1437,  1437,  1437,  1437,  1437,  1437,  1437,
    1437,  1437,  1437,  1437,  1437,  -115,  -115,  -115,   -19,  1437,
    -115,   311,  1945,  1891,  1918,    93,    93,   -30,   -30,   -30,
    1850,  1850,  1850,  1850,  1972,  1972,  1863,  1830,  1599,  1599,
    1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,    21,
      18,  -115,   -30,    13,   -19,    22,    24,  -115,    29,  -115,
     218,    79,  1445,  1371,    36,   289,   -49,  -115,    37,   534,
    -115,  -115,    35,  -115,  -115,   713,   728,   997,   515,  -115,
      51,  -115,    56,  -115,  -115,    47,  1080,   382,  1487,     5,
      58,  1379,  -115,  2043,  1599,  -115,  1115,  -115,    61,   -46,
      33,    94,  1495,  1437,  -115,  -115,  -115,   353,   218,   997,
     218,   982,   997,  1437,    68,    67,  -115,  1437,  -115,  1503,
      11,  -115,    75,  1599,  1511,  -115,   961,  1437,  1437,  1437,
    1437,  1437,  1437,  1437,  1437,  1437,  1437,  1437,  1437,  1437,
    1437,  1437,  1437,  1437,  -115,  -115,    96,  -115,  1503,    91,
     -38,   434,    80,   284,    35,   123,   583,   599,  -115,  1599,
      89,   218,  1437,   348,  -115,  1599,    14,  -115,    75,  1599,
    -115,  1985,  1731,  1561,  1698,  2010,  2010,   447,   447,   447,
    1797,  1797,  1797,  1797,  1764,  1764,  1665,  1632,   199,   100,
    1150,    98,  -115,  1437,  -115,  1437,  -115,  -115,  -115,   113,
     101,   362,  1421,  1437,  1185,   648,  1220,  -115,  -115,   -34,
     481,  -115,  -115,  1437,  1599,  1599,  -115,   218,    97,   105,
    1255,  1290,  1429,  -115,  -115,   112,   115,  1599,   664,   138,
    -115,  1437,  1437,  1437,  1325,  -115,  -115,  -115,   132,   813,
     850,   887,  1354,  -115,  -115,  -115,  -115,  -115,   924,  -115
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     7,     8,     9,    11,
       0,     0,     0,     6,     0,     0,     0,   156,   154,   155,
     152,   153,     0,   111,     0,   112,   151,    12,   147,   146,
     145,   144,   149,   150,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,   142,    10,    17,     0,
     143,   126,   115,   116,   117,   113,   114,   127,   128,   129,
     120,   122,   123,   121,   125,   124,   119,   118,   130,   131,
     132,   133,   134,   135,   140,   138,   139,   136,   137,     0,
      13,    16,    86,    18,     0,     0,     0,    15,     0,    19,
      87,     0,     0,     0,     0,     0,   156,    44,     0,    87,
      43,    47,    48,    49,    50,    87,    51,    82,   111,    53,
       0,    54,     0,    55,    56,     0,     0,   151,     0,     0,
     156,     0,    23,    83,    85,    60,     0,    58,   156,     0,
       0,    73,     0,     0,    57,    14,    42,     0,    87,    79,
      87,    77,    84,     0,     0,     0,   107,     0,    46,     0,
     156,    67,    66,    65,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,    69,     0,   102,     0,   156,
       0,     0,   151,     0,    70,    73,    87,    87,    81,    88,
       0,    87,     0,     0,    71,    72,   156,    63,    62,    61,
      41,    38,    28,    29,    30,    26,    27,    39,    40,    24,
      33,    35,    36,    34,    25,    37,    32,    31,     0,    71,
      72,     0,    22,     0,    20,     0,    21,   110,    78,    76,
       0,     0,     0,     0,     0,    87,     0,   109,   101,     0,
       0,    75,    74,     0,   103,   106,    80,    87,   156,     0,
       0,     0,     0,    91,   108,     0,     0,   105,    87,     0,
      97,     0,     0,     0,     0,    99,   100,    89,     0,     0,
       0,     0,     0,    98,    93,    94,    95,    96,     0,    92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,  -115,  -115,   175,  -115,  -115,  -115,  -115,
    -115,  -115,    82,   -53,    48,   -50,   -63,  -115,   -20,  -103,
    -115,  -115,  -115,  -115,  -115,   -47,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,   -44,  -115,  -115,  -115,  -114,   -11,   179,
      78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,    10,     6,     7,     8,    12,    68,
     105,   100,   101,   118,   143,   119,   120,   139,   121,   122,
     123,   124,   125,   126,   127,    23,   129,   130,   250,   131,
     132,   165,   133,   200,   241,   134,   212,   135,   136,    25,
      26
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   150,   152,    -4,   195,    65,    66,   153,     3,   157,
     174,    36,   149,     4,   242,    -5,   -68,   243,     9,   -64,
     275,   243,    11,    27,   172,    99,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   204,   175,   156,   196,   102,   142,
     218,   -68,   152,   128,   -64,   152,   103,   153,    69,   106,
     153,   166,   128,   104,   108,   159,   161,   162,   128,   128,
     128,   109,   110,   197,   138,   171,   147,   154,   142,   167,
     157,   163,    29,    31,    34,   164,   156,    14,   156,   156,
      15,   144,   146,   167,    16,    43,    44,    45,   206,   152,
     207,   128,   128,   128,   128,   128,   214,   153,   198,   210,
     211,   217,    28,    18,    19,    20,    21,   173,    65,    66,
      36,   167,   246,   251,    17,    18,    19,    20,    21,   252,
      22,   201,   203,   156,   156,   239,  -104,   169,   149,   238,
     261,   266,   209,   263,   267,   279,   213,   280,   215,   128,
     128,   255,   285,   219,   128,   286,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   288,   293,    13,   107,   240,   137,   176,
     253,     0,   156,   151,   259,    33,     0,   137,     0,   254,
       0,   256,     0,   137,   137,   137,     0,    14,   128,     0,
      15,     0,     0,     0,    16,   156,     0,   278,     0,     0,
     128,   111,     0,     0,     0,     0,    14,   260,     0,    15,
     202,   128,   264,    16,   265,   205,   137,   137,   137,   137,
     137,   270,   271,     0,   199,    18,    19,    20,    21,     0,
      22,     0,   277,   258,     0,   112,     0,   -90,     0,   113,
     114,   284,   115,   116,    18,    19,    20,    21,   117,    22,
     289,   290,   291,    30,    18,    19,    20,    21,     0,     0,
       0,   298,     0,     0,   137,   137,     0,     0,    37,   137,
      38,    39,     0,    40,    41,    42,    43,    44,    45,     0,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    41,    42,    43,    44,    45,     0,     0,     0,   205,
       0,     0,     0,   137,   148,    18,    19,    20,    21,     0,
       0,   247,     0,     0,     0,   137,    65,    66,     0,     0,
       0,     0,    37,     0,    38,    39,   137,    40,    41,    42,
      43,    44,    45,     0,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,   -73,     0,     0,     0,     0,
     -73,     0,     0,   -73,     0,     0,     0,   -73,    17,    18,
      19,    20,    21,     0,     0,   257,   169,   268,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,   -73,
     -73,   -73,   -73,   -73,   -73,     0,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,     0,   -73,   -73,   -73,    37,     0,
      38,    39,     0,    40,    41,    42,    43,    44,    45,     0,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,    37,   244,    38,    39,   245,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,   -52,     0,
       0,     0,     0,   -52,     0,     0,   -52,     0,     0,     0,
     -52,     0,     0,     0,     0,   276,   245,   111,     0,     0,
       0,     0,    14,     0,     0,    15,     0,     0,     0,    16,
       0,     0,   -52,   -52,   -52,   -52,   -52,   -52,     0,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,     0,   -52,   -52,
       0,   112,     0,   -90,     0,   113,   114,     0,   115,   116,
      18,    19,    20,    21,   117,    22,   111,     0,   155,     0,
       0,    14,     0,     0,    15,     0,     0,     0,    16,     0,
       0,     0,   111,     0,     0,     0,     0,    14,     0,     0,
      15,     0,     0,     0,    16,     0,     0,     0,     0,     0,
     112,     0,   -90,     0,   113,   114,     0,   115,   116,    18,
      19,    20,    21,   117,    22,     0,   112,   248,   -90,     0,
     113,   114,     0,   115,   116,    18,    19,    20,    21,   117,
      22,   111,     0,   249,     0,     0,    14,     0,     0,    15,
       0,     0,     0,    16,     0,     0,     0,   111,     0,     0,
       0,     0,    14,     0,     0,    15,     0,     0,     0,    16,
       0,     0,     0,     0,     0,   112,     0,   -90,     0,   113,
     114,     0,   115,   116,    18,    19,    20,    21,   117,    22,
       0,   112,   273,   -90,     0,   113,   114,     0,   115,   116,
      18,    19,    20,    21,   117,    22,   111,     0,   287,     0,
       0,    14,     0,     0,    15,     0,     0,     0,    16,     0,
       0,   111,     0,     0,     0,     0,    14,     0,     0,    15,
       0,     0,     0,    16,     0,     0,     0,     0,     0,     0,
     112,     0,   -90,     0,   113,   114,     0,   115,   116,    18,
      19,    20,    21,   117,    22,   112,   158,     0,     0,   113,
     114,     0,   115,   116,    18,    19,    20,    21,   117,    22,
      37,   160,    38,    39,     0,    40,    41,    42,    43,    44,
      45,     0,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,     0,     0,     0,    37,     0,    38,
      39,     0,    40,    41,    42,    43,    44,    45,    70,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,     0,     0,     0,    37,     0,    38,    39,     0,    40,
      41,    42,    43,    44,    45,   294,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,    37,     0,    38,    39,     0,    40,    41,    42,    43,
      44,    45,   295,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,     0,     0,     0,    37,     0,
      38,    39,     0,    40,    41,    42,    43,    44,    45,   296,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,     0,     0,     0,   177,     0,   178,   179,     0,
     180,   181,   182,   183,   184,   185,   299,   186,   187,   188,
     189,   190,   191,   192,   193,   111,     0,     0,     0,     0,
      14,     0,     0,    15,     0,     0,     0,    16,     0,     0,
     111,     0,     0,     0,     0,    14,     0,     0,    15,     0,
       0,     0,    16,   220,     0,     0,     0,     0,     0,   112,
     208,     0,     0,   113,   114,     0,   115,   116,    18,    19,
      20,    21,   117,    22,   112,     0,     0,     0,   113,   114,
       0,   115,   116,    18,    19,    20,    21,   117,    22,    37,
       0,    38,    39,     0,    40,    41,    42,    43,    44,    45,
       0,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,     0,    37,     0,    38,    39,     0,    40,
      41,    42,    43,    44,    45,    67,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    37,
       0,    38,    39,     0,    40,    41,    42,    43,    44,    45,
     168,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,     0,    37,     0,    38,    39,     0,    40,
      41,    42,    43,    44,    45,   194,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    37,
       0,    38,    39,     0,    40,    41,    42,    43,    44,    45,
     262,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,     0,    37,     0,    38,    39,     0,    40,
      41,    42,    43,    44,    45,   272,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    37,
       0,    38,    39,     0,    40,    41,    42,    43,    44,    45,
     274,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,     0,    37,     0,    38,    39,     0,    40,
      41,    42,    43,    44,    45,   281,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,    37,
       0,    38,    39,     0,    40,    41,    42,    43,    44,    45,
     282,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    14,     0,     0,    15,     0,     0,     0,    16,
       0,    14,     0,     0,    15,   292,     0,     0,    16,    14,
       0,     0,    15,     0,     0,     0,    16,    14,     0,     0,
      15,     0,     0,     0,    16,     0,     0,     0,     0,    17,
      18,    19,    20,    21,     0,    22,   297,    35,    17,    18,
      19,    20,    21,     0,    22,     0,    17,    18,    19,    20,
      21,   145,    22,    35,   140,    18,    19,    20,    21,    14,
     141,     0,    15,     0,     0,     0,    16,    14,     0,     0,
      15,     0,     0,     0,    16,    14,     0,     0,    15,     0,
       0,     0,    16,    14,     0,     0,    15,     0,     0,     0,
      16,     0,     0,     0,     0,     0,    17,    18,    19,    20,
      21,   269,    22,     0,    17,    18,    19,    20,    21,   283,
      22,     0,    17,    18,    19,    20,    21,     0,    22,     0,
     140,    18,    19,    20,    21,    14,   141,     0,    15,     0,
       0,     0,    16,    14,     0,     0,    15,     0,     0,     0,
      16,    14,     0,     0,    15,     0,     0,     0,    16,    14,
       0,     0,    15,     0,     0,     0,    16,     0,     0,     0,
       0,     0,   170,    18,    19,    20,    21,     0,    22,     0,
     199,    18,    19,    20,    21,     0,    22,     0,   140,    18,
      19,    20,    21,     0,    22,     0,   216,    18,    19,    20,
      21,    14,    22,     0,    15,    37,     0,    38,    16,     0,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
      49,    50,    51,     0,     0,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    32,    18,
      19,    20,    21,    37,     0,    38,    39,     0,    40,    41,
      42,    43,    44,    45,     0,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    37,     0,    38,    39,
       0,    40,    41,    42,    43,    44,    45,     0,    46,    47,
      48,    49,    50,    51,    52,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    37,
       0,    38,    39,     0,    40,    41,    42,    43,    44,    45,
       0,    46,    47,    48,    49,    50,    51,     0,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    37,     0,    38,     0,     0,     0,    41,    42,
      43,    44,    45,     0,    46,    47,    48,    49,    50,    51,
       0,     0,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    37,     0,     0,     0,     0,
       0,    41,    42,    43,    44,    45,     0,    46,    47,    48,
      49,    50,    51,     0,     0,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    37,     0,
       0,     0,     0,     0,    41,    42,    43,    44,    45,     0,
      46,    47,    48,    49,     0,     0,     0,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    37,     0,     0,     0,     0,     0,    41,    42,    43,
      44,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    37,     0,    38,    39,     0,    40,
      41,    42,    43,    44,    45,     0,    46,    47,    48,    49,
      50,    51,    52,     0,    37,     0,     0,     0,     0,     0,
      41,    42,    43,    44,    45,    65,    66,    37,     0,    38,
      39,     0,    40,    41,    42,    43,    44,    45,     0,    46,
      47,    48,    49,    50,    51,    65,    66,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    38,    65,    66,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
      49,    50,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    38,     0,    65,    66,    41,    42,
      43,    44,    45,     0,    46,    47,    48,    49,    50,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,    65,    66,    41,    42,    43,    44,    45,
       0,    46,    47,    48,    49,    50,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
      65,    66,    41,    42,    43,    44,    45,     0,    46,    47,
      48,    49,     0,     0,     0,    41,    42,    43,    44,    45,
       0,     0,     0,     0,     0,     0,     0,    65,    66,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    43,    44,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,   177,     0,   178,
     179,     0,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,   189,   190,   191,   192,   193
};

static const yytype_int16 yycheck[] =
{
      11,   115,    51,     0,    50,    35,    36,    56,     0,    55,
       5,    22,   115,    44,    52,    44,     5,    55,    45,     5,
      54,    55,    24,    51,   138,    44,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   157,    50,   119,    24,    69,   112,
     174,    50,    51,   110,    50,    51,    45,    56,    52,    56,
      56,    24,   119,    55,    52,   125,   126,   127,   125,   126,
     127,    57,    53,    50,     5,   138,    50,    50,   141,    56,
      55,    40,    14,    15,    16,    39,   159,     8,   161,   162,
      11,   112,   113,    56,    15,    12,    13,    14,   158,    51,
     160,   158,   159,   160,   161,   162,   169,    56,    24,    51,
      53,   174,    45,    46,    47,    48,    49,   138,    35,    36,
     141,    56,    52,    44,    45,    46,    47,    48,    49,    50,
      51,   152,   153,   206,   207,   198,    55,    24,   251,    53,
      50,    38,   163,    55,    53,    58,   167,    52,   169,   206,
     207,   211,    50,   174,   211,    50,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    45,    52,    10,   104,   198,   110,   141,
     210,    -1,   255,   115,   238,    16,    -1,   119,    -1,   210,
      -1,   212,    -1,   125,   126,   127,    -1,     8,   255,    -1,
      11,    -1,    -1,    -1,    15,   278,    -1,   267,    -1,    -1,
     267,     3,    -1,    -1,    -1,    -1,     8,   238,    -1,    11,
     152,   278,   243,    15,   245,   157,   158,   159,   160,   161,
     162,   252,   253,    -1,    45,    46,    47,    48,    49,    -1,
      51,    -1,   263,    54,    -1,    37,    -1,    39,    -1,    41,
      42,   272,    44,    45,    46,    47,    48,    49,    50,    51,
     281,   282,   283,    45,    46,    47,    48,    49,    -1,    -1,
      -1,   292,    -1,    -1,   206,   207,    -1,    -1,     4,   211,
       6,     7,    -1,     9,    10,    11,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    10,    11,    12,    13,    14,    -1,    -1,    -1,   251,
      -1,    -1,    -1,   255,    45,    46,    47,    48,    49,    -1,
      -1,    57,    -1,    -1,    -1,   267,    35,    36,    -1,    -1,
      -1,    -1,     4,    -1,     6,     7,   278,     9,    10,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     3,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    11,    -1,    -1,    -1,    15,    45,    46,
      47,    48,    49,    -1,    -1,    57,    24,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    53,    54,    55,     4,    -1,
       6,     7,    -1,     9,    10,    11,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,     4,    52,     6,     7,    55,
       9,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     3,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    11,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    54,    55,     3,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    11,    -1,    -1,    -1,    15,
      -1,    -1,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    53,    54,
      -1,    37,    -1,    39,    -1,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,     3,    -1,    54,    -1,
      -1,     8,    -1,    -1,    11,    -1,    -1,    -1,    15,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      11,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    39,    -1,    41,    42,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    37,    54,    39,    -1,
      41,    42,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,     3,    -1,    54,    -1,    -1,     8,    -1,    -1,    11,
      -1,    -1,    -1,    15,    -1,    -1,    -1,     3,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    11,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,    41,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    37,    54,    39,    -1,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,     3,    -1,    54,    -1,
      -1,     8,    -1,    -1,    11,    -1,    -1,    -1,    15,    -1,
      -1,     3,    -1,    -1,    -1,    -1,     8,    -1,    -1,    11,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    39,    -1,    41,    42,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    37,    53,    -1,    -1,    41,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
       4,    53,     6,     7,    -1,     9,    10,    11,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,     4,    -1,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    52,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,     4,    -1,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    52,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,     4,    -1,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    52,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,     4,    -1,
       6,     7,    -1,     9,    10,    11,    12,    13,    14,    52,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,     4,    -1,     6,     7,    -1,
       9,    10,    11,    12,    13,    14,    52,    16,    17,    18,
      19,    20,    21,    22,    23,     3,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    11,    -1,    -1,    -1,    15,    -1,    -1,
       3,    -1,    -1,    -1,    -1,     8,    -1,    -1,    11,    -1,
      -1,    -1,    15,    52,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    41,    42,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    37,    -1,    -1,    -1,    41,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,     4,
      -1,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,     4,    -1,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    50,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,     4,
      -1,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      50,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,     4,    -1,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    50,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,     4,
      -1,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      50,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,     4,    -1,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    50,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,     4,
      -1,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      50,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,     4,    -1,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    50,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,     4,
      -1,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      50,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     8,    -1,    -1,    11,    -1,    -1,    -1,    15,
      -1,     8,    -1,    -1,    11,    50,    -1,    -1,    15,     8,
      -1,    -1,    11,    -1,    -1,    -1,    15,     8,    -1,    -1,
      11,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    -1,    51,    52,    44,    45,    46,
      47,    48,    49,    -1,    51,    -1,    45,    46,    47,    48,
      49,    50,    51,    44,    45,    46,    47,    48,    49,     8,
      51,    -1,    11,    -1,    -1,    -1,    15,     8,    -1,    -1,
      11,    -1,    -1,    -1,    15,     8,    -1,    -1,    11,    -1,
      -1,    -1,    15,     8,    -1,    -1,    11,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    -1,    45,    46,    47,    48,    49,    50,
      51,    -1,    45,    46,    47,    48,    49,    -1,    51,    -1,
      45,    46,    47,    48,    49,     8,    51,    -1,    11,    -1,
      -1,    -1,    15,     8,    -1,    -1,    11,    -1,    -1,    -1,
      15,     8,    -1,    -1,    11,    -1,    -1,    -1,    15,     8,
      -1,    -1,    11,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    -1,    51,    -1,
      45,    46,    47,    48,    49,    -1,    51,    -1,    45,    46,
      47,    48,    49,    -1,    51,    -1,    45,    46,    47,    48,
      49,     8,    51,    -1,    11,     4,    -1,     6,    15,    -1,
       9,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    45,    46,
      47,    48,    49,     4,    -1,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     4,    -1,     6,     7,
      -1,     9,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     4,
      -1,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     4,    -1,     6,    -1,    -1,    -1,    10,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     4,    -1,    -1,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     4,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,    -1,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     4,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     4,    -1,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    35,    36,     4,    -1,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,    -1,     6,    35,    36,
       9,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    -1,     6,    -1,    35,    36,    10,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
      -1,    -1,    -1,    35,    36,    10,    11,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,
      35,    36,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     4,    -1,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    60,    61,     0,    44,    62,    64,    65,    66,    45,
      63,    24,    67,    64,     8,    11,    15,    45,    46,    47,
      48,    49,    51,    84,    97,    98,    99,    51,    45,    99,
      45,    99,    45,    98,    99,    44,    97,     4,     6,     7,
       9,    10,    11,    12,    13,    14,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    50,    68,    52,
      52,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    44,
      70,    71,    97,    45,    55,    69,    56,    71,    52,    57,
      53,     3,    37,    41,    42,    44,    45,    50,    72,    74,
      75,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    88,    89,    91,    94,    96,    97,    99,     5,    76,
      45,    51,    72,    73,    97,    50,    97,    50,    45,    78,
      96,    99,    51,    56,    50,    54,    75,    55,    53,    74,
      53,    74,    74,    40,    39,    90,    24,    56,    50,    24,
      45,    72,    96,    97,     5,    50,    73,     4,     6,     7,
       9,    10,    11,    12,    13,    14,    16,    17,    18,    19,
      20,    21,    22,    23,    50,    50,    24,    50,    24,    45,
      92,    97,    99,    97,    78,    99,    74,    74,    38,    97,
      51,    53,    95,    97,    72,    97,    45,    72,    96,    97,
      52,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    53,    72,
      97,    93,    52,    55,    52,    55,    52,    57,    54,    54,
      87,    44,    50,    77,    97,    74,    97,    57,    54,    92,
      97,    50,    50,    55,    97,    97,    38,    53,    45,    50,
      97,    97,    50,    54,    50,    54,    54,    97,    74,    58,
      52,    50,    50,    50,    97,    50,    50,    54,    45,    97,
      97,    97,    50,    52,    52,    52,    52,    52,    97,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    61,    60,    60,    63,    62,    62,    64,    64,
      65,    67,    68,    69,    66,    70,    70,    70,    71,    71,
      72,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    74,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      78,    78,    78,    78,    79,    79,    80,    80,    80,    80,
      81,    81,    82,    82,    82,    83,    84,    86,    87,    85,
      89,    88,    90,    90,    90,    90,    90,    90,    90,    91,
      91,    91,    91,    92,    93,    92,    92,    95,    94,    96,
      96,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    98,    99,    99,    99,    99,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     0,     3,     1,     1,     1,
       5,     0,     0,     0,    11,     3,     1,     0,     2,     4,
       4,     4,     4,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       2,     3,     3,     3,     3,     2,     2,     2,     2,     3,
       3,     3,     3,     1,     5,     5,     4,     2,     4,     2,
       5,     3,     1,     2,     2,     2,     4,     0,     0,     7,
       0,     5,     8,     7,     7,     7,     7,     5,     7,     7,
       7,     5,     3,     3,     0,     4,     3,     0,     5,     4,
       4,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1
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
  case 2: /* $@1: %empty  */
#line 82 "./compiler.y"
      { pushScope(); }
#line 1740 "./build/y.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStmtList  */
#line 82 "./compiler.y"
                                      { 
        dumpScope(func_sig_list);
        strcpy(function_sig, "(");
        func_sig_index = 0;
    }
#line 1750 "./build/y.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 91 "./compiler.y"
                     {
        strcpy(function_sig, "(");
    }
#line 1758 "./build/y.tab.c"
    break;

  case 9: /* GlobalStmt: FunctionDefStmt  */
#line 98 "./compiler.y"
                      {
        strcpy(func_sig_list[func_sig_index], function_sig);
        func_sig_index++;
    }
#line 1767 "./build/y.tab.c"
    break;

  case 11: /* $@3: %empty  */
#line 110 "./compiler.y"
                       {
        ObjectType func = OBJECT_TYPE_FUNCTION;
        Insert_symbol(func, (yyvsp[0].s_var)); 
    }
#line 1776 "./build/y.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 113 "./compiler.y"
          { pushScope(); }
#line 1782 "./build/y.tab.c"
    break;

  case 13: /* $@5: %empty  */
#line 113 "./compiler.y"
                                                      {
        if((yyvsp[-5].var_type) == OBJECT_TYPE_INT){
            strcat(function_sig, ")I");
        }else if((yyvsp[-5].var_type) == OBJECT_TYPE_STR){
            strcat(function_sig, ")Ljava/lang/String;");
        }else if((yyvsp[-5].var_type) == OBJECT_TYPE_BOOL){
            strcat(function_sig, ")B");
        }else if((yyvsp[-5].var_type) == 2){
            strcat(function_sig, ")V");
        }
        strcpy(call_func_name[func_sig_index], (yyvsp[-4].s_var));
    }
#line 1799 "./build/y.tab.c"
    break;

  case 14: /* FunctionDefStmt: VARIABLE_T IDENT $@3 '(' $@4 FunctionParameterStmtList $@5 ')' '{' StmtList '}'  */
#line 124 "./compiler.y"
                           {
        dumpScope(func_sig_list);
    }
#line 1807 "./build/y.tab.c"
    break;

  case 18: /* FunctionParameterStmt: VARIABLE_T IDENT  */
#line 136 "./compiler.y"
                       {
        Insert_symbol((yyvsp[-1].var_type), (yyvsp[0].s_var));
        if((yyvsp[-1].var_type) == OBJECT_TYPE_INT){
            strcat(function_sig, "I");
        }else if((yyvsp[-1].var_type) == OBJECT_TYPE_STR){
            strcat(function_sig, "Ljava/lang/String;");
        }else if((yyvsp[-1].var_type) == OBJECT_TYPE_BOOL){
            strcat(function_sig, "B");
        }else if((yyvsp[-1].var_type) == 2){
            strcat(function_sig, "V");
        }
    }
#line 1824 "./build/y.tab.c"
    break;

  case 19: /* FunctionParameterStmt: VARIABLE_T IDENT '[' ']'  */
#line 148 "./compiler.y"
                               {
        Insert_symbol((yyvsp[-3].var_type), (yyvsp[-2].s_var));
        if((yyvsp[-3].var_type) == OBJECT_TYPE_STR){
            strcat(function_sig, "[Ljava/lang/String;");
        }
    }
#line 1835 "./build/y.tab.c"
    break;

  case 20: /* FunctionCallStmt: IDENT '(' Expression ')'  */
#line 156 "./compiler.y"
                                            {
                    modifyVariable((yyvsp[-3].s_var));
                    for(int i=0; i<func_sig_index; i++){
                        if(strcmp((yyvsp[-3].s_var), call_func_name[i]) == 0){
                            printf("call: %s%s\n", (yyvsp[-3].s_var), func_sig_list[i]);
                            break;
                        }
                    }
                    modifyVariable((yyvsp[-1].object_val).symbol->name);
                 }
#line 1850 "./build/y.tab.c"
    break;

  case 21: /* FunctionCallStmt: IDENT '(' Factor ')'  */
#line 166 "./compiler.y"
                                        {
                    modifyVariable((yyvsp[-3].s_var));
                    for(int i=0; i<func_sig_index; i++){
                        if(strcmp((yyvsp[-3].s_var), call_func_name[i]) == 0){
                            printf("call: %s%s\n", (yyvsp[-3].s_var), func_sig_list[i]);
                            break;
                        }
                    }
                    modifyVariable((yyvsp[-1].object_val).symbol->name);
                 }
#line 1865 "./build/y.tab.c"
    break;

  case 22: /* FunctionCallStmt: IDENT '(' ElementList ')'  */
#line 176 "./compiler.y"
                                             {
                    modifyVariable((yyvsp[-3].s_var));
                    for(int i=0; i<func_sig_index; i++){
                        if(strcmp((yyvsp[-3].s_var), call_func_name[i]) == 0){
                            printf("call: %s%s\n", (yyvsp[-3].s_var), func_sig_list[i]);
                            break;
                        }
                    }
                 }
#line 1879 "./build/y.tab.c"
    break;

  case 24: /* FunctionOp: FunctionOp REM Expression  */
#line 188 "./compiler.y"
                                       {
                printf("REM\n");
           }
#line 1887 "./build/y.tab.c"
    break;

  case 25: /* FunctionOp: FunctionOp EQL Expression  */
#line 191 "./compiler.y"
                                       {
                printf("EQL\n");
           }
#line 1895 "./build/y.tab.c"
    break;

  case 26: /* FunctionOp: FunctionOp ADD Expression  */
#line 194 "./compiler.y"
                                       { 
                printf("ADD\n");
           }
#line 1903 "./build/y.tab.c"
    break;

  case 27: /* FunctionOp: FunctionOp SUB Expression  */
#line 197 "./compiler.y"
                                       {
                printf("SUB\n");
           }
#line 1911 "./build/y.tab.c"
    break;

  case 28: /* FunctionOp: FunctionOp BAN Expression  */
#line 200 "./compiler.y"
                                       { 
                printf("BAN\n");
           }
#line 1919 "./build/y.tab.c"
    break;

  case 29: /* FunctionOp: FunctionOp BOR Expression  */
#line 203 "./compiler.y"
                                       { 
                printf("BOR\n");
           }
#line 1927 "./build/y.tab.c"
    break;

  case 30: /* FunctionOp: FunctionOp BXO Expression  */
#line 206 "./compiler.y"
                                       { 
                printf("BXO\n");
           }
#line 1935 "./build/y.tab.c"
    break;

  case 31: /* FunctionOp: FunctionOp LOR Expression  */
#line 209 "./compiler.y"
                                       {
                printf("LOR\n");
           }
#line 1943 "./build/y.tab.c"
    break;

  case 32: /* FunctionOp: FunctionOp LAN Expression  */
#line 212 "./compiler.y"
                                       {
                printf("LAN\n");
           }
#line 1951 "./build/y.tab.c"
    break;

  case 33: /* FunctionOp: FunctionOp GTR Expression  */
#line 215 "./compiler.y"
                                       {
                printf("GTR\n");
           }
#line 1959 "./build/y.tab.c"
    break;

  case 34: /* FunctionOp: FunctionOp LEQ Expression  */
#line 218 "./compiler.y"
                                       {
                printf("LEQ\n");
           }
#line 1967 "./build/y.tab.c"
    break;

  case 35: /* FunctionOp: FunctionOp LES Expression  */
#line 221 "./compiler.y"
                                       {
                printf("LES\n");
           }
#line 1975 "./build/y.tab.c"
    break;

  case 36: /* FunctionOp: FunctionOp GEQ Expression  */
#line 224 "./compiler.y"
                                       {
                printf("GEQ\n");
           }
#line 1983 "./build/y.tab.c"
    break;

  case 37: /* FunctionOp: FunctionOp NEQ Expression  */
#line 227 "./compiler.y"
                                       {
                printf("NEQ\n");
           }
#line 1991 "./build/y.tab.c"
    break;

  case 38: /* FunctionOp: FunctionOp SHR Expression  */
#line 230 "./compiler.y"
                                       { 
                printf("SHR\n");
           }
#line 1999 "./build/y.tab.c"
    break;

  case 39: /* FunctionOp: FunctionOp MUL Expression  */
#line 233 "./compiler.y"
                                       {
                printf("MUL\n");
           }
#line 2007 "./build/y.tab.c"
    break;

  case 40: /* FunctionOp: FunctionOp DIV Expression  */
#line 236 "./compiler.y"
                                       {
                printf("DIV\n");
           }
#line 2015 "./build/y.tab.c"
    break;

  case 45: /* Stmt: COUT CoutParmListStmt ';'  */
#line 250 "./compiler.y"
                                {
        stdoutPrint(tmp_cout, tmp_cout_index);
        tmp_cout_index = 0;
    }
#line 2024 "./build/y.tab.c"
    break;

  case 48: /* Stmt: decStmt  */
#line 256 "./compiler.y"
              {
        printf("EQL_ASSIGN\n");
    }
#line 2032 "./build/y.tab.c"
    break;

  case 58: /* Stmt: BREAK ';'  */
#line 268 "./compiler.y"
                { printf("BREAK\n"); }
#line 2038 "./build/y.tab.c"
    break;

  case 59: /* Stmt: RETURN Expression ';'  */
#line 269 "./compiler.y"
                            { printf("RETURN\n"); }
#line 2044 "./build/y.tab.c"
    break;

  case 60: /* Stmt: RETURN ';'  */
#line 270 "./compiler.y"
                 { printf("RETURN\n"); }
#line 2050 "./build/y.tab.c"
    break;

  case 61: /* CoutParmListStmt: CoutParmListStmt SHL Expression  */
#line 274 "./compiler.y"
                                      {
        tmp_cout[tmp_cout_index] = (yyvsp[0].object_val).type;
        tmp_cout_index++;
    }
#line 2059 "./build/y.tab.c"
    break;

  case 62: /* CoutParmListStmt: CoutParmListStmt SHL arrayStmt  */
#line 278 "./compiler.y"
                                     { 
        modifyVariable(array_name);
        Object tmp = lookup_symbol(array_name, 0);
        tmp_cout[tmp_cout_index] = tmp.type;
        tmp_cout_index++;
    }
#line 2070 "./build/y.tab.c"
    break;

  case 63: /* CoutParmListStmt: CoutParmListStmt SHL FunctionCallStmt  */
#line 284 "./compiler.y"
                                            {
        tmp_cout[tmp_cout_index] = OBJECT_TYPE_INT;
        tmp_cout_index++;
    }
#line 2079 "./build/y.tab.c"
    break;

  case 64: /* CoutParmListStmt: CoutParmListStmt SHL IDENT  */
#line 288 "./compiler.y"
                                 {
        Object node = lookup_symbol((yyvsp[0].s_var), 0);
        if(strcmp((yyvsp[0].s_var), "endl") == 0){
            tmp_cout[tmp_cout_index] = OBJECT_TYPE_STR;
            tmp_cout_index++;
            printf("IDENT (name=%s, address=%d)\n", "endl", -1);
        } else {
            tmp_cout[tmp_cout_index] = node.type;
            tmp_cout_index++;
            printf("IDENT (name=%s, address=%ld)\n", node.symbol->name, node.symbol->addr);
        }
    }
#line 2096 "./build/y.tab.c"
    break;

  case 65: /* CoutParmListStmt: SHL Expression  */
#line 300 "./compiler.y"
                     {
        tmp_cout[tmp_cout_index] = (yyvsp[0].object_val).type;
        tmp_cout_index++;
    }
#line 2105 "./build/y.tab.c"
    break;

  case 66: /* CoutParmListStmt: SHL arrayStmt  */
#line 304 "./compiler.y"
                    {
        modifyVariable(array_name);
        Object tmp = lookup_symbol(array_name, 0);
        tmp_cout[tmp_cout_index] = tmp.type;
        tmp_cout_index++;
    }
#line 2116 "./build/y.tab.c"
    break;

  case 67: /* CoutParmListStmt: SHL FunctionCallStmt  */
#line 310 "./compiler.y"
                           {
        tmp_cout[tmp_cout_index] = OBJECT_TYPE_INT;
        tmp_cout_index++;
    }
#line 2125 "./build/y.tab.c"
    break;

  case 68: /* CoutParmListStmt: SHL IDENT  */
#line 314 "./compiler.y"
                {
        Object node = lookup_symbol((yyvsp[0].s_var), 0);
        if(strcmp((yyvsp[0].s_var), "endl") == 0){
            tmp_cout[tmp_cout_index] = OBJECT_TYPE_STR;
            tmp_cout_index++;
            printf("IDENT (name=%s, address=%d)\n", "endl", -1);
        } else {
            tmp_cout[tmp_cout_index] = node.type;
            tmp_cout_index++;
            printf("IDENT (name=%s, address=%ld)\n", node.symbol->name, node.symbol->addr);
        }
        
    }
#line 2143 "./build/y.tab.c"
    break;

  case 69: /* decStmtList: VARIABLE_T decStmt ';'  */
#line 329 "./compiler.y"
                                     {
                for (int i=0; i<tmp_var_index; i++){
                    Insert_symbol((yyvsp[-2].var_type), tmp_var[i]);
                }
                tmp_var_index = 0;
            }
#line 2154 "./build/y.tab.c"
    break;

  case 71: /* decStmt: Factor VAL_ASSIGN FunctionCallStmt  */
#line 337 "./compiler.y"
                                             {
            Insert_symbol((yyvsp[-2].object_val).type, (yyvsp[-2].object_val).symbol->name);
        }
#line 2162 "./build/y.tab.c"
    break;

  case 72: /* decStmt: Factor VAL_ASSIGN Expression  */
#line 340 "./compiler.y"
                                       {
            Insert_symbol((yyvsp[0].object_val).type, (yyvsp[-2].object_val).symbol->name);
        }
#line 2170 "./build/y.tab.c"
    break;

  case 73: /* decStmt: Factor  */
#line 343 "./compiler.y"
                 {
            (yyval.object_val) = (yyvsp[0].object_val);
            tmp_var[tmp_var_index] = (yyvsp[0].object_val).symbol->name;
            tmp_var_index++;

        }
#line 2181 "./build/y.tab.c"
    break;

  case 74: /* decStmtWithVal: VARIABLE_T Factor VAL_ASSIGN Expression ';'  */
#line 351 "./compiler.y"
                                                             {
                    if((yyvsp[-4].var_type) == 1){
                        Insert_symbol((yyvsp[-1].object_val).type, (yyvsp[-3].object_val).symbol->name);
                    }else{
                        Insert_symbol((yyvsp[-4].var_type), (yyvsp[-3].object_val).symbol->name);
                    }
               }
#line 2193 "./build/y.tab.c"
    break;

  case 75: /* decStmtWithVal: VARIABLE_T Factor VAL_ASSIGN FunctionCallStmt ';'  */
#line 358 "./compiler.y"
                                                                   {
                    if((yyvsp[-4].var_type) == 1){
                        Insert_symbol((yyvsp[-1].object_val).type, (yyvsp[-3].object_val).symbol->name);
                    }else{
                        Insert_symbol((yyvsp[-4].var_type), (yyvsp[-3].object_val).symbol->name);
                    }
               }
#line 2205 "./build/y.tab.c"
    break;

  case 76: /* ifStmt: ifHead '{' StmtList '}'  */
#line 367 "./compiler.y"
                                 { dumpScope(func_sig_none); }
#line 2211 "./build/y.tab.c"
    break;

  case 77: /* ifStmt: ifHead StmtList  */
#line 368 "./compiler.y"
                         { dumpScope(func_sig_none); }
#line 2217 "./build/y.tab.c"
    break;

  case 78: /* ifStmt: ifElseStmt '{' StmtList '}'  */
#line 369 "./compiler.y"
                                     { dumpScope(func_sig_none); }
#line 2223 "./build/y.tab.c"
    break;

  case 79: /* ifStmt: ifElseStmt StmtList  */
#line 370 "./compiler.y"
                             { dumpScope(func_sig_none); }
#line 2229 "./build/y.tab.c"
    break;

  case 80: /* ifElseStmt: ifHead '{' StmtList '}' ELSE  */
#line 373 "./compiler.y"
                                          { dumpSameScope(); printf("ELSE\n"); pushSameScope(); }
#line 2235 "./build/y.tab.c"
    break;

  case 81: /* ifElseStmt: ifHead StmtList ELSE  */
#line 374 "./compiler.y"
                                  { dumpSameScope(); printf("ELSE\n"); pushSameScope(); }
#line 2241 "./build/y.tab.c"
    break;

  case 82: /* ifHead: ifHead2  */
#line 377 "./compiler.y"
                 { pushScope(); }
#line 2247 "./build/y.tab.c"
    break;

  case 83: /* ifHead: IF FunctionOp  */
#line 378 "./compiler.y"
                       { printf("IF\n"); pushScope(); }
#line 2253 "./build/y.tab.c"
    break;

  case 85: /* ifHead2: IF Expression  */
#line 382 "./compiler.y"
                        { printf("IF\n"); }
#line 2259 "./build/y.tab.c"
    break;

  case 86: /* castingStmt: '(' VARIABLE_T ')' Expression  */
#line 385 "./compiler.y"
                                                      {
                (yyval.object_val) = (yyvsp[0].object_val);
                (yyval.object_val).type = (yyvsp[-2].var_type);
                if((yyvsp[-2].var_type) == 0){
                    printf("Cast to undefined\n");
                } else if((yyvsp[-2].var_type) == 1)
                    printf("Cast to auto\n");
                else if((yyvsp[-2].var_type) == 2)
                    printf("Cast to void\n");
                else if((yyvsp[-2].var_type) == 3)
                    printf("Cast to char\n");
                else if((yyvsp[-2].var_type) == 4) {
                    printf("Cast to int\n");
                } else if((yyvsp[-2].var_type) == 5)
                    printf("Cast to long\n");
                else if((yyvsp[-2].var_type) == 6){
                    printf("Cast to float\n");
                } else if((yyvsp[-2].var_type) == 7)
                    printf("Cast to double\n");
                else if((yyvsp[-2].var_type) == 8)
                    printf("Cast to bool\n");
                else if((yyvsp[-2].var_type) == 9)
                    printf("Cast to string\n");
                else if((yyvsp[-2].var_type) == 10)
                    printf("Cast to function\n");
            }
#line 2290 "./build/y.tab.c"
    break;

  case 87: /* $@6: %empty  */
#line 413 "./compiler.y"
            { printf("WHILE\n"); }
#line 2296 "./build/y.tab.c"
    break;

  case 88: /* $@7: %empty  */
#line 413 "./compiler.y"
                                                    {
                pushScope();
            }
#line 2304 "./build/y.tab.c"
    break;

  case 89: /* whileStmt: $@6 WHILE Expression $@7 '{' StmtList '}'  */
#line 415 "./compiler.y"
                               { dumpScope(func_sig_none); }
#line 2310 "./build/y.tab.c"
    break;

  case 90: /* $@8: %empty  */
#line 418 "./compiler.y"
          { printf("FOR\n"); pushScope(); }
#line 2316 "./build/y.tab.c"
    break;

  case 91: /* forStmt: $@8 forHead '{' StmtList '}'  */
#line 418 "./compiler.y"
                                                                     {
            dumpScope(func_sig_none);
        }
#line 2324 "./build/y.tab.c"
    break;

  case 98: /* forHead: FOR '(' VARIABLE_T IDENT ':' IDENT ')'  */
#line 429 "./compiler.y"
                                                 {
            Object tmp = lookup_symbol((yyvsp[-1].s_var), 0);
            Insert_symbol(tmp.type, (yyvsp[-3].s_var));
            modifyVariable((yyvsp[-1].s_var));
        }
#line 2334 "./build/y.tab.c"
    break;

  case 99: /* arrayDecStmt: VARIABLE_T arrayStmt VAL_ASSIGN '{' ElementList '}' ';'  */
#line 436 "./compiler.y"
                                                                       {
                printf("create array: %d\n", array_size);
                array_size = 0;
                Insert_symbol((yyvsp[-6].var_type), array_name);
             }
#line 2344 "./build/y.tab.c"
    break;

  case 101: /* arrayDecStmt: VARIABLE_T arrayStmt VAL_ASSIGN '{' '}'  */
#line 442 "./compiler.y"
                                                       {
                printf("create array: %d\n", 0);
                Insert_symbol((yyvsp[-4].var_type), array_name);
             }
#line 2353 "./build/y.tab.c"
    break;

  case 102: /* arrayDecStmt: VARIABLE_T arrayStmt ';'  */
#line 446 "./compiler.y"
                                        {
                Insert_symbol((yyvsp[-2].var_type), array_name);
             }
#line 2361 "./build/y.tab.c"
    break;

  case 103: /* ElementList: ElementList ',' Expression  */
#line 451 "./compiler.y"
                                         {
                array_size += 1;
            }
#line 2369 "./build/y.tab.c"
    break;

  case 104: /* $@9: %empty  */
#line 454 "./compiler.y"
                    {
                modifyVariable((yyvsp[0].s_var));
            }
#line 2377 "./build/y.tab.c"
    break;

  case 105: /* ElementList: IDENT $@9 ',' Expression  */
#line 456 "./compiler.y"
                             {
                array_size += 2;
            }
#line 2385 "./build/y.tab.c"
    break;

  case 106: /* ElementList: Expression ',' Expression  */
#line 459 "./compiler.y"
                                        {
                array_size += 2;
            }
#line 2393 "./build/y.tab.c"
    break;

  case 107: /* $@10: %empty  */
#line 464 "./compiler.y"
                                       {
                    modifyVariable(array_name);
                }
#line 2401 "./build/y.tab.c"
    break;

  case 108: /* arrayAssignStmt: arrayStmt VAL_ASSIGN $@10 Expression ';'  */
#line 466 "./compiler.y"
                                 {
                    printf("EQL_ASSIGN\n");
                }
#line 2409 "./build/y.tab.c"
    break;

  case 109: /* arrayStmt: arrayStmt '[' Expression ']'  */
#line 471 "./compiler.y"
                                         {
            
          }
#line 2417 "./build/y.tab.c"
    break;

  case 110: /* arrayStmt: IDENT '[' Expression ']'  */
#line 474 "./compiler.y"
                                     {
            array_name = (yyvsp[-3].s_var);
          }
#line 2425 "./build/y.tab.c"
    break;

  case 111: /* Expression: castingStmt  */
#line 479 "./compiler.y"
                          {
                (yyval.object_val) = (yyvsp[0].object_val);
            }
#line 2433 "./build/y.tab.c"
    break;

  case 112: /* Expression: singleExpr  */
#line 482 "./compiler.y"
                         { 
                (yyval.object_val) = (yyvsp[0].object_val);
            }
#line 2441 "./build/y.tab.c"
    break;

  case 113: /* Expression: Expression ADD Expression  */
#line 485 "./compiler.y"
                                        { 
                printf("ADD\n");
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2450 "./build/y.tab.c"
    break;

  case 114: /* Expression: Expression SUB Expression  */
#line 489 "./compiler.y"
                                        {
                printf("SUB\n");
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2459 "./build/y.tab.c"
    break;

  case 115: /* Expression: Expression BAN Expression  */
#line 493 "./compiler.y"
                                        { 
                printf("BAN\n");
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2468 "./build/y.tab.c"
    break;

  case 116: /* Expression: Expression BOR Expression  */
#line 497 "./compiler.y"
                                        { 
                printf("BOR\n");
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2477 "./build/y.tab.c"
    break;

  case 117: /* Expression: Expression BXO Expression  */
#line 501 "./compiler.y"
                                        { 
                printf("BXO\n");
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2486 "./build/y.tab.c"
    break;

  case 118: /* Expression: Expression LOR Expression  */
#line 505 "./compiler.y"
                                        {
                printf("LOR\n");
                (yyval.object_val).type = OBJECT_TYPE_BOOL;
            }
#line 2495 "./build/y.tab.c"
    break;

  case 119: /* Expression: Expression LAN Expression  */
#line 509 "./compiler.y"
                                        {
                printf("LAN\n");
                (yyval.object_val).type = OBJECT_TYPE_BOOL;
            }
#line 2504 "./build/y.tab.c"
    break;

  case 120: /* Expression: Expression GTR Expression  */
#line 513 "./compiler.y"
                                        {
                printf("GTR\n");
                (yyval.object_val).type = OBJECT_TYPE_BOOL;
            }
#line 2513 "./build/y.tab.c"
    break;

  case 121: /* Expression: Expression LEQ Expression  */
#line 517 "./compiler.y"
                                        {
                printf("LEQ\n");
                (yyval.object_val).type = OBJECT_TYPE_BOOL;
            }
#line 2522 "./build/y.tab.c"
    break;

  case 122: /* Expression: Expression LES Expression  */
#line 521 "./compiler.y"
                                        {
                printf("LES\n");
                (yyval.object_val).type = OBJECT_TYPE_BOOL;
            }
#line 2531 "./build/y.tab.c"
    break;

  case 123: /* Expression: Expression GEQ Expression  */
#line 525 "./compiler.y"
                                        {
                printf("GEQ\n");
                (yyval.object_val).type = OBJECT_TYPE_BOOL;
            }
#line 2540 "./build/y.tab.c"
    break;

  case 124: /* Expression: Expression NEQ Expression  */
#line 529 "./compiler.y"
                                        {
                printf("NEQ\n");
                (yyval.object_val).type = OBJECT_TYPE_BOOL;
            }
#line 2549 "./build/y.tab.c"
    break;

  case 125: /* Expression: Expression EQL Expression  */
#line 533 "./compiler.y"
                                        {
                printf("EQL\n");
                (yyval.object_val).type = OBJECT_TYPE_BOOL;
            }
#line 2558 "./build/y.tab.c"
    break;

  case 126: /* Expression: Expression SHR Expression  */
#line 537 "./compiler.y"
                                        { 
                printf("SHR\n");
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2567 "./build/y.tab.c"
    break;

  case 127: /* Expression: Expression MUL Expression  */
#line 541 "./compiler.y"
                                        {
                printf("MUL\n");
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2576 "./build/y.tab.c"
    break;

  case 128: /* Expression: Expression DIV Expression  */
#line 545 "./compiler.y"
                                        {
                printf("DIV\n");
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2585 "./build/y.tab.c"
    break;

  case 129: /* Expression: Expression REM Expression  */
#line 549 "./compiler.y"
                                        { 
                printf("REM\n");
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2594 "./build/y.tab.c"
    break;

  case 130: /* Expression: Expression VAL_ASSIGN Expression  */
#line 553 "./compiler.y"
                                               {
                printf("EQL_ASSIGN\n");
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2603 "./build/y.tab.c"
    break;

  case 131: /* Expression: Expression ADD_ASSIGN Expression  */
#line 557 "./compiler.y"
                                               { 
                printf("ADD_ASSIGN\n");
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2612 "./build/y.tab.c"
    break;

  case 132: /* Expression: Expression SUB_ASSIGN Expression  */
#line 561 "./compiler.y"
                                               {
                printf("SUB_ASSIGN\n"); 
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2621 "./build/y.tab.c"
    break;

  case 133: /* Expression: Expression MUL_ASSIGN Expression  */
#line 565 "./compiler.y"
                                               { 
                printf("MUL_ASSIGN\n");
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2630 "./build/y.tab.c"
    break;

  case 134: /* Expression: Expression DIV_ASSIGN Expression  */
#line 569 "./compiler.y"
                                               {
                printf("DIV_ASSIGN\n");
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2639 "./build/y.tab.c"
    break;

  case 135: /* Expression: Expression REM_ASSIGN Expression  */
#line 573 "./compiler.y"
                                               { 
                printf("REM_ASSIGN\n");
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2648 "./build/y.tab.c"
    break;

  case 136: /* Expression: Expression SHR_ASSIGN Expression  */
#line 577 "./compiler.y"
                                               {
                printf("SHR_ASSIGN\n");
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2657 "./build/y.tab.c"
    break;

  case 137: /* Expression: Expression SHL_ASSIGN Expression  */
#line 581 "./compiler.y"
                                               {
                printf("SHL_ASSIGN\n");
                (yyval.object_val) = (yyvsp[-2].object_val); 
            }
#line 2666 "./build/y.tab.c"
    break;

  case 138: /* Expression: Expression BOR_ASSIGN Expression  */
#line 585 "./compiler.y"
                                               { 
                printf("BOR_ASSIGN\n"); 
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2675 "./build/y.tab.c"
    break;

  case 139: /* Expression: Expression BXO_ASSIGN Expression  */
#line 589 "./compiler.y"
                                               {
                printf("BXO_ASSIGN\n"); 
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2684 "./build/y.tab.c"
    break;

  case 140: /* Expression: Expression BAN_ASSIGN Expression  */
#line 593 "./compiler.y"
                                               {
                printf("BAN_ASSIGN\n"); 
                (yyval.object_val) = (yyvsp[-2].object_val);
            }
#line 2693 "./build/y.tab.c"
    break;

  case 141: /* Expression: Expression INC_ASSIGN  */
#line 597 "./compiler.y"
                                    {
                printf("INC_ASSIGN\n");
            }
#line 2701 "./build/y.tab.c"
    break;

  case 142: /* Expression: Expression DEC_ASSIGN  */
#line 600 "./compiler.y"
                                    {
                printf("DEC_ASSIGN\n");
            }
#line 2709 "./build/y.tab.c"
    break;

  case 143: /* Expression: '(' Expression ')'  */
#line 603 "./compiler.y"
                                 { (yyval.object_val) = (yyvsp[-1].object_val); }
#line 2715 "./build/y.tab.c"
    break;

  case 144: /* singleExpr: SUB Factor  */
#line 606 "./compiler.y"
                        { 
                printf("NEG\n");
                (yyval.object_val).type = (yyvsp[0].object_val).type;
            }
#line 2724 "./build/y.tab.c"
    break;

  case 145: /* singleExpr: SUB IDENT  */
#line 610 "./compiler.y"
                       { 
                printf("NEG\n");
            }
#line 2732 "./build/y.tab.c"
    break;

  case 146: /* singleExpr: BNT Factor  */
#line 613 "./compiler.y"
                        { 
                printf("BNT\n");
                (yyval.object_val).type = (yyvsp[0].object_val).type;
            }
#line 2741 "./build/y.tab.c"
    break;

  case 147: /* singleExpr: BNT IDENT  */
#line 617 "./compiler.y"
                       { 
                printf("BNT\n");
            }
#line 2749 "./build/y.tab.c"
    break;

  case 148: /* singleExpr: NOT Factor  */
#line 620 "./compiler.y"
                        { 
                printf("NOT\n");
                (yyval.object_val).type = (yyvsp[0].object_val).type;
            }
#line 2758 "./build/y.tab.c"
    break;

  case 149: /* singleExpr: NOT IDENT  */
#line 624 "./compiler.y"
                       { 
                printf("NOT\n"); 
            }
#line 2766 "./build/y.tab.c"
    break;

  case 150: /* singleExpr: NOT singleExpr  */
#line 627 "./compiler.y"
                            { 
                printf("NOT\n");
                (yyval.object_val).type = (yyvsp[0].object_val).type;
            }
#line 2775 "./build/y.tab.c"
    break;

  case 151: /* singleExpr: Factor  */
#line 631 "./compiler.y"
                    {
                (yyval.object_val) = (yyvsp[0].object_val);
           }
#line 2783 "./build/y.tab.c"
    break;

  case 152: /* Factor: INT_LIT  */
#line 636 "./compiler.y"
                  { 
            printf("INT_LIT %d\n", (yyvsp[0].i_var));
            (yyval.object_val).type = OBJECT_TYPE_INT;
            (yyval.object_val).value = (yyvsp[0].i_var);
        }
#line 2793 "./build/y.tab.c"
    break;

  case 153: /* Factor: FLOAT_LIT  */
#line 641 "./compiler.y"
                    { 
            printf("FLOAT_LIT %f\n", (yyvsp[0].f_var));
            (yyval.object_val).type = OBJECT_TYPE_FLOAT;
        }
#line 2802 "./build/y.tab.c"
    break;

  case 154: /* Factor: STR_LIT  */
#line 645 "./compiler.y"
                  { 
            printf("STR_LIT \"%s\"\n", (yyvsp[0].s_var));
            (yyval.object_val).type = OBJECT_TYPE_STR;
            (yyval.object_val).symbol = (SymbolData*)malloc(sizeof(SymbolData));
            (yyval.object_val).symbol->name = (char*)malloc(sizeof(char)*50);
            strcpy((yyval.object_val).symbol->name, (yyvsp[0].s_var));
        }
#line 2814 "./build/y.tab.c"
    break;

  case 155: /* Factor: BOOL_LIT  */
#line 652 "./compiler.y"
                   {
            if((yyvsp[0].b_var))
                printf("BOOL_LIT TRUE\n");
            else
                printf("BOOL_LIT FALSE\n");
            (yyval.object_val).type = OBJECT_TYPE_BOOL;
        }
#line 2826 "./build/y.tab.c"
    break;

  case 156: /* Factor: IDENT  */
#line 659 "./compiler.y"
                {
            Object tmp = lookup_symbol((yyvsp[0].s_var), 0);
            (yyval.object_val).symbol = (SymbolData*)malloc(sizeof(SymbolData));
            (yyval.object_val).symbol->name = (char*)malloc(sizeof(char)*50);
            strcpy((yyval.object_val).symbol->name, (yyvsp[0].s_var));
            (yyval.object_val).type = tmp.type;
            modifyVariable((yyvsp[0].s_var));
        }
#line 2839 "./build/y.tab.c"
    break;


#line 2843 "./build/y.tab.c"

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

#line 669 "./compiler.y"

/* C code section */
