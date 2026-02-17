//MAXIMUM SUBARRAY SUM

#include<bits/stdc++.h>
using namespace std;

//brute O(n*n*n)
int maxSubArraySumBrute(int a[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum += a[k];
                maxi = max(maxi,sum);
            }
        }
    }
    return maxi;
}

//better O(n*n)
int maxSubArraySumBetter(int a[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += a[j];
            maxi = max(maxi,sum);
        }
    }
    return maxi;
}

//optimal

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)

// KADANE's ALGORITHM O(n) printing array also
/*
APPROACH:-
-> Initialize two variables: maxSum and currentSum. Set both variables to the first element of the array.
-> Iterate through the array starting from the second element:
    Update currentSum by adding the current element to it.
    If currentSum becomes negative, reset it to 0. This step ensures that we consider only the subarrays with positive sums.
    Update maxSum by taking the maximum value between maxSum and currentSum. This keeps track of the maximum subarray sum encountered so far.
-> After the iteration, the maxSum variable will hold the largest sum of any subarray.
-> Return the maxSum as the result.
*/

int maxSubArraySumOptimal(int a[],int n){
    int maxi = INT_MIN;
    int sum = 0;
    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;
    for(int i=0;i<n;i++){
        if(sum == 0)
            start = i;
        sum +=a[i];
        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0)
            sum = 0;
    }
    return maxi;
}

//only sum
int maxSubArray(vector<int> &nums)
{
    int curr_sum = 0;
    int ans = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        curr_sum += nums[i];
        ans = max(ans, curr_sum);
        if (curr_sum < 0)
            curr_sum = 0;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    //cout <<   maxSubArraySumBrute(a,n);
    // cout <<   maxSubArraySumBetter(a,n);
    cout <<   maxSubArraySumOptimal(a,n);
    return 0;
}

// INPUT
// 9
// -2 1 -3 4 -1 2 1 -5 4
