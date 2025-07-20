#include<bits/stdc++.h>
using namespace std;
//Set Matrix Zeros
//brute O(2*n*m)+O(n+m)
void markrow(int **mat,int i,int m){
    for(int j=0;j<m;j++){
        if(mat[i][j] != 0)
            mat[i][j]=-1;
    }
}
void markcol(int** mat,int j,int n){
    for(int i=0;i<n;i++){
        if(mat[i][j] != 0)
            mat[i][j]=-1;
    }
}
void setMatrixZerosBrute(int** mat,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                markrow(mat,i,m);
                markcol(mat,j,n);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == -1)
                mat[i][j] = 0;
        }
    }
}
//better O(2*n*m) space O(n*m)
void setMatrixZerosBetter(int** mat,int n,int m){
    int col[m]={0};
    int row[n]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]==1 || col[j]==1)
                mat[i][j]=0;
        }
    }
}
//Optimal O(n*m) spcae 1 varaible
void setMatrixZerosOptimal(int** mat,int n,int m){
    // col[m] = {0} -> mat[0][..]
    // row[n] = {0} -> mat[..][0]
    int col0 = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                //mark ith row
                mat[i][0]=0;
                //mark jth col
                if(j!=0)
                    mat[0][j]=0;
                else
                col0=0;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j] != 0){
                if(mat[0][j] == 0 || mat[i][0]==0)
                    mat[i][j]=0;
            }
        }
    }
    if(mat[0][0] == 0){
        for(int j=0;j<m;j++)
            mat[0][j]=0;
    }
    if(col0 == 0){
        for(int i=0;i<n;i++)
            mat[i][0]=0;
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    int **mat = new int*[n];
    for (int i = 0; i < n; i++)
        mat[i] = new int[m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> mat[i][j];
    }
    // setMatrixZerosBrute(mat,n,m);
    // setMatrixZerosBetter(mat,n,m);
    setMatrixZerosOptimal(mat,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    // Free memory
    for (int i = 0; i < n; i++)
        delete[] mat[i];
    delete[] mat;
    return 0;
}
