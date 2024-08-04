#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> findPreviousSmaller(vector<int>&nums)
{
    int n = nums.size();
    vector<int>ans(n,0);
    stack<int>s;
    s.push(-1);

    for(int i = 0;i<n;i++)
    {
        while(!s.empty() && s.top() >= nums[i])
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(nums[i]);
    } 
    return ans;
}

int main()
{
    vector<int>nums = {4,5,2,10,8};
    vector<int>ans = findPreviousSmaller(nums);
    for(int i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}