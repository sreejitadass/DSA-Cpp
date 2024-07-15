#include <bits/stdc++.h>
using namespace std;

// TC and SC:O(n1+n2)
vector<int> findUnion(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> res;
    int i = 0, j = 0, n1 = arr1.size(), n2 = arr2.size();
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (res.empty() || res.back() != arr1[i])
                res.push_back(arr1[i]);
            i++;
        }
        else
        {
            if (res.empty() || res.back() != arr2[j])
                res.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n1)
    {
        if (res.back() != arr1[i])
            res.push_back(arr1[i]);
        i++;
    }
    while (j < n2)
    {
        if (res.back() != arr2[j])
            res.push_back(arr2[j]);
        j++;
    }
    return res;
}

vector<int> findIntersection(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> res;
    int i = 0, j = 0, n1 = arr1.size(), n2 = arr2.size();
    while (i < n1 && j < n2)
    {
        if (arr1[i] == arr2[j])
        {
            res.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return res;
}

int main()
{
    vector<int> arr1 = {1, 1, 2, 3, 4};
    vector<int> arr2 = {2, 2, 4, 5, 6, 7};
    vector<int> res = findIntersection(arr1, arr2);
    for (int i : res)
        cout << i << " ";
}