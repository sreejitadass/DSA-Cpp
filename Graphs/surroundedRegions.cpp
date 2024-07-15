#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int n, int m, vector<vector<int>> &vis, vector<vector<char>> &board)
{
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    vis[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int nrow = i + delRow[k];
        int ncol = j + delCol[k];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && !vis[nrow][ncol])
        {
            dfs(nrow, ncol, n, m, vis, board);
        }
    }
}

vector<vector<char>> convertOtoX(vector<vector<char>> &board)
{
    int n = board.size(), m = board[0].size();
    vector<vector<int>> vis(n, (vector<int>(m, 0)));

    // Boundary conditions
    for (int j = 0; j < m; j++)
    {
        // first row
        if (!vis[0][j] && board[0][j] == 'O')
            dfs(0, j, n, m, vis, board);
        // last row
        if (!vis[n - 1][j] && board[n - 1][j] == 'O')
            dfs(n - 1, j, n, m, vis, board);
    }
    for (int i = 0; i < n; i++)
    {
        // first column
        if (!vis[i][0] && board[i][0] == 'O')
            dfs(i, 0, n, m, vis, board);
        // last column
        if (!vis[i][m - 1] && board[i][m - 1] == 'O')
            dfs(i, m - 1, n, m, vis, board);
    }

    // Within boundary conditions
    // Once all boundary O's are marked, the O's inside will be X
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
    return board;
}

int main()
{
    vector<vector<char>> board = {{'X', 'O', 'X'},
                                  {'X', 'O', 'X'},
                                  {'X', 'O', 'X'}};
    vector<vector<char>> output = convertOtoX(board);
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}