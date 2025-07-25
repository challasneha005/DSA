//FIND OUT HOW MANY TIMES  ARRAY HAS BEEN ROTATED
#include<bits/stdc++.h>
using namespace std;
int findRotationCountUnique(int a[], int n) {  //just as minrotated
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;
    while(low <= high){
        int mid = (low+high)/2;
        //search space already sorted a[low] is always smaller
        if(a[low]<=a[high]){
            if(a[low] < ans){
                index = low;
                ans = a[low];
            }
            break;
        }
        if(a[low] <= a[mid]){
            if(a[low] < ans){
                index = low;
                ans =  a[low];
            }
            low = mid+1;
        }
        else{
            high = mid-1;
            if(a[mid] < ans){
                index = mid;
                ans =  a[mid];
            }
        }
    }
    return index;
}
//repeat
int findRotationCount(int a[], int n) {  //just as minrotated
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;
    while(low <= high){
        int mid = (low+high)/2;
        //duplicates
        if (a[low] == a[mid] && a[mid] == a[high]) {
            if(a[mid] < ans){
                ans = a[mid];
                index = mid;
            }
            else if (a[mid] == ans) {
                index = min(index, mid);  // pick smaller index  
            }
            low++;
            high--;
            continue;
        }
        //search space already sorted a[low] is always smaller
        if(a[low]<=a[high]){
            if(a[low] < ans){
                ans = a[low];
                index = low;
            }
            else if (a[low] == ans) {
                index = min(index, low);
            }
            if (a[low] < a[high]) 
            return index;  // No need to search further
            // If duplicates at boundaries 
            low++;
            high--;
            continue; 
        }
        if(a[low] <= a[mid]){
            if(a[low] < ans){
                index = low;
                ans =  a[low];
            }
            else if (a[low] == ans) {
                index = min(index, low);
            }
            low = mid+1;
        }
        else{
            high = mid-1;
            if(a[mid] < ans){
                index = mid;
                ans =  a[mid];
            }
             else if (a[mid] == ans) {
                index = min(index, mid);
            }
        }
    }
    return index;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    cin >> a[i];
    // int number = findRotationCountUnique(a,n);
    int number = findRotationCount(a,n);
    cout << "Rotation count : " << number ;
    return 0;
}