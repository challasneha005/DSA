//SHORTEST PATH IN UNDIRECTED GRAPH - UNIT WEIGHT-BFS O(n+m) , O(n+m)
#include<bits/stdc++.h>
using namespace std;
vector<int> ShortestpathUndirected(int N,int M,vector<vector<int>> edges,int src){
    vector<int> a[N];
    for(auto it:edges){
        a[it[0]].push_back(it[1]);
        a[it[1]].push_back(it[0]);
    }
    vector<int> dist(N, 1e9);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:a[node]){
            if(dist[node] != 1e9 &&  dist[node]+1 < dist[it]){
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }
    }
    vector<int> ans(N,-1);
    for(int i=0;i<N;i++){
        if(dist[i] != 1e9)
            ans[i] = dist[i];
    }
    return ans;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        edges[i].push_back(u);
        edges[i].push_back(v);
    }
    int src;
    cin >> src; 
    vector<int> res = ShortestpathUndirected(n,m,edges,src);
    for(auto x:res)   
        cout << x << " ";
    return 0;
}

// 6 7
// 0 1
// 0 4
// 1 2
// 4 2
// 4 5
// 2 3
// 5 3
// 0
