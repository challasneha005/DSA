 // MIN BITS FLIP FROM A TO B 

#include<bits/stdc++.h>
using namespace std;

/*
APPROACH:
To find the minimum number of bit flips required to convert start to goal, 
we can iterate over each bit position from right to left and compare the corresponding bits in start and goal. 
If they are different, we increment a counter. Finally, we return the counter.
*/

int minBitFlips(int a,int b){
    int i= 0,cnt = 0;
    while(i<32){
        int start = (a >> i) &1;
        int goal = (b >> i) &1;
        if(start != goal)
            cnt++;
        i++;
    }
    return cnt;
}

int main(){
    int a,b ;
    cin >> a >> b ;
    cout << minBitFlips(a,b) << "\n"; 
    return 0;
}

// INPUT 
// 10 7