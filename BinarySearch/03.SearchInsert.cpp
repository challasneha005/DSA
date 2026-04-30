//SEARCH INSERT

#include<bits/stdc++.h>
using namespace std;

// Using lowerbound

/*
APPROACH:
We can use the lower_bound function from the C++ standard library to find the index where the target should be inserted. The lower_bound function returns an iterator pointing to the first element that is not less than the target. By subtracting the beginning iterator from the lower_bound iterator, we get the index where the target should be inserted.
*/

int searchInsert(vector<int>& nums, int target) {
    auto ans = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    return ans;
}

//Iterative O(n),space - O(1) //just at lower bound
int searchInsert(int a[], int n, int target) {
    int ans = n;
    int low = 0,high = n-1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(a[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main(){
    int n,target;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> target;
    int index = searchInsert(a,n,target);
    cout << "Insert at: "<< index << endl;
    return 0;
}


// INPUT
// 8 
// -1 2 3 5 6 7 9 11
// 3
