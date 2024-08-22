/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <ctype.h>
#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(const int *data, int length);
int sum_numbers(const int *buffer, int length);
int find_numbers(int *data, int length, int number, int *output);

int main(void) {
    int data[NMAX];
    int buffer[NMAX];
    int n = 0;
    if (input(data, &n)) {
        int sum_of_elements = sum_numbers(data, n);  // !!!! а если сумма четных 0
        if (sum_of_elements) {
            int numbers_length = find_numbers(data, n, sum_of_elements, buffer);
            printf("%d\n", sum_of_elements);
            output(buffer, numbers_length);
            printf("\n");
        } else {
            printf("n/a");
        }

    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *buffer, int *length) {
    int status = 1;
    char extra;
    if (scanf("%d", length) != 1 || *length < 1 || *length > NMAX) {
        return 0;
    }

    for (int i = 0; i < *length; i++) {
        if (scanf("%d", &buffer[i]) != 1) {
            status = 0;
        }
    }

    if (status) {
        while ((extra = getchar()) != '\n' && extra != EOF) {
            if (!isspace(extra)) {
                status = 0;
                break;
            }
        }
    }

    return status;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(const int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] == 0) {
            continue;
        } else if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

void output(const int *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
}

int find_numbers(int *data, int length, int number, int *output) {
    int counter = 0;
    for (int i = 0; i < length; i++) {
        if (data[i] == 0) {
            continue;
        } else if (number % data[i] == 0) {
            output[counter] = data[i];
            counter++;
        }
    }
    return counter;
}
