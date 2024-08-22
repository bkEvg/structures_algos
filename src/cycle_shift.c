#include <ctype.h>
#include <stdio.h>
#define NMAX 10

int input(int *data, int *length, int *shift);
void output(const int *data, const int length);
void processing(int *data, const int length, const int shift, int *output);

int main(void) {
    int data[NMAX];
    int result[NMAX];
    int shift;
    int n;
    if (input(data, &n, &shift)) {
        printf("n/a\n");
    } else {
        processing(data, n, shift, result);
        output(result, n);
    }
    return 0;
}

int input(int *data, int *length, int *shift) {
    char extra;
    int status = 0;
    if (scanf("%d", length) != 1 || *length > 10 || *length <= 0) {
        return 1;
    }

    for (int i = 0; i < *length; i++) {
        if (scanf("%d", &data[i]) != 1) {
            status = 1;
        }
    }

    while ((extra = getchar()) != '\n') {
        if (!isspace(extra)) {
            status = 1;
        }
    }
    if (scanf("%d", shift) != 1) {
        status = 1;
    }

    return status;
}

void output(const int *data, const int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
}

void processing(int *data, const int length, const int shift, int *output) {
    int effectiveShift = shift % length;  // Уменьшаем сдвиг до размера массива
    if (effectiveShift < 0) {
        effectiveShift += length;  // Приводим отрицательный сдвиг к положительному эквиваленту
    }

    // Сдвиг вправо
    if (effectiveShift > 0) {
        for (int i = 0; i < length; i++) {
            output[(i + effectiveShift) % length] = data[i];
        }
    }
    // Сдвиг влево
    else if (effectiveShift < 0) {
        for (int i = 0; i < length; i++) {
            output[(i + effectiveShift + length) % length] = data[i];
        }
    }
}