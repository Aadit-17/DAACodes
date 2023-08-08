#include <stdio.h>
#include <limits.h>

#define N 5

int m[N][N];
int s[N][N];

void print_optimal_parens(int i, int j)
{
    if (i == j)
        printf("A%d", i);
    else
    {
        printf("(");
        print_optimal_parens(i, s[i][j]);
        print_optimal_parens(s[i][j] + 1, j);
        printf(")");
    }
}

void matrix_chain_order(int p[], int n)
{
    int i, j, k, l, q;
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (l = 2; l < n; l++) {
        for (i = 1; i < n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("Minimum number of multiplications is %d\n", m[1][n - 1]);
    printf("The optimal parenthesis is : ");
    print_optimal_parens(1, n - 1);
}

int main()
{
    int arr[] = {2, 3, 4, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    matrix_chain_order(arr, n);
    return 0;
}
