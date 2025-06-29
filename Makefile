CC ?= gcc
CFLAGS ?= -Wall -Wextra -pedantic -std=c99

SRC := $(wildcard src/*.c)
BIN := bin/mathquiz

$(BIN): $(SRC)
	@mkdir -p $(dir $(BIN))
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

.PHONY: clean
clean:
	$(RM) $(BIN)
