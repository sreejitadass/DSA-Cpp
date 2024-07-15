// generate Pascals triangle
#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int numRow)
{
    int ans = 1;
    vector<int> temp;
    temp.push_back(1);
    for (int i = 1; i < numRow; i++)
    {
        ans *= (numRow - i);
        ans /= i;
        temp.push_back(ans);
    }
    return temp;
}

vector<vector<int>> generateTriangle(int numRow)
{
    vector<int> temp;
    vector<vector<int>> ans;
    for (int i = 1; i <= numRow; i++)
    {
        temp = generateRow(i);
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    vector<vector<int>> ans = generateTriangle(6);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}