#include <iostream>
#include <vector>
using namespace std;

// k-->no of bananas per hour, h-->max limit of hours
// Find min value of k so that all bananas are eaten within h

int findMax(vector<int> &pile, int n)
{
    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pile[i] > max)
        {
            max = pile[i];
        }
    }
    return max;
}

bool isPossible(vector<int> &pile, int mid, int h, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ceil(double(pile[i]) / double(mid));
    }
    return sum <= h;
}

int findMinHours(vector<int> &pile, int h, int n)
{
    int low = 1, high = findMax(pile, n), ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(pile, mid, h, n))
        {
            // look for more minimum k
            ans = mid;
            high = mid - 1;
        }
        else
        {
            // if mid isnt possible, before mid is also not possible
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> pile = {3, 6, 7, 11};
    int n = pile.size();
    int h = 8;
    cout << "Minimum value: " << findMinHours(pile, h, n) << endl;
    return 0;
}