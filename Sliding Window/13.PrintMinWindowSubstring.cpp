// MINIMUM WINDOW SUBSTRING

#include<bits/stdc++.h>
using namespace std;

// Brute O(n*n) , O(256)
string lenMinWindowSubstringBrute(string &s,string &t){
    int n = s.size() , m = t.size();
    int minLen = INT_MAX , sIndex = -1;
    for(int i=0;i<n;i++){
        int hash[256] = {0},cnt =0;
        for(int j=0;j<m;j++)
            hash[t[j]]++;
        for(int j=i;j<n;j++){
            if(hash[s[j]] >0)
                cnt++;
            hash[s[j]]--;
            if(cnt == m){
                if(j-i+1 < minLen){
                    minLen = j-i+1;
                    sIndex = i;
                }
                break;
            }
        }
    }
    if(sIndex == -1)
        return "";
    return s.substr(sIndex,minLen);
}

// Optimal 

//  TIME COMPLEXITY O(2n+m)
//  SPACE COMPLEXITY O(256)

/*
APPROACH -
1. Create a function, lenMinWindowSubstringOptimal, that takes strings 's' and 't' as parameters.
   - Let 'n' be the length of string 's' and 'm' be the length of string 't'.
2. Initialize a fixed-size array 'hash[256]' to store the frequency of characters in string 't'.
   - Initialize all values of the array to 0.
   - Iterate over string 't' and increment the frequency of each character in 'hash'.
3. Initialize the sliding window variables:
   - 'l' (left pointer) = 0
   - 'r' (right pointer) = 0
   - 'cnt' = 0 (counts how many characters of 't' are matched in the current window)
   - 'minLen' = INT_MAX (to store the minimum window length)
   - 'sIndex' = -1 (starting index of the minimum window substring)
4. Expand the window by moving the right pointer 'r':
   - While 'r' is less than 'n':
     - If 'hash[s[r]]' is greater than 0, increment 'cnt'
       (this means the current character is required).
     - Decrement 'hash[s[r]]' to mark the character as used.
5. Check if the current window is valid:
   - When 'cnt' becomes equal to 'm', it means the window contains all characters of 't'.
6. Shrink the window from the left to find the minimum window:
   - While 'cnt' equals 'm':
     - If the current window size (r - l + 1) is smaller than 'minLen',
       update 'minLen' and set 'sIndex' to 'l'.
     - Increment 'hash[s[l]]' to release the leftmost character from the window.
     - If 'hash[s[l]]' becomes greater than 0, decrement 'cnt'
       (a required character is now missing).
     - Move the left pointer 'l' one step to the right.
7. Continue expanding the window by incrementing 'r'.
8. After the loop:
   - If 'sIndex' is still -1, return an empty string (no valid window found).
   - Otherwise, return the substring of 's' starting at 'sIndex' with length 'minLen'
     using the substr function.

*/

string lenMinWindowSubstringOptimal(string &s,string &t){
    int n = s.size() , m = t.size();
    int hash[256] = {0},cnt =0 , l =0, r=0; //cnt = mp.size()
    int minLen = INT_MAX , sIndex = -1;
    // unordered_map<char, int> mp;
    for(int i=0;i<m;i++)
            hash[t[i]]++;
    while(r<n){       //cnt  = mp.size()
        if(hash[s[r]] >0)  //if (mp[s[i]] == 0)
            cnt++;             //cnt--
        hash[s[r]]--; //
        while(cnt == m){    //while (count == 0)
            if(r-l+1 < minLen){
                minLen = r-l+1;
                sIndex = l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0)
                cnt--;  //cnt++
            l++;
        }
        r++;
    }
    if(sIndex == -1)
        return "";
    return s.substr(sIndex,minLen);
}

// Works for all---O(m+n) , O(n)
string lenMinWindowSubstring(string &s,string &t){
    int n = s.size() , m = t.size();
    int l =0;
    int minLen = INT_MAX , sIndex = -1;
    unordered_map<char, int> mp;
    for(int i=0;i<m;i++)
            mp[t[i]]++;
    int cnt = mp.size();
    for(int r=0;r<n;r++){       
        mp[s[r]]--; 
        if (mp[s[r]] == 0)
            cnt--;
        while(cnt == 0){     
            if(r-l+1 < minLen){
                minLen = r-l+1;
                sIndex = l;
            }
            mp[s[l]]++;
            if(mp[s[l]]>0)
                cnt++;
            l++;
        }
    }
    if(sIndex == -1)
        return "";
    return s.substr(sIndex,minLen);
}

int main(){
    string s,t;
    cin >> s;
    cin >> t;
    cout << lenMinWindowSubstringBrute(s,t) << "\n";
    cout << lenMinWindowSubstringOptimal(s,t) << "\n";
    cout << lenMinWindowSubstring(s,t) << "\n";
    return 0;
}

// INPUT
// ddaaabbca
// abc