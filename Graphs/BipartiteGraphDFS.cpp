//BIPARTITE GRAPH -DFS O(n+2E) , O(n)
#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,int col,int color[],vector<int> adj[]){
    color[node] = col;
    for(auto it:adj[node]){
        if(color[it] == -1){
            if(dfs(it,!col,color,adj) == false)
                return false;
        }
        else if(color[it] == col)    
            return false;
    }
    return true;
}
bool isBipartite(int V,vector<int> adj[]){
    int color[V+1];
    for(int i=1;i<=V;i++)
        color[i] = -1;
    for(int i=1;i<=V;i++){
        if(color[i] == -1){
            if(dfs(i,0,color,adj) == false)
                return false;
        }
    }
    return true;
}
int main(){
    int V,e;
    cin >> V >> e;
    vector<int> adj[V+1];
    for(int i=0;i<e;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // print adjacency list
    for (int i = 1; i <= V; i++) {
        cout << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    if(isBipartite(V,adj))
        cout << "It is Bipartite Graph";
    else
        cout << "It is not a Bipartite Graph";
    return 0;
}

//input not
// 8 8
// 1 2
// 2 3
// 2 6
// 3 4
// 6 5
// 4 5
// 4 7
// 7 8
