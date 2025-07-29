//ALLOCATE BOOKS 
// student atleast 1 book,consecutive distribution
//PAINTERS PARTITION - to complete in less time
//SPLIT ARRAY - LARGEST SUM -max subarray sum is minimum
#include<bits/stdc++.h>
using namespace std;
//brute O(sum-max+1)*O(n)
int findMax(int a[],int n){
    int maxi = INT_MIN;
    for(int i =0;i<n;i++)
        maxi = max(maxi,a[i]);
    return maxi;
}
int reqStudent(int a[],int n,int pages){
    int student = 1,pagesStudent = 0;
    for(int i=0;i<n;i++){
        if(pagesStudent+a[i]<=pages)
            pagesStudent+=a[i];
        else{
            student++;
            pagesStudent = a[i];
        }
    }
    return student;
}
int pagesLeastBrute(int a[],int n,int m){
    int maxi = findMax(a,n);
    int sum = accumulate(a,a+n,0);
    for(int pages = maxi;pages<=sum;pages++){
        int cntStudents = reqStudent(a,n,pages);
        if(cntStudents == m)
            return pages;
    }
    return -1;
} 
//optimal O(log (sum-max+1))*O(n)
int pagesLeast(int a[],int n,int m){
    if(m >n)
        return -1;
    int low = findMax(a,n);
    int high = accumulate(a,a+n,0);
    while(low<=high){
        int mid = (low+high)/2;
        int numOfStudents = reqStudent(a,n,mid);
        if(numOfStudents > m)
            low = mid+1;
        else    
            high = mid -1;
    } 
    return low;
}   
int main(){
    int n,m;
    cin >> n ;
    int a[n];
    for(int i=0;i<n;i++)
    cin >> a[i];
    cin >> m;
    // int result = pagesLeastBrute(a,n,m);
    int result = pagesLeast(a,n,m);
    if (result == -1)
        cout << "Allocation not possible";
    else
        cout << "Minimum number of pages to be allocated to students is: " << result;
    return 0;
}
