#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// m-->no of bouquets, k-->adjacent number of flowers
// make m bouquets with k adjacent flowers in each bouquet

pair<int, int> MaxMin(vector<int> &bloomDay, int n)
{
    int max = INT32_MIN, min = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] > max)
        {
            max = bloomDay[i];
        }
        else
        {
            min = bloomDay[i];
        }
    }
    return {max, min};
}

bool isPossible(vector<int> &bloomDay, int mid, int m, int k, int n)
{
    int cnt = 0, noOfB = 0;
    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] <= mid)
        {
            cnt++;
        }
        else
        {
            noOfB += cnt / k;
            cnt = 0;
        }
    }
    noOfB += cnt / k;
    if (noOfB >= m)
        return true;
    else
        return false;
}

int findMinDay(vector<int> &bloomDay, int m, int k, int n)
{
    if (m * k > n)
        return -1;

    pair<int, int> res = MaxMin(bloomDay, n);
    int low = res.second, high = res.first, ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(bloomDay, mid, m, k, n)) // look for more minimum days, eliminate right half
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            // if a day is not possible, days before it is also not possible,eliminate left half
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> bloomDay = {7, 7, 7, 7, 13, 11, 12, 7};
    int n = bloomDay.size();
    int m = 2, k = 3;
    cout << "Minimum days= " << findMinDay(bloomDay, m, k, n) << endl;
    return 0;
}