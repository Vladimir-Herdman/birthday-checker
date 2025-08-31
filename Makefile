CXX = clang++
CXXFLAGS = -std=c++23 -O3 -Isrc -Wall -Wextra -Wno-c99-designator

SRC := $(shell find src/ -name '*.cpp')
OBJ := $(patsubst src/%.cpp,build/main/%.o,$(SRC))

DEBUGCXXFLAGS = -std=c++23 -O0 -g -Isrc -Wall -Wextra -Wno-c99-designator
DEBUGSRC := $(shell find src/ -name '*.cpp')
DEBUGOBJ := $(patsubst src/%.cpp,build/debug/%.o,$(DEBUGSRC))


all: $(OBJ)
	@mkdir -p ./bin
	@$(CXX) $(CXXFLAGS) $(OBJ) -o ./bin/main
	@strip ./bin/main

build/main/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@


debug: $(DEBUGOBJ)
	@mkdir -p ./bin
	$(CXX) $(DEBUGCXXFLAGS) $(DEBUGOBJ) -o bin/debug
	@printf "%s\n" "    compiled into bin/debug"

build/debug/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(DEBUGCXXFLAGS) -c $< -o $@


.PHONY: all debug clean run
clean: 
	@printf "%s\n" "    cleaning build/ and bin/ directories..."
	@rm -r build/ bin/ 2>/dev/null || true

run: all
	@./bin/main
