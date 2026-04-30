//SEARCH IN ROTATED SORTED ARRAY -unique
#include<bits/stdc++.h>
using namespace std;
int searchRotatedUnique(int a[],int n,int target){
    int low = 0,high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] == target)
            return mid;
        //left sorted 
        if(a[low] <= a[mid]){
            if(a[low] <= target && target < a[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else{
            if(a[mid] <= target && target <= a[high])
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return -1;
}
//repeated exist..or not
bool searchRotated(int a[],int n,int target){
    int low = 0,high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] == target)
            return true;
        if(a[low] == a[mid] && a[mid] == a[high]){
            low++;
            high--;
            continue;
        }
        //left sorted 
        if(a[low] <= a[mid]){
            if(a[low] <= target && target < a[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else{
            if(a[mid] <= target && target <= a[high])
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return false;
}
int main(){
    int n,target;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> target;
    // int index = searchRotatedUnique(a,n,target);
    // cout << index << endl ;
    cout << "True (1) ,False(0): " << searchRotated(a,n,target);
    return 0;
}