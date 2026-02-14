// MAX SCORE FROM CARDS WINDOW SIZE K,PICK ONLY CONSECUTIVELY

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY: O(2k), where n is the size of the cardPoints array. We iterate over the array once to calculate the total sum and find the minimum sum of a subarray.
// SPACE COMPLEXITY: O(1), as the extra space used is constant throughout the algorithm.


/*
APPROACH: Prefix–Suffix (Left and Right Picking)
To maximize the score by picking exactly k cards, we consider all possible ways of selecting cards from the left and right ends of the array.
1.Initialize left sum (lsum)
    -Compute the sum of the first k elements of the array.
    -This represents the case where all k cards are picked from the left side.
    -Initialize maxSum with this value.
    -Set a pointer r to the last index of the array.
2.Iteratively shift picks from left to right
    -Starting from the (k−1)th index down to 0:
       Remove the current element from the left sum (lsum), representing one less card taken from the left.
       Add one element from the right side to the right sum (rsum), representing one more card taken from the right.
       Decrement the right pointer r after each addition.
       Update maxSum with the maximum of its current value and the combined sum (lsum + rsum).
3.Final result
    -After trying all possible combinations of taking i cards from the left and (k−i) cards from the right, maxSum contains the maximum achievable score
*/

int maxScore(vector<int> &a,int k){
    int n = a.size();
    int r;
    long long lsum = 0,rsum = 0,maxSum  = 0;
    for(int i=0;i<k;i++){
        lsum += a[i];
        maxSum = lsum;
        r = n-1;
    }
    for(int i=k-1;i>=0;i--){
        lsum -= a[i];
        rsum += a[r];
        r--; 
        maxSum = max(maxSum,lsum+rsum);
    }
    return maxSum;
}

/*
APPROACH: O(n) - TC
To maximize the score, we need to minimize the sum of the discarded cards. We can find the minimum sum of a subarray of size (n - k) using a sliding window approach.
1. Create a helper function, minimumSumOfSizeK, which finds the minimum sum of a subarray of size k.
   - Initialize ans to INT_MAX, currsum to 0, and start to 0.
   - Iterate over the array from left to right:
     - Add the current element to currsum.
     - If the size of the current window (i - start + 1) exceeds k, remove the element at the start of the window from currsum and move the start to the next position.
     - If the size of the current window is k, update ans with the minimum of ans and currsum.
   - Return ans.
2. In the main function, maxScore:
   - Calculate the total sum of all the cards, totalSum.
   - Calculate the size of the discarded cards, windowSize, which is (n - k).
   - Find the minimum sum of a subarray of size windowSize using the minimumSumOfSizeK function and store it in discardedSum.
   - Return the maximum score, which is (totalSum - discardedSum).
*/

int minimumSumOfSizeK(vector<int>& arr, int k) {
    int ans = INT_MAX, currsum = 0, start = 0;
    for (int i = 0; i < arr.size(); i++) {
        currsum += arr[i];
        while ((i - start + 1) > k) {
            currsum -= arr[start];
            start++;
        }
        if ((i - start + 1) == k)
            ans = min(ans, currsum);
    }
    return ans;
}

int maxScore2(vector<int>& cardPoints, int k) {
    int totalSum = 0;
    for (auto it : cardPoints) 
        totalSum += it;
    int windowSize = cardPoints.size() - k;
    int discardedSum = minimumSumOfSizeK(cardPoints, windowSize);
    return totalSum - discardedSum;
}

int main(){
    int n,k;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> k;
    cout <<   maxScore(a,k) <<"\n";
    cout <<   maxScore2(a,k) <<"\n";
    return 0;
}

// INPUT
// 9
// 6 2 3 4 7 2 1 7 1 
// 4