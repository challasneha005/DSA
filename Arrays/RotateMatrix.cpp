#include<bits/stdc++.h>
using namespace std;
//ROTATE MATRIX 90  //square matrix
//brute O(n*n)  space(n*n)
int** rotateMatrixBrute(int ** mat,int n){
    int ** ans = new int*[n];
    for (int i = 0; i < n; i++)
        ans[i] = new int[n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            ans[j][n-i-1] = mat[i][j];
        }
    }
    return ans;
}
//optimal O(n/2*n/2)+O(n* n/2) space O(1);
void reverse(int arr[],int start,int end){
    while(start<= end){
        int temp=arr[start];
        arr[start] = arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
void rotateMatrixOptimal(int ** mat,int n){
    //transpose
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<n;i++)
        reverse(mat[i],0,n-1);
}
int main(){
    int n;
    cin >> n ;
    int **mat = new int*[n];
    for (int i = 0; i < n; i++)
        mat[i] = new int[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin >> mat[i][j];
    }
    // int** rotate = rotateMatrixBrute(mat,n);   for brute extra space
    rotateMatrixOptimal(mat,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    // Free memory
    for (int i = 0; i < n; i++){
        delete[] mat[i];
        // delete[] rotate[i];
    }
    delete[] mat;
    // delete[] rotate;
    return 0;
}