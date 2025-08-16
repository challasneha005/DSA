//FLOOD FILL ALGORITHM O(n*m) , O(2*n*m)
#include<bits/stdc++.h>
using namespace std;
void dfs(int row,int col,vector<vector<int>> &ans,vector<vector<int>> &image,
    int newColor,int delrow[],int delcol[],int iniColor){
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for(int i=0;i<4;i++){
        int nrow = row+delrow[i];
        int ncol = col+delcol[i];
        if(nrow>= 0 && nrow <n && ncol >=0 && ncol<m && 
            ans[nrow][ncol] == iniColor){
                dfs(nrow,ncol,ans,image,newColor,delrow,delcol,iniColor);
        }
    }
} 
vector<vector<int>> floodFill(vector<vector<int>> &image,int sr,int sc,int newColor){
    int iniColor = image[sr][sc];
    if(newColor == iniColor) 
        return image; // avoid infinite recursion
    vector<vector<int>> ans = image;
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    dfs(sr,sc,ans,image,newColor,delrow,delcol,iniColor);
    return ans;
}
int main() {
    vector<vector<int>> image = {
        {1, 1, 0, 0},
        {1, 2, 2, 1},
        {0, 2, 1, 1},
        {0, 1, 1, 0}
    };
    int sr = 0;       // starting row
    int sc = 0;       // starting column
    int newColor = 5; // color to fill
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);
    cout << "Flood filled image:\n";
    for (auto &row : result) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
