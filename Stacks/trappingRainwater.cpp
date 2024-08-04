#include<iostream>
#include<vector>
using namespace std;

vector<int>findPrefixSum(vector<int>&heights)
{
    vector<int>prefix(heights.size(),0);
    prefix[0]=heights[0];
    for(int i = 1;i<heights.size();i++)
    {
        prefix[i] = max(prefix[i-1],heights[i]);
    }
    return prefix;
}

vector<int>findSuffixSum(vector<int>&heights)
{
    int n = heights.size();
    vector<int>suffix(n,0);
    suffix[n-1]=heights[n-1];
    for(int i = n-2;i>=0;i--)
    {
        suffix[i] = max(suffix[i+1],heights[i]);
    }
    return suffix;
}

int findTrappedWater(vector<int>&heights)
{
    int totalWater = 0;
    vector<int>prefix = findPrefixSum(heights);
    vector<int>suffix = findSuffixSum(heights);

    for(int i = 0;i<heights.size();i++)
    {
        int leftMax = prefix[i],rightMax = suffix[i];
        if(heights[i]<leftMax && heights[i]<rightMax)
        {
            totalWater+=min(leftMax,rightMax)-heights[i];
        }
    }
    return totalWater;
}

int main()
{
    vector<int>heights={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<"Total rainwater: "<<findTrappedWater(heights)<<endl;
    return 0;
}