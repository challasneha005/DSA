// BUY AND SELL STOCKS TO MAX PROFIT
// BUY & SELL  K TRANSACTIONS
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
int tab(vector<int> &prices,int n,int k){
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
    //already all base cases initialised with 0..
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=k;cap++){
                if(buy)
                    dp[ind][buy][cap] = max((-prices[ind]+dp[ind+1][0][cap]),
                        dp[ind+1][1][cap]);
                else
                    dp[ind][buy][cap] = max((prices[ind]+dp[ind+1][1][cap-1]),
                        dp[ind+1][0][cap]);
            }
        }
    }
    return dp[0][1][k];
}
// space
int spacetab(vector<int> &prices,int n,int k){
    vector<vector<int>> after(2,vector<int>(k+1,0));
    vector<vector<int>> cur(2,vector<int>(k+1,0));
    //already all base cases initialised with 0..
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=k;cap++){
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
    return after[1][k];
}
//trans = 0,1,2,3.. buy - even, sell odd
int recursionoptimize(int ind,int trans,vector<int> &prices,int n,int k){
    if(trans == k || ind == n)
        return 0;
    if(trans %2 ==0 )
        return max((-prices[ind]+ recursionoptimize(ind+1,trans+1,prices,n,k)),
                        recursionoptimize(ind+1,trans,prices,n,k));
    else
        return max((prices[ind]+recursionoptimize(ind+1,trans+1,prices,n,k)),
                    recursionoptimize(ind+1,trans,prices,n,k));

}
int dpmemoOptimize(int ind,int trans,vector<int> &prices,int n,vector<vector<int>> &dp,int k){
    if(trans == k || ind == n)
        return 0;
    if(dp[ind][trans] != -1)
        return dp[ind][trans];
    if(trans %2 ==0 )
        return dp[ind][trans] = max((-prices[ind]+ dpmemoOptimize(ind+1,trans+1,prices,n,dp,k)),
                        dpmemoOptimize(ind+1,trans,prices,n,dp,k));
    else
        return dp[ind][trans] = max((prices[ind]+dpmemoOptimize(ind+1,trans+1,prices,n,dp,k)),
                    dpmemoOptimize(ind+1,trans,prices,n,dp,k));

}
int tabOpt(vector<int> &prices,int n,int k){
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    for(int ind=n-1;ind>=0;ind--){
        //Because dp[ind][0] depends on dp[ind+1][1]
        for(int trans=k-1;trans>=0;trans--){
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
int spacetabOpt(vector<int> &prices,int n,int k){
    vector<int> after(k+1,0),cur(k+1);
    for(int ind=n-1;ind>=0;ind--){
        //Because dp[ind][0] depends on dp[ind+1][1]
        for(int trans=k-1;trans>=0;trans--){
            if(trans %2 ==0 )
                cur[trans] = max((-prices[ind]+ after[trans+1]),
                        after[trans]);
            else
                cur[trans] = max((prices[ind]+ after[trans+1]),
                    after[trans]);
        }
        after = cur;
    }
    return cur[0]; // starts from BUY-1
}
int main(){
    int n;
    cin >>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++)
        cin >> prices[i];

    int cap;
    cin >> cap;

    int k=2*cap;

    cout << maximizeprofit(0,1,cap,prices,n) << endl;

    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(cap+1,-1)));
    cout << dpmaximizeprofit(0,1,cap,prices,n,dp) << endl;

    cout << tab(prices,n,cap) << endl;

    cout << spacetab(prices,n,cap) << endl;

    cout << recursionoptimize(0,0,prices,n,k) << endl;

    vector<vector<int>> dpOpt(n,vector<int>(k+1,-1));
    cout << dpmemoOptimize(0,0,prices,n,dpOpt,k) << endl;

    cout << tabOpt(prices,n,k) << endl;

    cout << spacetabOpt(prices,n,k) << endl;

    return 0;
} 