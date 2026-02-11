 // JUMP GAME - Min Steps to reach end O(n*n) , O(n*n)

#include<bits/stdc++.h>
using namespace std;

// CAN ALSO BE DONE USING DP..
// AS GOAL IS TO REACH FARTHEST IT IS UNDER GREEDY
//Greedy approach O(n), O(1)

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

/*
APPROACH:
1. Treat the problem as expanding reachable ranges using a greedy strategy.
2. Use two pointers l and r to represent the current range of indices
   that can be reached with the current number of jumps.
3. For all indices in the current range [l, r], compute the farthest
   index that can be reached using one more jump.
4. After processing the current range, update the range to
   [r + 1, farthest], which represents the indices reachable with
   one additional jump.
5. Increment the jump count each time the range is expanded.
6. Repeat the process until the last index is included in the range.
7. The total number of range expansions gives the minimum number of jumps.
*/

int greedy(vector<int> &a){
    int jumps = 0;
    int l=0,r=0;
    while(r<a.size()-1){
        int farthest = 0;
        for(int i=l;i<=r;i++){
            farthest = max(i+a[i],farthest);
        }
        l = r+1;
        r = farthest;
        jumps++;
    }
    return jumps;
}

// recursion O(n^n), O(n) 
int minSteps(int ind,int jumps,vector<int> &a,int n){
    if(ind >=n-1)
        return jumps;
    if (a[ind] == 0) 
        return INT_MAX;
    int mini = INT_MAX;
    for(int step=1;step<=a[ind]&& ind + step < n;step++)
        mini = min(mini,minSteps(ind+step,jumps+1,a,n));
    return mini;
}

int rec(int ind, vector<int> &a, int n) {
    if (ind >= n - 1) 
        return 0;   // reached end
    if (a[ind] == 0) 
        return 1e9; // cannot move
    int mini = 1e9;
    for (int step= 1; step<= a[ind]&& ind + step < n; step++) {
        mini = min(mini, 1 + rec(ind + step, a, n));
    }
    return mini;
}

// dp O(n*n) , O(n*n)
int dpminSteps(int ind,int jumps,vector<int> &a,int n,vector<vector<int>> &dp){
    if(ind >=n-1)
        return jumps;
    if (a[ind] == 0) 
        return INT_MAX;
    if(dp[ind][jumps]!=-1)
        return dp[ind][jumps];
    int mini = INT_MAX;
    for(int i=1;i<=a[ind]&& ind + i < n;i++)
        mini = min(mini,dpminSteps(ind+i,jumps+1,a,n,dp));
    return dp[ind][jumps] = mini;
}

int memoSolve(int ind, vector<int> &a, int n, vector<int> &dp) {
    if (ind >= n - 1) 
        return 0;
    if (a[ind] == 0) 
        return 1e9;
    if (dp[ind] != -1) 
        return dp[ind];
    int mini = 1e9;
    for (int step= 1; step<= a[ind]&& ind + step < n; step++) {
        mini = min(mini, 1 + memoSolve(ind + step, a, n, dp));
    }

    return dp[ind] = mini;
}

// tab
int tab(vector<int> &a,int n){
    vector<int> dp(n,1e9);
    dp[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        for (int step= 1; step<= a[i] && i + step < n; step++)
            dp[i] = min(dp[i], 1 + dp[i+step]);
    }
    return dp[0];
}

//Follow greedy best...
int main(){
    vector<int> a = {1,2,4,1,1,3,2,5};
    int n = a.size();
    cout << greedy(a) << endl;
    cout << minSteps(0,0,a,n) << endl;
    
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout << dpminSteps(0,0,a,n,dp) << endl;
    cout << rec(0,a,n) << endl;
    
    vector<int> dpm(n,-1);
    cout << memoSolve(0,a,n,dpm) << endl;
    cout << tab(a,n) << endl;
    return 0;
}
