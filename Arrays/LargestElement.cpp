//LARGEST ELEMENT
#include<bits/stdc++.h>
using namespace std;
//brute sort and large  (O(n log n))
//better (o(n))

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int large = arr[0];
    for(int i=0;i<n;i++){
        if (arr[i]>large)
            large = arr[i];
    }
    cout << large ;
    return 0;
}
