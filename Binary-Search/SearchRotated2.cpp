// non-unique elements in rotated sorted array
#include <iostream>
using namespace std;

int searchInRotatedSorted(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        // identify the sorted half and checking for target there

        // problem-->arr[mid]=arr[low]=arr[high]-shrink the search space
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }
        if (arr[mid] >= arr[low]) // left is sorted
        {
            if (x >= arr[low] && x < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else // right is sorted
        {
            if (x > arr[mid] && x <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {3, 1, 2, 3, 3, 3, 3};
    cout << "Position: " << searchInRotatedSorted(arr, 7, 3) << endl;
    return 0;
}