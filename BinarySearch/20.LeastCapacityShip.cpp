//LEAST CAPACITY TO SHIP PACKAGES WITH IN D DAYS
#include<bits/stdc++.h>
using namespace std;
//brute O(sum - max+1)*O(n)
int reqDays(int a[],int n,int cap){
    int days = 1,load  =0;
    for(int i=0;i<n;i++){
        if(load+a[i]>cap){
            days = days +1;
            load = a[i];
        }
        else
            load += a[i];
    }
    return days;
}
int leastCapacityBrute(int a[], int n, int days) {
     int sum = 0, maxWeight = INT_MIN;
    for(int i=0;i <n;i++){
        sum += a[i];
        maxWeight = max(maxWeight, a[i]);
    }
    for(int cap= maxWeight;cap<=sum;cap++){
        int dayreq = reqDays(a,n,cap);
        if(dayreq <= days)
            return cap;
    }
    return -1;
}
//optimal O(log (sum - max+1))*O(n)
int leastCapacity(int a[], int n, int days) {
    // for vector
    // int low= *max(a.begin(),a.end()),high = accumulate(a.begin(),a.end(),0);  //sum/a
     int low = INT_MIN, high = 0;
    for (int i = 0; i < n; i++) {
        low = max(low, a[i]);
        high += a[i];
    }
    while(low<high){
        int mid = (low +high)/2;
        int dayreq = reqDays(a,n,mid);
        if(dayreq <= days)
            high = mid-1;
        else 
            low = mid+1;
    }
    return low;
}
int main() {
    int n, days;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> days;
    // int result = leastCapacityBrute(a, n, days);
    int result = leastCapacity(a, n, days);
    if (result == -1)
        cout << "Not Possible";
    else
        cout << "Least Capacity to Ship in " << days << " days: " << result;
    return 0;
}