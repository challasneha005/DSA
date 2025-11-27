// MAX SUM OF ARRAY WITH PARTITIOINS AT MAX K
// FRONT PARTITIONS
#include<bits/stdc++.h>
using namespace std;
int maxSum(int ind,vector<int> &a,int n,int k){
    if(ind == n)
        return 0;
    int len =0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;
    for(int j=ind;j<min(n,j+k);j++){
        len++;
        maxi = max(maxi,a[j]);
        int sum = len*maxi + maxSum(j+1,a,n,k);
        maxAns = max(maxAns,sum);
    }
    return maxAns;
}
//dp O(n*k) , O(n)+O(n)
int dpmaxSum(int ind,vector<int> &a,int n,int k,vector<int> &dp){
    if(ind == n)
        return 0;
    if(dp[ind]!=-1)
        return dp[ind];
    int len =0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;
    for(int j=ind;j<min(n,j+k);j++){
        len++;
        maxi = max(maxi,a[j]);
        int sum = len*maxi + dpmaxSum(j+1,a,n,k,dp);
        maxAns = max(maxAns,sum);
    }
    return dp[ind] = maxAns;
}
// tab O(n*k) , O(n)+
int tab(vector<int> a,int n,int k){
    vector<int> dp(n+1,0);
    for(int ind=n-1;ind>=0;ind--){
        int len =0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;
    for(int j=ind;j<min(n,j+k);j++){
            len++;
            maxi = max(maxi,a[j]);
            int sum = len*maxi + dp[j+1];
            maxAns = max(maxAns,sum);
        }
        dp[ind] = maxAns;
    }
    return dp[0];
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
        
    int k;
    cin >> k;

    cout << maxSum(0,a,n,k) << endl;

    vector<int> dp(n,-1);
    cout << dpmaxSum(0,a,n,k,dp) << endl;

    cout << tab(a,n,k);
    return 0;
}