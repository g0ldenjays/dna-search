#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bio.h"

#define MAX_SEQUENCE_LENGTH 1000

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

// esta función lee una línea del archivo, limpia saltos de linea, valida y guarda en sequence
int load_sequence_from_file(bio_state *state, char *filename) {
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error: no se pudo abrir el archivo %s\n", filename);
		return 1;
	}

	char buffer[MAX_SEQUENCE_LENGTH];

	if (fgets(buffer, sizeof(buffer), file) == NULL) {
		printf("Error: no se pudo leer la secuencia desde %s\n", filename);
		fclose(file);
		return 1;
	}

	fclose(file);

	// eliminación de saltos de línea
	size_t len = strlen(buffer);
	while (len > 0 && (buffer[len - 1] == '\n' || buffer[len - 1] == '\r')) {
		buffer[len - 1] = '\0';
		len = len - 1;
	}

	if (len == 0) {
		printf("Error: la secuencia está vacía\n");
		return 1;
	}

	// validar que solo tenga A - C - G - T
	size_t i = 0;
	while (i < len) {
		char c = buffer[i];
		if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
			printf("Error: caracter inválido '%c' en la secuencia\n", c);
			return 1;
		}
		i = i + 1;
	}

	// liberar secuencia anterior si existía
	if (state->sequence != NULL) {
		free(state->sequence);
		state->sequence = NULL;
		state->sequence_length = 0;
	}

	state->sequence = malloc((len + 1) * sizeof(char));
	if (state->sequence == NULL) {
		printf("Error: no se pudo reservar memoria para la secuencia\n");
		return 1;
	}

	strcpy(state->sequence, buffer);
	state->sequence_length = (int)len;

	return 0;
}

void build_index(bio_state *state) {
	if (state->root == NULL) {
		return;
	}

	int n = state->sequence_length;
	int m = state->gene_length;

	if (n < m) {
		printf("Error: la secuencia tiene solo %d caracteres y el gen mide %d\n", n, m);
		printf("       No es posible construir ningún gen de esa longitud.\n");
		return;
	}

	// usamos un buffer para copiar cada gen
	char gene_buffer[m + 1];
	int i;
	int j;

	for (i = 0; i <= n - m; i = i + 1) {
		for (j = 0; j < m; j = j + 1) {
			gene_buffer[j] = state->sequence[i + j];
		}
		gene_buffer[m] = '\0';

		trie_insert(state->root, gene_buffer, i);
	}
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
	if (state->is_initialized == 0 || state->root == NULL || state->gene_length <= 0) {
		printf("Error: primero debes ejecutar start <gene_length>\n");
		return 1;
	}

	if (filename == NULL) {
		printf("Error: nombre de archivo inválido\n");
		return 1;
	}

	// cargar la secuencia desde archivo
	int result = load_sequence_from_file(state, filename);
	if (result != 0) {
		return result;
	}

	// construir índice de todos los genes de largo m
	build_index(state);

	printf("Sequence S read from file %s\n", filename);
	return 0;
}

void print_position(int value, void *user_data) {
	int *first_ptr = (int *)user_data;

	if (*first_ptr) {
		printf("%d", value);
		*first_ptr = 0;
	} else {
		printf(" %d", value);
	}
}

void bio_search_command(bio_state *state, char *gene) {
	if (state == NULL) {
		return;
	}

	if (state->is_initialized == 0 || state->root == NULL) {
		printf("Error: primero debes ejecutar start <gene_length>\n");
		return;
	}

	if (state->sequence == NULL || state->sequence_length == 0) {
		printf("Error: primero debes ejecutar read <archivo>\n");
		return;
	}

	if (gene == NULL) {
		printf("Error: debes indicar un gen a buscar\n");
		return;
	}

	int m = state->gene_length;
	int len = (int) strlen(gene);

	if (len != m) {
		printf("Error: el gen '%s' tiene largo %d y se esperaba %d\n", gene, len, m);
		return;
	}

	// validar que el gen solo tenga A - C - G - T
	int i = 0;
	while (i < len) {
		char c = gene[i];
		if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
			printf("Error: el gen contiene un caracter inválido '%c'\n", c);
			return;
		}
		i = i + 1;
	}

	int_list *positions = trie_find(state->root, gene);
	if (positions == NULL) {
		printf("-1\n");
		return;
	}

	int count = int_list_count(positions);
	if (count == 0) {
		printf("-1\n");
		return;
	}

	int first = 1;
	int_list_foreach(positions, print_position, &first);
	printf("\n");
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
