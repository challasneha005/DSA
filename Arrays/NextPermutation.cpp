//NEXT PERMUTATION
//brute generate all ,linearsearch ,nect index--O(n*n*n)
//better STL  
void nextPermute(int a[],int n){
    next_permutation(a,a+n);
}
//using algorithm O(3n)
void nextPermuteGenerator(int a[],int n){
    int ind = -1;
    for(int i=n-2;i>=0;i--){
        if(a[i]<a[i+1]){
            ind = i;
            break;
        }
    }
    if (ind == -1){ 
        reverse(a, a + n);
        return;
    }
    for(int i=n-1;i>ind;i--){
        if(a[i]>a[ind]){
            swap(a[i],a[ind]);
            break;            
        }
    }
    reverse(a,ind+1,n-1);
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    //nextPermute(a,n);
    nextPermuteGenerator(a,n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
