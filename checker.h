#ifndef CHECKER_H_GUARD
#define CHECKER_H_GUARD

#include "symbol_table.h"
#include "node.h"

#define UNDEF_SYMBOL            0
#define TYPE_ERROR              1
#define DUPLICATE_DEF           2
#define DIV_ZERO                3

#define DEFAULT_RESULTS_SIZE    4

// 1. undef symbol
// 2. type error
// 3. duplicate definition

// 4. div 0 error
// 5. 

typedef struct check_result {
    int error_type;
    int line_num;
    char var_name[32];
} check_result;

typedef struct check_results_array {
    int size, length;
    check_result ** results;
} check_results_array;

enum exp_kind get_exp_kind (struct tree_node * e1, struct tree_node * e2);

check_result * create_check_result(int type, int line_num, char * var_name);

check_results_array * create_check_results_array();
void insert_check_results_array(check_results_array * array, check_result * result);
void resize_check_results_array(check_results_array * array, int len);
void free_check_results_array(check_results_array ** array);
void print_check_results_array(check_results_array * array);

void check_semantics(tree_node * node, check_results_array * results, symbol_table * table, int field_level);

#endif 