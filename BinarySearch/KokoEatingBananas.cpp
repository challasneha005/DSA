//KOKO EATING BANANAS
#include<bits/stdc++.h>
using namespace std;
int findMax(int a[],int n){
    int maxi = INT_MIN;
    for(int i =0;i<n;i++)
        maxi = max(maxi,a[i]);
    return maxi;
}
int calculateTotalHours(int a[],int n,int hourly){
    int totalHours = 0;
    for(int  i=0;i<n;i++)
        totalHours +=ceil((double)a[i] / (double)hourly );
    return totalHours;
}
int minRateToEat(int a[],int n,int h){
    int low = 1,high = findMax(a,n);
    while(low<=high){
        int mid = (low+high)/2;
        int totalHours = calculateTotalHours(a,n,mid);
        if(totalHours <= h)
            high = mid-1;
        else 
            low = mid+1;
    }
    return  low;
}
int main(){
    int n,h;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> h;
    int minRate = minRateToEat(a,n,h);
    cout << "minRate : " << minRate;
    return 0;
}