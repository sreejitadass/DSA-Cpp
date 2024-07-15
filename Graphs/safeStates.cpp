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

vector<int> findEventualSafeStates(int n, vector<int> adjList[])
{
    vector<int> indegree(n, 0);
    vector<int> adjRev[n];
    for (int i = 0; i < n; i++)
    {
        for (auto it : adjList[i])
        {
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adjRev[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n = 7, m = 7;
    vector<int> adjList[n];
    storeGraph(adjList, n, m);
    vector<int> ans = findEventualSafeStates(n, adjList);
    cout << "Safe states: ";
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}