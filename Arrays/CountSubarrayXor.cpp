//COUNT SUBARRAY WITH  XOR AS K
#include<bits/stdc++.h>
using namespace std;
void subarrayXorBrute(int a[],int n,int target){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int Xor = 0;
            for(int k=i;k<=j;k++)
                Xor = Xor ^ a[k];
            if(Xor == target)
                cnt++;
        }
    }
    cout << cnt << endl;
}
void subarrayXorBetter(int a[],int n,int target){
    int cnt = 0;
    for(int i=0;i<n;i++){
        int Xor = 0;
        for(int j=i;j<n;j++){
            Xor = Xor ^ a[j];
            if(Xor == target)
                cnt++;
        }
    }
    cout << cnt << endl;
}
void subarrayXorOptimal(int a[],int n,int target){
    int xr = 0,cnt=0;
    unordered_map <int,int> m;
    m[0] = 1;
    for(int i=0;i<n;i++){
        xr = xr ^ a[i];
        int x = xr ^ target;
        cnt += m[x];
        m[xr]++;
    }
    cout << cnt;
}
int main(){
    int n,target;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> target;
    // subarrayXorBrute(a,n,target);
    // subarrayXorBetter(a,n,target);
    subarrayXorOptimal(a,n,target);
    return 0;
}