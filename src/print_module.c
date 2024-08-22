#include "print_module.h"

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    int length = length_str(message);
    for (int i = 0; i < length; i++) {
        print(message[i]);
    }
}

int length_str(const char* str) {
    int result = 0;
    for (; *str; str++, result++)
        ;
    return result;
}