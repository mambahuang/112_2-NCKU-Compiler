/* Definition section */
%{
    #include "compiler_common.h"
    #include "compiler_util.h"
    #include "main.h"

    int yydebug = 1;

    int id_addr = -1;
    int is_cout = 0;
    int int_flag = 0;
    int float_flag = 0;
    int string_flag = 0;
    int bool_flag = 0;
    char* tmp_var[10] = {};
    int tmp_var_index = 0;
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

%left BAN BOR
%left ADD SUB
%left MUL DIV REM
%right NOT BNT
%right '^'

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
    | ifStmt
    | RETURN expr ';' { printf("RETURN\n"); }
    | RETURN INT_LIT ';' { 
        printf("INT_LIT %d\n", $2);
        printf("RETURN\n"); 
    }
;

decStmt : VARIABLE_T IDENT VAL_ASSIGN expr ';' {
            Insert_symbol($<var_type>1, $<s_var>2);
        }
        | VARIABLE_T variableList ';' {
            //tmp_obj = $<var_type>1;
            for(int i=0; i<tmp_var_index; i++){
                Insert_symbol($<var_type>1, tmp_var[i]);
            }
            tmp_var_index = 0;
        }
;

ifStmt : IF { 
            printf("IF\n");
            pushScope();
        } '(' expr ')' '{' Stmt '}' { dumpScope(); }
       | IF {
            printf("IF\n");
            pushScope();
        } '(' expr ')' '{' Stmt '}' ELSE '{' Stmt '}' { dumpScope(); }

variableList : variable
             | variableList ',' variable
;

variable : IDENT {
            tmp_var[tmp_var_index] = $<s_var>1;
            tmp_var_index++;
            //Insert_symbol(tmp_obj, $<s_var>1);
         }
         | IDENT VAL_ASSIGN expr {
            tmp_var[tmp_var_index] = $<s_var>1;
            tmp_var_index++;
            //Insert_symbol(tmp_obj, $<s_var>1);
         }
;

assginStmt : IDENT { modifyVariable($<s_var>1); } VAL_ASSIGN expr ';' { printf("EQL_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } ADD_ASSIGN expr ';' { printf("ADD_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } SUB_ASSIGN expr ';' { printf("SUB_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } MUL_ASSIGN expr ';' { printf("MUL_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } DIV_ASSIGN expr ';' { printf("DIV_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } REM_ASSIGN expr ';' { printf("REM_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } SHR_ASSIGN expr ';' { printf("SHR_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } SHL_ASSIGN expr ';' { printf("SHL_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } BOR_ASSIGN expr ';' { printf("BOR_ASSIGN\n"); }
           | IDENT { modifyVariable($<s_var>1); } BAN_ASSIGN expr ';' { printf("BAN_ASSIGN\n"); }
;

CoutParmListStmt
    : CoutParmListStmt SHL { is_cout = 1; } expr {
        int_flag = 0;
        float_flag = 0;
        string_flag = 0;
        bool_flag = 0;
    }
    | SHL { is_cout = 1; } expr { 
        int_flag = 0;
        float_flag = 0;
        string_flag = 0;
        bool_flag = 0; 
    }
;

expr    : expr ADD expr { printf("ADD\n"); }
        | expr SUB expr { printf("SUB\n"); }
        | expr BAN expr { printf("BAN\n"); }
        | expr BOR expr { printf("BOR\n"); }
        | expr BXO expr { printf("BXO\n"); }
        | expr LOR expr { printf("LOR\n"); }
        | expr LAN expr { printf("LAN\n"); }
        | expr GTR expr { printf("GTR\n"); }
        | expr LEQ expr { printf("LEQ\n"); }
        | expr LES expr { printf("LES\n"); }
        | expr GEQ expr { printf("GEQ\n"); }
        | expr NEQ expr { printf("NEQ\n"); }
        | expr EQL expr { printf("EQL\n"); }
        | expr SHR expr { printf("SHR\n"); }
        | term
;

term : term MUL factor { printf("MUL\n"); }
     | term DIV factor { printf("DIV\n"); }
     | term REM factor { printf("REM\n"); }
     | factor
;

factor  : INT_LIT { 
            printf("INT_LIT %d\n", $<i_var>1);
            if(is_cout == 1 && int_flag == 0){
                coutStmt("int");
                int_flag = 1;
            }
        }
        | FLOAT_LIT { 
            printf("FLOAT_LIT %f\n", $<f_var>1);
            if(is_cout == 1 && float_flag == 0){
                coutStmt("float");
                float_flag = 1;
            }
        }
        | STR_LIT { 
            printf("STR_LIT \"%s\"\n", $<s_var>1);
            if(is_cout == 1 && string_flag == 0){
                coutStmt("string");
                string_flag = 1;
            }
        }
        | '(' expr ')'
        | '(' VARIABLE_T ')' factor {
            if($<var_type>2 == 0)
                printf("Cast to undefined\n");
            else if($<var_type>2 == 1)
                printf("Cast to auto\n");
            else if($<var_type>2 == 2)
                printf("Cast to void\n");
            else if($<var_type>2 == 3)
                printf("Cast to char\n");
            else if($<var_type>2 == 4)
                printf("Cast to int\n");
            else if($<var_type>2 == 5)
                printf("Cast to long\n");
            else if($<var_type>2 == 6)
                printf("Cast to float\n");
            else if($<var_type>2 == 7)
                printf("Cast to double\n");
            else if($<var_type>2 == 8)
                printf("Cast to bool\n");
            else if($<var_type>2 == 9)
                printf("Cast to string\n");
            else if($<var_type>2 == 10)
                printf("Cast to function\n");
        }
        | SUB factor { printf("NEG\n"); }
        | BNT factor { printf("BNT\n"); }
        | NOT factor { printf("NOT\n"); }
        | IDENT {
            if(strcmp($<s_var>1, "endl") == 0){
                printf("IDENT (name=%s, address=%d)\n", $<s_var>1, -1);
                coutStmt("string");
            } else {
                modifyVariable($<s_var>1);
                if(is_cout == 1){
                    NODE tmp_node;
                    tmp_node = lookup_symbol($<s_var>1, 0);
                    if(tmp_node.address != 404){
                        coutStmt(tmp_node.type);
                    }
                }
            }
            is_cout = 0;
        }
        | BOOL_LIT {
            if($<b_var>1)
                printf("BOOL_LIT TRUE\n");
            else
                printf("BOOL_LIT FALSE\n");

            if(is_cout == 1 && bool_flag == 0){
                bool_flag = 1;
                coutStmt("bool");
            }
        }
        
;



%%
/* C code section */
