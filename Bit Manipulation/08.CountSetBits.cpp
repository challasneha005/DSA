// COUNT SET NUMBERS FROM 1 to N

#include<bits/stdc++.h>
using namespace std;

/*
APPROACH:
The approach to solve this problem is based on the observation that the count of set bits in the binary representation of a number `n` 
can be determined by the following formula:
countSetBits(n) = countSetBits(pow(2, x - 1) * x) + (n - pow(2, x) + 1) + countSetBits(n - pow(2, x)) 
*/

int countSetBits(int n){
    if(n<=1)
        return n;
    int x = log2(n); // Find the greatest power of 2 less than n
    return (pow(2,x-1)*x) + (n-pow(2,x)+1) + countSetBits(n-pow(2,x));
}

int main(){
    int n ;
    cin >> n ;
    cout << countSetBits(n) << "\n"; 
    return 0;
}

// INPUT 
// 20 