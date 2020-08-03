#include <bits/stdc++.h>
using namespace std;

int flag[100][100];

int knapsack(int v[], int w[], int n, int m)
{
    if (n == -1 || w == 0)
        return 0;

    if (flag[n][m] != -1)
        return flag[n][m];

    if (w[n] <= m)
    {
        flag[n][m] = max(v[n] + knapsack(v, w, n - 1, m - w[n]), knapsack(v, w, n - 1, m));
        return flag[n][m];
    }
    else
    {
        flag[n][m] = knapsack(v, w, n - 1, m);
        return flag[n][m];
    }
}

int main()
{
    memset(flag, -1, sizeof flag);

    int v[100] = {60, 100, 120};
    int w[100] = {10, 20, 30};

    int n = 2, m = 50;

    int ans = knapsack(v, w, n, m);

    cout << ans;
}