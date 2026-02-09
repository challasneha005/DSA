 // MAX SUM WITH CONSTANT WINDOW K=4

#include<bits/stdc++.h>
using namespace std;

//  TIME COMPLEXITY O(n)
//  SPACE COMPLEXITY O(1)

// APPROACH 
// Remove left element, add next right element, keep window size = k.

long long maxSumSubarray(vector<int>&a,int k){
    int n = a.size();
    int l=0,r=k-1;
    long long sum =0;
    for (int i = 0; i < k; i++)
        sum += a[i];
    long long maxSum = sum;
    while(r<n-1){
        sum -= a[l];
        l++;
        r++;
        sum += a[r];
        maxSum = max(maxSum,sum);
    }
    return maxSum;
}

int main(){
    int n,k;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> k;
    cout << maxSumSubarray(a,k);
    return 0;
}

// INPUT
// 7
// -1 2 3 3 4 5 -1
// 4
