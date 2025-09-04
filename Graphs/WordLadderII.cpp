//WORD LADDER II O(26 * N * L + P * K) , O(N * L + P * K)
//Brute BFS 
#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> wordLadderSeq(string beginword,string endword,vector<string> &wordList){
    unordered_set<string> s(wordList.begin(),wordList.end());
    queue<vector<string>> q;
    q.push({beginword});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginword);
    int level = 0;
    vector<vector<string>> ans;
    while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();
        if(vec.size() > level){
            level++;
            for(auto it:usedOnLevel)
                s.erase(it);
            usedOnLevel.clear();
        }
        string word = vec.back();
        if(word == endword){
            if(ans.size() == 0)
                ans.push_back(vec);
            else if(ans[0].size() == vec.size())
                ans.push_back(vec);
        }
        for(int i=0;i<word.size();i++){
            char original = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i] = ch;
                if(s.count(word)>0){
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
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


