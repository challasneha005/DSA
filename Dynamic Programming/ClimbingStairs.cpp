//CLIMBING STAIRS NO.OF WAYS TO REACH N
#include<bits/stdc++.h>
using namespace std;
int ways(int ind){
    if (ind == 0 || ind == 1)
        return 1;
    int left = ways(ind-1);
    int right = ways(ind-2);
    return left+right;
}
int dpways(int ind, vector<int> &dp){
    if (ind == 0 || ind == 1)
        return 1;
    if (dp[ind] != -1)
        return dp[ind];
    return dp[ind] = dpways(ind - 1, dp) + dpways(ind - 2, dp);
}    
int tab(int n){
    vector<int> dp(n+1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}
int spacetab(int n){
    if (n == 0 || n == 1)
        return 1;
    int prev2 = 1; // ways(0)
    int prev1 = 1; // ways(1)
    for (int i = 2; i <= n; i++) {
        int cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
int main(){
    int n;
    cin >> n;
    cout << "No.of ways to reach "<< n <<" is :";
    cout << ways(n) << endl;

    vector<int> dp(n+1, -1);
    cout << dpways(n, dp) <<endl;

    cout << tab(n) <<endl;

    cout << spacetab(n);
}
