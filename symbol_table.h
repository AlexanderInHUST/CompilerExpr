#ifndef SYMBOL_TABLE_H_GUARD
#define SYMBOL_TABLE_H_GUARD

#include "node.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define EXISTS 1
#define NOT_EX -1

#define DEFAULT_SIZE 4
#define DEFAULT_NEXT_SIZE 4

typedef struct symbol_node {
    char symbol_name[32];
    int exp_kind;
    int field_level;
} symbol_node;

typedef struct symbol_table {
    struct symbol_node * nodes;
    int length;
    int size;
    struct symbol_table ** next_tables;
    int next_len;
    int next_size;
} symbol_table;

symbol_table * create_symbol_table();
symbol_table * copy_create_symbol_table(symbol_table *);

void free_symbol_table(symbol_table * table, int b);
void add_next_symbol_table(symbol_table * src, symbol_table ** next);

int find_node(symbol_table * table, char * node_name);
void insert_edit_node(symbol_table * table, char * node_name, int exp_kind, int field_level);
void resize_table(symbol_table * table, int len);
void resize_next_tables(symbol_table * table, int len);
int get_node_kind(symbol_table * table, char * node_name);
void print_table(symbol_table * table, char * header, int pos);

#endif