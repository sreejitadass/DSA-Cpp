#include <bits/stdc++.h>
using namespace std;

/*
*********************
MATHS(EQUATION)
********************
*/

// x-->repeating,y-->missing
pair<int, int> findNumbers1(vector<int> &nums)
{
    long long n = nums.size();
    long long S1 = 0, S2 = 0, S3 = 0, S4 = 0, val1, val2, x, y;
    S2 = (n * (n + 1)) / 2;
    S4 = (n * (2 * n + 1) * (n + 1)) / 6;
    for (int i = 0; i < n; i++)
    {
        S1 += (nums[i]);
        S3 += (long long)(nums[i]) * (long long)(nums[i]);
    }
    val1 = S1 - S2; // x-y
    val2 = S3 - S4;
    val2 /= val1; // x+y

    x = (val1 + val2) / 2;
    y = x - val1;
    return {(int)x, (int)y};
}

/*
*********************
XOR
********************
*/
//(tough)

pair<int, int> findNumbers2(vector<int> &nums)
{
    long long n = nums.size();
    long long X1 = 0, X2 = 0, XR = 0;
    for (int i = 0; i < n; i++)
    {
        X1 ^= nums[i];
        X2 ^= (i + 1);
    }
    XR = X1 ^ X2;
    long long rightmost = ((XR & (XR - 1)) ^ XR);
    long long b1 = 0, b2 = 0; // b1-->1 club,b2-->0 club

    // array
    for (int i = 0; i < n; i++)
    {
        if (rightmost & nums[i]) // 1
            b1 ^= nums[i];
        else // 0
            b2 ^= nums[i];
    }

    // 1 to n
    for (int i = 1; i <= n; i++)
    {
        if (rightmost & i) // 1
            b1 ^= i;
        else // 0
            b2 ^= i;
    }

    // identify the numbers
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == b2)
            cnt++;
    }

    if (cnt == 2)
        return {b2, b1};
    return {b1, b2};
}

int main()
{
    vector<int> nums = {2, 2, 1, 3, 5, 6};
    pair<int, int> ans = findNumbers2(nums);
    cout << "Repeating number: " << ans.first << endl;
    cout << "Missing number: " << ans.second << endl;
    return 0;
}