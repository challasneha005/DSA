//PASCAL TRIANGLE

#include<bits/stdc++.h>
using namespace std;

// row,col given  element =?
int nCr(int n,int r){
    if(r>n)
        return 0;
    int res = 1;
    for(int i=0;i<r;i++){
        // coefficient = coefficient * (rowIndex - col + 1) / col;
        res = res * (n-i);
        res = res / (i+1);
    }
    return res ;
}

/*
APPROACH:**
To generate the `rowIndex`th row of Pascal's triangle, we can use the property that each 
number is the sum of the two numbers directly above it. We start with the base case of the first row, 
which is `[1]`. Then, for each subsequent row, we calculate the elements using the formula 
`C(n, k) = C(n-1, k-1) * (n-k+1) / k`, where `C(n, k)` represents the binomial coefficient
*/
// nth row elements?
void nthRowPascal(int n){
    for(int c=0;c<=n;c++)
        cout << nCr(n,c) << " ";
    cout << endl;
}
// entire triangle
void pascalTriangle(int n){
    for(int row=0;row<n;row++)
        nthRowPascal(row);
}
vector<vector<int>> pascal(int n){  //use void if no return
    vector<vector<int>> res(n);
    for(int row=0;row<n;row++){
        vector<int> templist;
        for(int col=0;col<= row;col++)
            templist.push_back(nCr(row,col));
        res.push_back(templist);
    }
    for (auto row : res) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
    return res;
}
int main(){
    //1st problem
    int n,r;
    cout << "enter row & col to get element: ";
    cin >> n >> r;
    cout << "Element : " << nCr(n-1,r-1);

    //2nd problem
    int row;
    cout << "enter row to get nth row elements: ";
    cin >> row;
    nthRowPascal(row-1);

    //3rd problem
    int num;
    cout << "enter number to get entire triangle: ";
    cin >> num;
    //pascalTriangle(n);
    pascal(n);
    return 0;
}

// INPUT
// enter row & col to get element: 5 3
// Element : 6
// enter row to get nth row elements: 5
// 1 4 6 4 1
// enter number to get entire triangle: 5
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
