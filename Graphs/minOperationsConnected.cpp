#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class DisjointSet{
public:
    vector<int>parent;
    vector<int>size;
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


int findMinOperations(int n, vector<vector<int>>&connections)
{
   DisjointSet ds(n);
   int extraEdges=0;
   for(auto it: connections)
   {
        int u = it[0],v=it[1];
        //if already connected,its an extra edge
        if(ds.findUltimateParent(u)==ds.findUltimateParent(v))
        {
            extraEdges++;
        }
        //if not connected, connect them
        else
        {
            ds.unionBySize(u,v);
        }
   }
   int noOfComponents=0;
   for(int i=0;i<n;i++)
   {
        //if parent and child is same, its a single component
        if(ds.parent[i]==i)
        {
            noOfComponents++;
        }
   } 
   
   int ans = noOfComponents-1;
   if(extraEdges>=ans)
        return ans;
    else
        return -1;
}

int main()
{
    vector<vector<int>>connections={{1,2},{1,0},{2,3},{0,2},{0,3},{4,5},{5,6},{7,8}};
    int n=9;
    cout<<"Minimum operations = "<<findMinOperations(n,connections)<<endl;
    return 0;
}