// http://codeforces.com/contest/9/problem/C

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl

int to_int(string cad){
    stringstream ss(cad);
    int r;
    ss>>r;
    return r;
}

vector<int> todos;


void gen(string num = "1"){
    int mio = to_int(num);
    if(mio > 1000000000) return;
    todos.push_back(mio);
    gen(num+"1");
    gen(num+"0");
}

int main(){ ___
    gen();
    
    int n;cin>>n;
    
    sort(todos.begin(),todos.end());
    
    vector<int>::iterator it = upper_bound(todos.begin(),todos.end(),n);
    
        
    cout<<distance(todos.begin(),it)<<endl;

    return 0;
}

