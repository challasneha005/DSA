// SORT CHARACTERS BY FREQUENCY

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n log n)
// SPACE COMPLEXITY : O(n)  

/*
Approach:
1. Create a frequency map to count the occurrences of each character in the string.
2. Use a priority queue to sort the characters based on their frequencies in decreasing order.
3. Iterate through the priority queue and append the characters to a new string according to their frequencies.
*/

string frequencySort(string &s){
    unordered_map<char,int> mp;
    for(auto c:s)
        mp[c]++;
    priority_queue<pair<int,char>> pq;
    for(auto it:mp)
        pq.push({it.second,it.first});
    string ans ="";
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        ans.append(cur.first,cur.second);
    }
    return ans;
}
 
int main(){
    string s;
    cin >> s  ;
    cout << frequencySort(s)<< "\n";
    return 0;
}

// INPUT 
// applecake