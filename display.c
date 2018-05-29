#include "stdio.h"
#include "node.h"

void display(tree_node * T, int tab_num) {
	switch (T->kind) {
		case VARIABLE_NODE: {
			printf("---[ %s ]\n", T->variable_name);
			break;
		}
		case CONST_INT_NODE: {
			printf("---[ %d ]\n", T->int_value);
			break;
		}
		case CONST_FLOAT_NODE: {
			printf("---[ %f ]\n", T->float_value);
			break;
		}
		case CONST_CHAR_NODE: {
			printf("---[ %c ]\n", T->char_value);
			break;
		}
		case UNARY_OP_NODE: {
			printf("---[ %s%s ]\n", T->complex_op.op1, T->complex_op.op2);
			break;
		}
		case S_UNARY_OP_NODE: {
			printf("---[ %s ]", T->op_name);
			display(T->unary_child.child, tab_num + 1);
			break;
		}
		case BINARY_OP_NODE: {
			printf("---[ %s ]", T->op_name);
			display(T->binary_children.left_child, tab_num + 1);
			for (int i = 0; i < tab_num + 1; i++) {
				printf("\t");
			}
			printf("|");
			display(T->binary_children.right_child, tab_num + 1);
			break;
		}

		case DATA_ASSIGN_NODE: {
			for (int i = 0; i < tab_num; i++) {
				printf("\t");
			}
			printf("|---[ %s%s ]", T->complex_op.op1, T->complex_op.op2);
			display(T->unary_child.child, tab_num + 1);
			break;
		}

		case DATA_DECLARE_NODE: {
			for (int i = 0; i < tab_num; i++) {
				printf("\t");
			}
			printf("|---[ %s ]", T->op_name);
			display(T->unary_child.child, tab_num + 1);
			break;
		}
		case DATA_DECLARE_VAR_NODE: {
			printf("---[ %s ]\n", T->variable_name);
			break;
		}
		case DATA_DECLARE_UNARY_NODE: {
			printf("---[ %s%s ]", T->complex_op.op1, T->complex_op.op2);
			display(T->unary_child.child, tab_num + 1);
			break;
		}		
		case DATA_DECLARE_BINARY_NODE: {
			printf("---[ %s ]", T->op_name);
			display(T->binary_children.left_child, tab_num + 1);
			for (int i = 0; i < tab_num + 1; i++) {
				printf("\t");
			}
			printf("|");
			display(T->binary_children.right_child, tab_num + 1);
			break;
		}

		case BLOCK_NODE: {
			display(T->unary_child.child, tab_num);
			break;
		}
		case CODE_NODE: {
			display(T->binary_children.left_child, tab_num);
			display(T->binary_children.right_child, tab_num);
			break;
		}
		case BLANK_NODE: {
			break;
		}

		case WHILE_CONDITION_NODE: {
			for (int i = 0; i < tab_num; i++) {
				printf("\t");
			}
			printf("|---[ %s ]", T->op_name);
			display(T->binary_children.left_child, tab_num + 1);
			for (int i = 0; i < tab_num + 1; i++) {
				printf("\t");
			}
			printf("Then:\n");
			display(T->binary_children.right_child, tab_num + 1);
			break;
		}
		case IF_CONDITION_NODE: {
			for (int i = 0; i < tab_num; i++) {
				printf("\t");
			}
			printf("|---[ %s ]", T->op_name);
			display(T->binary_children.left_child, tab_num + 1);
			for (int i = 0; i < tab_num + 1; i++) {
				printf("\t");
			}
			printf("Then:\n");
			display(T->binary_children.right_child, tab_num + 1);
			break;
		}
		case IF_ELSE_CONDITION_NODE: {
			for (int i = 0; i < tab_num; i++) {
				printf("\t");
			}
			printf("|---[ %s ]", T->op_name);
			display(T->trinary_children.first_child, tab_num + 1);
			for (int i = 0; i < tab_num + 1; i++) {
				printf("\t");
			}
			printf("Then:\n");
			display(T->trinary_children.second_child, tab_num + 1);
			for (int i = 0; i < tab_num + 1; i++) {
				printf("\t");
			}
			printf("Else:\n");
			display(T->trinary_children.third_child, tab_num + 1);
			break;
		}
	}
}

