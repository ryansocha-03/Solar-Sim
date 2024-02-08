CC=../../../../emsdk/upstream/emscripten/emcc

all: julian_date.o util_math.o

julian_date.o: julian_date.c julian_date.h
	$(CC) julian_date.c -c -o julian_date.o

util_math.o: util_math.c util_math.h
	$(CC) util_math.c -c -o util_math.o

clean:
	rm -rf julian_date.o util_math.o
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

