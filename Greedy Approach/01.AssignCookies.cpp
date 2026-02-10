// ASSIGN COOKIES ...SATISFY MORE CHILDREN O(n log n+m log m+M) , O(1)

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n log n)
// SPACE COMPLEXITY : O(1)

/*
APPROACH:
1. Sort the greed factor array greed and the cookie size array available in ascending order.
2. Initialize two pointers: r to track the current child and l to track the current cookie.
3. Traverse through the cookie array while both pointers are within bounds.
4 .If the current cookie size is greater than or equal to the greed factor of the current child, assign the cookie and move to the next child by incrementing r.
5. Move to the next cookie by incrementing l in all cases.
6. After traversal, return r, which represents the total number of content children.
*/

int assignCookies(vector<int> &greed,vector<int> &available){
    int n = greed.size();
    int m = available.size();
    sort(greed.begin(),greed.end());
    sort(available.begin(),available.end());
    int l=0, r = 0;
    while(l<m && r<n){
        if(greed[r]<=available[l])
            r = r+1;
        l = l+1;
    }
    return r;
}

int main(){
    vector<int> greed = {1,5,3,3,4};
    vector<int> available = {4,2,1,2,1,3};
    cout << assignCookies(greed,available);
    return 0;
}
