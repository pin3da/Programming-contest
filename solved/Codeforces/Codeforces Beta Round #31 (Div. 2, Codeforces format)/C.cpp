// http://codeforces.com/contest/31/problem/C

using namespace std;
#include <bits/stdc++.h>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl

template <class T> string to_str(const T &x){ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x){ stringstream s; s << x; int r; s >> r; return r; }

bool intersect(pair<int,int > a, pair<int,int > b) {
    if(b < a) swap(a,b);
    if(a.second > b.first) return true;
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > groups(n);
    For(i,n){
        int l,r;cin>>l>>r;
        groups[i] = make_pair(l,r);
    }
    int inter[n];
    memset(inter,0,sizeof inter);
    for(int i = 0; i< n;++i){
        for(int j = 0; j < n; ++j){
            if(i!=j)
                if(intersect(groups[i],groups[j]))inter[i]++;
        }
    }
    int paila = 0;
    int primero2 = 0;
    int index2;
    int someinter = 0;
    For(i,n){
        if(inter[i]>=2){
            index2 = i+1;
            if(primero2){
                paila = 1;
                break;
            }
            primero2 = 1;
        }
        if(inter[i]==1)someinter = 1;
        
    }
    if(paila){
        cout<<0<<endl;
    }else if(primero2){
        cout<<1<<"\n"<<index2<<endl;
    }else{
        vector<int> ans;
        For(i,n){
            if(inter[i]!=0 or !someinter)ans.push_back(i+1);
        }
        cout<<ans.size()<<endl;
        foreach(aa,ans){
            cout<<(*aa)<<" ";
        }
        cout<<endl;
    }
    return 0; 
}