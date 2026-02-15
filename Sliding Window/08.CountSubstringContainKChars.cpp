// NO.oF SUBSTRINGS CONTAINING ALL THREE CHARACTERS

#include<bits/stdc++.h>
using namespace std;

// brute O(n*n) , O(1)
int maxCountSubStringsBrute(string &s){
    int n = s.size();
    int count = 0;
    for(int i=0;i<n;i++){
        int hash[3] = {0};
        for(int j=i;j<n;j++){
            hash[s[j] - 'a'] = 1;
            if(hash[0]+hash[1]+hash[2] == 3)
                count++;
        }
    }
    return count;
}

// better O(*n*n) , O(1)
int maxCountSubStringsBetter(string &s){
    int n = s.size();
    int count = 0;
    for(int i=0;i<n;i++){
        int hash[3] = {0};
        for(int j=i;j<n;j++){
            hash[s[j]- 'a'] = 1;
            if(hash[0]+hash[1]+hash[2] == 3){
                count += (n-j);
                break;
            }
        }
    }
    return count;
}

// Optimal 

//  TIME COMPLEXITY O(n)
//  SPACE COMPLEXITY O(1)

/*
APPROACH 
1. Create a function maxCountSubStringsOptimal that takes a string s.
2. Initialize an array lastseen of size 3 with all values set to -1 to store the last index of characters a, b, and c.
3. Initialize a variable count to store the total number of valid substrings.
4. Traverse the string from left to right using an index i.
5. For each character at index i:
    -Update its last seen position in the lastseen array.
6. Check whether all three characters (a, b, c) have appeared at least once:
    -If yes, find the minimum index among their last seen positions.
7. Add 1 + minimum last seen index to count, which represents the number of valid substrings ending at index i.
8. Continue the process until the end of the string.
9. Return the final value of count.
*/

int maxCountSubStringsOptimal(string &s){
    int n = s.size();
    int count = 0, lastseen[3] = {-1,-1,-1};
    for(int i=0;i<n;i++){
        lastseen[s[i] - 'a'] = i;
        if(lastseen[0]!= -1 && lastseen[1]!= -1 && lastseen[2]!= -1)
            count += 1+min({lastseen[0],lastseen[1],lastseen[2]});
    }
    return count;
}

// Another method  for k characters best...
int countOfUnvalidSubstrings(string& s) {
    unordered_map<char, int> mp;
    int start = 0, ans = 0;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
        while (mp.size() > 2) {
            mp[s[start]]--;
            if (mp[s[start]] == 0)
                mp.erase(s[start]);
            start++;
        }  
        ans += i - start + 1;
    }
    return ans;
}
int numberOfSubstrings(string s) {
    long long n = s.size();
    int cntOfTotalSubstrings = (n * (n + 1)) / 2;
    return cntOfTotalSubstrings - countOfUnvalidSubstrings(s);
}

int main(){
    string s;
    cin >> s;
    cout << maxCountSubStringsBrute(s) << "\n";
    cout << maxCountSubStringsBetter(s)<< "\n";
    cout << maxCountSubStringsOptimal(s)<< "\n";
    return 0;
}

// INPUT
// bbacba