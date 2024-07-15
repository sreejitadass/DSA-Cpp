#include <iostream>
using namespace std;

int BSearch_recursive(int arr[], int low, int high, int target)
{
    if (low > high)
        return -1;
    else
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (target > arr[mid])
            return BSearch_recursive(arr, mid + 1, high, target);
        else
            return BSearch_recursive(arr, low, mid - 1, target);
    }
}

int main()
{
    int arr[] = {-2, 3, 4, 6, 9, 12, 45};
    cout << "Found at index: " << BSearch_recursive(arr, 0, 6, 12) << endl;
    return 0;
}