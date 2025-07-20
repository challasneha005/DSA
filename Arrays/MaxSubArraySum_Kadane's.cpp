//MAXIMUM SUBARRAY SUM
#include<bits/stdc++.h>
using namespace std;
//brute O(n*n*n)
int maxSubArraySumBrute(int a[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum += a[k];
                maxi = max(maxi,sum);
            }
        }
    }
    return maxi;
}
//better O(n*n)
int maxSubArraySumBetter(int a[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += a[j];
            maxi = max(maxi,sum);
        }
    }
    return maxi;
}
//optimal 
// KADANE's ALGORITHM O(n) printing array also
int maxSubArraySumOptimal(int a[],int n){
    int maxi = INT_MIN;
    int sum = 0;
    int start = 0;;
    int ansStart = -1;
    int ansEnd = -1;
    for(int i=0;i<n;i++){
        if(sum == 0)
            start = i;
        sum +=a[i];
        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0)
            sum = 0;
    }
    return maxi;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    //cout <<   maxSubArraySumBrute(a,n);
    // cout <<   maxSubArraySumBetter(a,n);
    cout <<   maxSubArraySumOptimal(a,n);
    return 0;
}
