#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshall(vector<vector<int>>& edges, int n) {
    vector<vector<int>> matrix(n, vector<int> (n+1, 1e9));
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        matrix[u][v] = w;
    }

    //diagonal elements are zero as distance from a node to itself is zero
    for(int i = 0; i < n; i++)
        matrix[i][i] = 0;

    //calculation of distance from every node to every node via every node
    for(int via = 0; via < n; via++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
            }
        }
    }

    //negative cycle detection
    for(int i = 0; i < n; i++) {
        if(matrix[i][i] < 0) {
            cout << "Negative cycle detected" << endl;
            return {{}};
        }
    }
    return matrix;
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<int>> vec(edges, vector<int>(3));
    for(int i = 0; i < edges; i++) {
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    }
    vector<vector<int>> result = floydWarshall(vec, vertices);
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
        