CC ?= gcc
CFLAGS ?= -Wall -Wextra -pedantic -std=c99

SRC := $(wildcard src/*.c)

# Detect Windows to set executable extension and use PowerShell commands
ifeq ($(OS),Windows_NT)
    EXE := .exe
    # Use PowerShell as the shell for command execution
    SHELL := powershell.exe
    .SHELLFLAGS := -NoProfile -Command
    # Cross‑platform directory creation and removal
    RM ?= Remove-Item -Force
    MKDIR ?= New-Item -ItemType Directory -Force -Path
else
    EXE :=
    RM ?= rm -f
    MKDIR ?= mkdir -p
endif

BIN := bin/mathquiz$(EXE)

$(BIN): $(SRC)
	@$(MKDIR) $(dir $(BIN))
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

.PHONY: clean
clean:
	$(RM) $(BIN)
