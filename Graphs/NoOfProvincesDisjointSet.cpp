// NO.OF PROVINCES DISJOINT SET O(n*n + V) , O(2n) 
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
    int numProvinces(int V,vector<vector<int>> a){
        DisjointSet ds(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(a[i][j] == 1)
                    ds.unionBySize(i,j);
            }
        }
        int cnt = 0;
        for(int i=0;i<V;i++){
            if(ds.findUpar(i) == i)
                cnt++;
        }
        return cnt;
    }
};
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> matrix(V, vector<int>(V, 0));
    cout << "Enter edges (u v):\n";
    for(int i=0; i<E; i++) {
        int u, v;
        cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1; // undirected
    }
    Solution sol;
    cout << "Number of Provinces = " << sol.numProvinces(V, matrix) << "\n";
    return 0;
}
// 7 4
// 0 1
// 0 2 
// 3 4
// 5 6