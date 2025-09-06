// ACCONTS MERGE O(E α(N) + N) ≈ O(E + N) , O(2N)
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank,size,parent;
public:
    DisjointSet(int n){
        size.resize(n+1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUpar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }
    void unionByRank(int u,int v){
        int pu = findUpar(u);
        int pv = findUpar(v);
        if(pu == pv )
            return;
        if(rank[pu] < rank[pv])
            parent[pu] = pv;
        else if(rank[pv] < rank[pu])
            parent[pv] = pu;
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void unionBySize(int u,int v){
        int pu = findUpar(u);
        int pv = findUpar(v);
        if(pu == pv )
            return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class  Solution{
public:
    vector<vector<string>> merge(vector<vector<string>> details){
        int n = details.size();
        DisjointSet ds(n);
        unordered_map <string,int> mapMail;
        // Step 1: Map each email to an index and union accounts
        for(int i=0;i<n;i++){
            for(int j=1;j<details[i].size();j++){
                string mail = details[i][j];
                if(mapMail.find(mail) == mapMail.end())
                    mapMail[mail] = i;
                else
                    ds.unionBySize(i,mapMail[mail]);
            }
        }
        // Step 2: Collect emails per component
        vector<string> mergeMail[n];
        for(auto it:mapMail){
            string mail = it.first;
            int node = ds.findUpar(it.second);
            mergeMail[node].push_back(mail);
        }
        // Step 3: Build final result
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size() == 0)
                continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for(auto &it:mergeMail[i])
                temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};
int main() {
    int n;
    // vector<vector<string>> details = {
    //     {"John","johnsmith@mail.com","john_newyork@mail.com"},
    //     {"John","johnsmith@mail.com","john00@mail.com"},
    //     {"Mary","mary@mail.com"},
    //     {"John","johnnybravo@mail.com"}
    // };
    // vector<vector<string>> res = sol.merge(details);
    cout << "Enter number of accounts: ";
    cin >> n;
    vector<vector<string>> details(n);
    cout << "Enter each account details:\n";
    cout << "Format -> Name email1 email2 ... emailK\n";
    for (int i = 0; i < n; i++) {
        int m;
        cout << "Enter number of emails for account " << i+1 << ": ";
        cin >> m;
        details[i].resize(m+1);
        cout << "Enter name: ";
        cin >> details[i][0];
        cout << "Enter " << m << " emails: ";
        for (int j = 1; j <= m; j++) cin >> details[i][j];
    }
    Solution sol;
    vector<vector<string>> res = sol.merge(details);
    cout << "\nMerged Accounts:\n";
    for (auto &acc : res) {
        for (auto &s : acc) cout << s << " ";
        cout << "\n";
    }
    return 0;
}

// Enter number of accounts: 4
// Enter number of emails for account 1: 2
// Enter name: John
// Enter 2 emails: johnsmith@mail.com john_newyork@mail.com

// Enter number of emails for account 2: 2
// Enter name: John
// Enter 2 emails: johnsmith@mail.com john00@mail.com

// Enter number of emails for account 3: 1
// Enter name: Mary
// Enter 1 emails: mary@mail.com

// Enter number of emails for account 4: 1
// Enter name: John
// Enter 1 emails: johnnybravo@mail.com
