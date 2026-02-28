CC=gcc
CFLAGS=-Wall -Wextra -std=c11

TARGET=football

SRC=src/main.c src/football.c
OBJ=$(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

src/%.o: src/%.c src/football.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
