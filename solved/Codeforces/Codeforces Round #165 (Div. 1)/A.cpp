// http://codeforces.com/contest/269/problem/A

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

int log4(int a){
    return ceil(log(a)/log(4));
}

int main(){
    int n;
    cin>>n;
    int p = 0, maxk = 0;
    while(n--){
        int k, a; cin>>k>>a;
        maxk = max(k, maxk);
        int m = log4(a);
        p = max(p, k+m);
    }
    if(p==maxk)p++;
    cout<<p<<endl;
    return 0; 
}