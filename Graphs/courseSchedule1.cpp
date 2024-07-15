#include <bits/stdc++.h>
using namespace std;

bool isPossible(int n, vector<vector<int>> &prerequisites)
{
    // create adjacency list
    vector<vector<int>> adjList(n);
    for (auto it : prerequisites)
    {
        adjList[it[1]].push_back(it[0]);
    }

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

    // to check if theres no cycle
    if (ans.size() == n)
        return true;
    else
        return false;
}

int main()
{
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}, {0, 3}};
    if (isPossible(4, prerequisites))
        cout << "Course schedule possible" << endl;
    else
        cout << "Course schedule not possible" << endl;
    return 0;
}