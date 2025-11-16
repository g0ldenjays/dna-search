CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = main.c bio.c trie.c int_list.c
OBJ = $(SRC:.c=.o)

TARGET = bio

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
	@echo ""
	@echo "============================================================================="
	@echo "               !!! Compilación completa de $(TARGET) !!! "
	@echo ""
	@echo "        Si ves warnings de 'unused parameter', es normal por ahora."
	@echo "    Esos parámetros todavía no se usan aún, pero son parte del esqueleto."
	@echo "      Se irán eliminando a medida que se implemente search/max/min/all."
	@echo "============================================================================="
	@echo ""

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clear:
	rm -f $(OBJ) $(TARGET)
