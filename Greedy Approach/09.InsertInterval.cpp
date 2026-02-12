// INSERT INTERVAL.. O(n) , O(n)
// IF OVERLAP THERE MAKE IT ONE INTERVAL 

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(n)

/*
APPROACH:
1. Initialize an empty result list to store the final intervals.
2. Traverse the given intervals and add all intervals that end
   before the new interval starts, since they do not overlap.
3. For all intervals that overlap with the new interval,
   merge them by updating the start as the minimum start
   and the end as the maximum end.
4. After merging all overlapping intervals, add the merged
   new interval to the result list.
5. Finally, add all remaining intervals that start after
   the merged interval.
6. Return the result list containing the updated set of intervals.
*/

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
