#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int, vector<pair<int, int>>> adj;
    for(int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> distance(vertices);
    for(int i = 0; i < vertices; i++)
        distance[i] = INT_MAX;

    set<pair<int, int>> st;
    distance[source] = 0;
    st.insert({source, 0});

    while(!st.empty()) {
        auto top = *(st.begin());
        int topNode = top.first;
        int nodeDistance = top.second;
        st.erase(st.begin());

        for(auto neighbour: adj[topNode]) {
            if(nodeDistance + neighbour.second < distance[neighbour.first]) {
                auto record = st.find({neighbour.first, distance[neighbour.first]});
                if(record != st.end())
                    st.erase(record);
                distance[neighbour.first] = nodeDistance + neighbour.second;
                st.insert({neighbour.first, distance[neighbour.first]});
            }
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
    vector<int> result = dijkstra(vec, vertices, edges, source);
    for(int i = 0; i < vertices; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}