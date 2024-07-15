#include <bits/stdc++.h>
using namespace std;

int findSum(vector<int> &nums)
{
    int sum = 0;
    for (int i : nums)
        sum += i;
    return sum;
}

int findMissingNumber1(vector<int> &nums)
{
    int n = nums[nums.size() - 1];
    int sum1 = findSum(nums);
    int sum2 = (n * (n + 1)) / 2;
    return (sum2 - sum1);
}

int findMissingNumber2(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != nums[i] - 1)
            return i + 1;
    }
}

// XOR
int findMissingNumber3(vector<int> &nums)
{
    int XOR1 = 0, XOR2 = 0, N = nums[nums.size() - 1];
    for (int i = 0; i < N - 1; i++)
    {
        XOR1 ^= (i + 1); // 1 to N
        XOR2 ^= nums[i]; // for all numbers
    }
    XOR1 ^= N;
    return (XOR1 ^ XOR2);
}

int main()
{
    vector<int> nums = {1, 3, 4, 5, 6, 7};
    cout << "Missing number: " << findMissingNumber3(nums) << endl;
}