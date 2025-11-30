// MIN REMOVAL TO MAKE NON OVERLAPPING INTERVALS O(n log n +n) , O(1)
// JUST REVERSE OF N MEETINGS IN A ROOM.. n-cnt
#include<bits/stdc++.h>
using namespace std;
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