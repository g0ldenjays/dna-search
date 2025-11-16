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

int bio_start(bio_state *state, int gene_length) {
	printf("bio start no implementado\n");
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
