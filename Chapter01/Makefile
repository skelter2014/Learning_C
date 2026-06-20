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
	rm -f $(TARGET) my_program *.o

# Phony targets
.PHONY: all clean driver

# Driver target: build the driver-based program from specific sources
driver: driver.c hello.c hello1.c hello2.c hello3.c hello_nowhitespace.c
	$(CC) -o my_program driver.c hello.c hello1.c hello2.c hello3.c hello_nowhitespace.c