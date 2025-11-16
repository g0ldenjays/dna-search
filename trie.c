#include <stdlib.h>
#include <stdio.h>
#include "trie.h"

struct trie_node {
	struct trie_node *children[4];
	int_list *positions;
};

trie_node *trie_create(int height) {
	printf("trie create no implementado");
	return NULL;
}

void trie_insert(trie_node *root, char *gene, int pos) {
	printf("trie insert no implementado");
}

int_list *trie_find(trie_node *root, char *gene) {
	printf("trie find no implementado");
	return NULL;
}

void trie_free(trie_node *root, int height) {
	printf("trie free no implementado");
}
