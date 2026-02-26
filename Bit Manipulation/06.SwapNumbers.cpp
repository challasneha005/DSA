// SWAP TWO NUMBERS WITHOUT VARIABLE

#include<bits/stdc++.h>
using namespace std;

/*
APPROACH:
To swap two numbers a and b without using a temporary variable, we can use the XOR (^) operation.
1. Set a = a XOR b, which XORs the binary representations of a and b and stores the result in a.
2. Set b = a XOR b, which XORs the new value of a (after step 1) with the original value of b, and stores the result in b.
3. Set a = a XOR b, which XORs the new value of a (after step 1) with the new value of b (after step 2), and stores the result in a.
4. The values of a and b are swapped.
*/
pair<int,int> swapNums(int a,int b){
    a = a^b;
    b = a^b;
    a = a^b;
    return {a,b};
}

int main(){
    int a,b ;
    cin >> a >> b ;
    pair<int,int> ans = swapNums(a,b) ;
    cout << ans.first << " " << ans.second << "\n"; 
    return 0;
}

// INPUT 
// 47 53