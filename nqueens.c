#include <stdio.h>
#include <stdbool.h>

#define N 4

int row[N];

bool is_place_valid(int r, int c)
{
    for (int i = 0; i < c; i++)
        if (row[i] == r || (i - c) == (row[i] - r) || (i - c) == (r - row[i]))
            return false;
    return true;
}

void print_board(int n)
{
    for (int i = 0; i < n; i++)
        {
        for (int j = 0; j < n; j++)
        {
            if (row[j] == i)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void solve_n_queens(int c, int n)
{
    if (c == n)
    {
        print_board(n);
        return;
    }

    for (int r = 0; r < n; r++)
    {
        if (is_place_valid(r, c))
        {
            row[c] = r;
            solve_n_queens(c + 1, n);
        }
    }
}

int main()
{
    solve_n_queens(0, N);
    return 0;
}
