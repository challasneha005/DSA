//BFS TRAVERSAL O(n)+O(2E) , O(3n)
#include<bits/stdc++.h>
using namespace std;
vector<int> bfsGraph(int v,vector<vector<int>> &a){
    vector<int> vis(v+1,0) ;
    vis[1] = 1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: a[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adjList(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    } 
    // print adjacency list
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    vector<int> bfs = bfsGraph(n,adjList);
    for(auto it: bfs)
        cout << it << " ";
    cout << endl;
    return 0;
}

