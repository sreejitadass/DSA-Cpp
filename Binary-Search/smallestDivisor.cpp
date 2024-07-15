#include <bits/stdc++.h>
using namespace std;

/*
find the smallest divisor that is <=threshold(the sum of divided elts<=threshold)
    min sum possible= n
*/

int sumOfDivisions(int arr[], int n, int x)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ceil((double)(arr[i]) / double(x));
    }
    return sum;
}

int findSmallestDivisor(int arr[], int n, int threshold)
{
    int low = 1, high = arr[n - 1], ans = -1;
    if (n > threshold)
        return -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (sumOfDivisions(arr, n, mid) <= threshold)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 5, 9};
    cout << "Smallest divisor: " << findSmallestDivisor(arr, 4, 7) << endl;
    return 0;
}