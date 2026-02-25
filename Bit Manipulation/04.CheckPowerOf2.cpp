 // CHECK POWER OF 2

#include<bits/stdc++.h>
using namespace std;

/*
APPROACH:
An integer n is a power of two if it has only one bit set (i.e., it is a power of 2).
To check if a number has only one bit set, we can use the bitwise AND operation with (n-1).
If the result is 0, then it is a power of two; otherwise, it is not.

1. If n is less than or equal to 0, return false.
2. Perform the bitwise AND operation between n and (n-1).
3. If the result is 0, return true; otherwise, return false.
*/
 
string power2(int n){
    if(n& n-1)
        return "false";
    if(n<=0)
        return "false";
    return "true";
}

int main(){
    int n ;
    cin >> n ;
    cout << power2(n);  
    return 0;
}

// INPUT 
// 8