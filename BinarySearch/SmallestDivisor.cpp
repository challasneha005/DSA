//SMALLEST DIVISOR IN THRESHHOLD
#include<bits/stdc++.h>
using namespace std;
int findMax(int a[],int n){
    int maxi = INT_MIN;
    for(int i =0;i<n;i++)
        maxi = max(maxi,a[i]);
    return maxi;
}
//brute O(max * n)
int smallestDivisorBrute(int a[],int n,int threshold){
    int maxi = findMax(a,n);
    for(int d=1;d<=maxi;d++){
        int sum=0;
        for(int i=0;i<n;i++)
            sum += ceil((double)a[i]/d);
        if(sum <= threshold)
            return d;
    }
    return -1;
}
//optimal O(log max * n)
int sumOfDivisors(int a[], int n, int divisor) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil((double)a[i] / divisor);   
    }
    return sum;
}
int smallestDivisor(int a[],int n,int threshold){
    if(n>threshold)
        return -1;
    int low = 1,high = findMax(a,n),ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(sumOfDivisors(a,n,mid) <= threshold){
            ans = mid;
            high = mid-1;
        }
        else 
            low = mid+1;
    }
    return low;
}
int main(){
    int n,threshold;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> threshold;
    // int d = smallestDivisorBrute(a,n,threshold);
    int d = smallestDivisor(a,n,threshold);
    if(d == -1)
        cout << "Not Possible";
    else
        cout << "Smallest Divisor : " << d;
    return 0;
}