//MINIMISE MAX DISTANCE TO GAS STATIONS
#include<bits/stdc++.h>
using namespace std;
//brute O(k*n)
long double minimiseMaxGasStationsBrute(int a[],int n,int k){
    vector <int> howMany(n-1,0);
    for(int gasStations = 1;gasStations<=k;gasStations++){
        long double maxSection = -1;
        int maxInd=-1;
        for(int i=0;i<n-1;i++){
            long double diff = a[i+1] - a[i];
            long double sectionLength = diff / (long double) (howMany[i]+1);
            if(sectionLength > maxSection){
                maxSection = sectionLength;
                maxInd = i;
            } 
        } 
        howMany[maxInd]++;
    }
    long double maxAns= -1;
    for(int i=0;i<n-1;i++){
        long double diff = (a[i+1] - a[i]);
        long double sectionLength = diff / (long double) (howMany[i]+1); 
        maxAns = max(maxAns,sectionLength);
    }
    return maxAns;
}
// better O(n log n+ k log n)
long double minimiseMaxGasStationsBetter(int a[],int n,int k){
    vector <int> howMany(n-1,0);
    priority_queue <pair<long double,int>> pq;
    for(int i=0;i<n-1;i++)
        pq.push({a[i+1] - a[i] ,i});
    for(int gasStations = 1;gasStations <=k;gasStations++){
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double diff = a[secInd+1] - a[secInd];
        long double sectionLength = diff / (long double) (howMany[secInd]+1);
        pq.push({sectionLength,secInd});
    }
    return pq.top().first;
}
//optimal O(n+log k)
int numOfGasStations(long double dist,int a[],int n){
    int cnt =0;
    for(int i=1;i<n;i++){
        int numInBetween = (a[i] - a[i-1])/dist;
        if((a[i] - a[i-1]) /dist == numInBetween * dist)
            numInBetween--;
        cnt += numInBetween;
    }
    return cnt;
}
long double minimiseMaxGasStationsOptimal(int a[],int n,int k){
    long double low = 0,high =0;
    for(int i=0;i<n-1;i++)
        high = max(high,(long double)(a[i+1] -a[i]));
    long double diff = 1e-6;
    while(high - low > diff){
        long double mid = (low+high)/(2.0);
        int cnt = numOfGasStations(mid,a,n);
        if(cnt > k)
            low = mid;
        else 
            high = mid;
    }
    return high;
}
int main(){
    int n,k;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> k; 
    // long double dist = minimiseMaxGasStationsBrute(a,n,k);
    // long double dist = minimiseMaxGasStationsBetter(a,n,k);
    long double dist = minimiseMaxGasStationsOptimal(a,n,k);
    cout << dist;
    return 0;
}