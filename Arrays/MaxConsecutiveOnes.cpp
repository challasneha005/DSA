//MAX CONSECUTIVE ONES
#include<bits/stdc++.h>
using namespace std;
int maxConsecutiveOnes(int a[],int n){
    int maxOnes = 0,cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            cnt++;
            maxOnes = max(maxOnes,cnt);
        }
        else cnt =0;
    }
    return maxOnes;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int maxOnes=maxConsecutiveOnes(a,n);
    cout << maxOnes;;
}
