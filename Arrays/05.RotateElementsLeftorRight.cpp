// LEFT or RIGHT ROTATE d ELEMENTS

#include<bits/stdc++.h>
using namespace std;

//brute O(n+d),O(d)
void bruteLeftRotate(vector<int>& arr,int n,int d){
    if (n == 0) return;
    d=d%n;
    vector<int> temp(arr.begin(), arr.begin() + d);
    for(int i=d;i<n;i++)
        arr[i-d]=arr[i];
    for(int i=n-d;i<n;i++)
        arr[i]=temp[i-(n-d)];
}

//optimal O(2n) using reverse function
//ONE PLACE

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)

/*
APPROACH:-
-> By observing we can the ans is the arr where arr[i] = arr[i+1] and at last place we will have arr[0]
-> Before traversing store the arr[0] in temp and then traverse the array and make arr[i] = arr[i+1]
-> Make arr[n-1] = arr[0], where n is the size of the array
*/

void leftRotateByOne(vector<int> &arr, int n){
    if (n == 0) return;
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    arr[n - 1] = temp;
}

// k places

/*
APPROACH:-
To rotate the array d places to right follow below steps
-> Reverse first n-d elements
-> Reverse last d elements
-> Reverse the entire array

To rotate the array d places to left follow below steps
-> Reverse first d elements
-> Reverse last n-d elements
-> Reverse the entire array
*/

void leftRotate(vector<int> &arr,int n,int d){
    if (n == 0) return;
    d = d%n;
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

void rightRotate(vector<int> &arr, int n, int d){
    if (n == 0) return;
    d = d % n; // to keep k within the range
    reverse(arr.begin(), arr.end() - d);
    reverse(arr.end() - d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int d;
    cin >> d;
    // bruteleftRotate(arr,n,d);
    // leftRotateByOne(arr,n);
    leftRotate(arr,n,d);
    // rightRotate(arr,n,d);
    for (int x : arr)
        cout << x << " ";
    
    return 0;
} 

// INPUT
// 5
// 1 2 3 4 5
// 2
