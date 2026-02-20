//4 SUM CODE

#include<bits/stdc++.h>
using namespace std;

//brute  O(n*n*n*n)
void sum4CodeBrute(int a[],int n,int target){
    set<vector<int>> s;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    int sum = a[i]+a[j]+a[k]+a[l];
                    if(sum == target){
                        vector<int> temp={ a[i],a[j],a[k],a[l]};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
    }
    for (auto triplet : s) {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }
}

//better O(n*n*n)+O(log m)-set
void sum4CodeBetter(int a[],int n,int target){
    set<vector<int>> s;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            unordered_set <int> hashset;
            for(int k=j+1;k<n;k++){
                int sum = a[i]+a[j]+a[k];
                int fourth = target-sum;
                if(hashset.find(fourth)!=hashset.end()){
                    vector<int> temp={ a[i],a[j],a[k],fourth};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
            }
            hashset.insert(a[j]);
        }
    } 
    for (auto triplet : s) {
        for (int x : triplet)
        cout << x << " ";
    cout << endl;
    }
}  
//optimal  O(n log n)+O(n*n*n)

// TIME COMPLEXITY: O(n^3), where n is the size of the input array nums.
// SPACE COMPLEXITY: O(1), as we are using a constant amount of extra space.

/*
APPROACH:
To find the unique quadruplets that sum up to the target, we can use a similar approach as the threeSum problem. We will fix two elements (nums[a] and nums[b]) and use two pointers to find the remaining two elements (nums[c] and nums[d]) that sum up to the target.
1. Sort the input array nums in ascending order.
2. Iterate through the array with two pointers: a and b.
3. For each pair of elements nums[a] and nums[b], use two pointers c and d to find the remaining two elements that sum up to the target.
   - Initialize c as b + 1 and d as the last index of the array.
   - Calculate the target sum as trgt = target - (nums[a] + nums[b]).
   - While c < d, compare the sum of nums[c] and nums[d] with the target sum.
     - If the sum is equal to the target sum, we found a quadruplet. Add it to the answer and move the pointers c and d.
       - Important: Skip any duplicate elements while moving c and d.
     - If the sum is greater than the target sum, decrement d.
     - If the sum is less than the target sum, increment c.
4. Skip any duplicate elements for pointers a and b to avoid duplicate quadruplets.
5. Return the answer array containing unique quadruplets.
*/

void sum4CodeOptimal(int a[],int n,int target){
    vector<vector<int>> ans;
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1])
            continue;
        for(int j=i+1;j<n;j++){
            if(j!=i+1 && a[j]==a[j-1])
                continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                int sum = a[i]+a[j]+a[k]+a[l];
                if(sum == target){
                    vector<int> temp={ a[i],a[j],a[k],a[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && a[k]==a[k-1])
                    k++;
                    while(k<l && a[l]==a[l+1])
                    l--;
                }
                else if(sum<target)
                    k++;
                else
                    l--;
            }
        }
    }
    for (auto triplet : ans) {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }
} 

int main(){
    int n,target;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
      cin >> target;
    sum4CodeBrute(a,n,target);
    sum4CodeBetter(a,n,target);
    sum4CodeOptimal(a,n,target);
    return 0;
}


// INPUT
// 6
// 1 0 -1 0 -2 2
// 0