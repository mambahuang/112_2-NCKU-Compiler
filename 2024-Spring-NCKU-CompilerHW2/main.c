#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

#define debug printf("%s:%d: ############### debug\n", __FILE__, __LINE__)

#define toupper(_char) (_char - (char)32)

const char* objectTypeName[] = {
    [OBJECT_TYPE_UNDEFINED] = "undefined",
    [OBJECT_TYPE_VOID] = "void",
    [OBJECT_TYPE_INT] = "int",
    [OBJECT_TYPE_FLOAT] = "float",
    [OBJECT_TYPE_BOOL] = "bool",
    [OBJECT_TYPE_STR] = "string",
    [OBJECT_TYPE_FUNCTION] = "function",
};

char* yyInputFileName;
bool compileError;

int indent = 0;
int scopeLevel = -1;
int funcLineNo = 0;
int cs_idx = -1;
int cout_num = 0;
int variableAddress = -1;
ObjectType variableIdentType;

int table_len[50] = {}; 
NODE table[50][50];
int address = 0;
char* str_cout[50] = {};
// int type = 0;
// char now_type[10] = "none";
// char now_op[10] = "none";
// char now_id[10] = "none";
// NODE *global_node , node_saving;

// char variable_name[20] = {};
// int variable_address = 0;
// int block_create = 0;
// bool func_first = 1;

void pushScope() {
    cs_idx++;
    // scopeLevel++;
    printf("> Create symbol table (scope level %d)\n", cs_idx);
}

void dumpScope() {
    // printf("> Dump symbol table (scope level: %d)\n", scope) , f = 1;
    printf("\n> Dump symbol table (scope level: %d)\n", cs_idx);


    printf("%-10s%-20s%-10s%-10s%-10s%-10s\n",
           "Index", "Name" , "Type", "Addr", "Lineno", "Func_sig");
    for(int i=0; i<table_len[cs_idx]; ++i){
        
        int mut = 0;

        if( strcmp(table[cs_idx][i].type,"function") == 0 ) mut = -1;

        if( mut == -1 )
        {
            printf("%-10d%-20s%-10s%-10d%-10d%-10s\n",
            i, table[cs_idx][i].name, table[cs_idx][i].type, table[cs_idx][i].address, table[cs_idx][i].lineno, "([Ljava/lang/String;)I");
        }     
        else 
        {
            printf("%-10d%-20s%-10s%-10d%-10d%-10s\n",
            i, table[cs_idx][i].name, table[cs_idx][i].type, table[cs_idx][i].address, table[cs_idx][i].lineno, "-");
        } 
    }
    table_len[cs_idx] = 0;
    cs_idx--;
}

Object* createVariable(ObjectType variableType, char* variableName, int variableFlag) {
    // printf("> Insert `%s` (addr: %d) to scope level %d\n", variableName, address, cs_idx);
    // printf("variable type: %s\n", objectTypeName[variableType]); -> type: int
    // address++;
    return NULL;
}

void modifyVariable(char* variableName) {
    NODE tmp = lookup_symbol(variableName, 0);
    if (tmp.address == 404) {
        printf("IDENT (name=%s, address=%d)\n", variableName, address - 1);
    } else {
        printf("IDENT (name=%s, address=%d)\n", variableName, tmp.address);
    }
}

void pushFunParm(ObjectType variableType, char* variableName, int variableFlag) {
    
}

void createFunction(ObjectType variableType, char* funcName) {
    
}

int Insert_symbol(ObjectType variableType, char* funcName) {
    NODE tmp = lookup_symbol(funcName, 0);
    
    if( strcmp(objectTypeName[variableType],"function") == 0 )
    {
        table[cs_idx][table_len[cs_idx]].address = address;
        table[cs_idx][table_len[cs_idx]].lineno = yylineno;
        strcpy(table[cs_idx][table_len[cs_idx]].name, funcName);
        strcpy(table[cs_idx][table_len[cs_idx]].type, objectTypeName[variableType]);
        // if( strcmp(element_type,"1") == 0 ) table[cs_idx][table_len[cs_idx]].mut = 1;
        // strcpy(table[cs_idx][table_len[cs_idx]].element_type, element_type);
        table_len[cs_idx]++;
        printf("func: %s\n",funcName); 
        printf("> Insert `%s` (addr: %d) to scope level %d\n", funcName, -1, cs_idx); 
        table[cs_idx][table_len[cs_idx-1]].address = -1;
      //  if( check_newline == 1 ) printf("\n");
        return -1;
    }
    // else printf("> Insert `%s` (addr: %d) to scope level %d\n", funcName, address, cs_idx);

    if(tmp.address == 404) { // not found
        printf("> Insert `%s` (addr: %d) to scope level %d\n", funcName, address, cs_idx);
        // if(strcmp(funcName, "argv") != 0)
        //     printf("IDENT (name=%s, address=%d)\n", funcName, address);
        table[cs_idx][table_len[cs_idx]].address = address;
        table[cs_idx][table_len[cs_idx]].lineno = yylineno;
        strcpy(table[cs_idx][table_len[cs_idx]].name, funcName);
        strcpy(table[cs_idx][table_len[cs_idx]].type, objectTypeName[variableType]);
        // if( strcmp(element_type,"1") == 0 ) table[cs_idx][table_len[cs_idx]].mut = 1;
        // strcpy(table[cs_idx][table_len[cs_idx]].element_type, element_type);
        table_len[cs_idx]++;
        address++;
    }

    // if( strcmp(objectTypeName[variableType],"function") != 0 ) address++;

    return address - 1;
}

NODE lookup_symbol(char* name, int flag) {

    for(int i=cs_idx; i>=0; --i){
        for(int j=0; j<table_len[i]; ++j){
            if(0 == strcmp(table[i][j].name, name))
                return table[i][j];
        }
    }
    NODE node;
    node.address = 404; // 404 not found
    return node;
}

void debugPrintInst(char instc, Object* a, Object* b, Object* out) {
}

bool objectExpression(char op, Object* dest, Object* val, Object* out) {
    return false;
}

bool objectExpBinary(char op, Object* a, Object* b, Object* out) {
    return false;
}

bool objectExpBoolean(char op, Object* a, Object* b, Object* out) {
    return false;
}

bool objectExpAssign(char op, Object* dest, Object* val, Object* out) {
    return false;
}

bool objectValueAssign(Object* dest, Object* val, Object* out) {
    return false;
}

bool objectNotBinaryExpression(Object* dest, Object* out) {
    return false;
}

bool objectNegExpression(Object* dest, Object* out) {
    return false;
}
bool objectNotExpression(Object* dest, Object* out) {
    return false;
}

bool objectIncAssign(Object* a, Object* out) {
    return false;
}

bool objectDecAssign(Object* a, Object* out) {
    return false;
}

bool objectCast(ObjectType variableType, Object* dest, Object* out) {
    return false;
}

Object* findVariable(char* variableName) {
    Object* variable = NULL;
    return variable;
}

void pushFunInParm(Object* variable) {
    
}

void coutStmt(char* var_type) {
    str_cout[cout_num] = var_type;
    cout_num++;
}

void stdoutPrint() {
    for (int i = 0; i < cout_num; i++)
    {
        if( i == cout_num - 1 ) printf("%s\n", str_cout[i]);
        else printf("%s ", str_cout[i]);
    }
    cout_num = 0;
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        yyin = fopen(yyInputFileName = argv[1], "r");
    } else {
        yyin = stdin;
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", yyInputFileName);
        exit(1);
    }

    // Start parsing
    yyparse();
    printf("Total lines: %d\n", yylineno);
    fclose(yyin);

    yylex_destroy();
    return 0;
}
