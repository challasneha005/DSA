//DIJKSTRA ALGORITHM- SHORTEST PATH O(V+E log V)+O(n) , O(V+E)
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> shortestPathDijkstra(int n,int m,vector<vector<int>> &edges,int src){
    vector<pair<int,int>> a[n];
    for(auto it:edges){
        a[it[0]].push_back({it[1],it[2]});
        a[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> pq;
    vector<int> dist(n,1e9), parent(n);
    for(int i=0;i<n;i++)
        parent[i] = i;
    dist[src] = 0; 
    pq.push({0,src});
    while (!pq.empty()){
        int distNode = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it: a[node]){
            int edgeWeight = it.second;
            int adjNode = it.first;
            if(distNode + edgeWeight < dist[adjNode]){
                dist[adjNode] = distNode + edgeWeight;
                pq.push({dist[adjNode],adjNode});
                parent[adjNode] = node;
            }
        }
    }
    //for single dest allpaths not necessary
    vector<vector<int>> allPaths;
    for (int dest = 0; dest < n; dest++) {
        if (dist[dest] == 1e9) {
            allPaths.push_back({-1}); // unreachable
            continue;
        }
    vector<int> path;
    int node = dest;
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(src);
    reverse(path.begin(),path.end());
    allPaths.push_back(path);
    }
    return allPaths;
}   
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> adj;
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({u, v, w}); 
    } 
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    vector<vector<int>> paths = shortestPathDijkstra(V, E, adj, src);
    cout << "Shortest paths from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        if (paths[i].size() == 1 && paths[i][0] == -1) {
            cout << "Node " << i << ": Unreachable\n";
        } else {
            cout << "Node " << i << " (dist=" << paths[i].size()-1 << " edges): ";
            for (int node : paths[i]) cout << node << " ";
            cout << "\n";
        }
    }
    return 0;
}

// 5 6
// 0 1 2
// 0 3 1 
// 2 3 3
// 1 2 4
// 1 4 5
// 2 4 1
// 0
