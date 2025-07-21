//4 SUM CODE
#include<bits/stdc++.h>
using namespace std;
//brute  O(n*n*n*n)
void sum4CodeBrute(int a[],int n,int target){
    set<vector<int>> s;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    int sum = a[i]+a[j]+a[k]+a[l];
                    if(sum == target){
                        vector<int> temp={ a[i],a[j],a[k],a[l]};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
    }
    for (auto triplet : s) {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }
}
//better O(n*n*n)+O(log m)-set
void sum4CodeBetter(int a[],int n,int target){
    set<vector<int>> s;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            unordered_set <int> hashset;
            for(int k=j+1;k<n;k++){
                int sum = a[i]+a[j]+a[k];
                int fourth = target-sum;
                if(hashset.find(fourth)!=hashset.end()){
                    vector<int> temp={ a[i],a[j],a[k],fourth};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
            }
            hashset.insert(a[j]);
        }
    } 
    for (auto triplet : s) {
        for (int x : triplet)
        cout << x << " ";
    cout << endl;
    }
}  
//optimal  O(n log n)+O(n*n*n)
void sum4CodeOptimal(int a[],int n,int target){
    vector<vector<int>> ans;
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1])
            continue;
        for(int j=i+1;j<n;j++){
            if(j!=1+1 && a[j]==a[j-1])
                continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                int sum = a[i]+a[j]+a[k]+a[l];
                if(sum == target){
                    vector<int> temp={ a[i],a[j],a[k],a[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && a[k]==a[k-1])
                    k++;
                    while(k<l && a[l]==a[l+1])
                    l--;
                }
            }
        }
    }
    for (auto triplet : ans) {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }
} 
int main(){
    int n,target;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
      cin >> target;
    sum4CodeBrute(a,n,target);
    sum4CodeBetter(a,n,target);
    sum4CodeOptimal(a,n,target);
    return 0;
}
