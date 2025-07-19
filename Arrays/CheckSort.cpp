//CHECK ARRAY SORTED OR NOT
bool isSorted(int a[],int n){
    for(int i=1;i<n;i++){
        if(a[i] >= a[i-1]) {}
        else return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    if (isSorted(arr,n))
        cout << "True";
    else cout << "False";
}
