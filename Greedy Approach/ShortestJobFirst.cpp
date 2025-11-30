// SHORTEST JOB FIRST..RETURN AVG WAITING TIME
#include<bits/stdc++.h>
using namespace std;
long long SJFavgwt(vector<int> &a){
    sort(a.begin(),a.end());
    int t=0,waitingTime = 0;
    for(int i=0;i<a.size();i++){
        waitingTime +=t;
        t+=a[i];
    }
    return waitingTime/a.size();
}
int main(){
    vector<int> a = {4,3,7,1,2};
    cout << SJFavgwt(a);
    return 0;
}