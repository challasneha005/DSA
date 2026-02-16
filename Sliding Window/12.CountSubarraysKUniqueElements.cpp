// COUNT NO.oF SUBARRAYS WITH K DIFFERENT INTEGERS

#include<bits/stdc++.h>
using namespace std;

// brute O(n*n) , O(n)
int countSubarraysKDifferentIntegersBrute(vector<int> &a,int k){
    int n = a.size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        unordered_map<int, int> mp;
        for(int j=i;j<n;j++){
            mp[a[j]]++;
            if(mp.size() == k)
                cnt++;
            else if(mp.size() > k)
                break;
        }
    }
    return cnt;
}

// Optimal O(2n) , O(n)

//  TIME COMPLEXITY O(2n)
//  SPACE COMPLEXITY O(n)

/*
APPROACH:
1. Create a helper function countOptimal(a, k) to count subarrays with at most k distinct integers.
2. Use a sliding window with two pointers:
   - l (left) and r (right).
3. Maintain an unordered_map mp to store the frequency of elements in the current window.
4. Move the right pointer r forward and add a[r] to the map.
5. If the number of distinct elements (mp.size()) becomes greater than k:
   - Decrease the frequency of a[l].
   - If the frequency becomes zero, erase it from the map.
   - Move the left pointer l forward.
6. Once the window has at most k distinct elements, all subarrays ending at r
   and starting between l and r are valid.
   - Add (r - l + 1) to the count.
7. Continue until the entire array is processed.
8. To get subarrays with exactly k distinct integers:
   - exactly k = atMost(k) - atMost(k - 1).
9. Return the final answer.
*/

int countOptimal(vector<int> &a,int k){
    int n = a.size();
    int l = 0,r = 0,cnt = 0;
    unordered_map<int,int> mp;
    while(r<n){
        mp[a[r]]++;
        while(mp.size() > k){
            mp[a[l]]--;
            if(mp[a[l]] == 0)
                mp.erase(a[l]);
            l++;
        }
        cnt +=(r-l+1);
        r++;
    }
    return cnt;
}
int countSubarraysKDifferentIntegersOptimal(vector<int> &a,int k){
    return countOptimal(a,k) - countOptimal(a,k-1);
}

int main(){
    int n,k;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> k;
    cout << countSubarraysKDifferentIntegersBrute(a,k) <<"\n";
    cout << countSubarraysKDifferentIntegersOptimal(a,k) <<"\n";
    // cout << countSubarraysWithSum(a,k);
    return 0;
}

// INPUT
// 5
// 1 2 1 3 4
// 3