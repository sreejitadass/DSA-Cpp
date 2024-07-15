#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Given-->D days as limit, find min capacity such that all packages are shipped by D days

int findMax(vector<int> &weights, int n)
{
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (weights[i] > max)
        {
            max = weights[i];
        }
    }
    return max;
}

int findSum(vector<int> &weights, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += weights[i];
    }
    return sum;
}

bool ifPossible(vector<int> &weights, int mid, int n, int days)
{
    int daysReq = 1, currLoad = 0;
    for (int i = 0; i < n; i++)
    {
        if (currLoad + weights[i] > mid)
        {
            daysReq++;
            currLoad = weights[i];
        }
        else
        {
            currLoad += weights[i];
        }
    }
    return (daysReq <= days);
}

int findMinCapacity(vector<int> &weights, int days)
{
    int n = weights.size();
    int low = findMax(weights, n), high = findSum(weights, n), ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (ifPossible(weights, mid, n, days))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = weights.size();
    int days = 5;
    cout << "Minimum capacity: " << findMinCapacity(weights, days) << endl;
    return 0;
}