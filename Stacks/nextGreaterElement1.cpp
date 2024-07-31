#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int>mpp;  //(nums1 elt, index in nums2)

    for(int i = 0;i<nums1.size();i++)
    {
        for(int j = 0; j<nums2.size();j++)
        {
            if(nums1[i] == nums2[j])
            {
                mpp[nums1[i]] = j;
            }
        }
    }

    for (const auto& pair : mpp) {
        cout << pair.first << " -> " << pair.second << endl;
    }


    vector<int>ans(nums1.size(),0);

    for(auto it: mpp)
    {
        stack<int>s;
        s.push(-1);
        int n = it.second;
        for(int i = n; i>=0; i--)
        {
            while(!s.empty() && s.top() > nums2[i])
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(nums2[i]);
        }
    }
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