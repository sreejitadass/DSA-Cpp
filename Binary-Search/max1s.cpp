#include <iostream>
#include <vector>
using namespace std;

/*
1)Traverse each row
2)For i-th row, calculate lb(1)-->index of 1 in that row/array
3)Calculate number of 1s--> m-lb(1)
4)Find max for all rows

TC: O(nlogm)
*/

int lower_bound(vector<int> &arr, int n, int x)
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

int rowWithMax1s(vector<vector<int>> &mat, int n, int m)
{
    int max_1 = -1, index = -1;
    for (int i = 0; i < n; i++)
    {
        int index_1 = lower_bound(mat[i], m, 1);
        int num_1 = m - index_1;
        if (num_1 > max_1)
        {
            max_1 = num_1;
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> mat = {{0, 0, 1, 1, 1}, {0, 0, 0, 0, 0}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {0, 1, 1, 1, 1}};
    cout << "Row index with maximum 1s: " << rowWithMax1s(mat, 5, 5) << endl;
    return 0;
}