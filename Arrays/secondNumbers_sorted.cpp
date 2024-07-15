#include <bits/stdc++.h>
using namespace std;

int findSecondLargest(vector<int> &nums)
{
    int largest = nums[0], sLargest = INT_MIN;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > largest)
        {
            sLargest = largest;
            largest = nums[i];
        }
        else if (nums[i] < largest && nums[i] > sLargest)
        {
            sLargest = largest;
        }
    }
    return sLargest;
}

int findSecondSmallest(vector<int> &nums)
{
    int smallest = nums[0], sSmallest = INT_MAX;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < smallest)
        {
            sSmallest = smallest;
            smallest = nums[i];
        }
        else if (nums[i] != smallest && nums[i] < sSmallest)
        {
            sSmallest = smallest;
        }
    }
    return sSmallest;
}

bool ifSorted(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < nums[i - 1])
            return false;
    }
    return true;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 10};
    cout << "Second largest: " << findSecondLargest(nums) << endl;
    cout << "Second smallest: " << findSecondSmallest(nums) << endl;
    cout << "Sorted: " << ifSorted(nums) << endl;
    return 0;
}