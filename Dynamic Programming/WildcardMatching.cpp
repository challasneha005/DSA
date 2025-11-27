#include<bits/stdc++.h>
using namespace std;
//recursion exponential,O(n+m)
bool wildcardMatch(int i,int j,string &s1,string &s2){
    if(i<0 && j<0)
        return true;
    if(i<0 && j>=0)
        return false;
    if(j<0 && i>=0){
        for(int k=0;k<=i;k++){
            if(s1[k] != '*')
                return false;
        }
        return true;
    }
    if(s1[i] == s2[j] || s1[i]=='?')
        return wildcardMatch(i-1,j-1,s1,s2);
    if(s1[i]=='*')
        return wildcardMatch(i-1,j,s1,s2) | wildcardMatch(i,j-1,s1,s2);
    return false;
}
//dp memo O(n*m) , O(n*m)+O(n+m)
bool dpwildcardMatch(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
    if(i<0 && j<0)
        return true;
    if(i<0 && j>=0)
        return false;
    if(j<0 && i>=0){
        for(int k=0;k<=i;k++){
            if(s1[k] != '*')
                return false;
        }
        return true;
    }
    if(dp[i][j] !=-1)
        return dp[i][j];
    if(s1[i] == s2[j] || s1[i]=='?')
        return dp[i][j] = dpwildcardMatch(i-1,j-1,s1,s2,dp);
    if(s1[i]=='*')
        return dp[i][j] = dpwildcardMatch(i-1,j,s1,s2,dp) | dpwildcardMatch(i,j-1,s1,s2,dp);
    return false;
}
//tab
bool tab(int n,int m,string &s1,string &s2){
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));

    dp[0][0] = true;
    for(int j=1;j<=m;j++)
        dp[0][j] = false;
    for(int i=1;i<=n;i++){
        bool flag = true;
        for(int l=1;l<=i;l++){
            if(s1[l-1] !='*'){
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1] || s1[i-1]=='?')
                dp[i][j] = dp[i-1][j-1];
            else if(s1[i-1]=='*')
                dp[i][j] = dp[i-1][j] | dp[i][j-1];
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}
//space
bool spacetab(int n,int m,string &s1,string &s2){
    vector<bool> prev(m+1,false),cur(m+1,false);

    prev[0] = true;
    for(int j=1;j<=m;j++)
        prev[j] = false;
    for(int i=1;i<=n;i++){
        bool flag = true;
        for(int l=1;l<=i;l++){
            if(s1[l-1] !='*'){
                flag = false;
                break;
            }
        }
        cur[0] = flag;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1] || s1[i-1]=='?')
                cur[j] = prev[j-1];
            else if(s1[i-1]=='*')
                cur[j] = prev[j] | cur[j-1];
            else
                cur[j] = false;
        }
        prev = cur;
    }
    return prev[m];
}
// no optimize
int main(){
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    int n = s1.size();
    int m = s2.size();

    cout << wildcardMatch(n-1,m-1,s1,s2) << endl;

    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout << dpwildcardMatch(n-1,m-1,s1,s2,dp) << endl;

    cout <<  tab(n,m,s1,s2) << endl;

    cout <<  spacetab(n,m,s1,s2) << endl;

    return 0;
}