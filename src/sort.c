#include <ctype.h>
#include <stdio.h>
#define NMAX 10

int input(int *data, int *n);
void output(const int *data, int n);
void sort(int *data, int n);

int main(void) {
    int data[NMAX];
    int n = 0;
    if (input(data, &n)) {
        sort(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *data, int *n) {
    int status = 1;
    char extra;
    if (scanf("%d", n) != 1 || *n < 1 || *n > NMAX) {
        return 0;
    }

    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &data[i]) != 1) {
            status = 0;
        }
    }

    if (status) {
        if (scanf("%c", &extra) == 1) {
            // Проверяем каждый символ в оставшемся вводе
            while (extra != '\n' && extra != EOF) {
                if (!isspace(extra)) {
                    status = 0;
                    break;
                }
                // Считываем следующий символ
                if (scanf("%c", &extra) != 1) {
                    break;
                }
            }
        };
    };

    return status;
}

void output(const int *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
}

void sort(int *data, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (data[j] > data[i]) {
                int tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
}