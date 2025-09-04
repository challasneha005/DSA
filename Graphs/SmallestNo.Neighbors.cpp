// CITY WITH SMALLEST NO.OF NEIGHBOURS AT THRESHOLD O(V*V*V) , O(V*V)
#include<bits/stdc++.h>
using namespace std;
int findcity(int n,int m,vector<vector<int>> &edges,int distThreshold){
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    for(auto it:edges){
        dist[it[0]] [it[1]] = it[2];
        dist[it[1]] [it[0]] = it[2];
    }
    for(int i=0;i<n;i++)
        dist[i][i] = 0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    continue;
                dist[i][j] = min(dist[i][j] ,dist[i][k] + dist[k][j]);
            }
        }
    }
    int cntcity =n, cityNo = -1;
    for(int city =0;city<n;city++){
        int cnt = 0;
        for(int adjcity=0;adjcity <n;adjcity++){
            if( city != adjcity && dist[city][adjcity] <= distThreshold)
                cnt++;
        }
        if(cnt <= cntcity){
            cntcity = cnt;
            cityNo = city;
        }
    }
    return cityNo;
} 
int main() {
    int n, m, threshold;
    cin >> n >> m >> threshold;
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++) cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    cout << findcity(n, m, edges, threshold) << endl;
    return 0;
}
// 4 4 4
// 0 1 3
// 1 2 1
// 1 3 4
// 2 3 1
