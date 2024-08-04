#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int>findNumberOfNGEs(vector<int>&arr, vector<int>&indices)
{
    vector<int>ans(indices.size(),0);
    for(int i = 0;i<indices.size();i++)
    {
        int idx = indices[i];
        int cnt = 0;
        for(int j = idx+1; j<arr.size();j++)
        {
            if(arr[j] > arr[idx])
            {
                cnt++;
            }
            ans[i] = cnt;
        }
    }
    return ans;
}

int main()
{
    vector<int>arr={1,2,3,4,1};
    vector<int>indices={0,3};
    vector<int>ans = findNumberOfNGEs(arr,indices);
    for(int i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}