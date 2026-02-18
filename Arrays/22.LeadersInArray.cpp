//LEADERS IN AN ARRAY -everything in right should be smaller

#include<bits/stdc++.h>
using namespace std;

//brute O(n*n)
vector<int> leadersBrute(int a[],int n){
    vector <int> ans;
    for(int i=0;i<n;i++){
        bool leader = true;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]){
                leader = false;
                break;
            }
        }
        if(leader == true) 
            ans.push_back(a[i]);
    }
    return ans;  //same order of array
}

//optimal O(n) if sort,same order+O(n log n)

// TIME COMPLEXITY: O(n), where n is the size of the array.
// SPACE COMPLEXITY: O(1)

/*
APPROACH:-
To find the leaders in the array, we can follow these steps:
1. Initialize a variable `maxRight` with the rightmost element of the array.
2. Iterate the array from right to left:
   - If the current element is greater than or equal to `maxRight`, it is a leader. Print the current element and update `maxRight` to the current element.
3. Finally, print `maxRight` as it is always a leader.
*/

vector<int> leaderOptimal(int a[],int n){
    int maxi = INT_MIN;
    vector <int> ans;
    for(int i=n-1;i>=0;i--){
        if(a[i]>maxi)
            ans.push_back(a[i]);
        maxi = max(maxi,a[i]);
    }
    // sort(a,a+n); 
    //need as array reverse it
    return ans;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    // vector <int> ans = leadersBrute(a,n);
    vector <int> ans = leaderOptimal(a,n);
    for(auto it: ans)
        cout << it << " ";
    return 0;
}

// INPUT
// 6
// 16 17 4 3 5 2
