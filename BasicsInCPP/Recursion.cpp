#include<bits/stdc++.h>
using namespace std;
void name(int i,int n){
    if (i>n) return;
    cout << "Sneha\n";
    name(i+1,n);  //time O(n)
}

void printNum(int i,int n){
    if (i>n) return;
    cout << i << " ";
    printNum(i+1,n);
}

void Num(int i,int n){
    if (i<1) return;
    Num(i-1,n);
    cout << i << " ";
}

void printNumRev(int n){
    if (n==0) return ;
    cout << n << " ";
    printNumRev(n-1);
}

void NumRev(int i,int n){
    if (i>n) return ;
    NumRev(i+1,n);
    cout << i << " ";
}

int main(){
    int n;
    cin >> n ;
    name(1,n);
    printNum(1,n); cout << endl;
    Num(n,n);  cout << endl; //see difference of cout line
    printNumRev(n); cout << endl;
    NumRev(1,n); cout << endl;
    
    return 0;
}