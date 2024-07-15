#include <bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int> &nums, int x, int y)
{
    reverse(nums.begin() + x, nums.begin() + y);
    return nums;
}

// vector<int> leftRotate1Place(vector<int> &nums)
// {
//     int temp = nums[0], i;
//     for (i = 1; i < nums.size(); i++)
//     {
//         nums[i - 1] = nums[i];
//     }
//     nums[(nums.size() - 1)] = temp;
//     return nums;
// }

vector<int> leftRotateDPlaces(vector<int> &nums, int d)
{
    /*
    Brute force: Use extra temp array of size d
    TC:O(n+d)   -->     O(d)+O(n-d)+O(d)    [copying d elts to temp,then left shifting remaining elts,then pushing back d elts]
    SC:O(d)

    Optimal: No use of extra space
    TC:O(2n)    -->     O(d)+O(n-d)+O(n)
    SC:O(1)
    */
    int n = nums.size();
    d = d % n; // for d>n(or less than also)

    nums = reverse(nums, 0, d); // reverse from 0 to d
    nums = reverse(nums, d, n); // reverse from d to n
    nums = reverse(nums, 0, n); // reverse whole array

    return nums;
}

vector<int> rightRotateDPlaces(vector<int> &nums, int d)
{
    int n = nums.size();
    d = d % n; // for d>n(or less than also)

    nums = reverse(nums, 0, n); // reverse whole array
    nums = reverse(nums, 0, d); // reverse from 0 to d
    nums = reverse(nums, d, n); // reverse from d to n

    return nums;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    vector<int> res = rightRotateDPlaces(nums, 3);
    for (int i : res)
        cout << i << " ";
}