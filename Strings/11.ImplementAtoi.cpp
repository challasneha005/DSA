// MYATOI(STRING S) FUNCTION, WHICH CONVERTS A STRING TO A 32-BIT SIGNED INTEGER
 
// aba , 2
// "ab", "ba" and "aba"

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)  

/*
Approach:
1. Initialize an index `i` to track the current position in the string.
2. Skip any leading whitespace by incrementing `i` until a non-whitespace character is encountered.
3. Check if the next character (if not at the end of the string) is `'-'` or `'+'`. Set a `sign` flag accordingly to determine the final result's sign.
4. Read the consecutive digits until a non-digit character is encountered or the end of the input is reached. Convert these digits into an integer.
5. Apply the sign to the integer obtained from the digits.
6. If the integer is out of the 32-bit signed integer range, clamp it to the range [-231, 231 - 1].
7. Return the final integer.
*/

int myAtoi(string &s){
    int i=0;

    // 1. Skip spaces
    while(i<s.size() && s[i]==' ')
        i++;
    if(i==s.size())
        return 0;

    // 2. Sign
    bool sign = true;
    if(s[i] =='-'){
        i++;
        sign = false;
    }
    else if(s[i]=='+')
        i++;
    
    // 3. Convert digits
    long long ans = 0;
    // while(i < s.size() && isdigit(s[i]))
    while(i<s.size() && (0<= s[i] - '0' && s[i]-'0' <= 9)){
        long long digit = s[i]-'0';
        ans = (ans*10) + digit;
        if(ans > INT_MAX && sign)
            return INT_MAX;
        else if(ans > INT_MAX)
            return INT_MIN;
        i++;
    }
    ans = sign ? ans : -1*ans;
    return (int)  ans;
}
 
int main(){
    string s;
    getline(cin, s) ;
    cout << myAtoi(s)<< "\n";
    return 0;
}

// INPUT 
// 42