// MAX RECTANGLE REA WITH 1'S
#include<bits/stdc++.h>
using namespace std;
// O(n*m)+O(m) , O(m)
int largestRectangleAreaHist(vector<int> &hist){
    stack <int> s;
    int maxi = 0;
    int n = hist.size();
    for(int i=0;i<=n;i++){
        while(!s.empty() && (i==n || hist[s.top()] >= hist[i]) ){
            int height = hist[s.top()];
            s.pop();
            int width;
            if(s.empty())
                width = i;
            else    
                width = i - s.top() - 1;
            maxi = max(maxi,width*height);
        }
        s.push(i);
    }
    return maxi;
}
int MaxRectangleAreaGrid(vector<vector<int>> &mat,int n,int m){
    int maxArea = 0;
    vector<int> height(m,0);;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 1)
                height[j]++;
            else    
                height[j] = 0;
        }
        int area = largestRectangleAreaHist(height);
        maxArea = max(area,maxArea);
    }
    return maxArea;
}
int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> mat[i][j];
    }

    cout << MaxRectangleAreaGrid(mat,n,m);

    return 0;
}
// 4 5
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0