//MEDIAN OF ROW WISE SORTED MATRIX
#include<bits/stdc++.h>
using namespace std;
//brute O(2 *n*m)+(O(log n*m) 
int medianOfRowWiseSortedMatrixBrute(int a[][100], int n, int m) {
    vector <int> l ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            l.push_back(a[i][j]);
        }
    }
    sort(l.begin(),l.end());
    return l[(m*n)/2];
}
//optimal O(log 1e9 + n*log m)
int upperBound(int arr[], int n, int target) {
    int ans = n;
    int low = 0,high = n-1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] > target){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
        }
    return ans;
}
int blackbox(int a[][100],int n,int m,int x){
    int cnt = 0;
    for(int i=0;i<n;i++)
        cnt += upperBound(a[i],m,x);
    return cnt;
}
int medianOfRowWiseSortedMatrixOptimal(int a[][100], int n, int m){
    int low = 0,high = n*m-1;
    int req = (n*m)/2;
    while(low<=high){
        int mid = (low+high)/2;
        int smallerEquals = blackbox(a,n,m,mid);
        if(smallerEquals <= req )
            low = mid+1;
        else    
            high = mid-1;
    }
    return low;
}
int main(){
        int n,m;
    cin >> n >> m;
    int a[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    }
    // int median = medianOfRowWiseSortedMatrixBrute(a,n,m);
        int median = medianOfRowWiseSortedMatrixOptimal(a,n,m);
    cout << median;
    return 0;
}