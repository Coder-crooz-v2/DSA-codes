#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &visited, stack<int> &topo) {
    visited[node] = true;
    for(auto neighbour : adj[node]) {
        if(!visited[neighbour.first]) {
            dfs(neighbour.first, adj, visited, topo);
        }
    }
    topo.push(node);
}

vector<int> shortestPath(int source, vector<vector<pair<int, int>>> &adj, stack<int> &topo, vector<int> &dist) {
    dist[source] = 0;

    while(!topo.empty()) {
        int node = topo.top();
        topo.pop();

        if(dist[node] != INT_MAX) {
            for(auto neighbour : adj[node]) {
                if(dist[neighbour.first] > dist[node] + neighbour.second) {
                    dist[neighbour.first] = dist[node] + neighbour.second;
                }
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    int source;
    cin >> source;

    vector<bool> visited(n, false);
    stack<int> topo;
    for(int i = 0; i < n; i++) {
        if(!visited[i])
            dfs(i, adj, visited, topo);
    }

    vector<int> dist(n, INT_MAX);
    vector<int> answer = shortestPath(source, adj, topo, dist);

    for(int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}