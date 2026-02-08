//MAX CONSECUTIVE ONES

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)
 
/*
APPROACH:-
-> Traverse the entire array and within it run a loop while element's are equal to 1 and store the count
-> Update the ans as max(ans,cnt)
*/

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
    cout << maxOnes;
    return 0;
}

// INPUT
// 7
// 1 1 9 1 1 1 8 1 1 
