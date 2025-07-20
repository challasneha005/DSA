//DP on BUY STOCK AND SELL STOCK
#include<bits/stdc++.h>
using namespace std;
int buySellStock(int a[],int n){
    int minPrice = a[0];
    int maxProfit = 0;
    for(int i=0;i<n;i++){
        int cost = a[i] - minPrice;
        maxProfit  = max(maxProfit,cost);
        minPrice = min(minPrice,a[i]);
    }
    return maxProfit;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout <<  buySellStock(a,n);
    return 0;
}
