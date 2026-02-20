//COUNT SUBARRAY WITH  XOR AS K

#include<bits/stdc++.h>
using namespace std;

// brute
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

// better
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

// optimal

// TIME COMPLEXITY: O(n), where n is the size of the input array a.
// SPACE COMPLEXITY: O(n), as we are using a hashmap to store the prefix XOR values and their corresponding counts.

/*
APPROACH:
To find the number of subarrays with bitwise XOR equal to B, we can use the technique of prefix XOR along with a hashmap.
1. Initialize a variable `prefixXOR` to keep track of the prefix XOR while iterating through the array.
2. Initialize a variable `count` to keep track of the count of subarrays with XOR equal to B.
3. Initialize a hashmap `xorCount` to store the frequency of prefix XOR values encountered so far.
4. Set the initial prefix XOR to 0 and set its count to 1 in the `xorCount` hashmap.
5. Iterate through the array and update the prefix XOR by XOR-ing each element.
6. Check if the current prefix XOR is equal to B. If it is, increment the `count` variable.
7. Check if the XOR of the current prefix XOR with B exists in the `xorCount` hashmap. If it does, add the count of that XOR value to the `count` variable.
8. Increment the count of the current prefix XOR in the `xorCount` hashmap.
9. Finally, return the `count` variable as the number of subarrays with XOR equal to B.
*/

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

// INPUT
// 4 
// 1 2 3 2
// 2