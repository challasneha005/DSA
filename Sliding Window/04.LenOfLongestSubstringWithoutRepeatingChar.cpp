// LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS

#include<bits/stdc++.h>
using namespace std;

// brute O(n*n) , O(256)
int lenOfLongestSubstringBrute(string &s){
    int n = s.size();
    int maxLen = 0,len = 0;
    for(int i=0;i<n;i++){
        vector<int> mp(256,0);
        for(int j=i;j<n;j++){
            if(mp[s[j]] == 1)
                break;
            len = j-i+1;
            maxLen = max(maxLen,len);
            mp[s[j]] = 1;
        }
    }
    return maxLen;
}

// Optimal

//  TIME COMPLEXITY O(n)
//  SPACE COMPLEXITY O(256)

/*APPROACH: Sliding Window with Last Seen Index (Optimal)
To find the length of the longest substring without repeating characters, we use a sliding window with two pointers and a hash map to track the last seen index of each character.
1.Initialize pointers and data structure
   -Use two pointers l (left) and r (right) to represent the current window.
   -Use an unordered map to store the last index at which each character appeared.
   -Initialize maxLen to store the maximum length found.
2.Expand the window
   -Move the right pointer r across the string one character at a time.
   -If the current character has appeared before and its last index is within the current window (>= l), update the left pointer l to one position right of the previous occurrence.
3.Update window and answer
   -Update the last seen index of the current character in the map.
   -Calculate the current window length as r - l + 1 and update maxLen if it is larger.
4.Final result
    After processing all characters, maxLen contains the length of the longest substring with all unique characters.
*/

int lenOfLongestSubstringOptimal(string &s){
    int n = s.size();
    int l = 0,r = 0, len = 0,maxLen = 0;
    unordered_map<char,int> hash;
    while(r<n){
        if(hash.find(s[r]) != hash.end()){ // check present or not
            if(hash[s[r]] >= l)
                l = hash[s[r]]+1;
        }
        len = r-l+1;
        maxLen = max(len,maxLen);
        hash[s[r]] = r;
        r++;
    }
    return maxLen;
}

int main(){
    string s;
    cin >> s;
    cout << lenOfLongestSubstringBrute(s) <<"\n";
    cout << lenOfLongestSubstringOptimal(s) <<"\n";
    return 0;
}

// INPUT
// cadbzabcd