//COURSE SCHEDULE || PRE- REQUISITE TASKS- BFS O(V+2E) , O(2n)
//KAHN's ALGORITHM
#include<bits/stdc++.h>
using namespace std;
bool isPossible(int V,vector<pair<int,int>> &prerequisites){
    vector<int> a[V+1];
    for(auto it: prerequisites)
        a[it.first].push_back(it.second);
    for (int i = 1; i <=V; i++) {
        cout << i << ": ";
        for (int neighbor : a[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
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
        return true;
    return false;
}
int main(){
    int V,e;
    cin >> V >> e;
    vector<pair<int,int>> prerequisites;
    for(int i=0;i<e;i++){
        int u, v;
        cin >> u >> v;
        prerequisites.push_back({u,v});
    }

    vector<vector<int>> a(V+1);
    for (auto &p : prerequisites) {
        a[p.first].push_back(p.second);
    }
    //to get order  return ans;
    if (isPossible(V,prerequisites))
        cout << "Schedule is possible" << endl;
    else
        cout << "Schedule is not possible." << endl;
    return 0;
}
// 4 3
// 3 2
// 2 1
// 4 3
 