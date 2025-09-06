// MAKING A LARGE ISLAND O(N*N⋅α(N*N))≈O(N*N) , O(N*N)
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
public:
    vector<int> rank,size,parent;
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
    int maxConnect(vector<vector<int>> &grid){
        int n = grid.size();
        // DisjointSet ds = new DisjointSet(n*n);
        DisjointSet ds(n*n);
        // Step 1: Build DSU for existing 1s
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c] == 0)
                    continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                for(int i=0;i<4;i++){
                    int nr = r+dr[i];
                    int nc = c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1){
                        int nodeNo = r *n+c;
                        int anodeNo = nr*n + nc;
                        ds.unionBySize(nodeNo,anodeNo);
                    }
                }
            }
        }
        // Step 2: Try flipping each 0
        int mx = 0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c] ==1)
                    continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                // HashSet<Integer> components = new HashSet<>();
                unordered_set<int> components;
                for(int i=0;i<4;i++){
                    int nr = r+dr[i];
                    int nc = c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1)
                        components.insert(ds.findUpar(nr*n + nc));
                }
                int sizeTotal = 0;
                // for(Integer parents:components)
                //     sizeTotal += ds.size.get(parents);
                for(auto p:components)
                    sizeTotal += ds.size[p];
                mx = max(mx,sizeTotal+1);
            }
        }
        // Step 3: In case grid has all 1s
        for(int cellno=0;cellno<n*n;cellno++)
            mx = max(mx,ds.size[ds.findUpar(cellno)]);
        return mx;
    }
};
int  main(){
    int n;
    cin >> n;  // size of grid
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }
    Solution sol;
    cout << sol.maxConnect(grid) << endl;
    return 0;
}
// 1 1 0 1 1 0
// 1 1 0 1 1 0
// 1 1 0 1 1 0
// 0 0 1 0 0 0
// 0 0 1 1 1 0
// 0 0 1 1 1 0