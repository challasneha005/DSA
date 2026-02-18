//LONGEST CONSECUTIVE SEQUENCE

#include<bits/stdc++.h>
using namespace std;

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

// TIME COMPLEXITY: O(n), where n is the size of the input array.
// SPACE COMPLEXITY: O(n), as we are using a set to store the elements of the array.

/*
APPROACH:-
To find the length of the longest consecutive elements sequence, we can follow these steps:
1. Create a set to store all the elements of the array.
2. Iterate through the array and insert each element into the set.
3. For each element, check if its previous consecutive element (num-1) exists in the set. If it does not exist, it means the current element is the starting element of a sequence.
4. For each starting element, keep incrementing the current element (num+1) and checking if it exists in the set. This will help find the consecutive elements in the sequence.
5. Keep track of the maximum length of consecutive elements encountered.
6. Return the maximum length as the result.
*/

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

int longestConsecutive(int nums[],int n){
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[nums[i]]++;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int start = nums[i];
        // check whehter this can be the start of the subsequence
        if (mp.find(nums[i] - 1) == mp.end()){
            int temp = 1;
            int nxt = nums[i];
            while (mp.find(nxt + 1) != mp.end()){
                temp++;
                nxt++;
            }
            ans = max(ans, temp);
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    // longestSequenceBrute(a,n);
    // longestSequenceBetter(a,n);
    // longestSequenceOptimal(a,n);
    cout << longestConsecutive(a,n);
    return 0;
}

// INPUT
// 7
// 100 4 200 1 3 2 101