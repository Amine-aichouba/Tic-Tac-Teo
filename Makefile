CC = gcc
CFLAGS = -Wall -Wextra
LIBS = -lm

# Source files
MAIN_SRC = main.c
IMPROVED_MAIN_SRC = improved_main.c

# Object files
MAIN_OBJ = $(MAIN_SRC:.c=.o)
IMPROVED_MAIN_OBJ = $(IMPROVED_MAIN_SRC:.c=.o)

# Executables
MAIN_EXEC = tictactoe
IMPROVED_MAIN_EXEC = tictactoe2

.PHONY: all clean

all: $(MAIN_EXEC) $(IMPROVED_MAIN_EXEC)

$(MAIN_EXEC): $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(IMPROVED_MAIN_EXEC): $(IMPROVED_MAIN_OBJ)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MAIN_OBJ) $(IMPROVED_MAIN_OBJ) $(MAIN_EXEC) $(IMPROVED_MAIN_EXEC)
