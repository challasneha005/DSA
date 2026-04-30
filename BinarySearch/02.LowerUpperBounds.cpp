//LOWER BOUND & UPPER BOUND

#include<bits/stdc++.h>
using namespace std;

//Iterative  O(log n),space - O(1)

// TIME COMPLEXITY: O(log N)
// SPACE COMPLEXITY: O(1)

/*
APPROACH:
- Initialize low as 0 and high as N-1.
- Iterate using a while loop until low is less than or equal to high.
- Calculate the mid index using mid = low + (high - low) / 2.
- Check if the element at mid index is less than or equal to x.
  - If true, update the answer as mid and move the low pointer to mid+1 to search for a larger element.
  - If false, update the high pointer to mid-1 to search in the lower half of the array.
- Finally, return the answer.
*/

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

// INPUT
// 8 
// -1 2 3 5 6 7 9 11
// 3