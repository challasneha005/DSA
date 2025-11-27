// BUY AND SELL STOCKS TO MAX PROFIT
// BUY & SELL MULTIPLE TIMES..NO CONSECUTIVES BUY OR SELL
#include<bits/stdc++.h>
using namespace std;
// recursion O(2^n) , O(n)
long maximizeprofit(int ind,int buy,vector<int> &prices,int n){
    if(ind == n)
        return 0;
    long profit = 0;
    if(buy){
        profit = max(-prices[ind] + maximizeprofit(ind+1,0,prices,n),
                0+maximizeprofit(ind+1,1,prices,n));
    }
    else{
        profit = max(prices[ind]+maximizeprofit(ind+1,1,prices,n),
                0+maximizeprofit(ind+1,0,prices,n));
    }
    return profit;
}
// dp memo O(n*2) , O(n*2)+O(n)
long dpmaximizeprofit(int ind,int buy,vector<int> &prices,int n,vector<vector<int>> &dp){
    if(ind == n)
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    long profit = 0;
    if(buy){
        profit = max(-prices[ind] + dpmaximizeprofit(ind+1,0,prices,n,dp),
                0+dpmaximizeprofit(ind+1,1,prices,n,dp));
    }
    else{
        profit = max(prices[ind]+dpmaximizeprofit(ind+1,1,prices,n,dp),
                0+dpmaximizeprofit(ind+1,0,prices,n,dp));
    }
    return dp[ind][buy]=profit;
}
// tab  O(n*2)
long tab(vector<int> &prices,int n){
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    dp[n][0] = dp[n][1] = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            long profit = 0;
            if(buy)
                profit = max((-prices[ind] + dp[ind+1][0]),dp[ind+1][1]);
            else
                profit = max((prices[ind]+dp[ind+1][1]),dp[ind+1][0]);
            dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}
//space 
long spacetab(vector<int> &prices,int n){
    vector<int> ahead(2,0) , cur(2,0);
    ahead[0] = ahead[1] = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            long profit = 0;
            if(buy)
                profit = max((-prices[ind] + ahead[0]),ahead[1]);
            else
                profit = max((prices[ind]+ahead[1]),ahead[0]);
            cur[buy]=profit;
        }
        ahead = cur;
    }
    return ahead[1];
}
//4 variables space optimize
long spacetaboptimize(vector<int> &prices,int n){
    long aheadBuy ,aheadNotBuy , CurBuy, CurNotBuy;
    aheadNotBuy = aheadBuy = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            long profit = 0;
            CurBuy = max((-prices[ind] + aheadNotBuy),aheadBuy);
            CurNotBuy = max((prices[ind]+aheadBuy),aheadNotBuy);
        }
        aheadBuy = CurBuy;
        aheadNotBuy = CurNotBuy;
    }
    return aheadBuy;
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

    cout << spacetab(prices,n) << endl;

    cout << spacetaboptimize(prices,n) << endl;

    return 0;
} 