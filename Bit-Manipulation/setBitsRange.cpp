#include <bits/stdc++.h>
using namespace std;

int countSetBits(int N)
{
    int c = 0;
    while (N != 0)
    {
        N = N & (N - 1); // remove/clear/toggle last set bit everytime
        c++;
    }
    return c;
}

int setBitsSum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += countSetBits(i);
    return sum;
}

int main()
{
    cout << "Required sum: " << setBitsSum(3) << endl;
}