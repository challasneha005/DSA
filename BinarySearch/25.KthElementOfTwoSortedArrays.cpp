//Kth ELEMENT OF TWO SORTED ARRAYS
#include<bits/stdc++.h>
using namespace std;
//Kth ELEMENT OF TWO SORTED ARRAYS
//brute O(n1+n2) space(O(n1+n2))
int kthElementSortedArraysBrute(int a[], int b[], int n1, int n2, int k) {
    vector<int> a3;
    int i = 0, j = 0;
    while(i < n1 && j < n2) {
        if(a[i] < b[j])
            a3.push_back(a[i++]);
        else
            a3.push_back(b[j++]);
    }
    while(i < n1)
        a3.push_back(a[i++]);
    while(j < n2)
        a3.push_back(b[j++]); 
    if(k <= 0 || k > n1 + n2)
        return -1;  
    return a3[k - 1];   
}
//better O(n1+n2) space(O(1))
int kthElementSortedArraysBetter(int a[], int b[], int n1, int n2, int k) {
    int i = 0, j = 0;
    int cnt = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            cnt++;
            if (cnt == k) 
                return a[i];
            i++;
        } else {
            cnt++;
            if (cnt == k) 
                return b[j];
            j++;
        }
    } 
    while (i < n1) {
        cnt++;
        if (cnt == k) 
            return a[i];
        i++;
    } 
    while (j < n2) {
        cnt++;
        if (cnt == k) 
            return b[j];
        j++;
    }

    return -1;  
}
//optimal O(log n1) n1 is smallest array size
int kthElementSortedArraysOptimal(int a[],int b[],int n1,int n2,int k){
    if(n1 > n2)
        return kthElementSortedArraysOptimal(b,a,n2,n1,k);
    int low =  max(0, k - n2), high = min(k, n1); //change
    int left = k; //change
    int n=n1+n2;
    while(low <= high){
        int mid1 = (low+high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN , l2 = INT_MIN;
        int r1 = INT_MAX , r2 = INT_MAX;
        if(mid1 < n1) 
            r1 = a[mid1];
        if(mid2 < n2)
            r2 = b[mid2];
        if(mid1-1 >= 0) 
            l1 = a[mid1 - 1];
        if(mid2-1 >= 0)
            l2 = b[mid2 - 1];
        if(l1 <= r2 && l2 <= r1) //change
            return max(l1,l2);
        else if(l1 > r2)
            high = mid1 -1;
        else 
            low = mid1 +1;
    }
    return 0;
}
int main(){
    int n1,n2,k;
    cin >> n1 >> n2;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++)
        cin >> a[i];
    for(int i=0;i<n2;i++)
        cin >> b[i];
    cin >> k;
    // double kthElement = kthElementSortedArraysBrute(a,b,n1,n2,k);
    // double kthElement = kthElementSortedArraysBetter(a,b,n1,n2,k);
    double kthElement = kthElementSortedArraysOptimal(a,b,n1,n2,k);
    cout << kthElement;
    return 0;
}