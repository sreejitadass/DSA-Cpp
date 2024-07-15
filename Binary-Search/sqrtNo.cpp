#include <iostream>
using namespace std;

// or,largest number such that number*number<=x
int findSqrt(int n)
{
    int low = 1, high = n, ans = 1;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (mid * mid <= n)
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
    cout << "Square root: " << findSqrt(8) << endl;
    return 0;
}