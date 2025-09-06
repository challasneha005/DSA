// NO.OF ISLANDS II - ONLINE QUERIES O(E α(N) + N) ≈ O(E + N) , O(2N)
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
    vector<int> noOfIslands(int n,int m,vector<vector<int>> operators){
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        vector<int> ans;
        for(auto it:operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr = row+dr[i];
                int nc = col+dc[i];
                if(nr >= 0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==1){
                    int nodeNo = row*m+col;
                    int anodeNo = nr*m+nc;
                    if(ds.findUpar(nodeNo) != ds.findUpar(anodeNo)){
                        cnt--;
                        ds.unionBySize(nodeNo,anodeNo);
                    }
                }
            } 
            ans.push_back(cnt);
        }
        return ans;
    }
};
int main() {
    int n, m, q;
    cout << "Enter grid dimensions (n m): ";
    cin >> n >> m;
    cout << "Enter number of operations: ";
    cin >> q;
    vector<vector<int>> operators(q, vector<int>(2));
    cout << "Enter each operator (row col):\n";
    for(int i=0; i<q; i++) 
        cin >> operators[i][0] >> operators[i][1];
    Solution sol;
    vector<int> res = sol.noOfIslands(n, m, operators);
    cout << "\nNumber of Islands after each operation:\n";
    for(int x : res) cout << x << " ";
    cout << "\n";
    return 0;
}
// 4 5
// 12 operations
// 0 0
// 0 0
// 1 1
// 1 0
// 0 1
// 0 3
// 1 3
// 0 4
// 3 2
// 2 2
// 1 2
// 0 2