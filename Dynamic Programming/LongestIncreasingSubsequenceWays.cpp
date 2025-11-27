// NO.OF LONGEST INCREASING SUBSEQUENCE
#include<bits/stdc++.h>
using namespace std;
// ALGORITHMIC APPROACH   
// one dp array O(n*n),O(n)
int wayslis(vector<int> &a,int n){
    vector<int> dp(n,1),cnt(n,1);
    int maxi = 1;
    for(int i=0;i<n;i++){
        for(int prev=0;prev <=i-1;prev++){
            if(a[prev] < a[i] && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                cnt[i] = cnt[prev];       
            }
            else if(a[prev] < a[i] && 1+dp[prev] == dp[i])
                cnt[i] += cnt[prev];
        }  
        maxi = max(maxi,dp[i]);
    }
    int num = 0;
    for(int i=0;i<n;i++){
        if(dp[i] == maxi)
            num += cnt[i];
    }
    return num;
}
int lis(vector<int> &a,int n){
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
int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
 
    cout << "ways : " <<wayslis(a,n) << endl;
    cout << "length : " << lis(a,n) << endl;
    return 0;
}