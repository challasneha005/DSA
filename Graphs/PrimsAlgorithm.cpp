//PRIMS ALGORITHM O(E log V) , O(V+E)
#include<bits/stdc++.h>
using namespace std;
int prim(int  V,vector<vector<int>> a[]){
    priority_queue <pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    vector<int> vis(V,0);
    pq.push({0,0});
    int sum = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if (vis[node]) 
            continue;
        vis[node] = 1;
        sum += wt;
        for(auto it:a[node]){
            int aNode = it[0];
            int edgeW = it[1];
        if(!vis[aNode])
            pq.push({edgeW,aNode});
        } 
    }
    return sum;
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> a[V];
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w}); // undirected graph
    }
    cout << prim(V, a) << endl;
    return 0;
}
// 5 6
// 0 1 2
// 1 2 3
// 1 3 6
// 1 3 8
// 1 4 5
// 4 2 7