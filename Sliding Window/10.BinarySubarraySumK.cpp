// BINARY SUBARRAYS WITH SUM  K

#include<bits/stdc++.h>
using namespace std;

// SLIDING WINDOW
// NOTE: Sliding window approach works only when array contains NON-NEGATIVE elements (binary array here).

// TIME COMPLEXITY - O(n)   
// SPACE COMPLEXITY - O(1)

/*
APPROACH 
1. Create a helper function countOptimal(a, k) that counts the number of subarrays with sum at most k.
2. If k is negative, immediately return 0, since no subarray can have a negative sum when all elements are non-negative.
3. Use a sliding window with two pointers l (left) and r (right), and maintain the current window sum.
4. Move the right pointer r forward and add a[r] to the current sum.
5. If the sum of the current window becomes greater than k, shrink the window from the left by:
    -Subtracting a[l] from the sum
    -Moving the left pointer l forward until the window sum becomes at most k.
6. Once the window sum is valid (≤ k), all subarrays ending at index r and starting from any index between l and r are valid.
    -Add (r − l + 1) to the count.
7. Continue this process until the entire array is processed and return the count of subarrays with sum at most k.
8. To find the number of subarrays with sum exactly k, use the relation:
    exactly k = atMost(k) − atMost(k−1)
9. Return the final result from countSubarrayKOptimal.
*/

int countOptimal(vector<int> &a,int k){
    int n = a.size();
    int l =0,r=0,cnt = 0 , sum =0;
    if(k<0)
        return 0;
    while(r<n){
        sum += a[r];
        while(sum > k){
            sum -= a[l];
            l++;
        }
        cnt+= r-l+1;
        r++;
    }
    return cnt;
}
int countSubarrayKOptimal(vector<int> &a,int k){
    return countOptimal(a,k) - countOptimal(a,k-1);
}

// BEST FOR INTERVIEW 

// TIME COMPLEXITY : O(N), where N is the size of the input array nums. We traverse the array once and perform constant time operations in the loop.
// SPACE COMPLEXITY : O(N), as the worst-case scenario would be that all prefix sums are distinct, so the map mp would store N prefix sums.
//     - we can reduce the space complexity to O(1) if we use this countOfSubarrays with atmost sum = k - atmost sum = k-1 
//     - which will return in countofSubarrays with sum exactly K, but this won't work if array has -ve elements

/*
APPROACH:
1. Create an unordered_map mp to store the prefix sum and its frequency.
2. Initialize a variable prefSum to keep track of the prefix sum.
3. Initialize a variable cnt to keep track of the count of subarrays with a sum equal to the goal.
4. Iterate through each element nums[i] in the array:
   - Update prefSum by adding nums[i].
   - Check if prefSum is equal to the goal, if so, increment cnt.
   - Check if the difference between prefSum and goal (prefSum - goal) exists in the map.
     - If it exists, increment cnt by the frequency of (prefSum - goal) in the map, as this would mean we have found subarrays with a sum equal to the goal.
   - Increment the frequency of prefSum in the map.
5. Return cnt, which represents the number of non-empty subarrays with a sum equal to the goal.
*/

int countSubarraysWithSum(vector<int>& a, int goal) {
    unordered_map<int, int> mp;
    int prefSum = 0, cnt = 0;
    for(int i = 0; i < a.size(); i++) {
        prefSum += a[i];
        if(prefSum == goal)
            cnt++;
        if(mp.find(prefSum - goal) != mp.end())
            cnt += mp[prefSum - goal];
        mp[prefSum]++;
    }
    return cnt;
}

int main(){
    int n,k;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> k;
    cout << countSubarrayKOptimal(a,k) <<"\n";
    cout << countSubarraysWithSum(a,k);
    return 0;
}

// INPUT
// 6
// 1 0 0 1 1 0
// 2