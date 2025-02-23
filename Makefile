# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -Wfatal-errors -pedantic -std=c++11 -O3

# Source files
SRCS = raytrace.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
EXEC = raytrace

# Default target
all: $(EXEC)

# Link object files to create executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files to create executable
raytrace: raytrace.o vec3.o ray.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean