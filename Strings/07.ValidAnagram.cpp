// VALID ANAGRAM
// same characteres different word

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(max(m,n))
// SPACE COMPLEXITY : O(n)

/*
Approach:
1. Create an unordered map to store the count of each character in string `s`.
2. Iterate over each character in `s` and increment its count in the map.
3. Iterate over each character in `t`.
   - If the character is not present in the map or its count is zero, return false.
   - Decrement the count of the character in the map.
   - If the count becomes zero, remove the character from the map.
4. After iterating through all characters in `t`, if the map is empty, return true; otherwise, return false.
*/

bool isValidAnagram(string &s,string &t){
    if(s.size() != t.size())
        return false;
    unordered_map<char,int> mp;
    for(auto c : s)
        mp[c]++;
    for(auto c : t){
        if(mp.find(c) == mp.end())
            return false;
        mp[c]--;
        if(mp[c] == 0)
            mp.erase(c);
    }
    return (mp.size()==0);
}

int main(){
    string s,t;
    cin >> s >> t;
    cout << isValidAnagram(s,t);
    return 0;
}

// INPUT 
// ukopwer
// powerku