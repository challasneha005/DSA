// No.Of ways to return TRUE IN BOOLEAN EXPRESSION
#include<bits/stdc++.h>
using namespace std;
int mod = 100000000;
// recursion
long long waysCount(int i,int j,int isTrue,string &exp){
    if(i>j)
        return 0;
    if(i==j){
        if(isTrue)
            return exp[i] == 'T';
        else    
            return exp[i] == 'F';
    }
    long long ways = 0;
    for(int ind=i+1;ind<=j-1;ind+=2){
        long long lT = waysCount(i,ind-1,1,exp);
        long long lF = waysCount(i,ind-1,0,exp);
        long long rT = waysCount(ind+1,j,1,exp);
        long long rF = waysCount(ind+1,j,0,exp);

        if( exp[ind] == '&'){
            if(isTrue)
                ways = (ways+(lT * rT) %mod) %mod;
            else    
                ways = (ways +(rT * lF) % mod + (lT * rF) %mod + (rF * lF) % mod) % mod;
        }
        else if(exp[ind] == '|'){
            if(isTrue)
                ways = (ways+(lT * rT) % mod + (rT * lF) % mod + (rF * lT) % mod) % mod;
            else    
                ways = (ways+(rF * lF) %mod) %mod;
        }
        else{
            if(isTrue)
                ways = (ways + (lT * rF)%mod + (lF * rT) % mod) % mod;
            else
                ways = (ways + (lT * rT)%mod + (lF * rF) % mod) % mod;
        }
    }
    return ways;
}
// dp O(n*n*n) , O(n*n) +O(n)
long long dpwaysCount(int i,int j,int isTrue,string &exp,vector<vector<vector<long long>>> &dp){
    if(i>j)
        return 0;
    if(i==j){
        if(isTrue)
            return exp[i] == 'T';
        else    
            return exp[i] == 'F';
    }
    if(dp[i][j][isTrue] !=-1)
        return dp[i][j][isTrue];
    long long ways = 0;
    for(int ind=i+1;ind<=j-1;ind+=2){
        long long lT = dpwaysCount(i,ind-1,1,exp,dp);
        long long lF = dpwaysCount(i,ind-1,0,exp,dp);
        long long rT = dpwaysCount(ind+1,j,1,exp,dp);
        long long rF = dpwaysCount(ind+1,j,0,exp,dp);

        if( exp[ind] == '&'){
            if(isTrue)
                ways = (ways+(lT * rT) %mod) %mod;
            else    
                ways = (ways +(rT * lF) % mod + (lT * rF) %mod + (rF * lF) % mod) % mod;
        }
        else if(exp[ind] == '|'){
            if(isTrue)
                ways = (ways+(lT * rT) % mod + (rT * lF) % mod + (rF * lT) % mod) % mod;
            else    
                ways = (ways+(rF * lF) %mod) %mod;
        }
        else{
            if(isTrue)
                ways = (ways + (lT * rF)%mod + (lF * rT) % mod) % mod;
            else
                ways = (ways + (lT * rT)%mod + (lF * rF) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] =ways;
}
// tab
long long tab(int n,string &exp){
    vector<vector<vector<long long>>> dp(n,
        vector<vector<long long>>(n, vector<long long>(2, 0)));
    for(int i=0;i<n;i++){
        dp[i][i][1] =  (exp[i]=='T');
        dp[i][i][0] =  (exp[i]=='F');
    }
     
    for(int i = n-1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            for(int isTrue = 0; isTrue <= 1; isTrue++){
                long long ways = 0;
                for(int ind=i+1;ind<=j-1;ind+=2){
                    long long lT = dp[i][ind-1][1];
                    long long lF = dp[i][ind-1][0];
                    long long rT = dp[ind+1][j][1];
                    long long rF = dp[ind+1][j][0];

                    if( exp[ind] == '&'){
                        if(isTrue)
                            ways = (ways+(lT * rT) %mod) %mod;
                        else    
                            ways = (ways +(rT * lF) % mod + (lT * rF) %mod + (rF * lF) % mod) % mod;
                    }
                    else if(exp[ind] == '|'){
                        if(isTrue)
                            ways = (ways+(lT * rT) % mod + (rT * lF) % mod + (rF * lT) % mod) % mod;
                        else    
                            ways = (ways+(rF * lF) %mod) %mod;
                    }
                    else{
                        if(isTrue)
                            ways = (ways + (lT * rF)%mod + (lF * rT) % mod) % mod;
                        else
                            ways = (ways + (lT * rT)%mod + (lF * rF) % mod) % mod;
                    }
                }
                dp[i][j][isTrue] =ways;
            }   
        }    
    }
    return dp[0][n-1][1];
}
int main() {
    string exp;
    cin >> exp;

    int n = exp.size();

    cout << waysCount(0, n - 1, 1, exp) % mod << endl;

    vector<vector<vector<long long>>> dp(n,
        vector<vector<long long>>(n, vector<long long>(2, -1)));
    cout << dpwaysCount(0, n - 1, 1, exp,dp) % mod << endl;

    cout << tab(n,exp) << endl;
    return 0;
}