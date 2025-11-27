// LONGEST COMMON SUBSEQUENCE STRINGS PRINT
#include<bits/stdc++.h>
using namespace std;
string tablcs(int n,int m,string &s1,string &s2){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) 
        dp[0][i] = 0;
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
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++)
    //         cout<< dp[i][j] <<" ";
    //     cout << endl;
    // }
    int len = dp[n][m];
    string ans = "";
    for(int i=0;i<len;i++)
        ans+="$";
    int index = len-1;
    int i =n,j=m;
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans[index] = s1[i-1];
            index--;
            i--,j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
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

    cout << "LCS string = " << tablcs(n, m, s1, s2) << endl;

    return 0;
}
