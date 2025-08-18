//DETECT A CYCLE IN DIRECTED GRAPH - DFS O(V+E) , O(2n)
#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<int> a[],int vis[],int pathvis[]){
    vis[node] = 1;
    pathvis[node] = 1;
    for(auto it: a[node]){
        //node not visited
        if(!vis[it]){
            if(dfs(it,a,vis,pathvis) == true)
                return true;
        }
        //node visited but pathvis also there?
        else if(pathvis[it])
            return true;
    }
    pathvis[node] =0;
    return false;
}
bool isCyclic(int V,vector<int> a[]){
    int vis[V+1] = {0};
    int pathvis[V+1] = {0};
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            if(dfs(i,a,vis,pathvis) == true)
                return true;
        }
    }
    return false;
}
//USING SINGLE ARRAYLIST
bool dfsSingle(int node,vector<int> a[],int vis[]){
    vis[node] = 1;
    for(auto it: a[node]){
        //node not visited
        if(vis[it] == 0){
            if(dfsSingle(it,a,vis) == true)
                return true;
        }
        //node visited but pathvis also there?
        else if(vis[it] == 1)
            return true;
    }
    vis[node] =2; // mark as "processed"
    return false;
}
bool isCyclicSingle(int V,vector<int> a[]){
    int vis[V+1] = {0};
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            if(dfsSingle(i,a,vis) == true)
                return true;
        }
    }
    return false;
}
int main(){
    int V,e;
    cin >> V >> e;
    vector<int> a[V+1];
    for(int i=0;i<e;i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    for (int i = 1; i <=V; i++) {
        cout << i << ": ";
        for (int neighbor : a[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    // if (isCyclic(V, a))
    if (isCyclicSingle(V, a))
        cout << "Cycle detected in directed graph." << endl;
    else
        cout << "No cycle in directed graph." << endl;
    return 0;
}




//input cycle
// 10 11
// 1 2
// 2 3
// 3 4
// 3 7
// 4 5
// 7 5
// 5 6
// 8 2 
// 8 9
// 9 10
// 10 8