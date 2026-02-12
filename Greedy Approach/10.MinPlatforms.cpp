// MIN NO.oF PLATFORMS REQUIRED FOR A RAILWAY 

#include<bits/stdc++.h>
using namespace std;

// brute O(n*n) , O(1)
int minPlatformsBrute(vector<int> &a,vector<int> &d){
    int n = a.size() , maxcnt = 0 , cnt = 0;
    for(int i=0;i<n;i++){
        cnt = 1;
        for(int j =i+1;j<n;j++){
            if(a[j] <= d[i] && a[i] <= d[j])
                cnt++;
        }
        maxcnt = max(maxcnt,cnt);
    }
    return maxcnt;
} 

// Optimal O(2( n log n +n)) , O(1)

// TIME COMPLEXITY : O(n log n+n)
// SPACE COMPLEXITY : O(1)

/*
APPROACH:
1. We sort the arrival array a and the departure array d in non-decreasing order.
2. We initialize two pointers i and j for traversing the arrival and departure arrays, along with variables cnt (current platforms in use) and maxcnt (maximum platforms needed).
3. We iterate through both arrays while i and j are within bounds.
4. If the arrival time a[i] is less than or equal to the departure time d[j], it means a train is arriving and an additional platform is required.
   - We increment i and increase cnt.
   - We update maxcnt with the maximum of maxcnt and cnt.
5. If the arrival time a[i] is greater than the departure time d[j], it means a train has departed and a platform is freed.
   - We increment j and decrease cnt.
6. After the traversal, maxcnt represents the minimum number of platforms required, which we return as the answer.
*/

int minPlatformsOptimal(vector<int> &a,vector<int> &d){
    int n = a.size();
    sort(a.begin(),a.end()) , sort(d.begin(), d.end());
    int i =0 , j= 0,cnt = 0,maxcnt = 0;
    while(i<n && j<n){
        if(a[i] <= d[j]){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        maxcnt = max(maxcnt, cnt);
    }
    return maxcnt;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n) , d(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> d[i];
    cout << minPlatformsBrute(a,d) << "\n";
    cout << minPlatformsOptimal(a,d) << "\n";
    return 0;
}

// INPUT 
// 6
// 900 945 955 1100 1500 1800
// 920 1200 1130 1150 1900 2000