#ifndef BIO_H
#define BIO_H

#include "trie.h"

typedef struct bio_state {
	trie_node *root;
	int gene_length;
	char *sequence;
	int sequence_length;
	int is_initialized;
} bio_state;

void bio_state_init(bio_state *state);

int bio_start(bio_state *state, int gene_length);
int bio_read(bio_state *state, char *filename);

void bio_search_command(bio_state *state, char *gene);
void bio_max_command(bio_state *state);
void bio_min_command(bio_state *state);
void bio_all_command(bio_state *state);

#endif
