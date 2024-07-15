#include <bits/stdc++.h>
using namespace std;

// Fibonacci sequence--> 0 1 1 2 3 5 8 ...

//  Memoization
int findFibonacci_memo(int n, vector<int> &dp)
{
    if (n <= 1) // base case
        return n;
    if (dp[n] != -1) // already stored SP
        return dp[n];
    else
        return dp[n] = findFibonacci_memo(n - 1, dp) + findFibonacci_memo(n - 2, dp); // storing new SP
}

// SC optimized tabulation
int findFibonacci_tab(int n)
{
    if (n == 0 || n == 1)
        return n;
    int prev1 = 0, prev2 = 1, curr = 0;
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return curr;
}

int main()
{
    int n = 7;
    vector<int> dp(n + 1, -1);
    cout << "Value = " << findFibonacci_tab(n) << endl;
    return 0;
}