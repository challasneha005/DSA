// FIND NUMBER APPEARS ONCE,OTHERS TWICE

#include<bits/stdc++.h>
using namespace std;

//brute O(n*n)
int findSingleBrute(int a[],int n){
    for(int i=0;i<n;i++){
        int num = a[i];
        int cnt =0;
        for(int j=0;j<n;j++){
            if(a[j]==num) 
                cnt++;
        }
        if(cnt==1) return num;
    }
    return -1;
}

//better O(3n) last O(max m) m-element
int findSingleBetterHash(int a[],int n){
    int maxi = a[0];
    for(int i=1;i<n;i++)
        maxi = max(maxi,a[i]);
    int hash[maxi+1]={0};
    for(int i=0;i<n;i++)
        hash[a[i]]++;
    for(int i=0;i<n;i++){
        if(hash[a[i]]==1) 
            return a[i];
    }
    return -1;
}

//better map  ordered - O(n log m+ n/2 +1)  unordered O(n+ n/2 +1)
int findSingleBetterMap(int a[],int n){
    map<int,int> m;
    for(int i=0;i<n;i++)
        m[a[i]]++;
    for(auto it : m){
        if(it.second==1) 
            return it.first;
    }
    return -1;
}

//Optimal XOR O(n)

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)

/*
APPROACH:-
-> We can use XOR operation as we know xor cancles out the same elements
-> Intial xr=0 then traverse the entire array and xor each element with xr
-> Since only one element is present once and all other are present twice so the remaining element would be the
    one which is present only once cause all other gets cancels out
*/

int findSingleOptimal(int a[],int n){
    int Xor = 0;
    for(int i=0;i<n;i++)
        Xor = Xor^a[i];
    return Xor;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    // int num = findSingleBrute(a,n); 
    // int num = findSingleBetterHash(a,n);  
    // int num = findSingleBetterMap(a,n); 
    int num = findSingleOptimal(a,n);   //give one single
    cout << num << " ";
    return 0;
}

// INPUT
// 5
// 1 4 2 2 1