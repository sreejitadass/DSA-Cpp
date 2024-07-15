#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

void storeGraph(int n, int m, vector<vector<int>> &edges, vector<pair<int, int>> adjList[])
{
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];
        adjList[u].push_back({v, w}); // start->{end,weight}
        adjList[v].push_back({u, w});
    }
    cout << "Graph stored" << endl;
}

void primsAlgo(int n,vector<vector<int>>&edges)
{
    int m=edges.size();
    vector<pair<int,int>>adjList[n];
    storeGraph(n,m,edges,adjList);

    vector<int>vis(n,0);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0,0,-1});     //{dist,node,parent}

    vector<vector<int>>MST;
    int sum=0;
    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int parent = it[2];
        int node = it[1];
        int dis = it[0];

        //if already visited
        if(vis[node]==1)
            continue;
        //if not visited
        vis[node]=1;
        //skip for initial node push
        if(parent!=-1)
        {
            sum+=dis;
            MST.push_back({node,parent});
        }

        for(auto it: adjList[node])
        {
            int adjNode = it.first;
            int wt = it.second;

            //dont mark as visited - only mark after all its connected edges are traversed
            if(!vis[adjNode])
                pq.push({wt,adjNode,node});
        }
    }
    cout<<"\nMST edges: "<<endl;
    for(auto it: MST)
    {
        for(int i: it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<"\nSum of the MST: "<<sum<<endl;
}

int main()
{
    int n=5;
    vector<vector<int>>edges={{0,1,2},{0,2,1},{2,1,1},{2,4,2},{4,3,1},{2,3,2}};
    primsAlgo(n,edges);
    return 0;
}