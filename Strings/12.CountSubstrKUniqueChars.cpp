// COUNT SUBSTRINGS THAT HAVE K UNIQUE/DISTINCT CHARACTERS
// all possible substrings (not necessarily distinct) 

// aba , 2
// "ab", "ba" and "aba"

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(k)  

/*
Approach:
1. We can solve this problem using the sliding window technique.
2. Initialize a variable ans to keep track of the count of substrings with exactly k distinct characters.
3. Create an unordered_map mp to store the count of characters in the current window.
4. Initialize two pointers i and j to mark the start and end of the window, both initially pointing to the start of the string.
5. Iterate j from the start to the end of the string:
   - Increment the count of the current character s[j] in mp.
   - If the number of distinct characters in mp exceeds k, move the start pointer i towards the right until the number of distinct characters becomes k again.
   - Update the ans by adding the length of the current window (j - i + 1) to it.
6. Return the value of ans.
*/

long long int substrAtmostK(string &s,int k){
    long long int cnt = 0;
    unordered_map<char,int> mp;
    int i=0;
    for(int j=0;j<s.size();j++){
        mp[s[j]]++;
        while(mp.size()>k){
            mp[s[i]]--;
            if(mp[s[i]]==0)
                mp.erase(s[i]);
            i++;
        }
        cnt += j-i+1;
    }
    return cnt;
}

long long int cntSubstringsKUniqueChars(string &s,int k){
    long long int atmostk = substrAtmostK(s,k);
    long long int atmostk_1 = substrAtmostK(s,k-1);
    return atmostk - atmostk_1;
}
 
int main(){
    string s;
    cin >> s ;
    int k;
    cin >> k;
    cout << cntSubstringsKUniqueChars(s,k)<< "\n";
    return 0;
}

// INPUT 
// abaaaca 1