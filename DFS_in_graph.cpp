#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, bool> &visited, vector<int> &component, unordered_map<int, set<int>> &adjList, int i) {
    component.push_back(i);
    visited[i] = true;

    for(auto it: adjList[i]) {
        if(!visited[it])
            dfs(visited, component, adjList, it);
    }
}
vector<vector<int>> DFS(int vertex, vector<pair<int, int>> &edges) {
    
    unordered_map<int, set<int>> adjList;
    unordered_map<int, bool> visited;

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    vector<vector<int>> ans;

    for(int i = 0; i < vertex; i++) {
        if(!visited[i]) {
            vector<int> component;
            dfs(visited, component, adjList, i);
            ans.push_back(component);
        }
    }
    return ans;

}
int main(){
    vector<pair<int, int>> edges({{9,7},{0,1},{0,2},{0,5},{3,6},{7,4},{4,8},{7,8}});
    int vertex;
    vector<vector<int>> ans = DFS(10, edges);
    for(auto i: ans) {
        for(auto j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}