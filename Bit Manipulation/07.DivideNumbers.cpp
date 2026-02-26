// DIVIDE TWO NUMBERS UISNG BIT MANIPULATION

#include<bits/stdc++.h>
using namespace std;

/*
APPROACH:
To divide two integers without using multiplication, division, and mod operator, we can use a bitwise shifting approach.
1. Initialize a variable ans as 0 to store the quotient.
2. Check if the dividend and divisor have different signs to determine the sign of the quotient.
3. Take the absolute values of the dividend and divisor to work with positive numbers.
4. Iterate while the absolute value of the dividend is greater than or equal to the absolute value of the divisor:
    a. Initialize a variable q as 1 to represent the current quotient digit.
    b. Iterate while the absolute value of the dividend is greater than the absolute value of the divisor left-shifted by q:
        i. Increment q.
    c. Add (1 << (q - 1)) to the quotient ans.
    d. Subtract the absolute value of the divisor left-shifted by (q - 1) from the absolute value of the dividend.
5. Return the quotient ans, considering the sign based on the step 2.
*/

int divideTwoNums(int dividend, int divisor){
    if(dividend == divisor)
        return 1;
    bool isNeg = ((dividend <0 && divisor >=0)
                || (dividend >= 0 && divisor <0));
    int ans = 0;
    int a = abs(dividend);
    int b = abs(divisor);
    while(a>=b){
        int q = 1;
        while(a> (b << q))
            q++;
        ans += (1 << (q-1));
        a -= (b << (q-1));
    }
    return (isNeg)? -ans : ans;
}

int main(){
    int a,b ;
    cin >> a >> b ;
    cout << divideTwoNums(a,b) << "\n"; 
    return 0;
}

// INPUT 
// 20 3