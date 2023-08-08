#include <stdio.h>
#define A 0
#define B 1
#define C 2
#define MAX 1000
#define O 1000000000

int n;
int f;
int cap[MAX][MAX];
int flow[MAX][MAX];
int color[MAX];
int pred[MAX];
int min(int x, int y)
{
    return x < y ? x : y;
}
int head, tail;
int q[MAX + 2];
void enqueue(int x)
{
    q[tail] = x;
    tail++;
    color[x] = B;
}
int dequeue()
{
    int x = q[head];
    head++;
    color[x] = C;
    return x;
}
int bfs(int start, int target)
{
    int u, v;
    for (u = 0; u < n; u++)
    {
        color[u] = A;
    }
    head = tail = 0;
    enqueue(start);
    pred[start] = -1;
    while (head != tail)
    {
        u = dequeue();
        for (v = 0; v < n; v++)
        {
            if (color[v] == A && cap[u][v] - flow[u][v] > 0)
            {
                enqueue(v);
                pred[v] = u;
            }
        }
    }
    return color[target] == C;
}
int fordFulkerson(int source, int sink)
{
    int i, j, u;
    int max_flow = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            flow[i][j] = 0;
        }
    }
    while (bfs(source, sink))
    {
        int inc = O;
        for (u = n - 1; pred[u] >= 0; u = pred[u])
        {
            inc = min(inc, cap[pred[u]][u] - flow[pred[u]][u]);
        }
        for (u = n - 1; pred[u] >= 0; u = pred[u])
        {
            flow[pred[u]][u] += inc;
            flow[u][pred[u]] -= inc;
        }
        max_flow += inc;
    }
    return max_flow;
}
int main()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cap[i][j] = 0;
        }
    }
    n = 6;
    f = 7;
    cap[0][1] = 4;
    cap[0][4] = 5;
    cap[1][3] = 6;
    cap[2][4] = 7;
    cap[2][5] = 5;
    cap[3][2] = 3;
    cap[3][4] = 2;
    cap[4][1] = 4;
    cap[4][3] = 6;
    int s = 0, t = 5;
    printf("Max Flow for this problem is: %d\n", fordFulkerson(s, t));
}
