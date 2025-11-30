// JOB SEQUENCING
#include<bits/stdc++.h>
using namespace std;
struct Job {
    int id;
    int deadline;
    int profit;
};
bool comp(Job value1,Job value2){
    return value1.profit > value2.profit;
}
pair<int,int> jobSequencing(vector<Job> &a){
    int n=a.size();
    sort(a.begin(),a.end(),comp);
    int totalProfit = 0,cnt = 0;
    int maxDl = -1;
    for(int i=0;i<n;i++)
        maxDl =  max(maxDl,a[i].deadline);
    vector<int> hash(maxDl + 1, -1);
    for(int i=0;i<n;i++){
        for(int j=a[i].deadline;j>0;j--){
            if(hash[j] == -1){
                cnt+=1;
                hash[j] = a[i].id;
                totalProfit+= a[i].profit;
                break;
            }
        }
    }
    return {cnt,totalProfit};
}
int main() {

    vector<Job> jobs = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };

    auto ans = jobSequencing(jobs);

    cout << "Number of Jobs Done: " << ans.first << endl;
    cout << "Total Profit: " << ans.second << endl;

    return 0;
}