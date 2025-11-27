// LONGEST INCREASING SUBSEQUENCE
#include<bits/stdc++.h>
using namespace std;
// recursion O(2^n) , O(n)
int lis(int ind,int prevInd,vector<int> &a,int n){
    if(ind == n)
        return 0;
    int nottake = lis(ind+1,prevInd,a,n);
    int take = 0;
    if(prevInd == -1 || a[ind]>a[prevInd])
        take = 1+lis(ind+1,ind,a,n);
    return max(nottake,take); 
}
//  dp O(n*n) , O(n*n)+O(n)
int dplis(int ind,int prevInd,vector<int> &a,int n,vector<vector<int>> &dp){
    if(ind == n) //shift
        return 0;
    if(dp[ind][prevInd+1]!=-1)
        return dp[ind][prevInd+1];
    int nottake = dplis(ind+1,prevInd,a,n,dp);
    int take = 0;
    if(prevInd == -1 || a[ind]>a[prevInd])
        take = 1+dplis(ind+1,ind,a,n,dp);
    return dp[ind][prevInd+1] = max(nottake,take); 
}
// tab
int tab(vector<int> &a,int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int prevInd = ind-1;prevInd>=-1;prevInd--){
            int nottake = dp[ind+1][prevInd+1];
            int take = 0;
            if(prevInd == -1 || a[ind]>a[prevInd])
                take = 1+dp[ind+1][ind+1];
            dp[ind][prevInd+1] = max(nottake,take); 
        }
    }
    return dp[0][0];
}
// space O(n*n) , O(2*n)
int spacetab(vector<int> &a,int n){
    vector<int> next(n+1,0),cur(n+1,0);
    for(int ind=n-1;ind>=0;ind--){
        for(int prevInd = ind-1;prevInd>=-1;prevInd--){
            int nottake = next[prevInd+1];
            int take = 0;
            if(prevInd == -1 || a[ind]>a[prevInd])
                take = 1+next[ind+1];
            cur[prevInd+1] = max(nottake,take); 
        }
        next = cur;
    }
    return next[0];
}
// ALGORITHMIC APPROACH   
// one dp array O(n*n),O(n)
int lisdp1(vector<int> &a,int n){
    vector<int> dp(n,1);
    int maxi = 1;
    for(int i=0;i<n;i++){
        for(int prev=0;prev <=i-1;prev++){
            if(a[prev] < a[i])
                dp[i] = max(dp[i],1+dp[prev]);
        }
        maxi = max(maxi,dp[i]);
    }
    return maxi;
}
// PRINT LIST OF LIS 
int lisprint(vector<int> &a,int n){
    vector<int> dp(n,1),hash(n);
    int maxi = 1;
    int lastInd = 0;
    for(int i=0;i<n;i++){
        hash[i] = i;
        for(int prev=0;prev <=i-1;prev++){
            if(a[prev] < a[i] && dp[i] < 1+dp[prev] ){
                dp[i] = 1+dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastInd = i;
        }
    }
    vector<int> temp;
    temp.push_back(a[lastInd]);
    while(hash[lastInd] != lastInd){
        lastInd = hash[lastInd];
        temp.push_back(a[lastInd]);
    }
    reverse(temp.begin(),temp.end());
    for(auto it:temp)
        cout << it << " ";
    cout << endl;
    return maxi;
}
// USING BINARY SEARCH O(n log n) , O(n)
int lisBS(vector<int> &a,int n){
    vector<int> temp;
    temp.push_back(a[0]);
    int len = 1;
    for(int i=1;i<n;i++){
        if(a[i] > temp.back()){
            temp.push_back(a[i]);
            len++;
        }
        else{
            int ind = lower_bound(temp.begin(),temp.end(),a[i]) - temp.begin();
            temp[ind] = a[i];
        }
    }
    return len;
} 
int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    cout << lis(0,-1,a,n) << endl;

    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    cout << dplis(0,-1,a,n,dp) << endl;

    cout << tab(a,n) << endl;

    cout << spacetab(a,n) << endl;

    cout << lisdp1(a,n) << endl;

    cout << lisprint(a,n) << endl;

    cout << lisBS(a,n) << endl;

    return 0;
}