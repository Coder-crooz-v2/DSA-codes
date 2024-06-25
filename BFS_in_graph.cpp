#include<bits/stdc++.h>
using namespace std;
vector<int> BFS(int vertex, vector<pair<int, int>> &edges) {
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
    for(int i = 0; i < vertex; i++) {
        if(!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()) {
                int frontNode = q.front();
                ans.push_back(frontNode);
                q.pop();
                for(auto i: adjList[frontNode]) {
                    if(!visited[i]) {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
    return ans;
}
int main(){
    vector<pair<int, int>> edges({{4,3},{0,1},{0,3},{1,3}});
    int vertex;
    vector<int> ans = BFS(4, edges);
    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
