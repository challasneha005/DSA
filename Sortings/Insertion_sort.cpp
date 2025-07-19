#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[],int n){  //O(n sq)  worst,avg   ;O(n) best
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1] > arr[j]){
            //swap j-1,j
            int temp = arr[j-1];
            arr[j-1] =arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n]; 
    for(int i=0;i<n;i++) cin >> arr[i];
    insertion_sort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
} 
