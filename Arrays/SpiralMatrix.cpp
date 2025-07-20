//SPIRAL MATRIX
#include<bits/stdc++.h>
using namespace std;
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