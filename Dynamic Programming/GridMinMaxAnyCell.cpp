// MIN/MAX SUM PATH FROM ANY CELL IN FROM 1ST ROW, TO LAST ROW DOWN,LDIAG,RDIAG
#include<bits/stdc++.h>
using namespace std;
// recursion O(3^n),O(n)+O(n*m)
int maxAnyPath(int i,int j,vector<vector<int>> &a){
    int m = a[0].size(); 
    if(j<0 || j>=m)
        return -1e9;
    if(i==0)
        return a[0][j];
    int u = a[i][j]+maxAnyPath(i-1,j,a);
    int ld = a[i][j]+maxAnyPath(i-1,j-1,a);
    int rd = a[i][j]+maxAnyPath(i-1,j+1,a);
    return max(u,max(ld,rd));
}
//dp memorization O(n*m) , O(n*m)+O(n)
int dpmaxAnyPath(int i,int j,vector<vector<int>> &a,vector<vector<int>> &dp){
    int m = a[0].size(); 
    if(j<0 || j>=m)
        return -1e9;
    if(i==0)
        return a[0][j];
    if(dp[i][j] != -1)
        return dp[i][j];
    int u = a[i][j]+dpmaxAnyPath(i-1,j,a,dp);
    int ld = a[i][j]+dpmaxAnyPath(i-1,j-1,a,dp);
    int rd = a[i][j]+dpmaxAnyPath(i-1,j+1,a,dp);
    return dp[i][j]=max(u,max(ld,rd));
}
//tab O(n*m)+O(n) , O(n*m)
int tab(vector<vector<int>> &a){
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int j=0;j<m;j++)
        dp[0][j] = a[0][j];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up = a[i][j] + dp[i-1][j];
            int ld = a[i][j];
            if(j-1>0)
                ld +=  dp[i-1][j-1];
            int rd = a[i][j];
            if(j+1<m)
                rd += dp[i-1][j+1];
            dp[i][j] = max(up,max(ld,rd));
        }
    }
    int maxi = -1e9;
    for (int j=0; j<m; j++)
        maxi= max(maxi, dp[n-1][j]);

    return maxi;
}
//tab O(n*m)+O(n) , m)
int spacetab(vector<vector<int>> &a){
    int n = a.size();
    int m = a[0].size();
    vector<int> prev(m,0),cur(m,0);
    for(int j=0;j<m;j++)
        prev[j] = a[0][j];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up = a[i][j] + prev[j];
            int ld = a[i][j];
            if(j-1>0)
                ld +=  prev[j-1];
            int rd = a[i][j];
            if(j+1<m)
                rd += prev[j+1];
            cur[j] = max(up,max(ld,rd));
        }
        prev = cur;
    }
    int maxi = -1e9;
    for (int j=0; j<m; j++)
        maxi= max(maxi, cur[j]);

    return maxi;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    }
    //recursion
    int recAns = -1e9;
    for(int j=0;j<m;j++)
        recAns = max(recAns,maxAnyPath(n-1,j,a));
    cout << recAns << endl;

    //dp memorization
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int memoAns = -1e9;
    for (int j=0; j<m; j++)
        memoAns = max(memoAns, dpmaxAnyPath(n-1, j, a, dp));
    cout << memoAns << endl;

    //tab
    cout << tab(a) << endl;

    //spacetab
    cout << spacetab(a) << endl;

    return 0;
}
// 3 3
// 1 1 100
// 2 2 3
// 3 10 2