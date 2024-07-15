#include <bits/stdc++.h>
using namespace std;

// Memoization
int maxPoints_memo(int day, int last, vector<vector<int>> &task, vector<vector<int>> &dp)
{
    if (dp[day][last] != -1)
        return dp[day][last];

    // base case
    if (day == 0)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, task[0][i]);
        }
        return dp[day][last] = maxi;
    }

    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        int points = 0;
        if (i != last)
        {
            points = task[day][i] + maxPoints_memo(day - 1, i, task, dp);
            maxi = max(maxi, points);
        }
    }
    return dp[day][last] = maxi;
}

// Tabulation
int maxPoints_tab(int day, int last, vector<vector<int>> &task, vector<vector<int>> &dp)
{
}

// SC optimized tabulation
int maxPoints_tab1(int day, int last, vector<vector<int>> &task, vector<int> &dpArr)
{
}

int main()
{
    int day = 2;
    vector<vector<int>> dp(day, vector<int>(4, -1));
    vector<int> dpArr(4, 0);
    vector<vector<int>> task = {{10, 5, 1}, {5, 100, 11}};
    cout << "Maximum points obtained (memoization): " << maxPoints_memo(day - 1, 3, task, dp) << endl;
    // cout << "Maximum points obtained (tabulation): " << maxPoints_tab(day - 1, 3, task, dp) << endl;
    //  cout << "Maximum points obtained (space complexity optimized): " << maxPoints_tab1(day - 1, 3, task, dpArr) << endl;
    return 0;
}