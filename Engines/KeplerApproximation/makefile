CC=../../../../emsdk/upstream/emscripten/emcc

all: kepler

kepler: main.o JulianDate.o
	$(CC) main.o JulianDate.o -o kepler.mjs -sEXPORTED_RUNTIME_METHODS=ccall,cwrap

main.o: main.c JulianDate.h
	$(CC) main.c -c -o main.o

JulianDate.o: JulianDate.c JulianDate.h
	$(CC) JulianDate.c -c -o JulianDate.o

clean:
	rm -rf main.o JulianDate.o kepler.js main.wasm
# CC = gcc
# CFLAGS = -Wall -Wextra -Wno-format
# SRC_DIR = src
# OBJ_DIR = obj

# SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
# OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# TARGET = my_program.o

# $(OBJ_DIR)/$(TARGET): $(SRC_FILES) $(SRC_DIR)/Julian.h
# 	$(CC) $(SRC_FILES) -c -o $(OBJ_DIR)/$(TARGET) $(CFLAGS)

# .PHONY: clean

# clean:
# 	rm -rf $(OBJ_DIR)/*.o

