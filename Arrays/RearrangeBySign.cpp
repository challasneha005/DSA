//REARRANGE ARRAY ELEMENTS BY SIGN 
//IF EQUAL ELEMENTS
//brute O(n)+O(n)
void rearrangeArrayBrute(int a[],int n){
    int pos[n],neg[n];
    int posIndex = 0,negIndex = 0;
    for(int i=0;i<n;i++){
        if(a[i] > 0)
            pos[posIndex++] = a[i];
        else
            neg[negIndex++] = a[i];
    }
    for(int i=0;i<n/2;i++){
        a[2*i] = pos[i];
        a[2*i+1] = neg[i];
    }
}
//optimal O(n)
void rearrangeArrayOptimal(int a[],int n){
    int ans[n];
    int posIndex = 0,negIndex = 1;
    for(int i=0;i<n;i++){
        if(a[i] > 0)
        ans[posIndex++] = a[i];
        else
        ans[negIndex++] = a[i];
    }
}
//LEFT OVER ELEMENTS
void rearrangeElements(int a[],int n){
    int pos[n],neg[n];
    int posIndex = 0,negIndex = 0;
    for(int i=0;i<n;i++){
        if(a[i] > 0)
        pos[posIndex++] = a[i];
        else
        neg[negIndex++]=a[i];
    }
    int i=0;
    int index=0;
    if (posIndex > negIndex){
        for(int i=0;i<negIndex;i++){
            a[2*i] = pos[i];
            a[2*i+1]=neg[i];
        }
        index = negIndex *2;
        for(i=negIndex;i<posIndex;i++)
            a[index++]=pos[i];
    }
    else{
        for(int i=0;i<posIndex;i++){
            a[2*i] = pos[i];
            a[2*i+1]=neg[i];
        }
        index = posIndex *2;
        for(i=posIndex;i<negIndex;i++)
            a[index++]=neg[i];
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    //rearrangeArrayBrute(a,n);
    // rearrangeArrayOptimal(a,n);
    rearrangeElements(a,n);
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}
