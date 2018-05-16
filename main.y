%{
    #include "stdio.h"
    #include "math.h"
    #include "string.h"
    #include "node.h"

    extern char *yytext;
    extern FILE *yyin;
%}

%union {
    int int_value;
    char name_value[32];
    float float_value;
    struct tree_node * _tree_node;
};

%type       <_tree_node>     line exp
%token      <int_value>     _INTEGER_VALUE
%token      <name_value>    _VARIABLE_NAME
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

%right      _ASSIGN_UNARY_OP _PLUS_ASSIGN_OP _MINUS_ASSIGN_OP _MULTI_ASSIGN_OP _DIVIDE_ASSIGN_OP _MODULE_ASSIGN_OP
%left       _EQUAL_OP _NOT_EQUAL_OP
%left       _LARGER_OP _LESS_OP _LARGER_EQUAL_OP _LESS_EQUAL_OP
%left       _PLUS_OP _MINUS_OP
%left       _MULTIPLE_OP _DIVIDE_OP _MODULE_OP _LEFT_SELF_PLUS_UNARY_OP _LEFT_SELF_MINUS_UNARY_OP
%right      _RIGHT_SELF_PLUS_UNARY_OP _RIGHT_SELF_MINUS_UNARY_OP _UMINUS_OP
%left       _LEFT_BRACKET _RIGHT_BRACKET

%%

code:
    | code line
    ;

line: '\n'      {;}
    | exp '\n'  {;}
    | exp exp '\n' {;}
    ;

exp : _PLUS_OP
    | _MULTIPLE_OP
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