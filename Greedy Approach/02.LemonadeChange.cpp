// LEMONADE CHANGE O(n) , O(2)

#include<bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(2)

/*
APPROACH:
- We maintain two counters: `fiveCnt` to count the number of $5 bills and `tenCnt` to count the number of $10 bills we have.
- We iterate over the bills array.
- For each bill, we check if it is $5, $10, or $20.
  - If it is $5, we increment the `fiveCnt`.
  - If it is $10, we increment the `tenCnt` and decrement the `fiveCnt` since we need to give back a $5 bill as change.
  - If it is $20, we try to give back a $10 bill and a $5 bill as change if we have them. Otherwise, we try to give back three $5 bills.
- After each transaction, we check if the `fiveCnt` is negative, which means we have given a $5 bill that we actually don't have. In this case, we return false.
- If we successfully process all the bills without any negative `fiveCnt`, we return true.
*/

bool lemonadeChange(vector<int> &a){
    int five = 0, ten = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] == 5)
            five+=1;
        else if(a[i]==10){
            if(five){
                five-=1;
                ten+=1;
            }
            else    
                return false;
        }   
        else{
            if(ten && five){
                ten-=1;
                five-=1;
            }
            else if(five>=3)
                five-=3;
            else
                return false;
        }
    }
    return true;
}

int main(){
    vector<int> a = {5,5,10,20,5};
    cout << lemonadeChange(a); 
    return 0;
}
