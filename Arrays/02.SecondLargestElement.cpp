//SECOND LARGEST ELEMENT WITHOUT SORT

#include<bits/stdc++.h>
using namespace std;

//brute with sort    (O(n log n))
// for(i=n-1;i>=0;i--){
//     if(arr[i]!= large){
//         slarge=arr[i];
//         break;
//     }
// }

//better without sort O(2n)
//  int secondLargest(int arr[],int n){
//     int large = arr[0];
//     for(int i=0;i<n;i++){
//         if (arr[i]>large)
//             large = arr[i];
//     }
//     int slarge=-1;
//     for(int i=0;i<n;i++){
//         if(arr[i]>slarge && arr[i]!=large)
//             slarge=arr[i];
//     }
//     return slarge;
// }


//optimal  //SECOND  LARGEST & SECOND SMALLEST
// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)

/*
APPROACH
-> If the current element is larger than ‘large’ then update second_large and large variables
-> Else if the current element is larger than ‘second_large’ then we update the variable second_large.
-> Once we traverse the entire array, we would find the second largest element in the variable second_large.
*/

int secondLargest(vector <int> &a,int n){
    int large=a[0];
    int slarge=-1;
    for(int i=1;i<n;i++){
        if(a[i] >large){
            slarge =large;
            large = a[i]; 
        }
        else if(a[i] < large && a[i] > slarge){
            slarge = a[i];
        }
    }
    return slarge;
}
int secondSmallest(vector <int> &a,int n){
    int small = a[0];
    int ssmall = INT_MAX;
    for(int i=1;i<n;i++){
        if(a[i] < small){
            ssmall = small;
            small = a[i];
        }
        else if(a[i] != small && a[i] < ssmall){
            ssmall = a[i];
        }
    }
    return ssmall;
}


int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int slarge = secondLargest(arr,n);
    int ssmall = secondSmallest(arr,n);
    cout << "Slarge : " << slarge << "\nSSmall : " << ssmall;
    return 0;
}

//INPUT
// 5
// 245 46 3 2 524