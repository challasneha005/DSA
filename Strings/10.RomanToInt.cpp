// ROMAN TO INTEGER

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)  

/*
Approach:
1. Create a map to store the values of each Roman symbol.
2. Initialize `result` as the value of the first symbol in the input string.
3. Iterate through each character `c` in the input string `s`, starting from the second character.
    a. If the value of the current symbol is greater than the value of the previous symbol, subtract twice the value of the previous symbol from `result` and add the value of the current symbol.
    b. Otherwise, add the value of the current symbol to `result`.
4. Return `result` as the converted integer.
*/

int romanToInt(string &s){
    unordered_map<char,int> values={
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    int ans = values[s[0]];
    for(int i=1;i<s.size();i++){
        if(values[s[i]] > values[s[i-1]]){
            ans -= 2*values[s[i-1]];
            ans += values[s[i]];
        }
        else
            ans += values[s[i]];
    }
    return ans;
}
 
int main(){
    string s;
    cin >> s  ;
    cout << romanToInt(s)<< "\n";
    return 0;
}

// INPUT 
// III