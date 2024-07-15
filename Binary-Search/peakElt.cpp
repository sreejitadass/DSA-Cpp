#include <iostream>
using namespace std;

int PeakElement(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    // handling edge cases
    if (arr[0] > arr[1])
        return arr[0];
    if (arr[n - 1] > arr[n - 2])
        return arr[n - 1];
    else
    {
        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
                return arr[mid];
            // peak is in increasing curve--eliminate left
            else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1])
                low = mid + 1;
            // peak is in decreasing curve--eliminate right
            else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1])
                high = mid - 1;
        }
        return -1;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    cout << "Peak element: " << PeakElement(arr, 10) << endl;
    return 0;
}