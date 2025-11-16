#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bio.h"

void bio_state_init(bio_state *state) {
	state->root = NULL;
	state->gene_length = 0;
	state->sequence = NULL;
	state->sequence_length = 0;
	state->is_initialized = 0;
}

void bio_state_clear(bio_state *state) {
	if (state->root != NULL) {
		trie_free(state->root, state->gene_length);
		state->root = NULL;
	}

	if (state->sequence != NULL) {
		free(state->sequence);
		state->sequence = NULL;
	}

	state->gene_length = 0;
	state->sequence_length = 0;
	state->is_initialized = 0;
}

int bio_start(bio_state *state, int gene_length) {
	if (gene_length <= 0) {
		printf("Error: gene_length debe ser mayor que 0\n");
		return 1;
	}

	bio_state_clear(state);

	state->root = trie_create(gene_length);
	if (state->root == NULL) {
		printf("Error: no se pudo crear el trie\n");
		return 1;
	}

	state->gene_length = gene_length;
	state->is_initialized = 1;

	printf("Tree created with height %d\n", gene_length);
	return 0;
}

int bio_read(bio_state *state, char *filename) {
	printf("bio read no implementado\n");
	return 0;
}

void bio_search_command(bio_state *state, char *gene) {
	printf("bio search no implementado\n");
}

void bio_max_command(bio_state *state) {
	printf("bio max no implementado\n");
}

void bio_min_command(bio_state *state) {
	printf("bio min no implementado\n");
}

void bio_all_command(bio_state *state) {
	printf("bio all no implementado\n");
}
