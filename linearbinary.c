#include <stdio.h>

int linearSearch(int arr[], int low, int high, int x, int *count) {
    if (low > high) return -1;
    (*count)++;
    if (arr[low] == x) return low;
    return linearSearch(arr, low + 1, high, x, count);
}

int binarySearch(int arr[], int low, int high, int x, int *count) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    (*count)++;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, low, mid - 1, x, count);
    return binarySearch(arr, mid + 1, high, x, count);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    printf("Array fed into program is {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}\n");
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;
    printf("Element to be found is 6\n");
    int count = 0;
    int choice;
    printf("Enter 1 for linear search, 2 for binary search: ");
    scanf("%d", &choice);
    int result;
    if (choice == 1) {
        result = linearSearch(arr, 0, n - 1, x, &count);
    } else if (choice == 2) {
        result = binarySearch(arr, 0, n - 1, x, &count);
    } else {
        printf("Invalid choice.\n");
        return 0;
    }
    if (result == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }
    printf("Number of comparisons: %d\n", count);
    return 0;
}
