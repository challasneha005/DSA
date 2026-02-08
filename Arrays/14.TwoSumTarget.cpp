#include<bits/stdc++.h>
using namespace std;
//TWO SUM PROBLEMS elements sum = target,return index also
//brute O(n*n)
void twoSumBrute(int a[],int n,int target){
    bool found = false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==target){
                cout << a[i] << " at " << i << " and " << a[j] << " at "<< j << endl;
                found = true;
            }
        }
    }
    if(!found)
        cout << -1;
}
//better hashmap O(n log n)-ordered, O(n) unordered
//space O(n)
/*
Approach:
-> Create an empty map to store the elements and their corresponding indices.
>  Iterate through the input array, nums, and for each element:
    Calculate the complement by subtracting the current element from the target value.
    Check if the complement exists in the map.
    If the complement exists, return the indices of the current element and the complement.
    If the complement does not exist, add the current element and its index to the map.
-> If no solution is found, return an empty vector or a message indicating no solution exists.
*/
void twoSumHashmap(int a[],int n,int target){
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        int more = target - a[i];
        if(map.find(more) != map.end()){
            cout << a[map[more]] << " at " << map[more]
                 << " and " << a[i] << " at " << i << endl;
            return;
        }
        map[a[i]] =i;
    }
    cout<< "NO" << endl;
}

//Optimal O(n)+O(n log n) -sort ,space O(1)

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(N)

void twoSumOptimal(int a[],int n,int target){
    bool found = false;
    sort(a,a+n);
    int left = 0;
    int right = n-1;
    while(left<right){
        int sum = a[left] + a[right];
        if(sum == target){
            cout << a[left]  << " and " << a[right] << endl;
            found = true;
            left++;
            right--;
        }
        else if(sum < target)
            left++;
        else
            right--;
    }
    if(!found)
        cout << -1 << endl;
}     

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int target;
    cin >> target;
    // twoSumBrute(a,n,target);
    // twoSumHashmap(a,n,target);  //return only 1 pair
    twoSumOptimal(a,n,target);
    return 0;
}


// INPUT
// 4
// 2 7 11 15
// 9
