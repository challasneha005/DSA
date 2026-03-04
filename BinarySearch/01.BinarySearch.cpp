//BINARY SEARCH -sort n unique elements
#include<bits/stdc++.h>
using namespace std;
//Iterative O(log n ),space O(1)
int binarySearch(int arr[], int n, int target) {
    int low = 0,high = n-1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == target) 
            return mid;
        else if(target > arr[mid])
            low = mid+1;
        else 
            high = mid -1;
    }
    return -1;
}
//recursive O(log n ),space-O(log n )
int recursivebs(int arr[], int low,int high, int target) {
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if(arr[mid] == target)
        return mid;
    else if(target > arr[mid])
        return recursivebs(arr,mid+1,high,target);
    else
        return recursivebs(arr,low,high-1,target);
}
int main() {
    int n,target;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> target;
    // int index = binarySearch(a,n,target);
    int index = recursivebs(a,0,n-1,target);
    cout << "Found at: <<  index;
    return 0;
}
