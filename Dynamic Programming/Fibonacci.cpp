//FIBONACCI
#include<bits/stdc++.h>
using namespace std;
//USING DYNAMIC O(n),O(n)+O(n)
int fibo(int n,vector<int> &dp){
    if (n<=1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibo(n-1,dp)+fibo(n-2,dp);
}
//SPACE OPTIMIZATION O(n),O(n)
int fibonacci(int n){
    int prev2 = 0;
    int prev1 = 1;
    for(int i=2;i<=n;i++){
        int curi = prev1 + prev2;
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}
int main(){
    int n;
    cin >> n;
    vector <int> dp(n+1,-1);
    // cout << fibo(n,dp);
    cout << fibonacci(n);
    return 0;
}