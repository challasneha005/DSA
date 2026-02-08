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

/*
APPROACH:-
To solve this problem, we can use a prefix sum approachalong with a hashmap to keep track of the prefix sums encountered so far. We iterate through the array and 
maintain a prefix sum variable. At each index, we check if the prefix sum equals K, in which case we update the maximum length of the subarray found so far. Additionally, 
we check if the current prefix sum minus K exists in the hashmap. If it does, it means there is a subarray between the previous occurrence of the prefix sum minus K and
the current index that sums up to K. We update the maximum length accordingly. We store the prefix sums and their corresponding indices in the hashmap.
*/

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

//optimal   POISTIVES ZEROES

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)

/*
APPROACH:-
-> Use sliding window approach using two pointers start and end
-> Run a loop to traverse the entire array add from end and subtract from start when sum>k
-> If sum==k then, update the ans now, window size = end-start+1
*/

void longestSubarrayOptimal(int a[],int n,int target){
    int maxLen = 0;
    int left =0,right = 0;
    long long sum = 0;
    while(right<n){
        sum+= a[right];
        while(sum > target && left<=right){
            sum -= a[left];
            left++;
        }
        if(sum ==target)
            maxLen = max(maxLen,right-left+1);
        right++;
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

// INPUT
// 7
// 1 2 3 1 1 1 1
// 3