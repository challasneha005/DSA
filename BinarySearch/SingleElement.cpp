//SINGLE ELEMENT IN SORTED ARRAY -Others twice
#include<bits/stdc++.h>
using namespace std;
//no duplicates
//brute
int singleElementBrute(int a[],int n){
    for(int i=0;i<n;i++){
        if(i==0){
            if(a[1] != a[i+1])
                return a[i];
        }
        else if(i==n-1){
            if(a[i] != a[i-1])
                return a[i];
        }
        else{
            if(a[i] != a[i+1] && a[i] != a[i-1])
                return a[i];
        }
    }
    return -1;
}
int singleElement(int a[],int n){
    if(n==1) 
        return a[0];
    if(a[0] != a[1])
        return a[0];
    if(a[n-1] != a[n-2])
        return a[n-1];
    int low = 1,high = n-2;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] != a[mid+1] && a[mid] != a[mid-1])
            return a[mid];
        //left eliminate
        if((mid%2 ==1 && (a[mid-1]== a[mid]) || (mid %2 ==0 && a[mid]==a[mid+1]) ))
            low = mid+1;
        //right eliminate
        else
            high= mid-1;
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    // int single = singleElementBrute(a,n);
    int single = singleElement(a,n);
    cout << single ;
    return 0;
}