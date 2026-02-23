// MERGE SORTED ARRAYS

#include<bits/stdc++.h>
using namespace std;

//brute O(n+m) + O(n+m)
void mergeSortedArraysBrute(int a1[],int a2[],int n,int m){
    long long a3[n+m];
    int left = 0,right = 0,index = 0;
    while(left<n && right<m){
        if(a1[left]<a2[right])
            a3[index++] = a1[left++];
        else
            a3[index++] = a2[right++];
    }
    while(left<n)
    a3[index++] = a1[left++];
    while(right<m)
    a3[index++] = a2[right++];
    for(int i = 0;i<n+m;i++){
        if(i<n) 
            a1[i] = a3[i];
        else
            a2[i-n] = a3[i];
    }
}

//optimal solution 1 O(min(n,m))+O(nlogn)+O(mlog m)

/*
TIME COMPLEXITY: O(m + n), where m and n are the lengths of nums1 and nums2 respectively.
The merging process requires iterating through both arrays once.
SPACE COMPLEXITY: O(1)
The merge is performed in-place without using any additional space.
*/

/*
APPROACH:
To merge two sorted arrays, nums1 and nums2, into nums1, we can use a two-pointer approach.
1. Initialize three pointers: i, j, and k, where i points to the last valid element of nums1, j points to the last element of nums2, and k points to the last index of the merged array nums1.
2. Start from the end of the arrays and compare the elements at i and j.
3. If the element at nums1[i] is greater than the element at nums2[j], swap it with the element at nums1[k], decrement i and k.
4. Otherwise, swap the element at nums2[j] with the element at nums1[k], decrement j and k.
5. Repeat steps 3 and 4 until all elements in nums1 and nums2 have been merged.
6. If there are still elements remaining in nums2 after merging, copy them to the remaining positions in nums1.
*/

void mergeSortedArraysOptimal1(int a1[],int a2[],int n,int m){
    int left = n-1;
    int right = 0;
    while(left>=0 && right<m){
        if(a1[left]>a2[right]){
            swap(a1[left],a2[right]);
            left--;
            right++;
        }
        else 
            break;
    }
    sort(a1,a1+n);
    sort(a2,a2+m);
}

void mergeBest(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
    while (j >= 0)
        nums1[k--] = nums2[j--];
}

//optimal solution 2 O(log n base 2)+O(n+m)
void mergeSortedArraysOptimal2(int a1[],int a2[],int n,int m){
    int len = n+m;
    int gap = (len/2) + (len%2);
    while(gap > 0){
        int left = 0;
        int right = left+gap;
        while(right < len){
            if(left< n && right >=n){  //a1 a2
                if(a1[left] > a2[right-n])
                    swap(a1[left],a2[right-n]);
            }
            else if(left>=n  ){ //a2 a2
                if(a2[left-n] > a2[right-n])
                    swap(a2[left-n],a1[right-n]);
            }
            else  { //a1 a1
                if(a1[left] > a1[right])
                    swap(a1[left],a1[right]);
            }
            left++;
            right++;
        }
        if(gap == 1) break;
        gap = (gap/2)+ (gap%2);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    int a1[n],a2[m];
    for(int i = 0;i<n;i++)
        cin >> a1[i];
    for(int i=0;i<m;i++)
        cin >> a2[i];
    // mergeSortedArraysBrute(a1,a2,n,m);
    // mergeSortedArraysOptimal1(a1,a2,n,m);
    mergeSortedArraysOptimal2(a1,a2,n,m);
    for(int i=0;i<n;i++)
        cout << a1[i] << " ";
    cout << endl;
    for(int i=0;i<m;i++)
        cout << a2[i] << " ";
    return 0;
}

// INPUT
// 6 3
// 1 2 3 3 7 8 
// 6 9 19
