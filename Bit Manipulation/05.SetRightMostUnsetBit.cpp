 // SET RIGHT MOST UNSET BIT - MAKE IT SET BIT

#include<bits/stdc++.h>
using namespace std;

/*
APPROACH:
To set the rightmost unset bit in the binary representation of N, we can follow these steps:
1. Check if N+1 is a power of 2. If it is, then N already has all bits set, so return N.
2. Otherwise, perform the bitwise OR operation between N and (N+1). This will set the rightmost unset bit.
3. Return the result.

1. Check if N+1 is a power of 2 by using the isPowerOfTwo function.
2. If it is, return N as it already has all bits set.
3. Otherwise, perform the bitwise OR operation between N and (N+1) and return the result.
*/

bool isPowerOfTwo(int n) {
    if(n <= 0)
        return false;
    if(n & (n-1))
        return false;
    return true;
}

int setBit(int N){
    if(isPowerOfTwo(N+1))
        return N;

    int ans = (N | (N+1));
    return ans;
}

 
/*Approach
1. First, check whether (N + 1) is a power of 2.
   -If (N + 1) is a power of 2, then the binary representation of N consists entirely of set bits (1s).
   -In this case, there is no unset bit to modify, so return N unchanged.
2. If (N + 1) is not a power of 2, then N contains at least one unset bit.
3. Perform a bitwise OR operation between N and (N + 1):
    N | (N + 1)
   -This operation sets the rightmost unset bit while keeping all other bits unchanged.
4. Return the resulting value.
*/

int setBitAns(int n){
    // if all bits are already set
    if ((n & (n+1)) == 0)
        return n;
    return n|n+1;
} 

int main(){
    int n ;
    cin >> n ;
    cout << setBit(n) << "\n";
    cout << setBitAns(n);  
    return 0;
}

// INPUT 
// 47