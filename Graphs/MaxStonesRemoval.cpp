// MAXIMUM STONE REMOVAL O(N·α(N)) ≈ O(N), O(N)
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
    int maxRemove(vector<vector<int>> &stones,int n){
        int maxRow = 0;
        int maxCol = 0;
        for(auto it: stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map <int,int> stoneNodes;
        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1]+maxRow +1;
            ds.unionBySize(nodeRow,nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int cnt = 0;
        for(auto it: stoneNodes){
            if(ds.findUpar(it.first) == it.first)
                cnt++;
        } 
        return n-cnt;
    }
};
int main() {
    int n;
    cout << "Enter number of stones: ";
    cin >> n;
    vector<vector<int>> stones(n, vector<int>(2));
    cout << "Enter stone positions (row col):\n";
    for (int i = 0; i < n; i++) 
        cin >> stones[i][0] >> stones[i][1];
    Solution sol;
    int ans = sol.maxRemove(stones, n);
    cout << "Maximum stones that can be removed: " << ans << "\n";
    return 0;
}
// 0 0
// 0 1
// 1 0
// 1 2
// 2 1
// 2 2

// 0 0
// 0 2
// 1 1
// 2 0
// 2 2
 