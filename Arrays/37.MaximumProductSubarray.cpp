//MAXIMUM PRODUCT SUBARRAY

#include<bits/stdc++.h>
using namespace std;

//brute O(n*n*n)
void  maxProductSubarrayBrute(int a[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int product = 1;
            for(int k=i;k<=j;k++)
                product = product * a[k];
            maxi = max(maxi,product);
        }
    }
    cout << maxi;
}

//better O(n*n)
void  maxProductSubarrayBetter(int a[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int product = 1;
        for(int j=i;j<n;j++){
            product = product * a[j];
            maxi = max(maxi,product);
        }
    }
    cout << maxi;
}

//optimal O(n)

// TIME COMPLEXITY: O(N), where N is the size of the input array.
// SPACE COMPLEXITY: O(1).

/*
APPROACH:
To find the subarray with the largest product, we iterate through the array while 
keeping track of the current product. We maintain two variables: `ans` to store the maximum 
product found so far and `prdct` to store the current product. Since negative numbers can change
the sign and potentially result in a larger product, we run the loop twice, once from left to right and once from right to left.
*/

void maxProductSubarrayOptimal(int a[],int n){
    int pre = 1,suff =1;
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;
        pre = pre * a[i];
        suff = suff * a[n-i-1];
        ans = max(ans,max(pre,suff));
    }
    cout << ans;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    // maxProductSubarrayBrute(a,n);
    // maxProductSubarrayBetter(a,n);
    maxProductSubarrayOptimal(a,n);
}

// INPUT
// 5
// 1 3 -2 -7 6