 // JOB SEQUENCING O(n log n*maxdl) , O(maxDl)

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY: O(n log n*maxdl)
// SPACE COMPLEXITY : O(maxdl)

/*
APPROACH:
1. Sort all jobs in descending order of profit so that more profitable jobs
   are considered first.
2. Find the maximum deadline among all jobs to determine the number of
   available time slots.
3. Create an array (hash) to represent time slots, where each index denotes
   a unit of time and -1 indicates a free slot.
4. Traverse the sorted jobs one by one and for each job, try to schedule it
   at the latest available slot on or before its deadline.
5. If a free slot is found, assign the job to that slot, increment the job
   count, and add its profit to the total profit.
6. Continue this process until all jobs are processed.
7. Return the total number of jobs scheduled and the maximum profit obtained.
*/


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
