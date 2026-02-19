//ROTATE MATRIX 90  //square matrix

#include<bits/stdc++.h>
using namespace std;

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

// TIME COMPLEXITY = O(N^2), where N is the size of the matrix.
// SPACE COMPLEXITY = O(1)

/*
APPROACH:-
To rotate the image by 90 degrees clockwise in-place, we can follow these steps:
1. Transpose the matrix: Iterate over the matrix and swap each element (i, j) with its corresponding element (j, i). This step transforms rows into columns.
2. Reverse each row: Iterate over each row in the transposed matrix and reverse the elements. This step ensures the rotation in a clockwise direction.
*/

// void reverse(int arr[],int start,int end){
//     while(start<= end){
//         int temp=arr[start];
//         arr[start] = arr[end];
//         arr[end]=temp;
//         start++;
//         end--;
//     }
// }
void rotateMatrixOptimal(int ** mat,int n){
    //transpose
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<n;i++)
        reverse(mat[i],mat[i]+1);
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
    cout << "Rotated Matrix:\n";
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

// INPUT
// 3
// 1 2 3
// 4 5 6
// 7 8 9
