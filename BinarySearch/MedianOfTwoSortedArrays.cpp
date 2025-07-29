//MEDIAN OF TWO SORTED ARRAYS
#include<bits/stdc++.h>
using namespace std;
//brute O(n1+n2) space(O(n1+n2))
int medianSortedArraysBrute(int a[],int b[],int n1,int n2){
    vector <int> a3;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(a[i] < b[j])
            a3.push_back(a[i++]);
        else
            a3.push_back(b[j++]);
    }
    while(i<n1)
        a3.push_back(a[i++]);
    while(j<n2)
        a3.push_back(b[j++]);
    int n = n1+n2;
    if(n%2 == 1)
        return a3[n/2];
    else
        return (double)((double)(a3[n/2])+(double)(a3[n/2-1]))/2.0;
}
//better O(n1+n2) space(O(1))
int medianSortedArraysBetter(int a[],int b[],int n1,int n2){
    int i=0,j=0;
    int n = n1+n2;
    int ind2 = n/2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el =-1,ind2el = -1;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            if(cnt == ind1)
                ind1el = a[i];
            if(cnt == ind2)
                ind2el = a[i];
            cnt++;
            i++;    
        }
        else{
            if(cnt == ind1)
                ind1el = b[j];
            if(cnt == ind2)
                ind2el = b[j];
            cnt++;
            j++;    
        }
    }
    while(i<n1){
        if(cnt == ind1)
            ind1el = a[i];
        if(cnt == ind2)
            ind2el = a[i];
        cnt++;
        i++;    
    }
    while(j<n2){
        if(cnt == ind1)
            ind1el = b[j];
        if(cnt == ind2)
            ind2el = b[j];
        cnt++;
        j++;    
    }
    if(n%2==1)
        return ind2el;
    return (double)((double)(ind1el+ind2el)) / 2.0;
}
//optimal O(log n1) n1 is smallest array size
int medianSortedArraysOptimal(int a[],int b[],int n1,int n2){
    if(n1 > n2)
        return medianSortedArraysOptimal(b,a,n2,n1);
    int low =0,high = n1;
    int left = (n1+n2+1)/2;
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
        if(l1 <= r2 && l2 <= r1){
            if(n%2 == 1)
                return max(l1,l2);
            return ((double)(max(l1,l2)+ min(r1,r2))) /2.0; 
        }
        else if(l1 > r2)
            high = mid1 -1;
        else 
            low = mid1 +1;
    }
    return 0;
}
int main(){
    int n1,n2;
    cin >> n1 >> n2;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++)
        cin >> a[i];
    for(int i=0;i<n2;i++)
        cin >> b[i];
    // double median = medianSortedArraysBrute(a,b,n1,n2);
    // double median = medianSortedArraysBetter(a,b,n1,n2);
    double median = medianSortedArraysOptimal(a,b,n1,n2);
    cout << median;
    return 0;
}