// MIN CANDY SLOPE 

#include<bits/stdc++.h>
using namespace std;

// brute O(3n), O(2n)
int minCandyBrute(vector<int> &a){
    int n = a.size();
    if(n==0) 
        return 0;
    vector<int> l(n) , r(n);
    l[0] = 1,r[n-1] = 1;
    for(int i=1;i<n;i++){
        if(a[i] > a[i-1])
            l[i] = l[i-1]+1;
        else
            l[i] = 1;
    }
    for(int i=n-2;i>=0;i--){
        if(a[i]>a[i+1])
            r[i] = r[i+1]+1;
        else
            r[i] = 1;
    }
    long long sum =0;
    for(int i=0;i<n;i++)
        sum += max(l[i],r[i]);
    return sum;
}

// Better O(2n), O(n)
int minCandyBetter(vector<int> &a){
    int n = a.size();
    if(n==0) 
        return 0;
    vector<int> l(n);
    l[0] = 1;
    for(int i=1;i<n;i++){
        if(a[i] > a[i-1])
            l[i] = l[i-1]+1;
        else
            l[i] = 1;
    }
    int cur = 1;
    long long sum = max(1,l[n-1]); 
    for(int i=n-2;i>=0;i--){
        if(a[i]>a[i+1])
            cur++;
        else
            cur = 1;
        sum +=  max(l[i],cur);
    }
    return sum;
}

// Optimal 

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

/*
APPROACH-
1. Each child must get at least one candy, and children with a higher rating than
   their immediate neighbors must receive more candies.
2. We traverse the ratings array once while identifying three possible patterns:
   - Flat slope (equal ratings)
   - Increasing slope
   - Decreasing slope
3. If two adjacent ratings are equal, we assign 1 candy to the current child,
   add it to the total sum, and move forward.
4. When we encounter an increasing slope (a[i] > a[i-1]):
   - We start counting the length of the increasing sequence using a variable `peak`.
   - For each step up the slope, we increase `peak` and add it to the total sum.
   - This ensures each child in the increasing sequence gets more candies than the previous one.
5. When we encounter a decreasing slope (a[i] < a[i-1]):
   - We count the length of the decreasing sequence using a variable `down`.
   - For each step down the slope, we add the current `down` value to the total sum and increment it.
   - This ensures the decreasing side also follows the candy distribution rules.
6. If the decreasing slope is longer than the increasing slope (`down > peak`):
   - The peak child would not have enough candies to satisfy both sides.
   - We add the extra `(down - peak)` candies to correct this imbalance.
7. By handling increasing, decreasing, and flat slopes in a single traversal,
   we ensure all constraints are satisfied.
8. The accumulated sum at the end represents the minimum number of candies required.
*/


int minCandyOptimal(vector<int> &a){
    long long sum = 1;
    int i=1,n = a.size();
    if(n==0) 
        return 0;
    while(i<n){
        if(a[i] == a[i-1]){
            sum += 1;
            i++;
            continue;
        }
        int peak = 1;
        while(i<n && a[i] > a[i-1]){
            peak++;
            sum += peak;
            i++;
        }
        int down = 1;
        while(i<n && a[i] < a[i-1]){
            sum += down;
            down++;
            i++;
        }
        if(down > peak)
        sum += down-peak;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << minCandyBrute(a) << "\n";
    cout << minCandyBetter(a) << "\n";
    cout << minCandyOptimal(a) << "\n";
    return 0;
}

// INPUT 
// 13
// 0 2 4 3 2 1 1 3 5 6 4 0 0