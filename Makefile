# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra -g

# Paths and filenames
SRC_DIR := .
LIB_DIR := ./lib/
LIB_NAME := m_lib

# Source files and object files
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(SRC_DIR)/%.o, $(SRCS))

# Targets
all: my_program

my_program: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIB_DIR) -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) my_program

