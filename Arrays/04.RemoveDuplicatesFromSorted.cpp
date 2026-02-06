//REMOVE DUPLICATES IN SORTED ARRAY

#include<bits/stdc++.h>
using namespace std;
 
// brute  O(n log n+n)
int BruteUnique(int arr[],int n){
    set <int> s;
    for(int i=0;i<n;i++)
        s.insert(arr[i]);
    int index=0;
    for(auto it : s){
        arr[index] =it;\
        index++;
    }
    return  index;
}

//optimal
// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)

/*
APPROACH:-
-> The idea, is to use keep a pointer iwhich signifies that upto here the array is sorted
-> Now travese the entire array and if arr[i]!=arr[j] that is arr[j] is a unique value hence it should be included
   so increment the iand swap arr[i] with arr[j]
-> Return i+1, +1 is because of 0 based indexing
*/

int Unique(int a[],int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(a[i] != a[j]){
            i++;
            a[i] = a[j];
        }
    }
    return i+1;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    // int index = BruteUnique(arr,n);
    int index = Unique(arr,n);
    cout << index;
    return 0;
}

// INPUT
// 9
// 0 0 1 1 1 2 2 3 3 