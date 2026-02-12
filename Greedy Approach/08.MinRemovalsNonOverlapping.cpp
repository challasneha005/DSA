// MIN REMOVAL TO MAKE NON OVERLAPPING INTERVALS O(n log n +n) , O(1)
// JUST REVERSE OF N MEETINGS IN A ROOM.. n-cnt

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n log n+n)
// SPACE COMPLEXITY : O(1)

struct interval{
    int start;
    int end;
};
bool comp(interval a, interval b) {
    return a.end < b.end;
}
int minRemovals(vector<int> &start,vector<int>&end,int n){
    vector<interval> a(n);
    for (int i = 0; i < n; i++) {
        a[i].start = start[i];
        a[i].end = end[i];
    }
    sort(a.begin(), a.end(), comp);
    int cnt = 1;
    int lastEndTime = a[0].end;
    for (int i = 1; i < n; i++) {
        if (a[i].start >= lastEndTime) {
            cnt++;
            lastEndTime = a[i].end;
        }
    }
    return n-cnt;
}

// (eraseOverlapIntervals) is best for interviews.

/*
APPROACH:
- We sort the intervals based on the end time in ascending order.
- We initialize a count variable to keep track of the number of intervals that need to be removed.
- We initialize the end variable to store the end time of the first interval.
- Then, we iterate through the intervals starting from the second interval.
- If the start time of the current interval is less than the end time of the previous interval, it means there is an overlap.
- In that case, we increment the count variable since we need to remove this interval to make the rest non-overlapping.
- Otherwise, if there is no overlap, we update the end variable to the end time of the current interval.
- Finally, we return the count variable, which represents the minimum number of intervals to remove.
*/

bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if(intervals.size() < 2) return 0;
    sort(intervals.begin(), intervals.end(), compare);
    int cnt = 0, end = intervals[0][1];
    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i][0] < end) {
            cnt++;
        }
        else {
            end = intervals[i][1];
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for (int i = 0; i < n; i++) 
        cin >> start[i];
    for (int i = 0; i < n; i++) 
        cin >> end[i];
    cout << minRemovals(start,end,n);
    return 0;
}
