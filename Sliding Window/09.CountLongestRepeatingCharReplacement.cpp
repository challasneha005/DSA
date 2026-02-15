// LONGEST REPEATING CHARACTER REPLACEMENT

#include<bits/stdc++.h>
using namespace std;

// “In pseudocode, we can index directly by character, but in C++ arrays we convert characters to indices using s[j] - 'A'.”

// brute O(n*n) , O(26)
int maxLenLongestRepeatingkBrute(string &s,int k){
    int n = s.size();
    int maxLen = 0,changes = 0;
    for(int i=0;i<n;i++){
        int hash[26] = {0};
        int maxf = 0;
        for(int j=i;j<n;j++){
            hash[s[j]-'A']++;
            maxf = max(maxf,hash[s[j]-'A']);
            changes = (j-i+1) - maxf;
            if(changes <=k)
                maxLen = max(maxLen,j-i+1);
            else
                break;
        }
    }
    return maxLen;
}

// Better O(n+n+26) , O(26)
int maxLenLongestRepeatingkBetter(string &s,int k){
    int n = s.size();
    int maxLen = 0,l =0 , r = 0, maxf =0;
    int hash[26] = {0};
    while(r<n){
        hash[s[r]-'A']++;
        maxf = max(maxf,hash[s[r]-'A']);
        while((r-l+1)- maxf  > k){
            hash[s[l] - 'A']--;
            maxf = 0;
            for(int i=0;i<26;i++)
                maxf = max(maxf,hash[i]);
            l++;
        }
        if((r-l+1) - maxf <=k )
            maxLen = max(maxLen,r-l+1);
        r++;
    }
    return maxLen;
}

// Optimal

//  TIME COMPLEXITY O(n)
//  SPACE COMPLEXITY O(26)

/*
APPROACH  
1. Create a frequency array hash of size 26 to store the count of characters in the current window.
2. Initialize two pointers l (left) and r (right) to represent the sliding window, along with variables maxf (maximum frequency of any character in the window) and maxLen (maximum length of a valid substring).
3. Traverse the string using the right pointer r
    -Increment the frequency of the current character in hash.
    -Update maxf as the maximum of its current value and the frequency of the current character.
4. Check if the number of characters to be replaced, i.e.
(current window length − maxf), exceeds k:
    -If yes, shrink the window from the left by decrementing the frequency of s[l] and moving l forward by one.
5. If the number of replacements required is at most k, update maxLen with the current window length.
6. Continue this process until the entire string is processed.
7. Return maxLen as the length of the longest repeating character substring after at most k replacements.
*/

int maxLenLongestRepeatingkOptimal(string &s,int k){
    int n = s.size();
    int maxLen = 0,l =0 , r = 0, maxf =0;
    int hash[26] = {0};
    while(r<n){
        hash[s[r]-'A']++;
        maxf = max(maxf,hash[s[r]-'A']);
        if((r-l+1)- maxf  > k){
            hash[s[l] - 'A']--;
            l++;
        }
        if((r-l+1) - maxf <=k )
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
    cout << maxLenLongestRepeatingkBrute(s,k) << "\n";
    cout << maxLenLongestRepeatingkBetter(s,k)<< "\n";
    cout << maxLenLongestRepeatingkOptimal(s,k)<< "\n";
    return 0;
}

// INPUT
// AABABBA
// 2