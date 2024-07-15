#include<iostream>
#include<vector>
#include<utility>
#include<queue>
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
    //cout << "Graph stored" << endl;
}

int countShortestPathWays(int n, vector<vector<int>>&roads)
{
    int m=roads.size();
    vector<pair<int, int>> adjList[n];
    storeGraph(n,m,roads,adjList);

    vector<int>ways(n,0);
    vector<int>dist(n,1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //source = 0, destination = n-1
    ways[0]=1;
    dist[0]=0;
    pq.push({0,0});     //{dist,node}

    while(!pq.empty())
    {
        auto it = pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();

        for(auto it: adjList[node])
        {
            int adjNode = it.first;
            int wt = it.second;

            //first time encountering the node
            if(dis+wt < dist[adjNode])
            {
                dist[adjNode]=dis+wt;
                pq.push({dis+wt,adjNode});
                ways[adjNode]=ways[node];       //have to increase the ways by number of ways the parent is reached
            }

            //again encountering the node with same distance,dont push to pq
            else if(dis+wt==dist[adjNode])
            {
                ways[adjNode]+= ways[node];
            }
        }
    }
    return ways[n-1];
}

int main()
{
    int n=9;
    vector<vector<int>>roads = {{0,1,1},{0,2,2},{0,3,1},{0,4,2},{1,5,2},{2,5,1},{3,5,2},{3,7,3},{3,6,2},{4,6,1},{6,8,1},{7,8,1},{5,8,1}};
    cout<<"All possible shortest paths: "<<countShortestPathWays(n,roads)<<endl;
    return 0;
}