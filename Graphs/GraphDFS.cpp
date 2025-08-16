//DFS TRAVERSAL O(n)+O(2E) , O(3n)
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>> &a,vector<int> &vis,vector <int> &ls){
    vis[node] = 1;
    ls.push_back(node);
    for(auto it:a[node]){
        if(!vis[it])
            dfs(it,a,vis,ls);
    }
}
vector<int> dfsGraph(int v,vector<vector<int>> &a){
    vector<int> vis(v+1,0) ;
    int start = 1;
    vector<int> ls;
    dfs(start,a,vis,ls);
    return ls; 
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
    vector<int> dfs = dfsGraph(n,adjList);
    for(auto it: dfs)
        cout << it << " ";
    cout << endl;
    return 0;
}