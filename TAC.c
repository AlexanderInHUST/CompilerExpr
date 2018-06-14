
#include "TAC.h"

TAC * create_TAC(int type, char * op, char * first_value, char * second_value, char * third_value) {
    TAC * new_TAC = (TAC *) malloc (sizeof(TAC));
    new_TAC->type = type;
    strcpy(new_TAC->op, op);
    strcpy(new_TAC->first_value, first_value);
    strcpy(new_TAC->second_value, second_value);
    strcpy(new_TAC->third_value, third_value);
    return new_TAC;
}

TAC_list * create_TAC_list() {
    TAC_list * new_list = (TAC_list *) malloc (sizeof(TAC_list));
    new_list->size = 128;
    new_list->length = 0;
    new_list->list = (TAC **) malloc (sizeof(TAC *) * new_list->size);
    return new_list;
}

void free_TAC_list(TAC_list ** list) {
    TAC_list * aim = * list;
    for (int i = 0; i < aim->length; i++) {
        free (aim->list[i]);
    }
    free(aim->list);
    free(aim);
}

void insert_TAC(TAC_list * list, TAC * new_TAC) {
    resize_TAC_list(list, list->length + 1);
    list->list[list->length] = new_TAC;
    list->length++;
}

void resize_TAC_list(TAC_list * list, int length) {
    if (list->size == length) {
        list->size *= 2;
        list->list = (TAC **) realloc (list->list, sizeof(TAC *) * list->size);   
    }
}

void append_TAC_list(TAC_list * dst, TAC_list * src) {
    if (src == NULL) {
        return;
    }
    for (int i = 0; i < src->length; i++) {
        insert_TAC(dst, src->list[i]);
    }
}

void print_TAC_list(TAC_list * list) {
    printf("The TAC codes are below:\n");
    for (int i = 0; i < list->length; i++) {
        TAC * tac = list->list[i];
        if (tac->type == NORMAL_TAC) {
            printf("(%s, %s, %s, %s)\n", tac->op, tac->first_value, tac->second_value, tac->third_value);
        } else {
            printf("%s:\n", tac->op);
        }
    }
}