#include <bits/stdc++.h>
using namespace std;

int modifyX(int x, int y, int l, int r)
{
    if (l < 1 || r > 32)
        return -1;
    for (int i = l; i <= r; i++)
    {
        int mask = 1 << (i - 1);

        if ((y & mask) != 0)
            x = x | mask;
    }
    return x;
}

int main()
{
    cout << "Modified value: " << modifyX(10, 13, 2, 3) << endl;
    return 0;
}