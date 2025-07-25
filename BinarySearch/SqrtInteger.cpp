//SQUARE ROOT OF INTEGER USING BINARY SEARCH
#include<bits/stdc++.h>
using namespace std;
//brute
int sqrtIntegerBrute(int n){
    int ans = 1;
    for(int i=1;i<=n;i++){
        if(i*i <= n)
            ans = i;
        else
            break;
    }
    return ans;
}
int sqrtInteger(int n){
    int low = 1,high = n,ans = 1;
    while(low<=high){
        int mid = (low+high)/2;
        if( mid * mid <=n){
            ans = mid;
            low = mid+1;
        } 
        else 
            high = mid-1;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    // int sqrt = sqrtIntegerBrute(n);
    int sqrt = sqrtInteger(n);
    cout << sqrt;
    return 0;
}
