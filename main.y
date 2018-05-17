%{
    #include "stdio.h"
    #include "math.h"
    #include "string.h"
    #include "node.h"

    extern char *yytext;
    extern FILE *yyin;

    int yyerror(char *s);
    int yylex();
%}

%union {
    int int_value;
    char name_value[32];
    float float_value;
    struct tree_node * tree_node;
};

%type       <tree_node>     block 
%token      <name_value>    _VARIABLE_NAME
%token      <int_value>     _INTEGER_VALUE
%token      <float_value>   _FLOAT_VALUE
%token      <char_value>    _CHAR_VALUE

%token      _INT_DECLARATION _FLOAT_RECLARATION _CHAR_DECLARATION
%token      _IF_CONDITION _WHILE_CONDITION
%token      _ASSIGN_UNARY_OP _PLUS_OP _MINUS_OP _MULTIPLE_OP _DIVIDE_OP _MODULE_OP
%token      _PLUS_ASSIGN_OP _MINUS_ASSIGN_OP _MULTI_ASSIGN_OP _DIVIDE_ASSIGN_OP _MODULE_ASSIGN_OP
%token      _SELF_PLUS_UNARY_OP _SELF_MINUS_UNARY_OP
%token      _LARGER_OP _LESS_OP _LARGER_EQUAL_OP _LESS_EQUAL_OP _NOT_EQUAL_OP _EQUAL_OP
%token      _LEFT_BRACKET _RIGHT_BRACKET _LEFT_BRACE _RIGHT_BRACE
%token      _END_DIVIDED_CHAR _COMMA_DIVIDED_CHAR
%token      _COMMENT_LEFT _COMMENT_RIGHT
%token      _EOF

%left       _COMMA_DIVIDED_CHAR
%right      _ASSIGN_UNARY_OP _PLUS_ASSIGN_OP _MINUS_ASSIGN_OP _MULTI_ASSIGN_OP _DIVIDE_ASSIGN_OP _MODULE_ASSIGN_OP
%left       _EQUAL_OP _NOT_EQUAL_OP
%left       _LARGER_OP _LESS_OP _LARGER_EQUAL_OP _LESS_EQUAL_OP
%left       _PLUS_OP _MINUS_OP
%left       _MULTIPLE_OP _DIVIDE_OP _MODULE_OP _LEFT_SELF_PLUS_UNARY_OP _LEFT_SELF_MINUS_UNARY_OP
%right      _RIGHT_SELF_PLUS_UNARY_OP _RIGHT_SELF_MINUS_UNARY_OP _UMINUS_OP
%left       _EXP_LEFT_BRACKET _EXP_RIGHT_BRACKET

%%

code:
    |   code block
    |   code _EOF {
            printf("A block for whole program\n"); return 0;
        }
    ;

block:  sentence _END_DIVIDED_CHAR {
            ;
        }
    |   _LEFT_BRACE code _RIGHT_BRACE {
            printf("A block for brace block\n");
        }
    |   _IF_CONDITION _LEFT_BRACKET exp _RIGHT_BRACKET block {
            printf("An if sentence\n");
        }
    |   _WHILE_CONDITION _LEFT_BRACKET exp _RIGHT_BRACKET block {
            printf("A while sentence\n");
        }
    ;

sentence:
        exp
    |   var_declaration {
            printf("A declaration\n");
        }
    ;

exp:    
        _PLUS_OP 
    |   _MINUS_OP 
    |   _MULTIPLE_OP 
    |   exp _COMMA_DIVIDED_CHAR exp
    |   _VARIABLE_NAME _ASSIGN_UNARY_OP _INTEGER_VALUE
    |   _VARIABLE_NAME _ASSIGN_UNARY_OP _FLOAT_VALUE
    |   _VARIABLE_NAME _ASSIGN_UNARY_OP _CHAR_VALUE
    ;

var_declaration:
        _INT_DECLARATION var_link_int
    |   _FLOAT_RECLARATION var_link_float
    |   _CHAR_DECLARATION var_link_char
    ;

var_link_int:
        _VARIABLE_NAME _ASSIGN_UNARY_OP _INTEGER_VALUE
    |   var_link_int _COMMA_DIVIDED_CHAR var_link_int
    ;

var_link_float:
        _VARIABLE_NAME _ASSIGN_UNARY_OP _FLOAT_VALUE
    |   var_link_float _COMMA_DIVIDED_CHAR var_link_float
    ;

var_link_char:
        _VARIABLE_NAME _ASSIGN_UNARY_OP _CHAR_VALUE
    |   var_link_char _COMMA_DIVIDED_CHAR var_link_char
    ;
%%

int main(int argc, char *argv[]){
	yyin = fopen(argv[1], "r");
	if (!yyin) {
        return 0;
    }
	yyparse();
	return 0;
}