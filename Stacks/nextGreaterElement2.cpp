#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> findNextGreater(vector<int> &nums)
{
    int n = nums.size();
    stack<int> s;
    vector<int> ans(n, -1); 

    for (int i = n - 1; i >= 0; i--)
    {

        while (!s.empty() && s.top() <= nums[i])
        {
            s.pop();
        }
        
        if (!s.empty())
        {
            ans[i] = s.top();
        }

        s.push(nums[i]);
    }

    return ans;
}


int main()
{
    vector<int>nums = {2,10,12,1,11};
    vector<int>ans = findNextGreater(nums);
    for(int i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}