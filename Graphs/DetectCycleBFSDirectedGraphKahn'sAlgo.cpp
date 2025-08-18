// //DETECT A CYCLE IN DIRECTED GRAPH - BFS O(V+2E) , O(2n)
//KAHN's ALGORITHM
#include<bits/stdc++.h>
using namespace std;
bool detectCycleKahn(int V,vector<int> a[]){
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
    // vector<int> ans;
    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        // ans.push_back(node);
        count++;
        //node in topological order so remove
        for(auto it:a[node]){
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    if(count == V)
        return false;
    return true;
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
    if (detectCycleKahn(V, a))
        cout << "Cycle detected in directed graph." << endl;
    else
        cout << "No cycle in directed graph." << endl;
    return 0;
}
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
// 12 10
