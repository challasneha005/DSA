// N MEETINGS ONE ROOM 
#include<bits/stdc++.h>
using namespace std;

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
