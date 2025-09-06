// DISJOINT SET O(E α(N) + N) ≈ O(E + N) , O(2N)
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
int main(){
    DisjointSet ds(7);
    // same for unionBySize
    // can use only one at a time
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findUpar(3) == ds.findUpar(7))
        cout << "same" << endl;
    else
        cout << "Not same" << endl;
    ds.unionByRank(3,7);
    if(ds.findUpar(3) == ds.findUpar(7))
        cout << "same" << endl;
    else
        cout << "Not same" << endl;
    return 0;
}