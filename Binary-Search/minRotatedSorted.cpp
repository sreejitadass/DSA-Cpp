#include <iostream>
#include <climits>
using namespace std;

int findMinRotated(int arr[], int n)
{
    int low = 0, high = n - 1, ans = INT32_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // identify the sorted half and checking for target there
        // find min from sorted half
        if (arr[mid] >= arr[low]) // left is sorted
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else // right is sorted
        {
            high = mid - 1;
            ans = min(ans, arr[mid]);
        }
    }
    return ans;
}

int main()
{
    int arr[] = {5, 6, 7, 1, 2, 3, 4};
    cout << "Minimum: " << findMinRotated(arr, 7) << endl;
    return 0;
}