// INSERT INTERVAL.. O(n) , O(n)
// IF OVERLAP THERE MAKE IT ONE INTERVAL 
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> insertInterval(vector<vector<int>> &a,vector<int> newInterval){
    vector<vector<int>> res;
    int n = a.size();
    int i=0;
    while(i<n && a[i][1]<newInterval[0]){
        res.push_back(a[i]);
        i++;
    }
    while(i<n && a[i][0] <= newInterval[1]){
        newInterval[0] = min(newInterval[0],a[i][0]);
        newInterval[1] = max(newInterval[1],a[i][1]);
        i++;
    }
    res.push_back(newInterval);
    while(i<n){
        res.push_back(a[i]);
        i++;
    }
    return res;
}
int main() {
    vector<vector<int>> arr = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
    vector<int> newInterval = {4,9};

    vector<vector<int>> ans = insertInterval(arr, newInterval);

    for (auto &v : ans) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    return 0;
}