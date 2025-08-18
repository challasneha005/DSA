//EVENTUAL SAFE NODES -DFS O(V+E) , O(3n)
#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<int> a[],int vis[],int pathvis[],int check[]){
    vis[node] = 1;
    pathvis[node] = 1;
    check[node] =0;
    for(auto it: a[node]){
        //node not visited
        if(!vis[it]){
            if(dfs(it,a,vis,pathvis,check) == true){
                check[node] =0;
                return true;
            }
        }
        //node visited but pathvis also there?
        else if(pathvis[it]){
            check[node] =0;
            return true;
        }
    }
    check[node] =1;
    pathvis[node] =0;
    return false;
}
vector<int> eventualSafe(int V,vector<int> a[]){
    int vis[V+1] ={0};
    int pathvis[V+1] ={0};
    int check[V+1] = {0};
    vector<int> safeNodes;
    for(int i=1;i<=V;i++){
        if(!vis[i])
            dfs(i,a,vis,pathvis,check);
    }
    for(int i=1;i<=V;i++){
        if(check[i] ==1)
            safeNodes.push_back(i);
    }
    return safeNodes;
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
    vector<int> safe = eventualSafe(V,a);
    for(auto i:safe)
        cout << i << " ";
    return 0;
}

//input 
// 12 13
// 1 2
// 2 3
// 3 4
// 4 6
// 4 5
// 5 7
// 7 8
// 6 7
// 9 2
// 9 10
// 10 11
// 11 9
//12 10

