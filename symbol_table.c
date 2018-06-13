#include "symbol_table.h"

const char TYPE_TABLE[3][32] = {
    "Integer",
    "Character",
    "Float"
};

symbol_table * create_symbol_table() {
    symbol_table * table = (symbol_table *) malloc (sizeof(symbol_table));
    table->size = DEFAULT_SIZE;
    table->length = 0;
    table->nodes = (symbol_node *) malloc (sizeof(symbol_node) * table->size);
    table->next_size = DEFAULT_NEXT_SIZE;
    table->next_len = 0;
    table->next_tables = (symbol_table **) malloc (sizeof(symbol_table *) * table->next_size);
    table->tmp_number = 0;
    return table;
}

symbol_table * copy_create_symbol_table(symbol_table * table) {
    symbol_table * photo = (symbol_table *) malloc (sizeof(symbol_table));
    photo->size = table->size;
    photo->length = table->length;
    photo->nodes = (symbol_node *) malloc (sizeof(symbol_node) * photo->size);
    memcpy(photo->nodes, table->nodes, sizeof(symbol_node) * table->length);
    photo->next_size = DEFAULT_NEXT_SIZE;
    photo->next_len = 0;
    photo->next_tables = (symbol_table **) malloc (sizeof(symbol_table *) * photo->next_size);
    photo->tmp_number = 0;
    return photo;
}

void free_symbol_table(symbol_table * table, int b) {
    for (int i = 0; i < table->next_len; i++) {
        free_symbol_table(table->next_tables[i], b + 1);
    }
    free(table->nodes);
    free(table->next_tables);
};

void add_next_symbol_table(symbol_table * src, symbol_table * next) {
    resize_next_tables(src, src->next_len + 1);
    src->next_tables[src->next_len] = next;
    src->next_len++;
}

int find_node(symbol_table * table, char * node_name) {
    for (int i = 0; i < table->length; i++) {
        int result = (strcmp(table->nodes[i].symbol_name, node_name) == 0)
            ? EXISTS : NOT_EX;
        if (result == EXISTS) {
            return i;
        }
    }
    return NOT_EX;
}

symbol_node * get_node(symbol_table * table, char * node_name) {
    int pos = find_node(table, node_name);
    return (pos == NOT_EX) ? NULL : &table->nodes[pos];
}

void insert_edit_node(symbol_table * table, char * node_name, int exp_kind, int field_level) {
    int pos = find_node(table, node_name);
    if (pos == NOT_EX) {
        resize_table(table, table->length + 1);
        strcpy(table->nodes[table->length].symbol_name, node_name);
        table->nodes[table->length].exp_kind = exp_kind;
        table->nodes[table->length].field_level = field_level;
        table->length++;
    } else {
        table->nodes[pos].exp_kind = exp_kind;
        table->nodes[pos].field_level = field_level;
    }
}

void resize_table(symbol_table * table, int len) {
    if (table->size == len) {
        table->size *= 2;
        table->nodes = (symbol_node *) realloc(table->nodes, sizeof(symbol_node) * table->size);
    }
}

void resize_next_tables(symbol_table * table, int len) {
    if (table->next_size == len) {
        table->next_size *= 2;
        table->next_tables = (symbol_table **) realloc(table->next_tables, sizeof(symbol_table *) * table->next_size);
    }
}

void print_table(symbol_table * table, char * header, int pos) {
    printf("\nSymbol table of %s%d\n", header, pos);
    printf("|------------|--|------------|--|------------|\n");
    printf("|symbol_name |  |    type    |  |field_level |\n");
    printf("|------------|--|------------|--|------------|\n");
    for (int i = 0; i < table->length; i++) {
        symbol_node * node = &table->nodes[i];
        printf("|%-12s|  |%-12s|  |%-12d|\n", node->symbol_name, TYPE_TABLE[node->exp_kind], node->field_level);
    }
    printf("|------------|--|------------|--|------------|\n");
    char new_header[63]; 
    char number[10];
    sprintf(number, "%d", pos);
    strcpy(new_header, header);
    strcat(new_header, number);
    strcat(new_header, "-");
    for (int i = 0; i < table->next_len; i++) {
        print_table(table->next_tables[i], new_header, i + 1);
    }
}