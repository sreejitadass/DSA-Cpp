#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0, n = high - low + 1;
    vector<int> merged(n);
    while (i <= mid && j <= high)
    {
        if (nums[i] <= nums[j])
        {
            merged[k] = nums[i];
            k++;
            i++;
        }
        else
        {
            merged[k] = nums[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        merged[k] = nums[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        merged[k] = nums[j];
        k++;
        j++;
    }
    for (i = 0; i < n; i++)
    {
        nums[low + i] = merged[i];
    }
}

int countPairs(vector<int> &nums, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && nums[i] > 2 * nums[right])
            right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &nums, int low, int high)
{
    int cnt = 0;
    if (low < high)
    {
        int mid = (low + high) / 2;
        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        cnt += countPairs(nums, low, mid, high);
        // merging both sorted halves
        merge(nums, low, mid, high);
    }
    return cnt;
}

int main()
{
    vector<int> nums = {4, 1, 2, 3, 1};
    int n = nums.size();
    cout << "Number of pairs: " << mergeSort(nums, 0, n - 1) << endl;
    return 0;
}