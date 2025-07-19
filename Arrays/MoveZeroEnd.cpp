//MOVING ZERO TO END
//brute  O(2n)
void moveZeroesBrute(int arr[],int n){
    vector <int> temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0)
            temp.push_back(arr[i]);
    }
    for(int i=0;i<temp.size();i++)
        arr[i]=temp[i];
    int nonzeroIndex = temp.size();
    for(int i=nonzeroIndex;i<n;i++)
        arr[i]=0;
     
}
//optimal O(n)
void moveZeroesOptimal(int arr[],int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            j=i;
            break;
        }
    }
    if(j==-1) cout<<"no zeroes";
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    //  moveZeroesBrute(arr, n);
    moveZeroesOptimal(arr,n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
