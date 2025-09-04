// NO.OF WAYS TO REACH DESTINATION O(V * k) , O(V)
#include<bits/stdc++.h>
using namespace std;
int countpaths(int n,vector<vector<int>> &roads){
    vector<pair<int,int>> a[n];
    for(auto it:roads){
        a[it[0]].push_back({it[1],it[2]});
        a[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n,1e9),ways(n,0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0,0});
    int mod = (int)(1e9+7);
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it:a[node]){
            int aNode = it.first;
            int edgeW = it.second;
            if(dis +edgeW < dist[aNode]){
                dist[aNode] = dis+edgeW;
                pq.push({dis+edgeW,aNode});
                ways[aNode] = ways[node];
            }
            else if(dis+edgeW  == dist[aNode])
                ways[aNode] = (ways[aNode]+ways[node])%mod;
        }
    }
    return ways[n-1] %mod;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> roads(m, vector<int>(3));
    for (int i = 0; i < m; i++)
        cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
    cout << countpaths(n, roads) << endl;
    return 0;
}
// 7 10
// 0 6 1
// 0 1 1
// 1 2 1
// 1 3 2
// 2 3 1
// 3 4 3
// 3 5 1
// 4 6 1
// 5 6 1
// 2 5 2