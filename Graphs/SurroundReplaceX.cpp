//SURROUNDED REGION REPLACE O'S WITH X -DFS  O(n*m*4) , O(n*m)
#include<bits/stdc++.h>
using namespace std;
void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &adj,int delrow[],int delcol[]){
    vis[row][col] = 1;
    int n = adj.size();
    int m = adj[0].size();
    for(int i=0;i<4;i++){
        int nrow = row+delrow[i];
        int ncol = col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
        && !vis[nrow][ncol] && adj[nrow][ncol]=='O'){
            dfs(nrow,ncol,vis,adj,delrow,delcol);
        }
    }
}
vector<vector<char>> fill(int n,int m,vector<vector<char>> adj){
    vector<vector<int>> vis(n,vector<int>(m,0));
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    for(int j=0;j<m;j++){
        if(!vis[0][j] && adj[0][j] == 'O')
            dfs(0,j,vis,adj,delrow,delcol);
        if(!vis[n-1][j] && adj[n-1][j] == 'O')
            dfs(n-1,j,vis,adj,delrow,delcol);
    }
    for(int i=0;i<n;i++){
        if(!vis[i][0] && adj[i][0] == 'O')
            dfs(i,0,vis,adj,delrow,delcol);
        if(!vis[i][m-1] && adj[i][m-1] == 'O')
            dfs(i,m-1,vis,adj,delrow,delcol);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && adj[i][j] == 'O')
                adj[i][j] = 'X';
        }
    }
    return adj;
} 

int main() {
    int n, m;
    cout << "Enter rows and cols: ";
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    cout << "Enter board (O/X):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    vector<vector<char>> result = fill(n, m, board);
    cout << "\nResult:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// Enter rows and cols: 4 4
// Enter board (O/X):
// X X X X
// X O O X
// X X O X
// X O X X
