//SEARCH IN A 2D MATRIX    //EXIST OR NOT
#include<bits/stdc++.h>
using namespace std;
//brute O(n*m)
bool search2DArrayBrute(int a[][100],int n,int m,int target){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == target)
                return true; //row no is i
        }
    }
    return false;
}
//better O(n)+O(log m)
int recursivebs(int arr[], int low,int high, int target) {
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if(arr[mid] == target)
        return mid;
    else if(target > arr[mid])
        return recursivebs(arr,mid+1,high,target);
    else
        return recursivebs(arr,low,high-1,target);
}
bool search2DArrayBetter(int a[][100],int n,int m,int target){
    for(int i=0;i<n;i++){
        if(a[i][0] <= target && target <= a[i][m-1])
            return recursivebs(a[i],0,m-1,target); //col no.
    }
    return false;
}
//oprimal O(log (n*m))
bool search2DArrayOptimal(int a[][100],int n,int m,int target){
    int low=0,high = (n*m-1);
    while(low <=high){
        int mid = (low+high)/2;
        int row = mid/m;
        int col = mid%m;
        if(a[row][col] == target)
            return true;
        else if(a[row][col] < target)
            low = mid+1;
        else
            high = mid-1;
    } 
    return false;
}
int main(){
    int n,m,target;
    cin >> n >> m;
    int a[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    }
    cin >> target;
    // bool x =  search2DArrayBrute(a,n,m,target);
    // bool x =  search2DArrayBetter(a,n,m,target);
    bool x =  search2DArrayOptimal(a,n,m,target);
    cout << x;
    return 0;
}
