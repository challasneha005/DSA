// SHORTEST JOB FIRST..RETURN AVG WAITING TIME  O(n+n log n), O(1)
// Non-Preemptive scheduling solution.

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n log n)
// SPACE COMPLEXITY : O(1)

/*
APPROACH:
1. Sort the array of job burst times in ascending order to follow the Shortest Job First (SJF) scheduling strategy.
2. Initialize a variable to keep track of the total time elapsed so far.
3. For each job, add the current elapsed time to the total waiting time, since the job has to wait for all previously executed jobs.
4. Update the elapsed time by adding the burst time of the current job.
5.After processing all jobs, calculate and return the average waiting time by dividing the total waiting time by the number of jobs.
*/

long long SJFavgwt(vector<int> &a){
    sort(a.begin(),a.end());
    int t=0,waitingTime = 0;
    for(int i=0;i<a.size();i++){
        waitingTime +=t;
        t+=a[i];
    }
    return waitingTime/a.size();
}

int main(){
    vector<int> a = {4,3,7,1,2};
    cout << SJFavgwt(a);
    return 0;
}
