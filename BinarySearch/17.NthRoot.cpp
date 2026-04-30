//Nth ROOT
#include<bits/stdc++.h>
using namespace std;
int fun(int mid,int n){
    long long ans = 1;
    while(n>0){
        if(n%2 == 1){
            ans = ans * mid;
            n= n-1;
        }
        else{
            mid = mid*mid;
            n= n/2;
        }
    }
    //mid ^ n;
    return ans;
}
int nthrootBrute(int n,int m){
    for(int i=1;i<=m;i++){
        if(fun(i,n) == m)
            return i;
        else if(fun(i,n) > m)
            break;
    }
    return -1;
}
int nthroot(int n,int m){
    int low = 1,high = m;
    while(low<=high){
        int mid = (low+high)/2;
        int midN = fun(mid,n);
        if(midN == m)
            return mid;
        else if( midN < m)
            low=mid+1;
        else
            high = mid-1;
    }
    return -1;
}
//above one overflow
//return 1 if ==m
//return 0 if <m
//return 2 if >m
int checkPower(int mid,int n,int m){
    long long ans = 1;
    for(int i=1;i<=n;i++){
        ans= ans*mid;
        if(ans > m)
            return 2;
    }
    if(ans == m)
        return 1;
    return 0;
}
int nthrootClean(int n,int m){
    int low = 1,high = m;
    while(low<=high){
        int mid = (low+high)/2;
        int midN = checkPower(mid,n,m);
        if(midN == 1)
            return mid;
        else if( midN == 0)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}
int main(){
    int m,n;
    cin >> n >> m;
    // int root = nthrootBrute(n,m);
    // int root = nthroot(n,m);
    int root = nthrootClean(n,m);
    cout << "Nth root : " << root;
    return 0;
}