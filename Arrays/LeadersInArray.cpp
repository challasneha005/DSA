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
