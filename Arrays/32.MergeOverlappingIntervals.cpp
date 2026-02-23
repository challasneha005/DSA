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

/*
TIME COMPLEXITY: O(nlogn), where n is the number of intervals in the input.
The sorting step takes O(nlogn) time, and the merging step takes O(n) time.
Overall, the time complexity is dominated by the sorting step.
SPACE COMPLEXITY: O(n), where n is the number of intervals in the input.
We are using additional space to store the merged intervals in the `ans` vector.
*/

/*
APPROACH:
To merge overlapping intervals, we can follow these steps:
1. Sort the intervals based on the start time.
2. Initialize a vector `ans` to store the merged intervals.
3. Add the first interval from the sorted intervals to the `ans` vector.
4. Iterate through the remaining intervals:
   - If the start time of the current interval is less than or equal to the end time of the last interval in the `ans` vector, it means they overlap. Update the end time of the last interval in the `ans` vector if necessary.
   - If the start time of the current interval is greater than the end time of the last interval in the `ans` vector, it means they don't overlap. Add the current interval to the `ans` vector.
5. Return the `ans` vector as the merged non-overlapping intervals.
*/

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

// INPUT
// 3
// 1 6 
// 8 10 
// 15 18
