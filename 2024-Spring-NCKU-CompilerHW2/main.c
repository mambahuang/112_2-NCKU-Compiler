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

int table_len[50] = {0}; 
Object table[50][50];
int address = 0;
char* str_cout[50] = {};

void pushScope() {
    scopeLevel++;
    printf("> Create symbol table (scope level %d)\n", scopeLevel);
    table[scopeLevel][table_len[scopeLevel]].symbol = (SymbolData*)malloc(sizeof(SymbolData));
    table[scopeLevel][table_len[scopeLevel]].symbol->name = (char*)malloc(sizeof(char)*50);
    table[scopeLevel][table_len[scopeLevel]].symbol->index = 0;
    table[scopeLevel][table_len[scopeLevel]].symbol->addr = 0;
    table[scopeLevel][table_len[scopeLevel]].symbol->lineno = 0;
    table[scopeLevel][table_len[scopeLevel]].symbol->func_sig = (char*)malloc(sizeof(char)*50);
    table[scopeLevel][table_len[scopeLevel]].symbol->func_var = 0;
}

void pushSameScope() {
    printf("> Create symbol table (scope level %d)\n", scopeLevel);
    table[scopeLevel][table_len[scopeLevel]].symbol = (SymbolData*)malloc(sizeof(SymbolData));
    table[scopeLevel][table_len[scopeLevel]].symbol->name = (char*)malloc(sizeof(char)*50);
    table[scopeLevel][table_len[scopeLevel]].symbol->index = 0;
    table[scopeLevel][table_len[scopeLevel]].symbol->addr = 0;
    table[scopeLevel][table_len[scopeLevel]].symbol->lineno = 0;
    table[scopeLevel][table_len[scopeLevel]].symbol->func_sig = (char*)malloc(sizeof(char)*50);
    table[scopeLevel][table_len[scopeLevel]].symbol->func_var = 0;
}

void dumpScope() {
    printf("\n> Dump symbol table (scope level: %d)\n", scopeLevel);

    printf("%-10s%-20s%-10s%-10s%-10s%-10s\n",
           "Index", "Name" , "Type", "Addr", "Lineno", "Func_sig");
    for(int i=0; i<table_len[scopeLevel]; ++i){
        
        int mut = 0;

        if( table[scopeLevel][i].type == OBJECT_TYPE_FUNCTION ) mut = -1;

        if( mut == -1 )
        {
            printf("%-10d%-20s%-10s%-10ld%-10d%-10s\n",
            i, table[scopeLevel][i].symbol->name, objectTypeName[table[scopeLevel][i].type], table[scopeLevel][i].symbol->addr, table[scopeLevel][i].symbol->lineno, "([Ljava/lang/String;)I");
        }     
        else 
        {
            printf("%-10d%-20s%-10s%-10ld%-10d%-10s\n",
            i, table[scopeLevel][i].symbol->name, objectTypeName[table[scopeLevel][i].type], table[scopeLevel][i].symbol->addr, table[scopeLevel][i].symbol->lineno, "-");
        } 
    }
    table_len[scopeLevel] = 0;
    scopeLevel--;
}

void dumpSameScope() {
    printf("\n> Dump symbol table (scope level: %d)\n", scopeLevel);

    printf("%-10s%-20s%-10s%-10s%-10s%-10s\n",
           "Index", "Name" , "Type", "Addr", "Lineno", "Func_sig");
    for(int i=0; i<table_len[scopeLevel]; ++i){
        
        int mut = 0;

        if( table[scopeLevel][i].type == OBJECT_TYPE_FUNCTION ) mut = -1;

        if( mut == -1 )
        {
            printf("%-10d%-20s%-10s%-10ld%-10d%-10s\n",
            i, table[scopeLevel][i].symbol->name, objectTypeName[table[scopeLevel][i].type], table[scopeLevel][i].symbol->addr, table[scopeLevel][i].symbol->lineno, "([Ljava/lang/String;)I");
        }     
        else 
        {
            printf("%-10d%-20s%-10s%-10ld%-10d%-10s\n",
            i, table[scopeLevel][i].symbol->name, objectTypeName[table[scopeLevel][i].type], table[scopeLevel][i].symbol->addr, table[scopeLevel][i].symbol->lineno, "-");
        } 
    }
    table_len[scopeLevel] = 0;
}

Object* createVariable(ObjectType variableType, char* variableName, int variableFlag) {
    // printf("> Insert `%s` (addr: %d) to scope level %d\n", variableName, address, scopeLevel);
    // printf("variable type: %s\n", objectTypeName[variableType]); -> type: int
    // address++;
    return NULL;
}

void modifyVariable(char* variableName) {
    Object tmp = lookup_symbol(variableName, 0);
    if (tmp.symbol->addr != 404) {
        printf("IDENT (name=%s, address=%ld)\n", variableName, tmp.symbol->addr);
    }
}

void pushFunParm(ObjectType variableType, char* variableName, int variableFlag) {
    
}

void createFunction(ObjectType variableType, char* funcName) {
    
}

int Insert_symbol(ObjectType variableType, char* funcName) {
    Object tmp = lookup_symbol(funcName, 0);

    if( variableType == OBJECT_TYPE_FUNCTION )
    {
        table[scopeLevel][table_len[scopeLevel]].symbol->addr = address;
        table[scopeLevel][table_len[scopeLevel]].symbol->lineno = yylineno;
        strcpy(table[scopeLevel][table_len[scopeLevel]].symbol->name, funcName);
        table[scopeLevel][table_len[scopeLevel]].type = variableType;
        strcpy(table[scopeLevel][table_len[scopeLevel]].symbol->func_sig, "([Ljava/lang/String;)I");
        table_len[scopeLevel]++;
        printf("func: %s\n",funcName); 
        printf("> Insert `%s` (addr: %d) to scope level %d\n", funcName, -1, scopeLevel); 
        table[scopeLevel][table_len[scopeLevel-1]].symbol->addr = -1;
        return -1;
    }

    if(tmp.symbol->addr == 404) { // not found
        printf("> Insert `%s` (addr: %d) to scope level %d\n", funcName, address, scopeLevel);
        table[scopeLevel][table_len[scopeLevel]].symbol->addr = address;
        table[scopeLevel][table_len[scopeLevel]].symbol->lineno = yylineno;
        strcpy(table[scopeLevel][table_len[scopeLevel]].symbol->name, funcName);
        table[scopeLevel][table_len[scopeLevel]].type = variableType;
        table_len[scopeLevel]++;
        address++;
    } else {
        // printf("current type: %d\n", variableType);
        // printf("tmp type: %s\n", objectTypeName[tmp.type]);
        if(variableType != tmp.type) {
            // printf("> Insert `%s` (addr: %d) to scope level %d\n", funcName, address, scopeLevel);
            // table[scopeLevel][table_len[scopeLevel]].symbol->addr = address;
            // table[scopeLevel][table_len[scopeLevel]].symbol->lineno = yylineno;
            // strcpy(table[scopeLevel][table_len[scopeLevel]].symbol->name, funcName);
            // table[scopeLevel][table_len[scopeLevel]].type = variableType;
            // table_len[scopeLevel]++;
            // address++;
        }
    }

    return address - 1;
}

Object lookup_symbol(char* name, int flag) {

    for(int i=scopeLevel; i>=0; --i){
        for(int j=0; j<table_len[i]; ++j){
            if(0 == strcmp(table[i][j].symbol->name, name))
                return table[i][j];
        }
    }
    Object node = (Object){.type = OBJECT_TYPE_UNDEFINED, .value = 0, .symbol = (SymbolData*)malloc(sizeof(SymbolData))};
    node.symbol->addr = 404; // 404 not found
    node.symbol->lineno = yylineno;
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

void stdoutPrint(ObjectType* cout_str, int cout_num) {
    printf("cout");
    for(int i=0; i<cout_num; ++i){
        printf(" %s", objectTypeName[cout_str[i]]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    // Initialize
    for(int i=0; i<50; ++i){
        table_len[i] = 0;
    }
    for (int i = 0; i < 50; i++){
        for(int j=0; j<50; ++j){
            table[i][j].symbol = (SymbolData*)malloc(sizeof(SymbolData));
            table[i][j].symbol->name = (char*)malloc(sizeof(char)*50);
            table[i][j].symbol->func_sig = (char*)malloc(sizeof(char)*50);
        }
    }
    
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
