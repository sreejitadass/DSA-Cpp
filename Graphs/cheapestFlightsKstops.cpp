#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void storeGraph(int n, int m, vector<pair<int, int>> adjList[], vector<vector<int>> &flights)
{
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        u = flights[i][0];
        v = flights[i][1];
        w = flights[i][2];
        adjList[u].push_back({v, w}); // start->{end,weight}
    }
    cout << "Graph stored" << endl;
}

int findCheapestFlights(int n, vector<vector<int>> &flights, vector<pair<int, int>> adjList[], int src, int dst, int k)
{
    vector<int> dist(n, 1e9);
    queue<vector<int>> q;
    q.push({0, src, 0}); // {stops, node, cost}
    dist[src] = 0;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it[0];
        int node = it[1];
        int cost = it[2];

        if (stops > k)
            continue;

        for (auto adj : adjList[node])
        {
            int adjNode = adj.first;
            int wt = adj.second;

            if (cost + wt < dist[adjNode])
            {
                dist[adjNode] = cost + wt;
                q.push({stops + 1, adjNode, dist[adjNode]});
            }
        }
    }

    return dist[dst] == 1e9 ? -1 : dist[dst];
}

int main()
{
    int m = 6, n = 5;
    vector<vector<int>> flights = {{0, 3, 2}, {0, 1, 5}, {1, 2, 5}, {2, 4, 1}, {1, 4, 1}, {4, 2, 1}};
    vector<pair<int, int>> adjList[n];

    storeGraph(n, m, adjList, flights);

    cout << "Cost of cheapest flight: " << findCheapestFlights(n, flights, adjList, 0, 2, 3) << endl;
    return 0;
}
