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
