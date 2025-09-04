//WORD LADDER  Optimised   O(N*L+P*L) , O(N+P*L)
//leet code
#include<bits/stdc++.h>
using namespace std;
void dfs(string word,vector<string> &seq,string &b,
         unordered_map<string,int> &m, vector<vector<string>> &ans){
    if(word == b){
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        reverse(seq.begin(),seq.end());
        return;
    }
    int steps = m[word];
    int n = word.size();
    for(int i=0;i<n;i++){
        char original = word[i];
        for(char ch='a';ch<='z';ch++){
            word[i] = ch;
            if(m.find(word) != m.end() && m[word]+1 == steps){
                seq.push_back(word);
                dfs(word,seq, b, m, ans);
                seq.pop_back();
            }
        }
        word[i] = original;
    }
}
vector<vector<string>> wordLadderSeq(string beginword,string endword,vector<string> &wordList){
    unordered_set<string> s(wordList.begin(),wordList.end());
     unordered_map<string,int> m;
    vector<vector<string>> ans;
    queue<string> q;
    q.push(beginword);
    m[beginword] = 1;
    int n = beginword.size();
    while(!q.empty()){
        string word = q.front();
        int steps = m[word];
        q.pop();
        for(int i=0;i<n;i++){
            char original = word[i];
        }
        for(int i=0;i<word.size();i++){
            char original = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i] = ch;
                if(s.count(word)){
                    q.push(word);
                    s.erase(word);
                    m[word] = steps+1;
                }
            }
            word[i] = original;
        }
    }
    if(m.find(endword)!=m.end()){
        vector<string> seq;
        seq.push_back(endword);
        dfs(endword,seq,beginword,m,ans);
    }
    return ans;
}
int main() {
    string start = "hit";
    string target = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>>  result = wordLadderSeq(start, target, wordList);
     cout << "All shortest transformation sequences:\n";
    for(auto seq : result){
        for(auto w : seq){
            cout << w << " ";
        }
        cout << "\n";
    }
    return 0;
}