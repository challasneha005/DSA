//FROG JUMP MINIMUM ENERGY
#include<bits/stdc++.h>
using namespace std;
//recursive
int lessEnergy(int ind,int arr[]){
    if (ind == 0)
        return 0;
    int left = lessEnergy(ind-1,arr)+abs(arr[ind]- arr[ind-1]);
    int right = INT_MAX;
    if (ind>1)    
        right = lessEnergy(ind-2,arr)+abs(arr[ind]- arr[ind-2]);
    return min(left,right);
}
//dynamic  memorization  O(n) , O(n)+O(n)
int dplessEnergy(int ind,int arr[],vector<int> &dp){
    if (ind == 0)
        return 0;
    if (dp[ind]!= -1)
        return dp[ind];
    int left = dplessEnergy(ind-1,arr,dp)+abs(arr[ind]- arr[ind-1]);
    int right = INT_MAX;
    if (ind>1)    
        right = dplessEnergy(ind-2,arr,dp)+abs(arr[ind]- arr[ind-2]);
    return dp[ind]=min(left,right);
} 
//dynamic tabulation
int tab(int n,int arr[]){
    vector<int> dp(n,0);
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int left = dp[i-1]+abs(arr[i] - arr[i-1]);
        int right = INT_MAX;
        if(i>1)
            right = dp[i-2]+abs(arr[i] - arr[i-2]);
        dp[i] = min(left,right);
    }
    return dp[n-1];
}
//space optimization for tab
int spacetab(int n,int arr[]){
    int prev1 = 0;
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int left = prev1+abs(arr[i] - arr[i-1]);
        int right = INT_MAX;
        if(i>1)
            right = prev2+abs(arr[i] - arr[i-2]);
        int curi = min(left,right);
        prev2 = prev1;
        prev1 = curi; 
    }
    return prev1;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    // cout << lessEnergy(n-1,a); 
    // vector<int> dp(n, -1);
    // cout << dplessEnergy(n - 1, a, dp);
    // cout << tab(n,a);
    cout << spacetab(n,a);
    return 0;
}