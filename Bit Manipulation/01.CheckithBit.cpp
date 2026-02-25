/*
// check ith bit
(n >> i) & 1

// set ith bit
n | (1 << i)

// clear ith bit
n & ~(1 << i)

// toggle ith bit
n ^ (1 << i)

// last bit (odd/even)
n & 1
*/

// CHECK Ith BIT

#include<bits/stdc++.h>
using namespace std;

/*
Approach:
1. Perform a bitwise AND operation between N and (1 << K).
2. If the result is non-zero, it means the Kth index bit is set (1); otherwise, it is not set (0).
*/

bool checkithBit(int n,int k){
    if(n & (1<<k))
        return true;
    return false;
}

int main(){
    int n , i;
    cin >> n >> i;
    cout << checkithBit(n,i-1); // 1 based index
    return 0;
}

// INPUT
// 70 3