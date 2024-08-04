#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int>findNextSmaller(vector<int>&nums)
{
    int n = nums.size();
    vector<int>ans(n,0);
    stack<int>s;
    s.push(-1);

    for(int i = n-1; i>=0; i--)
    {
        while(!s.empty() && s.top() > nums[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(nums[i]);
    }
    return ans;
}

int main()
{
    vector<int>nums = {2,1,4,3};
    vector<int>ans = findNextSmaller(nums);
    for(int i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}