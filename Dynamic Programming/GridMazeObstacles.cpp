// GRID UNIQUE LENGTHS WITH OBSTACLES
#include<bits/stdc++.h>
using namespace std;
//recursion O(2^(m*n)) , O(pathlength)
int mazeobstacles(int i,int j,vector<vector<int>> &a){
    if(i>=0 && j>=0 && a[i][j] == -1)
        return 0;
    if(i==0 && j==0)
        return 1;
    if(i<0 || j<0)
        return 0;
    int up = mazeobstacles(i-1,j,a);
    int left = mazeobstacles(i,j-1,a);
    return up+left;
}
//dp memorization O(n*m) , O((n-1)*(m-1)) +O(n*m)
int dpmazeobstacles(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &a){
    if(i>=0 && j>=0 && a[i][j] == -1)
        return 0;
    if(i==0 && j==0)
        return 1;
    if(i<0 || j<0)
        return 0;
    if (dp[i][j] !=-1)
        return dp[i][j];
    int up = dpmazeobstacles(i-1,j,dp,a);
    int left = dpmazeobstacles(i,j-1,dp,a);
    return dp[i][j] = up+left;
}
//tabulation O(n*m),O(n*m)
int tabmazeobstacles(int n,int m,vector<vector<int>> &a){
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == -1)
                dp[i][j] = 0;
            else if(i==0 && j == 0)
                dp[0][0] = 1;
            else{
                int up=0,left = 0;
                if(i>0 )
                    up = dp[i-1][j];
                if(j>0)
                    left = dp[i][j-1];
                dp[i][j] = up+left;
            }
        }
    }
    return dp[n-1][m-1];
}
//space 
int spacetabmazeobstacles(int n,int m,vector<vector<int>> &a){
    vector<int> prev(m,0); 
    for(int i=0;i<n;i++){
        vector<int> cur(m,0);
        for(int j=0;j<n;j++){
            if(a[i][j] == -1)
                cur[j] = 0;
            else if(i==0 && j == 0)
                cur[j] = 1;
            else{
                int up=0,left = 0;
                if(i>0 )
                    up = prev[j];
                if(j>0)
                    left = cur[j-1];
                cur[j] = up+left;
            }
        }
        prev = cur;
    }
    return prev[m-1];
}
int main(){
    int n, m;
    cin >> n >> m;   
    vector<vector<int>> a(n, vector<int>(m));          // rows and columns
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    cout << mazeobstacles(n - 1, m - 1,a);
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << dpmazeobstacles(n-1,m-1,dp,a);
    cout << tabmazeobstacles(n,m,a);
    cout << spacetabmazeobstacles(n,m,a);
    return 0;
}
// 3 3
// 0 0 0
// 0 -1 0
// 0 0 0