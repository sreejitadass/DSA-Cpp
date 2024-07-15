#include<iostream>
#include<vector>
#include<utility>
using namespace std;

vector<int> findShortestDistance(int n,vector<vector<int>>&edges)
{
    vector<int>dist(n,1e9);
    dist[0]=0;

    for(int i=0;i<n-1;i++)
    {
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];

            //edge relaxation
            if(dist[u]!=1e9 && dist[u]+w<dist[v])
            {
                dist[v] = dist[u]+w;
            }        
        }
    }

    //check for negative cycles-nth relaxation
    for(auto it: edges)
    {
        int u=it[0];
        int v=it[1];
        int w=it[2];

        //if further edge relaxation occurs, its a cycle
        if(dist[u]!=1e9 && dist[u]+w<dist[v])
        {
            return {-1};
        }       
    }
    return dist;
}

int main()
{
    vector<vector<int>>edges = {{3,2,6},{5,3,1},{0,1,5},{1,5,-3},{1,2,-2},{3,4,-2},{2,4,3}};
    int n=6;
    vector<int>ans = findShortestDistance(n,edges);
    cout<<"Shortest distances: ";
    for(int i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}