  //DETECT CYCLE IN UNDIRECTED GRAPGH BFS O(n+2E) ,  O(n+2E)
#include<bits/stdc++.h>
using namespace std;
bool detect(int sr,vector<vector<int>> &a,int vis[]){
    vis[sr]=1;
    queue<pair<int,int>> q;
    q.push({sr,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it:a[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it,node});
            }
            else if(parent!=it)
                return true;
        }
    }
    return false;
}
int main(){
    int n,e;
    cin >> n >> e;
    vector<vector<int>> a(n+1);
    for(int i=0;i<e;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int neighbor : a[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    int vis[n+1] = {0};
    bool hasCycle = false;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(detect(i, a, vis)) {
                hasCycle = true;
                break;
            }
        }
    }
    if(hasCycle)
        cout << "Cycle detected in the graph." << endl;
    else
        cout << "No cycle in the graph." << endl;
    return 0;
}
// 7 7
// 1 2
// 1 3
// 2 5 
// 3 6
// 3 4
// 5 7
// 6 7
