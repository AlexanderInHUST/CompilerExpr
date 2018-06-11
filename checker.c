#include "checker.h"

const char ERROR_TYPE_TABLE[4][64] = {
    "Undefined symbol",
    "Type error",
    "Duplicate definition",
    "Divide zero error"
};

enum exp_kind get_exp_kind (struct tree_node * e1, struct tree_node * e2) {
    if (e1->exp_kind == FLOAT_EXP || e2->exp_kind == FLOAT_EXP) {
        return FLOAT_EXP;
    } else if (e1->exp_kind == CHAR_EXP && e2->exp_kind == CHAR_EXP) {
        return CHAR_EXP;
    } else if (e1->exp_kind == NOT_EXP && e2->exp_kind == NOT_EXP) {
        return NOT_EXP;
    } else {
        return INTEGER_EXP;
    }
}

void check_semantics(tree_node * node, check_results_array * results, symbol_table * table, int field_level) {
    switch(node->kind) {
        case BLOCK_NODE:
        case CODE_NODE:
        case WHILE_CONDITION_NODE:
        case IF_CONDITION_NODE:
        case IF_ELSE_CONDITION_NODE:

		case CONST_INT_NODE:
		case CONST_FLOAT_NODE:
		case CONST_CHAR_NODE: 
        case BLANK_NODE: break;

        case UNARY_OP_NODE: {
            if (node->complex_op.var_pos == 1) {
                symbol_node * left_variable = get_node(table, node->complex_op.op1);
                if (left_variable == NULL) {
                    insert_check_results_array(results, create_check_result(UNDEF_SYMBOL, node->line_number, node->complex_op.op1));
                }
            } else {
                symbol_node * right_variable = get_node(table, node->complex_op.op2);
                if (right_variable == NULL) {
                    insert_check_results_array(results, create_check_result(UNDEF_SYMBOL, node->line_number, node->complex_op.op2));
                }
            }
            break;
        }

        case VARIABLE_NODE: {
            symbol_node * left_variable = get_node(table, node->variable_name);
            if (left_variable == NULL) {
                insert_check_results_array(results, create_check_result(UNDEF_SYMBOL, node->line_number, node->variable_name));
            } else {
                node->exp_kind = left_variable->exp_kind;
            }
            break;
        }

		case S_UNARY_OP_NODE: {
            check_semantics(node->unary_child.child, results, table, field_level);
            node->exp_kind = node->unary_child.child->exp_kind;
            break;
        }

		case BINARY_OP_NODE: {
            check_semantics(node->binary_children.left_child, results, table, field_level);
            check_semantics(node->binary_children.right_child, results, table, field_level);
            node->exp_kind = get_exp_kind(node->binary_children.left_child, node->binary_children.right_child);
            break;
        }

        case DATA_ASSIGN_NODE: {
            symbol_node * left_variable = get_node(table, node->complex_op.op1);
            check_semantics(node->unary_child.child, results, table, field_level);
            node->exp_kind = node->unary_child.child->exp_kind;
            if (left_variable == NULL) {
                insert_check_results_array(results, create_check_result(UNDEF_SYMBOL, node->line_number, node->complex_op.op1));
            } else if (left_variable->exp_kind != node->unary_child.child->exp_kind 
                            && node->unary_child.child->exp_kind != NOT_EXP) {
                insert_check_results_array(results, create_check_result(TYPE_ERROR, node->line_number, node->complex_op.op1));
            }
            break;
        }

        case DATA_DECLARE_NODE: {
            check_semantics(node->unary_child.child, results, table, field_level);
            if (node->exp_kind != node->unary_child.child->exp_kind
                    && node->unary_child.child->exp_kind != NOT_EXP) {
                insert_check_results_array(results, create_check_result(TYPE_ERROR, node->line_number, node->op_name));
            }
            break;
        }

        case DATA_DECLARE_VAR_NODE: {
            symbol_node * left_variable = get_node(table, node->variable_name);
            if (left_variable != NULL && left_variable->field_level == field_level) {
                insert_check_results_array(results, create_check_result(DUPLICATE_DEF, node->line_number, node->variable_name));
            }
            node->exp_kind = NOT_EXP;
            break;
        }

        case DATA_DECLARE_UNARY_NODE: {
            symbol_node * left_variable = get_node(table, node->complex_op.op1);
            if (left_variable != NULL && left_variable->field_level == field_level) {
                insert_check_results_array(results, create_check_result(DUPLICATE_DEF, node->line_number, node->complex_op.op1));
            }
            check_semantics(node->unary_child.child, results, table, field_level);
            node->exp_kind = node->unary_child.child->exp_kind;
            break;
        }

        case DATA_DECLARE_BINARY_NODE: {
            check_semantics(node->binary_children.left_child, results, table, field_level);
            check_semantics(node->binary_children.right_child, results, table, field_level);
            node->exp_kind = get_exp_kind(node->binary_children.left_child, node->binary_children.right_child);
            break;
        }
    }
}

check_result * create_check_result(int type, int line_num, char * var_name) {
    check_result * new_result = (check_result *) malloc (sizeof(check_result));
    new_result->error_type = type;
    new_result->line_num = line_num;
    strcpy(new_result->var_name, var_name);
    return new_result;
}

check_results_array * create_check_results_array() {
    check_results_array * array = (check_results_array *) malloc (sizeof(check_results_array));
    array->size = DEFAULT_RESULTS_SIZE;
    array->length = 0;
    array->results = (check_result **) malloc(sizeof(check_result *) * array->size);
    return array;
}

void insert_check_results_array(check_results_array * array, check_result * result) {
    resize_check_results_array(array, array->length + 1);
    array->results[array->length] = result;
    array->length++;
}

void resize_check_results_array(check_results_array * array, int len) {
    if (array->size == len) {
        array->size *= 2;
        array->results = (check_result **) realloc(array->results, sizeof(check_result *) * array->size);
    }
}

void free_check_results_array(check_results_array ** array) {
    check_results_array * aim = * array;
    for (int i = 0; i < aim->length; i++) {
        free(aim->results[i]);
    }
    free(aim->results);
    free(aim);
}

void print_check_results_array(check_results_array * array) {
    printf("There exist %d semantics errors!\n\n", array->length);
    for (int i = 0; i < array->length; i++) {
        check_result * current_result = array->results[i];
        printf("The %d error:\n", i + 1);
        printf("    Error %s happens at line %d with keyword \"%s\"\n\n",
            ERROR_TYPE_TABLE[current_result->error_type], current_result->line_num, current_result->var_name);
    }
}