// generate n-th row
#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void generateRow(int numRow)
{
    int ans = 1;
    cout << ans << " ";
    for (int i = 1; i < numRow; i++)
    {
        ans *= (numRow - i);
        ans /= i;
        cout << ans << " ";
    }
    cout << endl;
}

int main()
{
    generateRow(6);
    return 0;
}