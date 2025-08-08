#include<bits/stdc++.h>
using namespace std;
void selection_sort(int arr[],int n){   //O(n sq) best,worst,average
    for (int i=0;i<=n-2;i++){ 
        int mini =i;
        for (int j=i;j<=n-1;j++){
            if (arr[j] < arr[mini])
                mini =j;
        }
        //swap
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}



void bubble_sort(int arr[],int n){    //O(n sq)  worst,avg   ;O(n) best 
    // int didswap=0;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i-1;j++){
            if(arr[j] > arr[j+1]){
                //swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            //     didswap=1;
            }
        }
        // if (didswap==0) break; 
        
    }
}



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
void mergesort(vector<int> &arr,int low,int high  ){
    if (low == high) return ;
    int mid =(low+high) /2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}



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
    //int arr[n];
    vector <int> arr(n); //merge,qucik  
    for(int i=0;i<n;i++) cin >> arr[i];
    //selection_sort(arr,n);
    // bubble_sort(arr,n);
    // insertion_sort(arr,n);
    // mergesort(arr,0,n-1);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
} 
