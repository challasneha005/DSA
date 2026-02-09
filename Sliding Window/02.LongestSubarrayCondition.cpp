// LONGEST SUBARRAY WHERE SUM<=14

#include<bits/stdc++.h>
using namespace std;

// brute O(n*n),O(1)
int maxLenSubarrayBrute(vector<int> &a,int target){
    int n = a.size();
    int maxLen = INT_MIN;
    for(int i=0;i<n;i++){
        long long sum = 0;
        for(int j=i;j<n;j++){
            sum += a[j];
            if(sum <= target)
                maxLen = max(maxLen,j-i+1);
            else if(sum > target)
                break;
        }
    }
    return maxLen;
}

//better O(2n),O(1)
// optimal if array asked
int maxLenSubarrayBetter(vector<int> &a,int target){
    int l =0,r=0,maxLen = 0;
    int n = a.size();
    long long  sum =0;
    while(r<n){
        sum+= a[r];
        while(sum>target){
            sum -= a[l];
            l++;
        }
        if(sum <= target)
            maxLen = max(maxLen,r-l+1);
        r++;
        
    }
    return maxLen;
}

//Optimal  only length

//  TIME COMPLEXITY O(n*n)
//  SPACE COMPLEXITY O(1)

/*
APPROACH
We use two pointers (l and r) to represent a sliding window and maintain the sum of elements inside the window.
The right pointer expands the window by adding new elements, while the left pointer shrinks the window whenever the sum exceeds the target value.
At every step where the window sum is less than or equal to the target, we update the maximum window length.
This approach works efficiently in O(n) time for arrays containing non-negative elements
*/

int maxLenSubarrayOptimal(vector<int> &a,int target){
    int l =0,r=0,maxLen = 0;
    int n = a.size();
    long long  sum =0;
    while(r<n){
        sum+= a[r];
        if(sum>target){
            sum -= a[l];
            l++;
        }
        if(sum <= target)
            maxLen = max(maxLen,r-l+1);
        r++;
        
    }
    return maxLen;
}

int main(){
    int n,sum;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> sum;
    cout <<  maxLenSubarrayBrute(a,sum) <<"\n";
    cout <<  maxLenSubarrayBetter(a,sum) <<"\n";
    cout <<  maxLenSubarrayBetter(a,sum) <<"\n";
    return 0;
}

// INPUT
// 5
// 2 5 1 7 10
// 14