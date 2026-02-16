// COUNT NICE SUBARRAYS - no.of odd numbers
// convert odd to 1 even 0,do BINARY SUBARRAYS WITH SUM  K

#include<bits/stdc++.h>
using namespace std;

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
        sum += a[r]%2;
        while(sum > k){
            sum -= a[l]%2;
            l++;
        }
        cnt+= r-l+1;
        r++;
    }
    return cnt;
}
int countNiceSubarrayKOptimal(vector<int> &a,int k){
    return countOptimal(a,k) - countOptimal(a,k-1);
}

// BEST FOR INTERVIEW

// TIME COMPLEXITY - O(n)   
// SPACE COMPLEXITY - O(1)

/*
APPROACH:
1. Define a helper function called atMostK, which calculates the number of subarrays with at most k odd numbers.
2. Initialize variables start to 0, oddCnt to 0, and ans to 0.
3. Iterate through each element nums[i] in the array:
   - If nums[i] is odd, increment oddCnt by 1.
   - While oddCnt is greater than k, move the start pointer and decrement oddCnt if the element at nums[start] is odd. This ensures that we maintain at most k odd numbers in the subarray.
   - Add the count of subarrays from start to i (i - start + 1) to ans.
4. Return ans, which represents the number of subarrays with at most k odd numbers.
5. In the numberOfSubarrays function, return the difference between atMostK(nums, k) and atMostK(nums, k - 1) to get the number of nice subarrays.
*/

int atMostK(vector<int>& nums, int k) {
    int l = 0, oddCnt = 0, ans = 0;
    for (int r = 0; r < nums.size(); r++) {
        if (nums[r] % 2 != 0)
            oddCnt++;
        while (oddCnt > k) {
            if (nums[l] % 2 != 0)
                oddCnt--;
            l++;
        }
        ans += r - l + 1;
    }
    return ans;
}
int numberOfSubarrays(vector<int>& nums, int k) {
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

int main(){
    int n,k;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> k;
    cout << countNiceSubarrayKOptimal(a,k) <<"\n";
    // cout << countSubarraysWithSum(a,k);
    return 0;
}

// INPUT
// 5
// 1 1 2 1 1 
// 3