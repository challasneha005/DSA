//SEARCH INSERT
#include<bits/stdc++.h>
using namespace std;
//Iterative O(n),space - O(1) //just at lower bound
int searchInsert(int a[], int n, int target) {
    int ans = n;
    int low = 0,high = n-1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(a[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
// int main(){
//     int n,target;
//     cin >> n;
//     int a[n];
//     for(int i=0;i<n;i++)
//     cin >> a[i];
//     cin >> target;
//     int index = searchInsert(a,n,target);
//     cout << "Insert at: "<< index << endl;
//     return 0;
// }


//FLOOR AND CEIL
