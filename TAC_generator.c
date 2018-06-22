#include "TAC_generator.h"

int label_number = 0;

void make_up_TACs(tree_node * T, symbol_table * table, count_stack * stack) {
    
    switch (T->kind) {
		case VARIABLE_NODE: {
            T->codes = NULL;
            T->side_effect = NULL;
            strcpy(T->place, T->variable_name);
            break;
        }

		case CONST_INT_NODE: {
            T->codes = NULL;
            T->side_effect = NULL;
            sprintf(T->place, "%d", T->int_value);
            break;
        }

		case CONST_FLOAT_NODE: {
            T->codes = NULL;
            T->side_effect = NULL;
            sprintf(T->place, "%f", T->float_value);
            break;
        }

		case CONST_CHAR_NODE: {
            T->codes = NULL;
            T->side_effect = NULL;
            sprintf(T->place, "\'%c\'", T->char_value);
            break;
        }

        case BLANK_NODE: {
            break;
        }

		case UNARY_OP_NODE: {
            T->codes = create_TAC_list();
            T->side_effect = create_TAC_list();
            char tmp_op[32];
            strcpy(T->place, create_new_tmp(INTEGER_EXP, table));
            if (T->complex_op.var_pos == 1) { // a++
                sprintf(tmp_op, "%c", T->complex_op.op2[0]);
                TAC * tac = create_TAC(NORMAL_TAC, tmp_op, T->complex_op.op1, "0", T->place);
                insert_TAC(T->codes, tac);
                TAC * effect = create_TAC(NORMAL_TAC, tmp_op, T->complex_op.op1, "1", T->complex_op.op1);
                insert_TAC(T->side_effect, effect);
            } else { // ++a
                sprintf(tmp_op, "%c", T->complex_op.op1[0]);
                TAC * tac = create_TAC(NORMAL_TAC, tmp_op, T->complex_op.op2, "1", T->place);
                insert_TAC(T->codes, tac);
                TAC * effect = create_TAC(NORMAL_TAC, tmp_op, T->complex_op.op2, "1", T->complex_op.op2);
                insert_TAC(T->side_effect, effect);
            }
            break;
        }

		case S_UNARY_OP_NODE: {
            T->codes = create_TAC_list();
            T->side_effect = create_TAC_list();
            make_up_TACs(T->unary_child.child, table, stack);
            append_TAC_list(T->codes, T->unary_child.child->codes);
            append_TAC_list(T->side_effect, T->unary_child.child->side_effect);
            if (strcmp(T->op_name, "-") == 0) {
                strcpy(T->place, create_new_tmp(T->exp_kind, table));
                TAC * tac = create_TAC(NORMAL_TAC, "0", "0", T->unary_child.child->place, T->place);
                insert_TAC(T->codes, tac);
            } else {
                strcpy(T->place, T->unary_child.child->place);
            }
            break;
        }

        case DATA_DECLARE_BINARY_NODE:
		case BINARY_OP_NODE: {
            T->codes = create_TAC_list();
            T->side_effect = create_TAC_list();
            make_up_TACs(T->binary_children.left_child, table, stack);
            make_up_TACs(T->binary_children.right_child, table, stack);
            append_TAC_list(T->codes, T->binary_children.left_child->codes);
            append_TAC_list(T->codes, T->binary_children.right_child->codes);
            append_TAC_list(T->side_effect, T->binary_children.left_child->side_effect);
            append_TAC_list(T->side_effect, T->binary_children.right_child->side_effect);
            if (T->kind == BINARY_OP_NODE) {
                strcpy(T->place, create_new_tmp(T->exp_kind, table));
                TAC * tac = create_TAC(NORMAL_TAC, T->op_name, T->binary_children.left_child->place, T->binary_children.right_child->place, T->place);
                insert_TAC(T->codes, tac);
            }
            break;
        };

        case DATA_DECLARE_UNARY_NODE: 
        case DATA_ASSIGN_NODE: {
            T->codes = create_TAC_list();
            T->side_effect = create_TAC_list();
            char tmp_op[32];
            make_up_TACs(T->unary_child.child, table, stack);
            append_TAC_list(T->codes, T->unary_child.child->codes);
            append_TAC_list(T->side_effect, T->unary_child.child->side_effect);
            if (strcmp(T->complex_op.op2, "=") == 0) {
                TAC * tac = create_TAC(NORMAL_TAC, T->complex_op.op2, "", T->unary_child.child->place, T->complex_op.op1);
                insert_TAC(T->codes, tac);
            } else {
                sprintf(tmp_op, "%c", T->complex_op.op2[0]);
                TAC * tac = create_TAC(NORMAL_TAC, tmp_op, T->complex_op.op1, T->unary_child.child->place, T->complex_op.op1);
                insert_TAC(T->codes, tac);
            }
            if (T->kind == DATA_ASSIGN_NODE) {
                append_TAC_list(T->codes, T->side_effect);
            }
            break;
        }

        case DATA_DECLARE_NODE: {
            T->codes = create_TAC_list();
            T->side_effect = create_TAC_list();
            make_up_TACs(T->unary_child.child, table, stack);
            append_TAC_list(T->codes, T->unary_child.child->codes);
            append_TAC_list(T->side_effect, T->unary_child.child->side_effect);
            append_TAC_list(T->codes, T->side_effect);
            break;
        }

        case DATA_DECLARE_VAR_NODE: {
            T->codes = NULL;
            T->side_effect = NULL;
            strcpy(T->place, T->variable_name);
            break;
        }

		case BLOCK_NODE: {
            T->codes = create_TAC_list();
            T->side_effect = NULL;
            symbol_table * next_table = table->next_tables[get_count_stack(stack)];
            push_count_stack(stack);
            make_up_TACs(T->unary_child.child, next_table, stack); // fix me : cannot change table
            TAC * start_tac = create_TAC(LABEL_TAC, "{", "", "", ""); // todo : for changing table
            insert_TAC(T->codes, start_tac);
            append_TAC_list(T->codes, T->unary_child.child->codes);
            append_TAC_list(T->side_effect, T->unary_child.child->side_effect);
            TAC * end_tac = create_TAC(LABEL_TAC, "}", "", "", ""); // todo : for changing table
            insert_TAC(T->codes, end_tac);
            pull_count_stack(stack);
            next_table->tmp_number = 1;
            move_count_stack(stack);
			break;
		}

		case CODE_NODE: {
            T->codes = create_TAC_list();
            T->side_effect = NULL;
            make_up_TACs(T->binary_children.left_child, table, stack);
            make_up_TACs(T->binary_children.right_child, table, stack);
            append_TAC_list(T->codes, T->binary_children.left_child->codes);
            append_TAC_list(T->codes, T->binary_children.right_child->codes);
			break;
		}

		case WHILE_CONDITION_NODE: {
            T->codes = create_TAC_list();
            T->side_effect = create_TAC_list();
            make_up_TACs(T->binary_children.left_child, table, stack);
            make_up_TACs(T->binary_children.right_child, table, stack);
            strcpy(T->false_label, create_new_label());            
            strcpy(T->label, create_new_label());
            TAC * label_tac = create_TAC(LABEL_TAC, T->label, "", "", "");
            insert_TAC(T->codes, label_tac);
            append_TAC_list(T->codes, T->binary_children.left_child->codes);
            append_TAC_list(T->codes, T->binary_children.left_child->side_effect);
            TAC * jmp_tac = create_TAC(NORMAL_TAC, "jne", "0", T->binary_children.left_child->place, T->false_label);
            insert_TAC(T->codes, jmp_tac);
            append_TAC_list(T->codes, T->binary_children.right_child->codes);
            TAC * back_tac = create_TAC(NORMAL_TAC, "jmp", "", "", T->label);
            insert_TAC(T->codes, back_tac);
            TAC * dst_tac = create_TAC(LABEL_TAC, T->false_label, "", "", "");
            insert_TAC(T->codes, dst_tac);
            break;
		}

		case IF_CONDITION_NODE: {
            T->codes = create_TAC_list();
            T->side_effect = create_TAC_list();
            make_up_TACs(T->binary_children.left_child, table, stack);
            make_up_TACs(T->binary_children.right_child, table, stack);
            strcpy(T->false_label, create_new_label());            
            append_TAC_list(T->codes, T->binary_children.left_child->codes);
            append_TAC_list(T->codes, T->binary_children.left_child->side_effect);
            TAC * jmp_tac = create_TAC(NORMAL_TAC, "jne", "0", T->binary_children.left_child->place, T->false_label);
            insert_TAC(T->codes, jmp_tac);
            append_TAC_list(T->codes, T->binary_children.right_child->codes);
            TAC * dst_tac = create_TAC(LABEL_TAC, T->false_label, "", "", "");
            insert_TAC(T->codes, dst_tac);
			break;
		}

		case IF_ELSE_CONDITION_NODE: {
            T->codes = create_TAC_list();
            T->side_effect = create_TAC_list();
            make_up_TACs(T->trinary_children.first_child, table, stack);
            make_up_TACs(T->trinary_children.second_child, table, stack);
            make_up_TACs(T->trinary_children.third_child, table, stack);
            strcpy(T->label, create_new_label());
            strcpy(T->false_label, create_new_label());          
            append_TAC_list(T->codes, T->trinary_children.first_child->codes); 
            append_TAC_list(T->codes, T->trinary_children.first_child->side_effect);           
            TAC * jmp_tac = create_TAC(NORMAL_TAC, "jne", "0", T->trinary_children.first_child->place, T->false_label);
            insert_TAC(T->codes, jmp_tac);
            append_TAC_list(T->codes, T->trinary_children.second_child->codes);
            TAC * exit_tac = create_TAC(NORMAL_TAC, "jmp", "", "", T->label);
            insert_TAC(T->codes, exit_tac);
            TAC * false_lab_tac = create_TAC(LABEL_TAC, T->false_label, "", "", "");
            insert_TAC(T->codes, false_lab_tac);
            append_TAC_list(T->codes, T->trinary_children.third_child->codes);
            TAC * dst_tac = create_TAC(LABEL_TAC, T->label, "", "", "");
            insert_TAC(T->codes, dst_tac);
			break;
		}
	}
}

char * create_new_tmp(int type, symbol_table * table) {
    char tmp_int[32];
    char * tmp_name = (char *) malloc (sizeof(char) * 32); // todo : mem link
    sprintf(tmp_int, "%d", table->tmp_number);
    strcpy(tmp_name, TMP_PREFIX);
    strcat(tmp_name, tmp_int);
    insert_edit_node(table, tmp_name, type, -1);
    table->tmp_number++;
    return tmp_name;
}

char * create_new_label() {
    char * label_name = (char *) malloc (sizeof(char) * 32); // todo : mem link
    char label_int[32];
    sprintf(label_int, "%d", label_number);
    strcpy(label_name, LAB_PREFIX);
    strcat(label_name, label_int);
    label_number++;
    return label_name;
}

count_stack * create_count_stack() {
    count_stack * stack = (count_stack *) malloc (sizeof(count_stack));
    for (int i = 0; i < 128; i++) {
        stack->table_pos[i] = 0;
    } 
    stack->tail = 0;
    return stack;
}

int get_count_stack(count_stack * stack) {
    return stack->table_pos[stack->tail];
}

void push_count_stack(count_stack * stack) {
    stack->tail++;
}

void pull_count_stack(count_stack * stack) {
    stack->table_pos[stack->tail] = 0;
    stack->tail--;
}

void move_count_stack(count_stack * stack) {
    stack->table_pos[stack->tail]++;
}