// LARGEST ODD NUMBER IN STRING

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

/*
Approach:
1. Iterate through the string from the last character.
2. Check if the current character is odd.
3. If it is odd, return the substring from the beginning of the string to the current character index.
4. If no odd number is found, return an empty string. 
*/

string largestOddNum(string &s){
    for(int i=s.size()-1;i>=0;i--){
        // Converts character digit → actual integer.
        if((s[i]-'0') % 2 != 0)
            return s.substr(0,i+1);
    } 
    return "";
}

int main(){
    string s;
    cin >> s;
    cout << largestOddNum(s);
    return 0;
}

// INPUT 
// 56133862