// BUY AND SELL STOCKS TO MAX PROFIT
// BUY & SELL  2 TRANSACTIONS
#include<bits/stdc++.h>
using namespace std;
// recursion O(2^n) , O(n) 
int  maximizeprofit(int ind,int buy,int cap,vector<int> &prices,int n){
    if(cap == 0 || ind == n)
        return 0;
    if(buy)
        return max((-prices[ind]+maximizeprofit(ind+1,0,cap,prices,n)),
                        maximizeprofit(ind+1,1,cap,prices,n));
    else
        return max((prices[ind]+maximizeprofit(ind+1,1,cap-1,prices,n)),
                        maximizeprofit(ind+1,0,cap,prices,n));
} 
// dp memo O(n*2*3),O(n*2*3)+O(n)  
int dpmaximizeprofit(int ind,int buy,int cap,vector<int> &prices,int n,vector<vector<vector<int>>> &dp){
    if(cap == 0 || ind == n)
        return 0;
    if(dp[ind][buy][cap] !=-1)
        return dp[ind][buy][cap];
    if(buy)
        return dp[ind][buy][cap] = max((-prices[ind]+dpmaximizeprofit(ind+1,0,cap,prices,n,dp)),
                        dpmaximizeprofit(ind+1,1,cap,prices,n,dp));
    else
        return dp[ind][buy][cap] = max((prices[ind]+dpmaximizeprofit(ind+1,1,cap-1,prices,n,dp)),
                        dpmaximizeprofit(ind+1,0,cap,prices,n,dp));
}
int tab(vector<int> &prices,int n){
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    //already all base cases initialised with 0..
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy)
                    dp[ind][buy][cap] = max((-prices[ind]+dp[ind+1][0][cap]),
                        dp[ind+1][1][cap]);
                else
                    dp[ind][buy][cap] = max((prices[ind]+dp[ind+1][1][cap-1]),
                        dp[ind+1][0][cap]);
            }
        }
    }
    return dp[0][1][2];
}
// space
int spacetab(vector<int> &prices,int n){
    vector<vector<int>> after(2,vector<int>(3,0));
    vector<vector<int>> cur(2,vector<int>(3,0));
    //already all base cases initialised with 0..
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy)
                    cur[buy][cap] = max((-prices[ind]+after[0][cap]),
                        after[1][cap]);
                else
                    cur[buy][cap] = max((prices[ind]+after[1][cap-1]),
                        after[0][cap]);
            }
        }
        after = cur;
    }
    return after[1][2];
}
// in dp[n][4]..
//trans = 0,1,2,3.. buy - even, sell odd
int recursionoptimize(int ind,int trans,vector<int> &prices,int n){
    if(trans == 4 || ind == n)
        return 0;
    if(trans %2 ==0 )
        return max((-prices[ind]+ recursionoptimize(ind+1,trans+1,prices,n)),
                        recursionoptimize(ind+1,trans,prices,n));
    else
        return max((prices[ind]+recursionoptimize(ind+1,trans+1,prices,n)),
                    recursionoptimize(ind+1,trans,prices,n));

}
int dpmemoOptimize(int ind,int trans,vector<int> &prices,int n,vector<vector<int>> &dp){
    if(trans == 4 || ind == n)
        return 0;
    if(dp[ind][trans] != -1)
        return dp[ind][trans];
    if(trans %2 ==0 )
        return dp[ind][trans] = max((-prices[ind]+ dpmemoOptimize(ind+1,trans+1,prices,n,dp)),
                        dpmemoOptimize(ind+1,trans,prices,n,dp));
    else
        return dp[ind][trans] = max((prices[ind]+dpmemoOptimize(ind+1,trans+1,prices,n,dp)),
                    dpmemoOptimize(ind+1,trans,prices,n,dp));

}
int tabOpt(vector<int> &prices,int n){
    vector<vector<int>> dp(n+1,vector<int>(5,0));
    for(int ind=n-1;ind>=0;ind--){
        //Because dp[ind][0] depends on dp[ind+1][1]
        for(int trans=3;trans>=0;trans--){
            if(trans %2 ==0 )
                dp[ind][trans] = max((-prices[ind]+ dp[ind+1][trans+1]),
                        dp[ind+1][trans]);
            else
                dp[ind][trans] = max((prices[ind]+dp[ind+1][trans+1]),
                    dp[ind+1][trans]);
        }
    }
    return dp[0][0]; // starts from BUY-1
}
int spacetabOpt(vector<int> &prices,int n){
    vector<int> after(5,0),cur(5,0);
    for(int ind=n-1;ind>=0;ind--){
        //Because dp[ind][0] depends on dp[ind+1][1]
        for(int trans=3;trans>=0;trans--){
            if(trans %2 ==0 )
                cur[trans] = max((-prices[ind]+ after[trans+1]),
                        after[trans]);
            else
                cur[trans] = max((prices[ind]+after[trans+1]),
                    after[trans]);
        }
        after = cur;
    }
    return after[0]; // starts from BUY-1
}
int main(){
    int n;
    cin >>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++)
        cin >> prices[i];

    int cap = 2;
    cout << maximizeprofit(0,1,2,prices,n) << endl;

    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    cout << dpmaximizeprofit(0,1,2,prices,n,dp) << endl;

    cout << tab(prices,n) << endl;

    cout << spacetab(prices,n) << endl;

    cout << recursionoptimize(0,0,prices,n) << endl;

    vector<vector<int>> dpOpt(n,vector<int>(4,-1));
    cout << dpmemoOptimize(0,0,prices,n,dpOpt) << endl;

    cout << tabOpt(prices,n) << endl;

    cout << spacetabOpt(prices,n) << endl;
    return 0;
} 
// 8
// 3 3 5 0 0 3 1 4