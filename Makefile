CXX = clang++
CXXFLAGS = -std=c++23 -O3 -Isrc -Wall -Wextra -Wno-c99-designator

SRC := $(shell find src/ -name '*.cpp')
OBJ := $(patsubst src/%.cpp,build/main/%.o,$(SRC))

all: $(OBJ)
	@mkdir -p ./bin
	@$(CXX) $(CXXFLAGS) $(OBJ) -o ./bin/main
	@strip ./bin/main

build/main/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean run
clean: 
	@echo '    cleaning build/ and bin/ directories...'
	@rm -r build/ bin/ 2>/dev/null || true

run: all
	@./bin/main
