#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int>rank;
    vector<int>parent;
    vector<int>size;
public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
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

    void unionByRank(int u,int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        //if they belong to same component
        if(pu==pv)
            return;
        if(rank[pu]<rank[pv])
            parent[pu]=pv;
        else if(rank[pv]<rank[pu])
            parent[pv]=pu;
        else
        {
            parent[pv]=pu;
            rank[pu]++;
        }
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

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    ds.unionBySize(3,7);

    if(ds.findUltimateParent(3)==ds.findUltimateParent(7))
        cout<<"Belong to same component"<<endl;
    else
        cout<<"Do not belong to same component"<<endl;
    return 0;
}