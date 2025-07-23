//LOWER BOUND & UPPER BOUND
#include<bits/stdc++.h>
using namespace std;
//Iterative  O(log n),space - O(1)
int lowerBound(int arr[], int n, int target) {
    int ans = n;
    int low = 0,high = n-1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
        }
    return ans;
}

//UPPER BOUND
//Iterative  O(log n),space - O(1)
int UpperBound(int arr[], int n, int target) {
    int ans = n;
    int low = 0,high = n-1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] > target){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
        }
    return ans;
}
int main(){
    int n,target;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    cin >> a[i];
    cin >> target;

    // int index1 = lowerBound(a,n,target);
    //cpp
    int* lb = lower_bound(a, a + n, target);
    int index1 = lb - a;
    cout << "Lower Bound Index: " << index1 << endl;

    // int index2 = UpperBound(a,n,target);
    //cpp
    int* ub = upper_bound(a, a + n, target);
    int index2 = ub - a;

    cout << "Upper Bound Index: " << index2;
    return 0; 
}