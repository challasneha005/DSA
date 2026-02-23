//FIND THE MISSING & REPEATING NUMBER

#include<bits/stdc++.h>
using namespace std;

 
//brute O(n*n)
void missingRepeatNumberBrute(int a[],int n){
    int repeat = -1, missing = -1;
    for(int i = 1;i<=n;i++){
        int count = 0;
        for(int j = 0;j<n;j++){
            if(a[j] == i)
                count++;
        }
        if(count == 2) 
            repeat = i;
        else if(count == 0)
            missing = i;
        if(repeat != -1 && missing != -1)
            break;
    }
    cout << "Repeating number: " << repeat << endl;
    cout << "Missing number: " << missing << endl;
}

//better using hash O(2n)
void missingRepeatNumberHash(int a[],int n){
    int hash[n+1] = {0};
    int repeat = -1,missing = -1;
    for(int i=0;i<n;i++)
        hash[a[i]]++;
    for(int i =1;i<=n;i++){
        if(hash[i]==2)
            repeat = i;
        else if(hash[i]==0)
            missing = i;
        if(repeat != -1 && missing != -1)
            break;
    }
    cout << "Repeating number: " << repeat << endl;
    cout << "Missing number: " << missing << endl;
}

//optimal sum O(n)

// TIME COMPLEXITY: O(N), where N is the size of the array.
// SPACE COMPLEXITY: O(1).

/*
APPROACH:
To find the missing and repeating numbers in the given unsorted array, we can utilize the properties of summation and sum of squares. Let's denote the missing number as 'x' and the repeating number as 'y'.
1. Calculate the optimal sum 'optSum' using the formula: optSum = N * (N + 1) / 2, where N is the size of the array.
2. Calculate the optimal sum of squares 'opt2Sum' using the formula: opt2Sum = N * (N + 1) * (2 * N + 1) / 6.
3. Calculate the actual sum 'actSum' and actual sum of squares 'act2Sum' of the given array.
4. Find the difference between the optimal sum and the actual sum: xMinusY = optSum - actSum.
5. Find the difference between the optimal sum of squares and the actual sum of squares: x2MinusY2 = opt2Sum - act2Sum.
6. Calculate the sum of 'x' and 'y': xPlusY = x2MinusY2 / xMinusY.
7. Calculate 'x' and 'y' using the equations: x = (xPlusY + xMinusY) / 2 and y = xPlusY - x.
*/

void missingRepeatNumberOptimalSum(int a[],int n){
    long long Sn = (n*(n+1))/2;
    long long S2n = (n*(n+1)*(2*n+1))/6;
    long long S = 0,S2 =0;
    for(int i=0;i<n;i++){
        S += a[i];
        S2 += (long long)a[i]* (long long)a[i];
    } //x repeat y missing
    int val1 = S-Sn; //x-y
    int val2 = S2 - S2n; 
    val2 = val2/val1; //x+y
    long long x = (val1+val2) /2;
    long long y = x-val1;
    cout << "Repeating number: " << x << endl;
    cout << "Missing number: " << y << endl;
}

//optimal xr O(n)
void missingRepeatNumberOptimalXor(int a[],int n){
    int xr = 0;
    for(int i=0;i<n;i++){
        xr = xr ^ a[i];
        xr = xr ^ (i+1);
    }
    int bitNo = 0; //number = xr ^ & ~(xr-1)
    while(1){
        if((xr & (1<<bitNo)) !=0)
            break;
        bitNo++;
    }
    int zero = 0;
    int one = 0;
    for(int i = 0;i<n;i++){
        if((a[i] & (1<< bitNo))!=0)
            one = one ^ a[i];
        else
            zero = zero ^ a[i]; 
    }
    for (int i = 1; i <= n; i++) {
        if ((i & (1 << bitNo)) != 0)
            one ^= i;
        else
            zero ^= i;
    }
    int cnt = 0;
    for(int i=0;i<n;i++)
        if(a[i] == zero )
            cnt++;
    if(cnt == 2){
        cout << "Repeating number: " << zero << endl;
        cout << "Missing number: " << one << endl;
    }
    else{
        cout << "Repeating number: " << one << endl;
        cout << "Missing number: " << zero << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++)
        cin >> arr[i];
    // missingRepeatNumberBrute(arr,n);
    // missingRepeatNumberHash(arr,n);
    // missingRepeatNumberOptimalSum(arr,n);
     missingRepeatNumberOptimalXor(arr,n);
    return 0;
}


// INPUT
// 2 2
