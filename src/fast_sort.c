
#include <ctype.h>
#include <stdio.h>
#define NMAX 10

int input(int *data, int *data2, int *n);
void output(const int *data, int n);
void quickSort(int *data, int low, int high);
int partition(int arr[], int low, int high);
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

void swap(int *num1, int *num2) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int main(void) {
    int data[NMAX];
    int data2[NMAX];
    int n = 0;
    if (input(data, data2, &n)) {
        quickSort(data, 0, n - 1);
        mergeSort(data2, 0, n - 1);
        output(data, n);
        output(data2, n);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *data, int *data2, int *n) {
    int status = 1;
    char extra;
    if (scanf("%d", n) != 1 || *n != NMAX) {
        return 0;
    }

    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &data[i]) != 1) {
            status = 0;
        } else {
            data2[i] = data[i];
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
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {  // зачем проверка  j >= low + 1
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);  // зачем проверка доп своп
    return j;
}

void quickSort(int *data, int low, int high) {
    if (low < high) {
        int pivot_index = partition(data, low, high);
        quickSort(data, low,
                  pivot_index - 1);  //  почему здесь и ниже мы не обрабатываем массив не включая индекс опоры
        quickSort(data, pivot_index + 1, high);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArray[n1], rightArray[n2];

    for (int i = 0; i < n1; i++) leftArray[i] = arr[left + i];
    for (int i = 0; i < n2; i++) rightArray[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
