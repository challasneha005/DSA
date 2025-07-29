//FIND Kth MISSING NUMBER
#include<bits/stdc++.h>
using namespace std;
//brute O(n)
int KthMissingNumberBrute(int a[], int n, int k) {
    for(int i=0;i<n;i++){
        if(a[i]<=k)
            k++;
        else 
            break;
    }
    return k; 
}
//optimal O(log n)
int KthMissingNumber(int a[], int n, int k) {
    int low =0,high = n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing = a[mid] - (mid+1);
        if(missing < k)
        low = mid+1;
        else
        high = mid-1;
    }
    return low+k;
}
int main(){
    int n,k;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> k;
    // int result = KthMissingNumberBrute(a,n,k);
    int result = KthMissingNumber(a,n,k);
    cout << "Kth missing number is: " << result;
    return 0;
}
