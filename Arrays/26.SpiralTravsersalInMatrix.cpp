//SPIRAL MATRIX

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY: O(N), where N is the total number of elements in the matrix.
// SPACE COMPLEXITY: O(1)

/*
APPROACH:-
To traverse the matrix in a spiral order, we can use the following steps:
1. Initialize four variables: top, bottom, left, and right to keep track of the boundaries of the current spiral.
2. Create an empty vector called 'ans' to store the elements in spiral order.
3. While the top boundary is less than or equal to the bottom boundary and the left boundary is less than or equal to the right boundary:
   - Traverse the top row from left to right and add each element to 'ans'.
   - Increment the top boundary.
   - Traverse the right column from top to bottom and add each element to 'ans'.
   - Decrement the right boundary.
   - Check if the top boundary is still less than or equal to the bottom boundary:
     - Traverse the bottom row from right to left and add each element to 'ans'.
     - Decrement the bottom boundary.
   - Check if the left boundary is still less than or equal to the right boundary:
     - Traverse the left column from bottom to top and add each element to 'ans'.
     - Increment the left boundary.
4. Return the 'ans' vector containing all the elements in spiral order.
*/

void spiralMatrix(int **mat,int n,int m){
    vector<int> ans;
    int left =0 , right = m-1;
    int top = 0 , bottom = n-1;
    while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++)
            ans.push_back(mat[top][i]);
        top++;
        for(int i=top;i<=bottom;i++)
            ans.push_back(mat[i][right]);
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--)
                ans.push_back(mat[bottom][i]);
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--)
                ans.push_back(mat[i][left]);
            left++;
        }
    }   
     for (int val : ans)
        cout << val << " ";
    cout << endl; 
}
int main(){
    int n,m;
    cin >> n >> m ;
    int **mat = new int*[n];
    for (int i = 0; i < n; i++)
        mat[i] = new int[m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> mat[i][j];
    }
    spiralMatrix(mat,n,m);
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

// INPUT
// 3 4
// 1  2  3  4
// 5  6  7  8
// 9 10 11 12
