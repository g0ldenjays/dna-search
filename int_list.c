#include <stdlib.h>
#include <stdio.h>
#include "int_list.h"

struct int_node {
    int value;
    struct int_node *next;
};

int_list *int_list_create(void) {
    return NULL;
}

void int_list_append(int_list *list, int value) {
    printf("int list append no implementado");
}

void int_list_free(int_list *list) {
    printf("int list free no implementado");
}

int int_list_count(int_list *list) {
    printf("int list count no implementado");
    return 0;
}
