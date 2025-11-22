// 0/1 KNAPSACK PROBLEM
#include<bits/stdc++.h>
using namespace std;
//  recursion O(2^n) , O(n)
int knap(int ind,int W,vector<int> &wt,vector<int> &val){
    if(ind ==0){
        if(wt[0] <=W)
            return val[0];
        return 0;
    }
    int nottake = 0+knap(ind-1,W,wt,val);
    int take = INT_MIN;
    if(wt[ind] <=W)
        take = val[ind]+knap(ind-1,W-wt[ind],wt,val);
    return max(take,nottake);
}
// dp O(n*w) , O(n*w)+O(n)
int dpknap(int ind,int W,vector<int> &wt,vector<int> &val,vector<vector<int>> &dp){
    if(ind ==0){
        if(wt[0] <=W)
            return val[0];
        return 0;
    }
    if(dp[ind][W]!=-1)
         return dp[ind][W];
    int nottake = 0+dpknap(ind-1,W,wt,val,dp);
    int take = INT_MIN;
    if(wt[ind] <=W)
        take = val[ind]+dpknap(ind-1,W-wt[ind],wt,val,dp);
    return dp[ind][W]=max(take,nottake);
}
//tab
int tab(int n,int maxW,vector<int> wt,vector<int> &val){
    vector<vector<int>> dp(n,vector<int>(maxW+1,0));
    for(int W= wt[0];W<=maxW;W++)
        dp[0][W] = val[0];
    for(int ind = 1;ind<n;ind++){
        for(int W=0;W<=maxW;W++){
            int nottake = 0+dp[ind-1][W];
            int take = INT_MIN;
            if(wt[ind]<=W)
                take = val[ind]+dp[ind-1][W-wt[ind]];
            dp[ind][W] = max(take,nottake);
        }
    }
    return dp[n-1][maxW];
}   
int spacetab(int n,int maxW,vector<int> wt,vector<int> &val){
    vector<int> prev(maxW+1,0),cur(maxW+1,0);
    for(int W= wt[0];W<=maxW;W++)
        prev[W] = val[0];
    for(int ind = 1;ind<n;ind++){
        for(int W=0;W<=maxW;W++){
            int nottake = 0+prev[W];
            int take = INT_MIN;
            if(wt[ind]<=W)
                take = val[ind]+prev[W-wt[ind]];
            cur[W] = max(take,nottake);
        }
        prev = cur;
    }
    return prev[maxW];
}   
//single array space
int optimized(int n,int maxW,vector<int> wt,vector<int> &val){
    vector<int> prev(maxW+1,0);
    for(int W= wt[0];W<=maxW;W++)
        prev[W] = val[0];
    for(int ind = 1;ind<n;ind++){
        for(int W=maxW;W>=0;W-- ){
            int nottake = 0+prev[W];
            int take = INT_MIN;
            if(wt[ind]<=W)
                take = val[ind]+prev[W-wt[ind]];
            prev[W] = max(take,nottake);
        }
    }
    return prev[maxW];
}   
int main() {
    int n;
    cin >> n;   // number of items
    vector<int> wt(n), val(n);
    // input weights
    for(int i = 0; i < n; i++)
        cin >> wt[i];

    // input values
    for(int i = 0; i < n; i++)
        cin >> val[i];
    
    int W; 
    cin >> W;   // bag capacity

    cout << knap(n-1, W, wt, val) << endl;

    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    cout << dpknap(n-1, W, wt, val,dp) << endl;

    cout << tab(n,W,wt,val)<<endl;

    cout << spacetab(n,W,wt,val)<<endl;

    cout << optimized(n,W,wt,val)<<endl;
    return 0; 
}
// 4
// 1 3 4 5
// 1 4 5 7
// 7

