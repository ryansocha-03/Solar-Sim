CC=../../../../emsdk/upstream/emscripten/emcc
UTIL_DIR=../util

all: kepler

kepler: main.o kepler_approximation.o $(UTIL_DIR)/julian_date.o
	$(CC) main.o kepler_approximation.o $(UTIL_DIR)/julian_date.o -o kepler.mjs

main.o: main.c $(UTIL_DIR)/julian_date.h
	$(CC) main.c -c -o main.o

kepler_approximation.o: kepler_approximation.c kepler_approximation.h
	$(CC) kepler_approximation.c -c -o kepler_approximation.o

julian_date.o: $(UTIL_DIR)/julian_date.c $(UTIL_DIR)/julian_date.h
	$(CC) $(UTIL_DIR)/julian_date.c -c -o $(UTIL_DIR)/julian_date.o

clean:
	rm -rf main.o kepler_approximation.o kepler.mjs kepler.wasm 
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

