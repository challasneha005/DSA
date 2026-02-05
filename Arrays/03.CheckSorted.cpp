 //CHECK ARRAY SORTED OR NOT

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)

/*
APPROACH:-
Compare all neignbour elements (a,b) in A,
the case of a > b can happen at most once.

Note that the first element and the last element are also connected.

If all a <= b, A is already sorted so answer is true.
If all a <= b but only one a > b, and the first element is greater than equal to last element
we can rotate and make b the first element so answer is true.
Other case, return false.
*/

// normal
bool isSorted(int a[],int n){
    for(int i=1;i<n;i++){
        if(a[i] >= a[i-1]) {}
        else return false;
    }
    return true;
}

// rotated
bool check(int arr[],int n){
    int cnt = 0;
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1])
            cnt++;
    }
    if(cnt ==0)
        return true;
    else if(cnt == 1 & arr[0] >= arr[n-1])
        return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    if (isSorted(arr,n))
        cout << "True\n";
    else cout << "False\n";
    cout << check(arr,n);
    return 0;
}

// INPUT
// 7
// 7 8 19 1 3 5 6
