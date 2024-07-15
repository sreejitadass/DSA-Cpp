#include <bits/stdc++.h>
using namespace std;

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

string findAlienOrder(vector<string> &dict, int n, int k)
{
    // create DAG list from dictionary
    vector<int> adjList[k];
    for (int i = 0; i < dict.size() - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());
        for (int j = 0; j < len; j++)
        {
            if (s1[j] != s2[j])
            {
                // s1[j]-->s2[j]
                adjList[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }
    vector<int> ans = findTopoSort_Kahn(k, adjList);
    string ansOrder = "";
    for (auto i : ans)
    {
        ansOrder += char(i + 'a');
    }
    return ansOrder;
}

int main()
{
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    int n = dict.size();
    int k = 4; // a,b,c,d
    string ansOrder = findAlienOrder(dict, n, k);
    cout << "Alien ordering: " << ansOrder << endl;
    return 0;
}