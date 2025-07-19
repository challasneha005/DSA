#include<bits/stdc++.h>
using namespace std;
int partition(vector <int> &arr,int low,int high){  //time O(n log n base 2) space O(1)
    int pivot = arr[low];
    int i= low;
    int j = high;
    while(i<j){
        while(arr[i] <= pivot && i<=high-1){
            i++;
        } 
        while(arr[j] > pivot && j>=low+1){
            j--;
        }
        if(i<j){
            //swap arr[i],arr[j];
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //swap arr[low],arr[j] //here low is pivot
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quicksort(vector <int> &arr,int low,int high){
    if(low<high){
        int pIndex = partition(arr,low,high);
        quicksort(arr,low,pIndex-1);
        quicksort(arr,pIndex+1,high); 
    }
}
int main(){
    int n;
    cin >> n;
    vector <int> arr(n); //merge,qucik  
    for(int i=0;i<n;i++) 
      cin >> arr[i];
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
} 
