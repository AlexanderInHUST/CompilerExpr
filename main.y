%{
    #include "stdio.h"
    #include "math.h"
    #include "string.h"
    #include "node.h"
    #include "symbol_table.h"
    #include "create_table.h"
    #include "checker.h"
    #include "TAC_generator.h"
    #include "TAC.h"

    extern char *yytext;
    extern FILE *yyin;

    int yyerror(char *s);
    int yylex();
    void exit(int);
    enum exp_kind get_exp_kind (struct tree_node * e1, struct tree_node * e2);
    
%}

%union {
    int int_value;
    char name_value[32];
    float float_value;
    char char_value[32];
    struct tree_node * tree_node;
};

%type       <tree_node>     code block sentence exp if_conditions while_conditions assign_series declaration_series var_declaration
%token      <name_value>    _VARIABLE_NAME
%token      <int_value>     _INTEGER_VALUE
%token      <float_value>   _FLOAT_VALUE
%token      <char_value>    _CHAR_VALUE

%token      _INT_DECLARATION _FLOAT_RECLARATION _CHAR_DECLARATION
%token      _IF_CONDITION _WHILE_CONDITION _ELSE_CONDITION
%token      _ASSIGN_UNARY_OP _PLUS_OP _MINUS_OP _MULTIPLE_OP _DIVIDE_OP _MODULE_OP
%token      _OR_OP _AND_OP _NOT_OP
%token      _PLUS_ASSIGN_OP _MINUS_ASSIGN_OP _MULTI_ASSIGN_OP _DIVIDE_ASSIGN_OP _MODULE_ASSIGN_OP
%token      _SELF_PLUS_UNARY_OP _SELF_MINUS_UNARY_OP
%token      _LARGER_OP _LESS_OP _LARGER_EQUAL_OP _LESS_EQUAL_OP _NOT_EQUAL_OP _EQUAL_OP
%token      _LEFT_BRACKET _RIGHT_BRACKET _LEFT_BRACE _RIGHT_BRACE
%token      _END_DIVIDED_CHAR _COMMA_DIVIDED_CHAR
%token      _COMMENT_LEFT _COMMENT_RIGHT

%left       _COMMA_DIVIDED_CHAR
%right      _ASSIGN_UNARY_OP _PLUS_ASSIGN_OP _MINUS_ASSIGN_OP _MULTI_ASSIGN_OP _DIVIDE_ASSIGN_OP _MODULE_ASSIGN_OP
%left       _OR_OP _AND_OP
%left       _EQUAL_OP _NOT_EQUAL_OP
%left       _LARGER_OP _LESS_OP _LARGER_EQUAL_OP _LESS_EQUAL_OP
%left       _PLUS_OP _MINUS_OP
%left       _MULTIPLE_OP _DIVIDE_OP _MODULE_OP _LEFT_SELF_PLUS_UNARY_OP _LEFT_SELF_MINUS_UNARY_OP
%right      _RIGHT_SELF_PLUS_UNARY_OP _RIGHT_SELF_MINUS_UNARY_OP _UMINUS_OP _NOT_OP
%left       _LEFT_BRACKET _RIGHT_BRACKET

%%

input:
        code {
            display($1, 0);
            symbol_table * root = create_symbol_table();
            check_results_array * checks = create_check_results_array();
            count_stack * stack = create_count_stack();
            create_tables(root, 0, $1, -1, checks);
            print_check_results_array(checks);
            make_up_TACs($1, root, stack);
            print_table(root, "", 1);
            print_TAC_list($1->codes);
            free_symbol_table(root, 0);
            free_check_results_array(&checks);
        }
    ;

code:   {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->kind = BLANK_NODE;
        }
    |   code block {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = NOT_EXP;
            strcpy($$->op_name, $2->op_name);
            $$->kind = CODE_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $2;
        }
    |   code if_conditions {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = NOT_EXP;
            strcpy($$->op_name, $2->op_name);
            $$->kind = CODE_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $2;
        }
    |   code while_conditions {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = NOT_EXP;
            strcpy($$->op_name, $2->op_name);
            $$->kind = CODE_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $2;
        }
    |   code sentence _END_DIVIDED_CHAR {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = NOT_EXP;
            strcpy($$->op_name, $2->op_name);
            $$->kind = CODE_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $2;
        }
    ;

if_conditions:
        _IF_CONDITION _LEFT_BRACKET exp _RIGHT_BRACKET block {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            strcpy($$->op_name, "if");
            $$->exp_kind = NOT_EXP;
            $$->kind = IF_CONDITION_NODE;
            $$->binary_children.left_child = $3;
            $$->binary_children.right_child = $5;
            $$->line_number = @1.first_line;
        }
    
    |   _IF_CONDITION _LEFT_BRACKET exp _RIGHT_BRACKET block _ELSE_CONDITION block {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            strcpy($$->op_name, "if-else");
            $$->exp_kind = NOT_EXP;
            $$->kind = IF_ELSE_CONDITION_NODE;
            $$->trinary_children.first_child = $3;
            $$->trinary_children.second_child = $5;
            $$->trinary_children.third_child = $7;
            $$->line_number = @1.first_line;
        }
    
    |   _IF_CONDITION _LEFT_BRACKET exp _RIGHT_BRACKET block _ELSE_CONDITION if_conditions {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            strcpy($$->op_name, "if-else");
            $$->exp_kind = NOT_EXP;
            $$->kind = IF_ELSE_CONDITION_NODE;
            $$->trinary_children.first_child = $3;
            $$->trinary_children.second_child = $5;
            $$->trinary_children.third_child = $7;
            $$->line_number = @1.first_line;
        }
    ;

while_conditions:
        _WHILE_CONDITION _LEFT_BRACKET exp _RIGHT_BRACKET block {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            strcpy($$->op_name, "while");
            $$->exp_kind = NOT_EXP;
            $$->kind = WHILE_CONDITION_NODE;
            $$->binary_children.left_child = $3;
            $$->binary_children.right_child = $5;
            $$->line_number = @1.first_line;
        }
    ;

block:  
        _LEFT_BRACE code _RIGHT_BRACE {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = NOT_EXP;
            strcpy($$->op_name, "block");
            $$->kind = BLOCK_NODE;
            $$->unary_child.child = $2;
            $$->line_number = @2.first_line;
        }
    ;

sentence:
        declaration_series var_declaration {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = $1->exp_kind;
            strcpy($$->op_name, $1->op_name);
            $$->kind = DATA_DECLARE_NODE;
            $$->unary_child.child = $2;
            $$->line_number = @1.first_line;
        }
    |   _VARIABLE_NAME assign_series exp {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = $3->exp_kind;
            strcpy($$->complex_op.op1, $1);
            strcpy($$->complex_op.op2, $2->op_name);
            $$->complex_op.var_pos = 1;
            $$->kind = DATA_ASSIGN_NODE;
            $$->unary_child.child = $3;
            $$->line_number = @1.first_line;
        }
    ;

exp:    

    /********************************************************/

        _VARIABLE_NAME {         
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->kind = VARIABLE_NODE;
            $$->exp_kind = NOT_EXP;         // fix me
            strcpy($$->variable_name, $1);
            $$->line_number = @1.first_line;
        }
    |   _INTEGER_VALUE {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->kind = CONST_INT_NODE;
            $$->exp_kind = INTEGER_EXP;
            $$->int_value = $1;
            $$->line_number = @1.first_line;
        }
    |   _FLOAT_VALUE {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->kind = CONST_FLOAT_NODE;
            $$->exp_kind = FLOAT_EXP;
            $$->float_value = $1;
            $$->line_number = @1.first_line;
        }
    |   _CHAR_VALUE {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->kind = CONST_CHAR_NODE;
            $$->exp_kind = CHAR_EXP;
            $$->char_value = $1[1];
            $$->line_number = @1.first_line;
        }

    /********************************************************/

    |   _VARIABLE_NAME _SELF_PLUS_UNARY_OP %prec _RIGHT_SELF_PLUS_UNARY_OP {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            strcpy($$->complex_op.op1, $1);
            strcpy($$->complex_op.op2, "++");
            $$->complex_op.var_pos = 1;
            $$->exp_kind = INTEGER_EXP;     // fix me
            $$->kind = UNARY_OP_NODE;
            $$->line_number = @1.first_line;
        }

    |   _VARIABLE_NAME _RIGHT_SELF_MINUS_UNARY_OP %prec _RIGHT_SELF_MINUS_UNARY_OP {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            strcpy($$->complex_op.op1, $1);
            strcpy($$->complex_op.op2, "--");
            $$->complex_op.var_pos = 1;
            $$->exp_kind = INTEGER_EXP;     // fix me
            $$->kind = UNARY_OP_NODE;
            $$->line_number = @1.first_line;
        }

    |   _LEFT_SELF_PLUS_UNARY_OP _VARIABLE_NAME %prec _LEFT_SELF_PLUS_UNARY_OP {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            strcpy($$->complex_op.op1, "++");
            strcpy($$->complex_op.op2, $2);
            $$->complex_op.var_pos = 2;
            $$->exp_kind = INTEGER_EXP;     // fix me
            $$->kind = UNARY_OP_NODE;
            $$->line_number = @1.first_line;
        }

    |   _LEFT_SELF_MINUS_UNARY_OP _VARIABLE_NAME %prec _LEFT_SELF_MINUS_UNARY_OP {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            strcpy($$->complex_op.op1, "--");
            strcpy($$->complex_op.op2, $2);
            $$->complex_op.var_pos = 2;
            $$->exp_kind = INTEGER_EXP;     // fix me
            $$->kind = UNARY_OP_NODE;
            $$->line_number = @1.first_line;
        }

    /********************************************************/

    |   exp _PLUS_OP exp {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = get_exp_kind($1, $3);
            strcpy($$->op_name, "+");
            $$->kind = BINARY_OP_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $3;
            $$->line_number = @2.first_line;
        }
    |   exp _MINUS_OP exp {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = get_exp_kind($1, $3);
            strcpy($$->op_name, "-");
            $$->kind = BINARY_OP_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $3;
            $$->line_number = @2.first_line;
        }
    |   exp _MULTIPLE_OP exp {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = get_exp_kind($1, $3);
            strcpy($$->op_name, "*");
            $$->kind = BINARY_OP_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $3;
            $$->line_number = @2.first_line;
        }
    |   exp _DIVIDE_OP exp {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = get_exp_kind($1, $3);
            strcpy($$->op_name, "/");
            $$->kind = BINARY_OP_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $3;
            $$->line_number = @2.first_line;
        }
    |   exp _MODULE_OP exp {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = get_exp_kind($1, $3);
            strcpy($$->op_name, "%");
            $$->kind = BINARY_OP_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $3;
            $$->line_number = @2.first_line;
        }

    /**************************/
    
    |   exp _LARGER_OP exp {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = INTEGER_EXP;
            strcpy($$->op_name, ">");
            $$->kind = BINARY_OP_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $3;
            $$->line_number = @2.first_line;
        }
    |   exp _LESS_OP exp {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = INTEGER_EXP;
            strcpy($$->op_name, "<");
            $$->kind = BINARY_OP_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $3;
            $$->line_number = @2.first_line;
        }
    |   exp _LARGER_EQUAL_OP exp {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = INTEGER_EXP;
            strcpy($$->op_name, ">=");
            $$->kind = BINARY_OP_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $3;
            $$->line_number = @2.first_line;
        }
    |   exp _LESS_EQUAL_OP exp {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = INTEGER_EXP;
            strcpy($$->op_name, "<=");
            $$->kind = BINARY_OP_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $3;
            $$->line_number = @2.first_line;
        }
    |   exp _EQUAL_OP exp {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = INTEGER_EXP;
            strcpy($$->op_name, "==");
            $$->kind = BINARY_OP_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $3;
            $$->line_number = @2.first_line;
        }
    |   exp _NOT_EQUAL_OP exp {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = INTEGER_EXP;
            strcpy($$->op_name, "!=");
            $$->kind = BINARY_OP_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $3;
            $$->line_number = @2.first_line;
        }
        
    /**************************/

    |   exp _OR_OP exp {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = INTEGER_EXP;
            strcpy($$->op_name, "||");
            $$->kind = BINARY_OP_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $3;
            $$->line_number = @2.first_line;
        }
    |   exp _AND_OP exp {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = INTEGER_EXP;
            strcpy($$->op_name, "&&");
            $$->kind = BINARY_OP_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $3;
            $$->line_number = @2.first_line;
    }

    /**************************/

    |   _LEFT_BRACKET exp _COMMA_DIVIDED_CHAR exp _RIGHT_BRACKET {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = get_exp_kind($2, $4);
            strcpy($$->op_name, ",");
            $$->kind = BINARY_OP_NODE;
            $$->binary_children.left_child = $2;
            $$->binary_children.right_child = $4;
            $$->line_number = @2.first_line;
        }

    /********************************************************/
    
    |   _LEFT_BRACKET exp _RIGHT_BRACKET {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = $2->exp_kind;
            strcpy($$->op_name, "()");
            $$->kind = S_UNARY_OP_NODE;
            $$->unary_child.child = $2;
            $$->line_number = @2.first_line;
        }

    /********************************************************/

    |   _MINUS_OP exp %prec _UMINUS_OP {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = $2->exp_kind;
            strcpy($$->op_name, "-");
            $$->kind = S_UNARY_OP_NODE;
            $$->unary_child.child = $2;
            $$->line_number = @1.first_line;
        }

    |   _NOT_OP exp {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = $2->exp_kind;
            strcpy($$->op_name, "!");
            $$->kind = S_UNARY_OP_NODE;
            $$->unary_child.child = $2;
            $$->line_number = @1.first_line;
        }
    ;

assign_series:
        _ASSIGN_UNARY_OP {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            strcpy($$->op_name, "=");
            $$->line_number = @1.first_line;
        }

    |   _PLUS_ASSIGN_OP {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            strcpy($$->op_name, "+=");
            $$->line_number = @1.first_line;
        }

    |   _MINUS_ASSIGN_OP {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            strcpy($$->op_name, "-=");
            $$->line_number = @1.first_line;
        }

    |   _MULTI_ASSIGN_OP {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            strcpy($$->op_name, "*=");
            $$->line_number = @1.first_line;
        }

    |   _DIVIDE_ASSIGN_OP {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            strcpy($$->op_name, "/=");
            $$->line_number = @1.first_line;
        }

    |   _MODULE_ASSIGN_OP {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            strcpy($$->op_name, "%=");
            $$->line_number = @1.first_line;
        }
    ;

declaration_series:
        _INT_DECLARATION {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = INTEGER_EXP;
            strcpy($$->op_name, "int");
            $$->line_number = @1.first_line;
        }
    |   _CHAR_DECLARATION {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = CHAR_EXP;
            strcpy($$->op_name, "char");
            $$->line_number = @1.first_line;
        }
    |   _FLOAT_RECLARATION {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = FLOAT_EXP;
            strcpy($$->op_name, "float");
            $$->line_number = @1.first_line;
        }
    ;

var_declaration:
        _VARIABLE_NAME {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = NOT_EXP;        // fix me  
            strcpy($$->variable_name, $1);
            $$->kind = DATA_DECLARE_VAR_NODE;
            $$->line_number = @1.first_line;
        }
    |   _VARIABLE_NAME assign_series exp  {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = $3->exp_kind;
            strcpy($$->complex_op.op1, $1);
            strcpy($$->complex_op.op2, $2->op_name);
            $$->complex_op.var_pos = 1;
            $$->kind = DATA_DECLARE_UNARY_NODE;
            $$->unary_child.child = $3;
            $$->line_number = @1.first_line;
        }
    |   var_declaration _COMMA_DIVIDED_CHAR var_declaration  {
            $$ = (tree_node *) malloc (sizeof(tree_node));
            $$->exp_kind = $1->exp_kind;
            strcpy($$->op_name, ",");
            $$->kind = DATA_DECLARE_BINARY_NODE;
            $$->binary_children.left_child = $1;
            $$->binary_children.right_child = $3;
            $$->line_number = @1.first_line;
        }
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