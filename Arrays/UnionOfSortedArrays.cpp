//UNION OF TWO SORTED ARRAYS
//brute  O(n1 log n+n2 log n)+O(n1+n2)
void unionSortedBrute(int a[],int n,int b[],int m){
    set <int> s;
    for(int i=0;i<n;i++)
        s.insert(a[i]);
    for(int i=0;i<m;i++)
        s.insert(b[i]);
    vector <int> Union;
    for(auto it:s)
        Union.push_back(it);
    
    for(auto it:Union)
        cout << it << " ";
}
//Optimal  O(n+m)
vector <int> unionSortedOptimal(int a[],int n,int b[],int m){
    int i=0,j=0;
    vector <int> Union;
    while(i<n && j<m){
        if(a[i]<b[j]){
            if(Union.size()==0 || Union.back() != a[i])
                Union.push_back(a[i]);
            i++;
        }
        else if(a[i]>b[j]){
            if(Union.size()==0 || Union.back() != b[j])
                Union.push_back(b[j]);
            j++;
        }
        else{
            //a[i]==b[j]
            if(Union.size()==0 || Union.back() != a[i])
                Union.push_back(a[i]);
            i++;
            j++;
        }
    }
    while(i<n){
        if(Union.size()==0 || Union.back() != a[i])      
            Union.push_back(a[i]);
        i++;
        }
    while(j<m){
        if(Union.size()==0 || Union.back() != b[j])  
            Union.push_back(b[j]);
        j++;
    }
    return Union ;
}
int main(){
    int n,m;
    cin >> n ;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> m;
    int b[m];
    for(int i=0;i<m;i++)
        cin >> b[i];
    //unionSortedBrute(a,n,b,m);
    vector <int> Unionarray = unionSortedOptimal(a,n,b,m);
    for(auto it:Unionarray)
        cout << it << " ";
    return 0;
}
