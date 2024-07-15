#include <iostream>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0) // n is even
    {
        return power(x, n / 2) * power(x, n / 2);
    }
    else // n is odd
    {
        return x * power(x, n / 2) * power(x, n / 2);
    }
}

int findNthRoot(int m, int n)
{
    int low = 1, high = m, ans = -1;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (power(mid, n) == m)
        {
            low = mid + 1;
            ans = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    cout << "n-th root: " << findNthRoot(27, 3) << endl;
    return 0;
}