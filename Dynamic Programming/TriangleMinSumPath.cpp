// TRIANGLE NO FIXED ENDING POINT,,FIXED STARTING POINT..MIN SUM PATH
#include<bits/stdc++.h>
using namespace std;
//recursion O(2^n^2) , O(n)+O(n*n)
int triMinSum(int i,int j,vector<vector<int>> &triangle,int n){
    if(i==n-1)
        return triangle[n-1][j];
    int down = triangle[i][j] + triMinSum(i+1,j,triangle,n);
    int diag = triangle[i][j] + triMinSum(i+1,j+1,triangle,n);
    return min(down,diag);
}
// dp memorization O(n*n) , O(n)+O(n*n)
int dptriMinSum(int i,int j,vector<vector<int>> &triangle,int n,vector<vector<int>> &dp){
    if(i==n-1)
        return triangle[n-1][j];
    if(dp[i][j]!=-1)
        return dp[i][j];
    int down = triangle[i][j] + dptriMinSum(i+1,j,triangle,n,dp);
    int diag = triangle[i][j] + dptriMinSum(i+1,j+1,triangle,n,dp);
    return dp[i][j]=min(down,diag);
}
//tab O(n*n) , O(n*n)
int tab(vector<vector<int>> &triangle,int n,vector<vector<int>> &dp){
    for(int j=0;j<n;j++)
        dp[n-1][j] = triangle[n-1][j];
    for(int i=n-2;i>=0;i--){
        for(int j=1;j>=0;j--){
            int down = triangle[i][j]+dp[i+1][j];
            int diag = triangle[i][j]+dp[i+1][j+1];
            dp[i][j]=min(down,diag);
        }
    }
    return dp[0][0];
}
//tab O(n*n) , O(n)
int spacetab(vector<vector<int>> &triangle,int n){
    vector<int> front(n,0),cur(n,0);
    for(int j=0;j<n;j++)
        front[j] = triangle[n-1][j];
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down = triangle[i][j]+front[j];
            int diag = triangle[i][j]+front[j+1];
            cur[j]=min(down,diag);
        }
        front = cur;
    }
    return front[0];
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin >> a[i][j];
        }
    }
    cout << triMinSum(0,0,a,n) << endl;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout << dptriMinSum(0,0,a,n,dp) << endl;
    cout << tab(a,n,dp) << endl;
    cout << spacetab(a,n) << endl;
    return 0;
}
// 4
// 1
// 2 3
// 3 6 7
// 8 9 6 10
