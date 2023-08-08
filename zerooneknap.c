#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

int w[MAX_ITEMS];
int v[MAX_ITEMS];
int dp[MAX_ITEMS][MAX_ITEMS];

int max(int a, int b)
{
    return a > b ? a : b;
}

int knapsack(int n, int W)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (w[i - 1] <= j)
                {
                dp[i][j] = max(v[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
                }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int n = 4;
    int W = 7;

    w[0] = 1;
    w[1] = 5;
    w[2] = 2;
    w[3] = 2;

    v[0] = 4;
    v[1] = 1;
    v[2] = 7;
    v[3] = 5;

    printf("The maximum value that can be put in a knapsack of capacity %d is %d\n", W, knapsack(n, W));
    return 0;
}
