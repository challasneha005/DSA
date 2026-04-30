//BINARY SEARCH -sort n unique elements

#include<bits/stdc++.h>
using namespace std;

//Iterative O(log n ),space O(1)

// TIME COMPLEXITY: O(log n)
// - The algorithm divides the search space in half at each step, resulting in a logarithmic time complexity.

// SPACE COMPLEXITY: O(1)
// - The algorithm uses a constant amount of extra space for the variables.

/*
APPROACH:-
1. Initialize low as 0 and high as the last index of the array.
2. Iterate using a while loop until low is less than or equal to high.
3. Calculate the middle index using the formula mid = low + (high - low) / 2.
4. Compare the target value with the element at the middle index:
   - If they are equal, return the middle index.
   - If the target is less than the element, update high to mid - 1 and continue the search in the left half.
   - If the target is greater than the element, update low to mid + 1 and continue the search in the right half.
5. If the target is not found, return -1.
*/

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
    cout << "Found at: " <<  index;
    return 0;
}


// INPUT
// 7
// -1 0 4 5 7 9 11
// 5
