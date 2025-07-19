//count no.of digits
#include<bits/stdc++.h>
using namespace std;
int count(int n){
    int c=0;
    while(n>0){
        c=c+1;
        n=n/10;
    }
    return c;
}

int counts(int n){
    int c= (int) (log10(n)+1);
    return c;
}

int reverseNum(int n){
    int revNum = 0;
    while(n>0){
        int l=n%10;
        revNum = (revNum *10) +l;
        n=n/10; 
    }
    return revNum ;
}

void Palindrome(int n){
    reverseNum(n);
    if(n==reverseNum(n)) 
        cout << "Palindrome: True" << endl;
    else cout << "Palindrome: False" << endl;

}

//Arm strong = number is power of digits = sum of digits power of digit
void ArmStrong(int n){
    int sum =0;
    int digits =0;
    //count digit
    int temp=n;
    digits = count(temp);
    //sum of digits
    temp=n;
    while(temp!=0){
        int digit = temp%10;
        sum += pow(digit,digits);
        temp /=10;
    }
    if (sum ==n) cout << "ArmStrong : True" << endl;
    else cout << "ArmStrong : False" << endl;

}

void PrintDivisor(int n){
    cout << "Factors : " ;
    int num=n;
    for(int i=1;i<=num;i++){
        if (num%i ==0) cout << i << " ";
    }
    cout << endl; //time complexity O(n) 
}

void PrintDivisors(int n){
    cout << "Factors : " ;
    vector <int> l;
    int num=n;
    for(int i=1;i<=sqrt(num);i++){
        if (num %i == 0){ 
            l.push_back(i);
            if ((num/i) != i){
                l.push_back(n/i);
            }
        }
    }
    // O(no of factors * log(no.of factors))
    sort(l.begin(),l.end());
    for(auto it :l) cout << it << " ";
    cout << endl; // total ..time O(sqrt(n ))
}

void CheckPrime(int n){
    int c=0;
    for(int i=1;i*i<=n;i++){
        if (n%i==0) {
            c++;
            if((n%i) != i) c++;
        }
    }
    if (c==2) cout << n << " is Prime";
    else cout << n << " is not prime";
}

void gcd(){
    int a,b;
    cin >> a >> b;
    int gcd =1;
    for(int i=1 ;i<=min(a,b);i++){
        if (a%i==0 && b%i ==0){
            gcd =i;
        }
    }
    cout << "Gcd of "<< a << " & " << b << " is : " << gcd << endl;
    // time O(min(a,b))
}

void euclideanGcd(){
    int a,b;
    cin >> a >> b;
    while(a!=0 && b!=0){
        if (a>=b) a=a%b;
        else b=b%a;
    }
    if (a==0) cout << "Gcd is : " << b;
    else  cout << "Gcd is : " << a;
    // time O(log min(a,b))
}
int main(){
    int n;
    cin >> n;
    cout << "using nrml : "<< count(n) << endl;
    cout << "using log : "<< counts(n) << endl;
    cout << "Reverse Num: "<< reverseNum(n) << endl;
    Palindrome(n);
    ArmStrong(n);
    PrintDivisor(n);
    PrintDivisors(n);
    CheckPrime(n);
    euclideanGcd();
}