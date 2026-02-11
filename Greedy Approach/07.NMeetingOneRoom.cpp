// N MEETINGS ONE ROOM O(2n+log n) , O(3n+n)

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY: O(n log n)
// SPACE COMPLEXITY : O(n)

/*
APPROACH:
1. Create a structure to store each meeting’s start time, end time,
   and its original position.
2. Sort all meetings in ascending order of their end times so that
   meetings finishing earlier are considered first.
3. Select the first meeting and set its end time as the current free time.
4. Traverse the remaining meetings and check if the start time of the
   current meeting is strictly greater than the free time.
5. If the meeting is compatible, select it, update the free time to
   its end time, and store its position.
6. Continue this greedy selection until all meetings are processed.
7. Return the total number of selected meetings along with their positions.
*/

struct meet {
    int start;
    int end;
    int pos;
};

// Sort by ending time
bool comp(meet a, meet b) {
    return a.end < b.end;
}

pair<int, vector<int>> maxMeetings(vector<int> &start, vector<int> &end, int n) {
    vector<meet> a(n);
    for (int i = 0; i < n; i++) {
        a[i].start = start[i];
        a[i].end = end[i];
        a[i].pos = i + 1;
    }
    sort(a.begin(), a.end(), comp);
    int cnt = 1;
    int freetime = a[0].end;
    vector<int> ds;
    ds.push_back(a[0].pos);
    for (int i = 1; i < n; i++) {
        if (a[i].start > freetime) {
            cnt++;
            freetime = a[i].end;
            ds.push_back(a[i].pos);
        }
    }
    return {cnt, ds};
}

// JUST SEE
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> meet;
    for (int i = 0; i < n; i++) {
        meet.push_back({end[i], start[i]});
    }
    sort(meet.begin(), meet.end());
    int ans = 1, prev = meet[0].first;
    for (int i = 1; i < n; i++) {
        if (meet[i].second > prev) {
            ans++;
            prev = meet[i].first;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> start(n), end(n);

    for (int i = 0; i < n; i++) 
        cin >> start[i];
    for (int i = 0; i < n; i++) 
        cin >> end[i];

    auto ans = maxMeetings(start, end, n);

    cout << ans.first << endl;        // number of meetings
    for (int x : ans.second) 
        cout << x << " ";            // meeting positions
}
