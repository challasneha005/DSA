// ASSIGN COOKIES ...SATISFY MORE CHILDREN O(n log n+m log m+M) , O(1)
#include<bits/stdc++.h>
using namespace std;
int assignCookies(vector<int> &greed,vector<int> &available){
    int n = greed.size();
    int m = available.size();
    sort(greed.begin(),greed.end());
    sort(available.begin(),available.end());
    int l=0, r = 0;
    while(l<m){
        if(greed[r]<=available[l])
            r = r+1;
        l = l+1;
    }
    return r;
}
int main(){
    vector<int> greed = {1,5,3,3,4};
    vector<int> available = {4,2,1,2,1,3};
    cout << assignCookies(greed,available);
    return 0;
}