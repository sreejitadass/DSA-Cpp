#include<iostream>
#include<vector>
#include<utility>
#include<unordered_map>
#include<algorithm>
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

vector<vector<string>> mergeAccounts(vector<vector<string>>&accounts)
{
    int n=accounts.size();
    DisjointSet ds(n);
    unordered_map<string,int>mapEmailNode;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<accounts[i].size();j++)
        {
            string mail = accounts[i][j];
            if(mapEmailNode.find(mail)==mapEmailNode.end())
            {
                mapEmailNode[mail]=i;
            }
            else
            {
                ds.unionBySize(i,mapEmailNode[mail]);
            }
        }
    }

    vector<vector<string>>mergedMail(n);
    for(auto it: mapEmailNode)
    {
        string mail = it.first;
        int node = ds.findUltimateParent(it.second);
        mergedMail[node].push_back(mail);
    }

    vector<vector<string>>ans;
    for(int i=0;i<n;i++)
    {
        if(mergedMail[i].size()==0) continue;
        sort(mergedMail[i].begin(),mergedMail[i].end());
        vector<string>temp;
        temp.push_back(accounts[i][0]);

        for(auto it: mergedMail[i])
        {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    vector<vector<string>> accounts =       {{"John", "j1@com", "j2@com", "j3@com"},
                                            {"John", "j4@com"},
                                            {"Raj", "r1@com", "r2@com"},
                                            {"John", "j1@com", "j5@com"},
                                            {"Raj", "r2@com", "r3@com"},
                                            {"Mary", "m1@com"}
                                        };
    vector<vector<string>>ans=mergeAccounts(accounts);
    cout<<"Merged accounts: "<<endl;
    for(auto it: ans)
    {
        for(auto i: it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}