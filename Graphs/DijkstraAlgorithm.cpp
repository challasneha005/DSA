//DIJKSTRA ALGORITHM 
#include<bits/stdc++.h>
using namespace std;
//PRIORITY QUEUE O(V+E log V) , O(V+E)
vector<int> dijkstrapq(int V,vector<vector<int>> a[],int src){
    priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> pq;
    vector<int> dist(V);
    for(int i=0;i<V;i++)
        dist[i] = 1e9;
    dist[src] = 0;
    pq.push({0,src});
    while (!pq.empty()){
        int distNode = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it: a[node]){
            int edgeWeight = it[1];
            int aNode = it[0];
            if(distNode + edgeWeight < dist[aNode]){
                dist[aNode] = distNode + edgeWeight;
                pq.push({dist[aNode],aNode});
            }
        }
    }
    return dist;
}
//SET O(V+E log V) , O(V+E)
vector<int> dijkstraSet(int V,vector<vector<int>> a[],int src){
    set<pair<int,int>> s;
    vector<int> dist(V,1e9);
    s.insert({0,src});
    dist[src] = 0;
    while(!s.empty()){
        auto it = *(s.begin());
        int node = it.second;
        int distNode = it.first;
        s.erase(it);
        for(auto it:a[node]){
            int aNode = it[0];
            int edgeWeight = it[1];
            if(distNode+edgeWeight < dist[aNode]){
                if(dist[aNode]!= 1e9)
                    s.erase({dist[aNode],aNode});
                dist[aNode] = distNode+edgeWeight;
                s.insert({dist[aNode],aNode});
            }
        }
    }
    return dist;
}
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> adj[V];
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});   // directed edge
        adj[v].push_back({u, w});   // remove this line if graph is directed
    }
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    // vector<int> dist = dijkstrapq(V, adj, src);
    vector<int> dist = dijkstraSet(V, adj, src);
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << dist[i] << "\n";
    }
    return 0;
}

// 5 6
// 0 1 2
// 0 2 4
// 1 2 1
// 1 3 7
// 2 4 3
// 3 4 1
// 0
