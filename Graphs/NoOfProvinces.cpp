//NO.OF PROVINCES O(n)+O(v+2E) , O(n)+O(n)
#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adjList[], int vis[]) {
    vis[node] = 1;
    for (auto it : adjList[node]) {
        if (!vis[it])
            dfs(it, adjList, vis);
    }
}
int nump(vector<vector<int>> a,int v){
    vector<int> adjList[v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(a[i][j] ==1 && i!=j){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    int vis[v] = {0};
    int count = 0;
    for(int i =0;i<v;i++){
        if(!vis[i]){
            count++;
            dfs(i,adjList,vis);
        }
    }
    return count;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> aList = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    cout << nump(aList,n) << endl;
    return 0;
}