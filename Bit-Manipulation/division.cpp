#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    bool sign = true; // both positive
    if (dividend == divisor)
        return 1;
    if ((dividend == -1 * divisor) || (-1 * dividend == divisor))
        return -1;
    if ((dividend <= 0 && divisor > 0) || (dividend >= 0 && divisor < 0))
    {
        sign = false;
    }
    long long n = abs(dividend), d = abs(divisor), ans = 0;
    while (n >= d)
    {
        int c = 0;
        while (n >= (d << (c + 1))) // d*2^(c+1)
        {
            c++;
        }
        ans += (1 << c);
        n -= (d << c);
    }
    if (ans >= pow(2, 31) && sign == true)
        return INT_MAX;
    if (ans >= pow(2, 31) && sign == false)
        return INT_MIN;

    ans = sign ? ans : -1 * ans;
    return ans;
}

int main()
{
    cout << "Answer: " << divide(22, 3) << endl;
    return 0;
}