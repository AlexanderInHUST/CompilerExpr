#ifndef TAC_H_GUARD
#define TAC_H_GUARD

#define NULL_TAC_POS    0
#define VAR_TAC_POS     1
#define INT_TAC_POS     2
#define FLOAT_TAC_POS   3
#define CHAR_TAC_POS    4
#define LABEL_TAC_POS   5

#define DEFAULT_LIST_SIZE   128

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct TAC{
    char op[32];
    char first_value[32];
    char second_value[32];
    char third_value[32];
    struct TAC * next;
    struct TAC * true_exit, * false_exit;
} TAC;

typedef struct TAC_list {
    int size, length;
    TAC ** list;
} TAC_list;

TAC * create_TAC(char * op, char * first_value, char * second_value, char * third_value);
TAC_list * create_TAC_list();

void free_TAC_list(TAC_list ** list);
void insert_TAC(TAC_list * list, TAC * new_TAC);
void resize_TAC_list(TAC_list * list, int length);
TAC * get_TAC(TAC_list * list, int label);
void append_TAC_list(TAC_list * dst, TAC_list * src);
void print_TAC_list(TAC_list * list);

#endif