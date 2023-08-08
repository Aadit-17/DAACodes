#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int part(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low - 1, j = high + 1;
	while (1)
    {
		do
        {
			i++;
		}
		while (arr[i] < pivot);
            do
            {
                j--;
            }
            while (arr[j] > pivot);
                if (i >= j)
                    return j;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
	}
}

int part_r(int arr[], int low, int high)
{
	srand(time(0));
	int random = low + rand() % (high - low);
	int temp = arr[random];
	arr[random] = arr[low];
	arr[low] = temp;
	return part(arr, low, high);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
    {
		int pi = part_r(arr, low, high);
		quickSort(arr, low, pi);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = { 9, 5, 2, 1, 7, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
