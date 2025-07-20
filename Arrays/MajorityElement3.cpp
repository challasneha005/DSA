//MAJORITY ELEMENTS >n/3
#include<bits/stdc++.h>
using namespace std;
//brute O(n*n)
void majorityElement3Brute(int a[], int n){
    vector<int> l;
    for(int i=0;i<n;i++){
        // If the element is already in the result list, skip it
        if (!l.empty() && (l[0] == a[i] || (l.size() > 1 && l[1] == a[i])))
            continue;
        int count = 0;
        for(int j=0;j<n;j++){
            if(a[i]==a[j])
            count++;
        }
        if(count > n/3)
            l.push_back(a[i]);
    if (l.size()==2) 
        break;
    }
    for (int val : l)
        cout << val << " ";
    cout << endl;
}
//better using map O(n log n)-ordered O(n)-unordered
void majorityElement3Better(int a[], int n){
    vector<int> ls;
    map<int,int> map;
    int mini = (int)(n/3)+1;
    for(int i=0;i<n;i++){
        map[a[i]]++;
        if(map[a[i]] == mini)
            ls.push_back(a[i]);
        if(ls.size() == 2)
            break;
    }
    sort(ls.begin(),ls.end());
    for (int val : ls)
        cout << val << " ";
    cout << endl;
}
//Optimal O(2n)
void majorityElement3Optimal(int a[], int n){
    int cnt1 = 0,cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for(int i=0;i<n;i++){
        if(cnt1 == 0 && a[i]!=el2){
            el1 = a[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 && a[i]!=el1){
            el2 = a[i];
            cnt2 = 1;
        }
        else if(a[i] == el1)
            cnt1++;
        else if(a[i] == el2)
            cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ls;
    cnt1 = 0,cnt2 = 0;
    for(int i=0;i<n;i++){
        if(el1 == a[i]) 
            cnt1++;
        if(el2 == a[i])
            cnt2++;
    }  
    int mini = (int)(n/3)+1;
    if(cnt1 >= mini)
        ls.push_back(el1);
    if(cnt2 >= mini)
        ls.push_back(el2);
    sort(ls.begin(),ls.end());
    for (int val : ls)
        cout << val << " ";
    cout << endl;
}     
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    // majorityElement3Brute(a,n);
    // majorityElement3Better(a,n);
    majorityElement3Optimal(a,n);
    return 0;
}
