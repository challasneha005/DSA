// TOPOLOGICAL SORTING BFS O(V+2E) , O(2n)
//KAHN's ALGORITHM
//ONLY FOR DAG
#include<bits/stdc++.h>
using namespace std;
vector<int> toposort(int V,vector<int> a[]){
    int indegree[V+1] ={0};
    for(int i=1;i<=V;i++){
        for(auto it: a[i])
            indegree[it]++;
    }
    queue<int> q;
    for(int i=1;i<=V;i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        //node in topological order so remove
        for(auto it:a[node]){
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
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