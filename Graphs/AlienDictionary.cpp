//ALIEN DICTIONARY--TOPOSORT -BFS O(N*L+ V+2E) , O(V+E)
#include<bits/stdc++.h>
using namespace std;
vector<int> toposort(int V,vector<int> a[]){
    int indegree[V] ={0};
    for(int i=0;i<V;i++){
        for(auto it: a[i])
            indegree[it]++;
    }
    queue<int> q;
    for(int i=0;i<V;i++){
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
string findOrder(string dict[],int N,int k){
    vector<int> adj[k];
    for(int i=0;i<N-1;i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(),s2.size());
        for(int ptr=0;ptr<len ;ptr++){
            if(s1[ptr] != s2[ptr]){
                adj[s1[ptr] -'a'].push_back(s2[ptr]-'a');
                break;
            }
        }
    }
    vector<int> topo = toposort(k,adj);
    string s ="";
    for(auto it:topo)
        s.push_back(char(it + 'a'));
    return s;
}
int main(){
    int V,e;
    cin >> V >> e;
    string  a[V];
    for (int i = 0; i <V; i++)  
        cin >> a[i];
    string order = findOrder(a,V,e);
    cout << order << endl;
    return 0;
}

// 5 4
// baa
// abcd
// abca
// cab
// cad
