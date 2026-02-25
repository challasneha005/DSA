// SUBTRACT I-th  BIT AND RETURN THE ANSWER

#include<bits/stdc++.h>
using namespace std;

/*
Approach:
1. Subtract 1 from i to adjust the index to 0-based.
2. To get the ith bit, perform a bitwise AND operation between num and (1 << i). If the result is non-zero, the ith bit is set; otherwise, it is cleared.
3. To set the ith bit, perform a bitwise OR operation between num and (1 << i).
4. To clear the ith bit, perform a bitwise AND operation between num and the complement of (1 << i).
*/

void ans(int n,int i){
    int num,setnum;
    i = i-1; //1 based
    if(n & (1 << i))
        cout << 1 << "\n";
    else    
        cout << 0 << "\n";
    
    setnum = n | (1<<i);
    cout << setnum << " ";

    num = n &(~(1<<i));
    cout << num;
}

int main(){
    int n , i;
    cin >> n >> i;
    ans(n,i);
    return 0;
}

// INPUT
// 70 3