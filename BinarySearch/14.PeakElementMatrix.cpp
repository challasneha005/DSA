//PEAK ELEMENT MATRIX
#include<bits/stdc++.h>
using namespace std;
//optimal O(log m*n)
int findMaxInCol(int a[][100], int n, int col) {
    int maxRow = 0;
    for (int i = 1; i < n; i++) {
        if (a[i][col] > a[maxRow][col]) {
            maxRow = i;
        }
    }
    return maxRow;
}
pair<int,int> peakElementMatrix(int a[][100],int n,int m){
    int low = 0,high = m-1;
    while(low<=high){
        int mid = (low+high)/2;
        int row = findMaxInCol(a,n,mid);
        int left = mid-1 >= 0? a[row][mid-1] : -1;
        int right = mid+1 < m? a[row][mid+1] : -1;
        if(a[row][mid] > left   && a[row][mid] > right)
            return {row,mid}; //peak found
        else if(a[row][mid] < left)
            high = mid-1;
        else
            low = mid+1;
    }
    return {-1,-1};
}
int main(){
    int n,m;
    cin >> n >> m;
    int a[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    }
    pair<int,int> peak = peakElementMatrix(a,n,m);
    cout << peak.first << " " << peak.second;
    return 0;
}