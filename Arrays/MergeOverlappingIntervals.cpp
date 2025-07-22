//MERGE OVERLAPPING INTERVALS
#include<bits/stdc++.h>
using namespace std;
//brute O(n log n)+O92n
void mergeOverlappingBrute(vector<vector<int>> &a,int n){
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        int start = a[i][0];
        int end = a[i][1];
        if(!ans.empty() && end <= ans.back()[1] )
            continue;
        for(int j=i+1;j<n;j++){
            if(a[j][0] <=end)
                end = max(end,a[j][1]);
            else
                break;
        }
        ans.push_back({start,end});
    }
    for (auto it : ans) 
        cout << "[" << it[0] << ", " << it[1] << "] ";
    cout << endl;
}
//Optimal O(n log n)
void mergeOverlappingOptimal(vector<vector<int>> &a,int n){
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(ans.empty() || a[i][0] > ans.back()[1])
            ans.push_back(a[i]);
        else
            ans.back()[1] = max(ans.back()[1],a[i][1]);
    }
    for (auto it : ans) 
        cout << "[" << it[0] << ", " << it[1] << "] ";
    cout << endl;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++) 
        cin >> a[i][0] >> a[i][1];
    mergeOverlappingBrute(a,n);
    mergeOverlappingOptimal(a,n);
    return 0;
}