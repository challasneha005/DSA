//SHORTEST PATH IN DAG-TOPO SORT O(n+m) , O(n+m)
#include<bits/stdc++.h>
using namespace std;
void toposort(int node,vector<pair<int,int>> a[],int vis[],stack<int> &s){
    vis[node] = 1;
    for(auto it:a[node]){
        int V = it.first;
        if(!vis[V])
            toposort(V,a,vis,s);
    }
    s.push(node);
}
vector<int> ShortestpathDAG(int N,int M,vector<vector<int>> edges){
    vector<pair<int,int>> a[N];
    for(int i=0;i<M;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        a[u].push_back({v,wt});
    }
    int vis[N] = {0};
    stack<int> s;
    for(int i=0;i<N;i++){
        if(!vis[i])
            toposort(i,a,vis,s);
    }
    vector<int> dist(N);
    for(int i=0;i<N;i++)
        dist[i] = 1e9;
    dist[0] = 0;
    while(!s.empty()){
        int node = s.top();
        s.pop();
        for(auto it:a[node]){
            int V = it.first;
            int wt = it.second;
            if(dist[node] != 1e9 &&  dist[node]+wt < dist[V])
                dist[V] = dist[node]+wt;
        }
    }
    return dist;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        edges[i].push_back(u);
        edges[i].push_back(v);
        edges[i].push_back(wt);
    }
    vector<int> res = ShortestpathDAG(n,m,edges);
    for(auto x:res){
        if(x==1e9) 
            cout << "INF ";
        else    
            cout << x << " ";
    }
    cout << endl;
    return 0;
}

// 6 7
// 0 1 2
// 0 4 1
// 1 2 3
// 4 2 2
// 4 5 4
// 2 3 6
// 5 3 1
