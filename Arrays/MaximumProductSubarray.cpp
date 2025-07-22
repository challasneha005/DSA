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