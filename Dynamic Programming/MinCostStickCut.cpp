// MIN COST TO CUT THE STICK
#include<bits/stdc++.h>
using namespace std;
// recursion
int mincost(int i,int j,vector<int> &cuts){
    if(i>j)
        return 0;
    int mini = INT_MAX;
    for(int ind=i;ind<=j;ind++){
        int cost = cuts[j+1] - cuts[i-1]+
                    mincost(i,ind-1,cuts)+mincost(ind+1,j,cuts);
            mini = min(mini,cost);
    }
    return mini;
}
// dp  O(m*m*m) , O(m*m)+O(m)
int dpmincost(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
    if(i>j)
        return 0;
    if(dp[i][j] !=-1)
        return dp[i][j];
    int mini = INT_MAX;
    for(int ind=i;ind<=j;ind++){
        int cost = cuts[j+1] - cuts[i-1]+
                    dpmincost(i,ind-1,cuts,dp)+dpmincost(ind+1,j,cuts,dp);
            mini = min(mini,cost);
    }
    return dp[i][j] = mini;
}
// tab O(m*m*m) , O(m*m)
int tab(vector<int> &cuts,int c,int n){
    vector<vector<int>> dp(c+2,vector<int>(c+2,0));
    for(int i=c;i>=1;i--){
        for(int j=1;j<=c;j++){
            if(i>j) continue;
            int mini = INT_MAX;
            for(int ind=i;ind<=j;ind++){
                int cost = cuts[j+1] - cuts[i-1]+
                        dp[i][ind-1]+dp[ind+1][j];
                mini = min(mini,cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}
//space opt not possible - require full 2D DP because of random dependencies
int main(){
    int n;
    cin >> n;   // length of stick

    int c;
    cin >> c;   // number of cuts

    vector<int> cuts(c);
    for(int i = 0; i < c; i++)
        cin >> cuts[i];

    // Add boundaries 0 and n
    cuts.push_back(0);
    cuts.push_back(n);

    sort(cuts.begin(), cuts.end());

    // Solve from 1 to c   (because 0 and n are added)
    cout << mincost(1, c, cuts) << endl;

    vector<vector<int>> dp(c+1,vector<int>(c+1 ,-1));
    cout << dpmincost(1, c, cuts,dp) << endl;

    cout << tab(cuts,c,n) << endl;
    return 0;
}
