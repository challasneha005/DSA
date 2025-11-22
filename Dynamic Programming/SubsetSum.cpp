//SUBSET SUM == TARGET? True or False
#include<bits/stdc++.h>
using namespace std;
//recursion O(2^n) ,O(n)
bool isSum(int ind,int target,vector<int> &a){
    if(target == 0)
        return true;
    if(ind == 0)
        return a[0] == target;
    bool nottake = isSum(ind-1,target,a);
    bool take = false;
    if(target>= a[ind])
        take = isSum(ind-1,target-a[ind],a);
    return take or nottake;
}
// dp memorization O(n*target) , O(n*target)+O(n)
bool dpisSum(int ind,int target,vector<int> &a,vector<vector<int>> &dp){
    if(target == 0)
        return true;
    if(ind == 0)
        return a[0] == target;
    if(dp[ind][target] !=-1)
        return dp[ind][target];
    bool nottake = dpisSum(ind-1,target,a,dp);
    bool take = false;
    if(target>= a[ind])
        take = dpisSum(ind-1,target-a[ind],a,dp);
    return dp[ind][target]=take or nottake;
}
//tab
bool tab(int n,int target,vector<int> &a){
    vector<vector<bool>> dp(n,vector<bool>(target+1,0));
    for(int i=0;i<n;i++)
        dp[i][0] = true;
    if(a[0] <= target)
        dp[0][a[0]] = true;
    for(int ind=1;ind<n;ind++){
        for(int j=1;j<=target;j++){
            bool nottake = dp[ind-1][j];
            bool take = false;
            if(a[ind]<=j)
                take =dp[ind-1][j-a[ind]];
            dp[ind][j] = take | nottake;
        }
    }
    return dp[n-1][target]; 
}
//space tab O(n*k) , O(k)
bool spacetab(int n,int target,vector<int> &a){
    vector<bool> prev(target+1,0),cur(target+1,0);
    prev[0] = cur[0] = true;
    if(a[0]<=target)
        prev[a[0]] = true;
    for(int ind=1;ind<n;ind++){
        for(int j=1;j<=target;j++){
            bool nottake =  prev [j];
            bool take = false;
            if(a[ind]<=j)
                take =prev[j-a[ind]];
            cur[j] = take | nottake;
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
    cout << isSum(n-1,target,a) << endl;

    //dp memorize
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout << dpisSum(n-1,target,a,dp) << endl;

    //tab
    cout << tab(n,target,a) << endl;

    //spacetab
    cout << spacetab(n,target,a) << endl;
    return 0;
}
// 4
// 2 3 1 1
// 4