// AGGRESSIVE COWS
#include<bits/stdc++.h>
using namespace std;
// Min distance between cows is max
//brute O(max - min)*O(n)
bool canWePlace(int a[],int n,int dist,int cows){
    int cntcows = 1,last = a[0];
    for(int i=1;i<n;i++){
        if(a[i]- last >=dist){
            cntcows++;
            last = a[i];
        }
    }
    if(cntcows >= cows) 
        return true;
    return false;
}
int minDistanceBrute(int a[], int n, int cows) {
    sort(a,a+n);
    int maxi = a[n - 1];
    int mini = a[0];
    int ans = 0;
    for(int i=1;i<= (maxi-mini);i++){
        if(canWePlace(a,n,i,cows)==true)
            ans  =i;
        else
            break;
    }
    return ans;
}
//optimal O(log (max - min))*O(n)
int minDistance(int a[], int n, int cows) {
    sort(a,a+n);
    int low = 0,high = a[n-1] - a[0];
    while(low<=high){
        int mid = (low+high)/2;
        if(canWePlace(a,n,mid,cows) == true)
            low = mid+1; 
        else   
            high = mid-1;
    }
    return high;
}
int main(){
    int n,cows;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    cin >> a[i];
    cin >> cows;
    // int result = minDistanceBrute(a,n,cows);
    int result = minDistance(a,n,cows);
    cout << "Max possible minimum distance between cow is: " << result;
    return 0;
}