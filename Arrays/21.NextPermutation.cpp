//NEXT PERMUTATION

#include<bits/stdc++.h>
using namespace std;

//brute generate all ,linearsearch ,next index--O(n*n*n)
//better STL  
void nextPermute(int a[],int n){
    next_permutation(a,a+n);
}

// TIME COMPLEXITY: O(n), where n is the size of the input array.
// SPACE COMPLEXITY: O(1)

/*
APPROACH:-
To find the next permutation of an array, we can follow these steps:
1. Find the first index `i` from the right such that `nums[i] < nums[i+1]`. This is the first element that needs to be swapped.
2. Find the first index `j` from the right such that `nums[j] > nums[i]`. This is the element that will replace `nums[i]`.
3. Swap `nums[i]` and `nums[j]`.
4. Reverse the subarray starting from `i+1` till the end of the array.
5. If step 1 does not find any index `i`, it means the array is in descending order. In that case, reverse the entire array to get the lowest possible order.

*/

//using algorithm O(3n)
void nextPermuteGenerator(int a[],int n){
    int ind = -1;
    for(int i=n-2;i>=0;i--){
        if(a[i]<a[i+1]){
            ind = i;
            break;
        }
    }
    if (ind == -1){ 
        reverse(a, a + n);
        return;
    }
    for(int i=n-1;i>ind;i--){
        if(a[i]>a[ind]){
            swap(a[i],a[ind]);
            break;            
        }
    }
    reverse(a+ind+1,a+n);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    //nextPermute(a,n);
    nextPermuteGenerator(a,n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

// INPUT
// 5
// 1 2 3 4 5
