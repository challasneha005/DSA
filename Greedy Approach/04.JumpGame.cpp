// JUMP GAME - Able to reach end  O(n) , O(1)

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)

/*
APPROACH:
- We maintain a variable 'farthest(maxInd)' to keep track of the farthest(maxInd) position we can reach.
- We iterate over the array from left to right.
- At each position, we check if the current position is reachable from the previous farthest(maxInd) position.
- If the current position is beyond the farthest(maxInd) position, it means we cannot reach the end, so we return false.
- Otherwise, we update the farthest(maxInd) position by taking the maximum of the current farthest(maxInd) and the current position plus the maximum jump length at that position.
- Finally, if we reach the end of the array or beyond it, we return true.
*/

bool reachEnd(vector<int> &a){
    int maxInd = 0;
    for(int i=0;i<a.size();i++){
        if(i>maxInd)
            return false;
        maxInd = max(maxInd,i+a[i]);
    }
    return true;
}

int main(){
    vector<int> a = {1,2,4,1,1,0,2,5};
    cout << reachEnd(a);
    return 0;
}
