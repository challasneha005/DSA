// RODS PRICE WITH MAX SUM-INFINITE SUPPLY
//UNBOUNDED KNAPSACK like as
#include<bits/stdc++.h>
using namespace std;
//  recursion O(2^n) , O(n)
int maxRodPrice(int ind,int N,vector<int> &price){
    if(ind ==0)
        return  N * price[0];
    int nottake = 0+maxRodPrice(ind-1,N,price);
    int take = INT_MIN;
    int rodlength = ind+1;
    if(rodlength <=N)
        take = price[ind]+maxRodPrice(ind,N-rodlength,price);
    return max(take,nottake);
}
// dp O(n*w) , O(n*w)+O(n)
int dpmaxRodPrice(int ind,int N,vector<int> &price,vector<vector<int>> &dp){
    if(ind ==0) 
        return  N * price[0];
    if(dp[ind][N]!=-1)
         return dp[ind][N];
    int nottake = 0+dpmaxRodPrice(ind-1,N,price,dp);
    int take = INT_MIN;
    int rodlength = ind+1;
    if(rodlength <=N)
        take = price[ind]+dpmaxRodPrice(ind,N-rodlength,price,dp);
    return dp[ind][N]=max(take,nottake);
}
//tab
int tab(int n,int N,vector<int> &price){
    vector<vector<int>> dp(n,vector<int>(N+1,0));
    for(int len =0;len<=N;len++)
        dp[0][len] =  len * price[0];
    for(int ind = 1;ind<n;ind++){
        for(int len=0;len<=N;len++){
            int nottake = 0+dp[ind-1][len];
            int take = 0;
            int rodlength = ind + 1;
            if (rodlength <= len)
                take = price[ind]+dp[ind][len-rodlength];
            dp[ind][len] = max(take,nottake);
        }
    }
    return dp[n-1][N];
}   
int spacetab(int n,int N,vector<int> &price){
    vector<int> prev(N+1,0),cur(N+1,0);
    for(int len=0;len<=N;len++)
        prev[len] =  len * price[0];
    for(int ind = 1;ind<n;ind++){
        for(int len=0;len<=N;len++){
            int nottake = 0+prev[len];
            int take = 0;
            int rodlength = ind+1;
            if(rodlength <=len)
                take = price[ind]+cur[len-rodlength];
            cur[len] = max(take,nottake);
        }
        prev = cur;
    }
    return prev[N];
}   
//single array space
int optimized(int n,int N,vector<int> &price){
    vector<int> prev(N+1,0);
    for(int len= 0;len<=N;len++)
        prev[len] = len * price[0];;
    for(int ind = 1;ind<n;ind++){
        for(int len=0;len<=N;len++ ){
            int nottake = 0+prev[len];
            int take = INT_MIN;
            int rodlength = ind+1;
            if(rodlength <=len)
                take = price[ind]+prev[len-rodlength];
            prev[len] = max(take,nottake);
        }
    }
    return prev[N];
}   
int main() {
    int n;
    cin >> n;   // number of items
    vector<int>  price(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];

    int N;     // total rod length
    cin >> N;

    cout << maxRodPrice(n-1, N, price) << endl;

    vector<vector<int>> dp(n,vector<int>(N+1,-1));
    cout << dpmaxRodPrice(n-1, N, price,dp) << endl;

    cout << tab(n,N,price)<<endl;

    cout << spacetab(n,N,price)<<endl;

    cout << optimized(n,N,price)<<endl;
    return 0; 
}
// 5
// 2 5 7 8 10
// 5

