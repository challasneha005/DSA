//PEAK ELEMENT
#include<bits/stdc++.h>
using namespace std;
//brute
int peakElementBrute(int a[],int n){
    for(int i=0;i<n;i++){
        if((i==0 || a[i-1] < a[i]) && (i==n-1 || a[i]>a[i+1]))
            return i; 
    }
    return -1;
}
/*
APPROACH:-
We can use the binary search approach to find the peak element.
1. Initialize low = 0 and high = n-1, where n is the size of the array.
2. While low < high, calculate mid = low + (high - low) / 2.
3. If nums[mid] < nums[mid+1], it means a peak element exists on the right side of mid, so update low = mid+1.
4. Otherwise, a peak element exists on the left side of mid or mid itself is a peak, so update high = mid.
5. After the loop ends, low will be pointing to the peak element index.
6. Return low as the result.
*/
int peakElement(int a[],int n){
    if(n==1 ) 
        return 0;
    if(a[0] > a[1])
        return 1;
    if(a[n-1]>a[n-2])
        return n-1;
    int low = 1,high = n-2;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]>a[mid-1] && a[mid]> a[mid+1])
            return mid;
        else if(a[mid]>a[mid-1])
            low=mid+1;
        // else if(a[mid]>a[mid+1])
        //     high = mid-1;
        //multiple peak
        else    
            high = mid-1;
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    // int peak = peakElementBrute(a,n);
    int peak = peakElement(a,n);
    cout << "peak index: " << peak;
    return 0;
}

