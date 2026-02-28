CC=gcc
CFLAGS=-Wall -Wextra -std=c11

TARGET=building_program

SRC=src/main.c src/buildings.c
OBJ=$(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

src/%.o: src/%.c src/buildings.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
