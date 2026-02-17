// MAJORITY ELEMENT 

#include<bits/stdc++.h>
using namespace std;

//brute O(n*n)
int majorityElementBrute(int a[],int n){
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(a[i]==a[j])
                count++;
        }
        if(count>n/2)
            return a[i];
    }
    return -1;
}

//better using hashmap O(nlog n)-ordered,  O(n)-unordered
int majorityElementBetter(int a[],int n){
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
        m[a[i]]++;
    for(auto it:m){
        if(it.second > n/2)
            return it.first;
    }
    return -1;
}

//Optimal

// TIME COMPLEXITY = O(N)
// SPACE COMPLEXITY = O(0)

//MOORE's VOTING ALGORITHM O(n)+ O(N) <-if exits 
/*
APROACH:-
-> Initialize two variables: candidate and count. Set candidate to the first element of the array, and count to 1.
-> Iterate through the array starting from the second element:
    If the current element is equal to the candidate, increment the count by 1.
    If the current element is different from the candidate, decrement the count by 1.
    If the count becomes 0, update the candidate to the current element and set the count to 1 again.
-> After the iteration, the candidate variable will hold the majority element.
Return the candidate as the result.
*/

int majorityElementOptimalMoore(int a[],int n){
    int count=0;
    int element;
    for(int i=0;i<n;i++){
        if(count==0){
            element=a[i];
            count++;
        }
        else if (a[i] == element)
            count++;
        else
            count--;
    }
    int count1 = 0;
    for(int i=0;i<n;i++){
        if(a[i] == element)
            count1++;
    }
    if(count1 > n/2)
        return element;
    return -1;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    // cout << majorityElementBrute(a,n);
    // cout << majorityElementBetter(a,n);
    cout << majorityElementOptimalMoore(a,n);
    return 0;
}

// INPUT
// 7
// 1 2 2 1 1 2 2