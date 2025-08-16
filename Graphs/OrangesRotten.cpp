//ROTTEN ORANGES TIME O(n*m +n*m*4) , O(n*m)
#include<bits/stdc++.h>
using namespace std;
int orangeRot(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> vis(n,vector<int>(m,0));
    int cntFresh =0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                vis[i][j] = 2;
            }
            else{   
                vis[i][j] = 0;
                if(grid[i][j]==1)
                    cntFresh++;
            }
        }
    }
    int time = 0,cnt = 0;
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        time = max(time,t);
        for(int i=0;i<4;i++){
            int nrow = r+drow[i];
            int ncol = c+dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                vis[nrow][ncol] == 0 &&  grid[nrow][ncol] ==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] != 2 && grid[i][j] ==1){
                    return -1;
            }
        }
        if(cnt!= cntFresh)
            return -1;
        }
    return time;
}
int main() {
    vector<vector<int>> grid = {
        {2,1,1,1,1},
        {1,1,0,1,0},
        {0,1,1,0,0}
    };
    int ans = orangeRot(grid);
    if(ans == -1)
        cout << "All oranges cannot rot." << endl;
    else
        cout << "Time required to rot all oranges: " << ans << endl;
    return 0;
}