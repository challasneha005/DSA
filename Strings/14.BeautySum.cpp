// BEAUTY SUM
// difference in frequencies between the most frequent and least frequent characters

// aabcb
// 5--substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n*n)
// SPACE COMPLEXITY : O(26)  

/*
Approach:
1. Initialize a variable `ans` to store the total beauty sum.
2. Iterate over the string `s` with the first loop, starting from index `i`.
   - Initialize a frequency array `freq` of size 26, initialized with zeros.
   - Iterate over the string `s` with the second loop, starting from index `j` equal to `i`.
      - Increment the frequency of the character `s[j]` in the `freq` array.
      - Calculate the difference between the highest and lowest frequencies in the `freq` array and add it to `ans`.
3. Return the value of `ans` as the final result
*/

int getMaxMin(vector<int> &freq){
    int maxi = INT_MIN,mini = INT_MAX;
    for(auto i:freq){
        maxi = max(maxi,i);
        if(i!=0)
            mini = min(mini,i);
    }
    return (mini==INT_MAX) ? 0 : maxi-mini;
}

int beautySum(string&s){
    int count = 0;
    for(int i=0;i<s.size();i++){
        vector<int> freq(26,0);
        for(int j=i;j<s.size();j++){
            freq[s[j] - 'a']++;
            int maxmin = getMaxMin(freq);
            count += maxmin;
        }
    }
    return count;
}
 
int main(){
    string s;
    cin >> s  ;
    cout << beautySum(s)<< "\n";
    return 0;
}

// INPUT 
// aabcbaa