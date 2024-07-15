#include <iostream>
using namespace std;

int ceil(int arr[], int n, int x)
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

int floor(int arr[], int n, int x)
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
}

int main()
{
    int arr[] = {3, 4, 4, 7, 8, 10};
    int n = 6;
    cout << "Floor of a number: " << floor(arr, n, 5) << endl;
    cout << "Ceil of a number: " << ceil(arr, n, 5) << endl;
    return 0;
}