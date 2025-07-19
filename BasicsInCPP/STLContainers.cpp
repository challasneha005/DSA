#include<bits/stdc++.h>
using namespace std;

void explainPair(){
    pair<int,int> p ={1,4};
    cout << p.first << " " << p.second << endl;

    pair <int,char> p1 ={1,'a'};
    cout << p1.first << " " << p1.second << endl;

    pair <int,pair<int,int>> p2={2,{3,4}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

    pair <int,int> arr[] = {{1,2},{2,3},{4,3}};
    cout << arr[1].second ;
}

void explainVector(){
    // vector <int> v={1,2,3,4,5};
    // cout << v[2] << endl;

    // v.push_back(11); //add 11 end
    // cout << v[5] << endl;
    // v.emplace_back(13); //add 13 at end
    // cout << v[6] << endl ;

    // // vector <int> v2=(5,20);
    // // cout <<v2[1]<<" "<<v2[3]<<" "<<v2[2]<<" "<<endl;
    
    // vector <pair<int,int>> v3;
    // v3.push_back({1,2});
    // v3.emplace_back(5,6);
    // cout << v3[0].first <<endl;

    ///iterator
    // vector <int> :: iterator i=v.begin();
    // cout<< *i<<endl;
    // cout<< *(i+1)<<endl;
    // cout<< *(i+2)<<endl;


    // vector<int>:: iterator i1=v.end();
    // vector<int>:: reverse_iterator i2=v.rend();
    // vector<int>:: reverse_iterator i3=v.rbegin();
    // i3++;
    // cout << *(i3) <<endl; 
    // cout << v.back() <<endl; //last element
    // return 0;

    //print vector
    // for(vector <int>::iterator i=v.begin(); i!=v.end(); i++)
    // cout << *i << " ";
    // cout <<endl;

    // for(auto i=v.begin(); i!=v.end(); i++)
    // cout << *i << " ";
    // cout <<endl;

    //for each loop
    // for(int k:v)
    // cout << k <<" ";
    // cout << endl;

    // for(auto k:v)
    // cout << k <<" ";
    // cout << endl;

    //delete v=1,3,7,9,11,13
    // v.erase(v.begin()+2); //1,3,7,9,11,3
    // for(auto k:v)
    // cout << k <<" ";
    // cout << endl;

    // v.erase(v.begin()+1,v.begin()+4); //1,11,13
    // for(auto k:v)
    // cout << k <<" ";
    // cout << endl;

    //insert
    vector<int> v4={1,2,3,4,5,6};
    v4.insert(v4.begin(),5);
    v4.insert(v4.begin()+2,2,8);

    // for(auto k:v)
    // cout << k <<" ";
    // cout << endl;

    vector<int>v6={20,6};
    v4.insert(v4.begin(),v6.begin(),v6.end());
    cout << v4.size() << endl;

    v4.pop_back();

    vector<int> v7={1,2};
    vector<int>v8={3,4};
    v7.swap(v8);
    v7.clear(); //erases entire vector

    cout<<v7.empty()<<endl;
     
    // vector <int> copy(2,50); //50,50
    // a.insert(a.begin(),copy.begin(),copy.end()); // 50,50,300,10,10,100,100

    // //{10,20}
    // cout << a.size();  //2
    // a.pop_back(); //10

}

void explainList(){
    list <int> l;
    l.push_back(2); //2
    l.emplace_back(4); //{2,4}
    l.push_front(5); //5,2,4
    l.emplace_front(9); //9,5,2,4

    // //cout<< l[0]; //errror

    for(auto k:l)
    cout<< k<<" ";
    cout << endl;

    l.pop_back();
    l.pop_front();

    cout <<l.back() <<endl;
    cout << l.front()<<endl;

    // rest same as vector
    // begin,end,rbegin,rend,clear,insert,size,swap
}

void explainDeque(){
    deque<int> dq;
    dq.push_back(3);
    dq.emplace_back(5);
    dq.push_front(1);
    dq.emplace_front(8);

    for(auto k:dq)
    cout<< k<<" ";
    cout << endl;

    dq.pop_back();
    dq.pop_front();

    cout<< dq.back()<<endl;
    cout<< dq.front()<<endl;

    cout<< dq[0]<< endl;
    // rest same as vector
    // begin,end,rbegin,rend,clear,insert,size,swap
    // O(1) insert
}

void explainStack(){
    stack<int> s;
    //LIFO
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.emplace(9);

    //cout<<s[0] //error

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

    cout <<s.size()<<endl;
    cout<<s.empty()<<endl;

    stack<int> s1;
    s.swap(s1);
    cout <<s1.size()<<endl;
    // O(1) insert
}

void explainQueue(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.emplace(9); //1,2,3,4,9

    q.front()+=10;
    cout<<q.front()<<endl; 

    q.back()+=5;
    cout<<q.back()<<endl;

    q.pop();
    cout<<q.front()<<endl;
    // O(1) insert
}

void explainPQueue(){
    priority_queue <int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.emplace(9);

    cout<<pq.top()<<endl;

    pq.pop();
    cout<<pq.top()<<endl;
    // O(log n) insert

    // //not linear ,tree data structure

    // //min .max heap
    priority_queue <int,vector<int>,greater<int>> minpq;
    minpq.push(1);
    minpq.push(22);
    minpq.push(13);
    minpq.push(18);
    minpq.emplace(9);

    cout<< minpq.top()<<endl;

    //push pop O(log N)
}
void explainSet(){
    set<int> s;
    s.insert(1);
    s.insert(9);
    s.insert(2);
    s.insert(4);
    s.insert(3);
    s.insert(4);

    auto i1 =s.find(2);
    auto i2 =s.find(7); //end 

    s.erase(9);
    s.erase(i1);

    set <int> s1={2,4,6,8,10};
    auto i3=s1.find(8);
    auto i4=s1.find(4);
    // // s1.erase(i3,i4);
    
    int c1=s1.count(6);
    int c2=s1.count(7);

    //lower_bound and upperbound works same as in vector
    auto i=s.lower_bound(2);
    auto a=s.upper_bound(8);
    
    //insert O(log N)
}
void explainMultiSet(){
    //stores duplicates also
    multiset<int>ms;
    ms.insert(1);
    ms.insert(9);
    ms.insert(1);
    ms.insert(2);
    ms.insert(1);
    ms.insert(4);

    ms.erase(1); // all 1 s erased
    ms.erase(ms.find(1)); //erase single element

    int count = ms.count(1);

    //rest same as set

    //O(log n) insert
}

void explainUnOrderedSet(){
    unordered_set<int> st;
    //lower and upper bound not work
    //rest same 
    //unordered,better compleity except some when collision happens 
    //O(1)  insert
}

void explainMap(){
    map<int,int> mpp;
    map<int,pair<int,int>> mp;
    map<pair<int,int>,int> m;

    mpp[1]=2;
    mpp.emplace(3,1);
    mpp.insert({2,4});
    m[{2,3}] =10;

    // {
    //     {1,2}
    //     {2,4}
    //     {3,1}
    // }

    for(auto i:mpp)
        cout << i.first << " " << i.second << endl;

    cout << mpp[1]; //2
    cout << mpp[5]; //0

    auto i1=mpp.find(3);
    cout << i1->second;

    auto i2=mpp.find(5); //end

    auto i3=mpp.lower_bound(2);
    auto i4=mpp.upper_bound(3);

    //erase ,swap,size,empty same as above
    //O(log n) insert

}

void explainMultiMap(){
    //everything same as map .stores multiple keys
    //mpp[key] cant be used here
    //O(log n) insert
}

void explainUnorderedMap(){
    //same as set and unordered set difference
    //O(1) insert
}

bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second < p2.second){
        return true;
    }else if(p1.second == p2.second){
        if(p1.first > p2.second) return true;
    }
    return false;
}
void Extra(){
    sort(a,a+n);
    sort(v.begin(),v.end());
    
    sort(a+2,a+4);
    
    sort(a,a+n,greater<int>);

    pair<int,int> a[]={{1,2},{2,1},{4,1}};
    //sort according to 2nd element
    //2nd element same .then sort
    // according to first element but in descending
    
    sort(a,a+n,comp);
    //{4,1},{2,1},{1,2}

    int num=7;
    int cnt=__builtin_popcount();

    long long num=123456789876546543;
    int cnt=__builtin_popcountll();

    string s="123";
    do{
        cout << s << endl;
    }while(next_permutation(s.begin(),s.end()));
    int maxi =*max_element(a,a+n);
}
int main(){
    explainMap();
    return 0;
}