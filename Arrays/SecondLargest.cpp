//SECOND LARGEST ELEMENT WITHOUT SORT
//brute with sort    (O(n log n))
// for(i=n-1;i>=0;i--){
//     if(arr[i]!= large){
//         slarge=arr[i];
//         break;
//     }
// }

//better without sort O(2n)
// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//         cin >> arr[i];
//     int large = arr[0];
//     for(int i=0;i<n;i++){
//         if (arr[i]>large)
//             large = arr[i];
//     }
//     cout << "largest:"<< large  << endl;
//     int slarge=-1;
//     for(int i=0;i<n;i++){
//         if(arr[i]>slarge && arr[i]!=large)
//             slarge=arr[i];
//     }
//      cout << "second largest:"<< slarge ;
//     return 0;
// }


//optimal //O(n) //SECOND  LARGEST & SECOND SMALLEST
int secondLargest(vector <int> &a,int n){
    int large=a[0];
    int slarge=-1;
    for(int i=1;i<n;i++){
        if(a[i] >large){
            slarge =large;
            large = a[i]; 
        }
        else if(a[i] < large && a[i] > slarge){
            slarge = a[i];
        }
    }
    return slarge;
}
int secondSmallest(vector <int> &a,int n){
    int small = a[0];
    int ssmall = INT_MAX;
    for(int i=1;i<n;i++){
        if(a[i] < small){
            ssmall = small;
            small = a[i];
        }
        else if(a[i] != small && a[i] < ssmall){
            ssmall = a[i];
        }
    }
    return ssmall;
}


int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int slarge = secondLargest(arr,n);
    int ssmall = secondSmallest(arr,n);
    cout << "Slarge : " << slarge << " SSmall : " << ssmall;
    return 0;
}
