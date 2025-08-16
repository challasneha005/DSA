//DETECT CYCLE IN UNDIRECTED GRAPGH DFS O(n+2E)+n , O(2n)
#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,int parent,vector<int> &vis,vector<vector<int>> &a){
    vis[node] = 1;
    for(auto adjNode : a[node]){
        if(!vis[adjNode]){
            if(dfs(adjNode,node,vis,a) == true)
                return true;
        }
        else if(adjNode!=parent)
            return true;
    }
    return false;
}
bool isCyclic(int V,vector<vector<int>> &a){
    vector<int> vis(V,0);  
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,-1,vis,a) == true)
                return true;
        }
    }
    return false;
}
     
int main(){
    int n,e;
    cin >> n >> e;
    vector<vector<int>> a(n);
    for(int i=0;i<e;i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        cout << i+1 << ": ";
        for (int neighbor : a[i]) {
            cout << neighbor+1 << " "; //display only
        }
        cout << endl;
    }
    if(isCyclic(n,a))
        cout << "Cycle detected in the graph." << endl;
    else
        cout << "No cycle in the graph." << endl;
    return 0;
}