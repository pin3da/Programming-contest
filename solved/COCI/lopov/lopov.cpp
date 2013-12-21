using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl
#define all(c) c.begin(), c.end()


struct mio{
    int c,v;
    mio(){}
    
    bool operator < (const mio &o) const{
        if(v == o.v) return c < o.c;
        return v > o.v;
    }
};

int main(){
    int n, k;
    cin>>n>>k;
    vector<mio> joyas(n);
    set<int> cap;
    int t;
    for(int i = 0; i< n; ++i)
        cin>>joyas[i].c>>joyas[i].v;
    for(int i = 0; i< k; ++i){
        cin>>t;
        cap.insert(t);
    }
    
    sort(all(joyas));
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        set<int>::iterator it =  cap.lower_bound(joyas[i].c);
        if(it == cap.end())continue;
        else{
            ans += joyas[i].v;
            cap.erase(it);
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
