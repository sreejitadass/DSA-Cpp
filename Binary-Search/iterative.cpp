#include <iostream>
using namespace std;

int BSearch_iterative(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target == arr[mid])
            return mid;
        else if (target < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {-2, 3, 4, 6, 9, 12, 45};
    cout << "Found at index: " << BSearch_iterative(arr, 7, 45) << endl;
    return 0;
}