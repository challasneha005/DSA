//LARGEST ELEMENT

#include<bits/stdc++.h>
using namespace std;

//brute sort and large  (O(n log n))

//better 
// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)

/*
APPROACH:-
-> Intialize the ans with starting element
-> Traverse the entire array and update the ans if the element is greater then ans
-> Finally, return the ans
*/

int largest(int arr[],int n){
    int large = arr[0];
    for(int i=0;i<n;i++){
        if (arr[i]>large)
            large = arr[i];
    }
    return large;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int large = largest(arr,n);
    cout << large ;
    return 0;
}

// INPUT
// 5
// 245 46 3 2 524
