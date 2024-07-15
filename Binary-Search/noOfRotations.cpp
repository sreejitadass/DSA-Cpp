#include <iostream>
#include <climits>
using namespace std;

// no of rotations=index of min element in array
int noOfRotations(int arr[], int n)
{
    int low = 0, high = n - 1, ans = INT32_MAX, index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // identify the sorted half and check for target there
        // find min from sorted half
        if (arr[mid] >= arr[low]) // left is sorted
        {
            if (ans > arr[low])
            {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        else // right is sorted
        {
            high = mid - 1;
            if (ans > arr[mid])
            {
                ans = arr[mid];
                index = mid;
            }
        }
    }
    return index;
}

int main()
{
    int arr[] = {5, 6, 7, 1, 2, 3, 4};
    cout << "Number of rotations: " << noOfRotations(arr, 7) << endl;
    return 0;
}