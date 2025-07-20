//3 CODE SUM
#include<bits/stdc++.h>
using namespace std;
//brute O(n*n*n)
void sum3CodeBrute(int a[],int n){
    set<vector<int>> s;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]+a[j]+a[k] == 0){
                    vector<int> temp={ a[i],a[j],a[k]};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
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
//better O(n*n)+O(log m)-set
void sum3CodeBetter(int a[],int n){
    set<vector<int>> s;
    for(int i=0;i<n;i++){
        unordered_set <int> hashset;
        for(int j=i+1;j<n;j++){
            int third = -(a[i]+a[j]);
            if(hashset.find(third)!=hashset.end()){
                vector<int> temp={ a[i],a[j],third};
                sort(temp.begin(),temp.end());
                s.insert(temp);
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
//optimal O(n log n)+O(n*n)
void sum3CodeOptimal(int a[],int n){
    vector<vector<int>> ans;
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1])
            continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = a[i]+a[j]+a[k];
            if(sum<0)
                j++;
            else if(sum>0)
                k--;
            else{
                vector<int> temp={ a[i],a[j],a[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && a[j]==a[j-1])
                j++;
                while(j<k && a[k]==a[k+1])
                k--;
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
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    // sum3CodeBrute(a,n);
    // sum3CodeBetter(a,n);
    sum3CodeOptimal(a,n);
    return 0;
}
