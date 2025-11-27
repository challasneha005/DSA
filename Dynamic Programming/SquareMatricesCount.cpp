// COUNT NO.OF SQUARE MATRICES...
#include<bits/stdc++.h>
using namespace std;
// O(n*m) , O(n*m)
int countSquares(vector<vector<int>> &a,int n,int m){
    vector<vector<int>> dp(n,vector<int>(m,0));
    // copy same
    for(int j=0;j<m;j++)
        dp[0][j] = a[0][j];
    for(int i=0;i<n;i++)
        dp[i][0] = a[i][0];
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j] == 0)
                dp[i][j] = 0;
            else{
                dp[i][j] = 1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            }
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            sum += dp[i][j];
    }
    return sum;
}
int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> mat[i][j];
    }

    cout << countSquares(mat,n,m);

    return 0;
}
// 4 5
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0