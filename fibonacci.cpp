#include <bits/stdc++.h>
using namespace std;

int buffer[100];

int fibo(int n)
{
    if (buffer[n] != -1)
        return buffer[n];

    buffer[n] = fibo(n - 1) + fibo(n - 2);

    return buffer[n];
}

int main()
{
    memset(buffer, -1, sizeof buffer);

    buffer[0] = 0;
    buffer[1] = 1;

    cout << fibo(10) << endl;
}