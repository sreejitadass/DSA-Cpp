#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> findNextGreaterArray(vector<int> &nums) {
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

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> NGEnums2 = findNextGreaterArray(nums2);

    unordered_map<int,int>mpp;
    for(int i = 0;i<nums2.size();i++)
    {
        mpp[nums2[i]] = NGEnums2[i];
    }
    vector<int>ans;
    for(int i = 0;i<nums1.size();i++)
    {
        ans.push_back(mpp[nums1[i]]); 
    }
    return ans;
}

int main()
{
    vector<int>nums1 = {4,1,2};
    vector<int>nums2 = {1,3,4,2};
    vector<int>ans = nextGreaterElement(nums1, nums2);
    for(int i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}