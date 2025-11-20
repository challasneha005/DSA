//CLIMBING STAIRS NO.OF WAYS TO REACH N
#include<bits/stdc++.h>
using namespace std;
int ways(int ind){
    if (ind == 0 || ind == 1)
        return 1;
    int left = ways(ind-1);
    int right = ways(ind-2);
    return left+right;
}
int main(){
    int n;
    cin >> n;
    cout << "No.of ways to reach "<< n <<" is :";
    cout << ways(n);
}