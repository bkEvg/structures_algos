#include <stdio.h>

#include "documentation_module.h"
#include "print_module.h"

int main() {
#ifdef QUEST_1
    time_t rawtime;
    struct tm* timeinfo;
    char message[50];
    print_log(print_char, Log_prefix);
    print_log(print_char, " ");
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(message, 10, "%H:%M:%S", timeinfo);
    strcat(message, " ");
    strcat(message, Module_load_success_message);
    print_log(print_char, message);
#endif
#ifdef QUEST_2
    print_log(print_char, "Module_load_success\n");

    int* availability_mask = check_available_documentation_module(validate, Documents_count, Documents);

    // Output availability for each document
    output_availability(availability_mask, Documents_count, Documents);
    free(availability_mask);
#endif
    return 0;
}
