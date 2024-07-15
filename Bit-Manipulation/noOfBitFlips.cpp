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

int countBitFlips(int start, int goal)
{
    int res = start ^ goal;
    int bitsFlipped = countSetBits(res);

    return bitsFlipped;
}

int main()
{
    cout << "Number of bits flipped: " << countBitFlips(3, 4) << endl;
    return 0;
}