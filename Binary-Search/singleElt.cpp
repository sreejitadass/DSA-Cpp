#include <iostream>
using namespace std;

/*if--
    (even,odd)-single elt is in right half,eliminate left half
    (odd,even)-single elt is in left half,eliminate right half
*/

int singleInSorted(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    // handle edge cases separately
    else if (arr[0] != arr[1])
        return arr[0];
    else if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];
    else
    {
        int low = 1, high = n - 2; // trim the array to exclude edge cases
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
                return arr[mid];

            // check if current index(mid) is even or odd
            else
            {
                if (mid % 2 == 1 && arr[mid] == arr[mid - 1] || mid % 2 == 0 && arr[mid] == arr[mid + 1]) //(even,odd)
                {
                    // eliminate left half
                    low = mid + 1;
                }
                else //(odd,even)
                {
                    // eliminate right half
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout << "Single element: " << singleInSorted(arr, 11) << endl;
    return 0;
}