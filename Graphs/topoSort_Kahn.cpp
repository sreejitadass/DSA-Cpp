#include <bits/stdc++.h>
using namespace std;

void storeGraph(vector<int> adjList[], int n, int m)
{
    int u, v;
    cout << "Enter:  " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    cout << "Graph stored" << endl;
}

vector<int> findTopoSort_Kahn(int n, vector<int> adjList[])
{
    vector<int> indegree(n, 0);
    vector<int> ans;

    // finding indegree
    for (int i = 0; i < n; i++)
    {
        for (auto it : adjList[i])
        {
            indegree[it]++;
        }
    }

    // if indegree=0, push in queue
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // remove edges from those nodes and reduce indegree and repeat
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adjList[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return ans;
}

int main()
{
    int n = 6, m = 6;
    vector<int> adjList[n];
    storeGraph(adjList, n, m);
    vector<int> ans = findTopoSort_Kahn(n, adjList);
    cout << "\nTopological sort = ";
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}