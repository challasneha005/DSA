// SORT  AN ARRAY OF 0,1,2

#include<bits/stdc++.h>
using namespace std;

//brute O(nlog n)  general sortings

//better O(2n)
void sortarray(int a[],int n){
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(a[i]==0)
            cnt0++;
        else if(a[i]==1)
            cnt1++;
        else
            cnt2++;
    }
    for(int i=0;i<cnt0;i++)
        a[i]=0;
    for(int i=cnt0;i<cnt1;i++)
        a[i]=1;
    for(int i=cnt1;i<cnt2;i++)
        a[i]=2;
}

//Optimal

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)

//DUTCH NATIONAL FLAG ALGORITHM O(n)
/*
APPROACH:-
-> Initialize three pointers: low at the beginning of the array, mid at the beginning of the array, and high at the end of the array.
-> Iterate through the array while the mid pointer is less than or equal to the high pointer:
1. If the current element at the mid pointer is 0 (red), we swap it with the element at the low pointer and increment both low and mid pointers. This ensures that red elements are moved to the left side of the array.
2. If the current element at the mid pointer is 1 (white), we simply increment the mid pointer. This keeps white elements in the middle of the array.
3. If the current element at the mid pointer is 2 (blue), we swap it with the element at the high pointer and decrement the high pointer. This ensures that blue elements are moved to the right side of the array.

Repeat step 2 until the mid pointer crosses the high pointer.
At the end of the algorithm, the array will be sorted in the desired order.
*/

void sortarrayOptimal(int a[],int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(a[mid]==0){
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if(a[mid]==1)
            mid++;
        else{
            swap(a[mid],a[high]);
            high--;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    //sortarray(a,n);
    sortarrayOptimal(a,n);
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}

// INPUT
// 8
// 1 2 0 1 1 0 0 2 1
