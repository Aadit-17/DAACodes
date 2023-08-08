#include<stdio.h>
#include<conio.h>
#include<string.h>

int match(char st[100], char pat[100]);
int main(int argc, char **argv)
{
    char str[100], pat[100];
    int status;
    printf("Enter the String to be checked:\n");
    gets(str);
    printf("Enter the pattern to be matched:\n");
    gets(pat);
    status = match(str, pat);
    if (status == -1)
    printf("\nNo match could be found");
    else
    printf("Match has been found at position %d.", status);
    return 0;
}
int match(char st[100], char pat[100])
{
    int n, m, i, j, count = 0, temp = 0;
    n = strlen(st);
    m = strlen(pat);
    for (i = 0; i <= n - m; i++)
    {
        temp++;
        for (j = 0; j < m; j++)
        {
            if (st[i + j] == pat[j])
            count++;
        }
        if (count == m)
        return temp;
        count = 0;
    }
    return -1;
}
