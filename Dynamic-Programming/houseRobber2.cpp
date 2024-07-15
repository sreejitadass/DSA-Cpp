#include <bits/stdc++.h>
using namespace std;

int findMaxSum_tab(vector<int> &arr)
{
    int prev1 = arr[0];
    int prev2 = 0;
    int curr = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick += prev2;
        int notpick = 0 + prev1;
        curr = max(pick, notpick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int houseRobber(vector<int> &arr)
{
    vector<int> temp1, temp2;
    vector<int> temp1 = arr, temp2 = arr;
    int n = arr.size();
    temp1.erase(temp1.begin()); // except 1st
    temp2.pop_back();           // except last
    return max(findMaxSum_tab(temp1), findMaxSum_tab(temp2));
}

int main()
{
    vector<int> arr = {1, 2, 3, 1};
    cout << "Required sum: " << houseRobber(arr) << endl;
    return 0;
}