// TOPOLOGICAL SORTING -DFS O(V+2E) , O(2n)
//ONLY FOR DAG
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int vis[],stack<int> &s,vector<int> a[]){
    vis[node] = 1;
    for(auto it: a[node]){
        if(!vis[it])
            dfs(it,vis,s,a);
    }
    s.push(node);
}
vector<int> toposort(int V,vector<int> a[]){
    int vis[V+1] ={0};
    stack<int> s;
    for(int i=1;i<=V;i++){
        if(!vis[i])
            dfs(i,vis,s,a);
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
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
    vector<int> result = toposort(V,a);
    for(auto i:result)
        cout << i << " ";
    return 0;
}
// 6 6
// 5 6
// 4 6
// 4 1
// 3 1
// 2 3
// 5 2
