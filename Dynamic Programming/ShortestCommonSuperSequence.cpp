// SHORTEST COMMON SUPERSEQUENCE STRINGS PRINT
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
    int len = dp[n][m];
    cout << "length of = "<< n+m - len  << endl;
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++)
    //         cout<< dp[i][j] <<" ";
    //     cout << endl;
    // }
    string ans = "";
    int i =n,j=m;
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            i--,j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
             ans+= s1[i-1];
            i--;
        }  
        else{
            ans+= s2[j-1];
            j--;
        }
    }
    while(i>0){
        ans+= s1[i-1];
        i--;
    }
    while(j>0){
        ans+= s2[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
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

    cout << "Shortest Common SuperSequence string = " << tablcs(n, m, s1, s2) << endl;

    return 0;
}
   