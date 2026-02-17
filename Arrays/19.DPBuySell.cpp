//DP on BUY STOCK AND SELL STOCK

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)

/*
APPROACH:-
Initialize two variables: min_price and max_profit.
-> min_price = minimum price in the array.
-> max_profit = 0.
Iterate through the array, and for each price:
-> Update min_price to the minimum price seen so far.
-> Update max_profit to the maximum profit seen so far, or the current price minus min_price, whichever is greater.
Return max_profit.
*/

int buySellStock(int a[],int n){
    int minPrice = a[0];
    int maxProfit = 0;
    for(int i=1;i<n;i++){
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

// INPUT
// 6
// 7 1 5 3 6 4
