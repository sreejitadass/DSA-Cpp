#include <iostream>
#include<vector>
using namespace std;

// Brute and better--> in copy; Optimal:DNF

vector<int> sortArray(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
    return arr;
}

int main()
{
    vector<int> nums = {0, 1, 0, 0, 1, 2, 1, 2, 0, 0, 1};
    vector<int> arr = sortArray(nums);
    for (int i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}
