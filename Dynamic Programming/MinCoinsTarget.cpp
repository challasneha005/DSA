//MIN COINS TO SUM TARGET
#include<bits/stdc++.h>
using namespace std;
//  recursion O(2^n) , O(n)
int minCoins(int ind,int sum,vector<int> &a){
    if(ind==0){
        if((sum % a[0] )== 0)
            return sum/a[0]; 
        else
            return 1e9;
    }
    int nottake = 0+minCoins(ind-1,sum,a);
    int take = 1e9;
    if(a[ind]<=sum)
        take = 1+minCoins(ind,(sum-a[ind]),a);
    return min(take,nottake);
}
// dp memorize O(n*t) , O(n*t)+O(t)
int dpminCoins(int ind,int sum,vector<int> &a,vector<vector<int>> &dp){
    if(ind==0){
        if((sum % a[0] )== 0)
            return sum/a[0]; 
        else
            return 1e9;
    }
    if(dp[ind][sum]!=-1)
        return dp[ind][sum];
    int nottake = 0+dpminCoins(ind-1,sum,a,dp);
    int take = 1e9;
    if(a[ind]<=sum)
        take = 1+dpminCoins(ind,(sum-a[ind]),a,dp);
    return dp[ind][sum] = min(take,nottake);
}
// tab
int tab(int n,int sum,vector<int> &a){
    vector<vector<int>> dp(n,vector<int>(sum+1,0));
    for(int t=0;t<=sum;t++){
        if(t%a[0] == 0)
            dp[0][t] = t/a[0];
        else    
            dp[0][t] = 1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int t=0;t<=sum;t++){
            int nottake = dp[ind-1][t];
            int take = 1e9;
            if(a[ind]<=t)
                take = 1+dp[ind][t-a[ind]];
            dp[ind][t] = min(take,nottake);
        }
    } 
    return dp[n-1][sum];
}
int spacetab(int n,int sum,vector<int> &a){
    vector<int> prev(sum+1,0),cur(sum+1,0);
    for(int t=0;t<=sum;t++){
        if(t%a[0] == 0)
            prev[t] = t/a[0];
        else    
            prev[t] = 1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int t=0;t<=sum;t++){
            int nottake = prev[t];
            int take = 1e9;
            if(a[ind]<=t)
                take = 1+cur[t-a[ind]];
            cur[t] = min(take,nottake);
        }
        prev = cur;
    } 
    return  prev[sum];
}
int main(){
    int n,targetSum;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> targetSum;
    cout << minCoins(n-1,targetSum,a) << endl;
    
    vector<vector<int>> dp(n,vector<int>(targetSum+1,-1));
    cout << dpminCoins(n-1,targetSum,a,dp) << endl;
    
    cout << tab(n,targetSum,a) << endl;

    cout << spacetab(n,targetSum,a);
    return 0;
}
// 3
// 1 2 3
// 8