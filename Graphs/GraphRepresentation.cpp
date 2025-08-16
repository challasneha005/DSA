//GRAPH REPRESENTATION
#include<bits/stdc++.h>
using namespace std;
int main(){
    // //using matrix O(n*n)
    // int n,m;
    // cin >> n >> m;
    // int a[n+1][m+1];
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         a[i][j] = 0;
    //     }
    // }
    // //undirected
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin >> u >> v;
    //     a[u][v] = 1;
    //     a[v][u] = 1;
    // }
    // //matrix print
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout <<a[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    //adj list O(2E)
    int n,m;
    cin >> n >> m;
    vector <int> adjList[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    } 
    // print adjacency list
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    return 0;
}
