// GRID UNIQUE LENGTHS
#include<bits/stdc++.h>
using namespace std;
//recursion O(2^(m*n)) , O(pathlength)
int uniquepaths(int i,int j){
    if(i==0 && j==0)
        return 1;
    if(i<0 || j<0)
        return 0;
    int up = uniquepaths(i-1,j);
    int left = uniquepaths(i,j-1);
    return up+left;
}
//dp memorization O(n*m) , O((n-1)*(m-1)) +O(n*m)
int dpuniquepaths(int i,int j,vector<vector<int>> &dp){
    if(i==0 && j==0)
        return 1;
    if(i<0 || j<0)
        return 0;
    if (dp[i][j] !=-1)
        return dp[i][j];
    int up = dpuniquepaths(i-1,j,dp);
    int left = dpuniquepaths(i,j-1,dp);
    return dp[i][j] = up+left;
}
//tabulation O(n*m),O(n*m)
int tabuniquepaths(int n,int m){
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j == 0)
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
int spacetabuniquepaths(int n,int m){
    vector<int> prev(m,0); 
    for(int i=0;i<n;i++){
        vector<int> cur(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j == 0)
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
    cin >> n >> m;              // rows and columns
    // cout << uniquepaths(n - 1, m - 1);
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << dpuniquepaths(n-1,m-1,dp);
    cout << tabuniquepaths(n,m);
    cout << spacetabuniquepaths(n,m);
    return 0;
}