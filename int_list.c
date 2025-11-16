#include <stdlib.h>
#include <stdio.h>
#include "int_list.h"

struct int_node {
	int value;
	struct int_node *next;
};

int_list *int_list_create(void) {
	int_list *list = malloc(sizeof(int_list));
	if (list == NULL) {
		return NULL;
	}

	list->head = NULL;
	list->tail = NULL;
	return list;
}

void int_list_append(int_list *list, int value) {
	if (list == NULL) {
		return;
	}

	int_node *node = malloc(sizeof(int_node));
	if (node == NULL) {
		return;
	}

	node->value = value;
	node->next = NULL;

	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
	} else {
		list->tail->next = node;
		list->tail = node;
	}
}

void int_list_free(int_list *list) {
	if (list == NULL) {
		return;
	}

	int_node *current = list->head;
	while (current != NULL) {
		int_node *next = current->next;
		free(current);
		current = next;
	}

	free(list);
}

int int_list_count(int_list *list) {
	if (list == NULL) {
		return 0;
	}

	int count = 0;
	int_node *current = list->head;

	while (current != NULL) {
		count = count + 1;
		current = current->next;
	}

	return count;
}
