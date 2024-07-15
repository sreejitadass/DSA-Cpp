// lower bound-->smallest element greater than or equal to target(if elt exists,lb=element)
// upper bound-->smallest element greater than target(if elt exists,lb=next greater of that element)
// opposite of lower bound-->largest element smaller than target
#include <iostream>
using namespace std;

int lower_bound(int arr[], int n, int x)
{
    int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            // look for smaller index
            high = mid - 1;
            ans = mid;
        }
        else
            low = mid + 1;
    }
    return arr[ans];
}

int upper_bound(int arr[], int n, int x)
{
    int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x)
        {
            // look for smaller index
            high = mid - 1;
            ans = mid;
        }
        else
            low = mid + 1;
    }
    return arr[ans];
}

/*int opp_lower_bound(int arr[], int n, int x)
{
    int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x)
        {
            // look for larger index
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }
    return arr[ans];
}*/

int main()
{
    int arr[] = {-2, 3, 4, 6, 9, 12, 45};
    cout << "Lower bound: " << lower_bound(arr, 7, 13) << endl;
    cout << "Upper bound: " << upper_bound(arr, 7, 12) << endl;
    return 0;
}