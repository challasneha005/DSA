//BELLMAN FORD ALGORITHM O(V * E) , O(V)
#include<bits/stdc++.h>
using namespace std;
vector<int> bellman(int V,vector<vector<int>> &edges,int s){
    vector<int> dist(V,1e8);
    dist[s] = 0;
    for(int i=0;i<V-1;i++){
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt<dist[v])
                dist[v] = dist[u] + wt;
        }
    }
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt<dist[v])
            return {-1};     
    }
    return dist;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges(E, vector<int>(3));
    for (int i = 0; i < E; i++) 
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    int src;
    cin >> src;
    vector<int> res = bellman(V, edges, src);
    if (res.size() == 1 && res[0] == -1) 
        cout << "Negative weight cycle detected\n";
    else {
        for (int i = 0; i < V; i++)
            cout << "Dist from " << src << " to " << i << " = " << res[i] << "\n";
    }
    return 0;
}
// 6 7
// 3 2 6
// 5 3 1
// 0 1 5
// 1 5 -3
// 1 2 -2
// 3 4 -2
// 2 4 3
// 0