// SORT  AN ARRAY OF 0,1,2
#include<bits/stdc++.h>
using namespace std;
//brute O(nlog n)  general sortings
//better O(2n)
void sortarray(int a[],int n){
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(a[i]==0)
            cnt0++;
        else if(a[i]==1)
            cnt1++;
        else
            cnt2++;
    }
    for(int i=0;i<cnt0;i++)
        a[i]=0;
    for(int i=cnt0;i<cnt1;i++)
        a[i]=1;
    for(int i=cnt1;i<cnt2;i++)
        a[i]=2;
}
//Optimal 
//DUTCH NATIONAL FLAG ALGORITHM O(n)
void sortarrayOptimal(int a[],int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(a[mid]==0){
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if(a[mid]==1)
            mid++;
        else{
            swap(a[mid],a[high]);
            high--;
        }
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    //sortarray(a,n);
    sortarrayOptimal(a,n);
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}
