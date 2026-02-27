 // EXCEPTIONALLY ODD

#include<bits/stdc++.h>
using namespace std;

/*
APPROACH:
To find the exceptional number, we can use the bitwise XOR operation. 
XORing a number with itself results in 0, so XORing all the numbers 
in the array will cancel out the even occurrences, leaving only the exceptional number in the result.
*/

int oddOccur(vector<int> &a){
    int xr = 0;
    for(int i=0;i<a.size();i++)
        xr = xr ^ a[i];
    return xr;
}

int main(){
    int n ;
    cin  >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << oddOccur(a) << "\n"; 
    return 0;
}

// INPUT 
// 7
// 1 2 3 1 2 3 9