# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

# Source and build structure
SRC := src/main.cpp src/games/*.cpp src/utils/*.cpp
OBJ := $(patsubst src/%,build/%,$(SRC:.cpp=.o))
TARGET := build/main

# Default rule
all: $(TARGET)

# Link the final binary
$(TARGET): $(OBJ)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp files to build/*.o
build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf build

.PHONY: all clean
