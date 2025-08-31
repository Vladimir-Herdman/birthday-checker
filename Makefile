CXX = clang
CXXFLAGS = -std=gnu17 -O3 -Isrc -Wall -Wextra -Wno-c99-designator

SRC := $(shell find src/ -name '*.c')
OBJ := $(patsubst src/%.c,build/main/%.o,$(SRC))

all: $(OBJ)
	@mkdir -p ./bin
	@$(CXX) $(CXXFLAGS) -g $(OBJ) -o ./bin/main
	@strip ./bin/main

build/main/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean run
clean: 
	@echo '    cleaning build/ and bin/ directories...'
	@rm -r build/ bin/ 2>/dev/null || true

run: all
	@./bin/main
