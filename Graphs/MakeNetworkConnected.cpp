// NO.OF OPERATIONS TO MAKE NETWORK CONNECTED O(E α(N) + N) ≈ O(E + N) , O(2N)
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
    int makeConnected(int n,vector<vector<int>> edges){
        DisjointSet ds(n);
        int cntExtras = 0;
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            if(ds.findUpar(u) == ds.findUpar(v))
                cntExtras++;
            else
                ds.unionBySize(u,v); 
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(ds.findUpar(i) == i)
                cnt++;
        }
        int ans = cnt -1;
        if(cntExtras == ans)
            return ans;
        return -1;
    }
};
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> edges;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    Solution sol;
    cout << "Minimum operations to connect network = "
         << sol.makeConnected(V, edges) << "\n";
    return 0;
}
// 8 8 nodes edges
// 0 1
// 0 3
// 0 2
// 1 2
// 2 3
// 4 5
// 5 6
// 7 8