// CHERRY PICKUP ALICE BOB START ROW CORNERS,MAX>
#include<bits/stdc++.h>
using namespace std;
//recursion O(3^n * 3^n) , O(n)-auxilary stack space
int maxCherry(int i,int j1,int j2,int r,int c,vector<vector<int>> &a){
    if(j1<0 || j2<0 || j1>=c || j2>=c)
        return -1e9;
    if(i==r-1){
        if(j1==j2)
            return a[i][j1];
        else
            return a[i][j1]+a[i][j2];
    }
    //explore paths alice & bob
    int maxi = -1e9;
    for(int dj1 = -1; dj1<=1;dj1++){
        for(int dj2=-1; dj2<=2;dj2++){
            int value = 0;
            if(j1==j2)
                value = a[i][j1];
            else    
                value = a[i][j1]+a[i][j2];
            value += maxCherry(i+1,j1+dj1,j2+dj2,r,c,a);
            maxi = max(maxi,value);
        }
    }
    return maxi; 
}
// dp memorization O(n*m*m)*9 , O(n*m*m)+O(n) - ass
int dpmaxCherry(int i,int j1,int j2,int r,int c,vector<vector<int>> &a,
vector<vector<vector<int>>> &dp){
    if(j1<0 || j2<0 || j1>=c || j2>=c)
        return -1e9;
    if(i==r-1){
        if(j1==j2)
            return a[i][j1];
        else
            return a[i][j1]+a[i][j2];
    }
    if(dp[i][j1][j2]!=-1)
        return dp[i][j1][j2];
    //explore paths alice & bob
    int maxi = -1e9;
    for(int dj1 = -1; dj1<=1;dj1++){
        for(int dj2=-1; dj2<=2;dj2++){
            int value = 0;
            if(j1==j2)
                value = a[i][j1];
            else    
                value = a[i][j1]+a[i][j2];
            value += dpmaxCherry(i+1,j1+dj1,j2+dj2,r,c,a,dp);
            maxi = max(maxi,value);
        }
    }
    return dp[i][j1][j2]=maxi; 
}
//tab
int tab(int i,int j1,int j2,int n,int m,vector<vector<int>> &a){
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2)
                dp[n-1][j1][j2] = a[n-1][j1];
            else    
                dp[n-1][j1][j2] = a[n-1][j1] +a[n-1][j2]; 
        }
    }
    //bottom up filling
    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi = -1e9;
                for(int dj1 = -1;dj1<=1;dj1++){
                    for(int dj2=-1;dj2<=1;dj2++){
                        int value =0;
                        if(j1 == j2)
                            value = a[i][j1];
                        else
                            value = a[i][j1] +a[i][j2];
                        if(j1+dj1>=0 && j1+dj1 <m && j2+dj2>=0 && j2+dj2<m)
                            value+= dp[i+1][j1+dj1][j2+dj2];
                        else
                            value+=-1e9;
                        maxi = max(maxi,value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    } 
    return dp[0][0][m-1];
}
// space..
// int dp[r][c][c]
// 1d -> two variables
// 2d -> 1d
// 3d -> 2d
int spacetab(int i,int j1,int j2,int n,int m,vector<vector<int>> &a){
    vector<vector<int>> front(m,vector<int>(m,0));
    vector<vector<int>> cur(m,vector<int>(m,0));
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2)
                front[j1][j2] = a[n-1][j1];
            else    
                front[j1][j2] = a[n-1][j1] +a[n-1][j2]; 
        }
    }
    //bottom up filling
    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi = -1e9;
                for(int dj1 = -1;dj1<=1;dj1++){
                    for(int dj2=-1;dj2<=1;dj2++){
                        int value =0;
                        if(j1 == j2)
                            value = a[i][j1];
                        else
                            value = a[i][j1] +a[i][j2];
                        if(j1+dj1>=0 && j1+dj1 <m && j2+dj2>=0 && j2+dj2<m)
                            value+= front[j1+dj1][j2+dj2];
                        else
                            value+=-1e9;
                        maxi = max(maxi,value);
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        front = cur;
    } 
    return front[0][m-1];
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++)
            cin >> a[i][j];
    }
    cout << maxCherry(0,0,m-1,n,m,a) << endl;

    // dp memorization
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    cout << dpmaxCherry(0,0,m-1,n,m,a,dp) << endl;

    //tab
    cout << tab(0,0,m-1,n,m,a) << endl;

    //spacetab
    cout << spacetab(0,0,m-1,n,m,a) << endl;
    
    return 0;
}
// 3 4
// 2 3 1 2
// 3 4 2 2 
// 5 6 3 5