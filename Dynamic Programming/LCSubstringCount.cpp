// LONGEST COMMON SUBSTRING --STRINGS
#include<bits/stdc++.h>
using namespace std;
int lcsEnd(int i, int j, string &s1, string &s2) {
    if (i < 0 || j < 0)
        return 0;
    if (s1[i] == s2[j])
        return 1 + lcsEnd(i - 1, j - 1, s1, s2);
    return 0;
}
int lcs(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    int maxi = 0;

    // MUST try every pair (i, j)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            maxi = max(maxi, lcsEnd(i, j, s1, s2));
    }
    return maxi;
}
//tab
int tablcs(int n,int m,string &s1,string &s2){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) 
        dp[i][0] = 0;
    for(int j=1;j<=m;j++)
        dp[0][j] = 0;
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}
//space
int space(int n,int m,string &s1,string &s2){
    vector<int> prev(m+1,0),cur(m+1,0);
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                cur[j] = 1+prev[j-1];
                ans = max(ans,cur[j]); 
            }
            else
                cur[j] = 0;
        }
        prev= cur;
    }
    return ans;
}
int main(){
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    int n = s1.size();
    int m = s2.size();

    cout << "LCSubstring length = " << lcs(s1, s2) << endl;

    cout << "LCSubstring length = " << tablcs(n, m, s1, s2) << endl;

    cout << "LCSubstring length = " << space(n, m, s1, s2) << endl;
    return 0;
}