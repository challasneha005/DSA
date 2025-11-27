// MATRIX CHAIN MIN MULTIPLICATIONS
#include<bits/stdc++.h>
using namespace std;
//recursion exponential..
int minMultiplications(int i,int j,vector<int> & a){
    if(i==j)
        return 0;
    int mini = 1e9;
    for(int k=i;k<j;k++){
        int steps = a[i-1]*a[k]*a[j]+
            minMultiplications(i,k,a)+
            minMultiplications(k+1,j,a); 
        if(steps < mini)
            mini = steps;
    }
    return mini;
}
// dp O(n*n*n) , O(n*n)+O(n)
int dpminMultiplications(int i,int j,vector<int> & a, vector<vector<int>> &dp){
    if(i==j)
        return 0;
    if(dp[i][j] !=-1)
        return dp[i][j];
    int mini = 1e9;
    for(int k=i;k<j;k++){
        int steps = a[i-1]*a[k]*a[j]+
            dpminMultiplications(i,k,a,dp)+
            dpminMultiplications(k+1,j,a,dp); 
        if(steps < mini)
            mini = steps;
    }
    return dp[i][j] = mini;
}
// tab
int tab(vector<int> &a,int n){
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int mini = 1e9;
            for(int k=i;k<j;k++){
                int steps = a[i-1]*a[k]*a[j]+
                dp[i][k]+dp[k+1][j]; 
            if(steps < mini)
                mini = steps;
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}
//can't be written in space it need matrix
int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    cout << minMultiplications(1,n-1,a) << endl;

    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout << dpminMultiplications(1,n-1,a,dp) << endl;

    cout << tab(a,n) << endl;
    return 0;
}