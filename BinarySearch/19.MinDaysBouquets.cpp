//MINIMUM NO.OF DAYS TO MAKE BOUQUETS
#include<bits/stdc++.h>
using namespace std;
//brute O(max-min+1) * n
bool possible(int a[],int n,int day,int m,int k){
    int cnt=0;
    int numOfBouq = 0;
    for(int i=0;i<n;i++){
        if(a[i] <= day)
            cnt++;
        else{
            numOfBouq += cnt/k;
            cnt = 0;
        }
    }
    numOfBouq += cnt/k;
    if(numOfBouq >= m)
        return true;
    return false;
}
pair<int,int> findMinMax(int a[],int n){
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i =0;i<n;i++){
        maxi = max(maxi,a[i]);
        mini = min(mini,a[i]);
    }
    return {mini,maxi};
}
int minDaysBrute(int a[],int n,int m,int k){
    if(n<m*k)
        return -1;
    pair<int, int> range = findMinMax(a, n);
    int mini = range.first;
    int maxi = range.second;
    for(int i=mini;i<=maxi;i++){
        if(possible(a,n,i,m,k) == true)
            return i;
    }
    return -1;
}
//optimal  O( log max-min+1) * n
int minDays(int a[],int n,int m,int k){
    if(n<m*k)
        return -1;
    pair<int, int> range = findMinMax(a, n);
    int mini = range.first;
    int maxi = range.second;
    int low = mini,high = maxi,ans = high;
    while(low<=high){
        int mid = (low+high)/2;
        if(possible(a,n,mid,m,k)==true){
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return ans;
}
int main(){
    int n,m,k; //m bouquets k asjacent flowers
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << "enter bouquets and adjacent flowers: ";
    cin >> m >> k;
    // int Days = minDaysBrute(a,n,m,k);
    int Days = minDays(a,n,m,k);
    if(Days == -1)
        cout << "Not Possible";
    else
        cout << "Minimum Days : " << Days;
    return 0;
}