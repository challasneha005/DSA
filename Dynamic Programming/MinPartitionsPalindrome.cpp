// MIN No.OF PARTITIONS OF PALINDROME
// FRONT PARTITIONS
#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int i,int j,string &s){
    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
//recursion
int minPartitions(int i,string &s,int n){
    if(i==n)    
        return 0;
    int mini = INT_MAX;
    for(int j=i;j<n;j++){
        if(isPalindrome(i,j,s)){
            int cost = 1+minPartitions(j+1,s,n);
            mini = min(mini,cost);
        }
    }
    return mini;
}
// dp O(n*n) , O(n)+O(n)
int dpminPartitions(int i,string &s,int n,vector<int> &dp){
    if(i==n)    
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    int mini = INT_MAX;
    for(int j=i;j<n;j++){
        if(isPalindrome(i,j,s)){
            int cost = 1+dpminPartitions(j+1,s,n,dp);
            mini = min(mini,cost);
        }
    }
    return dp[i]=mini;
}
//tab
int tab(string &s,int n){
    vector<int> dp(n+1,0);
    for(int i=n-1;i>=0;i--){
        int mini = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost = 1+dp[j+1];
                mini = min(mini,cost);
            }
        }
        dp[i]=mini;
    }
    return dp[0];
}
// no space opt 
// dp[i] depends on all future values, not just the next one (dp[i+1]
int main(){
    string s;
    cin >> s;
    int n = s.length();
 
    cout << minPartitions(0, s, n) - 1 << endl;

    vector<int> dp(n,-1);
    cout << dpminPartitions(0, s, n,dp) - 1 << endl;

    cout << tab(s, n) - 1 << endl;

    return 0;
}