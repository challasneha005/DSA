//MAXIMUM NON ADJACENT SUM
#include<bits/stdc++.h>
using namespace std;
//recursive O(2^n)
int maxNonAdjSum(int ind,vector<int> &a){
    if(ind == 0)
        return a[ind];
    if(ind<0)
        return 0;
    int pick = a[ind] + maxNonAdjSum(ind-2,a);
    int notpick = 0 + maxNonAdjSum(ind-1,a);
    return max(pick,notpick);
}
//dynamic  memorization  O(n) , O(n)+O(n)
int dpmaxNonAdjSum(int ind,vector<int> &a,vector<int> &dp){
    if(ind == 0)
        return a[ind];
    if(ind<0)
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];
    int pick = a[ind] + dpmaxNonAdjSum(ind-2,a,dp);
    int notpick = 0 + dpmaxNonAdjSum(ind-1,a,dp);
    return dp[ind]=max(pick,notpick);
}
//dynamic tabulation O(n),O(n)
int tab(int n,vector<int> &a){
    vector<int> dp(n,0);
    dp[0] = a[0];
    for(int i=1;i<n;i++){
        int take = a[i];
        if(i>1)
            take+=dp[i-2];
        int nontake = 0+dp[i-1];
        dp[i] = max(take,nontake);
    }
    return dp[n-1];
}
//space optimization for tab O(n),O(1)
int spacetab(int n,vector<int> &a){
    int prev1 = a[0];
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int take = a[i];
        if(i>1)
            take+=prev2;
        int nontake = 0+prev1;
        int curi = max(take,nontake);
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    // cout << maxNonAdjSum(n-1,a);
    // vector<int> dp(n,-1);
    // cout << dpmaxNonAdjSum(n-1,a,dp); 
    // cout << tab(n,a);
    cout << spacetab(n,a);
    return 0;
}