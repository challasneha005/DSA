// MAX FRUITS INTO BASKET -- NO SKIP, ONLY TWO VARIETIES
// MAX LENGTH SUNARRAY WITH ATMOST 2 TYPES OF FRUITS

#include<bits/stdc++.h>
using namespace std;

// brute O(n*n) , O(3)
int maxFruitsBrute(vector<int> &a){
    int n = a.size();
    int maxLen = 0;
    for(int i=0;i<n;i++){
        set<int> s;
        for(int j=i;j<n;j++){
            s.insert(a[j]);
            if(s.size() <=2)
                maxLen = max(maxLen,j-i+1);
            else
                break;
        }
    }
    return maxLen;
}

// better O(n*n) , O(1)
int maxFruitsBetter(vector<int> &a){
    int n = a.size();
    int l = 0,r = 0, maxLen = 0;
    unordered_map<int,int> mp;
    while(r<n){
        mp[a[r]]++;
        if(mp.size() > 2){
            while(mp.size() > 2){
                mp[a[l]]--;
                if(mp[a[l]] == 0)
                    mp.erase(a[l]);
                l++;
            }
        }
        if(mp.size()<= 2)
            maxLen = max(maxLen,r-l+1);
        r++;
    }
    return maxLen;
}

// Optimal O(n) , O(1)

// TIME COMPLEXITY - O(n) N is the number of fruit trees. We iterate through the fruit trees once using the sliding window approach. 
// SPACE COMPLEXITY - O(1) O(2), as the size of the map can be at most 2 since we only have two baskets.

/*
APPROACH  
1. Initialize two pointers l and r to represent a sliding window.
2. Use an unordered_map mp to store the frequency of fruit types in the current window.
3. Traverse the array using the right pointer r:
    -Add the current fruit a[r] to the map.
4. If the number of distinct fruits becomes more than 2:
    -Remove one fruit from the left side by decreasing its frequency.
    -If its frequency becomes 0, erase it from the map.
    -Move the left pointer l forward by 1.
5. If the window contains at most 2 distinct fruits:
    -Update the maximum window size (maxLen).
6. Continue until the end of the array.
7. Return maxLen.
*/

int maxFruitsOptimal(vector<int> &a){
    int n = a.size();
    int l = 0,r = 0, maxLen = 0;
    unordered_map<int,int> mp;
    while(r<n){
        mp[a[r]]++;
        if(mp.size() > 2){
            mp[a[l]]--;
            if(mp[a[l]] == 0)
               mp.erase(a[l]);
            l++;    
        }
        if(mp.size()<= 2)
            maxLen = max(maxLen,r-l+1);
        r++;
    }
    return maxLen;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout <<   maxFruitsBrute(a) <<"\n";
    cout <<   maxFruitsBetter(a) <<"\n";
    cout <<   maxFruitsOptimal(a) <<"\n";
    return 0;
}

// INPUT
// 11
// 3 3 3 1 2 1 1 2 3 3 4