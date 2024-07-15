#include <bits/stdc++.h>
using namespace std;

void rotateImage(vector<vector<int>> &A, int n)
{
    // transpose
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(A[i][j], A[j][i]);
        }
    }

    // reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse(A[i].begin(), A[i].end());
    }
}

int main()
{
    vector<vector<int>> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int n = A.size();
    rotateImage(A, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}