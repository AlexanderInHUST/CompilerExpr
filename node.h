#ifndef NODE_H_GUARD
#define NODE_H_GUARD

#include "TAC.h"

enum node_kind {
    CODE_NODE,
    BLOCK_NODE,
    BLANK_NODE,

    VARIABLE_NODE,
    CONST_INT_NODE,
    CONST_CHAR_NODE,
    CONST_FLOAT_NODE,

    S_UNARY_OP_NODE,
    UNARY_OP_NODE,
    BINARY_OP_NODE,

    IF_CONDITION_NODE,
    IF_ELSE_CONDITION_NODE,
    WHILE_CONDITION_NODE,

    DATA_ASSIGN_NODE,

    DATA_DECLARE_NODE,
    DATA_DECLARE_VAR_NODE,
    DATA_DECLARE_UNARY_NODE,
    DATA_DECLARE_BINARY_NODE
};

enum exp_kind {
    INTEGER_EXP,
    CHAR_EXP,
    FLOAT_EXP,
    NOT_EXP
};

typedef struct tree_node {
	enum node_kind kind;
    enum exp_kind exp_kind;
    int line_number;
	union {
		char variable_name[32];        
        int int_value;
        char char_value;
        float float_value;
        char op_name[32];     
        struct {
            char op1[32];
            char op2[32];
            int var_pos;
        } complex_op;
	};
    union {
        struct {
            struct tree_node * first_child;
            struct tree_node * second_child;
            struct tree_node * third_child;
        } trinary_children;
        struct {
            struct tree_node * left_child;
            struct tree_node * right_child;
        } binary_children;
        struct {
            struct tree_node * child;
        } unary_child;
    };

    TAC_list * codes;
    TAC_list * side_effect;
    char place[32];
    char label[32];
    char true_label[32];
    char false_label[32];
} tree_node;

void display(tree_node * T, int tab_num);

#endif