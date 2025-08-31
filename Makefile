CXX = clang
# -g and -O0 here for debugging purposes, REMOVE in final
CXXFLAGS = -std=gnu17 -O0 -g -Isrc -Wall -Wextra -Wno-c99-designator

SRC := $(shell find src/ -name '*.c')
OBJ := $(patsubst src/%.c,build/main/%.o,$(SRC))

all: $(OBJ)
	@mkdir -p ./bin
	@$(CXX) $(CXXFLAGS) $(OBJ) -o ./bin/main
#@strip ./bin/main

build/main/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean run
clean: 
	@echo '    cleaning build/ and bin/ directories...'
	@rm -r build/ bin/ 2>/dev/null || true

run: all
	@./bin/main
