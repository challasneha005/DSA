// LONGEST SUBSTRING AT MOST K DISTINCT CHARACTERS

#include<bits/stdc++.h>
using namespace std;

//  brute O(n*n* log 256) , O(256)
int maxLenSubStringkBrute(string &s,int k){
    int n = s.size();
    int maxLen = 0;
    unordered_map<char,int> mp;
    for(int i=0;i<n;i++){
        mp.clear();
        for(int j=i;j<n;j++){
            mp[s[j]]++;
            if(mp.size() <= k)
                maxLen = max(maxLen,j-i+1);
            else
                break;
        }
    }
    return maxLen;
}

// better O(n*n*log 256) , O(256)
int maxLenSubStringkBetter(string &s,int k){
    int n = s.size();
    int l = 0,r = 0, maxLen = 0;
    unordered_map<char,int> mp;
    while(r<n){
        mp[s[r]]++;
        while(mp.size() > k){
            mp[s[l]]--;
            if(mp[s[l]] == 0)
                mp.erase(s[l]);
            l++;
        }
        if(mp.size()<= k)
            maxLen = max(maxLen,r-l+1);
        r++;
    }
    return maxLen;
}

// Optimal O(n) , O(256)

//  TIME COMPLEXITY O(n)
//  SPACE COMPLEXITY O(256)

/*
APPROACH
1. Create a function maxLenSubStringkOptimal that takes an integer k and a string s.
2. Use a sliding window with two pointers l (left) and r (right).
3. Maintain an unordered_map mp to store the frequency of characters in the current window.
4. Move the right pointer r and add the current character to the map.
5. If the number of distinct characters exceeds k:
    -Remove one character from the left side of the window.
    -Decrease its frequency and erase it if the frequency becomes zero.
    -Move the left pointer l forward by one.
6. If the window contains at most k distinct characters:
    -Update the maximum length (maxLen).
7. Continue until the entire string is processed.
8. Return maxLen.
*/

int maxLenSubStringkOptimal(string &s,int k){
    int n = s.size();
    int l = 0,r = 0, maxLen = 0;
    unordered_map<char,int> mp;
    while(r<n){
        mp[s[r]]++;
        if(mp.size() > k){
            mp[s[l]]--;
            if(mp[s[l]] == 0)
                mp.erase(s[l]);
            l++;
        }
        if(mp.size()<= k)
            maxLen = max(maxLen,r-l+1);
        r++;
    }
    return maxLen;
}

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << maxLenSubStringkBrute(s,k) << "\n";
    cout << maxLenSubStringkBetter(s,k)<< "\n";
    cout << maxLenSubStringkOptimal(s,k)<< "\n";
    return 0;
}

// INPUT
// aaabbccd
// 2