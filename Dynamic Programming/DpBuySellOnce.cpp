// BUY AND SELL STOCKS TO MAX PROFIT
// BUY ONCE SELL ONCE
#include<bits/stdc++.h>
using namespace std;
//O(n) , O(1)
int maximizeprofit(vector<int> &prices){
    int mini = prices[0];
    int maxprofit = 0;
    int n = prices.size();
    for(int i=1;i<n;i++){
        int cost = prices[i]-mini;
        maxprofit = max(maxprofit,cost);
        mini = min(mini,prices[i]);
    }
    return maxprofit;
}
int main(){
    int n;
    cin >>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++)
        cin >> prices[i];
    cout << maximizeprofit(prices);
    return 0;
}