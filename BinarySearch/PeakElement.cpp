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

