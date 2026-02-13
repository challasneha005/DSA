// FRACTIONAL KNAPSACK

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n log n)
// SPACE COMPLEXITY : O(1)

/*
APPROACH:
1. For each item, compute its value-to-weight ratio (value / weight).
2. Sort all items in descending order of this ratio.
   - This ensures we always pick the item that gives the maximum value per unit weight.
3. Initialize a variable `totalValue` to store the maximum value obtained.
4. Traverse the sorted items one by one:
   a) If the current item’s weight is less than or equal to the remaining capacity,
      take the entire item and add its value to `totalValue`.
   b) Otherwise, take the fractional part of the item that fits in the remaining capacity
      and add the corresponding fraction of its value to `totalValue`.
5. Stop once the knapsack capacity becomes zero.
6. Return `totalValue` as the maximum achievable value.
This greedy approach works because, in the fractional knapsack problem,
items can be broken into fractions, allowing optimal local choices to lead
to a globally optimal solution.
*/

struct Item{
    int value;
    int weight;
};

// descending order
bool comp(Item a,Item b){
    return (double)a.value/a.weight > (double)b.value/b.weight;
}

double fractionalKnapsack(int w,Item a[],int n){
    double total = 0.0;
    sort(a,a+n,comp);
    for(int i=0;i<n;i++){
        if(a[i].weight <= w){
            total += a[i].value;
            w -= a[i].weight;
        }
        else{
            total += ((double)(a[i].value/a[i].weight))*w;
            break;
        }
    }
    return total;
}

int main(){
    int n,W;
    cin >> n >> W;
    Item a[n];
    for(int i=0;i<n;i++)
        cin >> a[i].value >> a[i].weight;
    cout << fractionalKnapsack(W, a, n);
    return 0;
}

// INPUT 
// 4 90
// 100 20 60 10 100 50 200 50