// CHECK ROTATED STRING

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n*n)
// SPACE COMPLEXITY : O(n)

/*
Approach:
- First, we check if the lengths of the two strings `s` and `goal` are equal. If not, they cannot be rotated versions of each other, so we return `false`.
- Then, we concatenate `s` with itself to create a new string `concat`.
- We check if `goal` is a substring of `concat`. If it is, that means `s` can be transformed into `goal` by performing some number of left shifts, 
so we return `true`. Otherwise, we return `false`.
*/

bool isRotatedString(string &s,string &t){
    if(s.size() != t.size())
        return false;
    // string::npos is a special constant in C++ that means:"Not Found"
    if((s+s).find(t) == string::npos)
        return false;
    return true;
}

int main(){
    string s,t;
    cin >> s >> t;
    cout << isRotatedString(s,t);
    return 0;
}

// INPUT 
// ukpower
// poweruk