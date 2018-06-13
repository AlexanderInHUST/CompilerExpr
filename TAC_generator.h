#ifndef TAC_GENERATOR_H_GUARD
#define TAC_GENERATOR_H_GUARD

#include "TAC.h"
#include "node.h"
#include "symbol_table.h"

#define TMP_PREFIX "#_tmp_"
#define LAB_PREFIX "@_label_"

typedef struct count_stack {
    int table_pos[128];
    int tail;
} count_stack;

count_stack * create_count_stack();
int get_count_stack(count_stack * stack);
void push_count_stack(count_stack * stack);
void pull_count_stack(count_stack * stack);
void move_count_stack(count_stack * stack);

void make_up_TACs(tree_node * node, symbol_table * table, count_stack * stack);
char * create_new_tmp(int type, symbol_table * table);
char * create_new_label();

#endif