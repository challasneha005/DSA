#include<bits/stdc++.h>
using namespace std;
void sumN(int i,int sum){  //parameterized
    if (i<1){
        cout << "sum : "<< sum << endl;
        return ;
    }
    sumN(i-1,sum+i);
}

int sumNum(int n){ //functional
    if (n==0) return 0;
    return n + (sumNum(n-1));
}

void factorialN(int i,int fact){  //parameterized
    if (i<1){
        cout << "Factorial : "<< fact << endl;
        return ;
    }
    factorialN(i-1,fact*i);
}

int factorial(int n){  //functional
    if (n==0 || n==1) return 1;
    return n* (factorial(n-1));
}
int main(){
    int n;
    cin >> n ;
    sumN(n,0);
    cout << "Sum : " << sumNum(n) << endl;
    factorialN(n,1);
    cout << "Factorial :  " << factorial(n) ;
    return 0;
}
 