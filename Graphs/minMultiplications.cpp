#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

int findMinMultiplications(int start,int end,vector<int>&arr)
{
    vector<int>dist(100000,1e9);
    dist[start]=0;

    queue<pair<int, int>> q;
    q.push({start,0});  //{node,steps}

    int mod = 100000;
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();

        int node = it.first;
        int steps = it.second;

        for(auto it: arr)
        {
            int newStart = (node*it)%mod;

            if(steps+1<dist[newStart])
            {
                dist[newStart]=steps+1;
                //if end is reached
                if(newStart==end)
                {
                    return steps+1;
                }
                q.push({newStart,steps+1});
            }
        }
    }
    return -1;
}

int main()
{
    int start = 7,end= 66175;
    vector<int>arr = {3,4,65};
    cout<<"Minimum number of multiplications; "<<findMinMultiplications(start,end,arr)<<endl;
    return 0;
}