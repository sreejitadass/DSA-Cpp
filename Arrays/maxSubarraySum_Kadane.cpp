#include <bits/stdc++.h>
using namespace std;

vector<int> maxSubArraySum(vector<int> &arr)
{
    int sum = 0, maxS = INT_MIN, n = arr.size(), ansStart, ansEnd, start;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i; // starting a new subarray

        sum += arr[i];

        if (sum < 0) // reject negative sum and start sum = 0 for new subarray
            sum = 0;
        else
        {
            if (sum > maxS)
            {
                maxS = sum;
                ansStart = start;
                ansEnd = i;
            }
        }
    }
    return {maxS, ansStart, ansEnd};
}

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    vector<int> ans = maxSubArraySum(arr);
    cout << "Maximum sum: " << ans[0] << endl;
    cout << "Required subarray: ";
    for (int i = ans[1]; i <= ans[2]; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}