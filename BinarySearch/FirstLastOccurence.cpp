//FIRST AND LAST OCCURENCE OF x
#include<bits/stdc++.h>
using namespace std;
pair<int,int> firstLastOccurence(int a[],int n,int target){
    int first = -1,last = -1;
    for(int i=0;i<n;i++){
        if(a[i] == target){
            if (first == -1)
                first = i;
            last = i;
        }
    }
    // cout << "First occurence at: "<< first << " last at: "<< last << endl;
    return {first,last};
}
pair<int,int> firstLastOccurenceBound(int a[],int n,int target){
    int* lb = lower_bound(a,a+n,target);
    int index1 = lb -a;
    int* ub = upper_bound(a,a+n,target);
    int index2 = ub - a; 
    if( index1 == n || a[index1] !=target )
        return {-1,-1};
    else
        return{index1,index2-1};
}
//using Binary search
int firstOccurence(int a[],int n,int target){
    int first = -1;
    int low = 0,high = n-1;
    while(low <=high){
        int mid = (low+high)/2;
        if(a[mid] == target){
            first = mid;
            high = mid -1;
        }
        else if(a[mid] < target)
            low = mid+1;
        else
            high = mid-1;
    }
    return first;
}
int lastOccurence(int a[],int n,int target){
    int last = -1;
    int low = 0,high = n-1;
    while(low <=high){
        int mid = (low+high)/2;
        if(a[mid] == target){
            last = mid;
            low = mid +1;
        }
        else if(a[mid] < target)
            low = mid+1;
        else
        high = mid-1;
    }
    return last;
}
pair<int,int> firstLastOccurenceBs(int a[],int n,int target){
    int first = firstOccurence(a,n,target);
    if (first == -1)
        return {-1,-1};
    int last = lastOccurence(a,n,target);
    return {first,last};
}
int main(){
    int n,target;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    cin >> a[i];
    cin >> target;
    // pair<int,int> index =firstLastOccurence(a,n,target); 
    // pair<int,int> index =firstLastOccurenceBound(a,n,target); 
    pair<int,int> index =firstLastOccurenceBs(a,n,target);
    cout << index.first <<" & "<< index.second; 
    return 0;
}