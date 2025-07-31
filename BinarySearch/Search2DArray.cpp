//SEARCH IN A 2D MATRIX    Return Row & Col
#include<bits/stdc++.h>
using namespace std;
//brute O(n*m)
pair<int,int>  search2DArrayBrute(int a[][100],int n,int m,int target){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == target)
                return {i,j}; 
        }
    }
    return {-1,-1};
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
pair <int,int> search2DArrayBetter(int a[][100],int n,int m,int target){
    for(int i=0;i<n;i++){
        if(a[i][0] <= target && target <= a[i][m-1]){
           int  index = recursivebs(a[i],0,m-1,target); 
            if( index != -1)
                return {i,index};
        }
    }
    return {-1,-1};
}
//Optimal O(n+m)
pair<int,int> search2DArrayOptimal(int a[][100],int n,int m,int target){
    int row =0,col=m-1;
    while(row<n && col>=0){
        if(a[row][col] == target)
            return {row,col};
        else if(a[row][col] < target)
            row++;
        else
            col--;
    }
    return {-1,-1};
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
    // pair<int,int> index =  search2DArrayBrute(a,n,m,target);
    // pair<int,int> index =  search2DArrayBetter(a,n,m,target);
    pair<int,int> index =  search2DArrayOptimal(a,n,m,target);
    cout << index.first << " " << index.second;
    return 0;
}