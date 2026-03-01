// CHECK ISOMORPHIC STRING
// Characters in string s can be replaced to get string t.

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(m) - unique characters

/*
Approach:
1. Initialize two maps to store the mapping of characters from s to t and from t to s.
2. Iterate through each character in s and t simultaneously.
3. If the current characters in s and t are already mapped differently, return false.
4. If the current characters in s and t are not mapped yet, add them to the maps.
5. If the current characters in s and t are already mapped to each other, continue to the next characters.
6. If all characters have been iterated and no inconsistencies are found, return true.
*/

bool isIsomorphicString(string &s,string &t){
    unordered_map<char,int> mps,mpt;
    if(s.size()!= t.size())
        return false;
    for(int i=0;i<s.size();i++){
        if(mps.find(s[i]) == mps.end() && mpt.find(t[i]) == mpt.end()){
            mps[s[i]] = t[i];
            mpt[t[i]] = s[i];
        }
        else if(mps[s[i]] != t[i] || mpt[t[i]] != s[i] )
            return false;
    }
    return true;
}

int main(){
    string s,t;
    cin >> s >> t;
    cout << isIsomorphicString(s,t);
    return 0;
}

// INPUT 
// add
// egg