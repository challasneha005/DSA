// NINJA TRAINING
#include<bits/stdc++.h>
using namespace std;
//recursion
int maxPoints(int day,int last,vector<vector<int>> &task){
    if(day == 0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=last)
                maxi = max(maxi,task[0][i]);
        }
        return maxi;
    }
    int maxi = 0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int points = task[day][i]+maxPoints(day-1,i,task);
            maxi = max(maxi,points);
        }
    }
    return maxi;
}
// dynamic  memorization O(n*4)*3 , O(n)+O(n*4)
int dpMaxPoints(int day,int last,vector<vector<int>> &task,vector<vector<int>> &dp){
    if(day == 0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=last)
                maxi = max(maxi,task[0][i]);
        }
        return maxi;
    }
    if(dp[day][last] !=-1)
        return dp[day][last];
    int maxi = 0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int points = task[day][i]+dpMaxPoints(day-1,i,task,dp);
            maxi = max(maxi,points);
        }
    }
    return dp[day][last]=maxi;
}
//tabulation O(n*4*3) , O(n*4)
int tab(int n,vector<vector<int>> &a){
    vector<vector<int>> dp(n,vector<int>(4,0));
    dp[0][0] = max(a[0][1],a[0][2]);
    dp[0][1] = max(a[0][0],a[0][2]);
    dp[0][2] = max(a[0][0],a[0][1]);
    dp[0][3] = max(a[0][1],max(a[0][0],a[0][2]));

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last] = 0;
            int maxi = 0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    int points = a[day][i]+dp[day-1][i];
                    dp[day][last] = max(dp[day][last],points);
                }
            }
        }
    }
    return dp[n-1][3];
}
// space optimization O(n*4*3) , O(4)
int spacetab(int n,vector<vector<int>> &a){
    vector<int> prev(4,0);
    prev[0] = max(a[0][1],a[0][2]);
    prev[1] = max(a[0][0],a[0][2]);
    prev[2] = max(a[0][0],a[0][1]);
    prev[3] = max(a[0][1],max(a[0][0],a[0][2]));

    for(int day=1;day<n;day++){
        vector<int> temp(4,0);
        for(int last=0;last<4;last++){
            temp[last] = 0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    temp[last] = max(temp[last],a[day][i]+prev[i]);
                }
            }
        }
        prev = temp;
    }
    return prev[3]; 
}
int main(){
    int n;//no.of days
    cin >> n;
    vector<vector<int>> a(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> a[i][j];
        }
    }
    // cout << maxPoints(n - 1, 3, a);
    vector<vector<int>> dp(n,vector<int>(4,-1));
    // cout << dpMaxPoints(n-1,3,a,dp);
    cout << tab(n,a);
    cout << spacetab(n,a);
    return 0;
}
// 4
// 2 1 3
// 3 4 6
// 10 1 6
// 8 3 7