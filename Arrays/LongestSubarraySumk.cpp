//LONGEST SUBARRAY WITH SUM -K  POSITIVES
#include<bits/stdc++.h>
using namespace std;
//brute O(n*n*n)
void longestSubarrayBrute(int a[],int n,int target){
    int len=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++)
                sum+=a[k];
            if(sum == target)
                len = max(len,j-i+1);
        }
    }
    cout << len;
}
//optimised brute O(n*n) as can add element without k loop
void longestSubarrayOptimisedBrute(int a[],int n,int target){
    int len=0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum == target)
                len = max(len,j-i+1);
        }
    }
     cout << len;
}
//better using hashmap O(n log n) - ordered ,O(n) unordered -worst O(n*n) rare ,space O(n)-worst
//IT IS OPTIMAL FOR POSITIVES, NEGATIVES, ZEROES     
void longestSubarrayHashmap(int a[],int n,int target){
    unordered_map<long long,int> presumMap;
    int maxLen = 0,sum = 0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum == target)
            maxLen = max(maxLen,i+1);
        long long rem = sum - target;
        if(presumMap.find(rem) != presumMap.end()){
            int len = i-presumMap[rem];
            maxLen = max(maxLen,len);
        }
        if(presumMap.find(sum)==presumMap.end()) //adding this work for zeroes if present
            presumMap[sum] = i;
    }
    cout << maxLen;
}
//optimal O(2n) -worst space O(1) POISTIVES ZEROES
void longestSubarrayOptimal(int a[],int n,int target){
    int maxLen = 0;
    int left =0,right = 0;
    long long sum = a[0];
    while(right<n){
        while(sum > target && left<=right){
            sum -= a[left];
            left;
        }
        if(sum ==target)
            maxLen = max(maxLen,right-left+1);
        right++;
        if(right<n)
            sum += right;
    }
    cout << maxLen;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int target ;
    cin >> target;
    // longestSubarrayBrute(a,n,target);
    // longestSubarrayOptimisedBrute(a,n,target);
    // longestSubarrayHashmap(a,n,target);
    longestSubarrayOptimal(a,n,target);
    return 0;
}
