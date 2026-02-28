// REMOVE OUTER PARENTHESIS

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(n)

/*
Approach:
- We can iterate through the characters of the string and keep track of the number of open parentheses encountered.
- Whenever we encounter an opening parenthesis, if the count of open parentheses is greater than 0, we append it to the result string.
- When we encounter a closing parenthesis, we decrement the count of open parentheses and append it to the result string only if the count is greater than 1.
*/

string removeOuterParenthesis(string &s){
    string ans;
    int open = 0;
    for(auto i : s){
        if(i == '('){
            if(open > 0)
                ans+=i;
            open++;
        }
        else{
            if(open > 1)
                ans += i;
            open--;
        }
    }
    return ans; 
}

int main(){
    string s;
    cin >> s;
    cout << removeOuterParenthesis(s);
    return 0;
}

// INPUT 
// (()())(())(()(()))