// LONGEST PALINDROMIC SUBSTRING

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n*n)
// SPACE COMPLEXITY : O(1)  

/*
Approach:
1. We define a helper function `expandFromCenter` that takes a string `s`, and two indices `start` and `end` as input.
2. The function expands from the center and checks if the substring from `start` to `end` is a palindrome.
3. If the length of the current palindrome is greater than the maximum length seen so far (`maxLen`), we update the maximum length and the corresponding start and end indices (`ans_start` and `ans_end`).
4. We iterate over each character of the string `s` and consider it as a potential center for the palindrome.
5. We call `expandFromCenter` twice for each character - once for considering odd-length palindromes and once for even-length palindromes.
6. Finally, we return the substring of `s` that corresponds to the longest palindromic substring.
*/

void expandFromCenter(string &s,int i,int j,int &l,int &r,int &maxLen){
    while(i>=0 && j<s.size() && s[i]==s[j]){
        if(j-i+1 > maxLen){
            l=i;
            r=j;
            maxLen = j-i+1;
        }
        i--;
        j++;
    }
}

string longestPalindrome(string &s){
    string ans="";
    int maxLen = 0,l = -1,r=-1;
    for(int i=0;i<s.size();i++){
        expandFromCenter(s,i,i,l,r,maxLen);
        expandFromCenter(s,i-1,i,l,r,maxLen);
    }
    return (maxLen == 0)? "" :s.substr(l,r-l+1);
}
 
int main(){
    string s;
    cin >> s  ;
    cout << longestPalindrome(s)<< "\n";
    return 0;
}

// INPUT 
// yuiopyypoirgd