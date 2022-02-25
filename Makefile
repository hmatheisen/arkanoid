SRC_DIR=src
INC_DIR=include
BUILD_DIR=build

CC=gcc
CFLAGS=-Wall -I$(INC_DIR)
LDLIBS=-lncurses
RM=rm -rf

# Get all '.c' files in src
SRCS=$(shell find $(SRC_DIR) -name '*.c')
# Object files in build dir
OBJS=$(SRCS:%.c=$(BUILD_DIR)/%.o)

all: arkanoid

# Final linker job
arkanoid: $(OBJS)
	@$(CC) -o $@ $(OBJS) $(LDLIBS)
	@echo "CC -o $@"

# Build step for C source
# Create build directories
# Build each C files in src
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC    $<"

# Format all C files
format:
	clang-format -i $(SRCS)

# Remove build dir
clean:
	@$(RM) $(BUILD_DIR)
	@echo "RM    $(BUILD_DIR)"

.PHONY: all format clean
