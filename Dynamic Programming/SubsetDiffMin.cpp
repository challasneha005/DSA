//MINIMUM SUBSET SUM DIFFERENCE
#include<bits/stdc++.h>
using namespace std;
//dp mem
int minSubsetDiff(vector<int>&a,int n){
    int totSum = 0;
    for(int i=0;i<n;i++)
        totSum += a[i];
    int target = totSum;
    //subset sum.
    vector<vector<bool>> dp(n,vector<bool>(target+1,0));
    for(int i=0;i<n;i++)
        dp[i][0] = true;
    if(a[0] <= target)
        dp[0][a[0]] = true;
    for(int ind=1;ind<n;ind++){
        for(int j=1;j<=target;j++){
            bool nottake = dp[ind-1][j];
            bool take = false;
            if(a[ind]<=j)
                take =dp[ind-1][j-a[ind]];
            dp[ind][j] = take | nottake;
        }
    }
    //dp[n-1][col->.totSum]
    int mini = 1e9;
    for(int s1 = 0;s1<=totSum/2;s1++){
        if(dp[n-1][s1] == true)
            mini = min(mini,abs((totSum-s1) - s1));
    }
    return mini;
}
int tabminSubsetDiff(vector<int>&a,int n){
    int totSum = 0;
    for(int i=0;i<n;i++)
        totSum += a[i];
    int target = totSum;
    //subset sum.
    vector<bool> prev(target+1,0),cur(target+1,0);
    prev[0] = cur[0] = true;
    if(a[0]<=target)
        prev[a[0]] = true;
    for(int ind=1;ind<n;ind++){
        cur = vector<bool>(target+1,0);
        for(int j=1;j<=target;j++){
            bool nottake =  prev [j];
            bool take = false;
            if(a[ind]<=j)
                take =prev[j-a[ind]];
            cur[j] = take | nottake;
        }
        prev = cur;
    }
    int mini = 1e9;
    for(int s1 = 0;s1<=totSum/2;s1++){
        if(prev[s1] == true)
            mini = min(mini,abs((totSum-s1) - s1));
    }
    return mini;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << minSubsetDiff(a,n) << endl;
    cout << tabminSubsetDiff(a,n);
    return 0;
}