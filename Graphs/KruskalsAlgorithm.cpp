// KRUSKALS ALGORITHM O(E log E), O(E+V)
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank,size,parent;
public:
    DisjointSet(int n){
        size.resize(n+1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUpar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }
    void unionByRank(int u,int v){
        int pu = findUpar(u);
        int pv = findUpar(v);
        if(pu == pv )
            return;
        if(rank[pu] < rank[pv])
            parent[pu] = pv;
        else if(rank[pv] < rank[pu])
            parent[pv] = pu;
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void unionBySize(int u,int v){
        int pu = findUpar(u);
        int pv = findUpar(v);
        if(pu == pv )
            return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class  Solution{
public:
    int kruskal(int V,vector<vector<int>> a[]){
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:a[i]){
                int aNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt,{node,aNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mstwt = 0;
        for(auto it:edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findUpar(u)!= ds.findUpar(v)){
                mstwt += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstwt;
    }
};
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> adj[V];
    cout << "Enter edges (u v w):\n";
    for(int i=0;i<E;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});  // undirected
    }
    Solution sol;
    cout << "Weight of MST = " << sol.kruskal(V, adj) << "\n";
    return 0;
}
// 6 9
// 0 3 1
// 0 1 2
// 1 5 7
// 1 2 3
// 2 5 8
// 2 3 5
// 1 3 3
// 3 4 9
// 0 4 4
 
 