#include <bits/stdc++.h>
using namespace std;

// power of 2 if there is only 1 set bit
bool checkIfPowerOf2(int N)
{
    return ((N & (N - 1)) == 0);
}

int findSetBitposition(int N)
{
    if (!checkIfPowerOf2(N))
    {
        return -1;
    }
    else
    {
        // move the 1 to end by right shift/outing the zeroes
        int cnt = 0;
        while (N != 1)
        {
            N >>= 1;
            cnt++;
        }
        return cnt;
    }
}

int main()
{
    int pos = findSetBitposition(4);
    cout << "Position: " << pos << endl;
    return 0;
}