enum node_kind {
    VARIABLE_NODE,
    CONST_INT_NODE,
    CONST_CHAR_NODE,
    CONST_FLOAT_NODE,
    UNARY_OP_NODE,
    BINARY_OP_NODE,
    CONDITION_NODE,
    DATA_DECLARE_NODE,
    LEFT_BRACKET_NODE,
    RIGHT_BRACKET_NODE,
    LEFT_BRACE_NODE,
    RIGHT_BRACE_NODE,
    DIVIDED_CHAR,
    COMMENT_LEFT_NODE,
    COMMENT_RIGHT_NODE
};

typedef struct tree_node {
	enum node_kind kind;
	union {
		char variable_name[32];        
        int int_value;
        char char_value;
        float float_value;
        char op_name;
        char condition_name[32];
        char data_declare_name[32];
        char bracket;      
        char divided_char;           
	};
    union {
        struct {
            struct tree_node * left_child;
            struct tree_node * right_child;
        } binary_children;
        struct {
            struct tree_node * child;
        } unary_child;
    };
} tree_node;


