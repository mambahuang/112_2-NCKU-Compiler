/* Definition section */
%{
    #include "compiler_common.h"
    #include "compiler_util.h"
    #include "main.h"

    int yydebug = 1;

    int id_addr = -1;
    int is_cout = 0;
    ObjectType tmp_obj;

%}

/* Variable or self-defined structure */
%union {
    ObjectType var_type;

    bool b_var;
    int i_var;
    float f_var;
    char *s_var;

    Object object_val;
}

/* Token without return */
%token COUT
%token SHR SHL BAN BOR BNT BXO
%token ADD SUB MUL DIV REM NOT 
%token GTR LES GEQ LEQ EQL NEQ LAN LOR
%token VAL_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN BAN_ASSIGN BOR_ASSIGN BXO_ASSIGN SHR_ASSIGN SHL_ASSIGN INC_ASSIGN DEC_ASSIGN
%token IF ELSE FOR WHILE RETURN BREAK CONTINUE

/* Token with return, which need to sepcify type */
%token <var_type> VARIABLE_T
%token <s_var> IDENT
%token <s_var> STR_LIT
%token <b_var> BOOL_LIT
%token <i_var> INT_LIT
%token <f_var> FLOAT_LIT

/* Nonterminal with return, which need to sepcify type */
/*%type <object_val> Expression Term Factor*/

%left ADD SUB
%left MUL DIV REM
%left LOR LAN
%left GTR LES EQL NEQ LEQ GEQ

/* Yacc will start at this nonterminal */
%start Program

%%
/* Grammar section */

Program
    : { pushScope(); } GlobalStmtList { dumpScope(); }
    | /* Empty file */
;

GlobalStmtList 
    : GlobalStmtList GlobalStmt
    | GlobalStmt
;

GlobalStmt
    : DefineVariableStmt
    | FunctionDefStmt
;

DefineVariableStmt
    : VARIABLE_T IDENT VAL_ASSIGN expr ';'
;

/* Function */
FunctionDefStmt
    : VARIABLE_T IDENT {
        ObjectType func = OBJECT_TYPE_FUNCTION;
        Insert_symbol(func, $<s_var>2); 
    } '(' FunctionParameterStmtList ')' '{' StmtList '}' {
        dumpScope(); 
    }
;
FunctionParameterStmtList 
    : FunctionParameterStmtList ',' FunctionParameterStmt
    | FunctionParameterStmt
    | /* Empty function parameter */
;

FunctionParameterStmt
    : VARIABLE_T IDENT { 
        pushFunParm($<var_type>1, $<s_var>2, VAR_FLAG_DEFAULT); 
    }
    | VARIABLE_T IDENT '[' ']' {
        pushScope();
        Insert_symbol($<var_type>1, $<s_var>2); 
    }
;

/* Scope */
StmtList 
    : StmtList Stmt
    | Stmt
;

Stmt
    : ';'
    | COUT CoutParmListStmt ';' {
        printf("cout ");
        stdoutPrint(); 
    }
    | decStmt
    | assginStmt
    | RETURN expr ';' { printf("RETURN\n"); }
    | RETURN INT_LIT ';' { 
        printf("INT_LIT %d\n", $2);
        printf("RETURN\n"); 
    }
;

decStmt : VARIABLE_T IDENT VAL_ASSIGN expr {
            Insert_symbol($<var_type>1, $<s_var>2);
        }
        | VARIABLE_T IDENT {
            Insert_symbol($<var_type>1, $<s_var>2);
            tmp_obj = $<var_type>1;
        }
        | ',' IDENT {
            Insert_symbol(tmp_obj, $<s_var>2);
        }
        | decStmt decStmt
;

assginStmt : IDENT { modifyVariable($<s_var>1); } VAL_ASSIGN expr { printf("EQL_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } ADD_ASSIGN expr { printf("ADD_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } SUB_ASSIGN expr { printf("SUB_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } MUL_ASSIGN expr { printf("MUL_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } DIV_ASSIGN expr { printf("DIV_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } REM_ASSIGN expr { printf("REM_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } SHR_ASSIGN expr { printf("SHR_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } SHL_ASSIGN expr { printf("SHL_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } BOR_ASSIGN expr { printf("BOR_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } BAN_ASSIGN expr { printf("BAN_ASSIGN\n"); }
;

CoutParmListStmt
    : CoutParmListStmt SHL expr {
        pushFunInParm(&$<object_val>3);
    }
    | SHL { is_cout = 1; } expr CoutParmListStmt
    | SHL STR_LIT {
        printf("STR_LIT \"%s\"\n", $<s_var>2); 
        coutStmt("string");
    } CoutParmListStmt
    | SHL IDENT {
        printf("IDENT (name=%s, address=%d)\n", $<s_var>2, -1);
        coutStmt("string");
    }
    |
;

expr    : expr ADD term { printf("ADD\n"); }
        | expr SUB term { printf("SUB\n"); }
        | term
;

term    : term MUL factor { printf("MUL\n"); }
        | term DIV factor { printf("DIV\n"); }
        | term REM factor { printf("REM\n"); }
        | factor
;

factor  : INT_LIT { printf("INT_LIT %d\n", $<i_var>1); }
        | FLOAT_LIT { printf("FLOAT_LIT %f\n", $<f_var>1); }
        | STR_LIT { printf("STR_LIT \"%s\"\n", $<s_var>1); }
        | '-' factor { printf("NEG\n"); }
        | '(' expr ')'
        | '~' factor { printf("BNT\n"); }
        | IDENT {
            modifyVariable($<s_var>1);
            if(is_cout == 1){
                NODE tmp_node;
                tmp_node = lookup_symbol($<s_var>1, 0);
                if(tmp_node.address != 404){
                    coutStmt(tmp_node.type);
                }
            }
            is_cout = 0;
        }
        | comparison
        | logical
;

comparison : expr GTR expr { printf("GTR\n"); }
           | expr LEQ expr { printf("LEQ\n"); }
           | expr LES expr { printf("LES\n"); }
           | expr GEQ expr { printf("GEQ\n"); }
           | expr NEQ expr { printf("NEQ\n"); }
;

logical : logical LAN logical { printf("LAN\n"); }
        | logical LOR logical { printf("LOR\n"); }
        | NOT factor { printf("NOT\n"); }
        | BOOL_LIT {
            if($<b_var>1)
                printf("BOOL_LIT TRUE\n");
            else
                printf("BOOL_LIT FALSE\n");
        }
;

%%
/* C code section */

