// MAX CONSECUTIVE ONES III with ATMOST K ZEROES
// LARGEST SUBARRAY WITH MAX ZEROES AS K

#include<bits/stdc++.h>
using namespace std;

// brute O(n*n) , O(1)
int maxConsecutiveOnesBrute(vector<int> &a,int k){
    int n = a.size();
    int zeroes;
    int maxLen = 0,len = 0;
    for(int i=0;i<n;i++){
        zeroes = 0;
        for(int j=i;j<n;j++){
            if(a[j] == 0)
                zeroes++;
            if(zeroes<=k){
                len = j-i+1;
                maxLen = max(maxLen,len);
            }
            else
                break;
        }
    }
    return maxLen;
} 

// better O(2n) , O(1)
int maxConsecutiveOnesBetter(vector<int> &a,int k){
    int n = a.size();
    int maxLen = 0,len = 0, l = 0,r = 0 , zeroes = 0;
    while(r<n){
        if(a[r] == 0)
            zeroes++;
        while(zeroes >k){
            if(a[l] == 0)
                zeroes--;
            l++;
        }
        if(zeroes <=k ){
            len = r-l+1;
            maxLen = max(maxLen,len); 
        }
        r++;
    }
    return maxLen;
}

// Optimal  

// TIME COMPLEXITY - O(n) N is the length of the input array nums. We iterate through the array once.
// SPACE COMPLEXITY - O(1)  as we are using a constant amount of additional space to store variables.

/*
APPROACH:
1. Initialize variables zeroCnt, start (l), and maxLen.
2. Use a sliding window with two pointers l and r.
3. Traverse the array using r:
   -If a[r] is 0, increment zeroCnt.
   -If zeroCnt becomes greater than k, move the left pointer l by one position and decrement zeroCnt if a[l] was 0.
   -If zeroCnt is less than or equal to k, update maxLen with the size of the current window (r - l + 1).
4. Continue until the end of the array and return maxLen
*/

int maxConsecutiveOnesOptimal(vector<int> &a,int k){
    int n = a.size();
    int maxLen = 0,len = 0, l = 0,r = 0 , zeroes = 0;
    while(r<n){
        if(a[r] == 0)
            zeroes++;
        if(zeroes >k){
            if(a[l] == 0)
                zeroes--;
            l++;
        }
        if(zeroes <=k ){
            len = r-l+1;
            maxLen = max(maxLen,len); 
        }
        r++;
    }
    return maxLen;
}

int main(){
    int n,k;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> k;
    cout <<   maxConsecutiveOnesBrute(a,k) <<"\n";
    cout <<   maxConsecutiveOnesBetter(a,k) <<"\n";
    cout <<   maxConsecutiveOnesOptimal(a,k) <<"\n";
    return 0;
}

// INPUT
// 11
// 1 1 1 0 0 0 1 1 1 1 0
// 2