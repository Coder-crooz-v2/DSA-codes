#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>&adj,vector<bool>&visited,int pointer,vector<int>&parent)
{
    visited[pointer]=true;
    parent[pointer]=-1;
    queue<int>q;
    q.push(pointer);
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(auto child:adj[front])
        {
            if(!visited[child])
            {
                visited[child]=true;
                parent[child] = front;
                q.push(child);
            }
        }
    }
}
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){

    // Write your code here
    vector<vector<int>>adj(n+1);
    for(int i=0; i<edges.size(); ++i)
    {
        int x = edges[i].first;
        int y = edges[i].second;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }   
    vector<bool>visited(n+1, false);
    vector<int>parent(n+1,-1);
    solve(adj,visited,s,parent);
    vector<int>ans;
    int currentnode = t;
    while(currentnode!=-1)
    {
        ans.push_back(currentnode);
        currentnode = parent[currentnode];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n,m;
    cout<<"Enter"<<endl;
    cin>>n>>m;
    int s,t;
    cin>>s>>t;
    vector<pair<int,int>>edges;
    for(int i=0; i<m; ++i)
    {
        int x,y;
        cin>>x>>y;
        edges.push_back({x,y});
    }
    vector<int>ans = shortestPath(edges,n,m,s,t);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}