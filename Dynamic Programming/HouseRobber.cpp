//HOUSE ROBBER
#include<bits/stdc++.h>
using namespace std;
//space optimization O(n),O(1) 
int maxNonAdjSum(vector<int> &a){
    int n = a.size();
    int prev1 = a[0];
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int take = a[i];
        if(i>1)
            take+=prev2;
        int nontake = 0+prev1;
        int curi = max(take,nontake);
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}
long long int houseRobber(vector<int> &a){
    int n = a.size();
    vector<int> temp1,temp2;
    if(n==1)
        return a[0];
    for(int i=0;i<n;i++){
        if(i!=0)
            temp1.push_back(a[i]);
        if(i!=n-1)
            temp2.push_back(a[i]);
    }
    return max(maxNonAdjSum(temp1),maxNonAdjSum(temp2));
}

int main(){
      int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << houseRobber(a);
    return 0;
}