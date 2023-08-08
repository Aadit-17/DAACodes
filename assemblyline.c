#include <stdio.h>

#define MAX_STAGES 10
#define MAX_LINES 2

int e[MAX_LINES];
int x[MAX_LINES];
int a[MAX_LINES][MAX_STAGES];
int t[MAX_LINES][MAX_STAGES];
int f[MAX_LINES][MAX_STAGES];
int l[MAX_LINES];

int min(int a, int b)
{
    return a < b ? a : b;
}

void assembly_line_scheduling(int n)
{
    f[0][0] = e[0] + a[0][0];
    f[1][0] = e[1] + a[1][0];

    for (int j = 1; j < n; j++)
    {
        f[0][j] = min(f[0][j - 1] + a[0][j], f[1][j - 1] + t[1][j - 1] + a[0][j]);
        f[1][j] = min(f[1][j - 1] + a[1][j], f[0][j - 1] + t[0][j - 1] + a[1][j]);
    }

    int ft1 = f[0][n - 1] + x[0];
    int ft2 = f[1][n - 1] + x[1];
    int ft = min(ft1, ft2);

    printf("The minimum time taken to speed through the assembly line: %d\n", ft);
}

int main()
{
    e[0] = 2;
    e[1] = 3;
    x[0] = 3;
    x[1] = 1;
    l[0] = 5;
    l[1] = 4;

    a[0][0] = 7;
    a[0][1] = 4;
    a[0][2] = 3;
    a[0][3] = 4;
    a[1][0] = 2;
    a[1][1] = 4;
    a[1][2] = 2;
    a[1][3] = 4;

    t[0][0] = 2;
    t[1][0] = 5;
    t[0][1] = 1;
    t[1][1] = 9;
    t[0][2] = 2;
    t[1][2] = 2;
    t[0][3] = 4;
    t[1][3] = 1;

    int n = 4;
    assembly_line_scheduling(n);
    return 0;
}
