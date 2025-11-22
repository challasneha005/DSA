 //SUBSET SUM == TARGET COUNT
#include<bits/stdc++.h>
using namespace std;
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
    return take +nottake;
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
    return dp[ind][target]=take+nottake;
}
//tab
int tab(int n,int target,vector<int> &a){
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    for(int i=0;i<n;i++)
        dp[i][0] = 1;
    if(a[0] <= target)
        dp[0][a[0]] = 1;
    for(int ind=1;ind<n;ind++){
        for(int j=1;j<=target;j++){
            int nottake = dp[ind-1][j];
            int take = 0;
            if(a[ind]<=j)
                take =dp[ind-1][j-a[ind]];
            dp[ind][j] = take + nottake;
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
            cur[j] = take + nottake;
        }
        prev = cur;
    }
    return prev[target]; 
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    int target;
    cin >> target;
    cout << kSumCount(n-1,target,a) << endl;

    //dp memorize
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout << dpkSumCount(n-1,target,a,dp) << endl;

    //tab
    cout << tab(n,target,a) << endl;

    //spacetab
    cout << spacetab(n,target,a) << endl;
    return 0;
}
 