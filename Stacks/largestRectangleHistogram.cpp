#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>findNextSmaller(vector<int>&heights)
{
    int n = heights.size();
    vector<int>ans(n);
    stack<int>s;

    for(int i = n-1; i>=0; i--)
    {
        while(!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        if(s.empty())
            ans[i] = n;
        else
            ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> findPreviousSmaller(vector<int>&heights)
{
    int n = heights.size();
    vector<int>ans(n);
    stack<int>s;

    for(int i = 0;i<n;i++)
    {
        while(!s.empty() && heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        if(s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
        s.push(i);
    } 
    return ans;
}

int findLargestArea(vector<int>&heights)
{
    vector<int>nse = findNextSmaller(heights);
    vector<int>pse = findPreviousSmaller(heights);
    int maxi = 0;
    for(int i = 0;i<heights.size();i++)
    {
        maxi = max(maxi,heights[i]*(nse[i]-pse[i]-1));
    }
    return maxi;
}

int main()
{
    vector<int>heights = {2,1,5,6,2,3};
    cout<<"Largest area is: "<<findLargestArea(heights)<<endl;
    return 0;
}