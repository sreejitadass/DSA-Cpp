#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class DisjointSet{
    vector<int>parent;
    vector<int>size;
public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
        size.resize(n+1,1);
    }

    int findUltimateParent(int node)
    {
        if(node==parent[node])
            return node;
        //path compression
        return parent[node] = findUltimateParent(parent[node]);
    }


    void unionBySize(int u,int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        //if they belong to same component
        if(pu==pv)
            return;
        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

void kruskalsAlgo(int n, vector<vector<int>>&edges)
{
    vector<pair<int, pair<int, int>>>edgesList;
    //{w,{u,v}}
    for(auto it: edges)
    {
        int node=it[0];
        int adjNode=it[1];
        int wt=it[2];

        edgesList.push_back({wt,{node,adjNode}});
    }

    vector<vector<int>>MST;
    int mstWt=0;
    DisjointSet ds(n);

    sort(edgesList.begin(),edgesList.end());
    for(auto it: edgesList)
    {
        int w=it.first;
        int u=it.second.first;
        int v=it.second.second;
        //check if they are in same CC
        if(ds.findUltimateParent(u)!=ds.findUltimateParent(v))
        {
            ds.unionBySize(u,v);
            mstWt+=w;
            MST.push_back({u,v});
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
    cout<<"\nSum of the MST: "<<mstWt<<endl;
}

int main()
{
    vector<vector<int>>edges = {{4,1,1},{4,5,9},{5,1,4},{4,3,5},{3,6,8},{2,6,7},{1,2,2},{2,3,3},{4,2,3}};
    int n=6;
    kruskalsAlgo(n,edges);
    return 0;
}