#include <stdlib.h>
#include <stdio.h>
#include "trie.h"

struct trie_node {
	struct trie_node *children[4]; // 0:A, 1:C, 2:G, 3:T
	int_list *positions;
};

int char_to_index(char c) {
	if (c == 'A') {
		return 0;
	} else if (c == 'C') {
		return 1;
	} else if (c == 'G') {
		return 2;
	} else if (c == 'T') {
		return 3;
	} else {
		return -1;
	}
}

// crea el trie completo de altura height (gene_length)
trie_node *trie_create_recursive(int level, int height) {
	trie_node *node = malloc(sizeof(trie_node));
	if (node == NULL) {
		return NULL;
	}

	int i;
	for (i = 0; i < 4; i++) {
		node->children[i] = NULL;
	}
	node->positions = NULL;

	if (level == height) {
		// lista de posiciones inicializada
		node->positions = int_list_create();
		if (node->positions == NULL) {
			free(node);
			return NULL;
		}
	} else {
		// nodo interno: crear 4 hijos 
		int child_level = level + 1;
		for (i = 0; i < 4; i++) {
			node->children[i] = trie_create_recursive(child_level, height);
			if (node->children[i] == NULL) {
				int j;
				for (j = 0; j < i; j++) {
					trie_free(node->children[j], height - child_level);
				}
				if (node->positions != NULL) {
					int_list_free(node->positions);
				}
				free(node);
				return NULL;
			}
		}
	}

	return node;
}

trie_node *trie_create(int height) {
	if (height <= 0) {
		return NULL;
	}

	return trie_create_recursive(0, height);
}

void trie_insert(trie_node *root, char *gene, int pos) {
	if (root == NULL || gene == NULL) {
		return;
	}

	trie_node *current = root;
	int i = 0;
	int index;

	while (gene[i] != '\0') {
		index = char_to_index(gene[i]);
		if (index < 0) {
			return;
		}

		if (current->children[index] == NULL) {
			return;
		}

		current = current->children[index];
		i = i + 1;
	}

	if (current->positions == NULL) {
		current->positions = int_list_create();
		if (current->positions == NULL) {
			return;
		}
	}

	int_list_append(current->positions, pos);
}

int_list *trie_find(trie_node *root, char *gene) {
	if (root == NULL || gene == NULL) {
		return NULL;
	}

	trie_node *current = root;
	int i = 0;
	int index;

	while (gene[i] != '\0') {
		index = char_to_index(gene[i]);
		if (index < 0) {
			return NULL;
		}

		if (current->children[index] == NULL) {
			return NULL;
		}

		current = current->children[index];
		i = i + 1;
	}

	return current->positions;
}

void trie_free(trie_node *root, int height) {

    if (root == NULL) {
        return;
    }

    int i;
    for (i = 0; i < 4; i++) {
        if (root->children[i] != NULL) {
            trie_free(root->children[i], height);
        }
    }

    if (root->positions != NULL) {
        int_list_free(root->positions);
    }

    free(root);
}
