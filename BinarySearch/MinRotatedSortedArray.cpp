//MINIMUM IN ROTATED SORTED ARRAY  //unique
#include<bits/stdc++.h>
using namespace std;
int minRotatedArrayUnique(int a[],int n){
    int low = 0,high = n-1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = (low+high)/2;
        //search space already sorted a[low] is always smaller
        if(a[low]<=a[high]){
            ans = min (ans,a[low]);
            break;
        }
        if(a[low] <= a[mid]){
            ans = min(ans,a[low]);
            low = mid+1;
        }
        else{
            high = mid-1;
            ans = min(ans,a[mid]);
        }
    }
    return ans;
}
//repeat elements
int minRotatedArray(int a[],int n){
    int low = 0,high = n-1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = (low+high)/2;
        //duplicates
        if (a[low] == a[mid] && a[mid] == a[high]) {
            ans = min(ans, a[mid]);
            low++;
            high--;
            continue;
        }
        //search space already sorted a[low] is always smaller
        if(a[low]<=a[high]){
            ans = min (ans,a[low]);
             high = mid - 1; //dont break search
        }
        if(a[low] <= a[mid]){
            ans = min(ans,a[low]);
            low = mid+1;
        }
        else{
            high = mid-1;
            ans = min(ans,a[mid]);
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    // int number = minRotatedArrayUnique(a,n);
    int number = minRotatedArray(a,n);
    cout << "Minimum in rotated array: " << number ;
    return 0;
}
