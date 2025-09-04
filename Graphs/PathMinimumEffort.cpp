//PATH WITH MINIMUM EFFORT O(E log V) ≈ O((nm) log(nm))  , O(n*m)
#include<bits/stdc++.h>
using namespace std;
int minEffort(vector<vector<int>> &heights){
    priority_queue <pair<int,pair<int,int>>, 
    vector<pair<int,pair<int,int>>>, 
    greater<pair<int,pair<int,int>>>> pq;
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    dist[0][0] = 0;
    pq.push({0,{0,0}});
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;
        if(row == n-1 && col ==m-1)
            return diff;
        for(int i=0;i<4;i++){
            int newr = row+dr[i];
            int newc = col+dc[i];
            if(newr >= 0 && newc >=0 && newr < n && newc <m){
                int effort = max(abs(heights[row][col] - heights[newr][newc]),diff);
                if(effort < dist[newr][newc]){
                    dist[newr][newc] = effort;
                    pq.push({effort,{newr,newc}});
                }
            }
        }
    }
    return 0;
}
int main() {
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };
    cout << "Minimum Effort Path: " << minEffort(heights) << endl;
    return 0;
}