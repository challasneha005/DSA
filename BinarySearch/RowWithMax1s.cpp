// FIND THE ROW WITH MAXIMUM 1's
#include<bits/stdc++.h>
using namespace std;
//brute O(n*m)
int rowWithMax1sBrute(int a[][100], int n, int m) {
    int index = -1,maxcnt = 0;
    for(int i=0;i<n;i++){
        int cntrow = 0;
        for(int j=0;j<m;j++)
            cntrow += a[i][j];
        if(cntrow > maxcnt){ 
            maxcnt = cntrow;
            index = i;
        }        
    }
    return index;
}
//optimal O(n log m)
int lowerBound(int arr[], int n, int target) {
    int ans = n;
    int low = 0,high = n-1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
        }
    return ans;
}
int rowWithMax1sOptimal(int a[][100],int n,int m){
    int cntmax =-1,index = -1;
    for(int i=0;i<n;i++){
        int cntones = m - lowerBound(a[i],m,1);
        if(cntones > cntmax){
            cntmax = cntones;
            index = i;
        }
    }
    return index;
}
int main(){
    int n,m;
    cin >> n >> m;
    int a[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    }
    // int row = rowWithMax1sBrute(a,n,m);
    int row = rowWithMax1sOptimal(a,n,m);
    cout << row;
    return 0;
}