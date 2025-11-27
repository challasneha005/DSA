// BUY AND SELL STOCKS TO MAX PROFIT
// BUY & SELL MULTIPLE TIMES..NO CONSECUTIVES BUY OR SELL 
// WITH COOL DOWN -- NO IMMEDIATE BUY AFTER SELL
#include<bits/stdc++.h>
using namespace std;
// recursion O(2^n) , O(n)
long maximizeprofit(int ind,int buy,vector<int> &prices,int n){
    if(ind >= n) //if ind = n-1.. so 
        return 0;
    long profit = 0;
    if(buy){
        profit = max(-prices[ind] + maximizeprofit(ind+1,0,prices,n),
                0+maximizeprofit(ind+1,1,prices,n));
    }
    else{
        //ind+2 when sell no immediate buy
        profit = max(prices[ind]+maximizeprofit(ind+2,1,prices,n),
                0+maximizeprofit(ind+1,0,prices,n));
    }
    return profit;
}
// dp memo O(n*2) , O(n*2)+O(n)
long dpmaximizeprofit(int ind,int buy,vector<int> &prices,int n,vector<vector<int>> &dp){
    if(ind >= n)
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    long profit = 0;
    if(buy){
        profit = max(-prices[ind] + dpmaximizeprofit(ind+1,0,prices,n,dp),
                0+dpmaximizeprofit(ind+1,1,prices,n,dp));
    }
    else{
        profit = max(prices[ind]+dpmaximizeprofit(ind+2,1,prices,n,dp),
                0+dpmaximizeprofit(ind+1,0,prices,n,dp));
    }
    return dp[ind][buy]=profit;
}
// tab  O(n*2)
long tab(vector<int> &prices,int n){
    //n+2  as ind>=2
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    dp[n][0] = dp[n][1] = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            long profit = 0;
            if(buy)
                profit = max((-prices[ind] + dp[ind+1][0]),dp[ind+1][1]);
            else
                profit = max((prices[ind]+dp[ind+2][1]),dp[ind+1][0]);
            dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}
//  for loop optimze of buy in tab
long tabopt(vector<int> &prices,int n){
    //n+2  as ind>=2
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    dp[n][0] = dp[n][1] = 0;
    for(int ind=n-1;ind>=0;ind--){
        dp[ind][1]= max((-prices[ind] + dp[ind+1][0]),dp[ind+1][1]);
        dp[ind][0] = max((prices[ind]+dp[ind+2][1]),dp[ind+1][0]);
    }
    return dp[0][1];
}
// space 3 vectors  
long spacetab(vector<int> &prices,int n){
    //n+2  as ind>=2
    vector<int> front2(2,0),front1(2,0),cur(2,0);
    for(int ind=n-1;ind>=0;ind--){
        cur[1] = max((-prices[ind] + front1[0]),front1[1]);
        cur[0] = max((prices[ind]+front2[1]),front1[0]);
        front2 = front1;
        front1 = cur;
    }
    return cur[1];
}

int main(){
    int n;
    cin >>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++)
        cin >> prices[i];

    cout << maximizeprofit(0,1,prices,n) << endl;

    vector<vector<int>> dp(n,vector<int>(2,-1));
    cout << dpmaximizeprofit(0,1,prices,n,dp) << endl;

    cout << tab(prices,n) << endl;

    cout << tabopt(prices,n) << endl;

    cout << spacetab(prices,n) << endl;

    return 0;
} 