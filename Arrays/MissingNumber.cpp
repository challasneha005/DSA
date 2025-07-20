//MISSING NUMBER in can be sort or unsort
#include<bits/stdc++.h>
using namespace std;
//brute O(n*n)
int missingBrute(int a[],int n){
    int flag;
    for(int i=1;i<=n;i++){
        flag=0;
        for(int j=0;j<n;j++){
            if(a[j]==i){
                flag=1;
                break;
            }
        }
        if (flag==0)
            return i;
    }
    return -1;
}
//better using hash O(2n)
int missingBetter(int a[],int n){
    int hash[n+1]={0};
    for(int i=0;i<n;i++)
        hash[a[i]]=1;
    for(int i=1;i<=n;i++){
        if(hash[i]==0)
            return i;
    }   
    return -1;
}
//optimal using sum O(n) but if 10**5 so long so use xor
int missingOptimalSum(int a[],int n){
    int total = (n * (n + 1)) / 2;
    int sum=0;
    for(int i=0;i<n-1;i++) //as 1 missing
        sum+=a[i];
    return total - sum;
}
int missingOptimalXor(int a[],int n){
    int xor1=0, xor2=0;
    for(int i=0;i<n-1;i++){ //as 1 missing
        xor2  = xor2 ^ a[i];
        xor1 = xor1 ^ (i+1);
    } 
    xor1 = xor1 ^n; //actual n
    return xor1^xor2;
}
int main(){
    int n;
    cin >> n;
    int a[n-1]; //as missing number
    for(int i=0;i<n;i++)
        cin >> a[i];
    // int miss=missingBrute(a,n);
    // int miss=missingBetter(a,n);
    // int miss=missingOptimalSum(a,n);
    int miss=missingOptimalXor(a,n);
    cout << miss;
    return 0;
}
