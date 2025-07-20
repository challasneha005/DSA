//LINEAR SEARCH
#include<bits/stdc++.h>
using namespace std;
//brute O(n) 
void linearSearchBrute(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target)
            cout << target << " index "<<i;
    }
}
//Optimal O(n)
void linearSearchOptimal(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout << target << " index "<<i;
            return ;
        }
    }
    cout << "Not found" ;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int target;
    cin >> target;
    //linearSearchBrute(arr,n,target);
    linearSearchOptimal(arr,n,target);
    return 0;
}
