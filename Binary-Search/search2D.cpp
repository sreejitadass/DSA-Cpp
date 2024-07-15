#include <iostream>
#include <vector>
using namespace std;

/*
1)Hypothetically flatten the 2D array and set low and high
2)Convert 1D index to 2D by formula:
    row--> 1D/m
    col-->1D%m          (n=#rows,m=#cols)
3)Check normally as 1D binary search
*/

pair<int, int> Search2DMatrix(vector<vector<int>> &mat, int n, int m, int x)
{
    int low = 0, high = (m * n) - 1;
    int r = -1, c = -1;
    pair<int, int> ans;
    ans.first = r;
    ans.second = c;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        r = mid / m;
        c = mid % m;
        if (mat[r][c] == x)
            return {r, c};
        else if (mat[r][c] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 2, 4},
                               {6, 8, 9, 12},
                               {16, 26, 28, 34}};
    pair<int, int> result = Search2DMatrix(mat, 3, 4, 26);
    cout << "Element found at: (" << result.first << "," << result.second << ")" << endl;
    return 0;
}