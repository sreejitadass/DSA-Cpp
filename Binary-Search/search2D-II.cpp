#include <iostream>
#include <vector>
using namespace std;

// unsorted matrix(Only indivual r & c is sorted)
pair<int, int> Search2DMatrix(vector<vector<int>> &mat, int n, int m, int x)
{
    int r = 0, c = m - 1;
    pair<int, int> ans = {-1, -1};
    while (r < n && c >= 0)
    {
        if (mat[r][c] == x)
            return {r, c};
        else if (mat[r][c] < x)
            r++;
        else
            c--;
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 2, 4},
                               {3, 5, 9, 12},
                               {10, 16, 28, 34}};
    pair<int, int> result = Search2DMatrix(mat, 3, 4, 4);
    cout << "Element found at: (" << result.first << "," << result.second << ")" << endl;
    return 0;
}