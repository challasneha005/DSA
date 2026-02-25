// CHECK ODD EVEN

#include<bits/stdc++.h>
using namespace std;

/*
APPROACH:
To determine whether a positive integer N is odd or even, we can check the least significant bit (LSB) of N. 
If the LSB is 1, the number is odd. If the LSB is 0, the number is even.
We can use the bitwise AND operation with 1 (N & 1) to check the LSB.
If the result is 1, we return "odd". If the result is 0, we return "even".
*/
 
string oddEven(int n){
    if(n&1)
        return "odd";
    else
        return "even";
}

int main(){
    int n ;
    cin >> n ;
    cout << oddEven(n);  
    return 0;
}

// INPUT 
// 3