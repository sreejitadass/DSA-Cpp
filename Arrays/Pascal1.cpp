// given row and column find the element
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

int generateElement(int row, int col)
{
    int ans = nCr(row - 1, col - 1);
    return ans;
}

int main()
{
    cout << "The element is: " << generateElement(4, 3) << endl;
    return 0;
}