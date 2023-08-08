#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

int kthSmallest(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pos = partition(arr, low, high);
        if (pos - low == k - 1) {
            return arr[pos];
        }
        if (pos - low > k - 1) {
            return kthSmallest(arr, low, pos - 1, k);
        }
        return kthSmallest(arr, pos + 1, high, k - pos + low - 1);
    }
    return -1;
}

int kthLargest(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pos = partition(arr, low, high);
        if (high - pos == k - 1) {
            return arr[pos];
        }
        if (high - pos > k - 1) {
            return kthLargest(arr, pos + 1, high, k);
        }
        return kthLargest(arr, low, pos - 1, k - high + pos - 1);
    }
    return -1;
}

int main() {
    int arr[] = {16, 13, 7, 4, 23, 9, 26, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    printf("Array fed into program is {16, 13, 7, 4, 23, 9, 26, 56}\n");
    printf("Taking k as 4 we get\n");
    printf("Kth smallest element is %d\n", kthSmallest(arr, 0, n - 1, k));
    printf("Kth largest element is %d", kthLargest(arr, 0, n - 1, k));
    return 0;
}
