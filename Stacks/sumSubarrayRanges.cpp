#include <iostream>
#include <vector>
#include <stack>
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

vector<int>findNextSmaller(vector<int>&nums)
{
    int n = nums.size();
    vector<int>ans(n,n);
    stack<int>s;

    for(int i = n-1; i>=0; i--)
    {
        while(!s.empty() && s.top() > nums[i])
        {
            s.pop();
        }
        if(!s.empty())
            ans[i] = s.top();
        s.push(nums[i]);
    }
    return ans;
}

vector<int> findNextGreater(vector<int>& nums) {
    int n = nums.size();
    stack<int> s;
    vector<int> ans(n, n); // Initialize with n (no next greater)

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() < nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            ans[i] = s.top();
        }
        s.push(nums[i]);
    }
    return ans;
}

vector<int> findPreviousGreater(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0); // Initialize with -1 (no previous greater)
    stack<int> s;
    s.push(-1);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() <= nums[i]) {
            s.pop();
        }
        if (!s.empty()) {
            ans[i] = s.top();
        }
        s.push(nums[i]);
    }
    return ans;
}

int findMinSum(vector<int>& nums) {
    int n = nums.size();
    int total = 0;
    vector<int> nse = findNextSmaller(nums);
    vector<int> pse = findPreviousSmaller(nums);

    for (int i = 0; i < n; i++) {
        int left = i - pse[i];
        int right = nse[i] - i;
        int contribution = (left * right);
        total += (contribution * nums[i]);
    }
    return total;
}

int findMaxSum(vector<int>& nums) {
    int n = nums.size();
    int total = 0;
    vector<int> nge = findNextGreater(nums);
    vector<int> pge = findPreviousGreater(nums);

    for (int i = 0; i < n; i++) {
        int left = i - pge[i];
        int right = nge[i] - i;
        int contribution = (left * right);
        total += (contribution * nums[i]);
    }
    return total;
}

int main() {
    vector<int> nums = {1, 3, 3};
    cout << "Range of subarray sum: " << findMaxSum(nums) - findMinSum(nums) << endl;
    return 0;
}
