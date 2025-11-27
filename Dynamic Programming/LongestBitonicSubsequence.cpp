// LONGEST BITONIC SUBSEQUENCE
#include<bits/stdc++.h>
using namespace std;
// Using Algorithm lbs 
int lbsAlgo(vector<int> &a,int n){
    vector<int> dp1(n,1);
    for(int i=0;i<n;i++){
        for(int prev=0;prev <i;prev++){
            if(a[prev] < a[i] )
                dp1[i] = max(dp1[i], 1 + dp1[prev]);
        }
    }
    for(int x:dp1)
        cout << x << " ";
    vector<int> dp2(n,1);
    for(int i=n-1 ;i>=0;i--){
        // for(int prev=n-1;prev >i;prev--){
        for(int prev=i+1;prev<n;prev++){
            if(a[prev] < a[i])
                dp2[i] = max(dp2[i], 1 + dp2[prev]);
        }
    }
    cout << endl;
    for(int x1:dp2)
        cout << x1 << " ";
    int maxi = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi,dp1[i]+dp2[i] -1);
    }
    cout << endl;
    return maxi;
}
// recursion O(2^n) , O(n)
int lisRec(int ind,int prevInd,vector<int> &a,int n){
    if(ind == n)
        return 0;
    int nottake = lisRec(ind+1,prevInd,a,n);
    int take = 0;
    if(prevInd == -1 || a[ind]>a[prevInd])
        take = 1+lisRec(ind+1,ind,a,n);
    return max(nottake,take); 
}
int ldsRec(int ind, int prevInd, vector<int>& a, int n){
    if(ind == n) 
        return 0;  // end of array
    int notTake = ldsRec(ind + 1, prevInd, a, n);
    int take = 0;
    if(prevInd == -1 || a[ind] < a[prevInd])
        take = 1 + ldsRec(ind + 1, ind, a, n);
    return max(take, notTake);
}
int lbsRecursion(vector<int>& a, int n){
    int maxi = 1;
    for(int i = 0; i < n; i++){
        int inc = lisRec(0,-1,a,i+1);      // start to i  
        int dec = ldsRec(i,-1,a,n);    //  i to end
        maxi = max(maxi, inc + dec - 1);
    }
    return maxi;
}
//  dp O(n*n) , O(n*n)+O(n)
int dplisCount(int ind,int prevInd,vector<int> &a,int n,vector<vector<int>> &dp){
    if(ind == n) //shift
        return 0;
    if(dp[ind][prevInd+1]!=-1)
        return dp[ind][prevInd+1];
    int nottake = dplisCount(ind+1,prevInd,a,n,dp);
    int take = 0;
    if(prevInd == -1 || a[ind]>a[prevInd])
        take = 1+dplisCount(ind+1,ind,a,n,dp);
    return dp[ind][prevInd+1] = max(nottake,take); 
}
int dpldsCount(int ind, int prevInd, vector<int>& a, int n, vector<vector<int>>& dp){
    if(ind == n) 
        return 0;
    if(dp[ind][prevInd + 1] != -1)
        return dp[ind][prevInd + 1];
    int notTake = dpldsCount(ind+1, prevInd, a, n, dp);
    int take = 0;
    if(prevInd == -1 || a[ind] < a[prevInd])
        take = 1 + dpldsCount(ind+1, ind, a, n, dp);
    return dp[ind][prevInd + 1] = max(take, notTake);
}
int dplbs(vector<int>& a, int n){
    int maxi = 1;
    for(int i = 0; i < n; i++){
        vector<vector<int>> dp1(n, vector<int>(n+1, -1));
        vector<vector<int>> dp2(n, vector<int>(n+1, -1));
        int inc = dplisCount(0,-1,a,i+1,dp1); //to end at i
        int dec = dpldsCount(i,-1,a,n,dp2); //start at i to end
        maxi = max(maxi, inc + dec - 1);
    }
    return maxi;
}
// tab
int tablis(vector<int> &a,int n){
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
int tablds(vector<int> &a,int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int prevInd = ind-1;prevInd>=-1;prevInd--){
            int nottake = dp[ind+1][prevInd+1];
            int take = 0;
            if(prevInd == -1 || a[ind]<a[prevInd])
                take = 1+dp[ind+1][ind+1];
            dp[ind][prevInd+1] = max(nottake,take); 
        }
    }
    return dp[0][0];
}
// computes globally increasing and decresing orders 
// SO SAME AS LBSALGO FOR BOTH TAB AND SPACE
// space O(n*n) , O(2*n)
int spacelis(vector<int> &a,int n){
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
int spacelds(vector<int> &a,int n){
    vector<int> next(n+1,0), cur(n+1,0);
    for(int ind = n-1; ind >=0; ind--){
        for(int prevInd = ind-1; prevInd>=-1; prevInd--){
            int nottake = next[prevInd+1];
            int take = 0;
            if(prevInd == -1 || a[ind] < a[prevInd])
                take = 1 + next[ind+1];
            cur[prevInd+1] = max(nottake, take);
        }
        next = cur;
    }
    return next[0];
}  
// one dp array O(n*n),O(n)
// alternate of take and not take..dp
int lisdp(vector<int> &a,int n){
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
// BINARY SEARCH WONT WORK
int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    cout << "main : ";
    cout << lbsAlgo(a,n) << endl;

    cout << lbsRecursion(a,n) << endl;

    cout << dplbs(a,n) << endl;
    
    cout << lisdp(a,n) << endl;
    
    return 0;
}