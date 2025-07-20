//REMOVE DUPLICATES IN SORTED ARRAY 
#include<bits/stdc++.h>
using namespace std;
// brute  O(n log n+n)
int setUnique(int arr[],int n){
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

//optimal O(n)
int Unique(int a[],int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(a[i] != a[j]){
            a[i+1] = a[j];
            i++;
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
    // int index = setUnique(arr,n);
    int index = Unique(arr,n);
    cout << index;
    return 0;
}
