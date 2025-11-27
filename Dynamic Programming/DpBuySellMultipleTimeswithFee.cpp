// BUY AND SELL STOCKS TO MAX PROFIT WITH TRANSACTION FEE
// BUY & SELL MULTIPLE TIMES..NO CONSECUTIVES BUY OR SELL
#include<bits/stdc++.h>
using namespace std;
// recursion O(2^n) , O(n)
long maximizeprofit(int ind,int buy,vector<int> &prices,int n,int fee){
    if(ind == n)
        return 0;
    long profit = 0;
    if(buy){
        profit = max(-prices[ind] - fee + maximizeprofit(ind+1,0,prices,n,fee),
                0+maximizeprofit(ind+1,1,prices,n,fee));
    }
    else{
        profit = max(prices[ind]+maximizeprofit(ind+1,1,prices,n,fee),
                0+maximizeprofit(ind+1,0,prices,n,fee));
    }
    return profit;
}
// dp memo O(n*2) , O(n*2)+O(n)
long dpmaximizeprofit(int ind,int buy,vector<int> &prices,int n,vector<vector<int>> &dp,int fee){
    if(ind == n)
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    long profit = 0;
    if(buy){
        profit = max(-prices[ind] - fee + dpmaximizeprofit(ind+1,0,prices,n,dp,fee),
                0+dpmaximizeprofit(ind+1,1,prices,n,dp,fee));
    }
    else{
        profit = max(prices[ind]+dpmaximizeprofit(ind+1,1,prices,n,dp,fee),
                0+dpmaximizeprofit(ind+1,0,prices,n,dp,fee));
    }
    return dp[ind][buy]=profit;
}
// tab  O(n*2)
long tab(vector<int> &prices,int n,int fee){
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    dp[n][0] = dp[n][1] = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            long profit = 0;
            if(buy)
                profit = max((-prices[ind]-fee + dp[ind+1][0]),dp[ind+1][1]);
            else
                profit = max((prices[ind]+dp[ind+1][1]),dp[ind+1][0]);
            dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}
//space   
long spacetab(vector<int> &prices,int n,int fee){
    vector<int> ahead(2,0) , cur(2,0);
    ahead[0] = ahead[1] = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            long profit = 0;
            if(buy)
                profit = max((-prices[ind] -fee + ahead[0]),ahead[1]);
            else
                profit = max((prices[ind]+ahead[1]),ahead[0]);
            cur[buy]=profit;
        }
        ahead = cur;
    }
    return ahead[1];
}
//4 variables space optimize
long spacetaboptimize(vector<int> &prices,int n,int fee){
    long aheadBuy ,aheadNotBuy , CurBuy, CurNotBuy;
    aheadNotBuy = aheadBuy = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            long profit = 0;
            CurBuy = max((-prices[ind] -fee + aheadNotBuy),aheadBuy);
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

    int fee;
    cin >> fee;

    cout << maximizeprofit(0,1,prices,n,fee) << endl;

    vector<vector<int>> dp(n,vector<int>(2,-1));
    cout << dpmaximizeprofit(0,1,prices,n,dp,fee) << endl;

    cout << tab(prices,n,fee) << endl;

    cout << spacetab(prices,n,fee) << endl;

    cout << spacetaboptimize(prices,n,fee) << endl;

    return 0;
} 