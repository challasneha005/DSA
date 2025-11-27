// DISTINCT SUBSEQUENCES COUNT
// babgbag bag ->5
#include<bits/stdc++.h>
using namespace std;
// recursion O(2^n * 2^m), O(n+m)
int distinct(int i,int j,string &s1,string &s2){
    if(j<0)
        return 1;
    if(i<0)
        return 0;
    if(s1[i] == s2[j])
        return distinct(i-1,j-1,s1,s2) + distinct(i-1,j,s1,s2);
    else
        return distinct(i-1,j,s1,s2);
}  
int dpdistinct(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
    if(j<0)
        return 1;
    if(i<0)
        return 0;
    if(dp[i][j] !=-1)
        return dp[i][j];
    if(s1[i] == s2[j])
        return dp[i][j] = dpdistinct(i-1,j-1,s1,s2,dp) + dpdistinct(i-1,j,s1,s2,dp);
    else
        return dp[i][j] = dpdistinct(i-1,j,s1,s2,dp);
} 
//tab  
int tab(int n,int m,string &s1,string &s2){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;
    // for(int j=1;j<=m;j++)
    //     dp[0][j] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] ;
        }
    }
    return dp[n][m];
}   
int spacetab(int n,int m,string &s1,string &s2){
    vector<int> prev(m+1,0),cur(m+1,0);  
    prev[0] = cur[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1])
                cur[j] = prev[j-1] + prev[j];
            else
                cur[j] = prev[j] ;
        }
        prev = cur;
    }
    return prev[m];
}   
// optimise space  
 int optimize(int n,int m,string &s1,string &s2){
    vector<int> prev(m+1,0);  
    prev[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j-- ){
            if(s1[i-1] == s2[j-1])
                prev[j] = prev[j-1] + prev[j];
        }
    }
    return prev[m];
} 
int main(){
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    int n = s1.size();
    int m = s2.size();

    cout << distinct(n-1,m-1,s1,s2) << endl;

    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout << dpdistinct(n-1,m-1,s1,s2,dp) << endl;

    cout << tab(n,m,s1,s2) << endl;

    cout << spacetab(n,m,s1,s2) << endl;

    cout << optimize(n,m,s1,s2) << endl;
    return 0;
}