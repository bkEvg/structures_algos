CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
SRCS = $(SRC_Q1) $(SRC_Q2) $(SRC_Q3)
SRC_Q1 = main_module_entry_point.c print_module.c
SRC_Q2 = main_module_entry_point.c documentation_module.c print_module.c
SRC_Q3 = bst.c bst_create_test.c
TARGET_1 = ../build/Quest1
TARGET_2 = ../build/Quest2
TARGET_3 = ../build/Quest3
TARGET_4 = ../build/Quest4
TARGET_5 = ../build/Quest5

OBJ_Q1 = $(SRC_Q1:.c=.o)
OBJ_Q2 = $(SRC_Q2:.c=.o)
OBJ_Q3 = $(SRC_Q3:.c=.o)

all: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test

print_module: $(TARGET_1)
documentation_module: $(TARGET_2)
bst_create_test: $(TARGET_3)
bst_insert_test: $(TARGET_4)
bst_traverse_test: $(TARGET_5)

clang_format:
	clang-format -n *.c
	clang-format -n *.h
	clang-format -i *.c
	clang-format -i *.h

$(TARGET_1): $(SRC_Q1)
	$(CC) $(CFLAGS) -o $(TARGET_1) $(SRC_Q1) -DQUEST_1

$(TARGET_2): $(SRC_Q2)
	$(CC) $(CFLAGS) -o $(TARGET_2) $(SRC_Q2) -DQUEST_2

$(TARGET_3): $(SRC_Q3)
	$(CC) $(CFLAGS) -o $(TARGET_3) $(SRC_Q3) -DQUEST_3

$(TARGET_4): $(SRC_Q3)
	$(CC) $(CFLAGS) -o $(TARGET_4) $(SRC_Q3) -DQUEST_4

$(TARGET_5): $(SRC_Q3)
	$(CC) $(CFLAGS) -o $(TARGET_5) $(SRC_Q3) -DQUEST_5

rebuild: clean all

clean:
	rm -f $(TARGET_1) $(TARGET_2) $(TARGET_3) $(TARGET_4) $(TARGET_5) $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test
