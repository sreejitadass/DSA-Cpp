#include<iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findNextGreater(vector<int> &nums) {
    stack<int>s;
    int n = nums.size();
    vector<int>nge(n,-1);

    for(int i = n-1; i>=0; i--)
    {
        while(!s.empty() && s.top() <= nums[i])
        {
            s.pop();
        }
        if(!s.empty())
            nge[i] = s.top();
        s.push(nums[i]);
    }
    return nge;
}


int main()
{
    vector<int>nums = {6,0,8,1,3};
    vector<int>ans = findNextGreater(nums);
    for(int i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}