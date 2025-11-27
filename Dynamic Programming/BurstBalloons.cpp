// BURST BALLOONS
#include<bits/stdc++.h>
using namespace std;
// recursion
int maxPoints(int i,int j,vector<int> a){
    if(i>j)
        return 0;
    int maxi = INT_MIN;
    for(int ind =i;ind<=j;ind++){
        int points = a[i-1]*a[ind]*a[j+1]+
            maxPoints(i,ind-1,a)+maxPoints(ind+1,j,a);
        maxi = max(maxi,points);
    }
    return maxi;
}
// dp  O(n*n*n) , O(n*n)+O(n)
int dpmaxPoints(int i,int j,vector<int> a,vector<vector<int>> &dp){
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int maxi = INT_MIN;
    for(int ind =i;ind<=j;ind++){
        int points = a[i-1]*a[ind]*a[j+1]+
            dpmaxPoints(i,ind-1,a,dp)+dpmaxPoints(ind+1,j,a,dp);
        maxi = max(maxi,points);
    }
    return dp[i][j] = maxi;
}
// tab O(n*n*n) , O(n*n)
int tab(vector<int> &a,int n){
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(i>j)
                continue;
            int maxi = INT_MIN;
            for(int ind =i;ind<=j;ind++){
                int points = a[i-1]*a[ind]*a[j+1]+
                    dp[i][ind-1]+dp[ind+1][j];
                maxi = max(maxi,points);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}
// Space Optimization is NOT possible
int main(){
    int n;
    cin >> n;   
    vector<int> balloons(n);
    for(int i = 0; i < n; i++)
        cin >> balloons[i];

    // Add boundaries 1 at ends
    balloons.insert(balloons.begin(),1);
    balloons.push_back(1);

    cout << maxPoints(1,n,balloons) << endl;

    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    cout << dpmaxPoints(1,n,balloons,dp) << endl;

    cout << tab(balloons,n) << endl;

    return 0;
}
