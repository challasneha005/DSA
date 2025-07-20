//TWO SUM PROBLEMS elements sum = target,return index also
#include<bits/stdc++.h>
using namespace std;
//brute O(n*n)
void twoSumBrute(int a[],int n,int target){
    bool found = false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==target){
                cout << a[i] << " at " << i << " and " << a[j] << " at "<< j << endl;
                found = true;
            }
        }
    }
    if(!found)
        cout << -1;
}
//better hashmap O(n log n)-ordered, O(n) unordered
//space O(n)
void twoSumHashmap(int a[],int n,int target){
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        int more = target - a[i];
        if(map.find(more) != map.end()){
            cout << a[map[more]] << " at " << map[more]
                 << " and " << a[i] << " at " << i << endl;
            return;
        }
        map[a[i]] =i;
    }
    cout<< "NO" << endl;
}
//Optimal O(n)+O(n log n) -sort ,space O(1)
void twoSumOptimal(int a[],int n,int target){
    bool found = false;
    sort(a,a+n);
    int left = 0;
    int right = n-1;
    while(left<right){
        int sum = a[left] + a[right];
        if(sum == target){
            cout << a[left] << " at " << left << " and " << a[right]
            << " at " << right << endl;
            found = true;
            left++;
            right--;
        }
        else if(sum < target)
            left++;
        else
            right--;
    }
    if(!found)
        cout << -1 << endl;
}        
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int target;
    cin >> target;
    // twoSumBrute(a,n,target);
    // twoSumHashmap(a,n,target);  //return only 1 pair
    twoSumOptimal(a,n,target);
    return 0;
}
