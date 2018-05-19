%option yylineno
%{
    #include "main.tab.h"
    #include "string.h"
    #include "node.h"

    void printDetail(char *yytext, char *type);

    typedef union {
        int int_value;
        char name_value[32];
        float float_value;
        tree_node * _tree_node;
    } YYLVAL;
    #define YYSTYPE YYLVAL;
%}

variable_name               [A-Za-z][A-Za-z0-9]*
integer_value               [0-9]+
float_value                 [0-9]+(\.[0-9]+)?f
char_value                  \'.\'

%%

 /**********************/

"int" {
    printDetail("DATA_DECLARE_NODE", yytext);
    return _INT_DECLARATION;
}

"float" {
    printDetail("DATA_DECLARE_NODE", yytext);
    return _FLOAT_RECLARATION;
}

"char" {
    printDetail("DATA_DECLARE_NODE", yytext);
    return _CHAR_DECLARATION;
}

 /**********************/

"if" {
    printDetail("CONDITION_NODE", yytext);
    return _IF_CONDITION;
}

"while" {
    printDetail("CONDITION_NODE", yytext);
    return _WHILE_CONDITION;
}

"else" {
    printDetail("CONDITION_NODE", yytext);
    return _ELSE_CONDITION;
}

 /**********************/

{variable_name} {
    strcpy(yylval.name_value, yytext);
    printDetail("VARIABLE_NODE", yytext);
    return _VARIABLE_NAME;
}

{integer_value} {
    yylval.int_value = atoi(yytext);
    printDetail("CONST_INT_NODE", yytext);
    return _INTEGER_VALUE;
}

{float_value} {
    yylval.float_value = atof(yytext);
    printDetail("CONST_FLOAT_NODE", yytext);
    return _FLOAT_VALUE;
}

{char_value} {
    strcpy(yylval.name_value, yytext);
    printDetail("CONST_CHAR_NODE", yytext);
    return _CHAR_VALUE;
}

 /**********************/

"=" {
    printDetail("BINARY_OP_NODE", yytext);
    return _ASSIGN_UNARY_OP;
}

"+" {
    printDetail("BINARY_OP_NODE", yytext);
    return _PLUS_OP;
}

"-" {
    printDetail("MULTIPLE_OP_NODE", yytext);
    return _MINUS_OP;
}

"*" {
    printDetail("BINARY_OP_NODE", yytext);
    return _MULTIPLE_OP;
}

"/" {
    printDetail("BINARY_OP_NODE", yytext);
    return _DIVIDE_OP;
}

"%" {
    printDetail("BINARY_OP_NODE", yytext);
    return _MODULE_OP;
}

 /**********************/

"||" {
    printDetail("BINARY_OP_NODE", yytext);
    return _OR_OP;
}

"&&" {
    printDetail("BINARY_OP_NODE", yytext);
    return _AND_OP;
}

"!" {
    printDetail("UNARY_OP_NODE", yytext);
    return _NOT_OP;
}

 /**********************/

"+=" {
    printDetail("BINARY_OP_NODE", yytext);
    return _PLUS_ASSIGN_OP;
}

"-=" {
    printDetail("BINARY_OP_NODE", yytext);
    return _MINUS_ASSIGN_OP;
}

"*=" {
    printDetail("BINARY_OP_NODE", yytext);
    return _MULTI_ASSIGN_OP;
}

"/=" {
    printDetail("BINARY_OP_NODE", yytext);
    return _DIVIDE_ASSIGN_OP;
}

"%=" {
    printDetail("BINARY_OP_NODE", yytext);
    return _MODULE_ASSIGN_OP;
}

 /**********************/

"++" {
    printDetail("UNARY_OP_NODE", yytext);
    return _SELF_PLUS_UNARY_OP;
}

"--" {
    printDetail("UNARY_OP_NODE", yytext);
    return _SELF_MINUS_UNARY_OP;
}

 /**********************/

">" {
    printDetail("BINARY_OP_NODE", yytext);
    return _LARGER_OP;
}

"<" {
    printDetail("BINARY_OP_NODE", yytext);
    return _LESS_OP;
}

">=" {
    printDetail("BINARY_OP_NODE", yytext);
    return _LARGER_EQUAL_OP;
}

"<=" {
    printDetail("BINARY_OP_NODE", yytext);
    return _LESS_EQUAL_OP;
}

"!=" {
    printDetail("BINARY_OP_NODE", yytext);
    return _NOT_EQUAL_OP;
}

"==" {
    printDetail("BINARY_OP_NODE", yytext);
    return _EQUAL_OP;
}

 /**********************/

"(" {
    printDetail("LEFT_BRACKET_NODE", yytext);
    return _LEFT_BRACKET;
}

")" {
    printDetail("RIGHT_BRACKET_NODE", yytext);
    return _RIGHT_BRACKET;
}

"{" {
    printDetail("LEFT_BRACE_NODE", yytext);
    return _LEFT_BRACE;
}

"}" {
    printDetail("RIGHT_BRACE_NODE", yytext);
    return _RIGHT_BRACE;
}

 /**********************/

";" {
    printDetail("DIVIDED_CHAR", yytext);
    return _END_DIVIDED_CHAR;
}

"," {
    printDetail("DIVIDED_CHAR", yytext);
    return _COMMA_DIVIDED_CHAR;
}

 /**********************/

"/*" {
    printDetail("COMMENT_LEFT_NODE", yytext);
    return _COMMENT_LEFT;
}

"*/" {
    printDetail("COMMENT_RIGHT_NODE", yytext);
    return _COMMENT_RIGHT;
}

 /**********************/

[ \t] {;}

[\n] {;}

<<EOF>> {
    printDetail("_EOF", yytext);
    return _EOF;
}

. {
    printf("error in line %d\n", yylineno);
}

%%

void printDetail(char *yytext, char *type) {
    printf("{%s, %s}\n", type, yytext);
}

int yyerror(char *text) {
    printf("%s %s %d\n", text, yytext, yylineno);
    return 0;
}