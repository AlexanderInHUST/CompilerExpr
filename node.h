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

    DATA_DECLARE_NODE,
    DATA_ASSIGN_BINARY_NODE,
    DATA_ASSIGN_UNARY_NODE
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
	union {
		char variable_name[32];        
        int int_value;
        char char_value;
        float float_value;
        char op_name[32];
        char condition_name[32];
        char data_declare_name[32];
        char bracket;      
        char divided_char;           
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
} tree_node;

void display(tree_node * T, int tab_num);