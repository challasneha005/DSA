// LONGEST COMMON PREFIX

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n*m*log n)
// SPACE COMPLEXITY : O(1)  

/*
Approach:
1. Sort the array of strings lexicographically.
2. Take the first and last string from the sorted array.
3. Compare each character of the first and last string until they don't match or the end of either string is reached.
4. Return the common prefix.
*/

string longestCommonPrefixStrings(string &s,string &t){
    int len = min(s.size(),t.size());
    int i=0;
    while(i< len && s[i] == t[i])
        i++;
    return s.substr(0,i);
}
string longestCommonPrefixVectors(vector<string> &strs){
    if(strs.empty())
        return "";
    sort(strs.begin(),strs.end());
    int l = 0,r=strs.size()-1;
    int i=0,j=0,len=0;
    while(i<strs[l].size() && j<strs[r].size() && strs[l][len] == strs[r][len]){
        i++;j++;
        len++;
    }
    return strs[l].substr(0,len);
}
int main(){
    string s,t;
    cin >> s >> t;
    cout << "String :" << longestCommonPrefixStrings(s,t)<< "\n";

    int n;
    cin >> n;
    vector<string> strs(n);
    for(int i=0;i<n;i++)
        cin >> strs[i];
    cout <<  "String :" << longestCommonPrefixVectors(strs)<< "\n";
    return 0;
}

// INPUT 
// apple
// applecake
// 3
// flow
// flower
// fire