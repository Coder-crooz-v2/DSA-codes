#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(vector<vector<int>>& edges, int n, int m, int source) {
    vector<int> distance(n, 1e9);
    distance[source] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if(distance[u] != 1e9 && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }
    for(int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        if(distance[u] != 1e9 && distance[u] + w < distance[v]) {
            cout << "Negative cycle detected" << endl;
            return {};
        }
    }
    return distance;
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<int>> vec(edges, vector<int>(3));
    for(int i = 0; i < edges; i++) {
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    }
    int source;
    cin >> source;
    vector<int> result = bellmanFord(vec, vertices, edges, source);
    for(int i = 0; i < vertices; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}