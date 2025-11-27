// MINIMUM INSERTION/DELETIONS / REPLACEMENT TO REACH B FROM A 
#include<bits/stdc++.h>
using namespace std;
int minEdit(int i,int j,string &s1,string &s2){
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
    if(s1[i] == s2[j])
        return minEdit(i-1,j-1,s1,s2);
    return 1 + min({
        minEdit(i, j-1, s1, s2),     // insert
        minEdit(i-1, j, s1, s2),     // delete
        minEdit(i-1, j-1, s1, s2)    // replace
});
}
//dp memo
int dpminEdit(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
    if(dp[i][j] !=-1)
        return dp[i][j];
    if(s1[i] == s2[j])
        return dp[i][j] = dpminEdit(i-1,j-1,s1,s2,dp);
    return dp[i][j] = 1+ min({
        dpminEdit(i,j-1,s1,s2,dp),
        dpminEdit(i-1,j,s1,s2,dp),
        dpminEdit(i-1,j-1,s1,s2,dp)
    });
}
//tab
int tab(int n,int m,string &s1,string &s2){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++)
        dp[i][0] = i;
    for(int j=0;j<=m;j++)
        dp[0][j] = j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else{    
                dp[i][j] =1 + min({
                    dp[i][j-1],
                    dp[i-1][j],
                    dp[i-1][j-1]});
            }
        }
    }
    return dp[n][m];
}
//space
int spacetab(int n,int m,string &s1,string &s2){
    vector<int> prev(m+1,0),cur(m+1,0);
    for(int j=0;j<=m;j++)
        prev[j] = j;
    for(int i=1;i<=n;i++){
        cur[0] = i;
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1])
                cur[j] = prev[j-1];
            else{    
                cur[j] =1 + min({
                    cur[j-1],
                    prev[j],
                    prev[j-1]});
            }
        }
        prev = cur;
    }
    return prev[m];
}
//no optimize
int main(){
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    int n = s1.size();
    int m = s2.size();

    cout << minEdit(n-1,m-1,s1,s2) << endl;

    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout << dpminEdit(n-1,m-1,s1,s2,dp) << endl;

    cout << tab(n,m,s1,s2) << endl;

    cout << spacetab(n,m,s1,s2) << endl;

    return 0;
}