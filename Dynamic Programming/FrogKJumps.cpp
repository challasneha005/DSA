//FROG KJUMPS MINIMUM ENERGY
#include<bits/stdc++.h>
using namespace std;
//recursive O(k^n),O(n)+O(n)
int lessEnergy(int ind,int arr[],int k){
    if (ind == 0)
        return 0;
    int minSteps = INT_MAX;
    for(int j=1;j<=k;j++){
        if(ind - j >=0){
            int jumps = lessEnergy(ind-j,arr,k)+abs(arr[ind]- arr[ind-j]);
            minSteps = min(minSteps,jumps);
        }
    }
    return minSteps;
}
//dynamic  memorization   
int dplessEnergy(int ind,int arr[],int k,vector<int> &dp){
    if (ind == 0)
        return 0;
    if (dp[ind]!= -1)
        return dp[ind];
    int minSteps = INT_MAX;
    for(int j=1;j<=k;j++){
        if(ind - j >=0){
            int jumps = dplessEnergy(ind-j,arr,k,dp)+abs(arr[ind]- arr[ind-j]);
            minSteps = min(minSteps,jumps);
        }
    }
    return dp[ind] = minSteps;
} 
//dynamic tabulation O(n*k),O(n)
int tab(int n,int arr[],int k){
    vector<int> dp(n,0);
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int minSteps = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i - j >=0){
                int jumps = dp[i-j]+abs(arr[i]- arr[i-j]);
                minSteps = min(minSteps,jumps);
            }
         }
        dp[i] = minSteps;
    }
    return dp[n-1];
}
//space optimization for tab O(n)->O(k) but what if n jumpss..O(n*n) worst
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << "Enter no.of jumps: ";
    int k;
    cin >> k;
    // cout << lessEnergy(n-1,a,k); 
    // vector<int> dp(n, -1);
    // cout << dplessEnergy(n - 1, a, k,dp);
    cout << tab(n,a,k);
     
    return 0;
}