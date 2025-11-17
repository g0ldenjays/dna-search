#ifndef TRIE_H
#define TRIE_H

#include "int_list.h"

typedef struct trie_node trie_node;

trie_node *trie_create(int height);
void trie_insert(trie_node *root, char *gene, int pos);
int_list *trie_find(trie_node *root, char *gene);
void trie_free(trie_node *root, int height);

typedef void (*trie_visit_fn)(char *gene, int_list *positions, void *user_data);

void trie_traverse(trie_node *root, int gene_length, trie_visit_fn visit, void *user_data);

#endif
