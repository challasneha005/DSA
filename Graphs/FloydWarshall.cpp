// FLOYD WARSHALL ALGORITHM O(V*V*V) , O(V*V)
#include<bits/stdc++.h>
using namespace std;
void floydWarshall(int V,vector<vector<int>> &mat){
    int n = V;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == -1)
                mat[i][j] = 1e9;
            if(i == j)
                mat[i][j] = 0;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = min(mat[i][j] ,mat[i][k] + mat[k][j]);
            }
        }
    }
    //negaive cycle
    for(int i=0;i<n;i++){
        if(mat[i][i] <0)
            cout << "Negative cycle";
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == 1e9)
                mat[i][j] = -1;
        }
    }
    cout << "All-pairs shortest paths:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    int V, E;
    cin >> V >> E; // nodes, edges
    vector<vector<int>> mat(V, vector<int>(V, -1));
    // Take edges input
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mat[u][v] = w; // directed edge u -> v with weight w
    }
    floydWarshall(V, mat);
    return 0;
}
// 4 6
// 0 1 2
// 1 0 1
// 1 2 3
// 3 1 5
// 3 2 4
// 3 0 3 