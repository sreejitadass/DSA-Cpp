#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int> &arr)
{
    int i, j, k;
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum > 0)
                k--;
            else if (sum < 0)
                j++;
            else
            {
                vector<int> temp = {arr[i],
                                    arr[j],
                                    arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (arr[j] == arr[j - 1])
                    j++;
                while (arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1, 0, 2, -1, 1, 2, 2, 0, 1};
    vector<vector<int>> ans = findTriplets(nums);
    cout << "Unique triplets: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}