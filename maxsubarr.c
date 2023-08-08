#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int max_crossing_sum(int arr[], int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

int max_subarray_sum(int arr[], int l, int h)
{
    if (l == h)
        return arr[l];

    int m = (l + h) / 2;

    return max(max(max_subarray_sum(arr, l, m),
                   max_subarray_sum(arr, m + 1, h)),
               max_crossing_sum(arr, l, m, h));
}

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = max_subarray_sum(arr, 0, n - 1);
    printf("Maximum contiguous sum is %d\n", max_sum);
    return 0;
}
