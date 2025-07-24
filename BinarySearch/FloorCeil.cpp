//FLOOR AND CEIL
#include<bits/stdc++.h>
using namespace std;
int floor(int a[],int n,int target){
    int low = 0,high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(a[mid] <= target){
            ans = a[mid];
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int ceil(int a[],int n,int target){ //just as lowerbound
    int low = 0,high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(a[mid] >= target){
            ans = a[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
        }
    return ans;
}
int main(){
    int n,target;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    cin >> a[i];
    cin >> target;
    int index1 = floor(a,n,target);
    cout << "Floor: "<< index1 << endl;
        int index2 = ceil(a,n,target);
    cout << "Ceil: "<< index2 << endl;
    return 0;
}