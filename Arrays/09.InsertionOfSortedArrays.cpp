//INSERTION OF TWO SORTED ARRAYS

#include<bits/stdc++.h>
using namespace std;

//brute O(n+m)

vector<int> insertionSortedBrute(vector<int> a, int n, vector<int> b, int m){
    vector<int> result;
    int vis[m]={0};
    for(int i=0;i<n;i++){
        for(int j=0;i<m;j++){
            if(a[i] == b[j] && vis[j]==0) {
                result.push_back(a[i]);
                vis[j]=1;
                break;  
            }
            if(b[j] > a[i]) break;
        }
    }
    return result;
}

//optimal   O(n+m) space is O(1)

// TIME COMPLEXITY = O(N+M)
// SPACE COMPLEXITY = O(0)

/*
APPROACH:-
-> Use two pointers i and j, where i points to the first sorted array and j points to the second sorted array
-> Traverse both arrays simultaneously
-> While traversing, three cases can occur:
    -> arr1[i] == arr2[j]
        Common element found
        Insert the element into the result
        Move both pointers i and j forward
    -> arr1[i] < arr2[j]
        Move pointer i forward to catch up
    -> arr1[i] > arr2[j]
        Move pointer j forward to catch up
-> Continue the process until one of the arrays is fully traversed
*/


vector<int> insertionSortedOptimal(vector<int> a, int n, vector<int> b,int m){
    vector<int> result;
    int i=0,j=0;
    while(i<n && j<m){
        if(a[i] < b[j])
            i++;
        else if(a[i] > b[j])
            j++;
        else{
            result.push_back(a[i]);
            i++;
            j++;
        }
    }
    return result;
}

int  main(){
    int n,m;
    cin >> n;
    vector <int> a(n);
    for(int i=0;i<n;i++) 
        cin >> a[i];
    cin >> m;
    vector <int> b(m);
    for(int i=0;i<m;i++) 
        cin >> b[i];
    // vector <int> result = insertionSortedBrute(a,n,b,m);
    vector <int> result = insertionSortedOptimal(a,n,b,m);
    for(auto it:result) 
        cout << it << " ";
    return 0;
}
