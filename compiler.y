/* Definition section */
%{
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
%type <object_val> Expression Factor 
%type <object_val> singleExpr 
%type <object_val> castingStmt
%type <object_val> decStmt

%right VAL_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN SHL_ASSIGN SHR_ASSIGN BAN_ASSIGN BXO_ASSIGN BOR_ASSIGN
%left LOR
%left LAN
%left BOR
%left BXO
%left BAN
%left EQL NEQ
%left GTR LES GEQ LEQ
%left SHL SHR
%left ADD SUB
%left MUL DIV REM
%right NOT BNT
%left INC_ASSIGN DEC_ASSIGN

/* Yacc will start at this nonterminal */
%start Program

%%
/* Grammar section */

Program
    : { pushScope(); } GlobalStmtList { 
        dumpScope(func_sig_list);
        strcpy(function_sig, "(");
        func_sig_index = 0;
    }
    | /* Empty file */
;

GlobalStmtList 
    : GlobalStmtList {
        strcpy(function_sig, "(");
    } GlobalStmt
    | GlobalStmt

GlobalStmt
    : DefineVariableStmt
    | FunctionDefStmt {
        strcpy(func_sig_list[func_sig_index], function_sig);
        func_sig_index++;
    }
;

DefineVariableStmt
    : VARIABLE_T IDENT VAL_ASSIGN Expression ';'
;

/* Function */
FunctionDefStmt
    : VARIABLE_T IDENT {
        ObjectType func = OBJECT_TYPE_FUNCTION;
        Insert_symbol(func, $<s_var>2); 
    } '(' { pushScope(); } FunctionParameterStmtList  {
        if($<var_type>1 == OBJECT_TYPE_INT){
            strcat(function_sig, ")I");
        }else if($<var_type>1 == OBJECT_TYPE_STR){
            strcat(function_sig, ")Ljava/lang/String;");
        }else if($<var_type>1 == OBJECT_TYPE_BOOL){
            strcat(function_sig, ")B");
        }else if($<var_type>1 == 2){
            strcat(function_sig, ")V");
        }
        strcpy(call_func_name[func_sig_index], $<s_var>2);
    } ')' '{' StmtList '}' {
        dumpScope(func_sig_list);
    }
;

FunctionParameterStmtList 
    : FunctionParameterStmtList ',' FunctionParameterStmt
    | FunctionParameterStmt
    | /* Empty function parameter */
;

FunctionParameterStmt
    : VARIABLE_T IDENT {
        Insert_symbol($<var_type>1, $<s_var>2);
        if($<var_type>1 == OBJECT_TYPE_INT){
            strcat(function_sig, "I");
        }else if($<var_type>1 == OBJECT_TYPE_STR){
            strcat(function_sig, "Ljava/lang/String;");
        }else if($<var_type>1 == OBJECT_TYPE_BOOL){
            strcat(function_sig, "B");
        }else if($<var_type>1 == 2){
            strcat(function_sig, "V");
        }
    }
    | VARIABLE_T IDENT '[' ']' {
        Insert_symbol($<var_type>1, $<s_var>2);
        if($<var_type>1 == OBJECT_TYPE_STR){
            strcat(function_sig, "[Ljava/lang/String;");
        }
    }
;

FunctionCallStmt : IDENT '(' Expression ')' {
                    modifyVariable($<s_var>1);
                    for(int i=0; i<func_sig_index; i++){
                        if(strcmp($<s_var>1, call_func_name[i]) == 0){
                            printf("call: %s%s\n", $<s_var>1, func_sig_list[i]);
                            break;
                        }
                    }
                    modifyVariable($<object_val>3.symbol->name);
                 }
                 | IDENT '(' Factor ')' {
                    modifyVariable($<s_var>1);
                    for(int i=0; i<func_sig_index; i++){
                        if(strcmp($<s_var>1, call_func_name[i]) == 0){
                            printf("call: %s%s\n", $<s_var>1, func_sig_list[i]);
                            break;
                        }
                    }
                    modifyVariable($<object_val>3.symbol->name);
                 }
                 | IDENT '(' ElementList ')' {
                    modifyVariable($<s_var>1);
                    for(int i=0; i<func_sig_index; i++){
                        if(strcmp($<s_var>1, call_func_name[i]) == 0){
                            printf("call: %s%s\n", $<s_var>1, func_sig_list[i]);
                            break;
                        }
                    }
                 }
;

FunctionOp : FunctionCallStmt
           | FunctionOp REM Expression {
                printf("REM\n");
           }
           | FunctionOp EQL Expression {
                printf("EQL\n");
           }
           | FunctionOp ADD Expression { 
                printf("ADD\n");
           }
           | FunctionOp SUB Expression {
                printf("SUB\n");
           }
           | FunctionOp BAN Expression { 
                printf("BAN\n");
           }
           | FunctionOp BOR Expression { 
                printf("BOR\n");
           }
           | FunctionOp BXO Expression { 
                printf("BXO\n");
           }
           | FunctionOp LOR Expression {
                printf("LOR\n");
           }
           | FunctionOp LAN Expression {
                printf("LAN\n");
           }
           | FunctionOp GTR Expression {
                printf("GTR\n");
           }
           | FunctionOp LEQ Expression {
                printf("LEQ\n");
           }
           | FunctionOp LES Expression {
                printf("LES\n");
           }
           | FunctionOp GEQ Expression {
                printf("GEQ\n");
           }
           | FunctionOp NEQ Expression {
                printf("NEQ\n");
           }
           | FunctionOp SHR Expression { 
                printf("SHR\n");
           }
           | FunctionOp MUL Expression {
                printf("MUL\n");
           }
           | FunctionOp DIV Expression {
                printf("DIV\n");
           }
           | '(' FunctionOp ')'
;

/* Scope */
StmtList 
    : StmtList Stmt
    | Stmt
;

Stmt
    : ';'
    | COUT CoutParmListStmt ';' {
        stdoutPrint(tmp_cout, tmp_cout_index);
        tmp_cout_index = 0;
    }
    | Expression ';'
    | decStmtList
    | decStmt {
        printf("EQL_ASSIGN\n");
    }
    | decStmtWithVal
    | ifStmt
    | ifHead
    | castingStmt
    | whileStmt
    | forStmt
    | arrayDecStmt
    | arrayAssignStmt
    | FunctionCallStmt ';'
    | BREAK ';' { printf("BREAK\n"); }
    | RETURN Expression ';' { printf("RETURN\n"); }
    | RETURN ';' { printf("RETURN\n"); }
;

CoutParmListStmt
    : CoutParmListStmt SHL Expression {
        tmp_cout[tmp_cout_index] = $<object_val>3.type;
        tmp_cout_index++;
    }
    | CoutParmListStmt SHL arrayStmt { 
        modifyVariable(array_name);
        Object tmp = lookup_symbol(array_name, 0);
        tmp_cout[tmp_cout_index] = tmp.type;
        tmp_cout_index++;
    }
    | CoutParmListStmt SHL FunctionCallStmt {
        tmp_cout[tmp_cout_index] = OBJECT_TYPE_INT;
        tmp_cout_index++;
    }
    | CoutParmListStmt SHL IDENT {
        Object node = lookup_symbol($<s_var>3, 0);
        if(strcmp($<s_var>3, "endl") == 0){
            tmp_cout[tmp_cout_index] = OBJECT_TYPE_STR;
            tmp_cout_index++;
            printf("IDENT (name=%s, address=%d)\n", "endl", -1);
        } else {
            tmp_cout[tmp_cout_index] = node.type;
            tmp_cout_index++;
            printf("IDENT (name=%s, address=%ld)\n", node.symbol->name, node.symbol->addr);
        }
    }
    | SHL Expression {
        tmp_cout[tmp_cout_index] = $<object_val>2.type;
        tmp_cout_index++;
    }
    | SHL arrayStmt {
        modifyVariable(array_name);
        Object tmp = lookup_symbol(array_name, 0);
        tmp_cout[tmp_cout_index] = tmp.type;
        tmp_cout_index++;
    }
    | SHL FunctionCallStmt {
        tmp_cout[tmp_cout_index] = OBJECT_TYPE_INT;
        tmp_cout_index++;
    }
    | SHL IDENT {
        Object node = lookup_symbol($<s_var>2, 0);
        if(strcmp($<s_var>2, "endl") == 0){
            tmp_cout[tmp_cout_index] = OBJECT_TYPE_STR;
            tmp_cout_index++;
            printf("IDENT (name=%s, address=%d)\n", "endl", -1);
        } else {
            tmp_cout[tmp_cout_index] = node.type;
            tmp_cout_index++;
            printf("IDENT (name=%s, address=%ld)\n", node.symbol->name, node.symbol->addr);
        }
        
    }
;

decStmtList : VARIABLE_T decStmt ';' {
                for (int i=0; i<tmp_var_index; i++){
                    Insert_symbol($<var_type>1, tmp_var[i]);
                }
                tmp_var_index = 0;
            }

decStmt : decStmt ',' decStmt
        | Factor VAL_ASSIGN FunctionCallStmt {
            Insert_symbol($<object_val>1.type, $<object_val>1.symbol->name);
        }
        | Factor VAL_ASSIGN Expression {
            Insert_symbol($<object_val>3.type, $<object_val>1.symbol->name);
        }
        | Factor {
            $$ = $<object_val>1;
            tmp_var[tmp_var_index] = $<object_val>1.symbol->name;
            tmp_var_index++;

        }
;

decStmtWithVal : VARIABLE_T Factor VAL_ASSIGN Expression ';' {
                    if($<var_type>1 == 1){
                        Insert_symbol($<object_val>4.type, $<object_val>2.symbol->name);
                    }else{
                        Insert_symbol($<var_type>1, $<object_val>2.symbol->name);
                    }
               }
               | VARIABLE_T Factor VAL_ASSIGN FunctionCallStmt ';' {
                    if($<var_type>1 == 1){
                        Insert_symbol($<object_val>4.type, $<object_val>2.symbol->name);
                    }else{
                        Insert_symbol($<var_type>1, $<object_val>2.symbol->name);
                    }
               }
;

ifStmt : ifHead '{' StmtList '}' { dumpScope(func_sig_none); }
       | ifHead StmtList { dumpScope(func_sig_none); }
       | ifElseStmt '{' StmtList '}' { dumpScope(func_sig_none); }
       | ifElseStmt StmtList { dumpScope(func_sig_none); }
;

ifElseStmt : ifHead '{' StmtList '}' ELSE { dumpSameScope(); printf("ELSE\n"); pushSameScope(); }
           | ifHead StmtList ELSE { dumpSameScope(); printf("ELSE\n"); pushSameScope(); }
;

ifHead : ifHead2 { pushScope(); } 
       | IF FunctionOp { printf("IF\n"); pushScope(); }
       | ifHead2 StmtList
;

ifHead2 : IF Expression { printf("IF\n"); }
;

castingStmt : '(' VARIABLE_T ')' Expression %prec NOT {
                $$ = $<object_val>4;
                $$.type = $<var_type>2;
                if($<var_type>2 == 0){
                    printf("Cast to undefined\n");
                } else if($<var_type>2 == 1)
                    printf("Cast to auto\n");
                else if($<var_type>2 == 2)
                    printf("Cast to void\n");
                else if($<var_type>2 == 3)
                    printf("Cast to char\n");
                else if($<var_type>2 == 4) {
                    printf("Cast to int\n");
                } else if($<var_type>2 == 5)
                    printf("Cast to long\n");
                else if($<var_type>2 == 6){
                    printf("Cast to float\n");
                } else if($<var_type>2 == 7)
                    printf("Cast to double\n");
                else if($<var_type>2 == 8)
                    printf("Cast to bool\n");
                else if($<var_type>2 == 9)
                    printf("Cast to string\n");
                else if($<var_type>2 == 10)
                    printf("Cast to function\n");
            }
;

whileStmt : { printf("WHILE\n"); } WHILE Expression {
                pushScope();
            } '{' StmtList '}' { dumpScope(func_sig_none); }
;

forStmt : { printf("FOR\n"); pushScope(); } forHead '{' StmtList '}' {
            dumpScope(func_sig_none);
        }
;

forHead : FOR '(' Expression ';' Expression ';' Expression ')'
        | FOR '(' ';' Expression ';' Expression ')'
        | FOR '(' decStmtList Expression ';' Expression ')'
        | FOR '(' Expression ';' ';' Expression ')'
        | FOR '(' Expression ';' Expression ';' ')'
        | FOR '(' ';' ';' ')'
        | FOR '(' VARIABLE_T IDENT ':' IDENT ')' {
            Object tmp = lookup_symbol($<s_var>6, 0);
            Insert_symbol(tmp.type, $<s_var>4);
            modifyVariable($<s_var>6);
        }
;

arrayDecStmt : VARIABLE_T arrayStmt VAL_ASSIGN '{' ElementList '}' ';' {
                printf("create array: %d\n", array_size);
                array_size = 0;
                Insert_symbol($<var_type>1, array_name);
             }
             | VARIABLE_T arrayStmt VAL_ASSIGN '{' Expression '}' ';'
             | VARIABLE_T arrayStmt VAL_ASSIGN '{' '}' {
                printf("create array: %d\n", 0);
                Insert_symbol($<var_type>1, array_name);
             }
             | VARIABLE_T arrayStmt ';' {
                Insert_symbol($<var_type>1, array_name);
             }
;

ElementList : ElementList ',' Expression {
                array_size += 1;
            }
            | IDENT {
                modifyVariable($<s_var>1);
            } ',' Expression {
                array_size += 2;
            }
            | Expression ',' Expression {
                array_size += 2;
            }
;

arrayAssignStmt : arrayStmt VAL_ASSIGN {
                    modifyVariable(array_name);
                } Expression ';' {
                    printf("EQL_ASSIGN\n");
                }
;

arrayStmt : arrayStmt '[' Expression ']' {
            
          }
          | IDENT '[' Expression ']' {
            array_name = $<s_var>1;
          }
;

Expression  : castingStmt {
                $$ = $<object_val>1;
            }
            | singleExpr { 
                $$ = $<object_val>1;
            }
            | Expression ADD Expression { 
                printf("ADD\n");
                $$ = $<object_val>1;
            }
            | Expression SUB Expression {
                printf("SUB\n");
                $$ = $<object_val>1;
            }
            | Expression BAN Expression { 
                printf("BAN\n");
                $$ = $<object_val>1;
            }
            | Expression BOR Expression { 
                printf("BOR\n");
                $$ = $<object_val>1;
            }
            | Expression BXO Expression { 
                printf("BXO\n");
                $$ = $<object_val>1;
            }
            | Expression LOR Expression {
                printf("LOR\n");
                $$.type = OBJECT_TYPE_BOOL;
            }
            | Expression LAN Expression {
                printf("LAN\n");
                $$.type = OBJECT_TYPE_BOOL;
            }
            | Expression GTR Expression {
                printf("GTR\n");
                $$.type = OBJECT_TYPE_BOOL;
            }
            | Expression LEQ Expression {
                printf("LEQ\n");
                $$.type = OBJECT_TYPE_BOOL;
            }
            | Expression LES Expression {
                printf("LES\n");
                $$.type = OBJECT_TYPE_BOOL;
            }
            | Expression GEQ Expression {
                printf("GEQ\n");
                $$.type = OBJECT_TYPE_BOOL;
            }
            | Expression NEQ Expression {
                printf("NEQ\n");
                $$.type = OBJECT_TYPE_BOOL;
            }
            | Expression EQL Expression {
                printf("EQL\n");
                $$.type = OBJECT_TYPE_BOOL;
            }
            | Expression SHR Expression { 
                printf("SHR\n");
                $$ = $<object_val>1;
            }
            | Expression MUL Expression {
                printf("MUL\n");
                $$ = $<object_val>1;
            }
            | Expression DIV Expression {
                printf("DIV\n");
                $$ = $<object_val>1;
            }
            | Expression REM Expression { 
                printf("REM\n");
                $$ = $<object_val>1;
            }
            | Expression VAL_ASSIGN Expression {
                printf("EQL_ASSIGN\n");
                $$ = $<object_val>1;
            }
            | Expression ADD_ASSIGN Expression { 
                printf("ADD_ASSIGN\n");
                $$ = $<object_val>1;
            }
            | Expression SUB_ASSIGN Expression {
                printf("SUB_ASSIGN\n"); 
                $$ = $<object_val>1;
            }
            | Expression MUL_ASSIGN Expression { 
                printf("MUL_ASSIGN\n");
                $$ = $<object_val>1;
            }
            | Expression DIV_ASSIGN Expression {
                printf("DIV_ASSIGN\n");
                $$ = $<object_val>1;
            }
            | Expression REM_ASSIGN Expression { 
                printf("REM_ASSIGN\n");
                $$ = $<object_val>1;
            }
            | Expression SHR_ASSIGN Expression {
                printf("SHR_ASSIGN\n");
                $$ = $<object_val>1;
            }
            | Expression SHL_ASSIGN Expression {
                printf("SHL_ASSIGN\n");
                $$ = $<object_val>1; 
            }
            | Expression BOR_ASSIGN Expression { 
                printf("BOR_ASSIGN\n"); 
                $$ = $<object_val>1;
            }
            | Expression BXO_ASSIGN Expression {
                printf("BXO_ASSIGN\n"); 
                $$ = $<object_val>1;
            }
            | Expression BAN_ASSIGN Expression {
                printf("BAN_ASSIGN\n"); 
                $$ = $<object_val>1;
            }
            | Expression INC_ASSIGN {
                printf("INC_ASSIGN\n");
            }
            | Expression DEC_ASSIGN {
                printf("DEC_ASSIGN\n");
            }
            | '(' Expression ')' { $$ = $<object_val>2; }
;

singleExpr : SUB Factor { 
                printf("NEG\n");
                $$.type = $<object_val>2.type;
            }
           | SUB IDENT { 
                printf("NEG\n");
            }
           | BNT Factor { 
                printf("BNT\n");
                $$.type = $<object_val>2.type;
            }
           | BNT IDENT { 
                printf("BNT\n");
            }
           | NOT Factor { 
                printf("NOT\n");
                $$.type = $<object_val>2.type;
            }
           | NOT IDENT { 
                printf("NOT\n"); 
            }
           | NOT singleExpr { 
                printf("NOT\n");
                $$.type = $<object_val>2.type;
            }
           | Factor {
                $$ = $<object_val>1;
           }
;

Factor  : INT_LIT { 
            printf("INT_LIT %d\n", $<i_var>1);
            $$.type = OBJECT_TYPE_INT;
            $$.value = $<i_var>1;
        }
        | FLOAT_LIT { 
            printf("FLOAT_LIT %f\n", $<f_var>1);
            $$.type = OBJECT_TYPE_FLOAT;
        }
        | STR_LIT { 
            printf("STR_LIT \"%s\"\n", $<s_var>1);
            $$.type = OBJECT_TYPE_STR;
            $$.symbol = (SymbolData*)malloc(sizeof(SymbolData));
            $$.symbol->name = (char*)malloc(sizeof(char)*50);
            strcpy($$.symbol->name, $<s_var>1);
        }
        | BOOL_LIT {
            if($<b_var>1)
                printf("BOOL_LIT TRUE\n");
            else
                printf("BOOL_LIT FALSE\n");
            $$.type = OBJECT_TYPE_BOOL;
        }
        | IDENT {
            Object tmp = lookup_symbol($<s_var>1, 0);
            $$.symbol = (SymbolData*)malloc(sizeof(SymbolData));
            $$.symbol->name = (char*)malloc(sizeof(char)*50);
            strcpy($$.symbol->name, $<s_var>1);
            $$.type = tmp.type;
            modifyVariable($<s_var>1);
        }
;

%%
/* C code section */
