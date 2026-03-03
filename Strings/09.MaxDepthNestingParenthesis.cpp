// MAX NESTING DEPTH OF PARENTHEIS

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)  

/*
Approach:
1. Initialize `opened` as 0 and `ans` as 0 to keep track of the number of opened parentheses and the maximum nesting depth respectively.
2. Iterate through each character `c` in the string `s`.
    a. If `c` is an opening parenthesis '(', increment `opened` by 1 and update `ans` if it is greater than the current value of `ans`.
    b. If `c` is a closing parenthesis ')', decrement `opened` by 1.
3. Return `ans` as the maximum nesting depth. 
*/

int maxDepth(string &s){
    int open = 0,ans = 0; 
    for(auto c:s){
        if(c=='('){
            open++;
            ans = max(ans,open);
        }
        else if(c==')')
            open--;
    }
    return ans;
}
 
int main(){
    string s;
    cin >> s  ;
    cout << maxDepth(s)<< "\n";
    return 0;
}

// INPUT 
// ((()))