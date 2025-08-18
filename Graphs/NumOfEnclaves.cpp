//NO.OF ENCLAVES -BFS  O(n*m*4) , O(n*m)
#include<bits/stdc++.h>
using namespace std;
int numEnclaves(vector<vector<int>> &grid){
    queue<pair<int,int>> q;
    int n = grid.size();
    int m = grid[0].size();
    //int vis[n][m] = {0};
    vector<vector<int>> vis (n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0 || i==n-1 || j==m-1){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
    }
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow >=0 && nrow <n && ncol >=0 && ncol<m 
            && grid[nrow][ncol] == 1 && vis[nrow][ncol]==0){
                vis[nrow][ncol] = 1; 
                q.push({nrow,ncol});
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1 && vis[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}
int main() {
    int n, m;
    cout << "Enter rows and cols: ";
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter grid (0 water, 1 land):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    cout << "Number of Enclaves = " << numEnclaves(grid) << "\n";
    return 0;
}
// Enter rows and cols: 4 4
// Enter grid (0 water, 1 land):
// 0 0 0 0
// 1 0 1 0
// 0 1 1 0
// 0 0 0 0
