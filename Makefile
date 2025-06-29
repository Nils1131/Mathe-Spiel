CC ?= gcc
CFLAGS ?= -Wall -Wextra -pedantic -std=c99

SRC := $(wildcard src/*.c)

# Detect Windows to set executable extension and remove command
ifeq ($(OS),Windows_NT)
    EXE := .exe
    RM ?= del /Q
else
    EXE :=
    RM ?= rm -f
endif

BIN := bin/mathquiz$(EXE)

$(BIN): $(SRC)
	@mkdir -p $(dir $(BIN))
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

.PHONY: clean
clean:
	$(RM) $(BIN)
