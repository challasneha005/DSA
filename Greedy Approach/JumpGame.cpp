// JUMP GAME - Able to reach end
#include<bits/stdc++.h>
using namespace std;
bool reachEnd(vector<int> &a){
    int maxInd = 0;
    for(int i=0;i<a.size();i++){
        if(i>maxInd)
            return false;
        maxInd = max(maxInd,i+a[i]);
    }
    return true;
}
int main(){
    vector<int> a = {1,2,4,1,1,0,2,5};
    cout << reachEnd(a);
    return 0;
}