//NUMBER OF SUBARRAY SUM K

#include<bits/stdc++.h>
using namespace std;

//brute O(n*n*n)
void numberOfSubarraySumBrute(int a[],int n,int target){
    int cnt =0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++)
                sum += a[k];
            if(sum == target)
                cnt++;
        }
    }
    cout << cnt << " is No.of subarrays of sum: " << target;
}

//better O(n*n)
void numberOfSubarraySumBetter(int a[],int n,int target){
    int cnt =0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += a[j];
        if(sum == target)
            cnt++;
        }
    }
    cout << cnt << " is No.of subarrays of sum: " << target;
}

//Optimal O(n log n) ordered map

// TIME COMPLEXITY: O(n), where n is the size of the input array nums.
// SPACE COMPLEXITY: O(n), as we are using a hashmap to store the prefix sums and their corresponding counts.

/*
APPROACH:
To find the total number of subarrays with sum equal to k, we can use the technique of prefix sum along with a hashmap.
1. Initialize a variable `count` to keep track of the count of subarrays with sum equal to k.
2. Initialize a variable `prefixSum` to keep track of the prefix sum while iterating through the array.
3. Initialize a hashmap `sumCount` to store the frequency of prefix sums encountered so far.
4. Set the initial prefix sum to 0 and set its count to 1 in the `sumCount` hashmap.
5. Iterate through the array and update the prefix sum by adding each element.
6. Check if the current prefix sum minus k exists in the `sumCount` hashmap. If it does, add the count of that prefix sum to the `count` variable.
7. Increment the count of the current prefix sum in the `sumCount` hashmap.
8. Finally, return the `count` variable as the total number of subarrays with sum equal to k.
*/

void numberOfSubarraySumOptimal(int a[],int n,int target){
    int cnt =0;
    unordered_map<int,int> map;
    map[0] = 1;
    int preSum = 0;
    for(int i=0;i<n;i++){
        preSum += a[i];
        int remove = preSum - target;
        cnt += map[remove];
        map[preSum]++;
    }
     cout << cnt << " is No.of subarrays of sum: " << target;
}

int main(){
    int n,target;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> target;
    numberOfSubarraySumBrute(a,n,target);
    return 0;
}

// INPUT
// 8 
// 3 4 7 2 -3 1 4 2
// 7