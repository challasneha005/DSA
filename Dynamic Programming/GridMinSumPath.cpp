// MINIMUM PATH SUM IN GRID
#include<bits/stdc++.h>
using namespace std;
//recursion O(2^(m*n)) , O(pathlength)
int minPath(int i,int j,vector<vector<int>> &a){
    if(i==0 && j==0)
        return a[i][j];
    if(i<0 || j<0)
        return 1e9; //INT_MAX; overflow
    int up = a[i][j]+minPath(i-1,j,a);
    int left = a[i][j]+minPath(i,j-1,a);
    return min(up,left);
}
//dp memorization O(n*m) , O((n-1)*(m-1)) +O(n*m)
int dpminPath(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &a){
    if(i==0 && j==0)
        return a[i][j];
    if(i<0 || j<0)
        return 1e9; //INT_MAX; overflow
    if (dp[i][j] !=-1)
        return dp[i][j];
    int up = a[i][j]+dpminPath(i-1,j,dp,a);
    int left = a[i][j]+dpminPath(i,j-1,dp,a);
    return dp[i][j] = min(up,left);
}
//tabulation O(n*m),O(n*m)
int tabminPath (int n,int m,vector<vector<int>> &a){
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = a[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j == 0)
                dp[i][j] = a[0][0];
            else{
                int up=INT_MAX,left = INT_MAX;
                if(i>0 )
                    up = a[i][j]+dp[i-1][j];
                if(j>0)
                    left = a[i][j]+dp[i][j-1];
                dp[i][j] = min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}
//space 
int spacetabminPath(int n,int m,vector<vector<int>> &a){
    vector<int> prev(m,0); 
    for(int i=0;i<n;i++){
        vector<int> cur(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j == 0)
                cur[j] = a[0][0];
            else{
                int up=INT_MAX,left = INT_MAX;
                if(i>0)
                    up = a[i][j]+prev[j];
                if(j>0)
                    left = a[i][j]+cur[j-1];
                cur[j] = min(up,left);
            }
        }
        prev = cur;
    }
    return prev[m-1];
}
int main(){
    int n, m;
    cin >> n >> m;   
    vector<vector<int>> a(n,vector<int>(m));           // rows and columns
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    cout << minPath(n - 1, m - 1,a) << endl;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << dpminPath(n-1,m-1,dp,a) << endl;
    cout << tabminPath(n,m,a) << endl;
    cout << spacetabminPath(n,m,a) << endl;
    return 0;
}
// 2 3
// 5 9 6
// 11 5 2