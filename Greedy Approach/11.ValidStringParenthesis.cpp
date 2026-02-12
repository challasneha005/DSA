// VALID PARENTHESIS STRING

#include<bits/stdc++.h>
using namespace std;

// brute O(3^n) , O(n)
bool isValidStringBrute(string &s,int ind,int cnt,int n){
    if(cnt <0)
        return false;
    if(ind == n)
        return cnt==0;
    if(s[ind] == '(' )
        return isValidStringBrute(s,ind+1,cnt+1,n);
    if(s[ind] == ')' )
        return isValidStringBrute(s,ind+1,cnt-1,n);
     // '*' case
    return isValidStringBrute(s,ind+1,cnt+1,n) or  isValidStringBrute(s,ind+1,cnt-1,n) or isValidStringBrute(s,ind+1,cnt,n);   
}

// Optimal O(n) , O(1)

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

/*
APPROACH:
1. Use a greedy strategy by maintaining two variables:
   - min: minimum number of open parentheses possible so far.
   - max: maximum number of open parentheses possible so far.
2. Traverse the string character by character.
3. If the character is '(':
   - Increment both min and max.
4. If the character is ')':
   - Decrement min and increment max.
5. If the character is '*':
   - Decrement min (treat '*' as ')').
   - Increment max (treat '*' as '(').
6. If min becomes negative, reset it to 0 since open parentheses
   cannot be less than zero.
7. If max becomes negative at any point, return false because
   the string cannot be balanced.
8. After processing the entire string, return true if min is 0;
   otherwise, return false.
*/


bool isValidString(string &s) {
    int min = 0, max = 0;
    for (int i=0;i<s.size();i++) {
        if (s[i] == '(') {
            max++;
            min++;
        } else if (s[i] == ')') {
            min--;
            max--;
        } else { // this is the case of '*'
            min--; // if we treat '*' as '('
            max++; // if we treat '*' as ')'
        }
        if (min < 0) // this means even after treating all '*' as '(' we can't maintain balance
            min = 0;
        if(max<0)
            return false;
    }
    return (min == 0);
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    cout << isValidStringBrute(s,0,0,n) << "\n";
    cout << isValidString(s) << "\n";
    return 0;
}

// INPUT
// (**(