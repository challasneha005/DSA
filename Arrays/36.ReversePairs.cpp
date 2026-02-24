//REVERSE PAIRS

#include<bits/stdc++.h>
using namespace std;

//brute O(n*n)
int countReversePairsBrute(vector<int> &a,int n){
    int count = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]> 2*a[j])
                count++;
        }
    }
    return count ;
}

//optimal O(2n log n)

// TIME COMPLEXITY: O(n log n), where n is the size of the array.
// SPACE COMPLEXITY: O(n), where n is the size of the array.

/*
APPROACH:
To solve this problem, we can use the merge sort algorithm. While merging the two sorted subarrays, we can count the number of reverse pairs.
1. Define a variable 'rev_pair' to store the count of reverse pairs.
2. Implement the 'merge' function to merge two subarrays and count the reverse pairs.
3. Implement the 'mergesort' function to recursively divide the array into subarrays and perform merge sort.
4. Initialize 'rev_pair' to 0 and call the 'mergesort' function on the given array.
5. Return the 'rev_pair' as the result.
*/

void merge(vector <int> &arr,int low,int mid,int high){ //time O(n log n base 2) space O(n)
    vector <int> temp;
    // low , mid
    //mid+1, high
    int left =low;
    int right = mid+1;
    while(left <= mid && right <= high){
        if (arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i - low];
    }
}
int countPairs(vector<int> &arr,int low,int mid,int high){
    int right = mid+1;
    int count = 0;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i]> 2*arr[right])
            right++;
        count += (right -(mid+1));
    }
    return count;
}
int  mergesort(vector<int> &arr,int low,int high  ){
    int count =0;
    if (low == high) return count;
    int mid =(low+high) /2;
    count += mergesort(arr,low,mid);
    count += mergesort(arr,mid+1,high);
    count += countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);

    return count;
}
int  countReversePairsOptimal(vector<int> &a,int n){
    return mergesort(a,0,n-1);  
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    // int count = countReversePairsBrute(a,n);
    int count = countReversePairsOptimal(a,n);
    cout << count;
    return 0;
}

// INPUT
// 5
// 1 3 2 3 1