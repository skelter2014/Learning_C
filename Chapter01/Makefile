# Compiler
CC = gcc

# Target executable
TARGET = hello3

# Source files
SRCS = $(wildcard *.c)

# Default target
all: $(TARGET)

# Build the target executable
$(TARGET): $(SRCS)
	$(CC) -o $(TARGET) $(SRCS)

# Target executable for hello2
TARGET2 = hello2

# Build the target executable for hello2
$(TARGET2): hello2.c
	$(CC) -o $(TARGET2) hello2.c

# Clean up build files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean