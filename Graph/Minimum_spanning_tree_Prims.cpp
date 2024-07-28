#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> graph;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({{u, v}, w});
    }

    unordered_map<int, vector<pair<int, int>>> adj;
    for(int i = 0; i < m; i++) {
        int u = graph[i].first.first;
        int v = graph[i].first.second;
        int w = graph[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> parent(n+1, -1);
    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    
    key[1] = 0;
    parent[1] = -1;
    for(int i = 1; i <= n; i++) {
        int mini = INT_MAX, u;
        for(int v = 1; v <= n; v++) {
            if(mst[v] == false && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }
        mst[u] = true;
        for(auto it: adj[u]) {
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && key[v] > w) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        cout<<parent[i]<<" "<<i<<" "<<key[i]<<endl;
    }
    return 0;
}