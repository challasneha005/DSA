//EVENTUAL SAFE NODES -BFS O(V+E) + Vlog V , O(3n)
#include<bits/stdc++.h>
using namespace std;
vector<int> eventualSafe(int V,vector<int> a[]){
    vector<int> adjRev[V];
    int indegree[V] ={0};
    for(int i=0;i<V;i++){
        for(auto it:a[i]){
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    vector<int> safeNodes;
    for(int i=0;i<V;i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);
        for(auto it:adjRev[node]){
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    sort(safeNodes.begin(),safeNodes.end());
    return safeNodes;
}
int main(){
    int V,e;
    cin >> V >> e;
    vector<int> a[V];
    for(int i=0;i<e;i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    for (int i = 0; i <V; i++) {
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
// 0 1
// 1 2
// 2 3
// 3 5
// 3 4
// 4 6
// 6 7
// 5 6
// 8 1
// 8 9
// 9 10
// 10 8
// 11 9
