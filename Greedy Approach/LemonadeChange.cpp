// LEMONADE CHANGE O(n) , O(2)
#include<bits/stdc++.h>
using namespace std;
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
