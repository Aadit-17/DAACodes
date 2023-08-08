#include <stdio.h>
#include <string.h>

struct Mobile {
    char model[20];
    int RAM;
    int year;
    int camera;
};

void merge(struct Mobile arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    struct Mobile L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].RAM <= R[j].RAM) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct Mobile arr[], int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main() {
    struct Mobile phones[] = {
        {"iPhone X", 3, 2017, 12},
        {"Galaxy S9", 4, 2018, 16},
        {"Pixel 2", 4, 2017, 12},
        {"Moto G5", 2, 2017, 8},
        {"OnePlus 5T", 6, 2017, 20}
    };
    int n = sizeof(phones) / sizeof(phones[0]);

    printf("Original list:\n");
    for (int i = 0; i < n; i++) {
        printf("Model: %s, RAM: %dGB, Year: %d, Camera: %dMP\n", phones[i].model, phones[i].RAM, phones[i].year, phones[i].camera);
    }

    mergeSort(phones, 0, n - 1);

    printf("\nSorted list (by RAM):\n");
    for (int i = 0; i < n; i++) {
        printf("Model: %s, RAM: %dGB, Year: %d, Camera: %dMP\n", phones[i].model, phones[i].RAM, phones[i].year, phones[i].camera);
    }

    return 0;
}
