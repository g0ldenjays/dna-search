#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bio.h"

#define MAX_COMMAND_LENGTH 256

int main(void) {
	bio_state state;
	char line[MAX_COMMAND_LENGTH];

	bio_state_init(&state);

	printf("dna-search\n");
	printf("Escribe un comando (start, read, search, max, min, all, exit)\n");

	while (1) {
		printf("> ");
		if (fgets(line, sizeof(line), stdin) == NULL) {
			break;
		}

		// eliminar salto de línea si existe
		size_t len = strlen(line);
		if (len > 0 && line[len - 1] == '\n') {
			line[len - 1] = '\0';
		}

		// parseado principal
		if (strcmp(line, "exit") == 0) {
			break;

		} else if (strncmp(line, "start", 5) == 0) {
		    int m;
		    int scanned = sscanf(line, "start %d", &m);

		    if (scanned != 1) {
		        printf("Uso: start <gene_length>\n");
		    } else {
		        bio_start(&state, m);
		    }

		} else if (strncmp(line, "read", 4) == 0) {
			printf("Comando read recibido (WIP)\n");

		} else if (strncmp(line, "search", 6) == 0) {
			printf("Comando search recibido (WIP)\n");

		} else if (strcmp(line, "max") == 0) {
			printf("Comando max recibido (WIP)\n");

		} else if (strcmp(line, "min") == 0) {
			printf("Comando min recibido (WIP)\n");

		} else if (strcmp(line, "all") == 0) {
			printf("Comando all recibido (WIP)\n");
			
		} else if (strlen(line) == 0) {
			// línea vacía = ignorar comandu
		} else {
			printf("Comando no reconocido: %s\n", line);
		}
	}

	return 0;
}
