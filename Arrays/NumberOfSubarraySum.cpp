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