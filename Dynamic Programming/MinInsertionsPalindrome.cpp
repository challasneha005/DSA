//MINIMUM INSERTINS TO MAKE A STRING PALINDROME
// N - LONGEST PALINDROME SUBSEQUENCE
//n - length of string,,
//lps = lcsunsequence of s,rev(s)
#include<bits/stdc++.h>
using namespace std;
//recursion O(2^n * 2^m),
int lcs(int i,int j,string &s1,string &s2){
    if(i<0 || j<0)
        return 0;
    if(s1[i] == s2[j])
        return 1+lcs(i-1,j-1,s1,s2);
    return max(lcs(i-1,j,s1,s2),lcs(i,j-1,s1,s2));
}
//dp memorize O(n*m), O(n*m)+O(n+m)
int dplcs(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
    if(i<0 || j<0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s1[i] == s2[j])
        return dp[i][j] = 1+dplcs(i-1,j-1,s1,s2,dp);
    return dp[i][j] = max(dplcs(i-1,j,s1,s2,dp),dplcs(i,j-1,s1,s2,dp));
}
//tab
int tablcs(int n,int m,string &s1,string &s2){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) 
        dp[i][0] = 0;
    for(int j=1;j<=m;j++)
        dp[0][j] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}
//space
int space(int n,int m,string &s1,string &s2){
    vector<int> prev(m+1,0),cur(m+1,0);
    for(int j=1;j<=m;j++)
        prev[j] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1])
                cur[j] = 1+prev[j-1];
            else
                cur[j] = max(prev[j],cur[j-1]);
        }
        prev= cur;
    }
    return prev[m];
}
int main(){
    string s1, s2;
    cout << "Enter string: ";
    cin >> s1;

    s2 = s1;                 // copy s1 → s2
    reverse(s2.begin(), s2.end());   // reverse s2
    
    int n = s1.size();
    int m = s2.size();

    cout << "Min Insertions = " << n - lcs(n-1, m-1, s1, s2) << endl;

    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout << "Min Insertions = " << n - dplcs(n-1, m-1, s1, s2,dp) << endl;

    cout << "Min Insertions = " << n - tablcs(n, m, s1, s2) << endl;

    cout << "Min Insertions = " << n - space(n, m, s1, s2) << endl;
    return 0;
}
