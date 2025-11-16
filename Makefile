CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = main.c bio.c trie.c int_list.c
OBJ = $(SRC:.c=.o)

TARGET = bio

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
