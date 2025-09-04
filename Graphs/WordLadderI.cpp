//WORD LADDER I O(n*l) , O(n*l)
//Brute
#include<bits/stdc++.h>
using namespace std;
int wordLadder(string startword,string target,vector<string> &wordList){
    unordered_set<string> s(wordList.begin(), wordList.end());
    queue<pair<string,int>> q;
    q.push({startword,1});
    s.erase(startword);
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == target)
            return steps;
        for(int i=0;i<word.size();i++){
            char original = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i] = ch;
                if(s.find(word)!=s.end()){
                    s.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}
int main() {
    string start = "hit";
    string target = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    int result = wordLadder(start, target, wordList);
    cout << "Shortest transformation length: " << result << endl;
    return 0;
}