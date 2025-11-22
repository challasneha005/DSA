//NO.OF WAYS TO GET TARGET BY S|ASIGNING SIGNS
//SAME AS SubsetDiffCount.cpp  
#include<bits/stdc++.h>
using namespace std;
int mod = (int)(1e9+7);
//recursion O(2^n) ,O(n)
int kSumCount(int ind,int target,vector<int> &a){
    if(target == 0)
        return 1;
    if(ind == 0)
        return a[0] == target;
    int nottake = kSumCount(ind-1,target,a);
    int take = 0;
    if(target>= a[ind])
        take = kSumCount(ind-1,target-a[ind],a);
    return (take +nottake)%mod;
}
// dp memorization O(n*target) , O(n*target)+O(n)
int dpkSumCount(int ind,int target,vector<int> &a,vector<vector<int>> &dp){
    if(target == 0)
        return 1;
    if(ind == 0)
        return a[0] == target;
    if(dp[ind][target] !=-1)
        return dp[ind][target];
    int nottake = dpkSumCount(ind-1,target,a,dp);
    int take = false;
    if(target>= a[ind])
        take = dpkSumCount(ind-1,target-a[ind],a,dp);
    return dp[ind][target]=(take+nottake)%mod;
}
//tab
int tab(int n,int target,vector<int> &a){
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    for(int i=0;i<n;i++)
        dp[i][0] = 1;
    if(a[0] <= target)
        dp[0][a[0]] = 1;
    // if(a[0] == 0) dp[0][0] = 2;
    // else dp[0][0] = 2;
    // if(a[0]!=0 && a[0] <=target) dp[0][a[0]] = 1;
    for(int ind=1;ind<n;ind++){
        for(int j=1;j<=target;j++){
            int nottake = dp[ind-1][j];
            int take = 0;
            if(a[ind]<=j)
                take =dp[ind-1][j-a[ind]];
            dp[ind][j] = (take + nottake)%mod;
        }
    }
    return dp[n-1][target]; 
}
//space tab O(n*k) , O(k)
int spacetab(int n,int target,vector<int> &a){
    vector<int> prev(target+1,0),cur(target+1,0);
    prev[0] = cur[0] = 1;
    if(a[0]<=target)
        prev[a[0]] = 1;
    for(int ind=1;ind<n;ind++){
        for(int j=1;j<=target;j++){
            int nottake =  prev [j];
            int take = 0;
            if(a[ind]<=j)
                take =prev[j-a[ind]];
            cur[j] = (take + nottake)%mod;
        }
        prev = cur;
    }
    return prev[target]; 
}
int countPartition(int n,int d,vector<int> &a){
    int totalSum = 0;
    for(int i=0;i<n;i++)
        totalSum += a[i];
    if(totalSum -d <0 || (totalSum - d) %2)
        return 0;
    return spacetab(n,(totalSum-d)/2,a);
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    int d;
    cin >> d;
    cout << countPartition(n,d,a);
    return 0;
}
// 4
// 5 2 6 4
// 3