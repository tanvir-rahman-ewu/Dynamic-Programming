#include <bits/stdc++.h>
using namespace std;

int arr[5][5] = {
    1, 3, 4, 5, 2,
    2, 3, 5, 7, 3,
    3, 4, 2, 2, 1,
    1, 0, 3, 6, 2,
    1, 4, 5, 6, 2};

int buffer[5][5];

int find_min_cost_path(int row, int col)
{
    if (buffer[row][col] != -1)
        return buffer[row][col];

    if (row == 0 && col == 0)
        return arr[row][col];

    if (row == 0 || col == 0)
        return arr[row][col];

    buffer[row][col] = arr[row][col] + min(find_min_cost_path(row - 1, col), find_min_cost_path(row, col - 1));

    return buffer[row][col];
}

int main()
{
    memset(buffer, -1, sizeof buffer);

    for (int i = 1; i < 5; i++)
    {
        arr[i][0] = arr[i - 1][0] + arr[i][0];
    }
    for (int i = 1; i < 5; i++)
    {
        arr[0][i] = arr[0][i - 1] + arr[0][i];
    }

    cout << find_min_cost_path(4, 4);
}