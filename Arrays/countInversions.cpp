#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &nums, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0, cnt = 0, n = high - low + 1;
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
            cnt += (mid - i + 1);
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
        // merging both sorted halves
        cnt += merge(nums, low, mid, high);
    }
    return cnt;
}

int main()
{
    vector<int> nums = {2, 3, 5, 4, 1};
    cout << "Number of pairs: " << mergeSort(nums, 0, 4) << endl;
    return 0;
}