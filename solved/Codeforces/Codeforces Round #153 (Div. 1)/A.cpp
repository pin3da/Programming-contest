// http://codeforces.com/contest/251/problem/A

using namespace std;
#include <bits/stdc++.h>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl

template <class T> string to_str(const T &x){ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x){ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;

int main(){
    ll n,d;
    cin>>n>>d;
    vector<int> todos(n);
    for(int i = 0; i< n;++i)
        cin>>todos[i];
    
    if(n<3){
        cout<<0<<endl;
        return 0;
    }
    ll ans = 0;
    for(int i = 0; i< n;++i){
        vector<int>::iterator hi = lower_bound(todos.begin()+i,todos.end(), todos[i]+d);
        if(hi==todos.end() or (*hi) - todos[i] > d ) hi--;
        ll t = (hi - todos.begin()) - i;
        ans+= (t*(t-1))>>1;
    }

    cout<<ans<<endl;
    
    return 0; 
}