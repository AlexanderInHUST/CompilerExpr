#include "create_table.h"

void create_tables(symbol_table * root, int field_level, tree_node * T, int exp_kind, check_results_array * results) {
    switch (T->kind) {
		case VARIABLE_NODE:
		case CONST_INT_NODE:
		case CONST_FLOAT_NODE:
		case CONST_CHAR_NODE: 
        case BLANK_NODE: 
		case UNARY_OP_NODE: 
		case S_UNARY_OP_NODE:
		case BINARY_OP_NODE: break;

        case DATA_ASSIGN_NODE: {
            check_semantics(T, results, root, field_level);
            break;
        }

        case DATA_DECLARE_NODE: {
            check_semantics(T, results, root, field_level);
            create_tables(root, field_level, T->unary_child.child, T->exp_kind, results);
            break;
        }

        case DATA_DECLARE_VAR_NODE: {
            insert_edit_node(root, T->variable_name, exp_kind, field_level);
            break;
        }

		case DATA_DECLARE_UNARY_NODE: {
            insert_edit_node(root, T->complex_op.op1, exp_kind, field_level);
            break;
        }

		case DATA_DECLARE_BINARY_NODE: {
            create_tables(root, field_level, T->binary_children.left_child, exp_kind, results);
            create_tables(root, field_level, T->binary_children.right_child, exp_kind, results);
            break;
        }

		case BLOCK_NODE: {
            symbol_table * new_table = copy_create_symbol_table(root);
            add_next_symbol_table(root, new_table);
            create_tables(new_table, field_level + 1, T->unary_child.child, -1, results);
			break;
		}

		case CODE_NODE: {
            create_tables(root, field_level, T->binary_children.left_child, -1, results);
            create_tables(root, field_level, T->binary_children.right_child, -1, results);
			break;
		}

		case WHILE_CONDITION_NODE: {
            check_semantics(T->binary_children.left_child, results, root, field_level);
            create_tables(root, field_level, T->binary_children.right_child, -1, results);
			break;
		}
		case IF_CONDITION_NODE: {
            check_semantics(T->binary_children.left_child, results, root, field_level);
            create_tables(root, field_level, T->binary_children.right_child, -1, results);
			break;
		}
		case IF_ELSE_CONDITION_NODE: {
            check_semantics(T->trinary_children.first_child, results, root, field_level);
            create_tables(root, field_level, T->trinary_children.second_child, -1, results);
            create_tables(root, field_level, T->trinary_children.third_child, -1, results);
			break;
		}
	}
}