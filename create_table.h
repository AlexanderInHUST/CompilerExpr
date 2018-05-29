#ifndef CREATE_TABLE_H_GUARD
#define CREATE_TABLE_H_GUARD

#include "symbol_table.h"
#include "node.h"

void create_tables(symbol_table * root, int field_level, tree_node * T, int exp_kind);

#endif