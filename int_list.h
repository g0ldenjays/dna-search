#ifndef INT_LIST_H
#define INT_LIST_H

typedef struct int_node int_node;

typedef struct int_list {
	int_node *head;
	int_node *tail;
} int_list;

int_list *int_list_create();
void int_list_append(int_list *list, int value);
void int_list_free(int_list *list);
int int_list_count(int_list *list);

typedef void (*int_list_visit_fn)(int value, void *user_data);
void int_list_foreach(int_list *list, int_list_visit_fn visit, void *user_data);

#endif
