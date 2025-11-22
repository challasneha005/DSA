// UNBOUNDED KNAPSACK PROBLEM-INFINITE SUPPLY
#include<bits/stdc++.h>
using namespace std;
//  recursion O(2^n) , O(n)
int UnBoundedknap(int ind,int W,vector<int> &wt,vector<int> &val){
    if(ind ==0)
        return (int)(W/wt[0]) * val[0];
    int nottake = 0+UnBoundedknap(ind-1,W,wt,val);
    int take = INT_MIN;
    if(wt[ind] <=W)
        take = val[ind]+UnBoundedknap(ind,W-wt[ind],wt,val);
    return max(take,nottake);
}
// dp O(n*w) , O(n*w)+O(n)
int dpUnBoundedknap(int ind,int W,vector<int> &wt,vector<int> &val,vector<vector<int>> &dp){
    if(ind ==0) 
        return (int)(W/wt[0]) * val[0];
    if(dp[ind][W]!=-1)
         return dp[ind][W];
    int nottake = 0+dpUnBoundedknap(ind-1,W,wt,val,dp);
    int take = INT_MIN;
    if(wt[ind] <=W)
        take = val[ind]+dpUnBoundedknap(ind,W-wt[ind],wt,val,dp);
    return dp[ind][W]=max(take,nottake);
}
//tab
int tab(int n,int maxW,vector<int> wt,vector<int> &val){
    vector<vector<int>> dp(n,vector<int>(maxW+1,0));
    for(int W= wt[0];W<=maxW;W++)
        dp[0][W] = (int)(W/wt[0]) * val[0];
    for(int ind = 1;ind<n;ind++){
        for(int W=0;W<=maxW;W++){
            int nottake = 0+dp[ind-1][W];
            int take = 0;
            if(wt[ind]<=W)
                take = val[ind]+dp[ind][W-wt[ind]];
            dp[ind][W] = max(take,nottake);
        }
    }
    return dp[n-1][maxW];
}   
int spacetab(int n,int maxW,vector<int> wt,vector<int> &val){
    vector<int> prev(maxW+1,0),cur(maxW+1,0);
    for(int W= wt[0];W<=maxW;W++)
        prev[W] =  (int)(W/wt[0]) * val[0];
    for(int ind = 1;ind<n;ind++){
        for(int W=0;W<=maxW;W++){
            int nottake = 0+prev[W];
            int take = 0;
            if(wt[ind]<=W)
                take = val[ind]+cur[W-wt[ind]];
            cur[W] = max(take,nottake);
        }
        prev = cur;
    }
    return prev[maxW];
}   
//single array space
int optimized(int n,int maxW,vector<int> wt,vector<int> &val){
    vector<int> prev(maxW+1,0);
    for(int W= 0;W<=maxW;W++)
        prev[W] = (int)(W/wt[0]) * val[0];;
    for(int ind = 1;ind<n;ind++){
        for(int W=0;W<=maxW;W++ ){
            int nottake = 0+prev[W];
            int take = 0;
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

    cout << UnBoundedknap(n-1, W, wt, val) << endl;

    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    cout << dpUnBoundedknap(n-1, W, wt, val,dp) << endl;

    cout << tab(n,W,wt,val)<<endl;

    cout << spacetab(n,W,wt,val)<<endl;

    cout << optimized(n,W,wt,val)<<endl;
    return 0; 
}
// 3
// 2 4 6
// 5 11 13
// 10

