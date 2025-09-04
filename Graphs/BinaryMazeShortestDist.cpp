//SHORTEST DISTANCE IN BINARY MAZE O(n*m) , O(n*m)
#include<bits/stdc++.h>
using namespace std;
int shortestDistance(vector<vector<int>> &grid,pair<int,int> src,pair<int,int> dest){
    queue<pair<int,pair<int,int>>> q;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n,vector<int> (m,1e9));
    dist[src.first][src.second] = 0;
    q.push({0,{src.first,src.second}});
    int delr[] = {-1,0,1,0};
    int delc[] = {0,1,0,-1};
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;
        for (int i=0; i<4; i++) {
            int newr = r+delr[i];
            int newc = c+delc[i];
            if (newr>=0 && newr<n && newc>=0 && newc<m
                && grid[newr][newc]==1 && dis+1 < dist[newr][newc]) {
                dist[newr][newc] = 1+dis;
                if (newr==dest.first && newc==dest.second)
                    return dis+1;
                q.push({1+dis,{newr,newc}});
            }
        }
    }
    return -1;  
}
int main() {
    int n, m;
    cout << "Enter grid size (rows cols): ";
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter grid (0 for blocked, 1 for open):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int sr, sc, dr, dc;
    cout << "Enter source (row col): ";
    cin >> sr >> sc;
    cout << "Enter destination (row col): ";
    cin >> dr >> dc;
    int result = shortestDistance(grid, {sr, sc}, {dr, dc});
    if (result == -1)
        cout << "No path exists\n";
    else
        cout << "Shortest distance = " << result << "\n";
    return 0;
}

// 5 4 
// 1 1 1 1
// 1 1 0 1
// 1 1 1 1
// 1 1 0 0 
// 1 0 0 0
// 0 1
// 2 2