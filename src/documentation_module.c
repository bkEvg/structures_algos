#include "documentation_module.h"

int validate(char *data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int *check_available_documentation_module(int (*validate)(char *), int document_count, ...) {
    int *mask = malloc(sizeof(int) * Documents_count);
    va_list document;
    va_start(document, document_count);
    for (int i = 0; i < document_count; i++) {
        mask[i] = validate(va_arg(document, char *));
    }
    va_end(document);
    return mask;
}

void output_availability(int *mask, int length, ...) {
    va_list documents;
    va_start(documents, length);
    for (int i = 0; i < length; i++) {
        printf("%s: %s\n", va_arg(documents, char *), mask[i] == 1 ? "available" : "unavailable");
    }
    va_end(documents);
}