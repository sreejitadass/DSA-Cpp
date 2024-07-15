//{first,last}={lb(x),ub(x)-1}-->if element exists in array

#include <iostream>
#include <bits/stdc++.h>
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
    return ans;
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
    return ans;
}

pair<int, int> firstLastOccurences(int arr[], int n, int x)
{
    int lb = lower_bound(arr, n, x);
    int ub = upper_bound(arr, n, x);
    if (arr[lb] != x || lb == n) // lb=x if x is in arr
        return {-1, -1};
    else
        return {lb, ub - 1};
}

int main()
{
    int arr[] = {1, 2, 5, 6, 7, 7, 7, 7, 8, 9, 11};
    pair<int, int> result = firstLastOccurences(arr, 11, 7);
    cout << "First occurrence: " << result.first << endl
         << "Last occurrence: " << result.second << endl;
    return 0;
}