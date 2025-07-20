#include<bits/stdc++.h>
using namespace std;
//LONGEST CONSECUTIVE SEQUENCE
//brute O(n*n)
bool linearSearch(int a[],int n,int y){
    for(int i=0;i<n;i++){
        if(a[i]== y)
            return true;
    }
    return false;
}
void longestSequenceBrute(int a[],int n){
    int longest = 1;
    for(int i=0;i<n;i++){
        int x = a[i];
        int cnt = 1;
        while(linearSearch(a,n,x+1)==true){
            x = x+1;
            cnt = cnt+1;
        }
        longest = max(longest, cnt);
    }
    cout << "Longest consecutive sequence: " << longest << endl;
}
//better O(n log n)+O(n)
void longestSequenceBetter(int a[],int n){
    sort(a,a+n);
    int longest = 1;
    int cntCur = 0;
    int lastSmaller = INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]-1 == lastSmaller){
            cntCur = cntCur+1;
            lastSmaller = a[i];
        }
        else if(a[i] != lastSmaller){
            cntCur = 1;
            lastSmaller = a[i];
        }
    longest = max(longest,cntCur);
    }
    cout << "Longest consecutive sequence: " << longest << endl;
}
//Optimal O(3n)
void longestSequenceOptimal(int a[],int n){
    if (n==0) 
        return;
    int longest = 1;
    unordered_set <int> s;
    for(int i=0;i<n;i++)
        s.insert(a[i]);
    for(auto it:s){
        int cnt = 1;
        int x = it;
        while(s.find(x+1) != s.end()){
            x=x+1;
            cnt = cnt+1;
        }
        longest = max(longest,cnt);
    }
    cout << "Longest consecutive sequence: " << longest << endl;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    // longestSequenceBrute(a,n);
    // longestSequenceBetter(a,n);
    longestSequenceOptimal(a,n);
    return 0;
}