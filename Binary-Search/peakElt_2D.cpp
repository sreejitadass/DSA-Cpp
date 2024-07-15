#include <iostream>
#include <vector>
using namespace std;

/*
1)Find mid column and find max from that column
2)Return the row containing max in the mid column and check only in that row
3)For a column,max element will always be greater than top and bottom neighbours,
so only check left and right like 1D array
*/

// if its greater than its top,down,right and left neighbours

int findMaxRow(vector<vector<int>> &mat, int n, int col)
{
    int max = INT32_MIN, max_idx;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][col] > max)
        {
            max = mat[i][col];
            max_idx = i;
        }
    }
    return max_idx;
}

pair<int, int> peak2DMatrix(vector<vector<int>> &mat, int n, int m)
{
    int low = 0, high = m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int max_row = findMaxRow(mat, n, mid);
        int left = (mid - 1) >= 0 ? mat[max_row][mid - 1] : -1;
        int right = (mid + 1) < m ? mat[max_row][mid + 1] : -1;

        if (mat[max_row][mid] > left && mat[max_row][mid] > right)
            return {max_row, mid};
        else if (mat[max_row][mid] < left && mat[max_row][mid] > right)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> mat = {{4, 2, 5, 1, 4, 5},
                               {2, 9, 3, 2, 3, 2},
                               {1, 7, 6, 0, 1, 3},
                               {3, 6, 2, 3, 7, 2}};
    pair<int, int> result = peak2DMatrix(mat, 4, 6);
    cout << "Peak element found at: (" << result.first << "," << result.second << ")" << endl;
    return 0;
}