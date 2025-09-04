// CHEAPEST FLIGHT WITH K STOPS O(E * k) , O(V+E)
#include<bits/stdc++.h>
using namespace std;
int  cheapFlight(int n,vector<vector<int>> &flight,int src,int dest,int k){
    vector<pair<int,int>> a[n];
    for(auto it: flight)
        a[it[0]].push_back({it[1],it[2]});
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});
    vector<int> dist(n,1e9);
    dist[src] = 0;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;
        if(stops >k)
            continue;
        for(auto iter:a[node]){
            int anode = iter.first;
            int edgew = iter.second;
            if(cost+edgew < dist[anode] && stops <=k){
                dist[anode] = cost+edgew;
                q.push({stops+1,{anode,cost+edgew}});
            }
        }
    }
    if(dist[dest] == 1e9)
        return -1;
    return dist[dest];
}
int main() {
    int n = 4;
    vector<vector<int>> flights = {
        {0,1,100}, {1,2,100}, {2,0,100}, {2,3,200},{1,3,600}
    };
    int src = 0, dest = 3, k = 1;
    cout << "Cheapest Flight Cost: " 
         << cheapFlight(n, flights, src, dest, k) << endl;
    return 0;
}