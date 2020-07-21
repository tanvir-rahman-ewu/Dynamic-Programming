#include <bits/stdc++.h>
using namespace std;

int buffer[5][5] = {1};

int find_path(int row, int col)
{
    if (buffer[row][col] != -1)
        return buffer[row][col];

    if (row == 0 && col == 0)
        return 0;

    if (row == 0 || col == 0)
        return 1;

    //cout << row << " " << col << endl;

    buffer[row][col] = find_path(row - 1, col) + find_path(row, col - 1);

    return buffer[row][col];
}

int main()
{

    memset(buffer, -1, sizeof buffer);

    int row = 3, col = 3;

    int ans = find_path(row, col);

    cout << ans << endl;
}